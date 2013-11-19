<?php
/**
 * @file
 * dimpact_rechten_en_rollen.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dimpact_rechten_en_rollen_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access inactive domains'.
  $permissions['access inactive domains'] = array(
    'name' => 'access inactive domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'access overlay'.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'overlay',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access service links'.
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site map'.
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block_class',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer cookie_consent'.
  $permissions['administer cookie_consent'] = array(
    'name' => 'administer cookie_consent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'cookie_consent',
  );

  // Exported permission: 'administer domains'.
  $permissions['administer domains'] = array(
    'name' => 'administer domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'administer elysia_cron'.
  $permissions['administer elysia_cron'] = array(
    'name' => 'administer elysia_cron',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'elysia_cron',
  );

  // Exported permission: 'administer empty page callbacks'.
  $permissions['administer empty page callbacks'] = array(
    'name' => 'administer empty page callbacks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'empty_page',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer faq'.
  $permissions['administer faq'] = array(
    'name' => 'administer faq',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'administer faq order'.
  $permissions['administer faq order'] = array(
    'name' => 'administer faq order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer forums'.
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forum',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer hansel'.
  $permissions['administer hansel'] = array(
    'name' => 'administer hansel',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'hansel',
  );

  // Exported permission: 'administer homebox'.
  $permissions['administer homebox'] = array(
    'name' => 'administer homebox',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'homebox',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer lightbox2'.
  $permissions['administer lightbox2'] = array(
    'name' => 'administer lightbox2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'lightbox2',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer mail templates'.
  $permissions['administer mail templates'] = array(
    'name' => 'administer mail templates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mail_edit',
  );

  // Exported permission: 'administer mailchimp'.
  $permissions['administer mailchimp'] = array(
    'name' => 'administer mailchimp',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mailchimp',
  );

  // Exported permission: 'administer mailchimp campaigns'.
  $permissions['administer mailchimp campaigns'] = array(
    'name' => 'administer mailchimp campaigns',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mailchimp_campaign',
  );

  // Exported permission: 'administer masquerade'.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer menu_token'.
  $permissions['administer menu_token'] = array(
    'name' => 'administer menu_token',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_token',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer piwik'.
  $permissions['administer piwik'] = array(
    'name' => 'administer piwik',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'administer quicktabs'.
  $permissions['administer quicktabs'] = array(
    'name' => 'administer quicktabs',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'quicktabs',
  );

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer sibling content'.
  $permissions['administer sibling content'] = array(
    'name' => 'administer sibling content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer sibling content display type'.
  $permissions['administer sibling content display type'] = array(
    'name' => 'administer sibling content display type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer sibling content title'.
  $permissions['administer sibling content title'] = array(
    'name' => 'administer sibling content title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer sibling content weight'.
  $permissions['administer sibling content weight'] = array(
    'name' => 'administer sibling content weight',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer solr synonyms'.
  $permissions['administer solr synonyms'] = array(
    'name' => 'administer solr synonyms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'solr_synonyms',
  );

  // Exported permission: 'administer sub content'.
  $permissions['administer sub content'] = array(
    'name' => 'administer sub content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer sub content display type'.
  $permissions['administer sub content display type'] = array(
    'name' => 'administer sub content display type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer sub content title'.
  $permissions['administer sub content title'] = array(
    'name' => 'administer sub content title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer sub content weight'.
  $permissions['administer sub content weight'] = array(
    'name' => 'administer sub content weight',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer submenu tree settings'.
  $permissions['administer submenu tree settings'] = array(
    'name' => 'administer submenu tree settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'submenutree',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer user subscriptions'.
  $permissions['administer user subscriptions'] = array(
    'name' => 'administer user subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'assign domain editors'.
  $permissions['assign domain editors'] = array(
    'name' => 'assign domain editors',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bulk-administer user subscriptions'.
  $permissions['bulk-administer user subscriptions'] = array(
    'name' => 'bulk-administer user subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel own vote'.
  $permissions['cancel own vote'] = array(
    'name' => 'cancel own vote',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'poll',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear rss_nos feeds'.
  $permissions['clear rss_nos feeds'] = array(
    'name' => 'clear rss_nos feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(),
    'module' => 'context_ui',
  );

  // Exported permission: 'create agenda content'.
  $permissions['create agenda content'] = array(
    'name' => 'create agenda content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create agenda content on assigned domains'.
  $permissions['create agenda content on assigned domains'] = array(
    'name' => 'create agenda content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create announcement content'.
  $permissions['create announcement content'] = array(
    'name' => 'create announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create announcement content on assigned domains'.
  $permissions['create announcement content on assigned domains'] = array(
    'name' => 'create announcement content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create blog content'.
  $permissions['create blog content'] = array(
    'name' => 'create blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create blog content on assigned domains'.
  $permissions['create blog content on assigned domains'] = array(
    'name' => 'create blog content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create editorial content'.
  $permissions['create editorial content'] = array(
    'name' => 'create editorial content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create editorial content on assigned domains'.
  $permissions['create editorial content on assigned domains'] = array(
    'name' => 'create editorial content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create faq content'.
  $permissions['create faq content'] = array(
    'name' => 'create faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create faq content on assigned domains'.
  $permissions['create faq content on assigned domains'] = array(
    'name' => 'create faq content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create file content'.
  $permissions['create file content'] = array(
    'name' => 'create file content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create file content on assigned domains'.
  $permissions['create file content on assigned domains'] = array(
    'name' => 'create file content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create forum content'.
  $permissions['create forum content'] = array(
    'name' => 'create forum content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create forum content on assigned domains'.
  $permissions['create forum content on assigned domains'] = array(
    'name' => 'create forum content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create foto_album content'.
  $permissions['create foto_album content'] = array(
    'name' => 'create foto_album content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create foto_album content on assigned domains'.
  $permissions['create foto_album content on assigned domains'] = array(
    'name' => 'create foto_album content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create marketplace content'.
  $permissions['create marketplace content'] = array(
    'name' => 'create marketplace content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create marketplace content on assigned domains'.
  $permissions['create marketplace content on assigned domains'] = array(
    'name' => 'create marketplace content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create message content'.
  $permissions['create message content'] = array(
    'name' => 'create message content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create message content on assigned domains'.
  $permissions['create message content on assigned domains'] = array(
    'name' => 'create message content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create news content'.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create news content on assigned domains'.
  $permissions['create news content on assigned domains'] = array(
    'name' => 'create news content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content on assigned domains'.
  $permissions['create page content on assigned domains'] = array(
    'name' => 'create page content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create person content'.
  $permissions['create person content'] = array(
    'name' => 'create person content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create person content on assigned domains'.
  $permissions['create person content on assigned domains'] = array(
    'name' => 'create person content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create poll content'.
  $permissions['create poll content'] = array(
    'name' => 'create poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create poll content on assigned domains'.
  $permissions['create poll content on assigned domains'] = array(
    'name' => 'create poll content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create product content'.
  $permissions['create product content'] = array(
    'name' => 'create product content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create product content on assigned domains'.
  $permissions['create product content on assigned domains'] = array(
    'name' => 'create product content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create regulation content'.
  $permissions['create regulation content'] = array(
    'name' => 'create regulation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create regulation content on assigned domains'.
  $permissions['create regulation content on assigned domains'] = array(
    'name' => 'create regulation content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create ris_agendaitem content'.
  $permissions['create ris_agendaitem content'] = array(
    'name' => 'create ris_agendaitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create ris_agendaitem content on assigned domains'.
  $permissions['create ris_agendaitem content on assigned domains'] = array(
    'name' => 'create ris_agendaitem content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create ris_meeting content'.
  $permissions['create ris_meeting content'] = array(
    'name' => 'create ris_meeting content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create ris_meeting content on assigned domains'.
  $permissions['create ris_meeting content on assigned domains'] = array(
    'name' => 'create ris_meeting content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create rss content'.
  $permissions['create rss content'] = array(
    'name' => 'create rss content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create rss content on assigned domains'.
  $permissions['create rss content on assigned domains'] = array(
    'name' => 'create rss content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create rss_source content'.
  $permissions['create rss_source content'] = array(
    'name' => 'create rss_source content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create rss_source content on assigned domains'.
  $permissions['create rss_source content on assigned domains'] = array(
    'name' => 'create rss_source content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create slide content'.
  $permissions['create slide content'] = array(
    'name' => 'create slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create slide content on assigned domains'.
  $permissions['create slide content on assigned domains'] = array(
    'name' => 'create slide content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create spatial_plan content'.
  $permissions['create spatial_plan content'] = array(
    'name' => 'create spatial_plan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create spatial_plan content on assigned domains'.
  $permissions['create spatial_plan content on assigned domains'] = array(
    'name' => 'create spatial_plan content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create subject content'.
  $permissions['create subject content'] = array(
    'name' => 'create subject content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create subject content on assigned domains'.
  $permissions['create subject content on assigned domains'] = array(
    'name' => 'create subject content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create vac content'.
  $permissions['create vac content'] = array(
    'name' => 'create vac content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create vac content on assigned domains'.
  $permissions['create vac content on assigned domains'] = array(
    'name' => 'create vac content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create webform content on assigned domains'.
  $permissions['create webform content on assigned domains'] = array(
    'name' => 'create webform content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create wiki content'.
  $permissions['create wiki content'] = array(
    'name' => 'create wiki content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create wiki content on assigned domains'.
  $permissions['create wiki content on assigned domains'] = array(
    'name' => 'create wiki content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete agenda content on assigned domains'.
  $permissions['delete agenda content on assigned domains'] = array(
    'name' => 'delete agenda content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete announcement content on assigned domains'.
  $permissions['delete announcement content on assigned domains'] = array(
    'name' => 'delete announcement content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete any agenda content'.
  $permissions['delete any agenda content'] = array(
    'name' => 'delete any agenda content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any announcement content'.
  $permissions['delete any announcement content'] = array(
    'name' => 'delete any announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any blog content'.
  $permissions['delete any blog content'] = array(
    'name' => 'delete any blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any editorial content'.
  $permissions['delete any editorial content'] = array(
    'name' => 'delete any editorial content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any faq content'.
  $permissions['delete any faq content'] = array(
    'name' => 'delete any faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any file content'.
  $permissions['delete any file content'] = array(
    'name' => 'delete any file content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any forum content'.
  $permissions['delete any forum content'] = array(
    'name' => 'delete any forum content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any foto_album content'.
  $permissions['delete any foto_album content'] = array(
    'name' => 'delete any foto_album content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any marketplace content'.
  $permissions['delete any marketplace content'] = array(
    'name' => 'delete any marketplace content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any message content'.
  $permissions['delete any message content'] = array(
    'name' => 'delete any message content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news content'.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any person content'.
  $permissions['delete any person content'] = array(
    'name' => 'delete any person content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any poll content'.
  $permissions['delete any poll content'] = array(
    'name' => 'delete any poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any product content'.
  $permissions['delete any product content'] = array(
    'name' => 'delete any product content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any regulation content'.
  $permissions['delete any regulation content'] = array(
    'name' => 'delete any regulation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ris_agendaitem content'.
  $permissions['delete any ris_agendaitem content'] = array(
    'name' => 'delete any ris_agendaitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ris_meeting content'.
  $permissions['delete any ris_meeting content'] = array(
    'name' => 'delete any ris_meeting content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any rss content'.
  $permissions['delete any rss content'] = array(
    'name' => 'delete any rss content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any rss_source content'.
  $permissions['delete any rss_source content'] = array(
    'name' => 'delete any rss_source content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any slide content'.
  $permissions['delete any slide content'] = array(
    'name' => 'delete any slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any spatial_plan content'.
  $permissions['delete any spatial_plan content'] = array(
    'name' => 'delete any spatial_plan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any subject content'.
  $permissions['delete any subject content'] = array(
    'name' => 'delete any subject content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any vac content'.
  $permissions['delete any vac content'] = array(
    'name' => 'delete any vac content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any wiki content'.
  $permissions['delete any wiki content'] = array(
    'name' => 'delete any wiki content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete blog content on assigned domains'.
  $permissions['delete blog content on assigned domains'] = array(
    'name' => 'delete blog content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete domain content'.
  $permissions['delete domain content'] = array(
    'name' => 'delete domain content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete editorial content on assigned domains'.
  $permissions['delete editorial content on assigned domains'] = array(
    'name' => 'delete editorial content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete faq content on assigned domains'.
  $permissions['delete faq content on assigned domains'] = array(
    'name' => 'delete faq content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete file content on assigned domains'.
  $permissions['delete file content on assigned domains'] = array(
    'name' => 'delete file content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete forum content on assigned domains'.
  $permissions['delete forum content on assigned domains'] = array(
    'name' => 'delete forum content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete foto_album content on assigned domains'.
  $permissions['delete foto_album content on assigned domains'] = array(
    'name' => 'delete foto_album content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete marketplace content on assigned domains'.
  $permissions['delete marketplace content on assigned domains'] = array(
    'name' => 'delete marketplace content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete message content on assigned domains'.
  $permissions['delete message content on assigned domains'] = array(
    'name' => 'delete message content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete news content on assigned domains'.
  $permissions['delete news content on assigned domains'] = array(
    'name' => 'delete news content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete own agenda content'.
  $permissions['delete own agenda content'] = array(
    'name' => 'delete own agenda content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own announcement content'.
  $permissions['delete own announcement content'] = array(
    'name' => 'delete own announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own blog content'.
  $permissions['delete own blog content'] = array(
    'name' => 'delete own blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own editorial content'.
  $permissions['delete own editorial content'] = array(
    'name' => 'delete own editorial content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own faq content'.
  $permissions['delete own faq content'] = array(
    'name' => 'delete own faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own file content'.
  $permissions['delete own file content'] = array(
    'name' => 'delete own file content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own forum content'.
  $permissions['delete own forum content'] = array(
    'name' => 'delete own forum content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own foto_album content'.
  $permissions['delete own foto_album content'] = array(
    'name' => 'delete own foto_album content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own marketplace content'.
  $permissions['delete own marketplace content'] = array(
    'name' => 'delete own marketplace content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own message content'.
  $permissions['delete own message content'] = array(
    'name' => 'delete own message content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news content'.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own person content'.
  $permissions['delete own person content'] = array(
    'name' => 'delete own person content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own poll content'.
  $permissions['delete own poll content'] = array(
    'name' => 'delete own poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own product content'.
  $permissions['delete own product content'] = array(
    'name' => 'delete own product content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own regulation content'.
  $permissions['delete own regulation content'] = array(
    'name' => 'delete own regulation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ris_agendaitem content'.
  $permissions['delete own ris_agendaitem content'] = array(
    'name' => 'delete own ris_agendaitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ris_meeting content'.
  $permissions['delete own ris_meeting content'] = array(
    'name' => 'delete own ris_meeting content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own rss content'.
  $permissions['delete own rss content'] = array(
    'name' => 'delete own rss content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own rss_source content'.
  $permissions['delete own rss_source content'] = array(
    'name' => 'delete own rss_source content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own slide content'.
  $permissions['delete own slide content'] = array(
    'name' => 'delete own slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own spatial_plan content'.
  $permissions['delete own spatial_plan content'] = array(
    'name' => 'delete own spatial_plan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own subject content'.
  $permissions['delete own subject content'] = array(
    'name' => 'delete own subject content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own vac content'.
  $permissions['delete own vac content'] = array(
    'name' => 'delete own vac content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete own wiki content'.
  $permissions['delete own wiki content'] = array(
    'name' => 'delete own wiki content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete page content on assigned domains'.
  $permissions['delete page content on assigned domains'] = array(
    'name' => 'delete page content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete person content on assigned domains'.
  $permissions['delete person content on assigned domains'] = array(
    'name' => 'delete person content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete poll content on assigned domains'.
  $permissions['delete poll content on assigned domains'] = array(
    'name' => 'delete poll content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete product content on assigned domains'.
  $permissions['delete product content on assigned domains'] = array(
    'name' => 'delete product content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete regulation content on assigned domains'.
  $permissions['delete regulation content on assigned domains'] = array(
    'name' => 'delete regulation content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete ris_agendaitem content on assigned domains'.
  $permissions['delete ris_agendaitem content on assigned domains'] = array(
    'name' => 'delete ris_agendaitem content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete ris_meeting content on assigned domains'.
  $permissions['delete ris_meeting content on assigned domains'] = array(
    'name' => 'delete ris_meeting content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete rss content on assigned domains'.
  $permissions['delete rss content on assigned domains'] = array(
    'name' => 'delete rss content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete rss_source content on assigned domains'.
  $permissions['delete rss_source content on assigned domains'] = array(
    'name' => 'delete rss_source content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete slide content on assigned domains'.
  $permissions['delete slide content on assigned domains'] = array(
    'name' => 'delete slide content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete spatial_plan content on assigned domains'.
  $permissions['delete spatial_plan content on assigned domains'] = array(
    'name' => 'delete spatial_plan content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete subject content on assigned domains'.
  $permissions['delete subject content on assigned domains'] = array(
    'name' => 'delete subject content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete terms in announcement_type'.
  $permissions['delete terms in announcement_type'] = array(
    'name' => 'delete terms in announcement_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in faq_categories'.
  $permissions['delete terms in faq_categories'] = array(
    'name' => 'delete terms in faq_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in forums'.
  $permissions['delete terms in forums'] = array(
    'name' => 'delete terms in forums',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in marketplace'.
  $permissions['delete terms in marketplace'] = array(
    'name' => 'delete terms in marketplace',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in person'.
  $permissions['delete terms in person'] = array(
    'name' => 'delete terms in person',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in spatial_plan_status'.
  $permissions['delete terms in spatial_plan_status'] = array(
    'name' => 'delete terms in spatial_plan_status',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in spatial_plan_type'.
  $permissions['delete terms in spatial_plan_type'] = array(
    'name' => 'delete terms in spatial_plan_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete vac content on assigned domains'.
  $permissions['delete vac content on assigned domains'] = array(
    'name' => 'delete vac content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete webform content on assigned domains'.
  $permissions['delete webform content on assigned domains'] = array(
    'name' => 'delete webform content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete wiki content on assigned domains'.
  $permissions['delete wiki content on assigned domains'] = array(
    'name' => 'delete wiki content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download original image'.
  $permissions['download original image'] = array(
    'name' => 'download original image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'lightbox2',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any agenda content'.
  $permissions['edit any agenda content'] = array(
    'name' => 'edit any agenda content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any announcement content'.
  $permissions['edit any announcement content'] = array(
    'name' => 'edit any announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any blog content'.
  $permissions['edit any blog content'] = array(
    'name' => 'edit any blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any editorial content'.
  $permissions['edit any editorial content'] = array(
    'name' => 'edit any editorial content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any faq content'.
  $permissions['edit any faq content'] = array(
    'name' => 'edit any faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any file content'.
  $permissions['edit any file content'] = array(
    'name' => 'edit any file content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any forum content'.
  $permissions['edit any forum content'] = array(
    'name' => 'edit any forum content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any foto_album content'.
  $permissions['edit any foto_album content'] = array(
    'name' => 'edit any foto_album content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any marketplace content'.
  $permissions['edit any marketplace content'] = array(
    'name' => 'edit any marketplace content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any message content'.
  $permissions['edit any message content'] = array(
    'name' => 'edit any message content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news content'.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any person content'.
  $permissions['edit any person content'] = array(
    'name' => 'edit any person content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any poll content'.
  $permissions['edit any poll content'] = array(
    'name' => 'edit any poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any product content'.
  $permissions['edit any product content'] = array(
    'name' => 'edit any product content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any regulation content'.
  $permissions['edit any regulation content'] = array(
    'name' => 'edit any regulation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ris_agendaitem content'.
  $permissions['edit any ris_agendaitem content'] = array(
    'name' => 'edit any ris_agendaitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ris_meeting content'.
  $permissions['edit any ris_meeting content'] = array(
    'name' => 'edit any ris_meeting content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any rss content'.
  $permissions['edit any rss content'] = array(
    'name' => 'edit any rss content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any rss_source content'.
  $permissions['edit any rss_source content'] = array(
    'name' => 'edit any rss_source content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any slide content'.
  $permissions['edit any slide content'] = array(
    'name' => 'edit any slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any spatial_plan content'.
  $permissions['edit any spatial_plan content'] = array(
    'name' => 'edit any spatial_plan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any subject content'.
  $permissions['edit any subject content'] = array(
    'name' => 'edit any subject content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any vac content'.
  $permissions['edit any vac content'] = array(
    'name' => 'edit any vac content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any wiki content'.
  $permissions['edit any wiki content'] = array(
    'name' => 'edit any wiki content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit domain content'.
  $permissions['edit domain content'] = array(
    'name' => 'edit domain content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'edit own agenda content'.
  $permissions['edit own agenda content'] = array(
    'name' => 'edit own agenda content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own announcement content'.
  $permissions['edit own announcement content'] = array(
    'name' => 'edit own announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own blog content'.
  $permissions['edit own blog content'] = array(
    'name' => 'edit own blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own editorial content'.
  $permissions['edit own editorial content'] = array(
    'name' => 'edit own editorial content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own faq content'.
  $permissions['edit own faq content'] = array(
    'name' => 'edit own faq content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own file content'.
  $permissions['edit own file content'] = array(
    'name' => 'edit own file content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own forum content'.
  $permissions['edit own forum content'] = array(
    'name' => 'edit own forum content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own foto_album content'.
  $permissions['edit own foto_album content'] = array(
    'name' => 'edit own foto_album content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own marketplace content'.
  $permissions['edit own marketplace content'] = array(
    'name' => 'edit own marketplace content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own menus'.
  $permissions['edit own menus'] = array(
    'name' => 'edit own menus',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'dominion_menu',
  );

  // Exported permission: 'edit own message content'.
  $permissions['edit own message content'] = array(
    'name' => 'edit own message content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news content'.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own person content'.
  $permissions['edit own person content'] = array(
    'name' => 'edit own person content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own poll content'.
  $permissions['edit own poll content'] = array(
    'name' => 'edit own poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own product content'.
  $permissions['edit own product content'] = array(
    'name' => 'edit own product content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own regulation content'.
  $permissions['edit own regulation content'] = array(
    'name' => 'edit own regulation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ris_agendaitem content'.
  $permissions['edit own ris_agendaitem content'] = array(
    'name' => 'edit own ris_agendaitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ris_meeting content'.
  $permissions['edit own ris_meeting content'] = array(
    'name' => 'edit own ris_meeting content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own rss content'.
  $permissions['edit own rss content'] = array(
    'name' => 'edit own rss content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own rss_source content'.
  $permissions['edit own rss_source content'] = array(
    'name' => 'edit own rss_source content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own slide content'.
  $permissions['edit own slide content'] = array(
    'name' => 'edit own slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own spatial_plan content'.
  $permissions['edit own spatial_plan content'] = array(
    'name' => 'edit own spatial_plan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own subject content'.
  $permissions['edit own subject content'] = array(
    'name' => 'edit own subject content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own vac content'.
  $permissions['edit own vac content'] = array(
    'name' => 'edit own vac content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit own wiki content'.
  $permissions['edit own wiki content'] = array(
    'name' => 'edit own wiki content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in announcement_type'.
  $permissions['edit terms in announcement_type'] = array(
    'name' => 'edit terms in announcement_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in faq_categories'.
  $permissions['edit terms in faq_categories'] = array(
    'name' => 'edit terms in faq_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in forums'.
  $permissions['edit terms in forums'] = array(
    'name' => 'edit terms in forums',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in marketplace'.
  $permissions['edit terms in marketplace'] = array(
    'name' => 'edit terms in marketplace',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in person'.
  $permissions['edit terms in person'] = array(
    'name' => 'edit terms in person',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in spatial_plan_status'.
  $permissions['edit terms in spatial_plan_status'] = array(
    'name' => 'edit terms in spatial_plan_status',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in spatial_plan_type'.
  $permissions['edit terms in spatial_plan_type'] = array(
    'name' => 'edit terms in spatial_plan_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'exclude nodes from apache solr'.
  $permissions['exclude nodes from apache solr'] = array(
    'name' => 'exclude nodes from apache solr',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'apachesolr_exclude_node',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flag favorieten'.
  $permissions['flag favorieten'] = array(
    'name' => 'flag favorieten',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'import rss_nos feeds'.
  $permissions['import rss_nos feeds'] = array(
    'name' => 'import rss_nos feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'inspect all votes'.
  $permissions['inspect all votes'] = array(
    'name' => 'inspect all votes',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'poll',
  );

  // Exported permission: 'manage default subsites'.
  $permissions['manage default subsites'] = array(
    'name' => 'manage default subsites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dominion',
  );

  // Exported permission: 'manage dominion subsites'.
  $permissions['manage dominion subsites'] = array(
    'name' => 'manage dominion subsites',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'dominion',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage felix blocks'.
  $permissions['manage felix blocks'] = array(
    'name' => 'manage felix blocks',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'felix',
  );

  // Exported permission: 'manage felix blocks on all domains'.
  $permissions['manage felix blocks on all domains'] = array(
    'name' => 'manage felix blocks on all domains',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'felix_domain',
  );

  // Exported permission: 'manage internet subsites'.
  $permissions['manage internet subsites'] = array(
    'name' => 'manage internet subsites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dominion',
  );

  // Exported permission: 'manage intranet subsites'.
  $permissions['manage intranet subsites'] = array(
    'name' => 'manage intranet subsites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dominion',
  );

  // Exported permission: 'manage team subsites'.
  $permissions['manage team subsites'] = array(
    'name' => 'manage team subsites',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'dominion',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'masquerade as admin'.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as user'.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from draft to published'.
  $permissions['moderate content from draft to published'] = array(
    'name' => 'moderate content from draft to published',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'publish from assigned domain'.
  $permissions['publish from assigned domain'] = array(
    'name' => 'publish from assigned domain',
    'roles' => array(
      'administrator' => 'administrator',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'publish from default domain'.
  $permissions['publish from default domain'] = array(
    'name' => 'publish from default domain',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'publish to any assigned domain'.
  $permissions['publish to any assigned domain'] = array(
    'name' => 'publish to any assigned domain',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set domain access'.
  $permissions['set domain access'] = array(
    'name' => 'set domain access',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for flagging'.
  $permissions['show format selection for flagging'] = array(
    'name' => 'show format selection for flagging',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'start atos import'.
  $permissions['start atos import'] = array(
    'name' => 'start atos import',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'atos_esuite',
  );

  // Exported permission: 'start durp import'.
  $permissions['start durp import'] = array(
    'name' => 'start durp import',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'durp',
  );

  // Exported permission: 'start gvop import'.
  $permissions['start gvop import'] = array(
    'name' => 'start gvop import',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'gvop',
  );

  // Exported permission: 'submit latitude/longitude'.
  $permissions['submit latitude/longitude'] = array(
    'name' => 'submit latitude/longitude',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'subscribe to all content types'.
  $permissions['subscribe to all content types'] = array(
    'name' => 'subscribe to all content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'subscribe to content'.
  $permissions['subscribe to content'] = array(
    'name' => 'subscribe to content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'subscribe to content types'.
  $permissions['subscribe to content types'] = array(
    'name' => 'subscribe to content types',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'suspend own subscriptions'.
  $permissions['suspend own subscriptions'] = array(
    'name' => 'suspend own subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'test hansel'.
  $permissions['test hansel'] = array(
    'name' => 'test hansel',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'hansel',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'unflag favorieten'.
  $permissions['unflag favorieten'] = array(
    'name' => 'unflag favorieten',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unlock rss_nos feeds'.
  $permissions['unlock rss_nos feeds'] = array(
    'name' => 'unlock rss_nos feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'update agenda content on assigned domains'.
  $permissions['update agenda content on assigned domains'] = array(
    'name' => 'update agenda content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update announcement content on assigned domains'.
  $permissions['update announcement content on assigned domains'] = array(
    'name' => 'update announcement content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update blog content on assigned domains'.
  $permissions['update blog content on assigned domains'] = array(
    'name' => 'update blog content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update editorial content on assigned domains'.
  $permissions['update editorial content on assigned domains'] = array(
    'name' => 'update editorial content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update faq content on assigned domains'.
  $permissions['update faq content on assigned domains'] = array(
    'name' => 'update faq content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update file content on assigned domains'.
  $permissions['update file content on assigned domains'] = array(
    'name' => 'update file content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update forum content on assigned domains'.
  $permissions['update forum content on assigned domains'] = array(
    'name' => 'update forum content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update foto_album content on assigned domains'.
  $permissions['update foto_album content on assigned domains'] = array(
    'name' => 'update foto_album content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update marketplace content on assigned domains'.
  $permissions['update marketplace content on assigned domains'] = array(
    'name' => 'update marketplace content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update message content on assigned domains'.
  $permissions['update message content on assigned domains'] = array(
    'name' => 'update message content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update news content on assigned domains'.
  $permissions['update news content on assigned domains'] = array(
    'name' => 'update news content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update page content on assigned domains'.
  $permissions['update page content on assigned domains'] = array(
    'name' => 'update page content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update person content on assigned domains'.
  $permissions['update person content on assigned domains'] = array(
    'name' => 'update person content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update poll content on assigned domains'.
  $permissions['update poll content on assigned domains'] = array(
    'name' => 'update poll content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update product content on assigned domains'.
  $permissions['update product content on assigned domains'] = array(
    'name' => 'update product content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update regulation content on assigned domains'.
  $permissions['update regulation content on assigned domains'] = array(
    'name' => 'update regulation content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update ris_agendaitem content on assigned domains'.
  $permissions['update ris_agendaitem content on assigned domains'] = array(
    'name' => 'update ris_agendaitem content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update ris_meeting content on assigned domains'.
  $permissions['update ris_meeting content on assigned domains'] = array(
    'name' => 'update ris_meeting content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update rss content on assigned domains'.
  $permissions['update rss content on assigned domains'] = array(
    'name' => 'update rss content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update rss_source content on assigned domains'.
  $permissions['update rss_source content on assigned domains'] = array(
    'name' => 'update rss_source content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update slide content on assigned domains'.
  $permissions['update slide content on assigned domains'] = array(
    'name' => 'update slide content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update spatial_plan content on assigned domains'.
  $permissions['update spatial_plan content on assigned domains'] = array(
    'name' => 'update spatial_plan content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update subject content on assigned domains'.
  $permissions['update subject content on assigned domains'] = array(
    'name' => 'update subject content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update vac content on assigned domains'.
  $permissions['update vac content on assigned domains'] = array(
    'name' => 'update vac content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update webform content on assigned domains'.
  $permissions['update webform content on assigned domains'] = array(
    'name' => 'update webform content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update wiki content on assigned domains'.
  $permissions['update wiki content on assigned domains'] = array(
    'name' => 'update wiki content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'use PHP for hansel configuration'.
  $permissions['use PHP for hansel configuration'] = array(
    'name' => 'use PHP for hansel configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'hansel',
  );

  // Exported permission: 'use PHP for service visibility'.
  $permissions['use PHP for service visibility'] = array(
    'name' => 'use PHP for service visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format mailchimp_campaign'.
  $permissions['use text format mailchimp_campaign'] = array(
    'name' => 'use text format mailchimp_campaign',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view faq page'.
  $permissions['view faq page'] = array(
    'name' => 'view faq page',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'eindredacteur' => 'eindredacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'faq',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view location directory'.
  $permissions['view location directory'] = array(
    'name' => 'view location directory',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view node location table'.
  $permissions['view node location table'] = array(
    'name' => 'view node location table',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'view node map'.
  $permissions['view node map'] = array(
    'name' => 'view node map',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'gmap_location',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'medewerker' => 'medewerker',
      'redacteur' => 'redacteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
      'teamlid' => 'teamlid',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
      'redacteur' => 'redacteur',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view unpublished domain content'.
  $permissions['view unpublished domain content'] = array(
    'name' => 'view unpublished domain content',
    'roles' => array(
      'administrator' => 'administrator',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'view user location details'.
  $permissions['view user location details'] = array(
    'name' => 'view user location details',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'gmap_location',
  );

  // Exported permission: 'view user location table'.
  $permissions['view user location table'] = array(
    'name' => 'view user location table',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'view user map'.
  $permissions['view user map'] = array(
    'name' => 'view user map',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'gmap_location',
  );

  // Exported permission: 'vote on polls'.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'eindredacteur' => 'eindredacteur',
    ),
    'module' => 'poll',
  );

  return $permissions;
}
