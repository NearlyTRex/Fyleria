// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterActionData.h"

namespace Gecko
{

CharacterActionData::CharacterActionData()
{
}

CharacterActionData::CharacterActionData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void CharacterActionData::Clear()
{
    // List of character actions
    GetAvailableActions().clear();
}

Bool CharacterActionData::operator==(const CharacterActionData& other) const
{
    return false;
}

Bool CharacterActionData::operator!=(const CharacterActionData& other) const
{
    return false;
}

void to_json(Json& jsonData, const CharacterActionData& obj)
{
    // List of character actions
    SET_JSON_DATA_IF_NOT_EMPTY(AvailableActions);
}

void from_json(const Json& jsonData, CharacterActionData& obj)
{
    // List of character actions
    obj.SetAvailableActions(GET_JSON_DATA_OR_DEFAULT(AvailableActions, CharacterActionArray, CharacterActionArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterActionData, CharacterActionData);

};
