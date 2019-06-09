// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

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

void CharacterBasicData::Clear()
{
    // Clear character ID
    SetCharacterID("");

    // Clear stat values
    RESET_STAT_TYPE_VALUES(CharacterBasicStatType, String);
    RESET_STAT_TYPE_VALUES(CharacterBasicStatType, Int);
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
    // Character ID
    SET_JSON_DATA_VIA_ASSIGNMENT(CharacterID);

    // Stat values
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBasicStatType, String);
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBasicStatType, Int);
}

void from_json(const Json& jsonData, CharacterBasicData& obj)
{
    // Character ID
    SET_OBJ_DATA(CharacterID, String, "");

    // Stat values
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBasicStatType, String);
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBasicStatType, Int);
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterBasicData, CharacterBasicData);

};
