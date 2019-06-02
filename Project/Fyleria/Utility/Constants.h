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

// Web pages
#define WEB_PAGE_TOOL_BASE                          "/tools"
#define WEB_PAGE_TOOL_CHARACTER_MANAGER             "/tools/character_manager.html"
#define WEB_PAGE_TOOL_PARTY_MANAGER                 "/tools/party_manager.html"
#define WEB_PAGE_TOOL_SAVE_MANAGER                  "/tools/save_manager.html"

// Web endpoints
#define WEB_ENDPOINT_DOES_MODULE_RESULT_EXIST       "/api/does_module_result_exist"
#define WEB_ENDPOINT_GET_MODULE_RESULT_SIZE         "/api/get_module_result_size"
#define WEB_ENDPOINT_GET_MODULE_RESULTS             "/api/get_module_results"
#define WEB_ENDPOINT_RUN_MODULE_FILE                "/api/run_module_file"
#define WEB_ENDPOINT_RUN_MODULE_FILE_RESULTS        "/api/run_module_file_results"
#define WEB_ENDPOINT_RUN_MODULE_COMMAND             "/api/run_module_command"
#define WEB_ENDPOINT_RUN_MODULE_COMMAND_RESULTS     "/api/run_module_command_results"
#define WEB_ENDPOINT_SET_CURRENT_MODULE_RESULT_ID   "/api/set_current_module_result_id"
#define WEB_ENDPOINT_CLEAR_MODULE_RESULTS           "/api/clear_module_results"
#define WEB_ENDPOINT_CLEAR_ALL_MODULE_RESULTS       "/api/clear_all_module_results"

#endif
