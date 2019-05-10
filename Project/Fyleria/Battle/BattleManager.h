// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_BATTLE_MANAGER_H_
#define _GECKO_BATTLE_MANAGER_H_

#include "Battle/Battle.h"
#include "Utility/Singleton.h"

namespace Gecko
{

class BattleManager : public Singleton<BattleManager>
{
public:

    // Types
    typedef STDUnorderedMap<IndexedString, Battle, IndexedStringHasher> BattleMappingType;

    // Constructors
    BattleManager();

    // Create a battle
    void CreateBattle(const IndexedString& sBattleName);

    // Unload battle
    void UnloadBattle(const IndexedString& sBattleName);

    // Determine if battle exists
    Bool DoesBattleExist(const IndexedString& sBattleName) const;

    // Get battle
    const Battle& GetBattle(const IndexedString& sPartyName) const;
    Battle& GetBattle(const IndexedString& sPartyName);
    const Battle& GetCurrentBattle() const;
    Battle& GetCurrentBattle();

    // Battles
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Battles, BattleMappingType);

    // Current battle
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentBattleName, IndexedString);
};

};

#endif
