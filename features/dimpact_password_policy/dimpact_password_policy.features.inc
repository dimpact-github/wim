<?php
/**
 * @file
 * dimpact_password_policy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_password_policy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
