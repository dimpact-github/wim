<?php
/**
 * Form callback for 'admin/settings/config/ris'.
 */
function ris_admin_settings_form($form, &$form_state) {
  $form = array();

  // Actions
  $form['ris_actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('RIS Actions'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['ris_actions']['run-all'] = array(
    '#type' => 'submit',
    '#value' => t('Run all'),
    '#submit' => array('ris_batch_run_all_submit'),
  );

  // Settings
  $form['ris_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  return system_settings_form($form);
}

/**
 * Run all submit handler for RIS Corsa page.
 */
function ris_batch_run_all_submit($form, &$form_state) {
  module_load_include('inc', 'ris', 'ris.import');
  ris_import_batch_start();
}
