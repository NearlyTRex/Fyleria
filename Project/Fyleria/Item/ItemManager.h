// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_ITEM_ITEM_MANAGER_H_
#define _GECKO_ITEM_ITEM_MANAGER_H_

// Internal includes
#include "CharacterAction/CharacterAction.h"
#include "Item/ItemDataArmor.h"
#include "Item/ItemDataIngredient.h"
#include "Item/ItemDataPotion.h"
#include "Item/ItemDataWeapon.h"
#include "Utility/Tree.h"

namespace Gecko
{

// Typedefs
typedef Tree<ItemDataArmor> ItemTreeArmor;
typedef Tree<ItemDataIngredient> ItemTreeIngredient;
typedef Tree<ItemDataPotion> ItemTreePotion;
typedef Tree<ItemDataWeapon> ItemTreeWeapon;

// Item manager
class ItemManager
{
public:

    // Constructors
    ItemManager();

    // Load/unload item trees into memory
    void LoadItemTreesIntoMemory();
    void UnloadItemTreesFromMemory();

    // Determine if item data exists
    Bool DoesItemDataExist(const TreeIndex& treeIndex) const;
    Bool DoesItemDataArmorExist(const TreeIndex& treeIndex) const;
    Bool DoesItemDataIngredientExist(const TreeIndex& treeIndex) const;
    Bool DoesItemDataPotionExist(const TreeIndex& treeIndex) const;
    Bool DoesItemDataWeaponExist(const TreeIndex& treeIndex) const;

    // Retrieve item data
    const ItemDataArmor& RetrieveItemDataArmor(const TreeIndex& treeIndex) const;
    const ItemDataIngredient& RetrieveItemDataIngredient(const TreeIndex& treeIndex) const;
    const ItemDataPotion& RetrieveItemDataPotion(const TreeIndex& treeIndex) const;
    const ItemDataWeapon& RetrieveItemDataWeapon(const TreeIndex& treeIndex) const;

    // Retrieve item type
    String RetrieveItemType(const TreeIndex& treeIndex) const;

    // Get item lists
    TreeIndexArray GetAllArmorItems() const;
    TreeIndexArray GetAllIngredientItems() const;
    TreeIndexArray GetAllPotionItems() const;
    TreeIndexArray GetAllWeaponItems() const;
    TreeIndexArray GetAllEquippedItems(const String& sCharID) const;

    // Resolve leaf into index
    TreeIndex ResolveItemLeafIntoIndex(const String& sLeaf) const;

    // Determine if item is actionable
    Bool IsItemActionable(const TreeIndex& treeIndex) const;

    // Generate character actions
    Bool GenerateItemCharacterActions(
        const TreeIndex& treeIndex,
        const String& sCharacterID,
        const String& sWeaponSet,
        CharacterActionArray& vActions) const;

    // Check "better" quality
    Bool IsArmorBetter(const TreeIndex& index1, const TreeIndex& index2) const;
    Bool IsWeaponBetter(const TreeIndex& index1, const TreeIndex& index2) const;

    // Check item type
    Bool IsItemWeapon(const TreeIndex& treeIndex) const;
    Bool IsItemShield(const TreeIndex& treeIndex) const;

    // Get action types
    StringArray GetActionTypes(const TreeIndex& treeIndex) const;

    // Get stat changes
    void FillItemStatChangeArrays(
        const TreeIndexArray& vItemDataArray,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables) const;

    // Item trees
    MAKE_RAW_TYPE_ACCESSORS(ItemTreeArmor, ItemTreeArmor);
    MAKE_RAW_TYPE_ACCESSORS(ItemTreeIngredient, ItemTreeIngredient);
    MAKE_RAW_TYPE_ACCESSORS(ItemTreePotion, ItemTreePotion);
    MAKE_RAW_TYPE_ACCESSORS(ItemTreeWeapon, ItemTreeWeapon);
};

};

#endif
