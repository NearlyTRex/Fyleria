// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Utility/ManagerSet.h"

namespace Gecko
{

ManagerSet::ManagerSet()
{
    // Create managers
    GetBattleManager() = STDMakeSharedPtr<BattleManager>();
    GetCacheManager() = STDMakeSharedPtr<CacheManager>();
    GetCharacterManager() = STDMakeSharedPtr<CharacterManager>();
    GetCharacterPartyManager() = STDMakeSharedPtr<CharacterPartyManager>();
    GetConfigManager() = STDMakeSharedPtr<ConfigManager>();
    GetSaveManager() = STDMakeSharedPtr<SaveManager>();
    GetSceneManager() = STDMakeSharedPtr<SceneManager>();
    GetItemManager() = STDMakeSharedPtr<ItemManager>();
    GetSkillManager() = STDMakeSharedPtr<SkillManager>();
    GetFileManager() = STDMakeSharedPtr<FileManager>();
}

};
