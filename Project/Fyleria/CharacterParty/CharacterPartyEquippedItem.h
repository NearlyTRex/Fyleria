// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_EQUIPPED_ITEM_H_
#define _GECKO_CHARACTER_PARTY_EQUIPPED_ITEM_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Tree.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

// Character party equipped item
class CharacterPartyEquippedItem
{
public:

    // Constructors
    CharacterPartyEquippedItem();
    CharacterPartyEquippedItem(const Json& jsonData);

    // Item tree index
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemTreeIndex, TreeIndex);

    // Item slot
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemSlot, String);
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterPartyEquippedItem);

// JSON Converters
void to_json(Json& jsonData, const CharacterPartyEquippedItem& obj);
void from_json(const Json& jsonData, CharacterPartyEquippedItem& obj);
MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_DECL(CharacterPartyEquippedItemArray);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterPartyEquippedItem, CharacterPartyEquippedItem);

// Comparisons
Bool operator==(const CharacterPartyEquippedItem& a, const CharacterPartyEquippedItem& b);

};

#endif
