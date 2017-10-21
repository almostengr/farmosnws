<?php
/**
 * @file
 * farmosnws.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function farmosnws_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_weather_conditions_kmgm';
  $feeds_importer->config = array(
    'name' => 'Import Weather Conditions KMGM',
    'description' => 'Import weather conditions from the National Weather Service',
    'fetcher' => array(
      'plugin_key' => 'feeds_fetcher_directory_fetcher',
      'config' => array(
        'recursive' => 1,
        'directory' => 'public://curweather',
        'filemask' => '/\\.xml$/',
        'updated_files' => 1,
        'after_processed' => '1',
        'move_to_folder' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'location',
          'xpathparser:1' => 'observation_time_rfc822',
          'xpathparser:2' => 'relative_humidity',
          'xpathparser:3' => 'temp_f',
          'xpathparser:4' => 'observation_time_rfc822',
          'xpathparser:5' => 'wind_dir',
          'xpathparser:6' => 'wind_mph',
          'xpathparser:7' => 'weather',
          'xpathparser:8' => 'observation_time_rfc822',
          'xpathparser:9' => 'location',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
        ),
        'context' => '/current_observation',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '28',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_wthr_rel_humidity',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_wthr_temp_f',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_wthr_time_string',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_wthr_wind_dir',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_wthr_wind_mph',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_wthr_weather',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_wthr_location',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'imported_weather_conditions',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_weather_conditions_kmgm'] = $feeds_importer;

  return $export;
}
