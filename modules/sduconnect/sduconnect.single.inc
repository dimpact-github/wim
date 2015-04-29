<?php

/**
 * @file
 * Implementation of SDU Single item API.
 */

/**
 * Import single item.
 *
 * @param object $collection
 * @param string $id
 * @param string $type
 */
function sduconnect_single_import($collection, $id, $type) {
  module_load_include('inc', 'sduconnect', 'sduconnect.content');
  $nid = 0;
  $not_found = FALSE;
  try {
    $node = sduconnect_load_node($collection, $id);
    if ($type == 'remove') {
      if (empty($node->nid)) {
        throw new Exception(t('Item %id is listed as removed, but was not found in Drupal.', array(
          '%id' => $id
        )));
      }
      node_delete($node->nid);
    }
    else {
      if (empty($node->nid)) {
        $not_found = TRUE;
      }
      $content = sduconnect_single_download($collection->type, $collection->external_id, $id);
      $content_function = "sduconnect_set_{$collection->type}_content";
      $content_function($content, $node, (bool) $collection->import_private);
      sduconnect_set_domains($collection, $node);
      sduconnect_save_node($collection, $id, $node);
    }
    $nid = $node->nid;
    $log = t('Processed item %id: %title', array('%id' => $id, '%title' => $node->title));
  }
  catch (Exception $e) {
    if ($e->getCode() == 404) {
      $not_found = TRUE;
    }
    $log = t('Got code %code from %url', array(
      '%code' => $e->getCode(),
      '%url' => $e->getMessage(),
    ));
  }
  $type_codes = array(
    'added' => 2,
    'changed' => 4,
    'removed' => 6,
  );
  db_insert('sduconnect_log')->fields(array(
    'date' => REQUEST_TIME,
    'type' => $type_codes[$type] + ((int) $not_found),
    'cid' => $collection->cid,
    'title' => $log,
    'nid' => $nid,
  ))->execute();
}

/**
 * Retreive single item from API.
 *
 * @param string $collection_type
 * @param int $collection_id
 * @param string $id
 * @return stdClass
 */
function sduconnect_single_download($collection_type, $collection_id, $id) {
  $account_id = variable_get('sduconnect_account', '');
  $version = $collection_type == 'pdc' ? '1.2' : '1.1';
  $url = "https://rest.sduconnect.nl/single/$collection_type/$version/account/$account_id/collectie/$collection_id/item/$id.xml";
  $data = drupal_http_request($url);
  if ($data->code != 200) {
    throw new Exception($url, intval($data->code));
  }
  $dom = new DOMDocument();
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($data->data);
  $xpath = new DOMXPath($dom);
  if ($xpath->query('//response/error')->length) {
    $code = $xpath->query('//response/error/code')->item(0)->nodeValue;
    throw new Exception($url, intval($xml->error->code));
  }
  return $xpath;
}

/**
 * Load node from collection.
 *
 * @param object $collection
 * @param string $id
 */
function sduconnect_load_node($collection, $id) {
  $nid = db_select('sduconnect_item', 'i')
    ->fields('i', array('nid'))
    ->condition('cid', $collection->cid)
    ->condition('external_id', $id)
    ->execute()
    ->fetchField();
  if ($nid) {
    $node = node_load($nid);
  }
  else {
    $node = new stdClass();
    $node->uid = 1;
    $node->status = 1;
    $node->language = language_default()->language;
  }
  return $node;
}

/**
 * Save node.
 *
 * @param object $collection
 * @param string $id
 * @param object $node
 */
function sduconnect_save_node($collection, $id, $node) {
  $new = empty($node->nid);
  node_submit($node);
  node_save($node);
  if ($new) {
    db_insert('sduconnect_item')->fields(array(
      'nid' => $node->nid,
      'cid' => $collection->cid,
      'external_id' => $id,
    ))->execute();
  }
}

/**
 * Set publication domains.
 *
 * @param object $collection
 * @param object $node
 */
function sduconnect_set_domains($collection, $node) {
  if (module_exists('domain')) {
    // @todo
  }
}
