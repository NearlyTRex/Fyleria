// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_ACTION_ENTRY_H_
#define _GECKO_CHARACTER_ACTION_ENTRY_H_

// Internal includes
#include "CharacterAction/CharacterActionResult.h"
#include "Utility/Macros.h"
#include "Utility/Json.h"
#include "Utility/Serializable.h"

namespace Gecko
{

class CharacterActionEntry : public SerializableToJson
{
public:

    // Types
    typedef STDUnorderedMap<String, CharacterActionResult> CharacterActionResultMapType;

    // Constructors
    CharacterActionEntry();
    explicit CharacterActionEntry(const Json& jsonData);
    explicit CharacterActionEntry(const String& jsonString);

    // Destructor
    virtual ~CharacterActionEntry();

    // Determine if action type is a match
    Bool DoesMatchActionType(const String& sType) const;

    // Action types
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ActionTypes, StringArray);

    // Hand
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HandType, String);

    // Whether hand is using a shield
    MAKE_JSON_BASIC_TYPE_ACCESSORS(IsHandTypeShield, Bool);

    // Target
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DestinationTargetType, String);

    // Character
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DestinationCharacterIDs, StringArray);

    // Result
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Results, CharacterActionResultMapType);

    // Comparisons
    Bool operator==(const CharacterActionEntry& other) const;
    Bool operator!=(const CharacterActionEntry& other) const;
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterActionEntry);

// JSON Converters
MAKE_JSON_OBJ_TYPE_CONVERTERS_DECL(CharacterActionEntry);
MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_DECL(CharacterActionEntryArray);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterActionEntry, CharacterActionEntry);

};

#endif
