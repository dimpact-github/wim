<?php

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
    '#value' => t('Start import'),
    '#submit' => array('durp_batch_run_all_submit'),
  );

  if (user_access('administer site configuration')) {
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
      '#description' => t('Full url to IMRO2012 formatted manifest XML file.'),
      '#default_value' => variable_get('durp_manifest', ''),
    );
  }

  return system_settings_form($form);
}

/**
 * Submit handler for "Run all" button.
 */
function durp_batch_run_all_submit($form, &$form_state) {
  module_load_include('inc', 'durp', 'durp.import');
  durp_import_batch_start();
}
