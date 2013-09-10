<?php
/**
 * @file
 * dimpact_quicktabs.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function dimpact_quicktabs_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'alfabet';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Alfabet';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'menu_delta_menu-alfabet-a',
      'hide_title' => 1,
      'title' => 'A',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'menu_delta_menu-alfabet-b',
      'hide_title' => 1,
      'title' => 'B',
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('A');
  t('Alfabet');
  t('B');

  $export['alfabet'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'nieuws_agenda';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Nieuws Agenda tabblok';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_nieuws-block_2',
      'hide_title' => 1,
      'title' => 'Nieuws',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_agenda-block_2',
      'hide_title' => 1,
      'title' => 'Agenda',
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  t('Nieuws');
  t('Nieuws Agenda tabblok');

  $export['nieuws_agenda'] = $quicktabs;

  return $export;
}
