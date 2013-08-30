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
        'module' => 'views',
        'delta' => 'agenda-block_1',
      ),
      1 => array(
        'module' => 'views',
        'delta' => 'agenda-block_2',
      ),
      2 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_1',
      ),
      3 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_2',
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
