<?php
/**
 * @file
 * dimpact_menus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_menus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
}
