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
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Kies uw onderwerp';
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
    2 => array(
      'bid' => 'menu_delta_menu-alfabet-c',
      'hide_title' => 1,
      'title' => 'C',
      'weight' => '-98',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'menu_delta_menu-alfabet-d',
      'hide_title' => 1,
      'title' => 'D',
      'weight' => '-97',
      'type' => 'block',
    ),
    4 => array(
      'bid' => 'menu_delta_menu-alfabet-e',
      'hide_title' => 1,
      'title' => 'E',
      'weight' => '-96',
      'type' => 'block',
    ),
    5 => array(
      'bid' => 'menu_delta_menu-alfabet-f',
      'hide_title' => 1,
      'title' => 'F',
      'weight' => '-95',
      'type' => 'block',
    ),
    6 => array(
      'bid' => 'menu_delta_menu-alfabet-g',
      'hide_title' => 1,
      'title' => 'G',
      'weight' => '-94',
      'type' => 'block',
    ),
    7 => array(
      'bid' => 'menu_delta_menu-alfabet-h',
      'hide_title' => 1,
      'title' => 'H',
      'weight' => '-93',
      'type' => 'block',
    ),
    8 => array(
      'bid' => 'menu_delta_menu-alfabet-i',
      'hide_title' => 1,
      'title' => 'I',
      'weight' => '-92',
      'type' => 'block',
    ),
    9 => array(
      'bid' => 'menu_delta_menu-alfabet-j',
      'hide_title' => 1,
      'title' => 'J',
      'weight' => '-91',
      'type' => 'block',
    ),
    10 => array(
      'bid' => 'menu_delta_menu-alfabet-k',
      'hide_title' => 1,
      'title' => 'K',
      'weight' => '-90',
      'type' => 'block',
    ),
    11 => array(
      'bid' => 'menu_delta_menu-alfabet-l',
      'hide_title' => 1,
      'title' => 'L',
      'weight' => '-89',
      'type' => 'block',
    ),
    12 => array(
      'bid' => 'menu_delta_menu-alfabet-m',
      'hide_title' => 1,
      'title' => 'M',
      'weight' => '-88',
      'type' => 'block',
    ),
    13 => array(
      'bid' => 'menu_delta_menu-alfabet-n',
      'hide_title' => 1,
      'title' => 'N',
      'weight' => '-87',
      'type' => 'block',
    ),
    14 => array(
      'bid' => 'menu_delta_menu-alfabet-o',
      'hide_title' => 1,
      'title' => 'O',
      'weight' => '-86',
      'type' => 'block',
    ),
    15 => array(
      'bid' => 'menu_delta_menu-alfabet-p',
      'hide_title' => 1,
      'title' => 'P',
      'weight' => '-85',
      'type' => 'block',
    ),
    16 => array(
      'bid' => 'menu_delta_menu-alfabet-q',
      'hide_title' => 1,
      'title' => 'Q',
      'weight' => '-84',
      'type' => 'block',
    ),
    17 => array(
      'bid' => 'menu_delta_menu-alfabet-r',
      'hide_title' => 1,
      'title' => 'R',
      'weight' => '-83',
      'type' => 'block',
    ),
    18 => array(
      'bid' => 'menu_delta_menu-alfabet-s',
      'hide_title' => 1,
      'title' => 'S',
      'weight' => '-82',
      'type' => 'block',
    ),
    19 => array(
      'bid' => 'menu_delta_menu-alfabet-t',
      'hide_title' => 1,
      'title' => 'T',
      'weight' => '-81',
      'type' => 'block',
    ),
    20 => array(
      'bid' => 'menu_delta_menu-alfabet-u',
      'hide_title' => 1,
      'title' => 'U',
      'weight' => '-80',
      'type' => 'block',
    ),
    21 => array(
      'bid' => 'menu_delta_menu-alfabet-v',
      'hide_title' => 1,
      'title' => 'V',
      'weight' => '-79',
      'type' => 'block',
    ),
    22 => array(
      'bid' => 'menu_delta_menu-alfabet-w',
      'hide_title' => 1,
      'title' => 'W',
      'weight' => '-78',
      'type' => 'block',
    ),
    23 => array(
      'bid' => 'menu_delta_menu-alfabet-x',
      'hide_title' => 1,
      'title' => 'X',
      'weight' => '-77',
      'type' => 'block',
    ),
    24 => array(
      'bid' => 'menu_delta_menu-alfabet-y',
      'hide_title' => 1,
      'title' => 'Y',
      'weight' => '-76',
      'type' => 'block',
    ),
    25 => array(
      'bid' => 'menu_delta_menu-alfabet-z',
      'hide_title' => 1,
      'title' => 'Z',
      'weight' => '-75',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('A');
  t('B');
  t('C');
  t('D');
  t('E');
  t('F');
  t('G');
  t('H');
  t('I');
  t('J');
  t('K');
  t('Kies uw onderwerp');
  t('L');
  t('M');
  t('N');
  t('O');
  t('P');
  t('Q');
  t('R');
  t('S');
  t('T');
  t('U');
  t('V');
  t('W');
  t('X');
  t('Y');
  t('Z');

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
