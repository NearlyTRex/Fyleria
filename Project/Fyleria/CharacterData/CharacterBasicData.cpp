// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "CharacterData/CharacterBasicData.h"

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
    INITIALIZE_STAT_TYPE_NAMES(CharacterBasicStatType, String);
    INITIALIZE_STAT_TYPE_NAMES(CharacterBasicStatType, Int);
}

Bool CharacterBasicData::operator==(const CharacterBasicData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterBasicData::operator!=(const CharacterBasicData& other) const
{
    return not operator==(other);
}

void to_json(Json& jsonData, const CharacterBasicData& obj)
{
    // Stat values
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBasicStatType, String);
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBasicStatType, Int);
}

void from_json(const Json& jsonData, CharacterBasicData& obj)
{
    // Stat values
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBasicStatType, String);
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBasicStatType, Int);
}

};
