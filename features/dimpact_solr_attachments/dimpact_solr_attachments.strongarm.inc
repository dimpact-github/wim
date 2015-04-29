<?php
/**
 * @file
 * dimpact_solr_attachments.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dimpact_solr_attachments_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_attachments_filesize_limit';
  $strongarm->value = '52428800';
  $export['apachesolr_attachments_filesize_limit'] = $strongarm;

  return $export;
}
