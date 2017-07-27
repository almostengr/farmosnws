{ "rules_create_water_grass_action" : {
    "LABEL" : "Create Water Grass Action",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "5",
    "OWNER" : "rules",
    "TAGS" : [ "actoin", "create", "grass", "water" ],
    "REQUIRES" : [ "rules" ],
    "ON" : { "node_update--variable" : { "bundle" : "variable" } },
    "IF" : [
      { "AND" : [
          { "data_is" : { "data" : [ "node:nid" ], "value" : "1" } },
          { "data_is" : { "data" : [ "node:title" ], "value" : "168" } }
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
      { "data_set" : {
          "data" : [ "activity:name" ],
          "value" : "Front yard grass needs to be watered"
        }
      },
      { "data_set" : { "data" : [ "activity:done" ], "value" : "0" } },
      { "entity_save" : { "data" : [ "activity" ] } },
      { "mail" : {
          "to" : "kjrobin04@yahoo.com",
          "subject" : "Water Grass",
          "message" : "Grass needs to be water as it has not rained in a week. ",
          "language" : [ "" ]
        }
      }
    ]
  }
}

