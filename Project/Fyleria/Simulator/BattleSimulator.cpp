// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Simulator/BattleSimulator.h"
#include "Application/Application.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterGenerator.h"
#include "Character/CharacterConstants.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Utility/Assert.h"

namespace Gecko
{

BattleSimulator::BattleSimulator():
    Simulator()
{
}

BattleSimulator::BattleSimulator(const Json& jsonData):
    Simulator(jsonData)
{
}

void BattleSimulator::Prepare()
{
    // Generate random participants
    GenerateRandomParticipants();
}

void BattleSimulator::Run()
{
    // Create new battle
    // For each ally character:
        // - Get list of available actions
        // - Select action (randomly or via user input)
        // - Add action to battle
    // For each enemy character:
        // - Get list of available actions
        // - Select action (randomly or via user input)
        // - Add action to battle
}

void BattleSimulator::GenerateRandomParticipants()
{
    // Get participant types
    String sAllyType = GetEnumString(CharacterPartyType::Ally);
    String sEnemyType = GetEnumString(CharacterPartyType::Enemy);

    // Generate characters
    CharacterGenerator generator;
    for(UInt iCharNum = 1; iCharNum <= MAX_TEAM_CHARACTER_AMOUNT; iCharNum++)
    {
        generator.RandomizeAll();
        GetManagers()->GetCharacterManager()->GenerateCharacter(sAllyType + BoostLexicalCast<String>(iCharNum), generator, false);
        GetManagers()->GetCharacterManager()->GenerateCharacter(sEnemyType + BoostLexicalCast<String>(iCharNum), generator, false);
    }

    // Generate parties
    GetManagers()->GetCharacterPartyManager()->CreateParty(sAllyType, sAllyType, true);
    GetManagers()->GetCharacterPartyManager()->CreateParty(sEnemyType, sEnemyType, true);

    // Get parties
    CharacterParty& allyParty = GetManagers()->GetCharacterPartyManager()->GetCurrentAllyParty();
    CharacterParty& enemyParty = GetManagers()->GetCharacterPartyManager()->GetCurrentEnemyParty();

    // Add party members
    for(UInt iCharNum = 1; iCharNum <= MAX_TEAM_CHARACTER_AMOUNT; iCharNum++)
    {
        allyParty.AddMember(sAllyType + BoostLexicalCast<String>(iCharNum));
        enemyParty.AddMember(sEnemyType + BoostLexicalCast<String>(iCharNum));
    }

    // Get item info
    const StringArray vItemTreeTypes = GetEnumNames<ItemTreeType>();
    const Int iNumRandomItems = 20;
    const Int iAmountStart = 5;
    const Int iAmountEnd = 10;

    // Add items
    allyParty.AddRandomItems(vItemTreeTypes, iNumRandomItems, iAmountStart, iAmountEnd);
    enemyParty.AddRandomItems(vItemTreeTypes, iNumRandomItems, iAmountStart, iAmountEnd);

    // Equip best items
    allyParty.EquipBestItemsForAllMembers();
    enemyParty.EquipBestItemsForAllMembers();
}

void to_json(Json& jsonData, const BattleSimulator& obj)
{
}

void from_json(const Json& jsonData, BattleSimulator& obj)
{
}

};
