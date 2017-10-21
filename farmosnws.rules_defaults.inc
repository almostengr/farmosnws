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
  $items['rules_download_nws_weather_data'] = entity_import('rules_config', '{ "rules_download_nws_weather_data" : {
      "LABEL" : "Download NWS Weather Data",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "data", "nws", "weather" ],
      "REQUIRES" : [ "rules_download", "rules" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "rules_download_action_generate_path" : {
            "USING" : {
              "path" : "http:\\/\\/w1.weather.gov\\/xml\\/current_obs\\/KMGM.xml",
              "cookie" : "0",
              "uri_scheme" : "public",
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
