<?php

/**
 * Available on <domain>/admin/config/search/c-content.
 * Generates the configuration form.
 * @return type
 */
function c_content_admin() {
  $form = array();

  $form['c_content_metatags'] = array(
    '#type' => 'fieldset',
    '#title' => t('Meta tags'),
    '#tree' => TRUE,
  );

  // Get fields available for meta tags embedding.
  $fields = array();
  foreach (field_info_field_map() as $key => $field) {
    // Only allow text and taxonomy_term_reference fields for now that are available on nodes.
    if (isset($field['bundles']['node']) && ($field['type'] === 'text' || $field['type'] === 'taxonomy_term_reference')) {
      $fields[$key] = $key . ' <em>(' . t('Used in types: @bundles', array('@bundles' => implode(', ', $field['bundles']['node']))) . ')</em>';
    }
  }

  $default_value = variable_get('c_content_metatags');
  $form['c_content_metatags']['fields'] = array(
    '#type' => 'checkboxes',
    '#options' => $fields,
    '#title' => t('Which node fields should be added as meta tag to the HTML?'),
    '#default_value' => $default_value['fields'],
  );

  return system_settings_form($form);
}