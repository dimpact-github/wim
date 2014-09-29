<?php
/**
 * @file
 * dimpact_files.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dimpact_files_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_entity_allowed_entity_types';
  $strongarm->value = array(
    'file' => array(
      'image' => array(
        'domain_entity_user_multiple_choice' => array(
          'DOMAIN_ACTIVE' => 'DOMAIN_ACTIVE',
        ),
      ),
      'video' => array(
        'domain_entity_user_multiple_choice' => array(
          'DOMAIN_ACTIVE' => 'DOMAIN_ACTIVE',
        ),
      ),
      'audio' => array(
        'domain_entity_user_multiple_choice' => array(
          'DOMAIN_ACTIVE' => 'DOMAIN_ACTIVE',
        ),
      ),
      'document' => array(
        'domain_entity_user_multiple_choice' => array(
          'DOMAIN_ACTIVE' => 'DOMAIN_ACTIVE',
        ),
      ),
    ),
  );
  $export['domain_entity_allowed_entity_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_entity_bypass_access_conditions';
  $strongarm->value = 0;
  $export['domain_entity_bypass_access_conditions'] = $strongarm;

  return $export;
}
