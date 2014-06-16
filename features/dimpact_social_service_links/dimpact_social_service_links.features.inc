<?php
/**
 * @file
 * dimpact_social_service_links.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_social_service_links_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
