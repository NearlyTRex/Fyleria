// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_ITEM_DATA_H_
#define _GECKO_CHARACTER_ITEM_DATA_H_

#include "Character/CharacterTypes.h"

namespace Gecko
{

class CharacterItemData
{
public:

    // Constructors
    CharacterItemData();
    ~CharacterItemData();

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

    // Equipped items
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(EquippedItems, CharacterProgressItemArray);

    // Comparisons
    Bool operator==(const CharacterItemData& other) const;
    Bool operator!=(const CharacterItemData& other) const;

private:

};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterItemData);

// JSON Converters
void to_json(Json& jsonData, const CharacterItemData& obj);
void from_json(const Json& jsonData, CharacterItemData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterItemData, CharacterItemData);

};

#endif
