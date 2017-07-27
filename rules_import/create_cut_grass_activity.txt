{ "rules_create_cut_grass_activity" : {
    "LABEL" : "Create Cut Grass Activity",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "5",
    "OWNER" : "rules",
    "TAGS" : [ "action", "Activity", "cut", "grass" ],
    "REQUIRES" : [ "rules", "twitter_actions" ],
    "ON" : { "node_update--variable" : { "bundle" : "variable" } },
    "IF" : [
      { "AND" : [
          { "data_is" : { "data" : [ "node:nid" ], "value" : "2825" } },
          { "data_is" : { "data" : [ "node:title" ], "value" : "192" } }
        ]
      }
    ],
    "DO" : [
      { "entity_create" : {
          "USING" : {
            "type" : "log",
            "param_type" : "farm_activity",
            "param_uid" : [ "site:current-user" ],
            "param_timestamp" : [ "site:current-date" ],
            "param_created" : [ "site:current-date" ],
            "param_changed" : [ "site:current-date" ]
          },
          "PROVIDE" : { "entity_created" : { "activity" : "activity" } }
        }
      },
      { "data_set" : { "data" : [ "activity:name" ], "value" : "cut grass" } },
      { "data_set" : { "data" : [ "activity:done" ], "value" : "0" } },
      { "data_set" : { "data" : [ "activity:type" ], "value" : "farm_activity" } },
      { "data_set" : { "data" : [ "activity:created" ], "value" : [ "site:current-date" ] } },
      { "entity_save" : { "data" : [ "activity" ] } },
      { "rules_core_twitter_actions_set_status_action" : { "message" : [ "activity:name" ], "sender" : "myhub_drupal" } }
    ]
  }
}

