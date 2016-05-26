<?php

/**
 * Admin settings form.
 */
function content_reminder_admin_form($form, &$form_state) {

  module_load_include('inc', 'dimpact_content_reminder', 'dimpact_content_reminder');
  $types = _get_reminder_types();

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form to configure content reminders for each content types.'),
  );
  $form['content_reminder_reminder_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject for content reminder mails'),
    '#default_value' => variable_get('content_reminder_reminder_subject', 'Je moet @count item(s) bekijken'),
    '#description' => t('The token %token will be replaced by the number of nodes.', array('%token' => '@count')),
  );
  $form['content_reminder_reminder_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for content reminder mails'),
    '#default_value' => variable_get('content_reminder_reminder_text', 'Inhoud die verlopen is of binnenkort verloopt.'),
  );
  $form['content_reminder_expire_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject for expired content mails'),
    '#default_value' => variable_get('content_reminder_expire_subject', '@count item(s) zijn verlopen en offline geplaatst'),
    '#description' => t('The token %token will be replaced by the number of nodes.', array('%token' => '@count')),
  );
  $form['content_reminder_expire_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for expired content mails'),
    '#default_value' => variable_get('content_reminder_expire_text', 'Inhoud die verlopen is of binnenkort verloopt.'),
  );
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
      '#title' => t('Send reminder e-mail?'),
      '#default_value' => variable_get('content_reminder_types_' . $type->type, 0),
      );
    $form['content_reminder_types_' . $type->type . '_days'] = array(
      '#type' => 'textfield',
      '#title' => t('Days to e-mail reminder'),
      '#default_value' => variable_get('content_reminder_types_' . $type->type . '_days', 182),
      '#maxlength' => 255,
      '#element_validate' => 'element_validate_number',
      );
    $form['content_reminder_types_' . $type->type . '_depub_box'] = array(
      '#type' => 'checkbox',
      '#title' => t('Unpublish content when expired?'),
      '#default_value' => variable_get('content_reminder_types_' . $type->type . '_depub_box', 0),
      );
    $form['content_reminder_types_' . $type->type . '_depub'] = array(
      '#type' => 'textfield',
      '#title' => t('Days to expired content.'),
      '#default_value' => variable_get('content_reminder_types_' . $type->type . '_depub', 213),
      '#maxlength' => 255,
      '#element_validate' => 'element_validate_number',
      );
  }

  return system_settings_form($form);
}