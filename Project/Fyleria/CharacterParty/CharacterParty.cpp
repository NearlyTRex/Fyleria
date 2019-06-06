// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "CharacterParty/CharacterParty.h"
#include "CharacterData/CharacterProgressData.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "Utility/Errors.h"
#include "Utility/Converters.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterParty::CharacterParty()
{
}

CharacterParty::CharacterParty(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterParty::CharacterParty(const String& jsonString)
{
    from_json(JsonParse(jsonString), *this);
}

void CharacterParty::RegenerateCharacterData()
{
    for(auto& member : GetMembers())
    {
        CharacterManager::GetInstance()->GetCharacter(member.first).RegenerateCharacterData();
    }
}

Bool CharacterParty::IsPartyAbleToFight() const
{
    UInt uMemberCount = GetMemberCount();
    if(uMemberCount == 0)
    {
        return false;
    }

    UInt uDeadMemberCount = GetStatusMemberCount((+CharacterStatusType::Dead)._to_string());
    if(uMemberCount == uDeadMemberCount)
    {
        return false;
    }
    return true;
}

Bool CharacterParty::IsPartyFull() const
{
    return GetNextAvailableTargetType().IsNone();
}

Bool CharacterParty::IsMemberPresent(const IndexedString& sCharacterID) const
{
    for(auto& member : GetMembers())
    {
        if (member.first == sCharacterID)
        {
            return true;
        }
    }
    return false;
}

Bool CharacterParty::IsTargetTypeAvailable(const IndexedString& sCharacterTargetType) const
{
    const IndexedStringArray& vTargetTypes = GetAvailableTargetTypes();
    auto iLocation = STDFindData(vTargetTypes.begin(), vTargetTypes.end(), sCharacterTargetType);
    return (iLocation != vTargetTypes.end());
}

Bool CharacterParty::IsTargetTypeTaken(const IndexedString& sCharacterTargetType) const
{
    const IndexedStringArray& vTargetTypes = GetTakenTargetTypes();
    auto iLocation = STDFindData(vTargetTypes.begin(), vTargetTypes.end(), sCharacterTargetType);
    return (iLocation != vTargetTypes.end());
}

Bool CharacterParty::AddMember(const IndexedString& sCharacterID)
{
    // Check if party is full
    if(IsPartyFull())
    {
        ERROR_FORMAT_STATEMENT("Party at ID '%s' is full\n", GetPartyID().c_str());
        return false;
    }

    // Check if member does not exist first
    if(IsMemberPresent(sCharacterID))
    {
        ERROR_FORMAT_STATEMENT("Character at ID '%s' was already present in party\n", sCharacterID.c_str());
        return false;
    }

    // Add member
    CharacterPartyMember newMember;
    newMember.SetCharacterID(sCharacterID);
    newMember.SetCharacterTargetType(GetNextAvailableTargetType());
    GetMembers().insert({sCharacterID, newMember});
    UseTargetType(newMember.GetCharacterTargetType());
    CharacterManager::GetInstance()->GetCharacter(sCharacterID).GetBasicData().SetPartyID(GetPartyID());
    return true;
}

Bool CharacterParty::RemoveMember(const IndexedString& sCharacterID)
{
    // Check if member exists first
    if(!IsMemberPresent(sCharacterID))
    {
        ERROR_FORMAT_STATEMENT("Character at ID '%s' was not present in party\n", sCharacterID.c_str());
        return false;
    }

    // Remove member
    UnequipAllItems(sCharacterID);
    FreeTargetType(GetMemberByID(sCharacterID).GetCharacterTargetType());
    CharacterManager::GetInstance()->GetCharacter(sCharacterID).GetBasicData().SetPartyID({});
    GetMembers().erase(sCharacterID);
    return true;
}

Bool CharacterParty::MoveMember(const IndexedString& sCharacterID, const IndexedString& sCharacterTargetType)
{
    // Check if member exists first
    if(!IsMemberPresent(sCharacterID))
    {
        ERROR_FORMAT_STATEMENT("Character at ID '%s' was not present in party\n", sCharacterID.c_str());
        return false;
    }

    // Check if new target type is available
    if(!IsTargetTypeAvailable(sCharacterTargetType))
    {
        ERROR_FORMAT_STATEMENT("Target type '%s' is not available\n", sCharacterTargetType.c_str());
        return false;
    }

    // Set new target type
    CharacterPartyMember& member = GetMemberByID(sCharacterID);
    FreeTargetType(member.GetCharacterTargetType());
    UseTargetType(sCharacterTargetType);
    member.SetCharacterTargetType(sCharacterTargetType);
    return true;
}

Bool CharacterParty::SwapMembers(const IndexedString& sFirstCharacterID, const IndexedString& sSecondCharacterID)
{
    // Check if members exists first
    if(!IsMemberPresent(sFirstCharacterID) || !IsMemberPresent(sSecondCharacterID))
    {
        ERROR_FORMAT_STATEMENT("Character at ID '%s' or ID '%s' was not present in party\n",
            sFirstCharacterID.c_str(),
            sSecondCharacterID.c_str());
        return false;
    }

    // Swap target types
    CharacterPartyMember& firstMember = GetMemberByID(sFirstCharacterID);
    CharacterPartyMember& secondMember = GetMemberByID(sSecondCharacterID);
    IndexedString sFirstTargetType = firstMember.GetCharacterTargetType();
    IndexedString sSecondTargetType = secondMember.GetCharacterTargetType();
    firstMember.SetCharacterTargetType(sSecondTargetType);
    secondMember.SetCharacterTargetType(sFirstTargetType);
    return true;
}

IndexedString CharacterParty::GetNextAvailableTargetType() const
{
    for(const IndexedString& sTarget : GetAvailableTargetTypes())
    {
        return sTarget;
    }
    return IndexedString("None");
}

Bool CharacterParty::UseTargetType(const IndexedString& sCharacterTargetType)
{
    if(!IsTargetTypeAvailable(sCharacterTargetType))
    {
        return false;
    }

    RemoveVectorElement<IndexedString>(GetAvailableTargetTypes(), sCharacterTargetType);
    GetTakenTargetTypes().push_back(sCharacterTargetType);
    return true;
}

Bool CharacterParty::FreeTargetType(const IndexedString& sCharacterTargetType)
{
    if(!IsTargetTypeTaken(sCharacterTargetType))
    {
        return false;
    }

    GetAvailableTargetTypes().push_back(sCharacterTargetType);
    RemoveVectorElement<IndexedString>(GetTakenTargetTypes(), sCharacterTargetType);
    return true;
}

const CharacterPartyMember& CharacterParty::GetMemberByID(const IndexedString& sCharacterID) const
{
    return GetMembers().at(sCharacterID);
}

const CharacterPartyMember& CharacterParty::GetMemberByTargetType(const IndexedString& sCharacterTargetType) const
{
    for (auto& member : GetMembers())
    {
        if (member.second.GetCharacterTargetType() == sCharacterTargetType)
        {
            return member.second;
        }
    }
    throw RuntimeError("No character matching character target type '" + sCharacterTargetType.Get() + "' was found");
}

CharacterPartyMember& CharacterParty::GetMemberByID(const IndexedString& sCharacterID)
{
    return const_cast<CharacterPartyMember&>(static_cast<const CharacterParty&>(*this).GetMemberByID(sCharacterID));
}

CharacterPartyMember& CharacterParty::GetMemberByTargetType(const IndexedString& sCharacterTargetType)
{
    return const_cast<CharacterPartyMember&>(static_cast<const CharacterParty&>(*this).GetMemberByTargetType(sCharacterTargetType));
}

IndexedStringArray CharacterParty::GetMemberCharacterIDs() const
{
    IndexedStringArray vMemberCharacterIDs;
    for(auto& member : GetMembers())
    {
        vMemberCharacterIDs.push_back(member.first);
    }
    return vMemberCharacterIDs;
}

Bool CharacterParty::GetCharacterIDsFromTargetType(const IndexedString& sCharacterTargetType, IndexedStringArray& vCharacterIDs) const
{
    // Check if requesting something that cannot be resolved
    CharacterTargetType eTargetType = StringToCharacterTargetType(sCharacterTargetType);
    switch(eTargetType)
    {
        case CharacterTargetType::Self:
        case CharacterTargetType::ActionTargetsThisAction:
        case CharacterTargetType::ActionSourceThisAction:
        case CharacterTargetType::ActionTargetsThisRound:
        case CharacterTargetType::ActionSourcesThisRound:
        case CharacterTargetType::ActionTargetsLastRound:
        case CharacterTargetType::ActionSourcesLastRound:
        case CharacterTargetType::MostRecentActionTargets:
        case CharacterTargetType::MostRecentActionSource:
            return false;
        default:
            break;
    }

    // Check if requesting for all allies/enemies
    IndexedStringArray vAllMemberCharacterIDs = GetMemberCharacterIDs();
    CharacterPartyType ePartyType = StringToCharacterPartyType(GetPartyType());
    if((ePartyType == +CharacterPartyType::Ally && eTargetType == +CharacterTargetType::AllAllies) ||
       (ePartyType == +CharacterPartyType::Enemy && eTargetType == +CharacterTargetType::AllEnemies))
    {
        vCharacterIDs = vAllMemberCharacterIDs;
        return true;
    }

    // Then check for specific targets
    const CharacterPartyMember& member = GetMemberByTargetType(sCharacterTargetType);
    if(!member.GetCharacterID().empty())
    {
        vCharacterIDs.push_back(member.GetCharacterID());
        return true;
    }
    return false;
}

UInt CharacterParty::GetStatusMemberCount(const IndexedString& sStatus) const
{
    UInt uCount = 0;
    const CharacterStatusType eStatusType = StringToCharacterStatusTypeOrNone(sStatus);
    for(auto& member : GetMembers())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(member.first);
        const CharacterBattleData& battleData = character.GetBattleDataBase();
        switch(eStatusType)
        {
            case CharacterStatusType::Dead:
                uCount += (battleData.GetIsDead()) ? 1 : 0;
                break;
            case CharacterStatusType::Unconscious:
                uCount += (battleData.GetIsUnconscious()) ? 1 : 0;
                break;
            default:
                break;
        }
    }
    return uCount;
}

