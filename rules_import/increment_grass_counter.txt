{ "rules_increment_grass_counter" : {
    "LABEL" : "increment grass counter",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules" ],
    "ON" : { "node_insert--imported_weather_conditions" : { "bundle" : "imported_weather_conditions" } },
    "DO" : [
      { "entity_fetch" : {
          "USING" : { "type" : "node", "id" : "2825" },
          "PROVIDE" : { "entity_fetched" : { "node_variable" : "Fetched entity" } }
        }
      },
      { "data_convert" : {
          "USING" : { "type" : "integer", "value" : [ "node-variable:title" ] },
          "PROVIDE" : { "conversion_result" : { "conversion_result" : "Conversion result" } }
        }
      },
      { "data_calc" : {
          "USING" : { "input_1" : [ "conversion-result" ], "op" : "+", "input_2" : "1" },
          "PROVIDE" : { "result" : { "result" : "Calculation result" } }
        }
      },
      { "data_set" : { "data" : [ "node-variable:title" ], "value" : [ "result" ] } },
      { "entity_save" : { "data" : [ "node-variable" ] } }
    ]
  }
}

