// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_H_
#define _GECKO_CHARACTER_PARTY_H_

// Internal includes
#include "Character/Character.h"
#include "CharacterParty/CharacterPartyMember.h"
#include "CharacterParty/CharacterPartyItem.h"

namespace Gecko
{

// Manager set
class ManagerSet;

// Character party
class CharacterParty
{
public:

    // Types
    typedef STDUnorderedMap<String, CharacterPartyMember> CharacterPartyMemberMapType;
    typedef STDUnorderedMap<String, CharacterPartyItem> CharacterPartyItemMapType;

    // Constructors
    CharacterParty();
    CharacterParty(const Json& jsonData);
    CharacterParty(const String& jsonString);

    // Regenerate character data
    void RegenerateCharacterData(
        SafeObject<ManagerSet>& pManagerSet,
        Bool bUpdateEquipmentRatings = true,
        Bool bUpdateAvailableChanges = true,
        Bool bUpdateAvailableActions = true,
        Bool bUpdateAvailableAP = true
    );

    // Determine if party is able to fight
    Bool IsPartyAbleToFight(SafeObject<ManagerSet>& pManagerSet) const;

    // Determine if party is full
    Bool IsPartyFull() const;

    // Determine if member is present
    Bool IsMemberPresent(const String& sCharacterID) const;

    // Determine if target type is available
    Bool IsTargetTypeAvailable(const String& sCharacterTargetType) const;

    // Determine if target type is taken
    Bool IsTargetTypeTaken(const String& sCharacterTargetType) const;

    // Add member
    Bool AddMember(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);

    // Remove member
    Bool RemoveMember(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);

    // Move member to the given target type
    Bool MoveMember(const String& sCharacterID, const String& sCharacterTargetType);

    // Swap target types between members
    Bool SwapMembers(const String& sFirstCharacterID, const String& sSecondCharacterID);

    // Get next available target type
    String GetNextAvailableTargetType() const;

    // Use target types
    Bool UseTargetType(const String& sCharacterTargetType);

    // Free target type
    Bool FreeTargetType(const String& sCharacterTargetType);

    // Get member by ID
    const CharacterPartyMember& GetMemberByID(const String& sCharacterID) const;
    CharacterPartyMember& GetMemberByID(const String& sCharacterID);

    // Get member by target type
    const CharacterPartyMember& GetMemberByTargetType(const String& sCharacterTargetType) const;
    CharacterPartyMember& GetMemberByTargetType(const String& sCharacterTargetType);

    // Get member character IDs
    StringArray GetMemberCharacterIDs() const;

    // Get character IDs from target type
    Bool GetCharacterIDsFromTargetType(const String& sCharacterTargetType, StringArray& vCharacterIDs) const;

    // Check member status
    UInt GetStatusMemberCount(SafeObject<ManagerSet>& pManagerSet, const String& sStatus) const;

    // Add random items
    Bool AddRandomItems(SafeObject<ManagerSet>& pManagerSet, const StringArray& vTreeTypes, Int iNumRandomItems, Int iAmountStart, Int iAmountEnd);

    // Add item by leaf
    Bool AddItemByLeaf(SafeObject<ManagerSet>& pManagerSet, const String& sLeaf, UInt uAmount);

    // Add item by tree index
    Bool AddItemByTreeIndex(SafeObject<ManagerSet>& pManagerSet, const TreeIndex& treeIndex, UInt uAmount);

    // Remove item by leaf
    Bool RemoveItemByLeaf(SafeObject<ManagerSet>& pManagerSet, const String& sLeaf, UInt uAmount);

    // Remove item by tree index
    Bool RemoveItemByTreeIndex(SafeObject<ManagerSet>& pManagerSet, const TreeIndex& treeIndex, UInt uAmount);

    // Get item by leaf
    const CharacterPartyItem& GetItemByLeaf(const String& sLeaf) const;
    CharacterPartyItem& GetItemByLeaf(const String& sLeaf);

    // Get item by tree index
    const CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& treeIndex) const;
    CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& treeIndex);

    // Get best unequipped item for the given slot
    TreeIndex GetBestUnequippedItem(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const String& sSlot) const;

    // Equip item
    Bool EquipItem(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const String& sLeaf, const String& sSlot);

    // Unequip item
    Bool UnequipItem(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const String& sLeaf, const String& sSlot);

    // Equip best items for the given member
    Bool EquipBestItems(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);

    // Equip best items for all members
    Bool EquipBestItemsForAllMembers(SafeObject<ManagerSet>& pManagerSet);

    // Unequip all items for the given member
    Bool UnequipAllItems(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);

    // Unequip all items for all members
    Bool UnequipAllItemsForAllMembers(SafeObject<ManagerSet>& pManagerSet);

    // Get member count
    UInt GetMemberCount() const;

    // Get item count
    UInt GetItemCount() const;

    // Get description
    String GetDescription() const;

    // Reset play time
    void ResetPlayTime();

    // Pause play time
    void PausePlayTime();

    // Resume play time
    void ResumePlayTime();

    // Get play time
    ULongLong GetPlayTime() const;

    // Set play time
    void SetPlayTime(ULongLong uTime);

    // Party ID
    MAKE_RAW_TYPE_ACCESSORS(PartyID, String);

    // Party type
    MAKE_RAW_TYPE_ACCESSORS(PartyType, String);

    // Map of members
    MAKE_RAW_TYPE_ACCESSORS(Members, CharacterPartyMemberMapType);

    // Map of items
    MAKE_RAW_TYPE_ACCESSORS(Items, CharacterPartyItemMapType);

    // Arrays of available target types
    MAKE_RAW_TYPE_ACCESSORS(AvailableTargetTypes, StringArray);

    // Array of taken target types
    MAKE_RAW_TYPE_ACCESSORS(TakenTargetTypes, StringArray);

    // Paused playtime
    MAKE_RAW_TYPE_ACCESSORS(PlayTimePaused, Bool);

    // Current playtime
    MAKE_RAW_TYPE_ACCESSORS(CurrentPlayTime, ULongLong);

    // Last time point
    MAKE_RAW_TYPE_ACCESSORS(LastTimePoint, STDTimePoint);
};

// Typedef
MAKE_COMMON_TYPEDEFS(CharacterParty);

// JSON Converters
void to_json(Json& jsonData, const CharacterParty& obj);
void from_json(const Json& jsonData, CharacterParty& obj);

};

#endif
