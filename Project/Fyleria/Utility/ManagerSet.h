// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_MANAGER_SET_H_
#define _GECKO_MANAGER_SET_H_

// Internal includes
#include "Battle/BattleManager.h"
#include "Cache/CacheManager.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Config/ConfigManager.h"
#include "File/FileManager.h"
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
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(BattleManager, STDSharedPtr<BattleManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(CacheManager, STDSharedPtr<CacheManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(CharacterManager, STDSharedPtr<CharacterManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(CharacterPartyManager, STDSharedPtr<CharacterPartyManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(ConfigManager, STDSharedPtr<ConfigManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(SaveManager, STDSharedPtr<SaveManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(SceneManager, STDSharedPtr<SceneManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(ItemManager, STDSharedPtr<ItemManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(SkillManager, STDSharedPtr<SkillManager>);
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(FileManager, STDSharedPtr<FileManager>);
};

// Typedef
MAKE_COMMON_TYPEDEFS(ManagerSet);

};

#endif
