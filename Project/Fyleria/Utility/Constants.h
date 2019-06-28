// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_CONSTANTS_H_
#define _GECKO_UTILITY_CONSTANTS_H_

// Application name
#define APPLICATION_NAME_SHORT                      "Fyleria"
#define APPLICATION_NAME_LONG                       "Fyleria Game Engine"

// Application version
#define APPLICATION_VERSION                         "v1.0"

// Save limits
#define MAX_SAVE_SLOT                               5

// Tree limits
#define MAX_SKILL_RANK                              20

// Character limits
#define MAX_TEAM_CHARACTER_AMOUNT                   6

// Character index for team size of 6
#define CHARACTER_INDEX_1                           0
#define CHARACTER_INDEX_2                           1
#define CHARACTER_INDEX_3                           2
#define CHARACTER_INDEX_4                           3
#define CHARACTER_INDEX_5                           4
#define CHARACTER_INDEX_6                           5

// Limits on equipped items
#define HAND_SIZE_LIMIT                             4
#define BODY_SIZE_LIMIT                             1

// Skill attacks
#define BASE_NUMBER_OF_SKILL_ATTACKS                1

// Skill damage boundary
#define SKILL_DAMAGE_BOUNDARY_PERCENT               0.1
#define SKILL_DAMAGE_BOUNDARY_DEFAULT_VALUE         1.0

// Skill rank upgrade amount
#define SKILL_RANK_UPGRADE_AMOUNT                   10

// Defaults for generators
#define DEFAULT_MAX_AGE                             100
#define DEFAULT_MAX_METER                           200
#define DEFAULT_MAX_SCORING                         200
#define DEFAULT_MAX_RANK                            20

// Scenes
#define FIRST_SCENE                                 "MainMenu"
#define SCENE_INTRO                                 "Intro"
#define SCENE_LOADING                               "Loading"
#define SCENE_MAIN_MENU                             "MainMenu"
#define SCENE_STATUS_MENU                           "StatusMenu"
#define SCENE_SAVE_MENU                             "SaveMenu"
#define SCENE_CRAFTING_MENU                         "CraftingMenu"
#define SCENE_MAP                                   "Map"
#define SCENE_SHOP                                  "Shop"
#define SCENE_BATTLE                                "Battle"
#define SCENE_CHARACTER_CREATION                    "CharacterCreation"
#define SCENE_CREDITS                               "Credits"
#define SCENE_TOOL_MAIN                             "ToolMain"
#define SCENE_TOOL_CHARACTER                        "ToolCharacter"
#define SCENE_TOOL_PARTY                            "ToolParty"
#define SCENE_TOOL_SAVE                             "ToolSave"

// Web files
#define WEB_LIB_CSS_BOOTSTRAP                       "lib/bootstrap/css/bootstrap.min.css"
#define WEB_LIB_JS_BOOTSTRAP                        "lib/bootstrap/js/bootstrap.min.js"
#define WEB_LIB_JS_JQUERY                           "lib/jquery/jquery.min.js"
#define WEB_LIB_JS_PHASER                           "lib/phaser/phaser.min.js"
#define WEB_PAGE_SYSTEM_INTRO                       "pages/system_intro.html"
#define WEB_PAGE_SYSTEM_LOADING                     "pages/system_loading.html"
#define WEB_PAGE_SYSTEM_MAIN_MENU                   "pages/system_main_menu.html"
#define WEB_PAGE_SYSTEM_STATUS_MENU                 "pages/system_status_menu.html"
#define WEB_PAGE_SYSTEM_SAVE_MENU                   "pages/system_save_menu.html"
#define WEB_PAGE_SYSTEM_CRAFTING_MENU               "pages/system_crafting_menu.html"
#define WEB_PAGE_SYSTEM_MAP                         "pages/system_map.html"
#define WEB_PAGE_SYSTEM_SHOP                        "pages/system_shop.html"
#define WEB_PAGE_SYSTEM_BATTLE                      "pages/system_battle.html"
#define WEB_PAGE_SYSTEM_CHARACTER_CREATION          "pages/system_character_creation.html"
#define WEB_PAGE_SYSTEM_CREDITS                     "pages/system_credits.html"
#define WEB_PAGE_TOOL_MAIN                          "pages/tool_main.html"
#define WEB_PAGE_TOOL_CHARACTER                     "pages/tool_character.html"
#define WEB_PAGE_TOOL_PARTY                         "pages/tool_party.html"
#define WEB_PAGE_TOOL_SAVE                          "pages/tool_save.html"

#endif
