<?php
/**
 * @file
 * farmosnws.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farmosnws_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__imported_weather_conditions';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__imported_weather_conditions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_imported_weather_conditions';
  $strongarm->value = array();
  $export['menu_options_imported_weather_conditions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_imported_weather_conditions';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_imported_weather_conditions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_imported_weather_conditions';
  $strongarm->value = array();
  $export['node_options_imported_weather_conditions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_imported_weather_conditions';
  $strongarm->value = '0';
  $export['node_preview_imported_weather_conditions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_imported_weather_conditions';
  $strongarm->value = 1;
  $export['node_submitted_imported_weather_conditions'] = $strongarm;

  return $export;
}
