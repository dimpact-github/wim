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
        'module' => 'menu',
        'delta' => 'menu-toptaken',
      ),
      1 => array(
        'module' => 'quicktabs',
        'delta' => 'nieuws_agenda',
      ),
      2 => array(
        'module' => 'views',
        'delta' => 'agenda-block_1',
      ),
      3 => array(
        'module' => 'views',
        'delta' => 'agenda-block_2',
      ),
      4 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_1',
      ),
      5 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_2',
      ),
      6 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block',
      ),
    ),
    'nodetypes' => array(
      0 => array(
        'nodetype' => 'editorial',
      ),
    ),
  );
  return $sets;
}
