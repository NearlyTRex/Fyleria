// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_STAT_CHANGE_DATA_H_
#define _GECKO_CHARACTER_STAT_CHANGE_DATA_H_

#include "Character/CharacterTypes.h"
#include "Stats/ProlongedStatChange.h"
#include "Utility/TreeIndex.h"

namespace Gecko
{

class CharacterStatChangeData
{
public:

    // Types
    typedef STDUnorderedMap<IndexedString, ProlongedStatChange, IndexedStringHasher> ProlongedStatChangeMapType;

    // Constructors
    CharacterStatChangeData();
    CharacterStatChangeData(const Json& jsonData);

    // Clear all data
    void Clear();

    // Get tree actives/passives
    const TreeIndexArray& GetPassiveChanges(const IndexedString& sTreeIndexType) const;
    const TreeIndexArray& GetActiveChanges(const IndexedString& sTreeIndexType) const;
    const TreeIndexArray& GetActionableChanges(const IndexedString& sTreeIndexType) const;

    // Add/remove prolonged stat changes
    void AddProlongedStatChange(const IndexedString& sKey, const ProlongedStatChange& change);
    Bool RemoveProlongedStatChange(const IndexedString& sKey);

    // Get prolonged stat change
    ProlongedStatChange& GetProlongedStatChange(const IndexedString& sKey);
    const ProlongedStatChange& GetProlongedStatChange(const IndexedString& sKey) const;

    // Get stat change entry lists from prolonged entries
    StatChangeEntryArray GetProlongedStatChangeEntries(Int iRound, Int iAttack, Int iDefend) const;

    // Determine if prolonged stat change exists
    Bool DoesProlongedStatChangeExist(const IndexedString& sKey) const;

    // Determine if prolonged change has fully expired
    Bool HasProlongedStatChangeExpired(const IndexedString& sKey, Int iRound, Int iAttack, Int iDefend) const;

    // Remove all expired prolonged stat changes
    void RemoveAllExpiredProlongedStatChanges(Int iRound, Int iAttack, Int iDefend);

    // Passive data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PassiveSkillDataArray, TreeIndexArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PassiveItemDataArray, TreeIndexArray);

    // Active data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActiveSkillDataArray, TreeIndexArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActiveItemDataArray, TreeIndexArray);

    // Actionable data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActionableSkillDataArray, TreeIndexArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActionableItemDataArray, TreeIndexArray);

    // Prolonged stat changes
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ProlongedStatChanges, ProlongedStatChangeMapType);

    // Comparisons
    Bool operator==(const CharacterStatChangeData& other) const;
    Bool operator!=(const CharacterStatChangeData& other) const;

};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterStatChangeData);

// JSON Converters
void to_json(Json& jsonData, const CharacterStatChangeData& obj);
void from_json(const Json& jsonData, CharacterStatChangeData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterStatChangeData, CharacterStatChangeData);

};

#endif
