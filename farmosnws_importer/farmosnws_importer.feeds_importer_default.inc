<?php
/**
 * @file
 * farmosnws_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function farmosnws_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'log_nws_observation';
  $feeds_importer->config = array(
    'name' => 'Log: NWS Observation',
    'description' => 'Weather observation from the National Weather Service.',
    'fetcher' => array(
      'plugin_key' => 'feeds_fetcher_directory_fetcher',
      'config' => array(
        'recursive' => 1,
        'directory' => 'public://nwsfeeds',
        'filemask' => '/\\.csv$/',
        'updated_files' => 0,
        'after_processed' => '0',
        'move_to_folder' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'ASCII',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'LogProcessor',
      'config' => array(
        'author' => variable_get('farmosnws_data_uid', 0),
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Done',
            'target' => 'done',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Name',
            'target' => 'name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Notes',
            'target' => 'field_farm_notes',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Value',
            'target' => 'field_farm_quantity:field_farm_quantity_value',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Unit',
            'target' => 'field_farm_quantity:field_farm_quantity_units',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Date',
            'target' => 'changed',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Date',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Latitude',
            'target' => 'field_farm_geofield:lat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Longitude',
            'target' => 'field_farm_geofield:lon',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'farm_observation',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['log_nws_observation'] = $feeds_importer;

  return $export;
}
