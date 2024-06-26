// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SAVES_SAVE_H_
#define _GECKO_SAVES_SAVE_H_

// Internal includes
#include "Character/Character.h"
#include "CharacterParty/CharacterParty.h"
#include "Utility/Json.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

class Save
{
public:

    // Constructors
    Save();
    Save(const Json& jsonData);
    Save(const String& jsonString);

    // Destructor
    virtual ~Save();

    // Clear all data
    void Clear();

    // Slot
    MAKE_RAW_TYPE_ACCESSORS(Slot, String);

    // Time
    MAKE_RAW_TYPE_ACCESSORS(Time, ULongLong);

    // Description
    MAKE_RAW_TYPE_ACCESSORS(Description, String);

    // Party
    MAKE_RAW_TYPE_ACCESSORS(Parties, CharacterPartyArray);

    // Characters
    MAKE_RAW_TYPE_ACCESSORS(Characters, CharacterArray);
};

// Typedef
MAKE_COMMON_TYPEDEFS(Save);

// JSON Converters
void to_json(Json& jsonData, const Save& obj);
void from_json(const Json& jsonData, Save& obj);

};

#endif
