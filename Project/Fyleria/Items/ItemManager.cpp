// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Items/ItemManager.h"
#include "Utility/Constants.h"
#include "Utility/FantasyName.h"
#include "Utility/Json.h"
#include "Utility/ManagerSet.h"

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
    // Armor
    GetItemTreeArmor().AddBranch("Chest", ITEM_FILE_ARMOR_CHEST, GetDataItemsDirectory());
    GetItemTreeArmor().AddBranch("Feet", ITEM_FILE_ARMOR_FEET, GetDataItemsDirectory());
    GetItemTreeArmor().AddBranch("Finger", ITEM_FILE_ARMOR_FINGER, GetDataItemsDirectory());
    GetItemTreeArmor().AddBranch("Hands", ITEM_FILE_ARMOR_HANDS, GetDataItemsDirectory());
    GetItemTreeArmor().AddBranch("Head", ITEM_FILE_ARMOR_HEAD, GetDataItemsDirectory());
    GetItemTreeArmor().AddBranch("Neck", ITEM_FILE_ARMOR_NECK, GetDataItemsDirectory());
    GetItemTreeArmor().AddBranch("Legs", ITEM_FILE_ARMOR_LEGS, GetDataItemsDirectory());
    GetItemTreeArmor().AddBranch("Shield", ITEM_FILE_ARMOR_SHIELD, GetDataItemsDirectory());

    // Ingredient
    GetItemTreeIngredient().AddBranch("Bar", ITEM_FILE_INGREDIENT_BAR, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Cloth", ITEM_FILE_INGREDIENT_CLOTH, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Crystal", ITEM_FILE_INGREDIENT_CRYSTAL, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Leather", ITEM_FILE_INGREDIENT_LEATHER, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Mail", ITEM_FILE_INGREDIENT_MAIL, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Plate", ITEM_FILE_INGREDIENT_PLATE, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Scale", ITEM_FILE_INGREDIENT_SCALE, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Screw", ITEM_FILE_INGREDIENT_SCREW, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Sheet", ITEM_FILE_INGREDIENT_SHEET, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Stud", ITEM_FILE_INGREDIENT_STUD, GetDataItemsDirectory());
    GetItemTreeIngredient().AddBranch("Thread", ITEM_FILE_INGREDIENT_THREAD, GetDataItemsDirectory());

    // Potion
    GetItemTreePotion().AddBranch("Energy", ITEM_FILE_POTION_ENERGY, GetDataItemsDirectory());
    GetItemTreePotion().AddBranch("Heal", ITEM_FILE_POTION_HEAL, GetDataItemsDirectory());
    GetItemTreePotion().AddBranch("Magic", ITEM_FILE_POTION_MAGIC, GetDataItemsDirectory());
    GetItemTreePotion().AddBranch("Speed", ITEM_FILE_POTION_SPEED, GetDataItemsDirectory());

    // Weapon
    GetItemTreeWeapon().AddBranch("Blunt", ITEM_FILE_WEAPON_BLUNT, GetDataItemsDirectory());
    GetItemTreeWeapon().AddBranch("Mage", ITEM_FILE_WEAPON_MAGE, GetDataItemsDirectory());
    GetItemTreeWeapon().AddBranch("Pierce", ITEM_FILE_WEAPON_PIERCE, GetDataItemsDirectory());
    GetItemTreeWeapon().AddBranch("Slash", ITEM_FILE_WEAPON_SLASH, GetDataItemsDirectory());

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

TreeIndexArray ItemManager::GetAllEquippedItems(ManagerSet* pManagerSet, const String& sCharID) const
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Check character existence
    TreeIndexArray vFinal;
    if(!pManagerSet->GetCharacterManager().DoesCharacterExist(sCharID))
    {
        return vFinal;
    }

    // Get items
    const Character& character = pManagerSet->GetCharacterManager().GetCharacter(sCharID);
    for(auto& item : character.GetEquippedItems(pManagerSet))
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
        return TreeIndex((+ItemTreeType::Armor)._to_string(), sBranch, sLeaf);
    }

    // Check weapon
    sBranch = GetItemTreeWeapon().GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex((+ItemTreeType::Weapon)._to_string(), sBranch, sLeaf);
    }

    // Check potion
    sBranch = GetItemTreePotion().GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex((+ItemTreeType::Potion)._to_string(), sBranch, sLeaf);
    }

    // Check ingredient
    sBranch = GetItemTreeIngredient().GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex((+ItemTreeType::Ingredient)._to_string(), sBranch, sLeaf);
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
    ManagerSet* pManagerSet,
    const TreeIndex& treeIndex,
    const String& sCharacterID,
    const String& sWeaponSet,
    CharacterActionArray& vActions) const
{
    if(DoesItemDataArmorExist(treeIndex))
    {
        const ItemDataArmor& itemData = RetrieveItemDataArmor(treeIndex);
        if(itemData.IsActionable() && itemData.DoesMeetActionRequirements(pManagerSet, sCharacterID, sWeaponSet))
        {
            CharacterActionArray vNewActions = itemData.CreateArmorActions(sCharacterID, sWeaponSet);
            vActions.insert(vActions.end(), vNewActions.begin(), vNewActions.end());
            return true;
        }
    }
    else if(DoesItemDataPotionExist(treeIndex))
    {
        const ItemDataPotion& itemData = RetrieveItemDataPotion(treeIndex);
        if(itemData.IsActionable() && itemData.DoesMeetActionRequirements(pManagerSet, sCharacterID, sWeaponSet))
        {
            CharacterActionArray vNewActions = itemData.CreatePotionActions(sCharacterID, sWeaponSet);
            vActions.insert(vActions.end(), vNewActions.begin(), vNewActions.end());
            return true;
        }
    }
    else if(DoesItemDataWeaponExist(treeIndex))
    {
        const ItemDataWeapon& itemData = RetrieveItemDataWeapon(treeIndex);
        if(itemData.IsActionable() && itemData.DoesMeetActionRequirements(pManagerSet, sCharacterID, sWeaponSet))
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
    ManagerSet* pManagerSet,
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
            for(const StatChange& statChange : GetStatChangesFromItemTreeIndex(pManagerSet, treeIndex))
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
