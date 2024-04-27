// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SKILL_SKILL_MANAGER_H_
#define _GECKO_SKILL_SKILL_MANAGER_H_

// Internal includes
#include "CharacterAction/CharacterAction.h"
#include "Skill/SkillDataAffinity.h"
#include "Skill/SkillDataAlchemy.h"
#include "Skill/SkillDataBreakdown.h"
#include "Skill/SkillDataCombat.h"
#include "Skill/SkillDataCrafting.h"
#include "Skill/SkillDataWeapon.h"
#include "Utility/Tree.h"

namespace Gecko
{

// Typedefs
typedef Tree<SkillDataAffinity> SkillTreeAffinity;
typedef Tree<SkillDataAlchemy> SkillTreeAlchemy;
typedef Tree<SkillDataBreakdown> SkillTreeBreakdown;
typedef Tree<SkillDataCombat> SkillTreeCombat;
typedef Tree<SkillDataCrafting> SkillTreeCrafting;
typedef Tree<SkillDataWeapon> SkillTreeWeapon;

// Skill manager
class SkillManager
{
public:

    // Constructors
    SkillManager();

    // Load/unload skill trees into memory
    void LoadSkillTreesIntoMemory();
    void UnloadSkillTreesFromMemory();

    // Determine if skill data exists
    Bool DoesSkillDataAffinityExist(const TreeIndex& treeIndex) const;
    Bool DoesSkillDataAlchemyExist(const TreeIndex& treeIndex) const;
    Bool DoesSkillDataBreakdownExist(const TreeIndex& treeIndex) const;
    Bool DoesSkillDataCombatExist(const TreeIndex& treeIndex) const;
    Bool DoesSkillDataCraftingExist(const TreeIndex& treeIndex) const;
    Bool DoesSkillDataWeaponExist(const TreeIndex& treeIndex) const;

    // Retrieve skill data
    const SkillDataAffinity& RetrieveSkillDataAffinity(const TreeIndex& treeIndex) const;
    const SkillDataAlchemy& RetrieveSkillDataAlchemy(const TreeIndex& treeIndex) const;
    const SkillDataBreakdown& RetrieveSkillDataBreakdown(const TreeIndex& treeIndex) const;
    const SkillDataCombat& RetrieveSkillDataCombat(const TreeIndex& treeIndex) const;
    const SkillDataCrafting& RetrieveSkillDataCrafting(const TreeIndex& treeIndex) const;
    const SkillDataWeapon& RetrieveSkillDataWeapon(const TreeIndex& treeIndex) const;

    // Get all skills
    TreeIndexArray GetAllAffinitySkills() const;
    TreeIndexArray GetAllAlchemySkills() const;
    TreeIndexArray GetAllBreakdownSkills() const;
    TreeIndexArray GetAllCombatSkills() const;
    TreeIndexArray GetAllCraftingSkills() const;
    TreeIndexArray GetAllWeaponSkills() const;

    // Get matching skills
    TreeIndexArray GetAffinitySkills(const String& sCharID, Bool bUniqueOnly = false) const;
    TreeIndexArray GetAlchemySkills(const String& sCharID, Bool bUniqueOnly = false) const;
    TreeIndexArray GetBreakdownSkills(const String& sCharID, Bool bUniqueOnly = false) const;
    TreeIndexArray GetCombatSkills(const String& sCharID, Bool bUniqueOnly = false) const;
    TreeIndexArray GetCraftingSkills(const String& sCharID, Bool bUniqueOnly = false) const;
    TreeIndexArray GetWeaponSkills(const String& sCharID, Bool bUniqueOnly = false) const;

    // Get skill type
    String GetSkillType(const TreeIndex& treeIndex) const;

    // Determine if base weapon skill
    Bool IsBaseWeaponSkill(const TreeIndex& treeIndex) const;

    // Determine if skill is actionable
    Bool IsSkillActionable(const TreeIndex& treeIndex) const;

    // Generate character actions
    Bool GenerateSkillCharacterActions(
        const TreeIndex& treeIndex,
        const String& sCharacterID,
        const String& sWeaponSet,
        CharacterActionArray& vActions) const;

    // Get stat changes
    void FillSkillStatChangeArrays(
        const String& sCharID,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables,
        Bool bUniqueOnly = false) const;

    // Skill trees
    MAKE_RAW_TYPE_ACCESSORS(SkillTreeAffinity, SkillTreeAffinity);
    MAKE_RAW_TYPE_ACCESSORS(SkillTreeAlchemy, SkillTreeAlchemy);
    MAKE_RAW_TYPE_ACCESSORS(SkillTreeBreakdown, SkillTreeBreakdown);
    MAKE_RAW_TYPE_ACCESSORS(SkillTreeCombat, SkillTreeCombat);
    MAKE_RAW_TYPE_ACCESSORS(SkillTreeCrafting, SkillTreeCrafting);
    MAKE_RAW_TYPE_ACCESSORS(SkillTreeWeapon, SkillTreeWeapon);
};

};

#endif
