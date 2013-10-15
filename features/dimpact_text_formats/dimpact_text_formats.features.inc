<?php
/**
 * @file
 * dimpact_text_formats.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_text_formats_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
}
