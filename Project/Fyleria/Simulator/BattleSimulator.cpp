// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Simulator/BattleSimulator.h"
#include "Application/Application.h"

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
    // Set ally characters
    // Set enemy characters
    // Set party ally
    // Set party enemy
    // Add ally characters to ally party
    // Add enemy characters to enemy party
    // Give items to ally party
    // Give items to enemy party
    // Equip best items in ally party
    // Equip best items in enemy party
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

void to_json(Json& jsonData, const BattleSimulator& obj)
{
}

void from_json(const Json& jsonData, BattleSimulator& obj)
{
}

};