Bool CharacterParty::AddRandomItems(const IndexedStringArray& vTreeTypes, Int iNumRandomItems, Int iAmountStart, Int iAmountEnd)
{
    // Notify user
    LOG_FORMAT_STATEMENT(
        "Trying to add random items to party '%s' "
        "(vTreeTypes = '%s', iNumRandomItems = %d, iAmountStart = %d, iAmountEnd = %d)\n",
        GetPartyID().c_str(),
        ConcatStringVector(vTreeTypes).c_str(),
        iNumRandomItems,
        iAmountStart,
        iAmountEnd);

    // Get lists of all items
    TreeIndexArray vAllArmors = ItemTree::GetAllArmorItems();
    TreeIndexArray vAllIngredients = ItemTree::GetAllIngredientItems();
    TreeIndexArray vAllPotions = ItemTree::GetAllPotionItems();
    TreeIndexArray vAllWeapons = ItemTree::GetAllWeaponItems();

    // Shuffle item lists
    ShuffleVector<TreeIndex>(vAllArmors);
    ShuffleVector<TreeIndex>(vAllIngredients);
    ShuffleVector<TreeIndex>(vAllPotions);
    ShuffleVector<TreeIndex>(vAllWeapons);

    // Take a look at each tree type
    Bool bAtLeastOneAdded = false;
    TreeIndexArray vAddedRandomTreeIndices;
    for(const IndexedString& sTreeType : vTreeTypes)
    {
        // Only do a certain amount of random pulls
        const ItemTreeType eItemTreeType = StringToItemTreeTypeOrNone(sTreeType);
        for(Int i = 0; i < iNumRandomItems; i++)
        {
            // Get the random item
            TreeIndex randomTreeIndex;
            switch(eItemTreeType)
            {
                case ItemTreeType::Armor:
                    randomTreeIndex = GetRandomVectorValue<TreeIndex>(vAllArmors);
                    break;
                case ItemTreeType::Ingredient:
                    randomTreeIndex = GetRandomVectorValue<TreeIndex>(vAllIngredients);
                    break;
                case ItemTreeType::Potion:
                    randomTreeIndex = GetRandomVectorValue<TreeIndex>(vAllPotions);
                    break;
                case ItemTreeType::Weapon:
                    randomTreeIndex = GetRandomVectorValue<TreeIndex>(vAllWeapons);
                    break;
                default:
                    break;
            }

            // Add item
            if(!randomTreeIndex.empty())
            {
                UInt uAmount = GetRandomIntValue<Int>(iAmountStart, iAmountEnd);
                Bool bSuccess = AddItemByTreeIndex(randomTreeIndex, uAmount);
                if(bSuccess)
                {
                    LOG_FORMAT_STATEMENT("Added item '%s' to party '%s' by amount %d\n",
                        randomTreeIndex.GetTreeBranchLeafType().c_str(),
                        GetPartyID().c_str(),
                        uAmount);
                    vAddedRandomTreeIndices.push_back(randomTreeIndex);
                }
                bAtLeastOneAdded = bAtLeastOneAdded || bSuccess;
            }
        }
    }
    return bAtLeastOneAdded;
}

