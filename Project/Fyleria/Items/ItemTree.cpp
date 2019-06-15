// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Items/ItemTree.h"
#include "Config/ConfigManager.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Utility/Constants.h"
#include "Utility/FantasyName.h"
#include "Utility/Json.h"

namespace Gecko
{

#define POSTPROCESS_ITEMS(tree)                                                         \
{                                                                                       \
    for(const TreeIndex& treeIndex : GetAll##tree##Items())                             \
    {                                                                                   \
        ItemData##tree& itemData = ItemTree##tree::GetInstance()->GetLeaf(treeIndex);   \
        itemData.SetItemTreeIndex(treeIndex);                                           \
        for(StatChange& statChange : itemData.GetStatChanges())                         \
        {                                                                               \
            statChange.SetItemTreeIndex(treeIndex);                                     \
        }                                                                               \
    }                                                                                   \
}

void ItemTree::LoadItemTreesIntoMemory()
{
    // Armor
    ItemTreeArmor::GetInstance()->AddBranch("Chest", ConfigManager::GetInstance()->GetItemArmorChestFile());
    ItemTreeArmor::GetInstance()->AddBranch("Feet", ConfigManager::GetInstance()->GetItemArmorFeetFile());
    ItemTreeArmor::GetInstance()->AddBranch("Finger", ConfigManager::GetInstance()->GetItemArmorFingerFile());
    ItemTreeArmor::GetInstance()->AddBranch("Hands", ConfigManager::GetInstance()->GetItemArmorHandsFile());
    ItemTreeArmor::GetInstance()->AddBranch("Head", ConfigManager::GetInstance()->GetItemArmorHeadFile());
    ItemTreeArmor::GetInstance()->AddBranch("Neck", ConfigManager::GetInstance()->GetItemArmorNeckFile());
    ItemTreeArmor::GetInstance()->AddBranch("Legs", ConfigManager::GetInstance()->GetItemArmorLegsFile());
    ItemTreeArmor::GetInstance()->AddBranch("Shield", ConfigManager::GetInstance()->GetItemArmorShieldFile());

    // Ingredient
    ItemTreeIngredient::GetInstance()->AddBranch("Bar", ConfigManager::GetInstance()->GetItemIngredientBarFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Cloth", ConfigManager::GetInstance()->GetItemIngredientClothFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Crystal", ConfigManager::GetInstance()->GetItemIngredientCrystalFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Leather", ConfigManager::GetInstance()->GetItemIngredientLeatherFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Mail", ConfigManager::GetInstance()->GetItemIngredientMailFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Plate", ConfigManager::GetInstance()->GetItemIngredientPlateFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Scale", ConfigManager::GetInstance()->GetItemIngredientScaleFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Screw", ConfigManager::GetInstance()->GetItemIngredientScrewFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Sheet", ConfigManager::GetInstance()->GetItemIngredientSheetFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Stud", ConfigManager::GetInstance()->GetItemIngredientStudFile());
    ItemTreeIngredient::GetInstance()->AddBranch("Thread", ConfigManager::GetInstance()->GetItemIngredientThreadFile());

    // Potion
    ItemTreePotion::GetInstance()->AddBranch("Energy", ConfigManager::GetInstance()->GetItemPotionEnergyFile());
    ItemTreePotion::GetInstance()->AddBranch("Heal", ConfigManager::GetInstance()->GetItemPotionHealFile());
    ItemTreePotion::GetInstance()->AddBranch("Magic", ConfigManager::GetInstance()->GetItemPotionMagicFile());
    ItemTreePotion::GetInstance()->AddBranch("Speed", ConfigManager::GetInstance()->GetItemPotionSpeedFile());

    // Weapon
    ItemTreeWeapon::GetInstance()->AddBranch("Blunt", ConfigManager::GetInstance()->GetItemWeaponBluntFile());
    ItemTreeWeapon::GetInstance()->AddBranch("Mage", ConfigManager::GetInstance()->GetItemWeaponMageFile());
    ItemTreeWeapon::GetInstance()->AddBranch("Pierce", ConfigManager::GetInstance()->GetItemWeaponPierceFile());
    ItemTreeWeapon::GetInstance()->AddBranch("Slash", ConfigManager::GetInstance()->GetItemWeaponSlashFile());

    // Post process item data
    POSTPROCESS_ITEMS(Armor);
    POSTPROCESS_ITEMS(Ingredient);
    POSTPROCESS_ITEMS(Potion);
    POSTPROCESS_ITEMS(Weapon);
}

void ItemTree::UnloadItemTreesFromMemory()
{
    // Clear all item data
    ItemTreeArmor::GetInstance()->ClearAllData();
    ItemTreeIngredient::GetInstance()->ClearAllData();
    ItemTreePotion::GetInstance()->ClearAllData();
    ItemTreeWeapon::GetInstance()->ClearAllData();
}

#define VERIFY_APPLY_STATCHANGES(tree, character_target)                                                        \
{                                                                                                               \
    String sBaseType = (+CharacterSegmentType::Base)._to_string();                                              \
    for(const TreeIndex& treeIndex : GetAll##tree##Items())                                                     \
    {                                                                                                           \
        ItemData##tree& itemData = ItemTree##tree::GetInstance()->GetLeaf(treeIndex);                           \
        LOG_FORMAT_STATEMENT("Processing item (ItemTreeType = '%s', "                                           \
                             "ItemType = '%s', "                                                                \
                             "ItemName = '%s', "                                                                \
                             "StatChanges = %zu)\n",                                                            \
            #tree,                                                                                              \
            itemData.GetItemType().c_str(),                                                                     \
            itemData.GetItemName().c_str(),                                                                     \
            itemData.GetStatChanges().size());                                                                  \
        for(StatChange change : itemData.GetStatChanges())                                                      \
        {                                                                                                       \
            Bool bAll, bOne = false;                                                                            \
            change.SetSourceTargetType(character_target);                                                       \
            change.SetDestinationTargetType(character_target);                                                  \
            change.SetChanceToApply(1.0);                                                                       \
            CharacterManager::GetInstance()->ApplyStatChange(sBaseType, change, bAll, bOne, true);              \
        }                                                                                                       \
    }                                                                                                           \
}

void ItemTree::VerifyItemTrees()
{
    // Log start
    LOG_STATEMENT("Verifying item trees...");

    // Load character generator
    CharacterGenerator generator;
    generator.RandomizeAll();

    // Generate a character and party
    const String sCharacterID("CharacterID");
    const String sCharacterPartyID("CharacterPartyID");
    const String sCharacterPartyType("Ally");
    CharacterManager::GetInstance()->GenerateCharacter(sCharacterID, generator);
    CharacterPartyManager::GetInstance()->CreateParty(sCharacterPartyID, sCharacterPartyType, true);
    CharacterPartyManager::GetInstance()->GetPartyByID(sCharacterPartyID).AddMember(sCharacterID);
    const String sCharacterTargetType = CharacterManager::GetInstance()->GetCharacter(sCharacterID).GetCharacterTargetType();

    // Apply all stat changes
    VERIFY_APPLY_STATCHANGES(Armor, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Ingredient, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Potion, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Weapon, sCharacterTargetType);

    // Cleanup
    CharacterPartyManager::GetInstance()->GetPartyByID(sCharacterPartyID).RemoveMember(sCharacterID);
    CharacterPartyManager::GetInstance()->UnloadParty(sCharacterPartyID);
    CharacterManager::GetInstance()->UnloadCharacter(sCharacterID);
}

Bool ItemTree::DoesItemDataExist(const TreeIndex& treeIndex)
{
    return (
        DoesItemDataArmorExist(treeIndex) ||
        DoesItemDataIngredientExist(treeIndex) ||
        DoesItemDataPotionExist(treeIndex) ||
        DoesItemDataWeaponExist(treeIndex)
    );
}

Bool ItemTree::DoesItemDataArmorExist(const TreeIndex& treeIndex)
{
    return ItemTreeArmor::GetInstance()->HasLeaf(treeIndex);
}

Bool ItemTree::DoesItemDataIngredientExist(const TreeIndex& treeIndex)
{
    return ItemTreeIngredient::GetInstance()->HasLeaf(treeIndex);
}

Bool ItemTree::DoesItemDataPotionExist(const TreeIndex& treeIndex)
{
    return ItemTreePotion::GetInstance()->HasLeaf(treeIndex);
}

Bool ItemTree::DoesItemDataWeaponExist(const TreeIndex& treeIndex)
{
    return ItemTreeWeapon::GetInstance()->HasLeaf(treeIndex);
}

const ItemDataArmor& ItemTree::RetrieveItemDataArmor(const TreeIndex& treeIndex)
{
    return ItemTreeArmor::GetInstance()->GetLeaf(treeIndex);
}

const ItemDataIngredient& ItemTree::RetrieveItemDataIngredient(const TreeIndex& treeIndex)
{
    return ItemTreeIngredient::GetInstance()->GetLeaf(treeIndex);
}

const ItemDataPotion& ItemTree::RetrieveItemDataPotion(const TreeIndex& treeIndex)
{
    return ItemTreePotion::GetInstance()->GetLeaf(treeIndex);
}

const ItemDataWeapon& ItemTree::RetrieveItemDataWeapon(const TreeIndex& treeIndex)
{
    return ItemTreeWeapon::GetInstance()->GetLeaf(treeIndex);
}

String ItemTree::RetrieveItemType(const TreeIndex& treeIndex)
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

#define ADD_ITEM_LEAVES(tree, branch)                                           \
{                                                                               \
    String sBranchName(#branch);                                                \
    auto vLeaves = ItemTree##tree::GetInstance()->GetAllLeaves(sBranchName);    \
    vFinal.insert(vFinal.end(), vLeaves.begin(), vLeaves.end());                \
}

TreeIndexArray ItemTree::GetAllArmorItems()
{
    TreeIndexArray vFinal;
    ADD_ITEM_LEAVES(Armor, Chest);
    ADD_ITEM_LEAVES(Armor, Feet);
    ADD_ITEM_LEAVES(Armor, Finger);
    ADD_ITEM_LEAVES(Armor, Hands);
    ADD_ITEM_LEAVES(Armor, Head);
    ADD_ITEM_LEAVES(Armor, Neck);
    ADD_ITEM_LEAVES(Armor, Legs);
    ADD_ITEM_LEAVES(Armor, Shield);
    return vFinal;
}

TreeIndexArray ItemTree::GetAllIngredientItems()
{
    TreeIndexArray vFinal;
    ADD_ITEM_LEAVES(Ingredient, Bar);
    ADD_ITEM_LEAVES(Ingredient, Cloth);
    ADD_ITEM_LEAVES(Ingredient, Crystal);
    ADD_ITEM_LEAVES(Ingredient, Leather);
    ADD_ITEM_LEAVES(Ingredient, Mail);
    ADD_ITEM_LEAVES(Ingredient, Plate);
    ADD_ITEM_LEAVES(Ingredient, Scale);
    ADD_ITEM_LEAVES(Ingredient, Screw);
    ADD_ITEM_LEAVES(Ingredient, Sheet);
    ADD_ITEM_LEAVES(Ingredient, Stud);
    ADD_ITEM_LEAVES(Ingredient, Thread);
    return vFinal;
}

TreeIndexArray ItemTree::GetAllPotionItems()
{
    TreeIndexArray vFinal;
    ADD_ITEM_LEAVES(Potion, Energy);
    ADD_ITEM_LEAVES(Potion, Heal);
    ADD_ITEM_LEAVES(Potion, Magic);
    ADD_ITEM_LEAVES(Potion, Speed);
    return vFinal;
}

TreeIndexArray ItemTree::GetAllWeaponItems()
{
    TreeIndexArray vFinal;
    ADD_ITEM_LEAVES(Weapon, Blunt);
    ADD_ITEM_LEAVES(Weapon, Mage);
    ADD_ITEM_LEAVES(Weapon, Pierce);
    ADD_ITEM_LEAVES(Weapon, Slash);
    return vFinal;
}

TreeIndexArray ItemTree::GetAllEquippedItems(const String& sCharID)
{
    TreeIndexArray vFinal;
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharID))
    {
        return vFinal;
    }

    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
    for(auto& item : character.GetEquippedItems())
    {
        vFinal.push_back(item.GetItemTreeIndex());
    }
    return vFinal;
}

TreeIndex ItemTree::ResolveItemLeafIntoIndex(const String& sLeaf)
{
    // Branch name
    String sBranch;

    // Check armor
    sBranch = ItemTreeArmor::GetInstance()->GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex((+ItemTreeType::Armor)._to_string(), sBranch, sLeaf);
    }

    // Check weapon
    sBranch = ItemTreeWeapon::GetInstance()->GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex((+ItemTreeType::Weapon)._to_string(), sBranch, sLeaf);
    }

    // Check potion
    sBranch = ItemTreePotion::GetInstance()->GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex((+ItemTreeType::Potion)._to_string(), sBranch, sLeaf);
    }

