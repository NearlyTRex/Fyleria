// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_SKILLDATA_H_
#define _GECKO_SKILLDATA_H_

#include "CharacterAction/CharacterAction.h"
#include "Stats/StatChange.h"
#include "Utility/IndexedString.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

class SkillData
{
public:

    // Constructors
    SkillData();
    SkillData(const Json& jsonData);

    // Clear all data
    virtual void Clear();

    // Is actionable
    Bool IsActionable() const;

    // Get number of attack/defend requirements
    void GetNumberOfAttackAndDefendRequirements(Int& iAttacks, Int& iDefends) const;

    // Determine if this has only attack requirements
    Bool DoesHaveOnlyAttackRequirements() const;

    // Determine if this has only defend requirements
    Bool DoesHaveOnlyDefendRequirements() const;

    // Get intersecting attack requirements
    Bool GetIntersectingRequirementTypes(
        const IndexedStringArray& vPrimaryActionTypes,
        const IndexedStringArray& vSecondaryActionTypes,
        IndexedStringArray& vPrimaryAttackIntersections,
        IndexedStringArray& vPrimaryDefendIntersections,
        IndexedStringArray& vSecondaryAttackIntersections,
        IndexedStringArray& vSecondaryDefendIntersections) const;

    // Does meet action requirements
    Bool DoesMeetActionRequirements(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const;

    // Create base character action
    CharacterActionArray CreateBaseActions(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const;

    // Run types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RunTypes, IndexedStringArray);

    // Data class
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(DataClass, IndexedString);

    // Skill rank
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SkillRank, UByte);

    // Skill name
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillName, IndexedString);

    // Skill description
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillDescription, IndexedString);

    // Skill type
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillType, IndexedString);

    // Skill costs
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SkillCostAP, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SkillCostHP, UByte);

    // Skill index
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillTreeIndex, TreeIndex);

    // Stat changes
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(StatChanges, StatChangeArray);
};

// Typedef
MAKE_TYPE_TYPEDEFS(SkillData);

// JSON Converters
void to_json(Json& jsonData, const SkillData& obj);
void from_json(const Json& jsonData, SkillData& obj);

};

#endif
