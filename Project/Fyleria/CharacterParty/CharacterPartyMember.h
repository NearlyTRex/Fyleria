// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_MEMBER_H_
#define _GECKO_CHARACTER_PARTY_MEMBER_H_

#include "Utility/IndexedString.h"
#include "Utility/Macros.h"
#include "Utility/Tree.h"
#include "Utility/Enum.h"

namespace Gecko
{

class CharacterPartyMember
{
public:

    // Constructors
    CharacterPartyMember();

    // Character ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterID, IndexedString);

    // Character target type
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterTargetType, IndexedString);

    // Attack/defend counters
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AttackCounter, Int);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DefendCounter, Int);

    // Previous action types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PreviousActionTypes, IndexedStringArray);
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterPartyMember);

// JSON Converters
void to_json(Json& jsonData, const CharacterPartyMember& obj);
void from_json(const Json& jsonData, CharacterPartyMember& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterPartyMember, CharacterPartyMember);

};

#endif
