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
        'module' => 'menu',
        'delta' => 'menu-toptaken',
      ),
      2 => array(
        'module' => 'menu_block',
        'delta' => 1,
      ),
      3 => array(
        'module' => 'quicktabs',
        'delta' => 'nieuws_agenda',
      ),
      4 => array(
        'module' => 'submenutree',
        'delta' => 1,
      ),
      5 => array(
        'module' => 'submenutree',
        'delta' => 2,
      ),
      6 => array(
        'module' => 'views',
        'delta' => '-exp-announcements-page',
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
        'delta' => 'foto_album-block_2',
      ),
      14 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_1',
      ),
      15 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_2',
      ),
      16 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_3',
      ),
      17 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_4',
      ),
      18 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_5',
      ),
      19 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_1',
      ),
      20 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_2',
      ),
      21 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_3',
      ),
      22 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block',
      ),
      23 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block_1',
      ),
      24 => array(
        'module' => 'views',
        'delta' => 'personen-block_1',
      ),
      25 => array(
        'module' => 'views',
        'delta' => 'personen-block_2',
      ),
      26 => array(
        'module' => 'views',
        'delta' => 'personen_intranet-block_1',
      ),
      27 => array(
        'module' => 'views',
        'delta' => 'producten-block_1',
      ),
      28 => array(
        'module' => 'views',
        'delta' => 'producten-block_2',
      ),
      29 => array(
        'module' => 'views',
        'delta' => 'updates-block_1',
      ),
      30 => array(
        'module' => 'views',
        'delta' => 'veelgestelde_vragen-faq_recent',
      ),
      31 => array(
        'module' => 'views',
        'delta' => 'voorpagina_banners-block_1',
      ),
      32 => array(
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
      3 => array(
        'nodetype' => 'webform',
      ),
    ),
  );
  $sets['footer-blokken'] = array(
    'name' => 'footer-blokken',
    'title' => 'Footer blokken',
    'blocks' => array(
      0 => array(
        'module' => 'dominion_social',
        'delta' => 'links',
      ),
    ),
    'nodetypes' => array(
      0 => array(
        'nodetype' => 'editorial',
      ),
    ),
  );
  return $sets;
}
