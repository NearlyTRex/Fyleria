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
#define DEFAULT_MAX_SKILL                           200

// Caches
#define CACHE_FILE_SYSTEM_TIMED_CAPACITY            100
#define CACHE_FILE_SYSTEM_TIMED_TTL                 1000*60*60*1.0
#define CACHE_FILE_SYSTEM_BASIC_CAPACITY            100

// Cache keys
#define CACHE_KEY_PROGRAM_DIRECTORY                 1

// Paths
#define DEFAULT_MAX_PATH_SIZE                       256

// Injected file tokens
#define INJECTED_STYLES_TOKEN                       "$INJECTED_STYLES$"
#define INJECTED_SCRIPTS_TOKEN                      "$INJECTED_SCRIPTS$"
#define INJECTED_MARKUP_TOKEN                       "$INJECTED_MARKUP$"

// File URI base
#define FILE_URI_BASE                               "file://"

// Starting URI
#define STARTING_URI                                "about:blank"

// Logger name
#define LOGGER_NAME                                 "log"

// Folders
#define FOLDER_DATA                                 "Data"
#define FOLDER_DATA_CHARACTERS                      "Data/Characters"
#define FOLDER_DATA_ICONS                           "Data/Icons"
#define FOLDER_DATA_ITEMS                           "Data/Items"
#define FOLDER_DATA_LIBS                            "Data/Libs"
#define FOLDER_DATA_PAGES                           "Data/Pages"
#define FOLDER_DATA_PARTIES                         "Data/Parties"
#define FOLDER_DATA_PORTRAITS                       "Data/Portraits"
#define FOLDER_DATA_SKILLS                          "Data/Skills"
#define FOLDER_SAVE                                 "Save"
#define FOLDER_LOG                                  "Log"

// Config file
#define CONFIG_FILE                                 "Config.json"

// Icon files
#define ICON_FILE_MAIN_WINDOW                       "Icon-32x32.ico"

// Item files
#define ITEM_FILE_ARMOR_CHEST                       "ItemTreeArmor-Chest.json"
#define ITEM_FILE_ARMOR_FEET                        "ItemTreeArmor-Feet.json"
#define ITEM_FILE_ARMOR_FINGER                      "ItemTreeArmor-Finger.json"
#define ITEM_FILE_ARMOR_HANDS                       "ItemTreeArmor-Hands.json"
#define ITEM_FILE_ARMOR_HEAD                        "ItemTreeArmor-Head.json"
#define ITEM_FILE_ARMOR_NECK                        "ItemTreeArmor-Neck.json"
#define ITEM_FILE_ARMOR_LEGS                        "ItemTreeArmor-Legs.json"
#define ITEM_FILE_ARMOR_SHIELD                      "ItemTreeArmor-Shield.json"
#define ITEM_FILE_INGREDIENT_BAR                    "ItemTreeIngredient-Bar.json"
#define ITEM_FILE_INGREDIENT_CLOTH                  "ItemTreeIngredient-Cloth.json"
#define ITEM_FILE_INGREDIENT_CRYSTAL                "ItemTreeIngredient-Crystal.json"
#define ITEM_FILE_INGREDIENT_LEATHER                "ItemTreeIngredient-Leather.json"
#define ITEM_FILE_INGREDIENT_MAIL                   "ItemTreeIngredient-Mail.json"
#define ITEM_FILE_INGREDIENT_PLATE                  "ItemTreeIngredient-Plate.json"
#define ITEM_FILE_INGREDIENT_SCALE                  "ItemTreeIngredient-Scale.json"
#define ITEM_FILE_INGREDIENT_SCREW                  "ItemTreeIngredient-Screw.json"
#define ITEM_FILE_INGREDIENT_SHEET                  "ItemTreeIngredient-Sheet.json"
#define ITEM_FILE_INGREDIENT_STUD                   "ItemTreeIngredient-Stud.json"
#define ITEM_FILE_INGREDIENT_THREAD                 "ItemTreeIngredient-Thread.json"
#define ITEM_FILE_POTION_ENERGY                     "ItemTreePotion-Energy.json"
#define ITEM_FILE_POTION_HEAL                       "ItemTreePotion-Heal.json"
#define ITEM_FILE_POTION_MAGIC                      "ItemTreePotion-Magic.json"
#define ITEM_FILE_POTION_SPEED                      "ItemTreePotion-Speed.json"
#define ITEM_FILE_WEAPON_BLUNT                      "ItemTreeWeapon-Blunt.json"
#define ITEM_FILE_WEAPON_MAGE                       "ItemTreeWeapon-Mage.json"
#define ITEM_FILE_WEAPON_PIERCE                     "ItemTreeWeapon-Pierce.json"
#define ITEM_FILE_WEAPON_SLASH                      "ItemTreeWeapon-Slash.json"

