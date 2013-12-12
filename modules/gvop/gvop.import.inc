<?php

function gvop_import_batch_start() {
  $batch = array(
    'title' => t('Processing GVOP run all'),
    'operations' => array(),
    'finished' => '_gvop_batch_run_finished',
    'file' => drupal_get_path('module', 'gvop') . '/gvop.import.inc',
  );

  $gvop_info = module_invoke_all('gvop_info');
  foreach ($gvop_info as $type_info) {
    $batch['operations'][] = array('_gvop_batch_run', array($type_info));
  }
  batch_set($batch);

  if (function_exists('drush_backend_batch_process')) {
    // Drush does not start the batch automatically, but we cannot skip
    // this batch without side effects.
    drush_backend_batch_process();
  }
}

/**
 * Callback for GVOP Batch.
 */
function _gvop_batch_run($type_info, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }

  $limit = variable_get('gvop_limit', 20);
  $dom = _gvop_retrieve_dom($type_info, $context['sandbox']['progress'], $limit);
  $xpath = new DOMXPath($dom);
  $context['sandbox']['max'] = (int) $dom->getElementsByTagName('numberOfRecords')->item(0)->nodeValue;
  $records = $dom->getElementsByTagName("gzd");
  foreach ($records as $record) {
    $context['message'] = t('Now processing !current / !max', array('!current' => $context['sandbox']['progress'], '!max' => $context['sandbox']['max']));
    $context['sandbox']['progress']++;
    $node = _gvop_map_node($type_info, $record, $xpath);
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['results']['count'] = $context['sandbox']['progress'];
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Batch 'finished' callback
 */
function _gvop_batch_run_finished($success, $results, $operations) {
  if (isset($results['count'])) {
    drupal_set_message(format_plural($results['count'], '1 node imported successfully. ', '@count nodes imported.'));
  }
}

/**
 * Helper function to retrieve the DOMDocument.
 *
 * @param $start
 * @param $limit
 * @return DOMDocument
 */
function _gvop_retrieve_dom($type_info, $start, $limit, $params = array()) {
  $uri = _gvop_build_uri($type_info, $start, $limit, $params);
  $data = drupal_http_request($uri);
  if ($data->code != 200) {
    watchdog('gvop', 'Unable to retreive XML from GVOP (code: %code, url: %url)', array(
      '%code' => $data->code,
      '%url' => $uri,
    ), WATCHDOG_ERROR);
  }
  else {
    $dom = new DOMDocument();
    $dom->loadXML($data->data);
  }
  return $dom;
}

/**
 * Function to map a gvop node.
 *
 * @param $type_info
 * @param DOMElement $record
 * @param DOMXPath $xpath
 * @param bool $force
 * @return bool|mixed|stdClass
 */
function _gvop_map_node($type_info, DOMElement $record, DOMXPath $xpath, $force = FALSE) {
  if ($type_info['file']) {
    include_once($type_info['file']);
  }

  $identifier = $xpath->query('.//dcterms:identifier')->item(0)->nodeValue;

  // Get the current version from the database.
  $current = db_select('gvop', 'g')
    ->fields('g', array('identifier', 'hash', 'nid'))
    ->condition('identifier', $identifier)
    ->execute()
    ->fetchAssoc();

  // Generate an hash for checking the update.
  $xml = $record->saveXML($record);
  $xml_hash = md5($xml);

  // Is this an actual update.
  if (!$force && $current && $xml_hash == $current['hash']) {
    return FALSE;
  }

  // Are we updating or inserting.
  $modified = strtotime($xpath->query('.//dcterms:modified')->item(0)->nodeValue);
  if ($current && !empty($current['nid'])) {
    $node = node_load($current['nid']);
  }
  else {
    $node = new stdClass();
    $node->uid = 1;
    $node->created = $modified;
    $node->type = $type_info['nodetype'];
    $node->status = 1;
  }

  // Set common info.
  $node->gvop_identifier = $identifier;
  $node->title = substr($xpath->query('.//dcterms:title')->item(0)->nodeValue, 0, 255);
  $node->changed = $modified;

  // Run the callback for mapping this type.
  $type_info['callback']($record, $node, $xpath);

  node_save($node);

  // Add to the GVOP table for hash checking and identifying.
  db_merge('gvop')
    ->key(array('identifier' => $identifier))
    ->fields(array('hash' => $xml_hash, 'nid' => $node->nid, 'xml' => $xml, 'changed' => REQUEST_TIME))
    ->execute();

  return $node;
}

/**
 * Helper function to retrieve the uri for requesting.
 *
 * @param $start
 * @param $limit
 * @return string
 */
function _gvop_build_uri($type_info, $start, $limit, $params = array()) {
  $uri = variable_get('gvop_uri', 'https://zoek.officielebekendmakingen.nl/sru/Search');
  $query = array(
    'version' => '1.2',
    'operation' => 'searchRetrieve',
    'x-connection' => $type_info['type'],
    'startRecord' => $start,
    'maximumRecords' => $limit,
    'query' =>
    'creator==' . variable_get('gvop_creator', '')
  );
  foreach ($type_info['query'] as $key => $value) {
    $query['query'] .= ' and ' . $key . '==' . $value;
  }
  foreach ($params as $param) {
    $query['query'] .= ' and ' . $param;
  }
  return $uri . '?' . drupal_http_build_query($query);
}
