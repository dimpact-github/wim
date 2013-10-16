<?php
/**
 * @file
 * dimpact_felix.features.felix_block_set.inc
 */

/**
 * Implements hook_felix_default_block_sets().
 */
function dimpact_felix_felix_default_block_sets() {
  $sets = array();
  $sets['default'] = array(
    'name' => 'default',
    'title' => 'default',
    'blocks' => array(
      0 => array(
        'module' => 'block',
        'delta' => 6,
      ),
      1 => array(
        'module' => 'mailchimp_lists',
        'delta' => 'algemeen',
      ),
      2 => array(
        'module' => 'menu',
        'delta' => 'menu-toptaken',
      ),
      3 => array(
        'module' => 'menu_block',
        'delta' => 1,
      ),
      4 => array(
        'module' => 'quicktabs',
        'delta' => 'nieuws_agenda',
      ),
      5 => array(
        'module' => 'submenutree',
        'delta' => 1,
      ),
      6 => array(
        'module' => 'submenutree',
        'delta' => 2,
      ),
      7 => array(
        'module' => 'views',
        'delta' => 'agenda-block_1',
      ),
      8 => array(
        'module' => 'views',
        'delta' => 'agenda-block_2',
      ),
      9 => array(
        'module' => 'views',
        'delta' => 'berichten-block_1',
      ),
      10 => array(
        'module' => 'views',
        'delta' => 'bestanden-block_1',
      ),
      11 => array(
        'module' => 'views',
        'delta' => 'favorieten-block_1',
      ),
      12 => array(
        'module' => 'views',
        'delta' => 'foto_album-block_1',
      ),
      13 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_1',
      ),
      14 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_2',
      ),
      15 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_3',
      ),
      16 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_4',
      ),
      17 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_5',
      ),
      18 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_1',
      ),
      19 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_2',
      ),
      20 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_3',
      ),
      21 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block',
      ),
      22 => array(
        'module' => 'views',
        'delta' => 'personen-block_1',
      ),
      23 => array(
        'module' => 'views',
        'delta' => 'personen-block_2',
      ),
      24 => array(
        'module' => 'views',
        'delta' => 'producten-block_1',
      ),
      25 => array(
        'module' => 'views',
        'delta' => 'updates-block_1',
      ),
      26 => array(
        'module' => 'views',
        'delta' => 'veelgestelde_vragen-faq_recent',
      ),
      27 => array(
        'module' => 'views',
        'delta' => 'voorpagina_banners-block_1',
      ),
      28 => array(
        'module' => 'views',
        'delta' => 'weblog-block',
      ),
    ),
    'nodetypes' => array(
      0 => array(
        'nodetype' => 'editorial',
      ),
      1 => array(
        'nodetype' => 'poll',
      ),
      2 => array(
        'nodetype' => 'slide',
      ),
    ),
  );
  return $sets;
}
