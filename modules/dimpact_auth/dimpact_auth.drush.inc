<?php

function dimpact_auth_drush_command() {
  $items = array();

  $items['dimpact-auth-update'] = array(
    'description' => 'Update local Dimpact user directory to match data from external provider.',
    'arguments' => array(
      'provider' => 'The module that provides external data for the Dimpact auth user directory.',
    ),
    'drupal dependencies' => array('dimpact_auth'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

function drush_dimpact_auth_update($provider = 'dimpact_auth_ldap_import') {
  module_load_include('inc', 'dimpact_auth', 'dimpact_auth.update');
  dimpact_auth_update($provider);
}