Bool CharacterParty::AddItemByLeaf(const IndexedString& sLeaf, UInt uAmount)
{
    TreeIndex treeIndex = ItemTree::ResolveItemLeafIntoIndex(sLeaf);
    if(treeIndex.empty())
    {
        ERROR_FORMAT_STATEMENT("Unable to resolve leaf '%s' into a valid tree index\n", sLeaf.c_str());
        return false;
    }

    if(!ItemTree::DoesItemDataExist(treeIndex))
    {
        ERROR_FORMAT_STATEMENT("Tree index '%s' was not found\n", treeIndex.GetTreeBranchLeafType().c_str());
        return false;
    }

    if (GetItems().count(sLeaf) > 0)
    {
        CharacterPartyItem& item = GetItems().at(sLeaf);
#ifdef DEBUG
        Json jsonData = item;
        String sJsonString = jsonData.dump(4);
        LOG_FORMAT_STATEMENT("Adding value of %d to existing item to party (PartyID = '%s'):\n%s\n",
            uAmount,
            GetPartyID().c_str(),
            sJsonString.c_str());
#endif
        return item.AddAmount(uAmount);
    }
    else
    {
        IndexedString sItemType = ItemTree::RetrieveItemType(treeIndex);
        IndexedStringArray vEquipTypes = ConvertItemTypeToCharacterEquipTypes(sItemType);
        CharacterPartyItem newItem;
        newItem.SetTreeIndex(treeIndex);
        newItem.SetAmount(uAmount);
        newItem.SetEquipCount(0);
        newItem.SetApplicableEquipmentSlots(vEquipTypes);
        GetItems().insert({sLeaf, newItem});
#ifdef DEBUG
        Json jsonData = newItem;
        String sJsonString = jsonData.dump(4);
        LOG_FORMAT_STATEMENT("Adding new item to party (PartyID = '%s'):\n%s\n",
            GetPartyID().c_str(),
            sJsonString.c_str());
#endif
        return true;
    }
}

