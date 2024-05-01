// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_MANAGER_SET_H_
#define _GECKO_UTILITY_MANAGER_SET_H_

// Internal includes
#include "Battle/BattleManager.h"
#include "Cache/CacheManager.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Config/ConfigManager.h"
#include "File/FileManager.h"
#include "Save/SaveManager.h"
#include "Scene/SceneManager.h"
#include "Item/ItemManager.h"
#include "Skill/SkillManager.h"

namespace Gecko
{

// ManagerSet
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
