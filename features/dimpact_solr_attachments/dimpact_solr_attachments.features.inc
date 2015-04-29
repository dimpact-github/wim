<?php
/**
 * @file
 * dimpact_solr_attachments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_solr_attachments_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
