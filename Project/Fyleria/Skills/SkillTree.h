// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_SKILL_TREE_H_
#define _GECKO_SKILL_TREE_H_

#include "CharacterAction/CharacterAction.h"
#include "Module/ModuleResultManager.h"
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
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesSkillDataAffinityExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesSkillDataAlchemyExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesSkillDataBreakdownExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesSkillDataCombatExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesSkillDataCraftingExist, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(DoesSkillDataWeaponExist, const TreeIndex&, treeIndex);

    // Retrieve skill data
    static const SkillDataAffinity& RetrieveSkillDataAffinity(const TreeIndex& treeIndex);
    static const SkillDataAlchemy& RetrieveSkillDataAlchemy(const TreeIndex& treeIndex);
    static const SkillDataBreakdown& RetrieveSkillDataBreakdown(const TreeIndex& treeIndex);
    static const SkillDataCombat& RetrieveSkillDataCombat(const TreeIndex& treeIndex);
    static const SkillDataCrafting& RetrieveSkillDataCrafting(const TreeIndex& treeIndex);
    static const SkillDataWeapon& RetrieveSkillDataWeapon(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveSkillDataAffinity, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveSkillDataAlchemy, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveSkillDataBreakdown, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveSkillDataCombat, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveSkillDataCrafting, const TreeIndex&, treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(RetrieveSkillDataWeapon, const TreeIndex&, treeIndex);

    // Get all skills
    static TreeIndexArray GetAllAffinitySkills();
    static TreeIndexArray GetAllAlchemySkills();
    static TreeIndexArray GetAllBreakdownSkills();
    static TreeIndexArray GetAllCombatSkills();
    static TreeIndexArray GetAllCraftingSkills();
    static TreeIndexArray GetAllWeaponSkills();
    static MAKE_MODULE_RESULT_VARIANT(GetAllAffinitySkills);
    static MAKE_MODULE_RESULT_VARIANT(GetAllAlchemySkills);
    static MAKE_MODULE_RESULT_VARIANT(GetAllBreakdownSkills);
    static MAKE_MODULE_RESULT_VARIANT(GetAllCombatSkills);
    static MAKE_MODULE_RESULT_VARIANT(GetAllCraftingSkills);
    static MAKE_MODULE_RESULT_VARIANT(GetAllWeaponSkills);

    // Get matching skills
    static TreeIndexArray GetAffinitySkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetAlchemySkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetBreakdownSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetCombatSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetCraftingSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
    static TreeIndexArray GetWeaponSkills(const IndexedString& sCharID, Bool bUniqueOnly = false);
    static MAKE_MODULE_RESULT_VARIANT_A2(GetAffinitySkills, const IndexedString&, sCharID, Bool, bUniqueOnly);
    static MAKE_MODULE_RESULT_VARIANT_A2(GetAlchemySkills, const IndexedString&, sCharID, Bool, bUniqueOnly);
    static MAKE_MODULE_RESULT_VARIANT_A2(GetBreakdownSkills, const IndexedString&, sCharID, Bool, bUniqueOnly);
    static MAKE_MODULE_RESULT_VARIANT_A2(GetCombatSkills, const IndexedString&, sCharID, Bool, bUniqueOnly);
    static MAKE_MODULE_RESULT_VARIANT_A2(GetCraftingSkills, const IndexedString&, sCharID, Bool, bUniqueOnly);
    static MAKE_MODULE_RESULT_VARIANT_A2(GetWeaponSkills, const IndexedString&, sCharID, Bool, bUniqueOnly);

    // Get skill type
    static IndexedString GetSkillType(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(GetSkillType, const TreeIndex&, treeIndex);

    // Determine if base weapon skill
    static Bool IsBaseWeaponSkill(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(IsBaseWeaponSkill, const TreeIndex&, treeIndex);

    // Determine if skill is actionable
    static Bool IsSkillActionable(const TreeIndex& treeIndex);
    static MAKE_MODULE_RESULT_VARIANT_A1(IsSkillActionable, const TreeIndex&, treeIndex);

    // Generate character actions
    static Bool GenerateSkillCharacterActions(const TreeIndex& treeIndex,
        const IndexedString& sCharacterID,
        const IndexedString& sWeaponSet,
        CharacterActionArray& vActions);

    // Get stat changes
    static void FillSkillStatChangeArrays(const IndexedString& sCharID,
        TreeIndexArray& vPassives,
        TreeIndexArray& vActives,
        TreeIndexArray& vActionables,
        Bool bUniqueOnly = false);
};

};

#endif
