<?php

/**
 * Form callback for 'admin/settings/config/atos-esuite'.
 */
function atos_esuite_admin_settings_form($form, &$form_state) {
  $form = array();

  // Actions.
  $form['atos_esuite_actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Atos esuite actions'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['atos_esuite_actions']['run-all'] = array(
    '#type' => 'submit',
    '#value' => t('Run all'),
    '#submit' => array('atos_esuite_batch_run_all_submit'),
  );

  // Settings.
  $form['atos_esuite_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['atos_esuite_settings']['atos_esuite_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Atos search callback'),
    '#default_value' => variable_get('atos_esuite_url', ''),
    '#description' => t('Full url to the search.xml callback. Do not include a query string.'),
  );

  $form['atos_esuite_settings']['atos_esuite_chunk_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Chunk site'),
    '#default_value' => variable_get('atos_esuite_chunk_size', 10),
    '#description' => t('Number of items to fetch per request'),
  );

  $form['atos_esuite_settings']['atos_esuite_finish_margin'] = array(
    '#type' => 'textfield',
    '#title' => t('Finished margin'),
    '#default_value' => variable_get('atos_esuite_finish_margin', 250),
    '#description' => t('Mark process as finished after retreiving this number of empty responses. This is required because a list of all elements is not available. We iterate over the id\'s.'),
  );

  return system_settings_form($form);
}

/**
 * Run all submit handler for atos_esuite page.
 */
function atos_esuite_batch_run_all_submit($form, &$form_state) {
  module_load_include('inc', 'atos_esuite', 'atos_esuite.import');
  atos_esuite_import_batch_start(array('product', 'vac'));
}
