// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SKILL_TREE_H_
#define _GECKO_SKILL_TREE_H_

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

class SkillTree
{
public:

    // Load/unload skill trees into memory
    static void LoadSkillTreesIntoMemory();
    static void UnloadSkillTreesFromMemory();

    // Verify
    static void VerifySkillTrees();

    // Determine if skill data exists
    static Bool DoesSkillDataAffinityExist(const TreeIndex& treeIndex);
    static Bool DoesSkillDataAlchemyExist(const TreeIndex& treeIndex);
    static Bool DoesSkillDataBreakdownExist(const TreeIndex& treeIndex);
    static Bool DoesSkillDataCombatExist(const TreeIndex& treeIndex);
    static Bool DoesSkillDataCraftingExist(const TreeIndex& treeIndex);
    static Bool DoesSkillDataWeaponExist(const TreeIndex& treeIndex);

    // Retrieve skill data
    static const SkillDataAffinity& RetrieveSkillDataAffinity(const TreeIndex& treeIndex);
    static const SkillDataAlchemy& RetrieveSkillDataAlchemy(const TreeIndex& treeIndex);
    static const SkillDataBreakdown& RetrieveSkillDataBreakdown(const TreeIndex& treeIndex);
    static const SkillDataCombat& RetrieveSkillDataCombat(const TreeIndex& treeIndex);
    static const SkillDataCrafting& RetrieveSkillDataCrafting(const TreeIndex& treeIndex);
    static const SkillDataWeapon& RetrieveSkillDataWeapon(const TreeIndex& treeIndex);

    // Get all skills
    static TreeIndexArray GetAllAffinitySkills();
    static TreeIndexArray GetAllAlchemySkills();
    static TreeIndexArray GetAllBreakdownSkills();
    static TreeIndexArray GetAllCombatSkills();
    static TreeIndexArray GetAllCraftingSkills();
    static TreeIndexArray GetAllWeaponSkills();

    // Get matching skills
    static TreeIndexArray GetAffinitySkills(const String& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetAlchemySkills(const String& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetBreakdownSkills(const String& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetCombatSkills(const String& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetCraftingSkills(const String& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetWeaponSkills(const String& sCharID, Bool bUniqueOnly = false);

    // Get skill type
    static String GetSkillType(const TreeIndex& treeIndex);

    // Determine if base weapon skill
    static Bool IsBaseWeaponSkill(const TreeIndex& treeIndex);

    // Determine if skill is actionable
    static Bool IsSkillActionable(const TreeIndex& treeIndex);

    // Generate character actions
    static Bool GenerateSkillCharacterActions(const TreeIndex& treeIndex,
        const String& sCharacterID,
        const String& sWeaponSet,
        CharacterActionArray& vActions);

    // Get stat changes
    static void FillSkillStatChangeArrays(const String& sCharID,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables,
        Bool bUniqueOnly = false);
};

};

#endif
