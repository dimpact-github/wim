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
  module_load_include('inc', 'gvop', 'gvop.import');
  gvop_import_batch_start();
}
