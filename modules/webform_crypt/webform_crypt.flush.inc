<?php

/**
 * Flush old submissions from webforms.
 */
function webform_crypt_flush_submissions() {
  if ($interval = (int) variable_get('webform_crypt_flush_submissions_after', 86400 * 7)) {
    // Delete old submissions.
    $sql = 'SELECT ws.*
    FROM webform_submissions ws
    JOIN node n ON ws.nid = n.nid
    WHERE n.type = \'webform\'
    AND ws.is_draft = 0
    AND ws.submitted < UNIX_TIMESTAMP() - :interval
    ORDER BY ws.sid DESC
    LIMIT 10';
    $rows = db_query($sql, array(':interval' => $interval));
    while ($submission = $rows->fetchObject()) {
      webform_crypt_flush_submission($submission);
    }
  }

  if ($interval = (int) variable_get('webform_crypt_flush_drafts_after', 86400)) {
    // Delete old drafts.
    $sql = 'SELECT ws.*
    FROM webform_submissions ws
    JOIN node n ON ws.nid = n.nid
    WHERE n.type = \'webform\'
    AND ws.is_draft = 1
    AND ws.submitted < UNIX_TIMESTAMP() - :interval
    ORDER BY ws.sid DESC
    LIMIT 10';
    $rows = db_query($sql, array(':interval' => $interval));
    while ($submission = $rows->fetchObject()) {
      webform_crypt_flush_submission($submission);
    }
  }
}

/**
 * Delete a webform submission.
 *
 * @param mixed $submission Submission id or submission object
 * @return bool
 */
function webform_crypt_flush_submission($submission) {
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  if (!is_object($submission)) {
    $submission = db_select('webform_submissions', 'ws')
      ->condition('ws.sid', $submission)
      ->execute()
      ->fetchObject();
    if (!$submission) {
      return FALSE;
    }
  }
  if ($node = node_load($submission->nid, NULL, memory_get_usage() > 50 * 1024 * 1024)) {
    // The full submission data is required to delete submissions.
    $submission = webform_get_submission($submission->nid, $submission->sid);
    webform_submission_delete($node, $submission);
    return TRUE;
  }
  return FALSE;
}
