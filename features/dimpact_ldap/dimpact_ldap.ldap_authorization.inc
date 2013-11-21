<?php
/**
 * @file
 * dimpact_ldap.ldap_authorization.inc
 */

/**
 * Implements hook_default_ldap_authorization().
 */
function dimpact_ldap_default_ldap_authorization() {
  $export = array();

  $consumer_type = new stdClass();
  $consumer_type->disabled = FALSE; /* Edit this to true to make a default consumer_type disabled initially */
  $consumer_type->api_version = 1;
  $consumer_type->sid = 'localhost';
  $consumer_type->consumer_type = 'drupal_role';
  $consumer_type->consumer_module = 'ldap_authorization_drupal_role';
  $consumer_type->status = TRUE;
  $consumer_type->only_ldap_authenticated = TRUE;
  $consumer_type->use_first_attr_as_groupid = TRUE;
  $consumer_type->mappings = 'a:3:{i:0;a:6:{s:12:"user_entered";s:9:"redacteur";s:4:"from";s:8:"redactie";s:10:"normalized";s:9:"redacteur";s:10:"simplified";s:9:"redacteur";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:1;a:6:{s:12:"user_entered";s:13:"eindredacteur";s:4:"from";s:12:"eindredactie";s:10:"normalized";s:13:"eindredacteur";s:10:"simplified";s:13:"eindredacteur";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:2;a:6:{s:12:"user_entered";s:10:"medewerker";s:4:"from";s:11:"medewerkers";s:10:"normalized";s:10:"medewerker";s:10:"simplified";s:10:"medewerker";s:5:"valid";b:1;s:13:"error_message";s:0:"";}}';
  $consumer_type->use_filter = TRUE;
  $consumer_type->synch_to_ldap = FALSE;
  $consumer_type->synch_on_logon = TRUE;
  $consumer_type->revoke_ldap_provisioned = TRUE;
  $consumer_type->create_consumers = FALSE;
  $consumer_type->regrant_ldap_provisioned = TRUE;
  $export['drupal_role'] = $consumer_type;

  return $export;
}
