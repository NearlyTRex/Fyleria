// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_ACTION_H_
#define _GECKO_CHARACTER_ACTION_H_

#include "CharacterAction/CharacterActionEntry.h"
#include "Utility/IndexedString.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/PolymorphicBase.h"

namespace Gecko
{

class CharacterAction : public SerializableToJson
{
public:

    // Constructors
    CharacterAction();
    explicit CharacterAction(const Json& jsonData);
    explicit CharacterAction(const String& jsonString);

    // Get array of character IDs
    IndexedStringArray GetAllCharacterIDs() const;

    // Get array of action types from all entries
    IndexedStringArray GetAllActionTypes() const;

    // Get array of destination target types from all entries
    IndexedStringArray GetAllDestinationTargetTypes() const;

    // Are all character IDs valid
    Bool AreAllCharacterIDsValid() const;

    // Prepare character IDs
    Bool PrepareCharacterIDs();

    // Run type
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RunType, IndexedString);

    // Order
    MAKE_RAW_BASIC_TYPE_ACCESSORS(Order, Short);

    // Cost
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CostAP, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CostHP, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CostMP, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CostEP, UByte);

    // Applicable weapon set
    MAKE_RAW_BASIC_TYPE_ACCESSORS(WeaponSet, IndexedString);

    // Action entries
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActionEntries, CharacterActionEntryArray);

    // Previous action types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PreviousActionTypes, IndexedStringArray);

    // Skill
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillTreeIndex, TreeIndex);

    // Item
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemTreeIndex, TreeIndex);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ItemAmount, UByte);

    // Targets
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SourceTargetType, IndexedString);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AreDestinationTargetsIdentical, Bool);

    // Characters
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SourceCharacterID, IndexedString);
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterAction);

// JSON Converters
void to_json(Json& jsonData, const CharacterAction& obj);
void from_json(const Json& jsonData, CharacterAction& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterAction, CharacterAction);

};

#endif
