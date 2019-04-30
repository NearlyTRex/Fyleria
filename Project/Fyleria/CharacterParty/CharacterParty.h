// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_H_
#define _GECKO_CHARACTER_PARTY_H_

#include "Character/Character.h"
#include "CharacterParty/CharacterPartyMember.h"
#include "CharacterParty/CharacterPartyItem.h"

namespace Gecko
{

class CharacterParty
{
public:

    // Constructors
    CharacterParty();

    // Regenerate character data
    void RegenerateCharacterData();

    // Determine if party is full
    Bool IsPartyFull() const;

    // Determine if member is present
    Bool IsMemberPresent(const IndexedString& sCharacterID) const;

    // Determine if target type is available/taken
    Bool IsTargetTypeAvailable(const IndexedString& sCharacterTargetType) const;
    Bool IsTargetTypeTaken(const IndexedString& sCharacterTargetType) const;

    // Add member
    Bool AddMember(const IndexedString& sCharacterID);

    // Remove member
    Bool RemoveMember(const IndexedString& sCharacterID);

    // Move/swap members
    Bool MoveMember(const IndexedString& sCharacterID, const IndexedString& sCharacterTargetType);
    Bool SwapMembers(const IndexedString& sFirstCharacterID, const IndexedString& sSecondCharacterID);

    // Get next available target type
    IndexedString GetNextAvailableTargetType() const;

    // Use/free target types
    Bool UseTargetType(const IndexedString& sCharacterTargetType);
    Bool FreeTargetType(const IndexedString& sCharacterTargetType);

    // Get member
    Int GetMemberIndexByID(const IndexedString& sCharacterID) const;
    Int GetMemberIndexByTargetType(const IndexedString& sCharacterTargetType) const;
    const CharacterPartyMember& GetMember(UInt uIndex) const;
    const CharacterPartyMember& GetMemberByID(const IndexedString& sCharacterID) const;
    const CharacterPartyMember& GetMemberByTargetType(const IndexedString& sCharacterTargetType) const;
    CharacterPartyMember& GetMember(UInt uIndex);
    CharacterPartyMember& GetMemberByID(const IndexedString& sCharacterID);
    CharacterPartyMember& GetMemberByTargetType(const IndexedString& sCharacterTargetType);

    // Get character IDs
    Bool GetCharacterIDsFromTargetType(const IndexedString& sCharacterTargetType, IndexedStringArray& vCharacterIDs) const;

    // Check member status
    UInt GetStatusMemberCount(const IndexedString& sStatus) const;

    // Add random items
    Bool AddRandomItems(const IndexedStringArray& vTreeTypes, Int iNumRandomItems, Int iAmountStart, Int iAmountEnd);

    // Add item
    Bool AddItemByLeaf(const IndexedString& sLeaf, UInt uAmount);
    Bool AddItemByIndex(const TreeIndex& index, UInt uAmount);

    // Remove item
    Bool RemoveItem(const TreeIndex& index, UInt uAmount);

    // Get item
    Int GetItemIndexByTreeIndex(const TreeIndex& index) const;
    const CharacterPartyItem& GetItem(UInt uIndex) const;
    const CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& index) const;
    CharacterPartyItem& GetItem(UInt uIndex);
    CharacterPartyItem& GetItemByTreeIndex(const TreeIndex& index);

    // Get best unequipped item for the given slot
    Int GetBestUnequippedItemIndex(UInt uCharacterIndex, const IndexedString& sSlot) const;

    // Equip item
    Bool EquipItem(UInt uCharacterIndex, UInt uItemIndex, const IndexedString& sSlot);

    // Unequip item
    Bool UnequipItem(UInt uCharacterIndex, UInt uItemIndex, const IndexedString& sSlot);

    // Equip best items
    Bool EquipBestItems(UInt uCharacterIndex);
    Bool EquipBestItemsForAllMembers();

    // Unequip all items
    Bool UnequipAllItems(UInt uCharacterIndex);
    Bool UnequipAllItemsForAllMembers();

    // Get member count
    UInt GetMemberCount() const;

    // Get item count
    UInt GetItemCount() const;

    // Get description
    String GetDescription() const;

    // Manage playtime
    void ResetPlayTime();
    void PausePlayTime();
    void ResumePlayTime();
    ULongLong GetPlayTime() const;
    void SetPlayTime(ULongLong uTime);

    // Party ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PartyID, IndexedString);

    // Party type
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PartyType, IndexedString);

    // Array of members
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Members, CharacterPartyMemberArray);

    // Array of items
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Items, CharacterPartyItemArray);

    // Arrays of available target types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(AvailableTargetTypes, IndexedStringArray);

    // Array of taken target types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(TakenTargetTypes, IndexedStringArray);

private:

    // Paused playtime
    Bool m_bPlayTimePaused;

    // Current playtime
    ULongLong m_uCurrentPlayTime;

    // Last time point
    STDTimePoint m_LastTimePoint;

};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterParty);

// JSON Converters
void to_json(Json& jsonData, const CharacterParty& obj);
void from_json(const Json& jsonData, CharacterParty& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterParty, CharacterParty);

};

#endif
