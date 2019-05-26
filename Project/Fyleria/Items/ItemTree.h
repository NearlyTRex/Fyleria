// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_ITEM_TREE_H_
#define _GECKO_ITEM_TREE_H_

#include "CharacterAction/CharacterAction.h"
#include "Module/ModuleResultManager.h"
#include "Items/ItemDataArmor.h"
#include "Items/ItemDataIngredient.h"
#include "Items/ItemDataPotion.h"
#include "Items/ItemDataWeapon.h"
#include "Utility/Tree.h"

namespace Gecko
{

// Typedefs
typedef Tree<ItemDataArmor> ItemTreeArmor;
typedef Tree<ItemDataIngredient> ItemTreeIngredient;
typedef Tree<ItemDataPotion> ItemTreePotion;
typedef Tree<ItemDataWeapon> ItemTreeWeapon;

class ItemTree
{
public:

    // Load/unload item trees into memory
    static void LoadItemTreesIntoMemory();
    static void UnloadItemTreesFromMemory();

    // Verify
    static void VerifyItemTrees();

    // Determine if item data exists
    static Bool DoesItemDataExist(const TreeIndex& treeIndex);
    static Bool DoesItemDataArmorExist(const TreeIndex& treeIndex);
    static Bool DoesItemDataIngredientExist(const TreeIndex& treeIndex);
    static Bool DoesItemDataPotionExist(const TreeIndex& treeIndex);
    static Bool DoesItemDataWeaponExist(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesItemDataExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesItemDataArmorExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesItemDataIngredientExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesItemDataPotionExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesItemDataWeaponExist, const TreeIndex&, treeIndex);

    // Retrieve item data
    static const ItemDataArmor& RetrieveItemDataArmor(const TreeIndex& treeIndex);
    static const ItemDataIngredient& RetrieveItemDataIngredient(const TreeIndex& treeIndex);
    static const ItemDataPotion& RetrieveItemDataPotion(const TreeIndex& treeIndex);
    static const ItemDataWeapon& RetrieveItemDataWeapon(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveItemDataArmor, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveItemDataIngredient, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveItemDataPotion, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveItemDataWeapon, const TreeIndex&, treeIndex);

    // Retrieve item type
    static IndexedString RetrieveItemType(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveItemType, const TreeIndex&, treeIndex);

    // Get item lists
    static TreeIndexArray GetAllArmorItems();
    static TreeIndexArray GetAllIngredientItems();
    static TreeIndexArray GetAllPotionItems();
    static TreeIndexArray GetAllWeaponItems();
    static TreeIndexArray GetAllEquippedItems(const IndexedString& sCharID);
    static MAKE_MODULE_RESULT_VARIANT(GetAllArmorItems);
    static MAKE_MODULE_RESULT_VARIANT(GetAllIngredientItems);
    static MAKE_MODULE_RESULT_VARIANT(GetAllPotionItems);
    static MAKE_MODULE_RESULT_VARIANT(GetAllWeaponItems);
    static MAKE_MODULE_RESULT_VARIANT_A1(GetAllEquippedItems, const IndexedString&, sCharID);

    // Resolve leaf into index
    static TreeIndex ResolveItemLeafIntoIndex(const IndexedString& sLeaf);
    static MAKE_MODULE_RESULT_VARIANT_A1(ResolveItemLeafIntoIndex, const IndexedString&, sLeaf);

    // Determine if item is actionable
    static Bool IsItemActionable(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(IsItemActionable, const TreeIndex&, treeIndex);

    // Generate character actions
    static Bool GenerateItemCharacterActions(const TreeIndex& treeIndex,
        const IndexedString& sCharacterID,
        const IndexedString& sWeaponSet,
        CharacterActionArray& vActions);

    // Check "better" quality
    static Bool IsArmorBetter(const TreeIndex& index1, const TreeIndex& index2);
    static Bool IsWeaponBetter(const TreeIndex& index1, const TreeIndex& index2);
    static MAKE_MODULE_RESULT_VARIANT_A2(IsArmorBetter, const TreeIndex&, index1, const TreeIndex&, index2);
    static MAKE_MODULE_RESULT_VARIANT_A2(IsWeaponBetter, const TreeIndex&, index1, const TreeIndex&, index2);

    // Check item type
    static Bool IsItemWeapon(const TreeIndex& treeIndex);
    static Bool IsItemShield(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(IsItemWeapon, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(IsItemShield, const TreeIndex&, treeIndex);

    // Get action types
    static IndexedStringArray GetActionTypes(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(GetActionTypes, const TreeIndex&, treeIndex);

    // Get stat changes
    static void FillItemStatChangeArrays(const TreeIndexArray& vItemDataArray,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables);
};

};

#endif
