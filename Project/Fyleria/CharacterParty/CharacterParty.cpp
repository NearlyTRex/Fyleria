// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterParty/CharacterParty.h"
#include "Character/CharacterProgressData.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"

namespace Gecko
{

CharacterParty::CharacterParty()
    : m_bPlayTimePaused(true)
    , m_uCurrentPlayTime(0)
    , m_LastTimePoint()
{
}

void CharacterParty::RegenerateCharacterData()
{
    for(auto& member : GetMembers())
    {
        CharacterManager::GetInstance()->GetCharacter(member.GetCharacterID()).RegenerateCharacterData();
    }
}

Bool CharacterParty::IsPartyFull() const
{
    return GetNextAvailableTargetType().IsNone();
}

Bool CharacterParty::IsMemberPresent(const IndexedString& sCharacterID) const
{
    for(auto& member : GetMembers())
    {
        if (member.GetCharacterID() == sCharacterID)
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
    ASSERT_ERROR(!IsPartyFull(), "Party at ID '%s' is full", GetPartyID().c_str());
    if(IsPartyFull())
    {
        return false;
    }

    // Check if member does not exist first
    ASSERT_ERROR(!IsMemberPresent(sCharacterID), "Character at ID '%s' was already present in party", sCharacterID.c_str());
    if(IsMemberPresent(sCharacterID))
    {
        return false;
    }

    // Add member
    GetMembers().emplace_back(sCharacterID, GetNextAvailableTargetType());
    UseTargetType(newMember.GetCharacterTargetType());
    CharacterManager::GetInstance()->GetCharacter(sCharacterID).GetBasicData().SetPartyID(GetPartyID());
    return true;
}

Bool CharacterParty::RemoveMember(const IndexedString& sCharacterID)
{
    // Check if member exists first
    ASSERT_ERROR(IsMemberPresent(sCharacterID), "Character at ID '%s' was not present in party", sCharacterID.c_str());
    if(!IsMemberPresent(sCharacterID))
    {
        return false;
    }

    // Remove member
    UInt uMemberIndex = GetMemberIndexByID(sCharacterID);
    UnequipAllItems(uMemberIndex);
    FreeTargetType(GetMember(uMemberIndex).GetCharacterTargetType());
    CharacterManager::GetInstance()->GetCharacter(sCharacterID).GetBasicData().SetPartyID({});
    STDVectorRemoveElement<CharacterPartyMember>(GetMembers(), GetMember(uMemberIndex));
    return true;
}

Bool CharacterParty::MoveMember(const IndexedString& sCharacterID, const IndexedString& sCharacterTargetType)
{
    // Check if member exists first
    ASSERT_ERROR(IsMemberPresent(sCharacterID), "Character at ID '%s' was not present in party", sCharacterID.c_str());
    if(!IsMemberPresent(sCharacterID))
    {
        return false;
    }

    // Check if new target type is available
    if(!IsTargetTypeAvailable(sCharacterTargetType))
    {
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
    ASSERT_ERROR(IsMemberPresent(sFirstCharacterID), "Character at ID '%s' was not present in party", sFirstCharacterID.c_str());
    ASSERT_ERROR(IsMemberPresent(sSecondCharacterID), "Character at ID '%s' was not present in party", sSecondCharacterID.c_str());
    if(!IsMemberPresent(sFirstCharacterID) || !IsMemberPresent(sSecondCharacterID))
    {
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

    STDVectorRemoveElement<IndexedString>(GetAvailableTargetTypes(), sCharacterTargetType);
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
    STDVectorRemoveElement<IndexedString>(GetTakenTargetTypes(), sCharacterTargetType);
    return true;
}

Int CharacterParty::GetMemberIndexByID(const IndexedString& sCharacterID) const
{
    for(UInt i = 0; i < GetMembers().size(); i++)
    {
        if(GetMember(i).GetCharacterID() == sCharacterID)
        {
            return i;
        }
    }
    return -1;
}

Int CharacterParty::GetMemberIndexByTargetType(const IndexedString& sCharacterTargetType) const
{
    for(UInt i = 0; i < GetMembers().size(); i++)
    {
        if(GetMember(i).GetCharacterTargetType() == sCharacterTargetType)
        {
            return i;
        }
    }
    return -1;
}

const CharacterPartyMember& CharacterParty::GetMember(UInt uIndex) const
{
    return GetMembers().at(uIndex);
}

const CharacterPartyMember& CharacterParty::GetMemberByID(const IndexedString& sCharacterID) const
{
    return GetMembers().at(GetMemberIndexByID(sCharacterID));
}

const CharacterPartyMember& CharacterParty::GetMemberByTargetType(const IndexedString& sCharacterTargetType) const
{
    return GetMembers().at(GetMemberIndexByTargetType(sCharacterTargetType));
}

CharacterPartyMember& CharacterParty::GetMember(UInt uIndex)
{
    return const_cast<CharacterPartyMember&>(static_cast<const CharacterParty&>(*this).GetMember(uIndex));
}

CharacterPartyMember& CharacterParty::GetMemberByID(const IndexedString& sCharacterID)
{
    return const_cast<CharacterPartyMember&>(static_cast<const CharacterParty&>(*this).GetMemberByID(sCharacterID));
}

CharacterPartyMember& CharacterParty::GetMemberByTargetType(const IndexedString& sCharacterTargetType)
{
    return const_cast<CharacterPartyMember&>(static_cast<const CharacterParty&>(*this).GetMemberByTargetType(sCharacterTargetType));
}

Bool CharacterParty::GetCharacterIDsFromTargetType(const IndexedString& sCharacterTargetType, IndexedStringArray& vCharacterIDs) const
{
    // Check if requesting for all allies/enemies
    CharacterPartyType ePartyType = StringToCharacterPartyType(GetPartyType());
    CharacterTargetType eTargetType = StringToCharacterTargetType(sCharacterTargetType);
    if((ePartyType == +CharacterPartyType::Ally && eTargetType == +CharacterTargetType::AllAllies) ||
       (ePartyType == +CharacterPartyType::Enemy && eTargetType == +CharacterTargetType::AllEnemies))
    {
        vCharacterIDs = GetMembers();
        return true;
    }

    // Then check for specific targets
    Int iMemberIndex = GetMemberIndexByTargetType(sCharacterTargetType);
    if(iMemberIndex >= 0)
    {
        vCharacterIDs.push_back(GetMembers()[iMemberIndex]);
        return true;
    }
    return false;
}

UInt CharacterParty::GetStatusMemberCount(const IndexedString& sStatus) const
{
    UInt uCount = 0;
    const CharacterStatusType eStatusType = (IsValidCharacterStatusType(sStatus)) ? StringToCharacterStatusType(sStatus) : +CharacterStatusType::None;
    for(auto& member : GetMembers())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(member.GetCharacterID());
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
    // Get lists of all items
    TreeIndexArray vAllArmors = GetAllArmorItems();
    TreeIndexArray vAllIngredients = GetAllIngredientItems();
    TreeIndexArray vAllPotions = GetAllPotionItems();
    TreeIndexArray vAllWeapons = GetAllWeaponItems();

    // Shuffle item lists
    STDVectorShuffle<TreeIndex>(vAllArmors);
    STDVectorShuffle<TreeIndex>(vAllIngredients);
    STDVectorShuffle<TreeIndex>(vAllPotions);
    STDVectorShuffle<TreeIndex>(vAllWeapons);

    // Take a look at each tree type
    Bool bAtLeastOneAdded = false;
    TreeIndexArray vAddedRandomTreeIndices;
    for(const IndexedString& sTreeType : vTreeTypes)
    {
        // Only do a certain amount of random pulls
        const ItemTreeType eItemTreeType = IsValidItemTreeType(sTreeType) ? StringToItemTreeType(sTreeType) : +ItemTreeType::None;
        for(Int i = 0; i < iNumRandomItems; i++)
        {
            // Get the random item
            TreeIndex randomTreeIndex;
            switch(eItemTreeType)
            {
                case ItemTreeType::Armor:
                    randomTreeIndex = STDRandomVectorValue<TreeIndex>(vAllArmors);
                    break;
                case ItemTreeType::Ingredient:
                    randomTreeIndex = STDRandomVectorValue<TreeIndex>(vAllIngredients);
                    break;
                case ItemTreeType::Potion:
                    randomTreeIndex = STDRandomVectorValue<TreeIndex>(vAllPotions);
                    break;
                case ItemTreeType::Weapon:
                    randomTreeIndex = STDRandomVectorValue<TreeIndex>(vAllWeapons);
                    break;
                default:
                    break;
            }

            // Add item
            if(!randomTreeIndex.empty())
            {
                Bool bSuccess = AddItemByIndex(randomTreeIndex, STDRandomIntValue<Int>(iAmountStart, iAmountEnd));
                if(bSuccess)
                {
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
    return AddItemByIndex(ResolveItemLeafIntoIndex(sLeaf), uAmount);
}

Bool CharacterParty::AddItemByIndex(const TreeIndex& index, UInt uAmount)
{
    if(!DoesItemDataExist(index))
    {
        return false;
    }

    Int iFoundIndex = GetItemIndexByTreeIndex(index);
    if(iFoundIndex >= 0)
    {
        CharacterPartyItem& item = GetItems()[iFoundIndex];
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
        IndexedString sItemType = RetrieveItemType(index);
        IndexedStringArray vEquipTypes = ConvertItemTypeToCharacterEquipTypes(sItemType);
        CharacterPartyItem newItem;
        newItem.SetTreeIndex(index);
        newItem.SetAmount(uAmount);
        newItem.SetEquipCount(0);
        newItem.SetApplicableEquipmentSlots(vEquipTypes);
        GetItems().push_back(newItem);
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

Bool CharacterParty::RemoveItem(const TreeIndex& index, UInt uAmount)
{
    Int iFoundIndex = GetItemIndexByTreeIndex(index);
    if(iFoundIndex >= 0)
    {
        CharacterPartyItem& item = GetItems()[iFoundIndex];
        return item.RemoveAmount(uAmount);
    }
    return false;
}

Int CharacterParty::GetItemIndexByTreeIndex(const TreeIndex& index) const
{
    for(UInt i = 0; i < GetItems().size(); i++)
    {
        if(GetItem(i).GetTreeIndex() == index)
        {
            return i;
        }
    }
    return -1;
}

const CharacterPartyItem& CharacterParty::GetItem(UInt uIndex) const
{
    return GetItems().at(uIndex);
}

const CharacterPartyItem& CharacterParty::GetItemByTreeIndex(const TreeIndex& index) const
{
    return GetItems().at(GetItemIndexByTreeIndex(index));
}

CharacterPartyItem& CharacterParty::GetItem(UInt uIndex)
{
    return const_cast<CharacterPartyItem&>(static_cast<const CharacterParty&>(*this).GetItem(uIndex));
}

CharacterPartyItem& CharacterParty::GetItemByTreeIndex(const TreeIndex& index)
{
    return const_cast<CharacterPartyItem&>(static_cast<const CharacterParty&>(*this).GetItemByTreeIndex(index));
}

Int CharacterParty::GetBestUnequippedItemIndex(UInt uCharacterIndex, const IndexedString& sSlot) const
{
    // Check character
    Int iBestIndex = -1;
    if(uCharacterIndex >= GetMemberCount())
    {
        return iBestIndex;
    }

    // Get shield count for this weapon set (if applicable)
    // We do this because we don't want to autofill more than one shield
    const IndexedString sWeaponSet = ConvertCharacterEquipmentTypeToCharacterWeaponSetType(sSlot);
    UInt uShieldCount = 0;
    if(!sWeaponSet.IsNone())
    {
        uShieldCount = GetMember(uCharacterIndex).GetEquippedShieldCount(sWeaponSet);
    }

    // Look at each of the matching, unequipped items the party has and find the best one
    TreeIndex bestItem;
    for(UInt i = 0; i < GetItems().size(); i++)
    {
        const CharacterPartyItem& item = GetItems()[i];
        if(uShieldCount == 1 && IsItemShield(item.GetTreeIndex()))
        {
            continue;
        }

        if(!item.DoesMatchSlot(sSlot))
        {
            continue;
        }

        if(!item.CanEquipAmount(1))
        {
            continue;
        }

        if(bestItem.empty())
        {
            iBestIndex = i;
            bestItem = item.GetTreeIndex();
            continue;
        }

        Bool bIsArmor = DoesItemDataArmorExist(item.GetTreeIndex());
        Bool bIsWeapon = DoesItemDataWeaponExist(item.GetTreeIndex());
        if(
            (bIsArmor && IsArmorBetter(item.GetTreeIndex(), bestItem)) ||
            (bIsWeapon && IsWeaponBetter(item.GetTreeIndex(), bestItem)))
        {
            iBestIndex = i;
            bestItem = item.GetTreeIndex();
        }
    }
    return iBestIndex;
}

Bool CharacterParty::EquipItem(UInt uCharacterIndex, UInt uItemIndex, const IndexedString& sSlot)
{
    // Get the item and character
    CharacterPartyItem& item = GetItem(uItemIndex);
    CharacterPartyMember& member = GetMember(uCharacterIndex);

    // Check if the item can be equipped
    if(!item.DoesMatchSlot(sSlot))
    {
        return false;
    }
    if(!item.CanEquipAmount(1))
    {
        return false;
    }
    if(!member.CanAddEquippedItem(item.GetTreeIndex()))
    {
        return false;
    }

    // Mark the item as being equipped
    if(!member.AddEquippedItem(item.GetTreeIndex(), sSlot) || !item.EquipAmount(1))
    {
        return false;
    }
    return true;
}

Bool CharacterParty::UnequipItem(UInt uCharacterIndex, UInt uItemIndex, const IndexedString& sSlot)
{
    // Get the item and character
    CharacterPartyItem& item = GetItem(uItemIndex);
    CharacterPartyMember& member = GetMember(uCharacterIndex);

    // Check if the item can be unequipped
    if(!item.DoesMatchSlot(sSlot))
    {
        return false;
    }
    if(!item.CanUnequipAmount(1))
    {
        return false;
    }
    if(!member.CanRemoveEquippedItem(item.GetTreeIndex()))
    {
        return false;
    }

    // Mark the item as being equipped
    if(!member.RemoveEquippedItem(item.GetTreeIndex(), sSlot) || !item.UnequipAmount(1))
    {
        return false;
    }
    return true;
}

Bool CharacterParty::EquipBestItems(UInt uCharacterIndex)
{
    // First unequip all that character's items
    UnequipAllItems(uCharacterIndex);

    // Get the best available item for each equipment slot
    for(const IndexedString& sEquipType : CharacterEquipmentType::_names())
    {
        // Get best item for this slot
        Int iBestItemForSlot = GetBestUnequippedItemIndex(uCharacterIndex, sEquipType);
        if(iBestItemForSlot < 0)
        {
            continue;
        }

        // Try equipping
        if(!EquipItem(uCharacterIndex, iBestItemForSlot, sEquipType))
        {
            continue;
        }
    }
    return true;
}

Bool CharacterParty::EquipBestItemsForAllMembers()
{
    for(UInt i = 0; i < GetMembers().size(); i++)
    {
        EquipBestItems(i);
    }
    return true;
}

Bool CharacterParty::UnequipAllItems(UInt uCharacterIndex)
{
    // Get the member
    CharacterPartyMember& member = GetMember(uCharacterIndex);

    // Try unequipping all of the character's items
    Bool bAtLeastOneSuccess = false;
    for(auto&& equippedItem : member.GetEquippedItems())
    {
        Bool bSuccess = UnequipItem(
            uCharacterIndex,
            GetItemIndexByTreeIndex(equippedItem.GetTreeIndex()),
            equippedItem.GetItemSlot());
        bAtLeastOneSuccess = bAtLeastOneSuccess || bSuccess;
    }
    return bAtLeastOneSuccess;
}

Bool CharacterParty::UnequipAllItemsForAllMembers()
{
    for(UInt i = 0; i < GetMembers().size(); i++)
    {
        UnequipAllItems(i);
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
    sDescription += "Play Time: " + STDGetGameTime(GetPlayTime()) + "\n";
    sDescription += "Members: \n";
    for(auto& member: GetMembers())
    {
        sDescription += "\t" + member.GetCharacterID().Get() + "\n";
    }
    return sDescription;
#endif
}

void CharacterParty::ResetPlayTime()
{
    m_uCurrentPlayTime = 0;
    m_LastTimePoint = STDGetCurrentTimePoint();
    m_bPlayTimePaused = false;
}

void CharacterParty::PausePlayTime()
{
    if (m_bPlayTimePaused)
    {
        return;
    }
    STDTimePoint currentTimePoint = STDGetCurrentTimePoint();
    ULongLong uDuration = STDGetTimePointDuration(currentTimePoint - m_LastTimePoint).count();
    m_uCurrentPlayTime += uDuration;
    m_bPlayTimePaused = true;
}

void CharacterParty::ResumePlayTime()
{
    if (!m_bPlayTimePaused)
    {
        return;
    }
    m_LastTimePoint = STDGetCurrentTimePoint();
    m_bPlayTimePaused = false;
}

ULongLong CharacterParty::GetPlayTime() const
{
    if (m_bPlayTimePaused)
    {
        return m_uCurrentPlayTime;
    }
    else
    {
        STDTimePoint currentTimePoint = STDGetCurrentTimePoint();
        ULongLong uDuration = STDGetTimePointDuration(currentTimePoint - m_LastTimePoint).count();
        return (m_uCurrentPlayTime + uDuration);
    }
}

void CharacterParty::SetPlayTime(ULongLong uTime)
{
    m_uCurrentPlayTime = uTime;
}

void to_json(Json& jsonData, const CharacterParty& obj)
{
    // Party ID
    SET_JSON_DATA_IF_NOT_DEFAULT(PartyID, IndexedString(""));

    // Party type
    SET_JSON_DATA_IF_NOT_DEFAULT(PartyType, IndexedString("None"));

    // Array of members
    SET_JSON_DATA_IF_NOT_EMPTY(Members);

    // Array of items
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

    // Array of members
    obj.SetMembers(GET_JSON_DATA_OR_DEFAULT(Members, CharacterPartyMemberArray, CharacterPartyMemberArray()));

    // Array of items
    obj.SetItems(GET_JSON_DATA_OR_DEFAULT(Items, CharacterPartyItemArray, CharacterPartyItemArray()));

    // Arrays of available target types
    obj.SetAvailableTargetTypes(GET_JSON_DATA_OR_DEFAULT(AvailableTargetTypes, IndexedStringArray, IndexedStringArray()));

    // Array of taken target types
    obj.SetTakenTargetTypes(GET_JSON_DATA_OR_DEFAULT(TakenTargetTypes, IndexedStringArray, IndexedStringArray()));

    // Play time
    obj.SetPlayTime(GET_JSON_DATA_OR_DEFAULT(PlayTime, ULongLong, 0));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterParty, CharacterParty);

};
