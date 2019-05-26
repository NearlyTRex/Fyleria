// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterParty/CharacterParty.h"
#include "CharacterParty/CharacterPartyItem.h"
#include "CharacterParty/CharacterPartyEquippedItem.h"
#include "CharacterParty/CharacterPartyMember.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Utility/Macros.h"
#include "Utility/Python.h"

namespace Gecko
{

SafePtr<CharacterPartyManager>& GetCharacterPartyManager() { return CharacterPartyManager::GetInstance(); }

};

PYBIND11_MAKE_OPAQUE(Gecko::CharacterPartyItemArray);
PYBIND11_MAKE_OPAQUE(Gecko::CharacterPartyArray);

PYBIND11_EMBEDDED_MODULE(GeckoCharacterParty, m)
{
    // CharacterParty.h
    PyBindClass<Gecko::CharacterParty>(m, "CharacterParty")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(RegenerateCharacterData, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsPartyFull, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsMemberPresent, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsTargetTypeAvailable, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsTargetTypeTaken, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddMember, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveMember, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(MoveMember, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(SwapMembers, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetNextAvailableTargetType, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UseTargetType, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(FreeTargetType, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetMemberByID, Gecko::CharacterParty, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetMemberByID, Gecko::CharacterParty, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetMemberByTargetType, Gecko::CharacterParty, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetMemberByTargetType, Gecko::CharacterParty, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_SIMPLE(GetMemberCharacterIDs, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetCharacterIDsFromTargetType, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetStatusMemberCount, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddRandomItems, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddItemByLeaf, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddItemByTreeIndex, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveItemByLeaf, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveItemByTreeIndex, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetItemByLeaf, Gecko::CharacterParty, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetItemByLeaf, Gecko::CharacterParty, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetItemByTreeIndex, Gecko::CharacterParty, PyBindReturnCopy, const Gecko::TreeIndex&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetItemByTreeIndex, Gecko::CharacterParty, PyBindReturnRefInternal, const Gecko::TreeIndex&)
        WRAPPING_ADD_METHOD_SIMPLE(GetBestUnequippedItem, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(EquipItem, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UnequipItem, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(EquipBestItems, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(EquipBestItemsForAllMembers, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UnequipAllItems, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UnequipAllItemsForAllMembers, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetMemberCount, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetItemCount, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetDescription, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(ResetPlayTime, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(PausePlayTime, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(ResumePlayTime, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetPlayTime, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(SetPlayTime, Gecko::CharacterParty)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(PartyID, Gecko::CharacterParty)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(PartyType, Gecko::CharacterParty)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(Members, Gecko::CharacterParty)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(Items, Gecko::CharacterParty)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(AvailableTargetTypes, Gecko::CharacterParty)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(TakenTargetTypes, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsPartyFull_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsMemberPresent_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsTargetTypeAvailable_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(IsTargetTypeTaken_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddMember_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveMember_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(MoveMember_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(SwapMembers_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetNextAvailableTargetType_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UseTargetType_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(FreeTargetType_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetMemberByID_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetMemberByTargetType_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetMemberCharacterIDs_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetCharacterIDsFromTargetType_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetStatusMemberCount_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddRandomItems_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddItemByLeaf_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(AddItemByTreeIndex_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveItemByLeaf_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveItemByTreeIndex_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetItemByLeaf_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetItemByTreeIndex_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetBestUnequippedItem_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(EquipItem_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UnequipItem_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(EquipBestItems_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(EquipBestItemsForAllMembers_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UnequipAllItems_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(UnequipAllItemsForAllMembers_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetMemberCount_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetItemCount_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetDescription_MR, Gecko::CharacterParty)
        WRAPPING_ADD_METHOD_SIMPLE(GetPlayTime_MR, Gecko::CharacterParty)
    ;
    PyBindVector<Gecko::CharacterPartyArray>(m, "CharacterPartyArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyArrayFromJsonString, Gecko);

    // CharacterPartyItem.h
    PyBindClass<Gecko::CharacterPartyItem>(m, "CharacterPartyItem")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(DoesMatchSlot, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(CanAddAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(CanRemoveAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(CanEquipAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(CanUnequipAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(AddAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(EquipAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_METHOD_SIMPLE(UnequipAmount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(TreeIndex, Gecko::CharacterPartyItem)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Amount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EquipCount, Gecko::CharacterPartyItem)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ApplicableEquipmentSlots, Gecko::CharacterPartyItem)
    ;
    PyBindVector<Gecko::CharacterPartyItemArray>(m, "CharacterPartyItemArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyItemToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyItemArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyItemFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyItemArrayFromJsonString, Gecko);

    // CharacterPartyEquippedItem.h
    PyBindClass<Gecko::CharacterPartyEquippedItem>(m, "CharacterPartyEquippedItem")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(TreeIndex, Gecko::CharacterPartyEquippedItem)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ItemSlot, Gecko::CharacterPartyEquippedItem)
    ;
    PyBindVector<Gecko::CharacterPartyEquippedItemArray>(m, "CharacterPartyEquippedItemArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyEquippedItemToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyEquippedItemArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyEquippedItemFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyEquippedItemArrayFromJsonString, Gecko);

    // CharacterPartyMember.h
    PyBindClass<Gecko::CharacterPartyMember>(m, "CharacterPartyMember")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(GetEquippedItemTypeCount, Gecko::CharacterPartyMember)
        WRAPPING_ADD_METHOD_SIMPLE(GetEquippedWeaponCount, Gecko::CharacterPartyMember)
        WRAPPING_ADD_METHOD_SIMPLE(GetEquippedShieldCount, Gecko::CharacterPartyMember)
        WRAPPING_ADD_METHOD_SIMPLE(CanAddEquippedItem, Gecko::CharacterPartyMember)
        WRAPPING_ADD_METHOD_SIMPLE(CanRemoveEquippedItem, Gecko::CharacterPartyMember)
        WRAPPING_ADD_METHOD_SIMPLE(AddEquippedItem, Gecko::CharacterPartyMember)
        WRAPPING_ADD_METHOD_SIMPLE(RemoveEquippedItem, Gecko::CharacterPartyMember)
        WRAPPING_ADD_METHOD_SIMPLE(GetHandInfoByWeaponSet, Gecko::CharacterPartyMember)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(EquippedItems, Gecko::CharacterPartyMember)
    ;
    PyBindVector<Gecko::CharacterPartyMemberArray>(m, "CharacterPartyMemberArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyMemberToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterPartyMemberArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyMemberFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyMemberArrayFromJsonString, Gecko);

    // CharacterPartyManager.h
    PyBindClass<Gecko::CharacterPartyManager>(m, "CharacterPartyManager")
        WRAPPING_ADD_METHOD_SIMPLE(LoadParty, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(LoadPartyFromFile, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(SavePartyToFile, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(CreateParty, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(UnloadParty, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(DoesPartyExist, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsValidPartyID, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetPartyByID, Gecko::CharacterPartyManager, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetPartyByID, Gecko::CharacterPartyManager, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetPartyByType, Gecko::CharacterPartyManager, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetPartyByType, Gecko::CharacterPartyManager, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetCurrentAllyParty, Gecko::CharacterPartyManager, PyBindReturnCopy, )
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetCurrentAllyParty, Gecko::CharacterPartyManager, PyBindReturnRefInternal, )
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetCurrentEnemyParty, Gecko::CharacterPartyManager, PyBindReturnCopy, )
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetCurrentEnemyParty, Gecko::CharacterPartyManager, PyBindReturnRefInternal, )
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(CurrentAllyPartyID, Gecko::CharacterPartyManager)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(CurrentEnemyPartyID, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(DoesPartyExist_MR, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsValidPartyID_MR, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetPartyByID_MR, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetPartyByType_MR, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetCurrentAllyParty_MR, Gecko::CharacterPartyManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetCurrentEnemyParty_MR, Gecko::CharacterPartyManager)
    ;

    // Local
    WRAPPING_STANDALONE_METHOD_POLICY(GetCharacterPartyManager, Gecko, PyBindReturnCopy);
}