// Skill files
#define SKILL_FILE_AFFINITY_BLOOD                   "SkillTreeAffinity-Blood.json"
#define SKILL_FILE_AFFINITY_DARK                    "SkillTreeAffinity-Dark.json"
#define SKILL_FILE_AFFINITY_EARTH                   "SkillTreeAffinity-Earth.json"
#define SKILL_FILE_AFFINITY_FIRE                    "SkillTreeAffinity-Fire.json"
#define SKILL_FILE_AFFINITY_FLESH                   "SkillTreeAffinity-Flesh.json"
#define SKILL_FILE_AFFINITY_FORCE                   "SkillTreeAffinity-Force.json"
#define SKILL_FILE_AFFINITY_HOLY                    "SkillTreeAffinity-Holy.json"
#define SKILL_FILE_AFFINITY_ICE                     "SkillTreeAffinity-Ice.json"
#define SKILL_FILE_AFFINITY_LIGHT                   "SkillTreeAffinity-Light.json"
#define SKILL_FILE_AFFINITY_MIND                    "SkillTreeAffinity-Mind.json"
#define SKILL_FILE_AFFINITY_SHOCK                   "SkillTreeAffinity-Shock.json"
#define SKILL_FILE_AFFINITY_WIND                    "SkillTreeAffinity-Wind.json"
#define SKILL_FILE_ALCHEMY_ALCHEMIST                "SkillTreeAlchemy-Alchemist.json"
#define SKILL_FILE_ALCHEMY_CHEMIST                  "SkillTreeAlchemy-Chemist.json"
#define SKILL_FILE_ALCHEMY_ENERGIST                 "SkillTreeAlchemy-Energist.json"
#define SKILL_FILE_ALCHEMY_HEALER                   "SkillTreeAlchemy-Healer.json"
#define SKILL_FILE_BREAKDOWN_BOWBANE                "SkillTreeBreakdown-Bowbane.json"
#define SKILL_FILE_BREAKDOWN_GOLDBANE               "SkillTreeBreakdown-Goldbane.json"
#define SKILL_FILE_BREAKDOWN_HAMMERBANE             "SkillTreeBreakdown-Hammerbane.json"
#define SKILL_FILE_BREAKDOWN_PLATEBANE              "SkillTreeBreakdown-Platebane.json"
#define SKILL_FILE_BREAKDOWN_SCALEBANE              "SkillTreeBreakdown-Scalebane.json"
#define SKILL_FILE_BREAKDOWN_SHIELDBANE             "SkillTreeBreakdown-Shieldbane.json"
#define SKILL_FILE_BREAKDOWN_SPELLBANE              "SkillTreeBreakdown-Spellbane.json"
#define SKILL_FILE_BREAKDOWN_STUDREMOVER            "SkillTreeBreakdown-StudRemover.json"
#define SKILL_FILE_BREAKDOWN_SWORDBANE              "SkillTreeBreakdown-Swordbane.json"
#define SKILL_FILE_BREAKDOWN_THREADBARE             "SkillTreeBreakdown-Threadbare.json"
#define SKILL_FILE_COMBAT_AMBIDEXTROUS              "SkillTreeCombat-Ambidextrous.json"
#define SKILL_FILE_COMBAT_AVATAR                    "SkillTreeCombat-Avatar.json"
#define SKILL_FILE_COMBAT_BARBARIAN                 "SkillTreeCombat-Barbarian.json"
#define SKILL_FILE_COMBAT_BLADEMASTER               "SkillTreeCombat-Blademaster.json"
#define SKILL_FILE_COMBAT_FOCUSED                   "SkillTreeCombat-Focused.json"
#define SKILL_FILE_COMBAT_MAGE                      "SkillTreeCombat-Mage.json"
#define SKILL_FILE_COMBAT_ROGUE                     "SkillTreeCombat-Rogue.json"
#define SKILL_FILE_COMBAT_STALWART                  "SkillTreeCombat-Stalwart.json"
#define SKILL_FILE_CRAFTING_BOWSMITH                "SkillTreeCrafting-Bowsmith.json"
#define SKILL_FILE_CRAFTING_GOLDSMITH               "SkillTreeCrafting-Goldsmith.json"
#define SKILL_FILE_CRAFTING_HAMMERSMITH             "SkillTreeCrafting-Hammersmith.json"
#define SKILL_FILE_CRAFTING_PLATESMITH              "SkillTreeCrafting-Platesmith.json"
#define SKILL_FILE_CRAFTING_SCALESMITH              "SkillTreeCrafting-Scalesmith.json"
#define SKILL_FILE_CRAFTING_SHIELDSMITH             "SkillTreeCrafting-Shieldsmith.json"
#define SKILL_FILE_CRAFTING_SPELLSMITH              "SkillTreeCrafting-Spellsmith.json"
#define SKILL_FILE_CRAFTING_SWORDSMITH              "SkillTreeCrafting-Swordsmith.json"
#define SKILL_FILE_CRAFTING_TANNER                  "SkillTreeCrafting-Tanner.json"
#define SKILL_FILE_CRAFTING_WEAVER                  "SkillTreeCrafting-Weaver.json"
#define SKILL_FILE_WEAPON_BASH                      "SkillTreeWeapon-Bash.json"
#define SKILL_FILE_WEAPON_BLOCK                     "SkillTreeWeapon-Block.json"
#define SKILL_FILE_WEAPON_BREAK                     "SkillTreeWeapon-Break.json"
#define SKILL_FILE_WEAPON_CLEAVE                    "SkillTreeWeapon-Cleave.json"
#define SKILL_FILE_WEAPON_COUNTER                   "SkillTreeWeapon-Counter.json"
#define SKILL_FILE_WEAPON_CRACK                     "SkillTreeWeapon-Crack.json"
#define SKILL_FILE_WEAPON_CRITICALSHOT              "SkillTreeWeapon-CriticalShot.json"
#define SKILL_FILE_WEAPON_CRUSH                     "SkillTreeWeapon-Crush.json"
#define SKILL_FILE_WEAPON_DECAPITATE                "SkillTreeWeapon-Decapitate.json"
#define SKILL_FILE_WEAPON_DODGE                     "SkillTreeWeapon-Dodge.json"
#define SKILL_FILE_WEAPON_DRILL                     "SkillTreeWeapon-Drill.json"
#define SKILL_FILE_WEAPON_IMPACT                    "SkillTreeWeapon-Impact.json"
#define SKILL_FILE_WEAPON_IMPALE                    "SkillTreeWeapon-Impale.json"
#define SKILL_FILE_WEAPON_PARRY                     "SkillTreeWeapon-Parry.json"
#define SKILL_FILE_WEAPON_PIERCE                    "SkillTreeWeapon-Pierce.json"
#define SKILL_FILE_WEAPON_RIPOSTE                   "SkillTreeWeapon-Riposte.json"
#define SKILL_FILE_WEAPON_RUSH                      "SkillTreeWeapon-Rush.json"
#define SKILL_FILE_WEAPON_SEVER                     "SkillTreeWeapon-Sever.json"
#define SKILL_FILE_WEAPON_SHOOT                     "SkillTreeWeapon-Shoot.json"
#define SKILL_FILE_WEAPON_SLASH                     "SkillTreeWeapon-Slash.json"
#define SKILL_FILE_WEAPON_SLICE                     "SkillTreeWeapon-Slice.json"
#define SKILL_FILE_WEAPON_SLIT                      "SkillTreeWeapon-Slit.json"
#define SKILL_FILE_WEAPON_SMASH                     "SkillTreeWeapon-Smash.json"
#define SKILL_FILE_WEAPON_STEALTHSTRIKE             "SkillTreeWeapon-StealthStrike.json"