    // Check ingredient
    sBranch = ItemTreeIngredient::GetInstance()->GetBranchFromLeaf(sLeaf);
    if(!sBranch.empty())
    {
        return TreeIndex((+ItemTreeType::Ingredient)._to_string(), sBranch, sLeaf);
    }

    // Nothing found
    return TreeIndex();
}

Bool ItemTree::IsItemActionable(const TreeIndex& treeIndex)
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

Bool ItemTree::GenerateItemCharacterActions(const TreeIndex& treeIndex,
    const String& sCharacterID,
    const String& sWeaponSet,
    CharacterActionArray& vActions)
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

Bool ItemTree::IsArmorBetter(const TreeIndex& treeIndex1, const TreeIndex& treeIndex2)
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

Bool ItemTree::IsWeaponBetter(const TreeIndex& treeIndex1, const TreeIndex& treeIndex2)
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

Bool ItemTree::IsItemWeapon(const TreeIndex& treeIndex)
{
    return DoesItemDataWeaponExist(treeIndex);
}

Bool ItemTree::IsItemShield(const TreeIndex& treeIndex)
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

StringArray ItemTree::GetActionTypes(const TreeIndex& treeIndex)
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

void ItemTree::FillItemStatChangeArrays(const TreeIndexArray& vItemDataArray,
    TreeIndexArray& vPassives,
    TreeIndexArray& vActives,
    TreeIndexArray& vActionables)
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
