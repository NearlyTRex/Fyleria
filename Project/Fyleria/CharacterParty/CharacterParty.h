// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_H_
#define _GECKO_CHARACTER_PARTY_H_

#include "Character/Character.h"
#include "CharacterParty/CharacterPartyMember.h"
#include "CharacterParty/CharacterPartyItem.h"
#include "Module/ModuleResultManager.h"

namespace Gecko
{

class CharacterParty
{
public:

    // Types
    typedef STDUnorderedMap<IndexedString, CharacterPartyMember, IndexedStringHasher> CharacterPartyMemberMapType;
    typedef STDUnorderedMap<IndexedString, CharacterPartyItem, IndexedStringHasher> CharacterPartyItemMapType;

    // Constructors
    CharacterParty();
    explicit CharacterParty(const Json& jsonData);
    explicit CharacterParty(const String& jsonString);

    // Regenerate character data
    void RegenerateCharacterData();

    // Determine if party is able to fight
    Bool IsPartyAbleToFight() const;
    MAKE_MODULE_RESULT_VARIANT(IsPartyAbleToFight);

    // Determine if party is full
    Bool IsPartyFull() const;
    MAKE_MODULE_RESULT_VARIANT(IsPartyFull);

    // Determine if member is present
    Bool IsMemberPresent(const IndexedString& sCharacterID) const;
    MAKE_MODULE_RESULT_VARIANT_A1(IsMemberPresent, const IndexedString&, sCharacterID);

    // Determine if target type is available
    Bool IsTargetTypeAvailable(const IndexedString& sCharacterTargetType) const;
    MAKE_MODULE_RESULT_VARIANT_A1(IsTargetTypeAvailable, const IndexedString&, sCharacterTargetType);

    // Determine if target type is taken
    Bool IsTargetTypeTaken(const IndexedString& sCharacterTargetType) const;
    MAKE_MODULE_RESULT_VARIANT_A1(IsTargetTypeTaken, const IndexedString&, sCharacterTargetType);

    // Add member
    Bool AddMember(const IndexedString& sCharacterID);
    MAKE_MODULE_RESULT_VARIANT_A1(AddMember, const IndexedString&, sCharacterID);

    // Remove member
    Bool RemoveMember(const IndexedString& sCharacterID);
    MAKE_MODULE_RESULT_VARIANT_A1(RemoveMember, const IndexedString&, sCharacterID);

    // Move member to the given target type
    Bool MoveMember(const IndexedString& sCharacterID, const IndexedString& sCharacterTargetType);
    MAKE_MODULE_RESULT_VARIANT_A2(MoveMember, const IndexedString&, sCharacterID, const IndexedString&, sCharacterTargetType);

    // Swap target types between members
    Bool SwapMembers(const IndexedString& sFirstCharacterID, const IndexedString& sSecondCharacterID);
    MAKE_MODULE_RESULT_VARIANT_A2(SwapMembers, const IndexedString&, sFirstCharacterID, const IndexedString&, sSecondCharacterID);

    // Get next available target type
    IndexedString GetNextAvailableTargetType() const;
    MAKE_MODULE_RESULT_VARIANT(GetNextAvailableTargetType);

    // Use target types
    Bool UseTargetType(const IndexedString& sCharacterTargetType);
    MAKE_MODULE_RESULT_VARIANT_A1(UseTargetType, const IndexedString&, sCharacterTargetType);

    // Free target type
    Bool FreeTargetType(const IndexedString& sCharacterTargetType);
    MAKE_MODULE_RESULT_VARIANT_A1(FreeTargetType, const IndexedString&, sCharacterTargetType);

    // Get member by ID
    const CharacterPartyMember& GetMemberByID(const IndexedString& sCharacterID) const;
    CharacterPartyMember& GetMemberByID(const IndexedString& sCharacterID);
    MAKE_MODULE_RESULT_VARIANT_A1(GetMemberByID, const IndexedString&, sCharacterID);

    // Get member by target type
    const CharacterPartyMember& GetMemberByTargetType(const IndexedString& sCharacterTargetType) const;
    CharacterPartyMember& GetMemberByTargetType(const IndexedString& sCharacterTargetType);
    MAKE_MODULE_RESULT_VARIANT_A1(GetMemberByTargetType, const IndexedString&, sCharacterTargetType);

    // Get member character IDs
    IndexedStringArray GetMemberCharacterIDs() const;
    MAKE_MODULE_RESULT_VARIANT(GetMemberCharacterIDs);

    // Get character IDs from target type
    Bool GetCharacterIDsFromTargetType(const IndexedString& sCharacterTargetType, IndexedStringArray& vCharacterIDs) const;
    MAKE_MODULE_RESULT_VARIANT_A2(GetCharacterIDsFromTargetType, const IndexedString&, sCharacterTargetType, IndexedStringArray&, vCharacterIDs);

    // Check member status
    UInt GetStatusMemberCount(const IndexedString& sStatus) const;
    MAKE_MODULE_RESULT_VARIANT_A1(GetStatusMemberCount, const IndexedString&, sStatus);

