<?php

/**
 * Encrypt data.
 *
 * @param string $data
 * @return string
 */
function webform_crypt_encrypt($data) {
  return '~' . base64_encode(encrypt($data));
}

/**
 * Decrypt data if encrypted.
 *
 * @param string $data
 * @return string
 */
function webform_crypt_decrypt($data) {
  if (preg_match('/^~[a-zA-Z0-9\/\r\n+]*={0,2}$/', $data)) {
    return decrypt(base64_decode(substr($data, 1)));
  }
  return $data;
}

/**
 * Get list of component id's for file fields.
 *
 * @param int $nid
 */
function webform_crypt_file_components($nid) {
  $components = array();
  $sql = 'SELECT cid, type
  FROM {webform_component}
  WHERE nid = %d
  AND type IN (\'securefile\')';
  $res = db_query($sql, $nid);
  while ($component = db_fetch_object($res)) {
    $components[] = $component->cid;
  }
  return $components;
}
