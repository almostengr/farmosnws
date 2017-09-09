<?php
/**
 * @file
 * farmosnws.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function farmosnws_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: farm.
  $menus['farm'] = array(
    'menu_name' => 'farm',
    'title' => 'Farm',
    'description' => 'Farm management links',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Farm');
  t('Farm management links');

  return $menus;
}
