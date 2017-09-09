<?php
/**
 * @file
 * farmosnws.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function farmosnws_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: farm_weather:weather-history.
  $menu_links['farm_weather:weather-history'] = array(
    'menu_name' => 'farm',
    'link_path' => 'weather-history',
    'router_path' => 'weather-history',
    'link_title' => 'Weather',
    'options' => array(
      'identifier' => 'farm_weather:weather-history',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_imported-weather-conditions:node/add/imported-weather-conditions.
  $menu_links['navigation_imported-weather-conditions:node/add/imported-weather-conditions'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/imported-weather-conditions',
    'router_path' => 'node/add/imported-weather-conditions',
    'link_title' => 'Imported Weather Conditions',
    'options' => array(
      'identifier' => 'navigation_imported-weather-conditions:node/add/imported-weather-conditions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Imported Weather Conditions');
  t('Weather');

  return $menu_links;
}
