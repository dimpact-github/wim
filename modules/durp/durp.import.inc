<?php

/**
 * Start import batch.
 */
function durp_import_batch_start() {
  durp_queue_import();

  $batch = array(
    'title' => t('Importing DURP'),
    'operations' => array(
      array('durp_import_batch_run', array()),
    ),
    'finished' => 'durp_import_batch_finished',
    'file' => drupal_get_path('module', 'durp') . '/durp.import.inc',
  );

  batch_set($batch);

  if (function_exists('drush_backend_batch_process')) {
    // Drush does not start the batch automatically, but we cannot skip
    // this batch without side effects.
    drush_backend_batch_process();
  }
}

/**
 * Parse manifest and create queue items.
 */
function durp_queue_import() {
  $url = variable_get('durp_manifest', '');
  if (!strstr($url, '://')) {
    $filename = $url;
  }
  else {
    // Given URI is an URL, download this file first.
    $filename = 'temporary://import_' . md5(time() . $url) . '.xml';
    if (!$data = drupal_http_request($url)) {
      watchdog('durp', 'Could not retrieve data to !url', array('!url' => $url), WATCHDOG_ERROR);
      return FALSE;
    }
    if ($data->code != 200) {
      watchdog('durp', 'Wrong response code for !url: !code', array('!url' => $url, '!code' => $data->code), WATCHDOG_ERROR);
      return FALSE;
    }
    if (!$fp = fopen($filename, 'w')) {
      watchdog('durp', 'Could not write data to !file', array('!file' => $filename), WATCHDOG_ERROR);
      return FALSE;
    }
    fwrite($fp, $data->data);
    fclose($fp);
    // Sleep 1s to wait for filesystem
    sleep(1);
  }

  $xmlReader = new XMLReader;
  $xmlReader->open($filename);

  // Move to the first <Dossier /> node.
  while ($xmlReader->read() && $xmlReader->name !== 'Dossier');

  $queue = DrupalQueue::get('durp');
  while ($xmlReader->name === 'Dossier') {
    $item = new stdClass();
    $item->id = $xmlReader->getAttribute('Id');
    $item->xml = $xmlReader->readOuterXml();
    $queue->createItem($item);
    $xmlReader->next('Dossier');
  }
}

/**
 * Callback for durp Batch.
 */
function durp_import_batch_run(&$context) {
  $queue = DrupalQueue::get('durp');

  if (empty($context['sandbox'])) {
    $context['sandbox']['done'] = 0;
    $context['sandbox']['max'] = $queue->numberOfItems();
  }

  if ($item = $queue->claimItem()) {
    _durp_map_node($item->data->id, $item->data->xml);
    $queue->deleteItem($item);
    ++$context['sandbox']['done'];
  }
  else {
    $context['sandbox']['max'] = $context['sandbox']['done'];
  }

  $context['message'] = t('Imported @count items.', array(
    '@count' => $context['sandbox']['done'],
  ));
  $context['finished'] = $context['sandbox']['done'] >= $context['sandbox']['max'];
  if ($context['finished']) {
    $context['results']['count'] = $context['sandbox']['done'];
  }
}

/**
 * Batch 'finished' callback
 */
function durp_import_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(format_plural($results['count'], '1 result processed', '@count results processed'));
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)
    ));
    drupal_set_message($message, 'error');
  }
}

/**
 * Import node from XML.
 *
 * @param string $dossier_id
 * @param string $dossierXML
 * @param bool $force
 */
