// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_STAT_PROLONGED_STAT_CHANGE_H_
#define _GECKO_STAT_PROLONGED_STAT_CHANGE_H_

// Internal includes
#include "Stat/StatChangeEntry.h"
#include "Utility/Json.h"

namespace Gecko
{

// Prolonged stat changes
class ProlongedStatChange
{
public:

    // Constructors
    ProlongedStatChange();
    ProlongedStatChange(const Json& jsonData);
    ProlongedStatChange(const String& jsonString);

    // Destructor
    virtual ~ProlongedStatChange();

    // Clear all data
    void Clear();

    // Relevant stat change
    MAKE_RAW_TYPE_ACCESSORS(StatChangeEntry, StatChangeEntry);

    // Valid round
    MAKE_RAW_TYPE_ACCESSORS(Round, Int);

    // Valid attack
    MAKE_RAW_TYPE_ACCESSORS(Attack, Int);

    // Valid defend
    MAKE_RAW_TYPE_ACCESSORS(Defend, Int);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(ProlongedStatChange);

// JSON Converters
void to_json(Json& jsonData, const ProlongedStatChange& obj);
void from_json(const Json& jsonData, ProlongedStatChange& obj);

};

#endif
