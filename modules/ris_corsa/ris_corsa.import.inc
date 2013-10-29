<?php
/*
 * Callback for RIS Batch.
 */
function _ris_corsa_import_batch_run(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }

  file_scan_directory(variable_get('ris_corsa_dir', ''), '/\.xml/i', array('callback' => '_ris_corsa_read_file'));

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = 1; // $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function _ris_corsa_read_file($filename) {
  $xmlReader = new XMLReader;
  $xmlReader->open($filename);
  $xmlReader->read();

  //drupal_set_message($filename . ' ' . $xmlReader->name);

  // Move to the first <result> node.
  //while ($xmlReader->read() && $xmlReader->name !== 'result');
}