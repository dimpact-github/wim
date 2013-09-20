<?php
/**
 * @file
 * dimpact_felix.features.felix_block_set.inc
 */

/**
 * Implements hook_felix_default_block_sets().
 */
function dimpact_felix_felix_default_block_sets() {
  $sets = array();
  $sets['default'] = array(
    'name' => 'default',
    'title' => 'default',
    'blocks' => array(
      0 => array(
        'module' => 'block',
        'delta' => 6,
      ),
      1 => array(
        'module' => 'menu',
        'delta' => 'menu-toptaken',
      ),
      2 => array(
        'module' => 'menu_block',
        'delta' => 1,
      ),
      3 => array(
        'module' => 'quicktabs',
        'delta' => 'nieuws_agenda',
      ),
      4 => array(
        'module' => 'submenutree',
        'delta' => 1,
      ),
      5 => array(
        'module' => 'views',
        'delta' => 'agenda-block_1',
      ),
      6 => array(
        'module' => 'views',
        'delta' => 'agenda-block_2',
      ),
      7 => array(
        'module' => 'views',
        'delta' => 'favorieten-block_1',
      ),
      8 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_1',
      ),
      9 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_1',
      ),
      10 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_2',
      ),
      11 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_3',
      ),
      12 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block',
      ),
      13 => array(
        'module' => 'views',
        'delta' => 'updates-block_1',
      ),
      14 => array(
        'module' => 'views',
        'delta' => 'voorpagina_banners-block_1',
      ),
      15 => array(
        'module' => 'views',
        'delta' => 'weblog-block',
      ),
    ),
    'nodetypes' => array(
      0 => array(
        'nodetype' => 'editorial',
      ),
      1 => array(
        'nodetype' => 'slide',
      ),
    ),
  );
  return $sets;
}
