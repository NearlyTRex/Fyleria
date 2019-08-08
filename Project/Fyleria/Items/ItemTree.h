// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_ITEM_MANAGER_H_
#define _GECKO_ITEM_MANAGER_H_

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

class ItemManager
{
public:

    // Constructors
    ItemManager();

    // Load/unload item trees into memory
    void LoadItemTreesIntoMemory();
    void UnloadItemTreesFromMemory();

    // Determine if item data exists
    Bool DoesItemDataExist(const TreeIndex& treeIndex);
    Bool DoesItemDataArmorExist(const TreeIndex& treeIndex);
    Bool DoesItemDataIngredientExist(const TreeIndex& treeIndex);
    Bool DoesItemDataPotionExist(const TreeIndex& treeIndex);
    Bool DoesItemDataWeaponExist(const TreeIndex& treeIndex);

    // Retrieve item data
    const ItemDataArmor& RetrieveItemDataArmor(const TreeIndex& treeIndex);
    const ItemDataIngredient& RetrieveItemDataIngredient(const TreeIndex& treeIndex);
    const ItemDataPotion& RetrieveItemDataPotion(const TreeIndex& treeIndex);
    const ItemDataWeapon& RetrieveItemDataWeapon(const TreeIndex& treeIndex);

    // Retrieve item type
    String RetrieveItemType(const TreeIndex& treeIndex);

    // Get item lists
    TreeIndexArray GetAllArmorItems();
    TreeIndexArray GetAllIngredientItems();
    TreeIndexArray GetAllPotionItems();
    TreeIndexArray GetAllWeaponItems();
    TreeIndexArray GetAllEquippedItems(const String& sCharID);

    // Resolve leaf into index
    TreeIndex ResolveItemLeafIntoIndex(const String& sLeaf);

    // Determine if item is actionable
    Bool IsItemActionable(const TreeIndex& treeIndex);

    // Generate character actions
    Bool GenerateItemCharacterActions(const TreeIndex& treeIndex,
        const String& sCharacterID,
        const String& sWeaponSet,
        CharacterActionArray& vActions);

    // Check "better" quality
    Bool IsArmorBetter(const TreeIndex& index1, const TreeIndex& index2);
    Bool IsWeaponBetter(const TreeIndex& index1, const TreeIndex& index2);

    // Check item type
    Bool IsItemWeapon(const TreeIndex& treeIndex);
    Bool IsItemShield(const TreeIndex& treeIndex);

    // Get action types
    StringArray GetActionTypes(const TreeIndex& treeIndex);

    // Get stat changes
    void FillItemStatChangeArrays(const TreeIndexArray& vItemDataArray,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables);

    // Item trees
    MAKE_RAW_TYPE_ACCESSORS(ItemTreeArmor, ItemTreeArmor);
    MAKE_RAW_TYPE_ACCESSORS(ItemTreeIngredient, ItemTreeIngredient);
    MAKE_RAW_TYPE_ACCESSORS(ItemTreePotion, ItemTreePotion);
    MAKE_RAW_TYPE_ACCESSORS(ItemTreeWeapon, ItemTreeWeapon);
};

};

#endif
