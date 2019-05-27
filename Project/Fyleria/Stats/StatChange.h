// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_STAT_CHANGE_H_
#define _GECKO_STAT_CHANGE_H_

#include "CharacterAction/CharacterAction.h"
#include "Stats/StatChangeEntry.h"
#include "Utility/Macros.h"
#include "Utility/Tree.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/Serializable.h"

namespace Gecko
{

// Class for stat changes
class StatChange
{
public:

    // Constructors
    StatChange();
    StatChange(const Json& jsonData);

    // Clear all data
    void Clear();

    // ID
    static ULongLong GenerateNewID();

    // Determine if change is passive, active, etc
    // Passive means that there are no requirements on costs/time/equipment, chances to run, or actions
    Bool IsActive() const;
    Bool IsPassive() const;
    Bool DoesHaveActiveRequirements() const;

    // Determine if change has specific requirements
    Bool DoesHaveItemEquippedRequirements() const;
    Bool DoesHaveItemUsedRequirements() const;
    Bool DoesHaveAttackRequirements() const;
    Bool DoesHaveDefendRequirements() const;

    // Determine if change meets specific requirements
    Bool DoesMeetItemEquippedRequirements(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const;
    Bool DoesMeetItemUsedRequirements(const IndexedStringArray& vActionItemTypes) const;
    Bool DoesMeetAttackRequirements(const IndexedStringArray& vActionTypes) const;
    Bool DoesMeetAttackRequirements(const IndexedStringArray& vActionTypes, const IndexedStringArray& vPreviousActionTypes) const;
    Bool DoesMeetDefendRequirements(const IndexedStringArray& vActionTypes) const;
    Bool DoesMeetDefendRequirements(const IndexedStringArray& vActionTypes, const IndexedStringArray& vPreviousActionTypes) const;
    Bool DoesMeetActiveRequirements(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const;
    Bool DoesMeetActiveRequirements(const IndexedString& sCharacterID, const IndexedString& sCharacterTargetType, const IndexedString& sWeaponSet, const CharacterAction& action) const;

    // Get intersecting requirements
    IndexedStringArray GetIntersectingAttackRequirements(const IndexedStringArray& vActionTypes) const;
    IndexedStringArray GetIntersectingDefendRequirements(const IndexedStringArray& vActionTypes) const;

    // Get resolved characters
    Bool GetResolvedCharacterArrays(IndexedStringArray& vSourceCharIDs, IndexedStringArray& vDestCharIDs) const;

    // Resolve target placeholders
    void ResolveTargetPlaceholders(const IndexedString& sCharacterID, const IndexedString& sSegment);

    // ID
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ID, ULongLong);

    // Relevant skill data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillTreeIndex, TreeIndex);

    // Relevant item data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemTreeIndex, TreeIndex);

    // Percent chance to apply this change
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ChanceToApply, Float);

    // Amount of rounds to apply this change (0 is indefinite)
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RoundAmount, UByte);

    // Amount of attacks to apply this change (0 is indefinite)
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AttackAmount, UByte);

    // Amount of defends to apply this change (0 is indefinite)
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DefendAmount, UByte);

    // Required items or attack types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredItemEquippedTypesOR, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredItemEquippedTypesAND, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredItemUsedTypesOR, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredItemUsedTypesAND, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredAttackTypesOR, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredAttackTypesAND, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredDefendTypesOR, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredDefendTypesAND, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredPreviousAttackTypesOR, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredPreviousAttackTypesAND, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredPreviousDefendTypesOR, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredPreviousDefendTypesAND, IndexedStringArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredEquippedWeaponCount, UByte);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RequiredEquippedShieldCount, UByte);

    // Whether destination target is the same as the source target
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DestinationIsSource, Bool);

    // Source and destination targets
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SourceTargetType, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(DestinationTargetType, IndexedString);

    // Stat change list
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(StatChangeEntries, StatChangeEntryArray);

    // Comparisons
    Bool operator==(const StatChange& other) const;
    Bool operator<(const StatChange& other) const;
};

// Typedefs
MAKE_TYPE_TYPEDEFS(StatChange);

// JSON Converters
void to_json(Json& jsonData, const StatChange& obj);
void from_json(const Json& jsonData, StatChange& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(StatChange, StatChange);

// Get stat changes from the given tree nodes
const StatChangeArray& GetStatChangesFromTreeIndex(const IndexedString& sTreeIndexType, const TreeIndex& treeIndex);
const StatChangeArray& GetStatChangesFromSkillTreeIndex(const TreeIndex& treeIndex);
const StatChangeArray& GetStatChangesFromItemTreeIndex(const TreeIndex& treeIndex);

};

#endif
