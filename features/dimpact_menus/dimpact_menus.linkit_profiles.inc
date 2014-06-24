<?php
/**
 * @file
 * dimpact_menus.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function dimpact_menus_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'menu_links';
  $linkit_profile->admin_title = 'Menu Links';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-9',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-8',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-7',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-6',
      ),
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_agenda' => 0,
        'comment_node_announcement' => 0,
        'comment_node_message' => 0,
        'comment_node_file' => 0,
        'comment_node_spatial_plan' => 0,
        'comment_node_blog' => 0,
        'comment_node_editorial' => 0,
        'comment_node_faq' => 0,
        'comment_node_forum' => 0,
        'comment_node_foto_album' => 0,
        'comment_node_marketplace' => 0,
        'comment_node_news' => 0,
        'comment_node_subject' => 0,
        'comment_node_page' => 0,
        'comment_node_poll' => 0,
        'comment_node_person' => 0,
        'comment_node_product' => 0,
        'comment_node_rss' => 0,
        'comment_node_rss_source' => 0,
        'comment_node_regulation' => 0,
        'comment_node_ris_agendaitem' => 0,
        'comment_node_ris_meeting' => 0,
        'comment_node_slide' => 0,
        'comment_node_standaard_pagina' => 0,
        'comment_node_vac' => 0,
        'comment_node_webform' => 0,
        'comment_node_wiki' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'agenda' => 'agenda',
        'announcement' => 'announcement',
        'message' => 'message',
        'file' => 'file',
        'spatial_plan' => 'spatial_plan',
        'blog' => 'blog',
        'faq' => 'faq',
        'foto_album' => 'foto_album',
        'marketplace' => 'marketplace',
        'news' => 'news',
        'subject' => 'subject',
        'page' => 'page',
        'poll' => 'poll',
        'person' => 'person',
        'product' => 'product',
        'regulation' => 'regulation',
        'slide' => 'slide',
        'standaard_pagina' => 'standaard_pagina',
        'vac' => 'vac',
        'webform' => 'webform',
        'wiki' => 'wiki',
        'editorial' => 0,
        'forum' => 0,
        'rss' => 0,
        'rss_source' => 0,
        'ris_agendaitem' => 0,
        'ris_meeting' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'tags' => 0,
        'marketplace' => 0,
        'person' => 0,
        'faq_categories' => 0,
        'announcement_type' => 0,
        'spatial_plan_status' => 0,
        'spatial_plan_type' => 0,
        'forums' => 0,
        'ris_category' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'plugin' => 'raw_url',
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['menu_links'] = $linkit_profile;

  return $export;
}
