<?php

/**
 * Available on <domain>/admin/config/search/c-content/webfinder.
 * Generates the configuration form.
 * @return type
 */
function c_content_webfinder_admin() {
  $form = array();

  $defaults = variable_get('c_content_webfinder');
  $form['c_content_webfinder'] = array(
    '#type' => 'fieldset',
    '#title' => t('Webfinder'),
    '#tree' => TRUE,
  );

  $form['c_content_webfinder']['server_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Server url'),
    '#description' => t('Set the url to the webfinder server that provides the rss containing the results.'),
    '#default_value' => isset($defaults['server_url']) ? $defaults['server_url'] : '',
    '#required' => TRUE,
    '#size' => 100,
  );

  global $base_url;
  $form['c_content_webfinder']['search_page_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Search page url'),
    '#description' => t('Set the url to the search page.'),
    '#field_prefix' => $base_url,
    '#field_suffix' => '/%searchterm',
    '#default_value' => isset($defaults['search_page_url']) ? $defaults['search_page_url'] : 'search/c-content',
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['c_content_webfinder']['items_per_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Items per page'),
    '#description' => t('Set the amount of items per page.'),
    '#default_value' => isset($defaults['items_per_page']) ? $defaults['items_per_page'] : 10,
    '#required' => TRUE,
  );

  $form['c_content_webfinder']['pre_filter_source'] = array(
    '#type' => 'textfield',
    '#title' => t('Pre filter on source'),
    '#description' => t('Define a specific source to pre filter on, this limits results to only display results from the configured source.'),
    '#default_value' => isset($defaults['pre_filter_source']) ? $defaults['pre_filter_source'] : '',
    '#required' => FALSE,
  );

  $form['c_content_webfinder']['search_format_parameters'] = array(
    '#type' => 'textfield',
    '#title' => t('Search format parameters'),
    '#description' => t('Define the search format parameters to use for searching.'),
    '#default_value' => isset($defaults['search_format_parameters']) ? $defaults['search_format_parameters'] : 'rss opensearch mylex',
    '#required' => TRUE,
  );

  $form['#submit'][] = '_c_content_webfinder_submit';

  return system_settings_form($form);
}

function _c_content_webfinder_submit($form, &$form_state) {
  // Rebuild menu because search page url may be changed.
  menu_rebuild();
}