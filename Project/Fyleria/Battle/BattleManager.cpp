// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Battle/BattleManager.h"

namespace Gecko
{

BattleManager::BattleManager()
    : Singleton<BattleManager>()
{
}

void BattleManager::CreateBattle(const String& sBattleName)
{
    // Create a new battle
    ASSERT_ERROR(!DoesBattleExist(sBattleName), "Battle '%s' was already registered", sBattleName.c_str());
    Battle newBattle;
    GetBattles().insert({sBattleName, newBattle});
}

void BattleManager::UnloadBattle(const String& sBattleName)
{
    // Unload battle
    ASSERT_ERROR(DoesBattleExist(sBattleName), "Battle '%s' was not registered", sBattleName.c_str());
    GetBattles().erase(sBattleName);
}

Bool BattleManager::DoesBattleExist(const String& sBattleName) const
{
    // Check if battle exists
    auto iSearch = GetBattles().find(sBattleName);
    return (iSearch != GetBattles().end());
}

const Battle& BattleManager::GetBattle(const String& sBattleName) const
{
    // Get battle
    ASSERT_ERROR(DoesBattleExist(sBattleName), "Battle '%s' was not registered", sBattleName.c_str());
    auto iSearch = GetBattles().find(sBattleName);
    return iSearch->second;
}

Battle& BattleManager::GetBattle(const String& sBattleName)
{
    // Get battle
    return const_cast<Battle&>(static_cast<const BattleManager&>(*this).GetBattle(sBattleName));
}

const Battle& BattleManager::GetCurrentBattle() const
{
    // Get current battle
    return GetBattle(GetCurrentBattleID());
}

Battle& BattleManager::GetCurrentBattle()
{
    // Get current battle
    return const_cast<Battle&>(static_cast<const BattleManager&>(*this).GetCurrentBattle());
}

};
