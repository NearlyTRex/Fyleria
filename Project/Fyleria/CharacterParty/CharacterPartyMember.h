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
    CharacterPartyMember(const IndexedString& sCharacterID, const IndexedString& sCharacterTargetType);

    // Get item counts
    UInt GetEquippedItemTypeCount(const TreeIndex& index) const;
    UInt GetEquippedWeaponCount(const IndexedString& sWeaponSet) const;
    UInt GetEquippedShieldCount(const IndexedString& sWeaponSet) const;

    // Check if an item can be added/removed
    Bool CanAddEquippedItem(const TreeIndex& index) const;
    Bool CanRemoveEquippedItem(const TreeIndex& index) const;

    // Add/remove equipped items
    Bool AddEquippedItem(const TreeIndex& index, const IndexedString& sEquipSlot);
    Bool RemoveEquippedItem(const TreeIndex& index, const IndexedString& sEquipSlot);

    // Get primary/secondary hand info
    Bool GetHandInfoByWeaponSet(const IndexedString& sWeaponSet,
        TreeIndex& primaryItemIndex,
        TreeIndex& secondaryItemIndex,
        IndexedStringArray& vPrimaryActionTypes,
        IndexedStringArray& vSecondaryActionTypes) const;

    // Character ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterID, IndexedString);

    // Character target type
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterTargetType, IndexedString);

    // Equipped items
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(EquippedItems, CharacterPartyEquippedItemArray);
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterPartyMember);

// JSON Converters
void to_json(Json& jsonData, const CharacterPartyMember& obj);
void from_json(const Json& jsonData, CharacterPartyMember& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterPartyMember, CharacterPartyMember);

};

#endif
