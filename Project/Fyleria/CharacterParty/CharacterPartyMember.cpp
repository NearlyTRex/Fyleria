// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterParty/CharacterPartyMember.h"

namespace Gecko
{

CharacterPartyMember::CharacterPartyMember()
{
}

void to_json(Json& jsonData, const CharacterPartyItem& obj)
{
    // Character ID
    SET_JSON_DATA_IF_NOT_DEFAULT(CharacterID, IndexedString(""));

    // Character target type
    SET_JSON_DATA_IF_NOT_DEFAULT(CharacterTargetType, IndexedString("None"));

    // Attack/defend counters
    SET_JSON_DATA_IF_NOT_DEFAULT(AttackCounter, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DefendCounter, 0);

    // Previous action types
    SET_JSON_DATA_IF_NOT_EMPTY(PreviousActionTypes);
}

void from_json(const Json& jsonData, CharacterPartyItem& obj)
{
    // Character ID
    obj.SetCharacterID(GET_JSON_DATA_OR_DEFAULT(CharacterID, IndexedString, IndexedString("")));

    // Character target type
    obj.SetCharacterTargetType(GET_JSON_DATA_OR_DEFAULT(CharacterTargetType, IndexedString, IndexedString("None")));
    
    // Attack/defend counters
    obj.SetAttackCounter(GET_JSON_DATA_OR_DEFAULT(AttackCounter, Int, 0));
    obj.SetDefendCounter(GET_JSON_DATA_OR_DEFAULT(DefendCounter, Int, 0));

    // Previous action types
    obj.SetPreviousActionTypes(GET_JSON_DATA_OR_DEFAULT(PreviousActionTypes, IndexedStringArray, IndexedStringArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterPartyItem, CharacterPartyItem);

};