Bool CharacterParty::AddItemByTreeIndex(const TreeIndex& treeIndex, UInt uAmount)
{
    return AddItemByLeaf(treeIndex.GetLeaf(), uAmount);
}

Bool CharacterParty::RemoveItemByLeaf(const IndexedString& sLeaf, UInt uAmount)
{
    if (GetItems().count(sLeaf) > 0)
    {
        CharacterPartyItem& item = GetItems().at(sLeaf);
        return item.RemoveAmount(uAmount);
    }
    return false;
}

Bool CharacterParty::RemoveItemByTreeIndex(const TreeIndex& treeIndex, UInt uAmount)
{
    return RemoveItemByLeaf(treeIndex.GetLeaf(), uAmount);
}

const CharacterPartyItem& CharacterParty::GetItemByLeaf(const IndexedString& sLeaf) const
{
    return GetItems().at(sLeaf);
}

const CharacterPartyItem& CharacterParty::GetItemByTreeIndex(const TreeIndex& treeIndex) const
{
    return GetItems().at(treeIndex.GetLeaf());
}

CharacterPartyItem& CharacterParty::GetItemByLeaf(const IndexedString& sLeaf)
{
    return const_cast<CharacterPartyItem&>(static_cast<const CharacterParty&>(*this).GetItemByLeaf(sLeaf));
}

