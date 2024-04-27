// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_BATTLE_BATTLE_MANAGER_H_
#define _GECKO_BATTLE_BATTLE_MANAGER_H_

// Internal includes
#include "Battle/Battle.h"

namespace Gecko
{

// Battle manager
class BattleManager
{
public:

    // Types
    typedef STDUnorderedMap<String, Battle> BattleMappingType;

    // Constructors
    BattleManager();

    // Create a battle
    void CreateBattle(const String& sBattleName);

    // Unload battle
    void UnloadBattle(const String& sBattleName);

    // Determine if battle exists
    Bool DoesBattleExist(const String& sBattleName) const;

    // Get battle
    const Battle& GetBattle(const String& sPartyName) const;
    Battle& GetBattle(const String& sPartyName);

    // Get current battle
    const Battle& GetCurrentBattle() const;
    Battle& GetCurrentBattle();

    // Battles
    MAKE_RAW_TYPE_ACCESSORS(Battles, BattleMappingType);

    // Current battle ID
    MAKE_RAW_TYPE_ACCESSORS(CurrentBattleID, String);
};

};

#endif
