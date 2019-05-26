// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_BATTLE_MANAGER_H_
#define _GECKO_BATTLE_MANAGER_H_

#include "Battle/Battle.h"
#include "Module/ModuleResultManager.h"

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
    MAKE_MODULE_RESULT_VARIANT_A1(DoesBattleExist, const IndexedString&, sBattleName);

    // Get battle
    const Battle& GetBattle(const IndexedString& sPartyName) const;
    Battle& GetBattle(const IndexedString& sPartyName);
    MAKE_MODULE_RESULT_VARIANT_A1(GetBattle, const IndexedString&, sPartyName);

    // Get current battle
    const Battle& GetCurrentBattle() const;
    Battle& GetCurrentBattle();
    MAKE_MODULE_RESULT_VARIANT(GetCurrentBattle);

    // Battles
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Battles, BattleMappingType);

    // Current battle ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentBattleID, IndexedString);
};

};

#endif
