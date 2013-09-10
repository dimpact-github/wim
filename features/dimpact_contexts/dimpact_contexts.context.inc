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
  $context->name = 'nodepage';
  $context->description = '';
  $context->tag = 'Algemeen';
  $context->conditions = array(
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
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
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
  t('Algemeen');
  $export['nodepage'] = $context;

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
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'quicktabs-alfabet' => array(
          'module' => 'quicktabs',
          'delta' => 'alfabet',
          'region' => 'navigation',
          'weight' => '-8',
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
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'region_footer_first',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'region_footer_second',
          'weight' => '-10',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'region_footer_third',
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

  return $export;
}