    // Add random items
    Bool AddRandomItems(const IndexedStringArray& vTreeTypes, Int iNumRandomItems, Int iAmountStart, Int iAmountEnd);
    MAKE_MODULE_RESULT_VARIANT_A4(AddRandomItems, const IndexedStringArray&, vTreeTypes, Int, iNumRandomItems, Int, iAmountStart, Int, iAmountEnd);

    // Add item by leaf
    Bool AddItemByLeaf(const IndexedString& sLeaf, UInt uAmount);
    MAKE_MODULE_RESULT_VARIANT_A2(AddItemByLeaf, const IndexedString&, sLeaf, UInt, uAmount);

    // Add item by tree index
    Bool AddItemByTreeIndex(const TreeIndex& treeIndex, UInt uAmount);
    MAKE_MODULE_RESULT_VARIANT_A2(AddItemByTreeIndex, const TreeIndex&, treeIndex, UInt, uAmount);

    // Remove item by leaf
    Bool RemoveItemByLeaf(const IndexedString& sLeaf, UInt uAmount);
    MAKE_MODULE_RESULT_VARIANT_A2(RemoveItemByLeaf, const IndexedString&, sLeaf, UInt, uAmount);

    // Remove item by tree index
    Bool RemoveItemByTreeIndex(const TreeIndex& treeIndex, UInt uAmount);
    MAKE_MODULE_RESULT_VARIANT_A2(RemoveItemByTreeIndex, const TreeIndex&, treeIndex, UInt, uAmount);

    // Get item by leaf
    const CharacterPartyItem& GetItemByLeaf(const IndexedString& sLeaf) const;
    CharacterPartyItem& GetItemByLeaf(const IndexedString& sLeaf);
    MAKE_MODULE_RESULT_VARIANT_A1(GetItemByLeaf, const IndexedString&, sLeaf);

    // Get item by tree index
    const CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& treeIndex) const;
    CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& treeIndex);
    MAKE_MODULE_RESULT_VARIANT_A1(GetItemByTreeIndex, const TreeIndex&, treeIndex);

    // Get best unequipped item for the given slot
    TreeIndex GetBestUnequippedItem(const IndexedString& sCharacterID, const IndexedString& sSlot) const;
    MAKE_MODULE_RESULT_VARIANT_A2(GetBestUnequippedItem, const IndexedString&, sCharacterID, const IndexedString&, sSlot);

    // Equip item
    Bool EquipItem(const IndexedString& sCharacterID, const IndexedString& sLeaf, const IndexedString& sSlot);
    MAKE_MODULE_RESULT_VARIANT_A3(EquipItem, const IndexedString&, sCharacterID, const IndexedString&, sLeaf, const IndexedString&, sSlot);

    // Unequip item
    Bool UnequipItem(const IndexedString& sCharacterID, const IndexedString& sLeaf, const IndexedString& sSlot);
    MAKE_MODULE_RESULT_VARIANT_A3(UnequipItem, const IndexedString&, sCharacterID, const IndexedString&, sLeaf, const IndexedString&, sSlot);

    // Equip best items for the given member
    Bool EquipBestItems(const IndexedString& sCharacterID);
    MAKE_MODULE_RESULT_VARIANT_A1(EquipBestItems, const IndexedString&, sCharacterID);

    // Equip best items for all members
    Bool EquipBestItemsForAllMembers();
    MAKE_MODULE_RESULT_VARIANT(EquipBestItemsForAllMembers);

    // Unequip all items for the given member
    Bool UnequipAllItems(const IndexedString& sCharacterID);
    MAKE_MODULE_RESULT_VARIANT_A1(UnequipAllItems, const IndexedString&, sCharacterID);

    // Unequip all items for all members
    Bool UnequipAllItemsForAllMembers();
    MAKE_MODULE_RESULT_VARIANT(UnequipAllItemsForAllMembers);

    // Get member count
    UInt GetMemberCount() const;
    MAKE_MODULE_RESULT_VARIANT(GetMemberCount);

    // Get item count
    UInt GetItemCount() const;
    MAKE_MODULE_RESULT_VARIANT(GetItemCount);

    // Get description
    String GetDescription() const;
    MAKE_MODULE_RESULT_VARIANT(GetDescription);

    // Reset play time
    void ResetPlayTime();

    // Pause play time
    void PausePlayTime();

    // Resume play time
    void ResumePlayTime();

    // Get play time
    ULongLong GetPlayTime() const;
    MAKE_MODULE_RESULT_VARIANT(GetPlayTime);

    // Set play time
    void SetPlayTime(ULongLong uTime);

    // Party ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PartyID, IndexedString);

    // Party type
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PartyType, IndexedString);

    // Map of members
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Members, CharacterPartyMemberMapType);

    // Map of items
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Items, CharacterPartyItemMapType);

    // Arrays of available target types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(AvailableTargetTypes, IndexedStringArray);

    // Array of taken target types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(TakenTargetTypes, IndexedStringArray);

    // Paused playtime
    MAKE_RAW_BASIC_TYPE_ACCESSORS(PlayTimePaused, Bool);

    // Current playtime
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CurrentPlayTime, ULongLong);

    // Last time point
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(LastTimePoint, STDTimePoint);
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterParty);

// JSON Converters
void to_json(Json& jsonData, const CharacterParty& obj);
void from_json(const Json& jsonData, CharacterParty& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterParty, CharacterParty);

};

#endif
