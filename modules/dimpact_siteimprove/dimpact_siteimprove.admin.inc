<?php

/**
 * Form callback for 'admin/config/system/siteimprove'.
 */
function siteimprove_admin_settings_form($form, &$form_state) {
  $form = array();

  if (user_access('administer site configuration')) {
    // Settings
    $form['siteimprove_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['siteimprove_settings']['dimpact_siteimprove_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Account ID'),
      '#description' => t('The ID of the Siteimprove account.'),
      '#default_value' => variable_get('dimpact_siteimprove_id'),
    );
  }

  return system_settings_form($form);
}
