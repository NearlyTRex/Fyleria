// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_STAT_STAT_CHANGE_ENTRY_H_
#define _GECKO_STAT_STAT_CHANGE_ENTRY_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

// Stat change general formula
// (Dest Stat)(Assignment Type)(Source Stat)(Operation Type)(Change Amount)
//
// Example: DestStat["WeaponPrimaryDamageBonusValue"] += SourceStat["HealthPointsCurrent"] * 3.0
//
// Breakdown of this:
// - Source Stat: SourceStat["HealthPointsCurrent"]
// - Dest Stat: DestStat["WeaponPrimaryDamageBonusValue"]
// - Operation Type: Multiply
// - Assignment Type: Increment
// - Change Amount: 3.0

// Stat change entry
class StatChangeEntry
{
public:

    // Constructors
    StatChangeEntry();
    StatChangeEntry(const Json& jsonData);

    // Destructor
    virtual ~StatChangeEntry();

    // Clear all data
    void Clear();

    // Applicable round or attack number
    MAKE_RAW_TYPE_ACCESSORS(Round, Short);
    MAKE_RAW_TYPE_ACCESSORS(Attack, Short);
    MAKE_RAW_TYPE_ACCESSORS(Defend, Short);

    // Change amount
    MAKE_RAW_TYPE_ACCESSORS(ChangeAmount, Float);

    // Operation type (Add, Subtract, Multiply, Divide, Modulus)
    MAKE_RAW_TYPE_ACCESSORS(OperationType, String);

    // Assignment type (Set, Increment, Decrement)
    MAKE_RAW_TYPE_ACCESSORS(AssignmentType, String);

    // Stats to serve as source and destination
    MAKE_RAW_TYPE_ACCESSORS(SourceStatType, String);
    MAKE_RAW_TYPE_ACCESSORS(DestinationStatType, String);

    // Character IDs for applying
    MAKE_RAW_TYPE_ACCESSORS(SourceCharacterID, String);
    MAKE_RAW_TYPE_ACCESSORS(DestinationCharacterIDs, StringArray);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(StatChangeEntry);

// JSON Converters
void to_json(Json& jsonData, const StatChangeEntry& obj);
void from_json(const Json& jsonData, StatChangeEntry& obj);

};

#endif
