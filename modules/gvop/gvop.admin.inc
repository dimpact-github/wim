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
    '#default_value' => variable_get('gvop_creator', ''),
  );
  $form['gvop_settings']['gvop_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Limit'),
    '#description' => t('For example "20"'),
    '#default_value' => variable_get('gvop_limit', 20),
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
