// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Stat/StatChangeEntry.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

StatChangeEntry::StatChangeEntry()
{
}

StatChangeEntry::StatChangeEntry(const Json& jsonData)
{
    from_json(jsonData, *this);
}

StatChangeEntry::~StatChangeEntry()
{
}

void StatChangeEntry::Clear()
{
    // Applicable round or attack number
    SetRound(0);
    SetAttack(0);
    SetDefend(0);

    // Change amount
    SetChangeAmount(0);

    // Operation type (Add, Subtract, Multiply, Divide, Modulus)
    SetOperationType("");

    // Assignment type (Set, Increment, Decrement)
    SetAssignmentType("");

    // Stats to serve as source and destination
    SetSourceStatType("");
    SetDestinationStatType("");
}

void to_json(Json& jsonData, const StatChangeEntry& obj)
{
    // Applicable round or attack number
    SET_JSON_DATA(Round);
    SET_JSON_DATA(Attack);
    SET_JSON_DATA(Defend);

    // Change amount
    SET_JSON_DATA(ChangeAmount);

    // Operation type (Add, Subtract, Multiply, Divide, Modulus)
    SET_JSON_DATA(OperationType);

    // Assignment type (Set, Increment, Decrement)
    SET_JSON_DATA(AssignmentType);

    // Stats to serve as source and destination
    SET_JSON_DATA(SourceStatType);
    SET_JSON_DATA(DestinationStatType);

    // Character IDs for applying
    SET_JSON_DATA(SourceCharacterID);
    SET_JSON_DATA(DestinationCharacterIDs);
}

void from_json(const Json& jsonData, StatChangeEntry& obj)
{
    // Applicable round or attack number
    SET_OBJ_DATA(Round, Int);
    SET_OBJ_DATA(Attack, Int);
    SET_OBJ_DATA(Defend, Int);

    // Change amount
    SET_OBJ_DATA(ChangeAmount, Float);

    // Operation type (Add, Subtract, Multiply, Divide, Modulus)
    SET_OBJ_DATA(OperationType, String);

    // Assignment type (Set, Increment, Decrement)
    SET_OBJ_DATA(AssignmentType, String);

    // Stats to serve as source and destination
    SET_OBJ_DATA(SourceStatType, String);
    SET_OBJ_DATA(DestinationStatType, String);

    // Character IDs for applying
    SET_OBJ_DATA(SourceCharacterID, String);
    SET_OBJ_DATA(DestinationCharacterIDs, StringArray);
}

};
