// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_ITEM_TREE_H_
#define _GECKO_ITEM_TREE_H_

// Internal includes
#include "CharacterAction/CharacterAction.h"
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

    // Retrieve item data
    static const ItemDataArmor& RetrieveItemDataArmor(const TreeIndex& treeIndex);
    static const ItemDataIngredient& RetrieveItemDataIngredient(const TreeIndex& treeIndex);
    static const ItemDataPotion& RetrieveItemDataPotion(const TreeIndex& treeIndex);
    static const ItemDataWeapon& RetrieveItemDataWeapon(const TreeIndex& treeIndex);

    // Retrieve item type
    static String RetrieveItemType(const TreeIndex& treeIndex);

    // Get item lists
    static TreeIndexArray GetAllArmorItems();
    static TreeIndexArray GetAllIngredientItems();
    static TreeIndexArray GetAllPotionItems();
    static TreeIndexArray GetAllWeaponItems();
    static TreeIndexArray GetAllEquippedItems(const String& sCharID);

    // Resolve leaf into index
    static TreeIndex ResolveItemLeafIntoIndex(const String& sLeaf);

    // Determine if item is actionable
    static Bool IsItemActionable(const TreeIndex& treeIndex);

    // Generate character actions
    static Bool GenerateItemCharacterActions(const TreeIndex& treeIndex,
        const String& sCharacterID,
        const String& sWeaponSet,
        CharacterActionArray& vActions);

    // Check "better" quality
    static Bool IsArmorBetter(const TreeIndex& index1, const TreeIndex& index2);
    static Bool IsWeaponBetter(const TreeIndex& index1, const TreeIndex& index2);

    // Check item type
    static Bool IsItemWeapon(const TreeIndex& treeIndex);
    static Bool IsItemShield(const TreeIndex& treeIndex);

    // Get action types
    static StringArray GetActionTypes(const TreeIndex& treeIndex);

    // Get stat changes
    static void FillItemStatChangeArrays(const TreeIndexArray& vItemDataArray,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables);
};

};

#endif
