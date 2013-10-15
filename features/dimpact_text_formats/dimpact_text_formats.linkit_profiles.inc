<?php
/**
 * @file
 * dimpact_text_formats.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function dimpact_text_formats_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'default';
  $linkit_profile->admin_title = 'default';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'full_html' => 'full_html',
      'filtered_html' => 'filtered_html',
      'plain_text' => 0,
      'php_code' => 0,
    ),
    'search_plugins' => array(
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'agenda' => 'agenda',
        'announcement' => 'announcement',
        'message' => 'message',
        'file' => 'file',
        'blog' => 'blog',
        'page' => 'page',
        'faq' => 'faq',
        'foto_album' => 'foto_album',
        'marketplace' => 'marketplace',
        'news' => 'news',
        'subject' => 'subject',
        'poll' => 'poll',
        'person' => 'person',
        'product' => 'product',
        'regulation' => 'regulation',
        'slide' => 'slide',
        'spatial_plan' => 'spatial_plan',
        'vac' => 'vac',
        'webform' => 'webform',
        'wiki' => 'wiki',
        'editorial' => 0,
        'rss' => 0,
        'rss_source' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 1,
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
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
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
  $export['default'] = $linkit_profile;

  return $export;
}
