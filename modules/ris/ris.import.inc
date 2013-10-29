<?php

function ris_import_batch_start() {
  $batch = array(
    'title' => t('Processing RIS run all'),
    'operations' => array(),
    'finished' => '_ris_import_batch_run_finished',
    'file' => drupal_get_path('module', 'ris') . '/ris.import.inc',
  );

  $ris_info = module_invoke_all('ris_info');
  foreach ($ris_info as $type_info) {
    $batch['operations'][] = array('_ris_import_batch_run', array($type_info));
  }
  batch_set($batch);

  if (function_exists('drush_backend_batch_process')) {
    // Drush does not start the batch automatically, but we cannot skip
    // this batch without side effects.
    drush_backend_batch_process();
  }
}

/*
 * Callback for RIS Batch.
 */
function _ris_import_batch_run($type_info, &$context) {
  // Shorten the timeout for external files.
  ini_set('default_socket_timeout', 1);

  include_once $type_info['batch_file'];
  $callback = $type_info['batch_callback'];
  $callback($context);
}

/**
 * Batch 'finished' callback
 */
function _ris_import_batch_run_finished($success, $results, $operations) {
  if (isset($results['count'])) {
    drupal_set_message(format_plural($results['count'], '1 node imported successfully. ', '@count nodes imported.'));
  }
}