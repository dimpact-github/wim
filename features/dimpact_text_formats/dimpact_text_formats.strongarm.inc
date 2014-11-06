<?php
/**
 * @file
 * dimpact_text_formats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dimpact_text_formats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_target';
  $strongarm->value = 0;
  $export['extlink_target'] = $strongarm;

  return $export;
}
