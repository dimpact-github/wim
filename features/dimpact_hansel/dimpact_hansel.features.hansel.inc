<?php
/**
 * @file
 * dimpact_hansel.features.hansel.inc
 */

/**
 * Implements hook_hansel_default().
 */
function dimpact_hansel_hansel_default() {
  $elements = array();
  $elements['config'] = array(
    'version' => 1,
    'start_rid' => 1,
    'rules' => array(
      1 => array(
        'rid' => 1,
        'pid' => NULL,
        'name' => 'start',
        'crumb_action' => 'add single link',
        'crumb_action_arguments' => array(
          'title' => 'Home',
          'translate' => 0,
          'remove_tokens' => 0,
          'path' => '<front>',
        ),
        'action' => 'switch',
        'handler' => 'blueprint',
        'arguments' => array(),
        'children' => array(
          0 => 10,
          1 => 13,
        ),
      ),
      2 => array(
        'rid' => 2,
        'pid' => 1,
        'name' => '<default>',
        'crumb_action' => 'add parents',
        'crumb_action_arguments' => array(),
        'action' => 'switch',
        'handler' => 'url argument',
        'arguments' => array(),
        'children' => array(
          0 => 11,
          1 => 12,
        ),
      ),
      3 => array(
        'rid' => 3,
        'pid' => 2,
        'name' => '<default>',
        'crumb_action' => 'add link to current page',
        'crumb_action_arguments' => array(),
        'action' => 'leave',
        'restore' => FALSE,
        'children' => array(),
      ),
      4 => array(
        'rid' => 4,
        'pid' => 2,
        'name' => 'node',
        'crumb_action' => 'add link to node',
        'crumb_action_arguments' => array(),
        'action' => 'leave',
        'restore' => FALSE,
        'children' => array(),
      ),
      5 => array(
        'rid' => 5,
        'pid' => 1,
        'name' => 'team',
        'crumb_action' => 'add parent subsites',
        'crumb_action_arguments' => array(
          'include_self' => 1,
          'include_root' => 0,
        ),
        'action' => 'goto',
        'destination' => 2,
        'children' => array(),
      ),
    ),
    'nodetypes' => array(
      'agenda' => array(
        'path' => 'actueel/agenda',
        'title' => 'Agenda',
      ),
      'news' => array(
        'path' => 'actueel/nieuws',
        'title' => 'Nieuws',
      ),
    ),
  );
  $elements['settings'] = array(
    'variables' => array(
      'hansel_breadcrumb_last_item_hide' => 0,
      'hansel_breadcrumb_last_item_link' => 1,
      'hansel_cache' => 0,
      'hansel_max_item_count' => 0,
      'hansel_max_item_length' => 0,
      'hansel_nodetypes' => array(
        'agenda' => array(
          'path' => 'actueel/agenda',
          'title' => 'Agenda',
        ),
        'news' => array(
          'path' => 'actueel/nieuws',
          'title' => 'Nieuws',
        ),
      ),
      'hansel_parent_lookup_paths' => 0,
      'hansel_removed_items_replacement' => '(...)',
      'hansel_remove_first_token_item' => 1,
      'hansel_set_menu_item' => 1,
      'hansel_set_menu_item_skip_first' => 1,
      'hansel_set_menu_name' => 0,
      'hansel_trim_ellipsis' => '...',
      'hansel_trim_on_word_boundary' => 1,
    ),
  );
  return $elements;
}
