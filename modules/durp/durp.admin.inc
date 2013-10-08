<?php
define('DURP_MANIFEST_DEFAULT', 'http://dimpact.dev/manifest2012.xml');

/**
 * Form callback for 'admin/settings/config/durp'.
 */
function durp_admin_settings_form($form, &$form_state) {
  $form = array();

  // Actions
  $form['durp_actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('durp Actions'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['durp_actions']['run-all'] = array(
    '#type' => 'submit',
    '#value' => t('Run all'),
    '#submit' => array('durp_batch_run_all_submit'),
  );

  // Settings
  $form['durp_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['durp_settings']['durp_manifest'] = array(
    '#type' => 'textfield',
    '#title' => t('Manifest'),
    '#description' => t('For example "!manifest"', array('!manifest' => DURP_MANIFEST_DEFAULT)),
    '#default_value' => variable_get('durp_manifest', DURP_MANIFEST_DEFAULT),
  );

  return system_settings_form($form);
}

/**
 * Run all submit handler for durp page.
 */
function durp_batch_run_all_submit($form, &$form_state) {
  $batch = array(
    'title' => t('Processing durp run all'),
    'operations' => array(
      array('_durp_batch_run', array())
    ),
    'finished' => '_durp_batch_run_finished',
    'file' => drupal_get_path('module', 'durp') . '/durp.admin.inc',
  );

  batch_set($batch);
}

/*
 * Callback for durp Batch.
 */
function _durp_batch_run(&$context) {
  $xmlReader = new XMLReader;
  $xmlReader->open(variable_get('durp_manifest', DURP_MANIFEST_DEFAULT));

// move to the first <product /> node
  while ($xmlReader->read() && $xmlReader->name !== 'Dossier');

  while ($xmlReader->name === 'Dossier') {
    $node = _durp_map_node($xmlReader->getAttribute('Id'), $xmlReader->readOuterXml());
    if ($node) {
      $context['results'][] = $node->title . ' [nid:' . $node->nid . ']';
    }
    $xmlReader->next('Dossier');
  }

  $context['finished'] = 1;
}

/**
 * Batch 'finished' callback
 */
function _durp_batch_run_finished($success, $results, $operations) {
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