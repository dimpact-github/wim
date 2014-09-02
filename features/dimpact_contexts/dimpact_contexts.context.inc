<?php
/**
 * @file
 * dimpact_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dimpact_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agenda_blokken';
  $context->description = '';
  $context->tag = 'team subsites';
  $context->conditions = array(
    'blueprint' => array(
      'values' => array(
        'team' => 'team',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'team-agenda' => 'team-agenda',
        'actueel/agenda/*' => 'actueel/agenda/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-agenda_team-block_2' => array(
          'module' => 'views',
          'delta' => 'agenda_team-block_2',
          'region' => 'region_444_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('team subsites');
  $export['agenda_blokken'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'announcements';
  $context->description = 'Bekendmakingen lijst- en kaartpagina';
  $context->tag = 'Internet';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'bekendmakingen' => 'bekendmakingen',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-announcements-page' => array(
          'module' => 'views',
          'delta' => '-exp-announcements-page',
          'region' => 'region_39_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Bekendmakingen lijst- en kaartpagina');
  t('Internet');
  $export['announcements'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage_team';
  $context->description = '';
  $context->tag = 'team subsites';
  $context->conditions = array(
    'blueprint' => array(
      'values' => array(
        'team' => 'team',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dominion_menu-3' => array(
          'module' => 'dominion_menu',
          'delta' => '3',
          'region' => 'region_39_first',
          'weight' => '-10',
        ),
        'views-personen_intranet-block_1' => array(
          'module' => 'views',
          'delta' => 'personen_intranet-block_1',
          'region' => 'region_full_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('team subsites');
  $export['frontpage_team'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nodedetail';
  $context->description = '';
  $context->tag = 'Felix';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*' => 'node/*',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Felix');
  $export['nodedetail'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nodepage';
  $context->description = '';
  $context->tag = 'Algemeen';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'node' => array(
      'values' => array(
        'agenda' => 'agenda',
        'announcement' => 'announcement',
        'blog' => 'blog',
        'editorial' => 'editorial',
        'faq' => 'faq',
        'marketplace' => 'marketplace',
        'news' => 'news',
        'page' => 'page',
        'person' => 'person',
        'product' => 'product',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cck_blocks-field_tags' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_tags',
          'region' => 'region_363_first',
          'weight' => '-10',
        ),
        'subscriptions_ui-0' => array(
          'module' => 'subscriptions_ui',
          'delta' => '0',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'cck_blocks-field_related_pdc' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_related_pdc',
          'region' => 'region_363_third',
          'weight' => '-90',
        ),
        'cck_blocks-field_related_vac' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_related_vac',
          'region' => 'region_363_third',
          'weight' => '-89',
        ),
        'views-maps-block_1' => array(
          'module' => 'views',
          'delta' => 'maps-block_1',
          'region' => 'region_363_third',
          'weight' => '-88',
        ),
        'views-bestanden-block_2' => array(
          'module' => 'views',
          'delta' => 'bestanden-block_2',
          'region' => 'region_363_third',
          'weight' => '-87',
        ),
        'views-nieuws-block_2' => array(
          'module' => 'views',
          'delta' => 'nieuws-block_2',
          'region' => 'region_363_third',
          'weight' => '-86',
        ),
        'views-agenda-block_2' => array(
          'module' => 'views',
          'delta' => 'agenda-block_2',
          'region' => 'region_363_third',
          'weight' => '-85',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Algemeen');
  $export['nodepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nodepage_intranet';
  $context->description = '';
  $context->tag = 'Intranet';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        2 => 2,
      ),
    ),
    'node' => array(
      'values' => array(
        'agenda' => 'agenda',
        'announcement' => 'announcement',
        'blog' => 'blog',
        'editorial' => 'editorial',
        'faq' => 'faq',
        'marketplace' => 'marketplace',
        'news' => 'news',
        'page' => 'page',
        'person' => 'person',
        'product' => 'product',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'region_363_first',
          'weight' => '-10',
        ),
        'views-nieuws-block_2' => array(
          'module' => 'views',
          'delta' => 'nieuws-block_2',
          'region' => 'region_363_third',
          'weight' => '-10',
        ),
        'views-agenda-block_2' => array(
          'module' => 'views',
          'delta' => 'agenda-block_2',
          'region' => 'region_363_third',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Intranet');
  $export['nodepage_intranet'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'onderwerp';
  $context->description = '';
  $context->tag = 'Felix';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'subject' => 'subject',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Felix');
  $export['onderwerp'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'overigenodes';
  $context->description = '';
  $context->tag = 'Felix';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'agenda' => 'agenda',
        'announcement' => 'announcement',
        'blog' => 'blog',
        'editorial' => 'editorial',
        'faq' => 'faq',
        'file' => 'file',
        'forum' => 'forum',
        'foto_album' => 'foto_album',
        'marketplace' => 'marketplace',
        'message' => 'message',
        'news' => 'news',
        'page' => 'page',
        'person' => 'person',
        'poll' => 'poll',
        'product' => 'product',
        'regulation' => 'regulation',
        'ris_agendaitem' => 'ris_agendaitem',
        'ris_meeting' => 'ris_meeting',
        'rss' => 'rss',
        'rss_source' => 'rss_source',
        'slide' => 'slide',
        'spatial_plan' => 'spatial_plan',
        'vac' => 'vac',
        'webform' => 'webform',
        'wiki' => 'wiki',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Felix');
  $export['overigenodes'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'profiel';
  $context->description = '';
  $context->tag = 'Intranet';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        2 => 2,
        3 => 3,
        4 => 4,
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-personen_intranet-block_2' => array(
          'module' => 'views',
          'delta' => 'personen_intranet-block_2',
          'region' => 'region_363_first',
          'weight' => '-10',
        ),
        'submenutree-2' => array(
          'module' => 'submenutree',
          'delta' => '2',
          'region' => 'region_363_first',
          'weight' => '-9',
        ),
        'views-profiel-block_1' => array(
          'module' => 'views',
          'delta' => 'profiel-block_1',
          'region' => 'region_363_third',
          'weight' => '-10',
        ),
        'views-profiel-block_2' => array(
          'module' => 'views',
          'delta' => 'profiel-block_2',
          'region' => 'region_363_third',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Intranet');
  $export['profiel'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = 'Algemeen';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~login-required-for-subsite' => '~login-required-for-subsite',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-10',
        ),
        'dominion_menu-1' => array(
          'module' => 'dominion_menu',
          'delta' => '1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Algemeen');
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide-without-node';
  $context->description = '';
  $context->tag = 'Felix';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~overigenodes' => '~overigenodes',
      ),
    ),
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~login-required-for-subsite' => '~login-required-for-subsite',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Felix');
  $export['sitewide-without-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_internet';
  $context->description = '';
  $context->tag = 'Internet';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~login-required-for-subsite' => '~login-required-for-subsite',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-10',
        ),
        'menu-menu-tabbladen' => array(
          'module' => 'menu',
          'delta' => 'menu-tabbladen',
          'region' => 'header',
          'weight' => '-9',
        ),
        'quicktabs-alfabet' => array(
          'module' => 'quicktabs',
          'delta' => 'alfabet',
          'region' => 'navigation',
          'weight' => '-9',
        ),
        'menu-menu-meta-menu-links' => array(
          'module' => 'menu',
          'delta' => 'menu-meta-menu-links',
          'region' => 'region_meta_first',
          'weight' => '-10',
        ),
        'menu-menu-meta-menu-rechts' => array(
          'module' => 'menu',
          'delta' => 'menu-meta-menu-rechts',
          'region' => 'region_meta_second',
          'weight' => '-10',
        ),
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'region_footer_third',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Internet');
  $export['sitewide_internet'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_intranet';
  $context->description = '';
  $context->tag = 'Intranet';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        2 => 2,
        3 => 3,
        4 => 4,
      ),
    ),
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~login-required-for-subsite' => '~login-required-for-subsite',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-10',
        ),
        'dominion_menu-1' => array(
          'module' => 'dominion_menu',
          'delta' => '1',
          'region' => 'navigation',
          'weight' => '-9',
        ),
        'quicktabs-kies_uw_onderwerp_intranet' => array(
          'module' => 'quicktabs',
          'delta' => 'kies_uw_onderwerp_intranet',
          'region' => 'navigation',
          'weight' => '-7',
        ),
        'menu-menu-meta-menu-links-intranet' => array(
          'module' => 'menu',
          'delta' => 'menu-meta-menu-links-intranet',
          'region' => 'region_meta_first',
          'weight' => '-10',
        ),
        'menu-menu-meta-menu-rechts' => array(
          'module' => 'menu',
          'delta' => 'menu-meta-menu-rechts',
          'region' => 'region_meta_second',
          'weight' => '-10',
        ),
        'submenutree-2' => array(
          'module' => 'submenutree',
          'delta' => '2',
          'region' => 'region_363_first',
          'weight' => '-10',
        ),
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'region_footer_third',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Intranet');
  $export['sitewide_intranet'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_not_team';
  $context->description = '';
  $context->tag = 'Algemeen';
  $context->conditions = array(
    'blueprint' => array(
      'values' => array(
        'default' => 'default',
        'internet' => 'internet',
        'intranet' => 'intranet',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'submenutree-2' => array(
          'module' => 'submenutree',
          'delta' => '2',
          'region' => 'region_363_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Algemeen');
  $export['sitewide_not_team'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_team';
  $context->description = '';
  $context->tag = 'team subsites';
  $context->conditions = array(
    'blueprint' => array(
      'values' => array(
        'team' => 'team',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dominion_menu-3' => array(
          'module' => 'dominion_menu',
          'delta' => '3',
          'region' => 'region_363_first',
          'weight' => '-10',
        ),
        'views-maps-block_1' => array(
          'module' => 'views',
          'delta' => 'maps-block_1',
          'region' => 'region_363_third',
          'weight' => '-10',
        ),
        'views-bestanden-block_2' => array(
          'module' => 'views',
          'delta' => 'bestanden-block_2',
          'region' => 'region_363_third',
          'weight' => '-9',
        ),
        'views-berichten-block_1' => array(
          'module' => 'views',
          'delta' => 'berichten-block_1',
          'region' => 'region_444_first',
          'weight' => '-10',
        ),
        'views-berichten-block_2' => array(
          'module' => 'views',
          'delta' => 'berichten-block_2',
          'region' => 'region_444_first',
          'weight' => '-9',
        ),
        'cck_blocks-field_related_pdc' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_related_pdc',
          'region' => 'region_444_second',
          'weight' => '-7',
        ),
        'cck_blocks-field_related_vac' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_related_vac',
          'region' => 'region_444_second',
          'weight' => '-6',
        ),
        'views-b41f743aad9009e7ef60abaed330ff96' => array(
          'module' => 'views',
          'delta' => 'b41f743aad9009e7ef60abaed330ff96',
          'region' => 'region_444_second',
          'weight' => '-5',
        ),
        'views-bestanden-block_1' => array(
          'module' => 'views',
          'delta' => 'bestanden-block_1',
          'region' => 'region_444_third',
          'weight' => '-10',
        ),
        'views-foto_album-block_1' => array(
          'module' => 'views',
          'delta' => 'foto_album-block_1',
          'region' => 'region_444_third',
          'weight' => '-9',
        ),
        'views-personen_intranet-block_1' => array(
          'module' => 'views',
          'delta' => 'personen_intranet-block_1',
          'region' => 'region_full_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('team subsites');
  $export['sitewide_team'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_teams';
  $context->description = '';
  $context->tag = 'Teamsite';
  $context->conditions = array(
    'blueprint' => array(
      'values' => array(
        'team' => 'team',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-personen_intranet-block_1' => array(
          'module' => 'views',
          'delta' => 'personen_intranet-block_1',
          'region' => 'region_full_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Teamsite');
  $export['sitewide_teams'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'spatialplans';
  $context->description = 'Bestemmingsplannen lijst- en kaartpagina';
  $context->tag = 'Internet';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'bestemmingsplannen' => 'bestemmingsplannen',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-spatial_plans-page' => array(
          'module' => 'views',
          'delta' => '-exp-spatial_plans-page',
          'region' => 'region_39_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Bestemmingsplannen lijst- en kaartpagina');
  t('Internet');
  $export['spatialplans'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'zoeken';
  $context->description = '';
  $context->tag = 'Algemeen';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu' => array(
          'module' => 'facetapi',
          'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
          'region' => 'region_39_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Algemeen');
  $export['zoeken'] = $context;

  return $export;
}
