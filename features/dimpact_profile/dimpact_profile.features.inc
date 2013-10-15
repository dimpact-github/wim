<?php
/**
 * @file
 * dimpact_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
