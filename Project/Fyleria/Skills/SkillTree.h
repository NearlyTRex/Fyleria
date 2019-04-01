// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_SKILL_TREE_H_
#define _GECKO_SKILL_TREE_H_

#include "CharacterAction/CharacterAction.h"
#include "Skills/SkillDataAffinity.h"
#include "Skills/SkillDataAlchemy.h"
#include "Skills/SkillDataBreakdown.h"
#include "Skills/SkillDataCombat.h"
#include "Skills/SkillDataCrafting.h"
#include "Skills/SkillDataWeapon.h"
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

// Load/unload skill trees into memory
void LoadSkillTreesIntoMemory();
void UnloadSkillTreesFromMemory();

// Verify
void VerifySkillTrees();

// Retrieve appropriate skill data
Bool DoesSkillDataAffinityExist(const TreeIndex& index);
Bool DoesSkillDataAlchemyExist(const TreeIndex& index);
Bool DoesSkillDataBreakdownExist(const TreeIndex& index);
Bool DoesSkillDataCombatExist(const TreeIndex& index);
Bool DoesSkillDataCraftingExist(const TreeIndex& index);
Bool DoesSkillDataWeaponExist(const TreeIndex& index);
const SkillDataAffinity& RetrieveSkillDataAffinity(const TreeIndex& index);
const SkillDataAlchemy& RetrieveSkillDataAlchemy(const TreeIndex& index);
const SkillDataBreakdown& RetrieveSkillDataBreakdown(const TreeIndex& index);
const SkillDataCombat& RetrieveSkillDataCombat(const TreeIndex& index);
const SkillDataCrafting& RetrieveSkillDataCrafting(const TreeIndex& index);
const SkillDataWeapon& RetrieveSkillDataWeapon(const TreeIndex& index);

// Get skill lists
TreeIndexArray GetAllAffinitySkills();
TreeIndexArray GetAllAlchemySkills();
TreeIndexArray GetAllBreakdownSkills();
TreeIndexArray GetAllCombatSkills();
TreeIndexArray GetAllCraftingSkills();
TreeIndexArray GetAllWeaponSkills();
TreeIndexArray GetAffinitySkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
TreeIndexArray GetAlchemySkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
TreeIndexArray GetBreakdownSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
TreeIndexArray GetCombatSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
TreeIndexArray GetCraftingSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
TreeIndexArray GetWeaponSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);

// Get skill type
IndexedString GetSkillType(const TreeIndex& index);

// Determine if base weapon skill
Bool IsBaseWeaponSkill(const TreeIndex& index);

// Determine if skill is actionable
Bool IsSkillActionable(const TreeIndex& index);

// Generate character actions
Bool GenerateSkillCharacterActions(const TreeIndex& index,
    const IndexedString& sCharacterID,
    const IndexedString& sWeaponSet,
    CharacterActionArray& vActions);

// Get stat changes
void FillSkillStatChangeArrays(const IndexedString& sCharID,
    TreeIndexArray& vPassives,
    TreeIndexArray& vActives,
    TreeIndexArray& vActionables,
    Bool bUniqueOnly = false);

};

#endif
