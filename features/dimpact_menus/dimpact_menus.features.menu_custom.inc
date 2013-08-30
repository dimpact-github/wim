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
  // Translatables
  // Included for use with string extractors like potx.
  t('Meta menu links');
  t('Meta menu rechts');


  return $menus;
}