CharacterPartyItem& CharacterParty::GetItemByTreeIndex(const TreeIndex& treeIndex)
{
    return const_cast<CharacterPartyItem&>(static_cast<const CharacterParty&>(*this).GetItemByTreeIndex(treeIndex));
}

TreeIndex CharacterParty::GetBestUnequippedItem(const IndexedString& sCharacterID, const IndexedString& sSlot) const
{
    // Check character
    TreeIndex bestItem;
    if(!IsMemberPresent(sCharacterID))
    {
        return bestItem;
    }

    // Get shield count for this weapon set (if applicable)
    // We do this because we don't want to autofill more than one shield
    LOG_FORMAT_STATEMENT("Looking for best unequipped item (matching slot '%s') for character '%s' in party '%s'\n",
        sSlot.c_str(),
        sCharacterID.c_str(),
        GetPartyID().c_str());
    const IndexedString sWeaponSet = ConvertCharacterEquipmentTypeToCharacterWeaponSetType(sSlot);
    UInt uShieldCount = 0;
    if(!sWeaponSet.IsNone())
    {
        uShieldCount = GetMemberByID(sCharacterID).GetEquippedShieldCount(sWeaponSet);
    }

    // Look at each of the matching, unequipped items the party has and find the best one
    for(auto& item : GetItems())
    {
        if(uShieldCount == 1 && ItemTree::IsItemShield(item.second.GetTreeIndex()))
        {
            continue;
        }

        if(!item.second.DoesMatchSlot(sSlot))
        {
            continue;
        }

        if(!item.second.CanEquipAmount(1))
        {
            continue;
        }

        if(bestItem.empty())
        {
            bestItem = item.second.GetTreeIndex();
            continue;
        }

        Bool bIsArmor = ItemTree::DoesItemDataArmorExist(item.second.GetTreeIndex());
        Bool bIsWeapon = ItemTree::DoesItemDataWeaponExist(item.second.GetTreeIndex());
        if(
            (bIsArmor && ItemTree::IsArmorBetter(item.second.GetTreeIndex(), bestItem)) ||
            (bIsWeapon && ItemTree::IsWeaponBetter(item.second.GetTreeIndex(), bestItem)))
        {
            bestItem = item.second.GetTreeIndex();
        }
    }
#if DEBUG
    if(!bestItem.empty())
    {
        LOG_FORMAT_STATEMENT("Found item '%s'\n", bestItem.GetTreeBranchLeafType().c_str());
    }
#endif
    return bestItem;
}

Bool CharacterParty::EquipItem(const IndexedString& sCharacterID, const IndexedString& sLeaf, const IndexedString& sSlot)
{
    // Get the item and character
    CharacterPartyItem& item = GetItemByLeaf(sLeaf);
    CharacterPartyMember& member = GetMemberByID(sCharacterID);

    // Check if the item can be equipped
    if(!item.DoesMatchSlot(sSlot))
    {
        ERROR_FORMAT_STATEMENT("Item '%s' does not match slot '%s'\n",
            sLeaf.c_str(),
            sSlot.c_str());
        return false;
    }
    if(!item.CanEquipAmount(1))
    {
        ERROR_FORMAT_STATEMENT("Item '%s' cannot be equipped (Amount = %d, Equip Count = %d)\n",
            sLeaf.c_str(),
            item.GetAmount(),
            item.GetEquipCount());
        return false;
    }
    if(!member.CanAddEquippedItem(item.GetTreeIndex()))
    {
        ERROR_FORMAT_STATEMENT("Member '%s' in party '%s' cannot equip item '%s'\n",
            sCharacterID.c_str(),
            GetPartyID().c_str(),
            sLeaf.c_str());
        return false;
    }

    // Mark the item as being equipped
    if(!member.AddEquippedItem(item.GetTreeIndex(), sSlot) || !item.EquipAmount(1))
    {
        ERROR_FORMAT_STATEMENT("Member '%s' in party '%s' was not able to equip item '%s' to slot '%s'\n",
            sCharacterID.c_str(),
            GetPartyID().c_str(),
            sLeaf.c_str(),
            sSlot.c_str());
        return false;
    }
    return true;
}