function _durp_map_node($dossier_id, $dossierXML, $force = FALSE) {
  $xml_hash = md5($dossierXML);
  $dossierDOM = new DOMDocument;
  $dossierDOM->loadXML($dossierXML);

  // Get the current version from the database.
  $current = db_select('durp', 'd')
    ->fields('d', array('identifier', 'hash', 'nid'))
    ->condition('identifier', $dossier_id)
    ->execute()
    ->fetchAssoc();

  $dossier = $dossierDOM->getElementsByTagName('Dossier');
  $dossier_status = $dossier->item(0)->getAttribute('Status');
  if ($dossier_status == variable_get('durp_due_state', 'vervallen')) {
    if ($current) {
      node_delete($current['nid']);
      drupal_set_message(t('Removed due dossier @dossier_id with nid @nid.', array('@dossier_id' => $dossier_id, '@nid' => $current['nid'])));
    }
    return FALSE;
  }


  // Is this an actual update.
  if (!$force && $current && $xml_hash == $current['hash']) {
    return FALSE;
  }

  // Search for the most recent plan.
  $plans = $dossierDOM->getElementsByTagName('Plan');
  $plansByDate = array();
  foreach ($plans as $plan) {
    $date = $plan->getElementsByTagName('Datum')->item(0)->nodeValue;
    $plansByDate[$date] = $plan;
  }
  krsort($plansByDate);
  $plan = reset($plansByDate);


  if ($plan) {
    $plan_uri = trim($plan->getElementsByTagName('GeleideFormulier')->item(0)->nodeValue);
    if (!$plan_uri) {
      watchdog('durp', 'Could not load proper plan uri for !dossier_id: !plan_uri', array('!dossier_id' => $dossier_id, '!plan_uri' => $plan_uri), WATCHDOG_ERROR);
      return FALSE;
    }
    $data = drupal_http_request($plan_uri);
    if (!$data->data) {
      watchdog('durp', 'Could not load plan uri for !dossier_id: !data', array('!dossier_id' => $dossier_id, '!data' => $data->data), WATCHDOG_ERROR);
      return FALSE;
    }

    $planXML = $data->data;
    $planDOM = new DOMDocument;
    $planDOM->loadXML($planXML);
    $planXpath = new DOMXPath($planDOM);

    // Setup namespace.
    $namespace = trim($planDOM->getElementsByTagName('GeleideFormulier')->item(0)->getAttribute('xmlns'));
    if (!$namespace) {
      $namespace = variable_get('durp_default_namespace', 'http://www.geonovum.nl/stri/2008/1');
    }
    $planXpath->registerNamespace('ns', $namespace);

    if ($current && !empty($current['nid'])) {
      $node = node_load($current['nid']);
    }
    else {
      $node = new stdClass();
      $node->uid = 1;
      $node->type = 'spatial_plan';
    }

    $node->title = $planXpath->query('/ns:GeleideFormulier/ns:Plan/ns:Eigenschappen/ns:Naam')->item(0)->nodeValue;
    $node->created = strtotime($planXpath->query('/ns:GeleideFormulier/ns:Plan/ns:Eigenschappen/ns:Datum')->item(0)->nodeValue);
    $node->changed = $node->created;

    if (empty($node->title)) {
      watchdog('durp', 'Could not determine node title for !dossier_id', array('!dossier_id' => $dossier_id), WATCHDOG_ERROR);
      return FALSE;
    }

    $node->field_spatial_plan_id = array(
      LANGUAGE_NONE => array(array('value' =>  $plan->getAttribute('Id')))
    );

    // Taxonomy type fields.
    $type = $planXpath->query('/ns:GeleideFormulier/ns:Plan/ns:Eigenschappen/ns:Type')->item(0)->nodeValue;
    $type_term = bespoke_get_term_id($type, 'spatial_plan_type');
    $node->field_spatial_type = array(
      LANGUAGE_NONE => array(array('tid' => $type_term->tid))
    );
    $status = $planXpath->query('/ns:GeleideFormulier/ns:Plan/ns:Eigenschappen/ns:Status')->item(0)->nodeValue;
    $status_term = bespoke_get_term_id($status, 'spatial_plan_status');
    $node->field_spatial_status = array(
      LANGUAGE_NONE => array(array('tid' => $status_term->tid))
    );

    // Link type fields.
    // Setup a base uri for the links.
    $base_uri = str_replace(basename($plan_uri), '', $plan_uri);
    _durp_link_field($base_uri, 'field_spatial_rules', $planXpath, '/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:Regels', $node);
    _durp_link_field($base_uri, 'field_spatial_policy_doc', $planXpath, '/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:BeleidsDocument', $node);
    _durp_link_field($base_uri, 'field_spactial_decision_doc', $planXpath, '/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:BesluitDocument', $node);
    _durp_link_field($base_uri, 'field_spatial_explanation', $planXpath, '/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:Toelichting', $node);
    _durp_link_field($base_uri, 'field_spatial_dete_decision', $planXpath, '/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:VaststellingsBesluit', $node);
    _durp_link_field($base_uri, 'field_spatial_attachment', $planXpath, '/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:Bijlage', $node);
    _durp_link_field($base_uri, 'field_spatial_illustration', $planXpath, '/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:Illustratie', $node);

    // Location
    $imro = $planXpath->query('/ns:GeleideFormulier/ns:Plan/ns:Onderdelen/ns:IMRO')->item(0)->nodeValue;
    $data = drupal_http_request($base_uri . $imro);
    $gmlXML = $data->data;
    if ($gmlXML) {
      // Load the Dom
      $gmlDOM = new DOMDocument;
      $gmlDOM->loadXML($gmlXML);

      // Setup xpath.
      $gmlXPATH = new DOMXPath($gmlDOM);
      $gmlXPATH->registerNamespace('imro', 'http://www.geonovum.nl/imro/2008/1');
      $gmlXPATH->registerNamespace('gml', 'http://www.opengis.net/gml');

      // We retrieve all positions and generate an average.
      $x = $y = array();
      $positions = $gmlXPATH->query('//gml:posList');
      $node->field_location = array(LANGUAGE_NONE => array());
      foreach ($positions as $posListNode) {
        $posListStr = $posListNode->nodeValue;
        $posList = explode(' ', $posListStr);

        $flag = TRUE;
        foreach ($posList as $value) {
          if ($flag) {
            $x[] = $value;
          }
          else {
            $y[] = $value;
          }

          $flag = !$flag;
        }
      }
      $x = array_sum($x) / count($x);
      $y = array_sum($y) / count($y);

      $location = rd2wgs($x, $y);
      $location['country'] = 'nl';

      $node->field_location[LANGUAGE_NONE][] = array(
        'country' => 'nl',
        'latitude' => (string)$location['latitude'],
        'longitude' => (string)$location['longitude'],
        'locpick' => array(
          'user_latitude' => (string)$location['latitude'],
          'user_longitude' => (string)$location['longitude'],
        ),
        'source' => 1,
      );
    }

    // Allow objects to be cleared from memory with garbage collection if
    // memory limits are close.
    unset($gmlDOM, $gmlXPATH, $pathDOM, $pathXpath, $dossierDOM);

    node_save($node);

    // Add to the durp table for hash checking and identifying.
    if ($node->nid) {
      db_merge('durp')
        ->key(array('identifier' => $dossier_id))
        ->fields(array('hash' => $xml_hash, 'nid' => $node->nid, 'xml' => $planXML, 'changed' => REQUEST_TIME))
        ->execute();

      return $node;
    }
  }
  else {
    drupal_set_message(t('Could not detect plan for !dossier_id', array('!dossier_id' => $dossier_id)));
  }

  return FALSE;
}

