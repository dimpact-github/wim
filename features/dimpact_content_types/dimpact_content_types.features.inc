<?php
/**
 * @file
 * dimpact_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dimpact_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dimpact_content_types_node_info() {
  $items = array(
    'agenda' => array(
      'name' => t('Agenda'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'announcement' => array(
      'name' => t('Bekendmaking'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'editorial' => array(
      'name' => t('Editorial'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'file' => array(
      'name' => t('Bestand'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'foto_album' => array(
      'name' => t('Foto'),
      'base' => 'node_content',
      'description' => t('Foto wordt gebruikt om foto-albums op te bouwen.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'marketplace' => array(
      'name' => t('Marktplaats'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'message' => array(
      'name' => t('Bericht'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('Nieuws'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Pagina'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'person' => array(
      'name' => t('Persoon'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'regulation' => array(
      'name' => t('Regeling'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'ris_agendaitem' => array(
      'name' => t('Ris Agendaitem'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'ris_meeting' => array(
      'name' => t('Ris Meeting'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'rss' => array(
      'name' => t('RSS'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'rss_source' => array(
      'name' => t('RSS Source'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'slide' => array(
      'name' => t('Slide'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'spatial_plan' => array(
      'name' => t('Bestemmingsplan'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'standaard_pagina' => array(
      'name' => t('Standaard pagina'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'subject' => array(
      'name' => t('Onderwerp'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'vac' => array(
      'name' => t('VAC'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webformulier'),
      'base' => 'node_content',
      'description' => t('Een nieuw formulier of vragenlijst aanmaken. Resultaten en statistieken worden opgeslagen en zijn toegankelijk voor gebruikers met de juiste rechten.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'wiki' => array(
      'name' => t('Wiki'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function dimpact_content_types_weight_features_default_settings() {
  $settings = array();

  $settings['agenda'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['announcement'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['blog'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['editorial'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['file'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['foto_album'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['marketplace'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['message'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['news'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['page'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['person'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['product'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['regulation'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['ris_agendaitem'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['ris_meeting'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['rss'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['rss_source'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['slide'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['spatial_plan'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['standaard_pagina'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['subject'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['vac'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['webform'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['wiki'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
