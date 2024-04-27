// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterMediaData.h"

namespace Gecko
{

CharacterMediaData::CharacterMediaData()
{
}

CharacterMediaData::CharacterMediaData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterMediaData::~CharacterMediaData()
{
}

void CharacterMediaData::InitAllStatNames()
{
    // Initialize stat type names
    InitializeStatTypeNames<CharacterMediaStatType_String>(GetStringStatNames());
}

Bool CharacterMediaData::operator==(const CharacterMediaData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterMediaData::operator!=(const CharacterMediaData& other) const
{
    return !operator==(other);
}

void to_json(Json& jsonData, const CharacterMediaData& obj)
{
    // Stat values
    SetJsonValuesFromStatTypeValues<CharacterMediaStatType_String, String>(jsonData, obj.GetStringStats());
}

void from_json(const Json& jsonData, CharacterMediaData& obj)
{
    // Stat values
    SetStatTypeValuesFromJsonValues<CharacterMediaStatType_String, String>(jsonData, obj.GetStringStats());
}

};
