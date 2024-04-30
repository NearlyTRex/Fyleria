// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SIMULATOR_BATTLE_SIMULATOR_H_
#define _GECKO_SIMULATOR_BATTLE_SIMULATOR_H_

// Internal includes
#include "Simulator/Simulator.h"

namespace Gecko
{

// BattleSimulator
class BattleSimulator : public Simulator
{
public:

    // Constructors
    BattleSimulator();
    BattleSimulator(const Json& jsonData);

    // Prepare
    virtual void Prepare() override;

    // Run
    virtual void Run() override;

    // Generate random participants
    void GenerateRandomParticipants();
};

// Typedef
MAKE_COMMON_TYPEDEFS(BattleSimulator);

// JSON Converters
void to_json(Json& jsonData, const BattleSimulator& obj);
void from_json(const Json& jsonData, BattleSimulator& obj);

};

#endif
