<?php
/**
 * @file
 * dimpact_homebox.features.inc
 */

/**
 * Implements hook_homebox().
 */
function dimpact_homebox_homebox() {
  $homeboxes = array();

  $homeboxes['dashboard_intranet'] = array (
    'regions' => 3,
    'cache' => 0,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'views_agenda-block_2' => 
      array (
        'module' => 'views',
        'delta' => 'agenda-block_2',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -45,
      ),
      'views_favorieten-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'favorieten-block_1',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -45,
      ),
      'views_marktplaats-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'marktplaats-block_1',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -45,
      ),
      'views_nieuws-block_3' => 
      array (
        'module' => 'views',
        'delta' => 'nieuws-block_3',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -45,
      ),
      'views_updates-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'updates-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -45,
      ),
      'views_weblog-block' => 
      array (
        'module' => 'views',
        'delta' => 'weblog-block',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -45,
      ),
      'views_feeds_intranet-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'feeds_intranet-block_1',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -46,
      ),
      'views_feeds_intranet-block_2' => 
      array (
        'module' => 'views',
        'delta' => 'feeds_intranet-block_2',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -46,
      ),
    ),
    'widths' => 
    array (
    ),
    'title' => 'Dashboard',
    'path' => 'dashboard',
    'menu' => 0,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 1,
    'roles' => 
    array (
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}
