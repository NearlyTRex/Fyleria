// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Item/ItemManager.h"
#include "Item/ItemConstants.h"
#include "Utility/FantasyName.h"
#include "Utility/Json.h"
#include "Application/Application.h"

namespace Gecko
{

ItemManager::ItemManager()
{
}

template <class T>
void PostProcessItems(T& tree, const TreeIndexArray& vTreeIndices)
{
    for(auto& treeIndex : vTreeIndices)
    {
        auto& itemData = tree.GetLeaf(treeIndex);
        itemData.SetItemTreeIndex(treeIndex);
        for(auto& statChange : itemData.GetStatChanges())
        {
            statChange.SetItemTreeIndex(treeIndex);
        }
    }
}

void ItemManager::LoadItemTreesIntoMemory()
{
    // Items location
    String sLocation = GetManagers()->GetFileManager()->GetDataTreesItemsDirectory();

    // Create file loader
    auto fnFileLoader = [&](const String& sBranchFile, const String& sFileRoot) -> Json
    {
        // Log loading of JSON data
        LOG_FORMAT_STATEMENT("Loading item file '{}'", sBranchFile.c_str());

        // Read json data
        Json jsonData;
        if(!ReadJsonFile(sBranchFile, jsonData, sFileRoot))
        {
            THROW_RUNTIME_ERROR("Could not load data from '" + sBranchFile + "'");
        }
        return jsonData;
    };

    // Armor
    GetItemTreeArmor().AddBranch("Chest", fnFileLoader(ITEM_FILE_ARMOR_CHEST, sLocation));
    GetItemTreeArmor().AddBranch("Feet", fnFileLoader(ITEM_FILE_ARMOR_FEET, sLocation));
    GetItemTreeArmor().AddBranch("Finger", fnFileLoader(ITEM_FILE_ARMOR_FINGER, sLocation));
    GetItemTreeArmor().AddBranch("Hands", fnFileLoader(ITEM_FILE_ARMOR_HANDS, sLocation));
    GetItemTreeArmor().AddBranch("Head", fnFileLoader(ITEM_FILE_ARMOR_HEAD, sLocation));
    GetItemTreeArmor().AddBranch("Neck", fnFileLoader(ITEM_FILE_ARMOR_NECK, sLocation));
    GetItemTreeArmor().AddBranch("Legs", fnFileLoader(ITEM_FILE_ARMOR_LEGS, sLocation));
    GetItemTreeArmor().AddBranch("Shield", fnFileLoader(ITEM_FILE_ARMOR_SHIELD, sLocation));

    // Ingredient
    GetItemTreeIngredient().AddBranch("Bar", fnFileLoader(ITEM_FILE_INGREDIENT_BAR, sLocation));
    GetItemTreeIngredient().AddBranch("Cloth", fnFileLoader(ITEM_FILE_INGREDIENT_CLOTH, sLocation));
    GetItemTreeIngredient().AddBranch("Crystal", fnFileLoader(ITEM_FILE_INGREDIENT_CRYSTAL, sLocation));
    GetItemTreeIngredient().AddBranch("Leather", fnFileLoader(ITEM_FILE_INGREDIENT_LEATHER, sLocation));
    GetItemTreeIngredient().AddBranch("Mail", fnFileLoader(ITEM_FILE_INGREDIENT_MAIL, sLocation));
    GetItemTreeIngredient().AddBranch("Plate", fnFileLoader(ITEM_FILE_INGREDIENT_PLATE, sLocation));
    GetItemTreeIngredient().AddBranch("Scale", fnFileLoader(ITEM_FILE_INGREDIENT_SCALE, sLocation));
    GetItemTreeIngredient().AddBranch("Screw", fnFileLoader(ITEM_FILE_INGREDIENT_SCREW, sLocation));
    GetItemTreeIngredient().AddBranch("Sheet", fnFileLoader(ITEM_FILE_INGREDIENT_SHEET, sLocation));
    GetItemTreeIngredient().AddBranch("Stud", fnFileLoader(ITEM_FILE_INGREDIENT_STUD, sLocation));
    GetItemTreeIngredient().AddBranch("Thread", fnFileLoader(ITEM_FILE_INGREDIENT_THREAD, sLocation));

    // Potion
    GetItemTreePotion().AddBranch("Energy", fnFileLoader(ITEM_FILE_POTION_ENERGY, sLocation));
    GetItemTreePotion().AddBranch("Heal", fnFileLoader(ITEM_FILE_POTION_HEAL, sLocation));
    GetItemTreePotion().AddBranch("Magic", fnFileLoader(ITEM_FILE_POTION_MAGIC, sLocation));
    GetItemTreePotion().AddBranch("Speed", fnFileLoader(ITEM_FILE_POTION_SPEED, sLocation));

    // Weapon
    GetItemTreeWeapon().AddBranch("Blunt", fnFileLoader(ITEM_FILE_WEAPON_BLUNT, sLocation));
    GetItemTreeWeapon().AddBranch("Mage", fnFileLoader(ITEM_FILE_WEAPON_MAGE, sLocation));
    GetItemTreeWeapon().AddBranch("Pierce", fnFileLoader(ITEM_FILE_WEAPON_PIERCE, sLocation));
    GetItemTreeWeapon().AddBranch("Slash", fnFileLoader(ITEM_FILE_WEAPON_SLASH, sLocation));

    // Post process item data
    PostProcessItems<ItemTreeArmor>(GetItemTreeArmor(), GetAllArmorItems());
    PostProcessItems<ItemTreeIngredient>(GetItemTreeIngredient(), GetAllIngredientItems());
    PostProcessItems<ItemTreePotion>(GetItemTreePotion(), GetAllPotionItems());
    PostProcessItems<ItemTreeWeapon>(GetItemTreeWeapon(), GetAllWeaponItems());
}

void ItemManager::UnloadItemTreesFromMemory()
{
    // Clear all item data
    GetItemTreeArmor().ClearAllData();
    GetItemTreeIngredient().ClearAllData();
    GetItemTreePotion().ClearAllData();
    GetItemTreeWeapon().ClearAllData();
}

Bool ItemManager::DoesItemDataExist(const TreeIndex& treeIndex) const
{
    return (
        DoesItemDataArmorExist(treeIndex) ||
        DoesItemDataIngredientExist(treeIndex) ||
        DoesItemDataPotionExist(treeIndex) ||
        DoesItemDataWeaponExist(treeIndex)
    );
}

Bool ItemManager::DoesItemDataArmorExist(const TreeIndex& treeIndex) const
{
    return GetItemTreeArmor().HasLeaf(treeIndex);
}

Bool ItemManager::DoesItemDataIngredientExist(const TreeIndex& treeIndex) const
{
    return GetItemTreeIngredient().HasLeaf(treeIndex);
}

Bool ItemManager::DoesItemDataPotionExist(const TreeIndex& treeIndex) const
{
    return GetItemTreePotion().HasLeaf(treeIndex);
}

Bool ItemManager::DoesItemDataWeaponExist(const TreeIndex& treeIndex) const
{
    return GetItemTreeWeapon().HasLeaf(treeIndex);
}

const ItemDataArmor& ItemManager::RetrieveItemDataArmor(const TreeIndex& treeIndex) const
{
    return GetItemTreeArmor().GetLeaf(treeIndex);
}

const ItemDataIngredient& ItemManager::RetrieveItemDataIngredient(const TreeIndex& treeIndex) const
{
    return GetItemTreeIngredient().GetLeaf(treeIndex);
}

const ItemDataPotion& ItemManager::RetrieveItemDataPotion(const TreeIndex& treeIndex) const
{
    return GetItemTreePotion().GetLeaf(treeIndex);
}

const ItemDataWeapon& ItemManager::RetrieveItemDataWeapon(const TreeIndex& treeIndex) const
{
    return GetItemTreeWeapon().GetLeaf(treeIndex);
}

String ItemManager::RetrieveItemType(const TreeIndex& treeIndex) const
{
    if(DoesItemDataArmorExist(treeIndex))
    {
        return RetrieveItemDataArmor(treeIndex).GetItemType();
    }
    else if(DoesItemDataIngredientExist(treeIndex))
    {
        return RetrieveItemDataIngredient(treeIndex).GetItemType();
    }
    else if(DoesItemDataPotionExist(treeIndex))
    {
        return (RetrieveItemDataPotion(treeIndex).GetItemType());
    }
    else if(DoesItemDataWeaponExist(treeIndex))
    {
        return RetrieveItemDataWeapon(treeIndex).GetItemType();
    }
    return GetNoneTypeForEnum<ItemTreeType>();
}

template <class T>
void AddItemLeaves(const T& tree, const String& sBranchName, TreeIndexArray& vLeaves)
{
    auto vNewLeaves = tree.GetAllLeaves(sBranchName);
    vLeaves.insert(vLeaves.end(), vNewLeaves.begin(), vNewLeaves.end());
}

TreeIndexArray ItemManager::GetAllArmorItems() const
{
    TreeIndexArray vFinal;
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Chest", vFinal);
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Feet", vFinal);
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Finger", vFinal);
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Hands", vFinal);
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Head", vFinal);
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Neck", vFinal);
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Legs", vFinal);
    AddItemLeaves<ItemTreeArmor>(GetItemTreeArmor(), "Shield", vFinal);
    return vFinal;
}

TreeIndexArray ItemManager::GetAllIngredientItems() const
{
    TreeIndexArray vFinal;
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Bar", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Cloth", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Crystal", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Leather", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Mail", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Plate", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Scale", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Screw", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Sheet", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Stud", vFinal);
    AddItemLeaves<ItemTreeIngredient>(GetItemTreeIngredient(), "Thread", vFinal);
    return vFinal;
}

