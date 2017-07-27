{ "rules_weather_node_reset_rain_counter" : {
    "LABEL" : "reset rain counter",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "counter", "rain", "reset", "weather" ],
    "REQUIRES" : [ "rules" ],
    "ON" : { "node_insert--imported_weather_conditions" : { "bundle" : "imported_weather_conditions" } },
    "IF" : [
      { "OR" : [
          { "text_matches" : { "text" : [ "node:field-wthr-weather" ], "match" : "Rain" } },
          { "text_matches" : { "text" : [ "node:field-wthr-weather" ], "match" : "Thunderstorm" } },
          { "text_matches" : { "text" : [ "node:field-wthr-weather" ], "match" : "Mist" } }
        ]
      }
    ],
    "DO" : [
      { "entity_fetch" : {
          "USING" : { "type" : "node", "id" : "1" },
          "PROVIDE" : { "entity_fetched" : { "rain_counter" : "Rain counter" } }
        }
      },
      { "data_set" : { "data" : [ "rain-counter:title" ], "value" : "0" } },
      { "entity_save" : { "data" : [ "rain-counter" ] } }
    ]
  }
}