// Lib files
#define LIB_FILE_COMMON_JS                          "common.js"
#define LIB_FILE_DEBUG_JS                           "debug.js"
#define LIB_FILE_DEBUG_HTML                         "debug.html"
#define LIB_FILE_BOOTSTRAP_CSS                      "bootstrap.min.css"
#define LIB_FILE_BOOTSTRAP_CSS_GRID                 "bootstrap-grid.min.css"
#define LIB_FILE_BOOTSTRAP_CSS_REBOOT               "bootstrap-reboot.min.css"
#define LIB_FILE_BOOTSTRAP_JS                       "bootstrap.min.js"
#define LIB_FILE_JQUERY_JS                          "jquery.min.js"
#define LIB_FILE_JQUERY_SLIM_JS                     "jquery.slim.min.js"
#define LIB_FILE_JQUERY_MOUSEWHEEL_JS               "jquery.mousewheel.min.js"
#define LIB_FILE_JQUERY_TERMINAL_CSS                "jquery.terminal.min.css"
#define LIB_FILE_JQUERY_TERMINAL_JS                 "jquery.terminal.min.js"
#define LIB_FILE_POLYFILL_KEYBOARD_JS               "polyfill.keyboard.min.js"
#define LIB_FILE_PHASER_JS                          "phaser.min.js"
#define LIB_FILE_PHASER_ARCADE_PHYSICS_JS           "phaser-arcade-physics.min.js"
#define LIB_FILE_SCREENFULL_JS                      "screenfull.min.js"

