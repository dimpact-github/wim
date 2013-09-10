<?php
/**
 * @file
 * dimpact_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dimpact_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-alfabet.
  $menus['menu-alfabet'] = array(
    'menu_name' => 'menu-alfabet',
    'title' => 'Alfabet',
    'description' => '',
  );
  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Direct online regelen',
    'description' => '',
  );
  // Exported menu: menu-footer-menu-right.
  $menus['menu-footer-menu-right'] = array(
    'menu_name' => 'menu-footer-menu-right',
    'title' => 'Footer menu right',
    'description' => 'Footer menu appears in the lower right corner of the page.',
  );
  // Exported menu: menu-meta-menu-links.
  $menus['menu-meta-menu-links'] = array(
    'menu_name' => 'menu-meta-menu-links',
    'title' => 'Meta menu links',
    'description' => '',
  );
  // Exported menu: menu-meta-menu-rechts.
  $menus['menu-meta-menu-rechts'] = array(
    'menu_name' => 'menu-meta-menu-rechts',
    'title' => 'Meta menu rechts',
    'description' => '',
  );
  // Exported menu: menu-service-menu-right.
  $menus['menu-service-menu-right'] = array(
    'menu_name' => 'menu-service-menu-right',
    'title' => 'Service menu right',
    'description' => 'Service menu appears in the upper right corner of the page.',
  );
  // Exported menu: menu-toptaken.
  $menus['menu-toptaken'] = array(
    'menu_name' => 'menu-toptaken',
    'title' => 'Toptaken',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Alfabet');
  t('Direct online regelen');
  t('Footer menu appears in the lower right corner of the page.');
  t('Footer menu right');
  t('Meta menu links');
  t('Meta menu rechts');
  t('Service menu appears in the upper right corner of the page.');
  t('Service menu right');
  t('Toptaken');


  return $menus;
}
