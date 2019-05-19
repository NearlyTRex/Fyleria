// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

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
    SetCharacterID(IndexedString(""));

    // Clear stat values
    RESET_STAT_TYPE_VALUES(CharacterBasicStatType, IndexedString);
    RESET_STAT_TYPE_VALUES(CharacterBasicStatType, Int);
}

void CharacterBasicData::InitAllStatNames()
{
    // Initialize stat type names
    INITIALIZE_STAT_TYPE_NAMES(CharacterBasicStatType, IndexedString);
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
    SET_JSON_DATA_IF_NOT_DEFAULT(CharacterID, IndexedString(""));

    // Stat values
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBasicStatType, IndexedString);
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBasicStatType, Int);
}

void from_json(const Json& jsonData, CharacterBasicData& obj)
{
    // Character ID
    obj.SetCharacterID(GET_JSON_DATA_OR_DEFAULT(CharacterID, IndexedString, IndexedString("")));

    // Stat values
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBasicStatType, IndexedString);
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBasicStatType, Int);
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterBasicData, CharacterBasicData);

};