TreeIndexArray ItemManager::GetAllPotionItems() const
{
    TreeIndexArray vFinal;
    AddItemLeaves<ItemTreePotion>(GetItemTreePotion(), "Energy", vFinal);
    AddItemLeaves<ItemTreePotion>(GetItemTreePotion(), "Heal", vFinal);
    AddItemLeaves<ItemTreePotion>(GetItemTreePotion(), "Magic", vFinal);
    AddItemLeaves<ItemTreePotion>(GetItemTreePotion(), "Speed", vFinal);
    return vFinal;
}

TreeIndexArray ItemManager::GetAllWeaponItems() const
{
    TreeIndexArray vFinal;
    AddItemLeaves<ItemTreeWeapon>(GetItemTreeWeapon(), "Blunt", vFinal);
    AddItemLeaves<ItemTreeWeapon>(GetItemTreeWeapon(), "Mage", vFinal);
    AddItemLeaves<ItemTreeWeapon>(GetItemTreeWeapon(), "Pierce", vFinal);
    AddItemLeaves<ItemTreeWeapon>(GetItemTreeWeapon(), "Slash", vFinal);
    return vFinal;
}

TreeIndexArray ItemManager::GetAllEquippedItems(const String& sCharID) const
{
    // Check character existence
    TreeIndexArray vFinal;
    if(!GetManagers()->GetCharacterManager()->DoesCharacterExist(sCharID))
    {
        return vFinal;
    }

    // Get items
    const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharID);
    for(auto& item : character.GetEquippedItems())
    {
        vFinal.push_back(item.GetItemTreeIndex());
    }
    return vFinal;
}

