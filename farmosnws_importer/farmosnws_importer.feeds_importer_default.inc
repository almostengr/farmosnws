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
        'directory' => 'public://feeds/curweather',
        'filemask' => '/\\.xml$/',
        'updated_files' => 0,
        'after_processed' => '0',
        'move_to_folder' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(),
        'rawXML' => array(),
        'context' => '',
        'exp' => array(
          'errors' => FALSE,
          'tidy' => FALSE,
          'debug' => array(),
          'tidy_encoding' => 'UTF8',
        ),
        'allow_override' => TRUE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'LogProcessor',
      'config' => array(
        'author' => '0',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_farm_quantity:field_farm_quantity_value',
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
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['log_nws_observation'] = $feeds_importer;

  return $export;
}