/**
 * Helper function for setting a link field.
 *
 * @param $base_uri
 *  Base url to the documents.
 * @param $field_name
 *  The drupal machine name for the field.
 * @param $planXpath
 *  The DOMXPath of the plan.
 * @param $xpathQuery
 *  Xpath query to the data.
 * @param $node
 *  The node to set the field data on.
 */
function _durp_link_field($base_uri, $field_name, DOMXPath $planXpath, $xpathQuery, $node) {
  $links = $planXpath->query($xpathQuery);
  $node->{$field_name} = array(LANGUAGE_NONE => array());
  foreach ($links as $linkNode) {
    $link_url = $base_uri .  $linkNode->nodeValue;
    $node->{$field_name}[LANGUAGE_NONE][] = array(
      'url' => $link_url,
      'title' => $linkNode->nodeValue,
    );
  }
}

/**
 * Convert RD to GPS
 *
 * Function copied from:
 * http://www.god-object.com/2009/10/23/convert-rijksdriehoekscordinaten-to-latitudelongitude/
 */
function rd2wgs($x, $y) {
  // Calculate WGS84 coördinates
  $dX = ($x - 155000) * pow(10, - 5);
  $dY = ($y - 463000) * pow(10, - 5);
  $SomN = (3235.65389 * $dY) + (- 32.58297 * pow($dX, 2)) + (- 0.2475 *
      pow($dY, 2)) + (- 0.84978 * pow($dX, 2) *
      $dY) + (- 0.0655 * pow($dY, 3)) + (- 0.01709 *
      pow($dX, 2) * pow($dY, 2)) + (- 0.00738 *
      $dX) + (0.0053 * pow($dX, 4)) + (- 0.00039 *
      pow($dX, 2) * pow($dY, 3)) + (0.00033 * pow(
        $dX, 4) * $dY) + (- 0.00012 *
      $dX * $dY);
  $SomE = (5260.52916 * $dX) + (105.94684 * $dX * $dY) + (2.45656 *
      $dX * pow($dY, 2)) + (- 0.81885 * pow(
        $dX, 3)) + (0.05594 *
      $dX * pow($dY, 3)) + (- 0.05607 * pow(
        $dX, 3) * $dY) + (0.01199 *
      $dY) + (- 0.00256 * pow($dX, 3) * pow(
        $dY, 2)) + (0.00128 *
      $dX * pow($dY, 4)) + (0.00022 * pow($dY,
        2)) + (- 0.00022 * pow(
        $dX, 2)) + (0.00026 *
      pow($dX, 5));

  $Latitude = 52.15517 + ($SomN / 3600);
  $Longitude = 5.387206 + ($SomE / 3600);

  return array(
    'latitude' => $Latitude ,
    'longitude' => $Longitude);
}