TreeIndex ItemManager::ResolveItemLeafIntoIndex(const String& sLeaf) const
{
    // Branch name
    String sBranch;

    // Check armor
    sBranch = GetItemTreeArmor().GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex(GetEnumString(ItemTreeType::Armor), sBranch, sLeaf);
    }

    // Check weapon
    sBranch = GetItemTreeWeapon().GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex(GetEnumString(ItemTreeType::Weapon), sBranch, sLeaf);
    }

    // Check potion
    sBranch = GetItemTreePotion().GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex(GetEnumString(ItemTreeType::Potion), sBranch, sLeaf);
    }

    // Check ingredient
    sBranch = GetItemTreeIngredient().GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex(GetEnumString(ItemTreeType::Ingredient), sBranch, sLeaf);
    }

    // Nothing found
    return TreeIndex();
}

Bool ItemManager::IsItemActionable(const TreeIndex& treeIndex) const
{
    if(DoesItemDataArmorExist(treeIndex))
    {
        return RetrieveItemDataArmor(treeIndex).IsActionable();
    }
    else if(DoesItemDataPotionExist(treeIndex))
    {
        return RetrieveItemDataPotion(treeIndex).IsActionable();
    }
    else if(DoesItemDataWeaponExist(treeIndex))
    {
        return RetrieveItemDataWeapon(treeIndex).IsActionable();
    }
    return false;
}

