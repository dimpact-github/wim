<?php

/**
 * Start batch.
 *
 * @param array $types
 */
function atos_esuite_import_batch_start($types) {
  $batch = array(
    'operations' => array(),
    'finished' => 'atos_esuite_import_batch_finished',
    'title' => t('Atos eSuite import'),
    'init_message' => t('Preparing import..'),
    'progress_message' => t('Importing...'),
    'error_message' => t('Batch has encountered an error.'),
    'file' => drupal_get_path('module', 'atos_esuite') . '/atos_esuite.import.inc',
  );
  $batch['operations'][] = array('atos_esuite_import_batch_worker', array());
  batch_set($batch);

  if (function_exists('drush_backend_batch_process')) {
    // Drush does not start the batch automatically, but we cannot skip
    // this batch without side effects.
    drush_backend_batch_process();
  }
}

/**
 * Worker callback for batch process.
 *
 * @param array $context
 */
function atos_esuite_import_batch_worker(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['done'] = 0;
    $context['sandbox']['max'] = variable_get('atos_esuite_finish_margin', 250);
    $context['sandbox']['last'] = 0;
    $context['sandbox']['last_found'] = 0;
    $context['sandbox']['errors'] = 0;
    $context['sandbox']['starttime'] = time();
  }

  $url = variable_get('atos_esuite_url', '');
  $query = array(
    'id' => implode(',', range($context['sandbox']['last'] + 1, $context['sandbox']['last'] + variable_get('atos_esuite_chunk_size', 10))),
  );
  $url = "$url?" . http_build_query($query, '', '&');
  if ($result = _atos_esuite_process_feed($url)) {
    list($done, $errors, $last_atos_id) = $result;
    $context['sandbox']['done'] += $done;
    $context['sandbox']['last_found'] = max($context['sandbox']['last_found'], $last_atos_id);
    $context['sandbox']['last'] += variable_get('atos_esuite_chunk_size', 10);
    $context['sandbox']['max'] = $context['sandbox']['last_found'] + variable_get('atos_esuite_finish_margin', 250);
  }
  else {
    $context['sandbox']['errors']++;
  }

  $context['message'] = t('Imported @count items.', array(
    '@count' => $context['sandbox']['done'],
  ));
  $context['finished'] = $context['sandbox']['last'] >= $context['sandbox']['max'];
  if ($context['finished']) {
    _atos_esuite_delete_nodes($context['sandbox']['starttime']);
    $context['results']['count'] = $context['sandbox']['done'];
  }
}

/**
 * Delete nodes which were not found during the batch.
 *
 * @param int $starttime
 */
function _atos_esuite_delete_nodes($starttime) {
  // Sleep a second to wait for database changes to be completed.
  sleep(1);

  $count = db_query('SELECT COUNT(*) FROM {atos_esuite}')->fetchField();
  $deleted = db_select('atos_esuite', 'a')
    ->fields('a', array('identifier', 'nid'))
    ->condition('a.changed', $starttime, '<')
    ->execute()
    ->fetchAll();
  if (count($deleted) == $count) {
    // Looks like all items are deleted. We don't proceed in this case as a safety measure.
    return FALSE;
  }
  foreach ($deleted as $node) {
    node_delete($node->nid);
  }
}

/**
 * Batch 'finished' callback
 */
function atos_esuite_import_batch_finished($success, array $results, array $operations) {
  if (isset($results['count'])) {
    drupal_set_message(format_plural($results['count'], '1 node imported successfully. ', '@count nodes imported.'));
  }
}

/**
 * Request url and process items.
 *
 * @param string $url
 * @return array
 *   array(int $done, int $errors, int $last_atos_id)
 */
function _atos_esuite_process_feed($url) {
  if (!strstr($url, '://')) {
    $filename = $url;
  }
  else {
    // Given URI is an URL, download this file first.
    $filename = 'temporary://import_' . md5(time() . $url) . '.xml';
    if (!$data = drupal_http_request($url)) {
      return FALSE;
    }
    if ($data->code != 200) {
      return FALSE;
    }
    if (!$fp = fopen($filename, 'w')) {
      return FALSE;
    }
    fwrite($fp, $data->data);
    fclose($fp);
    // Sleep 1s to wait for filesystem
    sleep(1);
  }

  $xmlReader = new XMLReader;
  $xmlReader->open($filename);

  $imported = 0;
  $errors = 0;

  $last_atos_id = 0;

  // Move to the first <result> node.
  while ($xmlReader->read() && $xmlReader->name !== 'result');

  while ($xmlReader->name === 'result') {
    try {
      $atos_id = atos_esuite_map_node($xmlReader->readOuterXml());
      ++$imported;
      $last_atos_id = max($last_atos_id, $atos_id);
    }
    catch (Exception $e) {
      ++$errors;
    }
    $xmlReader->next('result');
  }

  unlink($filename);

  return array($imported, $errors, $last_atos_id);
}

