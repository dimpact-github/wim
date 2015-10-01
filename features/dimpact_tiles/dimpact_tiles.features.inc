<?php
/**
 * @file
 * dimpact_tiles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_tiles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dimpact_tiles_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dimpact_tiles_node_info() {
  $items = array(
    'tile' => array(
      'name' => t('Tegel'),
      'base' => 'node_content',
      'description' => t('Dit inhoudstype kan worden gebruikt bij speciale tegeloverzichtpagina\'s.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
