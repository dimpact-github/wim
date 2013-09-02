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
        'module' => 'quicktabs',
        'delta' => 'nieuws_agenda',
      ),
      1 => array(
        'module' => 'views',
        'delta' => 'agenda-block_1',
      ),
      2 => array(
        'module' => 'views',
        'delta' => 'agenda-block_2',
      ),
      3 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_1',
      ),
      4 => array(
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
