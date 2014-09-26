<?php
/**
 * @file
 * dimpact_dominion.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dimpact_dominion_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_access_exclude';
  $strongarm->value = 'user
user/login
user/register
user/password
user/reset/*';
  $export['dominion_access_exclude'] = $strongarm;

  return $export;
}
