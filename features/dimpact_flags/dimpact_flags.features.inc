<?php
/**
 * @file
 * dimpact_flags.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function dimpact_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorieten".
  $flags['favorieten'] = array(
    'entity_type' => 'node',
    'title' => 'Favorieten',
    'global' => 0,
    'types' => array(
      0 => 'agenda',
      1 => 'message',
      2 => 'blog',
      3 => 'faq',
      4 => 'marketplace',
      5 => 'news',
      6 => 'product',
      7 => 'wiki',
    ),
    'flag_short' => 'Toevoegen aan favorieten',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Verwijderen uit favorieten',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'volle_breedte' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'dimpact_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
