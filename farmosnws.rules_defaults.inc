<?php
/**
 * @file
 * farmosnws.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function farmosnws_default_rules_configuration() {
  $items = array();
  $items['rules_pull_data_from_nws'] = entity_import('rules_config', '{ "rules_pull_data_from_nws" : {
      "LABEL" : "Pull data from NWS",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_download", "rules" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "rules_download_action_generate_path" : {
            "USING" : {
              "path" : "http:\\/\\/w1.weather.gov\\/xml\\/current_obs\\/KMGM.xml",
              "cookie" : "0",
              "uri_scheme" : "public",
              "file_directory" : "curweather",
              "temporary" : "0",
              "replace" : "0"
            },
            "PROVIDE" : { "rules_download_file" : { "rules_download_file" : "Downloaded file" } }
          }
        }
      ]
    }
  }');
  return $items;
}
