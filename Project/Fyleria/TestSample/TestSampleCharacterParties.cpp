// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "TestSample/TestSamples.h"

namespace Gecko
{

// Empty ally character party
const String EMPTY_ALLY_CHARACTER_PARTY = R"(
{
    "AvailableTargetTypes": [
        "Ally1",
        "Ally2",
        "Ally3",
        "Ally4",
        "Ally5",
        "Ally6"
    ],
    "Items": {},
    "Members": {},
    "PartyID": "EmptyAllyParty",
    "PartyType": "Ally",
    "PlayTime": 0,
    "TakenTargetTypes": []
}
)";

// Empty enemy character party
const String EMPTY_ENEMY_CHARACTER_PARTY = R"(
{
    "AvailableTargetTypes": [
        "Enemy1",
        "Enemy2",
        "Enemy3",
        "Enemy4",
        "Enemy5",
        "Enemy6"
    ],
    "Items": {},
    "Members": {},
    "PartyID": "EmptyEnemyParty",
    "PartyType": "Enemy",
    "PlayTime": 0,
    "TakenTargetTypes": []
}
)";
};
