<?php
/**
 * @file
 * farmosnws.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farmosnws_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function farmosnws_node_info() {
  $items = array(
    'imported_weather_conditions' => array(
      'name' => t('Imported Weather Conditions'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