Bool ItemManager::GenerateItemCharacterActions(
    const TreeIndex& treeIndex,
    const String& sCharacterID,
    const String& sWeaponSet,
    CharacterActionArray& vActions) const
{
    if(DoesItemDataArmorExist(treeIndex))
    {
        const ItemDataArmor& itemData = RetrieveItemDataArmor(treeIndex);
        if(itemData.IsActionable() && itemData.DoesMeetActionRequirements(sCharacterID, sWeaponSet))
        {
            CharacterActionArray vNewActions = itemData.CreateArmorActions(sCharacterID, sWeaponSet);
            vActions.insert(vActions.end(), vNewActions.begin(), vNewActions.end());
            return true;
        }
    }
    else if(DoesItemDataPotionExist(treeIndex))
    {
        const ItemDataPotion& itemData = RetrieveItemDataPotion(treeIndex);
        if(itemData.IsActionable() && itemData.DoesMeetActionRequirements(sCharacterID, sWeaponSet))
        {
            CharacterActionArray vNewActions = itemData.CreatePotionActions(sCharacterID, sWeaponSet);
            vActions.insert(vActions.end(), vNewActions.begin(), vNewActions.end());
            return true;
        }
    }
    else if(DoesItemDataWeaponExist(treeIndex))
    {
        const ItemDataWeapon& itemData = RetrieveItemDataWeapon(treeIndex);
        if(itemData.IsActionable() && itemData.DoesMeetActionRequirements(sCharacterID, sWeaponSet))
        {
            CharacterActionArray vNewActions = itemData.CreateWeaponActions(sCharacterID, sWeaponSet);
            vActions.insert(vActions.end(), vNewActions.begin(), vNewActions.end());
            return true;
        }
    }
    return false;
}

Bool ItemManager::IsArmorBetter(const TreeIndex& treeIndex1, const TreeIndex& treeIndex2) const
{
    if(!DoesItemDataArmorExist(treeIndex1) || !DoesItemDataArmorExist(treeIndex2))
    {
        return false;
    }

    const ItemDataArmor& itemData1 = RetrieveItemDataArmor(treeIndex1);
    const ItemDataArmor& itemData2 = RetrieveItemDataArmor(treeIndex2);
    return (
        itemData1.GetBluntDefendPercent() > itemData2.GetBluntDefendPercent() &&
        itemData1.GetPierceDefendPercent() > itemData2.GetPierceDefendPercent() &&
        itemData1.GetSlashDefendPercent() > itemData2.GetSlashDefendPercent() &&
        itemData1.GetMagicDefendPercent() > itemData2.GetMagicDefendPercent());
}

