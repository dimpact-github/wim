<?php

/**
 * Implements hook_drush_command().
 */
function webform_crypt_drush_command() {
  $items = array();

  $items['encrypt-webforms'] = array(
    'description' => dt('Encrypt all webform submissions'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['decrypt-webforms'] = array(
    'description' => dt('Decrypt all webform submissions'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Callback for drush encrypt-webforms
 */
function drush_webform_crypt_encrypt_webforms() {
  _webform_crypt_batch('encrypt');
}

/**
 * Callback for drush decrypt-webforms
 */
function drush_webform_crypt_decrypt_webforms() {
  _webform_crypt_batch('decrypt');
}

/**
 * Encrypt or decrypt all submissions.
 *
 * @param string $action
 *   'encrypt' or 'decrypt'
 */
function _webform_crypt_batch($action) {
  module_load_include('inc', 'webform_crypt', 'webform_crypt.utils');

  $sql = 'SELECT COUNT(*) FROM {webform_submissions}';
  $count = db_result(db_query($sql));
  if ($count) {
    $progress = 0;
    $updated = 0;

    drush_print(dt('Updating submissions.'));

    $sql = 'SELECT sid FROM {webform_submissions} ORDER BY sid';
    $res = db_query($sql);
    while ($submission = db_fetch_object($res)) {
      if (_webform_crypt_batch_single($submission->sid, $action)) {
        ++$updated;
      }
      ++$progress;

      // Print progressbar.
      $filled = round($progress / $count * 25);
      $percent = round($progress / $count * 100);
      print("\r|" . str_repeat('=', $filled) . str_repeat('-', 25 - $filled) . "| " . str_pad($percent, 3, ' ', STR_PAD_LEFT) . '%');
    }

    print("\n");
    drush_log(dt('@count submissions updated.', array('@count' => $updated)), 'ok');
  }
  else {
    drush_print(dt('No submissions in database'));
  }
}

/**
 * Process a single submission.
 *
 * @param int $sid
 * @param string $action
 */
function _webform_crypt_batch_single($sid, $action) {
  $updated = FALSE;

  $sql = 'SELECT nid, sid, cid, no, data FROM {webform_submitted_data} WHERE sid = %d';
  $res = db_query($sql, $sid);
  while ($row = db_fetch_object($res)) {
    $files = webform_crypt_file_components($row->nid);
    if ($action == 'encrypt') {
      $new = webform_crypt_encrypt($row->data);
      if (in_array($row->cid, $files)) {
        _webform_crypt_batch_encrypt_file(webform_crypt_decrypt($row->data));
      }
    } else {
      $new = webform_crypt_decrypt($row->data);
      if (in_array($row->cid, $files)) {
        _webform_crypt_batch_decrypt_file($new);
      }
    }
    if ($new != $row->data) {
      $sql = 'UPDATE {webform_submitted_data}
      SET data = \'%s\'
      WHERE nid = %d AND sid = %d AND cid = %d AND no = \'%s\'';
      db_query($sql, $new, $row->nid, $row->sid, $row->cid, $row->no);
    }
  }

  return $updated;
}

function _webform_crypt_batch_decrypt_file($fid) {
  if ($file = webform_crypt_load_file($fid)) {
    if ($file->encrypted) {
      $parts = explode('/', $file->filepath);
      array_pop($parts);
      $filename = $file->filename;
      $filepath = implode('/', $parts) . '/' . $filename;
      $filepath = file_destination($filepath, FILE_EXISTS_RENAME);
      if (file_put_contents($filepath, $file->contents)) {
        unlink($file->filepath);
        $sql = 'UPDATE {files} SET filename = \'%s\', filepath = \'%s\' WHERE fid = %d';
        db_query($sql, $filename, $filepath, $fid);
        $sql = 'DELETE FROM {files_crypt} WHERE fid = %d';
        db_query($sql, $fid);
      }
    }
  }
}

function _webform_crypt_batch_encrypt_file($fid) {
  if ($file = webform_crypt_load_file($fid)) {
    if (!$file->encrypted) {
      $ext = preg_match('/(\\.[a-z]{2,4})$/si', $file->filepath, $match) ? $match[1] : '';
      $parts = explode('/', $file->filepath);
      $filename = md5(array_pop($parts) . $fid);
      $filepath = implode('/', $parts) . '/' . $filename;
      $filepath = file_destination($filepath, FILE_EXISTS_RENAME);
      if (file_put_contents($filepath, encrypt($file->contents))) {
        @unlink($file->filepath);
        $sql = 'UPDATE {files} SET filename = \'%s\', filepath = \'%s\' WHERE fid = %d';
        db_query($sql, $filename, $filepath, $fid);
        $sql = 'INSERT INTO {files_crypt} (fid, filename) VALUES (%d, \'%s\')';
        db_query($sql, $fid, encrypt($file->filename));
      }
    }
  }
}