Bool CharacterParty::UnequipItem(const IndexedString& sCharacterID, const IndexedString& sLeaf, const IndexedString& sSlot)
{
    // Get the item and character
    CharacterPartyItem& item = GetItemByLeaf(sLeaf);
    CharacterPartyMember& member = GetMemberByID(sCharacterID);

    // Check if the item can be unequipped
    if(!item.DoesMatchSlot(sSlot))
    {
        ERROR_FORMAT_STATEMENT("Item '%s' does not match slot '%s'\n",
            sLeaf.c_str(),
            sSlot.c_str());
        return false;
    }
    if(!item.CanUnequipAmount(1))
    {
        ERROR_FORMAT_STATEMENT("Item '%s' cannot be unequipped (Amount = %d, Equip Count = %d)\n",
            sLeaf.c_str(),
            item.GetAmount(),
            item.GetEquipCount());
        return false;
    }
    if(!member.CanRemoveEquippedItem(item.GetTreeIndex()))
    {
        ERROR_FORMAT_STATEMENT("Member '%s' in party '%s' cannot unequip item '%s'\n",
            sCharacterID.c_str(),
            GetPartyID().c_str(),
            sLeaf.c_str());
        return false;
    }

    // Mark the item as being equipped
    if(!member.RemoveEquippedItem(item.GetTreeIndex(), sSlot) || !item.UnequipAmount(1))
    {
        ERROR_FORMAT_STATEMENT("Member '%s' in party '%s' was not able to unequip item '%s' to slot '%s'\n",
            sCharacterID.c_str(),
            GetPartyID().c_str(),
            sLeaf.c_str(),
            sSlot.c_str());
        return false;
    }
    return true;
}

Bool CharacterParty::EquipBestItems(const IndexedString& sCharacterID)
{
    // First unequip all that character's items
    UnequipAllItems(sCharacterID);

    // Get the best available item for each equipment slot
    for(const IndexedString& sEquipType : CharacterEquipmentType::_names())
    {
        // Get best item for this slot
        TreeIndex bestItemForSlot = GetBestUnequippedItem(sCharacterID, sEquipType);
        if(bestItemForSlot.empty())
        {
            continue;
        }

        // Try equipping
        if(!EquipItem(sCharacterID, bestItemForSlot.GetLeaf(), sEquipType))
        {
            continue;
        }
    }
    return true;
}

Bool CharacterParty::EquipBestItemsForAllMembers()
{
    for(auto& member : GetMembers())
    {
        EquipBestItems(member.first);
    }
    return true;
}

Bool CharacterParty::UnequipAllItems(const IndexedString& sCharacterID)
{
    // Get the member
    CharacterPartyMember& member = GetMemberByID(sCharacterID);

    // Try unequipping all of the character's items
    Bool bAtLeastOneSuccess = false;
    for(auto&& equippedItem : member.GetEquippedItems())
    {
        Bool bSuccess = UnequipItem(
            sCharacterID,
            equippedItem.GetTreeIndex().GetLeaf(),
            equippedItem.GetItemSlot());
        bAtLeastOneSuccess = bAtLeastOneSuccess || bSuccess;
    }
    return bAtLeastOneSuccess;
}

Bool CharacterParty::UnequipAllItemsForAllMembers()
{
    for(auto& member : GetMembers())
    {
        UnequipAllItems(member.first);
    }
    return true;
}

UInt CharacterParty::GetMemberCount() const
{
    return GetMembers().size();
}

UInt CharacterParty::GetItemCount() const
{
    return GetItems().size();
}

String CharacterParty::GetDescription() const
{
    String sDescription;
#if DEBUG
    sDescription += "Party ID: " + GetPartyID().Get() + "\n";
    sDescription += "Party Type: " + GetPartyType().Get() + "\n";
    sDescription += "Play Time: " + ConvertGameTimeToString(GetPlayTime()) + "\n";
    sDescription += "Members: \n";
    for(auto& member: GetMembers())
    {
        sDescription += "\t" + member.first.Get() + "\n";
    }
#endif
    return sDescription;
}

