<?php
/**
 * Form callback for 'admin/settings/config/atos_esuite'.
 */
function atos_esuite_admin_settings_form($form, &$form_state) {
  $form = array();

  // Actions
  $form['atos_esuite_actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('atos_esuite Actions'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['atos_esuite_actions']['run-all'] = array(
    '#type' => 'submit',
    '#value' => t('Run all'),
    '#submit' => array('atos_esuite_batch_run_all_submit'),
  );

  // Settings
  $form['atos_esuite_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['atos_esuite_settings']['atos_esuite_pdc_url'] = array(
    '#type' => 'textfield',
    '#title' => t('PDC Url'),
    '#description' => t('For example "!url"', array('!url' => ATOS_ESUITE_DEFAULT_PDC_URL)),
    '#default_value' => variable_get('atos_esuite_pdc_url', ATOS_ESUITE_DEFAULT_PDC_URL),
  );

  $form['atos_esuite_settings']['atos_esuite_vac_url'] = array(
    '#type' => 'textfield',
    '#title' => t('VAC Url'),
    '#description' => t('For example "!url"', array('!url' => ATOS_ESUITE_DEFAULT_VAC_URL)),
    '#default_value' => variable_get('atos_esuite_manifest', ATOS_ESUITE_DEFAULT_VAC_URL),
  );

  return system_settings_form($form);
}

/**
 * Run all submit handler for atos_esuite page.
 */
function atos_esuite_batch_run_all_submit($form, &$form_state) {
  $batch = array(
    'title' => t('Processing atos_esuite run all'),
    'operations' => array(
      array('_atos_esuite_batch_run', array('product', ATOS_ESUITE_DEFAULT_PDC_URL)),
      array('_atos_esuite_batch_run', array('vac', ATOS_ESUITE_DEFAULT_VAC_URL)),
    ),
    'finished' => '_atos_esuite_batch_run_finished',
    'file' => drupal_get_path('module', 'atos_esuite') . '/atos_esuite.admin.inc',
  );

  batch_set($batch);
}

/*
 * Callback for Atos eSuite Batch.
 */
function _atos_esuite_batch_run($type, $url, &$context) {
  $xmlReader = new XMLReader;
  $xmlReader->open($url);

  // move to the first <product /> node
  while ($xmlReader->read() && $xmlReader->name !== 'result');

  $i = 0;
  while ($xmlReader->name === 'result' && $i < 5) {
    $node = atos_esuite_map_node($type, $xmlReader->readOuterXml());
    if ($node) {
      $context['results'][] = $node->type . ': ' . $node->title . ' [nid:' . $node->nid . ']';
    }

    $xmlReader->next('result');
    $i++;
  }

  $context['finished'] = 1;
}

/**
 * Batch 'finished' callback
 */
function _atos_esuite_batch_run_finished($success, $results, $operations) {
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