Bool ItemManager::IsWeaponBetter(const TreeIndex& treeIndex1, const TreeIndex& treeIndex2) const
{
    if(!DoesItemDataWeaponExist(treeIndex1) || !DoesItemDataWeaponExist(treeIndex2))
    {
        return false;
    }

    const ItemDataWeapon& itemData1 = RetrieveItemDataWeapon(treeIndex1);
    const ItemDataWeapon& itemData2 = RetrieveItemDataWeapon(treeIndex2);
    return (
        itemData1.GetBluntAttackPercent() > itemData2.GetBluntAttackPercent() &&
        itemData1.GetPierceAttackPercent() > itemData2.GetPierceAttackPercent() &&
        itemData1.GetSlashAttackPercent() > itemData2.GetSlashAttackPercent());
}

Bool ItemManager::IsItemWeapon(const TreeIndex& treeIndex) const
{
    return DoesItemDataWeaponExist(treeIndex);
}

Bool ItemManager::IsItemShield(const TreeIndex& treeIndex) const
{
    if(DoesItemDataArmorExist(treeIndex))
    {
        const ItemDataArmor& item = RetrieveItemDataArmor(treeIndex);
        const ItemType& eType = GetEnumFromString<ItemType>(item.GetItemType());
        return (
            eType == +ItemType::ArmorShieldPierce ||
            eType == +ItemType::ArmorShieldBlunt ||
            eType == +ItemType::ArmorShieldSlash);
    }
    return false;
}

StringArray ItemManager::GetActionTypes(const TreeIndex& treeIndex) const
{
    StringArray vActionTypes;
    if(DoesItemDataArmorExist(treeIndex))
    {
        const ItemDataArmor& item = RetrieveItemDataArmor(treeIndex);
        vActionTypes.insert(vActionTypes.end(), item.GetActionTypes().begin(), item.GetActionTypes().end());
    }
    else if(DoesItemDataPotionExist(treeIndex))
    {
        const ItemDataPotion& item = RetrieveItemDataPotion(treeIndex);
        vActionTypes.insert(vActionTypes.end(), item.GetActionTypes().begin(), item.GetActionTypes().end());
    }
    else if(DoesItemDataWeaponExist(treeIndex))
    {
        const ItemDataWeapon& item = RetrieveItemDataWeapon(treeIndex);
        vActionTypes.insert(vActionTypes.end(), item.GetActionTypes().begin(), item.GetActionTypes().end());
    }
    return vActionTypes;
}

void ItemManager::FillItemStatChangeArrays(
    const TreeIndexArray& vItemDataArray,
    TreeIndexArray& vPassives,
    TreeIndexArray& vActives,
    TreeIndexArray& vActionables) const
{
    // Use a set to make sure that we do not include duplicates
    STDUnorderedSet<String> tAlreadyUsed;

    // Split them into separate lists
    for(const TreeIndex& treeIndex : vItemDataArray)
    {
        String sIndexKey = treeIndex.GetTreeBranchLeafType();
        Bool bIsActionable = IsItemActionable(treeIndex);
        Bool bIsAlreadyUsed = (tAlreadyUsed.count(sIndexKey) == 1);
        if(bIsActionable && !bIsAlreadyUsed)
        {
            vActionables.push_back(treeIndex);
            tAlreadyUsed.insert(sIndexKey);
        }
        else if(!bIsActionable && !bIsAlreadyUsed)
        {
            for(const StatChange& statChange : GetStatChangesFromItemTreeIndex(treeIndex))
            {
                if(statChange.IsPassive())
                {
                    vPassives.push_back(treeIndex);
                    tAlreadyUsed.insert(sIndexKey);
                    break;
                }
                else if(statChange.IsActive())
                {
                    vActives.push_back(treeIndex);
                    tAlreadyUsed.insert(sIndexKey);
                    break;
                }
            }
        }
    }
}

};
