<?php
/**
 * @file
 * dimpact_dominion.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dimpact_dominion_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_access_exclude';
  $strongarm->value = 'user
user/login
user/register
user/password
user/reset/*';
  $export['dominion_access_exclude'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_custom_functions';
  $strongarm->value = 'piwik|Piwik
googleanalytics|Google Analytics
news|Nieuws
agenda|Agenda
webform|Contactformulier
marktplaats|Marktplaats
alphabet_menu_internet|Alfabet Menu Internet
alphabet_menu_intranet|Alfabet Menu Intranet';
  $export['dominion_custom_functions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_agenda';
  $strongarm->value = 'own-agenda';
  $export['dominion_restrict_type_agenda'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_announcement';
  $strongarm->value = '0';
  $export['dominion_restrict_type_announcement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_blog';
  $strongarm->value = '1';
  $export['dominion_restrict_type_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_editorial';
  $strongarm->value = '0';
  $export['dominion_restrict_type_editorial'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_faq';
  $strongarm->value = '1';
  $export['dominion_restrict_type_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_file';
  $strongarm->value = '1';
  $export['dominion_restrict_type_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_forum';
  $strongarm->value = '2';
  $export['dominion_restrict_type_forum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_foto_album';
  $strongarm->value = '1';
  $export['dominion_restrict_type_foto_album'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_marketplace';
  $strongarm->value = 'any-marktplaats';
  $export['dominion_restrict_type_marketplace'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_message';
  $strongarm->value = '1';
  $export['dominion_restrict_type_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_news';
  $strongarm->value = 'own-news';
  $export['dominion_restrict_type_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_page';
  $strongarm->value = '0';
  $export['dominion_restrict_type_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_person';
  $strongarm->value = '0';
  $export['dominion_restrict_type_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_poll';
  $strongarm->value = '0';
  $export['dominion_restrict_type_poll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_product';
  $strongarm->value = '0';
  $export['dominion_restrict_type_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_regulation';
  $strongarm->value = '0';
  $export['dominion_restrict_type_regulation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_ris_agendaitem';
  $strongarm->value = '0';
  $export['dominion_restrict_type_ris_agendaitem'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_ris_meeting';
  $strongarm->value = '0';
  $export['dominion_restrict_type_ris_meeting'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_rss';
  $strongarm->value = '0';
  $export['dominion_restrict_type_rss'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_rss_source';
  $strongarm->value = '0';
  $export['dominion_restrict_type_rss_source'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_slide';
  $strongarm->value = '0';
  $export['dominion_restrict_type_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_spatial_plan';
  $strongarm->value = '0';
  $export['dominion_restrict_type_spatial_plan'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_standaard_pagina';
  $strongarm->value = '0';
  $export['dominion_restrict_type_standaard_pagina'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_subject';
  $strongarm->value = '0';
  $export['dominion_restrict_type_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_vac';
  $strongarm->value = '0';
  $export['dominion_restrict_type_vac'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_webform';
  $strongarm->value = 'own-webform';
  $export['dominion_restrict_type_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dominion_restrict_type_wiki';
  $strongarm->value = '1';
  $export['dominion_restrict_type_wiki'] = $strongarm;

  return $export;
}
