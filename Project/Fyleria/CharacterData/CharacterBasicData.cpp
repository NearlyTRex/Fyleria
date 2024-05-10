// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterBasicData.h"
#include "CharacterData/CharacterDataTypes.h"
#include "Stat/StatTypeTemplates.h"

namespace Gecko
{

CharacterBasicData::CharacterBasicData()
{
}

CharacterBasicData::CharacterBasicData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterBasicData::~CharacterBasicData()
{
}

void CharacterBasicData::InitAllStatNames()
{
    // Initialize stat type names
    InitializeStatTypeNames<CharacterBasicDataType_String>(GetStringStatNames());
    InitializeStatTypeNames<CharacterBasicDataType_Int>(GetIntStatNames());
}

Bool CharacterBasicData::operator==(const CharacterBasicData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterBasicData::operator!=(const CharacterBasicData& other) const
{
    return !operator==(other);
}

void to_json(Json& jsonData, const CharacterBasicData& obj)
{
    // Stat values
    SetJsonValuesFromStatTypeValues<CharacterBasicDataType_String, String>(jsonData, obj.GetStringStats());
    SetJsonValuesFromStatTypeValues<CharacterBasicDataType_Int, Int>(jsonData, obj.GetIntStats());
}

void from_json(const Json& jsonData, CharacterBasicData& obj)
{
    // Stat values
    SetStatTypeValuesFromJsonValues<CharacterBasicDataType_String, String>(jsonData, obj.GetStringStats());
    SetStatTypeValuesFromJsonValues<CharacterBasicDataType_Int, Int>(jsonData, obj.GetIntStats());
}

};
