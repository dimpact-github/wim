<?php

/**
 * Admin settings form.
 */
function content_reminder_admin_form($form, &$form_state) {

  module_load_include('inc', 'content_reminder', 'content_reminder');
  $types = _get_reminder_types();

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form to configure content reminders for each content types.'),
  );
  foreach ($types as $type) {
    $form['content_reminder_' .  $type->type . '_header'] = array(
      '#type' => 'markup',
      '#markup' => '<h2>' . $type->type . '</h2>',
      );
    $form['content_reminder_types_' . $type->type] = array(
      '#type' => 'checkbox',
      '#title' => $type->type,
      '#default_value' => variable_get('content_reminder_types_' . $type->type, 0),
      );
    $form['content_reminder_types_' . $type->type . '_days'] = array(
      '#type' => 'textfield',
      '#title' => t('Days to e-mail reminder'),
      '#default_value' => variable_get('content_reminder_types_' . $type->type . '_days', 182),
      '#maxlength' => 255,
      '#element_validate' => 'element_validate_number',
      );
    $form['content_reminder_types_' . $type->type . '_depub'] = array(
      '#type' => 'textfield',
      '#title' => t('Days to depublication'),
      '#default_value' => variable_get('content_reminder_types_' . $type->type . '_depub', 213),
      '#maxlength' => 255,
      '#element_validate' => 'element_validate_number',
      );
  }

  return system_settings_form($form);
}