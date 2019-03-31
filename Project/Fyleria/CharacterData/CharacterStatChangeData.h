// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_STAT_CHANGE_DATA_H_
#define _GECKO_CHARACTER_STAT_CHANGE_DATA_H_

#include "Character/CharacterTypes.h"

namespace Gecko
{

class CharacterStatChangeData
{
public:

    // Types
    typedef STDUnorderedMap<IndexedString, ProlongedStatChange, IndexedStringHasher> ProlongedStatChangeMapType;

    // Constructors
    CharacterStatChangeData();
    ~CharacterStatChangeData();

    // Get tree actives/passives
    const TreeIndexList& GetPassiveChanges(const IndexedString& sTreeIndexType) const;
    const TreeIndexList& GetActiveChanges(const IndexedString& sTreeIndexType) const;
    const TreeIndexList& GetActionableChanges(const IndexedString& sTreeIndexType) const;

    // Add/remove prolonged stat changes
    void AddProlongedStatChange(const IndexedString& sKey, const ProlongedStatChange& change);
    Bool RemoveProlongedStatChange(const IndexedString& sKey);

    // Get prolonged stat change
    ProlongedStatChange& GetProlongedStatChange(const IndexedString& sKey);
    const ProlongedStatChange& GetProlongedStatChange(const IndexedString& sKey) const;

    // Get stat change entry lists from prolonged entries
    StatChangeEntryList GetProlongedStatChangeEntries() const;

    // Determine if prolonged stat change exists
    Bool DoesProlongedStatChangeExist(const IndexedString& sKey) const;

    // Determine if prolonged change has fully expired
    Bool HasProlongedStatChangeExpired(const IndexedString& sKey) const;

    // Remove all expired prolonged stat changes
    void RemoveAllExpiredProlongedStatChanges();

    // List of passive/active/actionable data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PassiveSkillDataList, TreeIndexList);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActiveSkillDataList, TreeIndexList);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActionableSkillDataList, TreeIndexList);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PassiveItemDataList, TreeIndexList);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActiveItemDataList, TreeIndexList);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActionableItemDataList, TreeIndexList);

    // Prolonged stat changes
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ProlongedStatChanges, ProlongedStatChangeMapType);

    // Comparisons
    Bool operator==(const CharacterStatChangeData& other) const;
    Bool operator!=(const CharacterStatChangeData& other) const;

private:

    // Empty change list
    static const TreeIndexList s_vEmptyChanges;

};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterStatChangeData);

// JSON Converters
void to_json(Json& jsonData, const CharacterStatChangeData& obj);
void from_json(const Json& jsonData, CharacterStatChangeData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterStatChangeData, CharacterStatChangeData);

};

#endif