// Page files
#define PAGE_FILE_INTRO_HTML                        "Intro.html"
#define PAGE_FILE_INTRO_JS                          "Intro.js"
#define PAGE_FILE_INTRO_CSS                         "Intro.css"
#define PAGE_FILE_LOADING_HTML                      "Loading.html"
#define PAGE_FILE_LOADING_JS                        "Loading.js"
#define PAGE_FILE_LOADING_CSS                       "Loading.css"
#define PAGE_FILE_MAIN_MENU_HTML                    "MainMenu.html"
#define PAGE_FILE_MAIN_MENU_JS                      "MainMenu.js"
#define PAGE_FILE_MAIN_MENU_CSS                     "MainMenu.css"
#define PAGE_FILE_STATUS_MENU_HTML                  "StatusMenu.html"
#define PAGE_FILE_STATUS_MENU_JS                    "StatusMenu.js"
#define PAGE_FILE_STATUS_MENU_CSS                   "StatusMenu.css"
#define PAGE_FILE_SAVE_MENU_HTML                    "SaveMenu.html"
#define PAGE_FILE_SAVE_MENU_JS                      "SaveMenu.js"
#define PAGE_FILE_SAVE_MENU_CSS                     "SaveMenu.css"
#define PAGE_FILE_CRAFTING_MENU_HTML                "CraftingMenu.html"
#define PAGE_FILE_CRAFTING_MENU_JS                  "CraftingMenu.js"
#define PAGE_FILE_CRAFTING_MENU_CSS                 "CraftingMenu.css"
#define PAGE_FILE_MAP_HTML                          "Map.html"
#define PAGE_FILE_MAP_JS                            "Map.js"
#define PAGE_FILE_MAP_CSS                           "Map.css"
#define PAGE_FILE_SHOP_HTML                         "Shop.html"
#define PAGE_FILE_SHOP_JS                           "Shop.js"
#define PAGE_FILE_SHOP_CSS                          "Shop.css"
#define PAGE_FILE_BATTLE_HTML                       "Battle.html"
#define PAGE_FILE_BATTLE_JS                         "Battle.js"
#define PAGE_FILE_BATTLE_CSS                        "Battle.css"
#define PAGE_FILE_CHARACTER_CREATION_HTML           "CharacterCreation.html"
#define PAGE_FILE_CHARACTER_CREATION_JS             "CharacterCreation.js"
#define PAGE_FILE_CHARACTER_CREATION_CSS            "CharacterCreation.css"
#define PAGE_FILE_CREDITS_HTML                      "Credits.html"
#define PAGE_FILE_CREDITS_JS                        "Credits.js"
#define PAGE_FILE_CREDITS_CSS                       "Credits.css"
#define PAGE_FILE_TOOL_CHARACTER_HTML               "ToolCharacter.html"
#define PAGE_FILE_TOOL_CHARACTER_JS                 "ToolCharacter.js"
#define PAGE_FILE_TOOL_CHARACTER_CSS                "ToolCharacter.css"
#define PAGE_FILE_TOOL_PARTY_HTML                   "ToolParty.html"
#define PAGE_FILE_TOOL_PARTY_JS                     "ToolParty.js"
#define PAGE_FILE_TOOL_PARTY_CSS                    "ToolParty.css"
#define PAGE_FILE_TOOL_SAVE_HTML                    "ToolSave.html"
#define PAGE_FILE_TOOL_SAVE_JS                      "ToolSave.js"
#define PAGE_FILE_TOOL_SAVE_CSS                     "ToolSave.css"

#endif
