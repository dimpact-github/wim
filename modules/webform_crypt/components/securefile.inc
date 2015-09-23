<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_securefile() {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_defaults_file();
}


/**
 * Implements _webform_theme_component().
 */
function _webform_theme_securefile() {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_theme_file();
}


/**
 * Implements _webform_edit_component().
 */
function _webform_edit_securefile($component) {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_edit_file($component);
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_securefile($component, $value = NULL, $filter = TRUE) {
  $node = isset($component['nid']) ? node_load($component['nid']) : NULL;

  // Cap the upload size according to the PHP limit.
  $max_filesize = parse_size(file_upload_max_size());
  $set_filesize = $component['extra']['filtering']['size'];
  if (!empty($set_filesize) && parse_size($set_filesize) < $max_filesize) {
    $max_filesize = parse_size($set_filesize);
  }

  $element = array(
    '#type' => 'managed_file',
    '#encrypt_after_upload' => TRUE,
    '#title' => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#title_display' => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
    '#required' => $component['mandatory'],
    '#default_value' => isset($value[0]) ? $value[0] : NULL,
    '#attributes' => $component['extra']['attributes'],
    '#upload_validators' => array(
      'file_validate_size' => array($max_filesize),
      'file_validate_extensions' => array(implode(' ', $component['extra']['filtering']['types'])),
    ),
    '#pre_render' => array_merge(element_info_property('managed_file', '#pre_render'), array('webform_file_allow_access')),
    '#upload_location' => $component['extra']['scheme'] . '://webform/' . $component['extra']['directory'],
    '#progress_indicator' => $component['extra']['progress_indicator'],
    '#description' => $filter ? _webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
    '#weight' => $component['weight'],
    '#theme_wrappers' => array('webform_element'),
    '#translatable' => array('title', 'description'),
  );

  return $element;
}

/**
 * Implements _webform_submit_component().
 */
function _webform_submit_securefile($component, $value) {
  module_load_include('inc', 'webform', 'components/file');
  $fid = _webform_submit_file($component, $value);
  if ($fid) {
    // @todo: Encrypt file if not already done.

  }
  return $fid;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_securefile($component, $value, $format = 'html') {
  return array();
  module_load_include('inc', 'webform', 'components/file');
  return _webform_display_file($component, $value, $format);
}

/**
 * Implements _webform_delete_component().
 */
function _webform_delete_securefile($component, $value) {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_delete_file($component, $value);
}

/**
 * Implements _webform_analysis_component().
 */
function _webform_analysis_securefile($component, $sids = array()) {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_analysis_file($component, $sids);
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_securefile($component, $value) {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_table_file($component, $value);
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_securefile($component, $export_options) {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_csv_headers_file($component, $export_options);
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_securefile($component, $export_options, $value) {
  module_load_include('inc', 'webform', 'components/file');
  return _webform_csv_data_file($component, $export_options, $value);
}

/**
 * Implements _webform_attachments_component().
 */
function _webform_attachments_securefile($component, $value) {
  $file = (array) webform_crypt_load_file($value[0]);
  //This is necessary until the next release of mimemail is out, see [#1388786]
  $file['filepath'] = $file['uri'];
  $files = array($file);
  return $files;
}