void CharacterParty::ResetPlayTime()
{
    LOG_FORMAT_STATEMENT("Resetting play time for party '%s'\n", GetPartyID().c_str());
    SetCurrentPlayTime(0);
    SetLastTimePoint(STDGetCurrentTimePoint());
    SetPlayTimePaused(true);
}

void CharacterParty::PausePlayTime()
{
    LOG_FORMAT_STATEMENT("Pausing play time for party '%s'\n", GetPartyID().c_str());
    if (GetPlayTimePaused())
    {
        return;
    }
    STDTimePoint currentTimePoint = STDGetCurrentTimePoint();
    ULongLong uDuration = STDGetTimePointDuration(currentTimePoint - GetLastTimePoint()).count();
    SetCurrentPlayTime(GetCurrentPlayTime() + uDuration);
    SetPlayTimePaused(true);
}

void CharacterParty::ResumePlayTime()
{
    LOG_FORMAT_STATEMENT("Resuming play time for party '%s'\n", GetPartyID().c_str());
    if (!GetPlayTimePaused())
    {
        return;
    }
    SetLastTimePoint(STDGetCurrentTimePoint());
    SetPlayTimePaused(false);
}

ULongLong CharacterParty::GetPlayTime() const
{
    if (GetPlayTimePaused())
    {
        return GetCurrentPlayTime();
    }
    else
    {
        STDTimePoint currentTimePoint = STDGetCurrentTimePoint();
        ULongLong uDuration = STDGetTimePointDuration(currentTimePoint - GetLastTimePoint()).count();
        return (GetCurrentPlayTime() + uDuration);
    }
}

void CharacterParty::SetPlayTime(ULongLong uTime)
{
    SetCurrentPlayTime(uTime);
}

void to_json(Json& jsonData, const CharacterParty& obj)
{
    // Party ID
    SET_JSON_DATA_IF_NOT_DEFAULT(PartyID, IndexedString(""));

    // Party type
    SET_JSON_DATA_IF_NOT_DEFAULT(PartyType, IndexedString("None"));

    // Map of members
    SET_JSON_DATA_IF_NOT_EMPTY(Members);

    // Map of items
    SET_JSON_DATA_IF_NOT_EMPTY(Items);

    // Arrays of available target types
    SET_JSON_DATA_IF_NOT_EMPTY(AvailableTargetTypes);

    // Array of taken target types
    SET_JSON_DATA_IF_NOT_EMPTY(TakenTargetTypes);

    // Play time
    SET_JSON_DATA_IF_NOT_DEFAULT(PlayTime, 0);
}

void from_json(const Json& jsonData, CharacterParty& obj)
{
    // Party ID
    obj.SetPartyID(GET_JSON_DATA_OR_DEFAULT(PartyID, IndexedString, IndexedString("")));

    // Party type
    obj.SetPartyType(GET_JSON_DATA_OR_DEFAULT(PartyType, IndexedString, IndexedString("None")));

    // Map of members
    obj.SetMembers(GET_JSON_DATA_OR_DEFAULT(Members, CharacterParty::CharacterPartyMemberMapType, CharacterParty::CharacterPartyMemberMapType()));

    // Map of items
    obj.SetItems(GET_JSON_DATA_OR_DEFAULT(Items, CharacterParty::CharacterPartyItemMapType, CharacterParty::CharacterPartyItemMapType()));

    // Arrays of available target types
    obj.SetAvailableTargetTypes(GET_JSON_DATA_OR_DEFAULT(AvailableTargetTypes, IndexedStringArray, IndexedStringArray()));

    // Array of taken target types
    obj.SetTakenTargetTypes(GET_JSON_DATA_OR_DEFAULT(TakenTargetTypes, IndexedStringArray, IndexedStringArray()));

    // Play time
    obj.SetPlayTime(GET_JSON_DATA_OR_DEFAULT(PlayTime, ULongLong, 0));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterParty, CharacterParty);

};
