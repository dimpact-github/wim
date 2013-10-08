<?php
/**
 * Form callback for 'admin/settings/config/gvop'.
 */
function gvop_admin_settings_form($form, &$form_state) {
  $form = array();

  // Actions
  $form['gvop_actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('GVOP Actions'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['gvop_actions']['run-all'] = array(
    '#type' => 'submit',
    '#value' => t('Run all'),
    '#submit' => array('gvop_batch_run_all_submit'),
  );

  // Settings
  $form['gvop_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['gvop_settings']['gvop_creator'] = array(
    '#type' => 'textfield',
    '#title' => t('Creator'),
    '#description' => t('For example "amsterdam"'),
    '#default_value' => variable_get('gvop_creator', 'amsterdam'),
  );
  $form['gvop_settings']['gvop_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Limit'),
    '#description' => t('For example "100"'),
    '#default_value' => variable_get('gvop_limit', 100),
  );

  return system_settings_form($form);
}

/**
 * Run all submit handler for GVOP page.
 */
function gvop_batch_run_all_submit($form, &$form_state) {
  $batch = array(
    'title' => t('Processing GVOP run all'),
    'operations' => array(),
    'finished' => '_gvop_batch_run_finished',
    'file' => drupal_get_path('module', 'gvop') . '/gvop.admin.inc',
  );

  $gvop_info = module_invoke_all('gvop_info');
  foreach ($gvop_info as $type_info) {
    $batch['operations'][] = array('_gvop_batch_run', array($type_info));
  }
  batch_set($batch);
}

/*
 * Callback for GVOP Batch.
 */
function _gvop_batch_run($type_info, &$context) {
  // Setup Sandbox data.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $dom = _gvop_retrieve_dom($type_info, 0, 1);
    $context['sandbox']['max'] = (int)$dom->getElementsByTagName('numberOfRecords')->item(0)->nodeValue;
  }

  $dom = _gvop_retrieve_dom($type_info, $context['sandbox']['progress'], variable_get('gvop_limit', 100));
  $xpath = new DOMXPath($dom);
  $records = $dom->getElementsByTagName("gzd");

  foreach ($records as $record) {
    $context['message'] = t('Now processing !current / !max', array('!current' => $context['sandbox']['progress'], '!max' => $context['sandbox']['max']));
    $context['sandbox']['progress']++;

    $node = _gvop_map_node($type_info, $record, $xpath);
    if ($node) {
      $context['results'][] = $node->type . ': ' . $node->title . ' [nid:' . $node->nid . ']';
    }
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Batch 'finished' callback
 */
function _gvop_batch_run_finished($success, $results, $operations) {
  if ($success) {
    $message = count($results) .' results processed:';
    $message .= theme('item_list', array('items' => $results));
    drupal_set_message($message);
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