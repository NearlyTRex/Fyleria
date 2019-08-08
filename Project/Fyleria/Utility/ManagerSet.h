// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_MANAGER_SET_H_
#define _GECKO_MANAGER_SET_H_

// Internal includes
#include "Battle/BattleManager.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Config/ConfigManager.h"
#include "Saves/SaveManager.h"
#include "Scene/SceneManager.h"
#include "Items/ItemManager.h"
#include "Skills/SkillManager.h"

namespace Gecko
{

class ManagerSet
{
public:

    // Constructors
    ManagerSet();

    // Managers
    MAKE_RAW_TYPE_ACCESSORS(BattleManager, BattleManager);
    MAKE_RAW_TYPE_ACCESSORS(CharacterManager, CharacterManager);
    MAKE_RAW_TYPE_ACCESSORS(CharacterPartyManager, CharacterPartyManager);
    MAKE_RAW_TYPE_ACCESSORS(ConfigManager, ConfigManager);
    MAKE_RAW_TYPE_ACCESSORS(SaveManager, SaveManager);
    MAKE_RAW_TYPE_ACCESSORS(SceneManager, SceneManager);
    MAKE_RAW_TYPE_ACCESSORS(ItemManager, ItemManager);
    MAKE_RAW_TYPE_ACCESSORS(SkillManager, SkillManager);
};

};

#endif
