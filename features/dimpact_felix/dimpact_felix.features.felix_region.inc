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
  $regions['footer-first'] = array(
    'name' => 'footer-first',
    'title' => 'Footer first',
    'region' => 'region_footer_first',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'footer-blokken',
    'data' => array(
      'hash' => array(
        0 => 'domain',
      ),
    ),
  );
  $regions['footer-second'] = array(
    'name' => 'footer-second',
    'title' => 'Footer second',
    'region' => 'region_footer_second',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'footer-blokken',
    'data' => array(
      'hash' => array(
        0 => 'domain',
      ),
    ),
  );
  $regions['footer-third'] = array(
    'name' => 'footer-third',
    'title' => 'Footer third',
    'region' => 'region_footer_third',
    'weight' => 0,
    'context' => 'sitewide',
    'block_set' => 'footer-blokken',
    'data' => array(
      'hash' => array(
        0 => 'domain',
      ),
    ),
  );
  $regions['regio-3-12-3-9'] = array(
    'name' => 'regio-3-12-3-9',
    'title' => 'Regio 3/12 (3/9)',
    'region' => 'region_39_first',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-3-12-9-3'] = array(
    'name' => 'regio-3-12-9-3',
    'title' => 'Regio 4/12 (8/4)',
    'region' => 'region_93_second',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-3-12-first-3-6-3'] = array(
    'name' => 'regio-3-12-first-3-6-3',
    'title' => 'Regio 3/12 (3/5/4)',
    'region' => 'region_363_first',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-3-12-third-3-6-3'] = array(
    'name' => 'regio-3-12-third-3-6-3',
    'title' => 'Regio 4/12 (3/5/4)',
    'region' => 'region_363_third',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-3-12-third-3-6-3-node'] = array(
    'name' => 'regio-3-12-third-3-6-3-node',
    'title' => 'Regio 4/12 (3/5/4) Node',
    'region' => 'region_363_third',
    'weight' => 128,
    'context' => 'nodedetail',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-4-12-first'] = array(
    'name' => 'regio-4-12-first',
    'title' => 'Regio 4/12 first',
    'region' => 'region_444_first',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-4-12-second'] = array(
    'name' => 'regio-4-12-second',
    'title' => 'Regio 4/12 second',
    'region' => 'region_444_second',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-4-12-third'] = array(
    'name' => 'regio-4-12-third',
    'title' => 'Regio 4/12 third',
    'region' => 'region_444_third',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-5-12-content-bottom-node'] = array(
    'name' => 'regio-5-12-content-bottom-node',
    'title' => 'Regio 5/12 content bottom node',
    'region' => 'content_bottom',
    'weight' => 0,
    'context' => 'nodedetail',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-5-12-content-top-node'] = array(
    'name' => 'regio-5-12-content-top-node',
    'title' => 'Regio 5/12 content top node',
    'region' => 'content_top',
    'weight' => 0,
    'context' => 'nodedetail',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-6-12-content-bottom'] = array(
    'name' => 'regio-6-12-content-bottom',
    'title' => 'Regio 5/12 content bottom',
    'region' => 'content_bottom',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-6-12-content-top'] = array(
    'name' => 'regio-6-12-content-top',
    'title' => 'Regio 5/12 content top',
    'region' => 'content_top',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-9-12-3-9'] = array(
    'name' => 'regio-9-12-3-9',
    'title' => 'Regio 9/12 (3/9)',
    'region' => 'region_39_second',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['regio-9-12-9-3'] = array(
    'name' => 'regio-9-12-9-3',
    'title' => 'Regio 8/12 (8/4)',
    'region' => 'region_93_first',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['volle-breedte-boven'] = array(
    'name' => 'volle-breedte-boven',
    'title' => 'Volle breedte boven',
    'region' => 'region_full_top',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  $regions['volle-breedte-onder'] = array(
    'name' => 'volle-breedte-onder',
    'title' => 'Volle breedte onder',
    'region' => 'region_full_bottom',
    'weight' => 0,
    'context' => 'sitewide-without-node',
    'block_set' => 'default',
    'data' => array(
      'hash' => array(
        0 => 'path',
        1 => 'domain',
      ),
    ),
  );
  return $regions;
}
