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
  $batch['operations'][] = array('atos_esuite_import_batch_worker', array($types));
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
 * @param array $types
 * @param array $context
 */
function atos_esuite_import_batch_worker($types, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['done'] = 0;
    $context['sandbox']['max'] = variable_get('atos_esuite_finish_margin', 250);
    $context['sandbox']["last"] = 0;
    $context['sandbox']["last_found"] = 0;
  }

  foreach ($types as $type) {
    $url = variable_get('atos_esuite_url', '');
    $query = array(
      'type' => $type,
      'id' => implode(',', range($context['sandbox']["last"] + 1, $context['sandbox']["last"] + variable_get('atos_esuite_chunk_size', 10))),
    );
    $url = "$url?" . http_build_query($query, '', '&');
    list($done, $errors, $last_atos_id) = _atos_esuite_process_feed($type, $url);
    $context['sandbox']['done'] += $done;
    $context['sandbox']["last_found"] = max($context['sandbox']["last_found"], $last_atos_id);
  }
  $context['sandbox']["last"] += variable_get('atos_esuite_chunk_size', 10);

  $context['message'] = t('Imported @count items.', array(
    '@count' => $context['sandbox']['done'],
  ));
  $context['sandbox']['max'] = $context['sandbox']["last_found"] + variable_get('atos_esuite_finish_margin', 250);
  $context['finished'] = $context['sandbox']["last"] >= $context['sandbox']['max'];
  if ($context['finished']) {
    $context['results']['count'] = $context['sandbox']['done'];
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
 * @param string $type 'product' or 'vac'
 * @param string $url
 * @return array
 *   array(int $done, int $errors, int $last_atos_id)
 */
function _atos_esuite_process_feed($type, $url) {
  $xmlReader = new XMLReader;
  $xmlReader->open($url);

  $imported = 0;
  $errors = 0;

  $last_atos_id = 0;

  // Move to the first <result> node.
  while ($xmlReader->read() && $xmlReader->name !== 'result');

  while ($xmlReader->name === 'result') {
    try {
      $atos_id = atos_esuite_map_node($type, $xmlReader->readOuterXml());
      ++$imported;
      $last_atos_id = max($last_atos_id, $atos_id);
    }
    catch (Exception $e) {
      ++$errors;
    }
    $xmlReader->next('result');
  }

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
function atos_esuite_map_node($type, $documentXML, $force = FALSE) {
  $xml_hash = md5($documentXML);
  $documentDOM = new DOMDocument;
  $documentDOM->loadXML($documentXML);
  $xpath = new DOMXPath($documentDOM);

  $atos_id = $xpath->query('/result/id')->item(0)->nodeValue;
  $id = "$type-$atos_id";
  if ($id) {
    // Get the current version from the database.
    $current = db_select('atos_esuite', 'a')
      ->fields('a', array('identifier', 'hash', 'nid'))
      ->condition('identifier', $id)
      ->execute()
      ->fetchAssoc();

    // Is this an actual update.
    if (!$force && $current && $xml_hash == $current['hash']) {
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
        ->fields(array('hash' => $xml_hash, 'nid' => $node->nid))
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
      dsm('voeg toe');
      $body .= '<h2>**' . check_plain($label) . '</h2>';
      $body .= $text;
    }
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
  $node->field_explanation = array(
    LANGUAGE_NONE => array(
      array(
        'value' => $xpath->query('/result/toelichting')->item(0)->nodeValue,
        'format' => 'filtered_html',
      )
    )
  );
}
