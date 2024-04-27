// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_PARTY_H_
#define _GECKO_CHARACTER_CHARACTER_PARTY_H_

// Internal includes
#include "Character/Character.h"
#include "CharacterParty/CharacterPartyMember.h"
#include "CharacterParty/CharacterPartyItem.h"

namespace Gecko
{

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
        Bool bUpdateEquipmentRatings = true,
        Bool bUpdateAvailableChanges = true,
        Bool bUpdateAvailableActions = true,
        Bool bUpdateAvailableAP = true
    );

    // Determine if party is able to fight
    Bool IsPartyAbleToFight() const;

    // Determine if party is full
    Bool IsPartyFull() const;

    // Determine if member is present
    Bool IsMemberPresent(const String& sCharacterID) const;

    // Determine if target type is available
    Bool IsTargetTypeAvailable(const String& sCharacterTargetType) const;

    // Determine if target type is taken
    Bool IsTargetTypeTaken(const String& sCharacterTargetType) const;

    // Add member
    Bool AddMember(const String& sCharacterID);

    // Remove member
    Bool RemoveMember(const String& sCharacterID);

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
    UInt GetStatusMemberCount(const String& sStatus) const;

    // Add random items
    Bool AddRandomItems(const StringArray& vTreeTypes, Int iNumRandomItems, Int iAmountStart, Int iAmountEnd);

    // Add item by leaf
    Bool AddItemByLeaf(const String& sLeaf, UInt uAmount);

    // Add item by tree index
    Bool AddItemByTreeIndex(const TreeIndex& treeIndex, UInt uAmount);

    // Remove item by leaf
    Bool RemoveItemByLeaf(const String& sLeaf, UInt uAmount);

    // Remove item by tree index
    Bool RemoveItemByTreeIndex(const TreeIndex& treeIndex, UInt uAmount);

    // Get item by leaf
    const CharacterPartyItem& GetItemByLeaf(const String& sLeaf) const;
    CharacterPartyItem& GetItemByLeaf(const String& sLeaf);

    // Get item by tree index
    const CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& treeIndex) const;
    CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& treeIndex);

    // Get best unequipped item for the given slot
    TreeIndex GetBestUnequippedItem(const String& sCharacterID, const String& sSlot) const;

    // Equip item
    Bool EquipItem(const String& sCharacterID, const String& sLeaf, const String& sSlot);

    // Unequip item
    Bool UnequipItem(const String& sCharacterID, const String& sLeaf, const String& sSlot);

    // Equip best items for the given member
    Bool EquipBestItems(const String& sCharacterID);

    // Equip best items for all members
    Bool EquipBestItemsForAllMembers();

    // Unequip all items for the given member
    Bool UnequipAllItems(const String& sCharacterID);

    // Unequip all items for all members
    Bool UnequipAllItemsForAllMembers();

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