/**
 * Update node.
 *
 * @param string $type 'product' or 'vac'
 * @param string $documentXML
 * @param bool $force Force saving node
 * @return object Node object
 */
function atos_esuite_map_node($documentXML, $force = FALSE) {
  $xml_hash = md5($documentXML);
  $documentDOM = new DOMDocument;
  $documentDOM->loadXML($documentXML);
  $xpath = new DOMXPath($documentDOM);

  $xml_type = $xpath->query('/result/type')->item(0)->nodeValue;
  switch ($xml_type) {
    case 'Product':
      $type = 'product';
      break;
    case 'Vraag/Antwoord Combinatie':
      $type = 'vac';
      break;
    default:
      return FALSE;
  }

  $atos_id = $xpath->query('/result/id')->item(0)->nodeValue;
  $id = "$type-$atos_id";
  if ($id) {
    if ($type == 'product' && strstr($documentXML, '<type>Vraag/Antwoord Combinatie</type>')) {
      return FALSE;
    }

    // Get the current version from the database.
    $current = db_select('atos_esuite', 'a')
      ->fields('a', array('identifier', 'hash', 'nid'))
      ->condition('identifier', $id)
      ->execute()
      ->fetchAssoc();

    // Is this an actual update.
    if (!$force && $current && $xml_hash == $current['hash']) {
      // Update the changed date, so we know that this item still exists.
      db_merge('atos_esuite')
        ->key(array('identifier' => $id))
        ->fields(array('changed' => REQUEST_TIME))
        ->execute();
      return FALSE;
    }

    // Are we updating or inserting.
    if ($current && !empty($current['nid'])) {
      $node = node_load($current['nid']);
    }
    else {
      $node = new stdClass();
      $node->uid = 1;
      $node->type = $type;
    }

    $node->title = $xpath->query('/result/title')->item(0)->nodeValue;
    $node->created = $xpath->query('/result/created')->item(0)->nodeValue;
    $node->changed = $xpath->query('/result/changed')->item(0)->nodeValue;
    $callback = 'atos_esuite_map_node_' . $type;
    $callback($node, $documentDOM, $xpath);

    node_save($node);

    // Add to the atos_esuite table for hash checking and identifying.
    if ($node->nid) {
      db_merge('atos_esuite')
        ->key(array('identifier' => $id))
        ->fields(array('hash' => $xml_hash, 'nid' => $node->nid, 'xml' => $documentXML, 'changed' => REQUEST_TIME))
        ->execute();
    }

    return $atos_id;
  }
  else {
    throw new Exception('Could not determine id');
  }

  return FALSE;
}

function atos_esuite_map_node_product($node, DOMDocument $documentDOM, DOMXPath $xpath) {
  $body = $xpath->query('/result/beschrijving')->item(0)->nodeValue;

  $parts = variable_get('atos_esuite_product_parts', '');
  $parts = array_filter(array_unique(array_map('trim', explode("\n", $parts))));

  foreach ($parts as $part) {
    list($tag, $label) = explode('|', $part);
    $text = $xpath->query('/result/' . $tag)->item(0)->nodeValue;
    if (preg_match('/[a-z0-9]/', $text)) {
      $body .= '<h2>**' . check_plain($label) . '</h2>';
      $body .= $text;
    }
  }

  foreach ($xpath->query('/result/keywords/keyword') as $item) {
    $node->field_tags[LANGUAGE_NONE][] = array('tid' => atos_esuite_get_term_tid($item->nodeValue));
  }

  $node->field_related_vac = array(LANGUAGE_NONE => array());
  foreach ($xpath->query('/result/relatedvac/id') as $item) {
    $node->field_related_vac[LANGUAGE_NONE][] = array('value' => $item->nodeValue);
  }

  $node->field_related_pdc = array(LANGUAGE_NONE => array());
  foreach ($xpath->query('/result/relatedpdc/id') as $item) {
    $node->field_related_pdc[LANGUAGE_NONE][] = array('value' => $item->nodeValue);
  }

  $node->body = array(
    LANGUAGE_NONE => array(
      array(
        'value' => $body,
        'format' => 'filtered_html',
      )
    )
  );
}

function atos_esuite_map_node_vac($node, $documentDOM, $xpath) {
  $node->body = array(
    LANGUAGE_NONE => array(
      array(
        'value' => $xpath->query('/result/antwoord')->item(0)->nodeValue,
        'format' => 'filtered_html',
      )
    )
  );
}

/**
 * Get category term id by given name. Creates new term if not found.
 *
 * @param string $name
 * @return int
 */
function atos_esuite_get_term_tid($term_name) {
  $vocabulary_name = variable_get('atos_esuite_tags_vocabulary_name', 'tags');
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);

  $terms = taxonomy_get_term_by_name($term_name, $vocabulary_name);
  if (!count($terms)) {
    $term = new stdClass();
    $term->vid = $vocabulary->vid;
    $term->name = $term_name;
    taxonomy_term_save($term);
  }
  else {
    $term = reset($terms);
  }

  return $term->tid;
}
