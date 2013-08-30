<?php
/**
 * @file
 * dimpact_felix.features.felix_region.inc
 */

/**
 * Implements hook_felix_default_regions().
 */
function dimpact_felix_felix_default_regions() {
  $regions = array();
  $regions['regio-3-12-3-9'] = array(
    'name' => 'regio-3-12-3-9',
    'title' => 'Regio 3/12 (3/9)',
    'region' => 'region_39_first',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-3-12-9-3'] = array(
    'name' => 'regio-3-12-9-3',
    'title' => 'Regio 3/12 (9/3)',
    'region' => 'region_93_second',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-3-12-first-3-6-3'] = array(
    'name' => 'regio-3-12-first-3-6-3',
    'title' => 'Regio 3/12 (first 3/6/3)',
    'region' => 'region_363_first',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-3-12-third-3-6-3'] = array(
    'name' => 'regio-3-12-third-3-6-3',
    'title' => 'Regio 3/12 (third 3/6/3)',
    'region' => 'region_363_third',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-4-12-first'] = array(
    'name' => 'regio-4-12-first',
    'title' => 'Regio 4/12 first',
    'region' => 'region_444_first',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-4-12-second'] = array(
    'name' => 'regio-4-12-second',
    'title' => 'Regio 4/12 second',
    'region' => 'region_444_second',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-4-12-third'] = array(
    'name' => 'regio-4-12-third',
    'title' => 'Regio 4/12 third',
    'region' => 'region_444_third',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-6-12-content-bottom'] = array(
    'name' => 'regio-6-12-content-bottom',
    'title' => 'Regio 6/12 content bottom',
    'region' => 'content_bottom',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-6-12-content-top'] = array(
    'name' => 'regio-6-12-content-top',
    'title' => 'Regio 6/12 content top',
    'region' => 'content_top',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-9-12-3-9'] = array(
    'name' => 'regio-9-12-3-9',
    'title' => 'Regio 9/12 (3/9)',
    'region' => 'region_39_second',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['regio-9-12-9-3'] = array(
    'name' => 'regio-9-12-9-3',
    'title' => 'Regio 9/12 (9/3)',
    'region' => 'region_93_first',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['volle-breedte-boven'] = array(
    'name' => 'volle-breedte-boven',
    'title' => 'Volle breedte boven',
    'region' => 'region_full_top',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  $regions['volle-breedte-onder'] = array(
    'name' => 'volle-breedte-onder',
    'title' => 'Volle breedte onder',
    'region' => 'region_full_bottom',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
      ),
    ),
  );
  return $regions;
}