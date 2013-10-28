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
          0 => 13,
          1 => 15,
        ),
      ),
      2 => array(
        'rid' => 2,
        'pid' => 4,
        'name' => '<default>',
        'crumb_action' => 'add parents',
        'crumb_action_arguments' => array(),
        'action' => 'switch',
        'handler' => 'url argument',
        'arguments' => array(),
        'children' => array(
          0 => 11,
          1 => 12,
          2 => 14,
          3 => 19,
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
        'pid' => 1,
        'name' => '<default>',
        'crumb_action' => '',
        'crumb_action_arguments' => array(),
        'action' => 'switch',
        'handler' => 'node type',
        'arguments' => array(),
        'children' => array(
          0 => 10,
          1 => 17,
          2 => 23,
        ),
      ),
      5 => array(
        'rid' => 5,
        'pid' => 2,
        'name' => 'dashboard',
        'crumb_action' => '',
        'crumb_action_arguments' => array(),
        'action' => 'leave',
        'restore' => FALSE,
        'children' => array(),
      ),
      6 => array(
        'rid' => 6,
        'pid' => 4,
        'name' => 'forum',
        'crumb_action' => 'add single link',
        'crumb_action_arguments' => array(
          'title' => 'Forum',
          'translate' => 0,
          'remove_tokens' => 0,
          'path' => 'forum',
        ),
        'action' => 'goto',
        'destination' => 8,
        'children' => array(
          0 => 16,
        ),
      ),
      7 => array(
        'rid' => 7,
        'pid' => 2,
        'name' => 'forum',
        'crumb_action' => 'add single link',
        'crumb_action_arguments' => array(
          'title' => 'Forum',
          'translate' => 0,
          'remove_tokens' => 0,
          'path' => 'forum',
        ),
        'action' => 'goto',
        'destination' => 9,
        'children' => array(
          0 => 18,
        ),
      ),
      8 => array(
        'rid' => 8,
        'pid' => 6,
        'name' => 'forumpath',
        'crumb_action' => 'add forum path',
        'crumb_action_arguments' => array(
          'inc_containers' => 0,
        ),
        'action' => 'goto',
        'destination' => 2,
        'children' => array(),
      ),
      9 => array(
        'rid' => 9,
        'pid' => 7,
        'name' => 'forumpath',
        'crumb_action' => 'add forum path',
        'crumb_action_arguments' => array(
          'inc_containers' => 0,
        ),
        'action' => 'leave',
        'restore' => FALSE,
        'children' => array(),
      ),
      10 => array(
        'rid' => 10,
        'pid' => 2,
        'name' => 'node',
        'crumb_action' => 'add link to node',
        'crumb_action_arguments' => array(),
        'action' => 'leave',
        'restore' => FALSE,
        'children' => array(),
      ),
      11 => array(
        'rid' => 11,
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
      12 => array(
        'rid' => 12,
        'pid' => 4,
        'name' => 'wiki',
        'crumb_action' => 'add single link',
        'crumb_action_arguments' => array(
          'title' => 'Wiki',
          'translate' => 0,
          'remove_tokens' => 0,
          'path' => 'wiki',
        ),
        'action' => 'goto',
        'destination' => 13,
        'children' => array(
          0 => 24,
        ),
      ),
      13 => array(
        'rid' => 13,
        'pid' => 12,
        'name' => 'wikipage',
        'crumb_action' => 'add wiki page',
        'crumb_action_arguments' => array(),
        'action' => 'leave',
        'restore' => FALSE,
        'children' => array(),
      ),
    ),
    'nodetypes' => array(
      'agenda' => array(
        'path' => 'actueel/agenda',
        'title' => 'Agenda',
      ),
      'announcement' => array(
        'path' => 'bekendmakingen',
        'title' => 'Bekendmakingen',
      ),
      'message' => array(
        'path' => 'berichten',
        'title' => 'Berichten',
      ),
      'blog' => array(
        'path' => 'blogs',
        'title' => 'Blogs',
      ),
      'faq' => array(
        'path' => 'veelgestelde-vragen',
        'title' => 'Veelgestelde vragen',
      ),
      'marketplace' => array(
        'path' => 'actueel/marktplaats',
        'title' => 'Marktplaats',
      ),
      'news' => array(
        'path' => 'actueel/nieuws',
        'title' => 'Nieuws',
      ),
      'wiki' => array(
        'path' => 'wiki',
        'title' => 'Wiki',
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
        'announcement' => array(
          'path' => 'bekendmakingen',
          'title' => 'Bekendmakingen',
        ),
        'message' => array(
          'path' => 'berichten',
          'title' => 'Berichten',
        ),
        'blog' => array(
          'path' => 'blogs',
          'title' => 'Blogs',
        ),
        'faq' => array(
          'path' => 'veelgestelde-vragen',
          'title' => 'Veelgestelde vragen',
        ),
        'marketplace' => array(
          'path' => 'actueel/marktplaats',
          'title' => 'Marktplaats',
        ),
        'news' => array(
          'path' => 'actueel/nieuws',
          'title' => 'Nieuws',
        ),
        'wiki' => array(
          'path' => 'wiki',
          'title' => 'Wiki',
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
