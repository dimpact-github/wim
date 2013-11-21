<?php
/**
 * @file
 * dimpact_ldap.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_ldap_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ldap_authorization" && $api == "ldap_authorization") {
    return array("version" => "1");
  }
  if ($module == "ldap_servers" && $api == "ldap_servers") {
    return array("version" => "1");
  }
}
