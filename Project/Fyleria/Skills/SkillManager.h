// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SKILL_MANAGER_H_
#define _GECKO_SKILL_MANAGER_H_

// Internal includes
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

class SkillManager
{
public:

    // Constructors
    SkillManager();

    // Load/unload skill trees into memory
    void LoadSkillTreesIntoMemory();
    void UnloadSkillTreesFromMemory();

    // Determine if skill data exists
    Bool DoesSkillDataAffinityExist(const TreeIndex& treeIndex);
    Bool DoesSkillDataAlchemyExist(const TreeIndex& treeIndex);
    Bool DoesSkillDataBreakdownExist(const TreeIndex& treeIndex);
    Bool DoesSkillDataCombatExist(const TreeIndex& treeIndex);
    Bool DoesSkillDataCraftingExist(const TreeIndex& treeIndex);
    Bool DoesSkillDataWeaponExist(const TreeIndex& treeIndex);

    // Retrieve skill data
    const SkillDataAffinity& RetrieveSkillDataAffinity(const TreeIndex& treeIndex);
    const SkillDataAlchemy& RetrieveSkillDataAlchemy(const TreeIndex& treeIndex);
    const SkillDataBreakdown& RetrieveSkillDataBreakdown(const TreeIndex& treeIndex);
    const SkillDataCombat& RetrieveSkillDataCombat(const TreeIndex& treeIndex);
    const SkillDataCrafting& RetrieveSkillDataCrafting(const TreeIndex& treeIndex);
    const SkillDataWeapon& RetrieveSkillDataWeapon(const TreeIndex& treeIndex);

    // Get all skills
    TreeIndexArray GetAllAffinitySkills();
    TreeIndexArray GetAllAlchemySkills();
    TreeIndexArray GetAllBreakdownSkills();
    TreeIndexArray GetAllCombatSkills();
    TreeIndexArray GetAllCraftingSkills();
    TreeIndexArray GetAllWeaponSkills();

    // Get matching skills
    TreeIndexArray GetAffinitySkills(const String& sCharID, Bool bUniqueOnly = false);
    TreeIndexArray GetAlchemySkills(const String& sCharID, Bool bUniqueOnly = false);
    TreeIndexArray GetBreakdownSkills(const String& sCharID, Bool bUniqueOnly = false);
    TreeIndexArray GetCombatSkills(const String& sCharID, Bool bUniqueOnly = false);
    TreeIndexArray GetCraftingSkills(const String& sCharID, Bool bUniqueOnly = false);
    TreeIndexArray GetWeaponSkills(const String& sCharID, Bool bUniqueOnly = false);

    // Get skill type
    String GetSkillType(const TreeIndex& treeIndex);

    // Determine if base weapon skill
    Bool IsBaseWeaponSkill(const TreeIndex& treeIndex);

    // Determine if skill is actionable
    Bool IsSkillActionable(const TreeIndex& treeIndex);

    // Generate character actions
    Bool GenerateSkillCharacterActions(const TreeIndex& treeIndex,
        const String& sCharacterID,
        const String& sWeaponSet,
        CharacterActionArray& vActions);

    // Get stat changes
    void FillSkillStatChangeArrays(const String& sCharID,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables,
        Bool bUniqueOnly = false);

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
