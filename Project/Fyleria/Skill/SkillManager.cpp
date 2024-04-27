// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Skill/SkillManager.h"
#include "Skill/SkillConstants.h"
#include "Character/Character.h"
#include "Stat/StatChange.h"
#include "Utility/FantasyName.h"
#include "Utility/Json.h"
#include "Application/Application.h"

namespace Gecko
{

SkillManager::SkillManager()
{
}

template <class T>
void PostProcessSkills(T& tree, const TreeIndexArray& vTreeIndices)
{
    for(auto& treeIndex : vTreeIndices)
    {
        auto& skillData = tree.GetLeaf(treeIndex);
        skillData.SetSkillTreeIndex(treeIndex);
        for(auto& statChange : skillData.GetStatChanges())
        {
            statChange.SetSkillTreeIndex(treeIndex);
        }
    }
}

void SkillManager::LoadSkillTreesIntoMemory()
{
    // Skills location
    String sLocation = GetManagers()->GetFileManager()->GetDataTreesSkillsDirectory();

    // Create file loader
    auto fnFileLoader = [&](const String& sBranchFile, const String& sFileRoot) -> Json
    {
        // Log loading of JSON data
        LOG_FORMAT_STATEMENT("Loading skill file '{}'", sBranchFile.c_str());

        // Read json data
        Json jsonData;
        if(!ReadJsonFile(sBranchFile, jsonData, sFileRoot))
        {
            THROW_RUNTIME_ERROR("Could not load data from '" + sBranchFile + "'");
        }
        return jsonData;
    };

    // Affinity
    GetSkillTreeAffinity().AddBranch("Blood", fnFileLoader(SKILL_FILE_AFFINITY_BLOOD, sLocation));
    GetSkillTreeAffinity().AddBranch("Dark", fnFileLoader(SKILL_FILE_AFFINITY_DARK, sLocation));
    GetSkillTreeAffinity().AddBranch("Earth", fnFileLoader(SKILL_FILE_AFFINITY_EARTH, sLocation));
    GetSkillTreeAffinity().AddBranch("Fire", fnFileLoader(SKILL_FILE_AFFINITY_FIRE, sLocation));
    GetSkillTreeAffinity().AddBranch("Flesh", fnFileLoader(SKILL_FILE_AFFINITY_FLESH, sLocation));
    GetSkillTreeAffinity().AddBranch("Force", fnFileLoader(SKILL_FILE_AFFINITY_FORCE, sLocation));
    GetSkillTreeAffinity().AddBranch("Holy", fnFileLoader(SKILL_FILE_AFFINITY_HOLY, sLocation));
    GetSkillTreeAffinity().AddBranch("Ice", fnFileLoader(SKILL_FILE_AFFINITY_ICE, sLocation));
    GetSkillTreeAffinity().AddBranch("Light", fnFileLoader(SKILL_FILE_AFFINITY_LIGHT, sLocation));
    GetSkillTreeAffinity().AddBranch("Mind", fnFileLoader(SKILL_FILE_AFFINITY_MIND, sLocation));
    GetSkillTreeAffinity().AddBranch("Shock", fnFileLoader(SKILL_FILE_AFFINITY_SHOCK, sLocation));
    GetSkillTreeAffinity().AddBranch("Wind", fnFileLoader(SKILL_FILE_AFFINITY_WIND, sLocation));

    // Alchemy
    GetSkillTreeAlchemy().AddBranch("Alchemist", fnFileLoader(SKILL_FILE_ALCHEMY_ALCHEMIST, sLocation));
    GetSkillTreeAlchemy().AddBranch("Chemist", fnFileLoader(SKILL_FILE_ALCHEMY_CHEMIST, sLocation));
    GetSkillTreeAlchemy().AddBranch("Energist", fnFileLoader(SKILL_FILE_ALCHEMY_ENERGIST, sLocation));
    GetSkillTreeAlchemy().AddBranch("Healer", fnFileLoader(SKILL_FILE_ALCHEMY_HEALER, sLocation));

    // Breakdown
    GetSkillTreeBreakdown().AddBranch("Bowbane", fnFileLoader(SKILL_FILE_BREAKDOWN_BOWBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("Goldbane", fnFileLoader(SKILL_FILE_BREAKDOWN_GOLDBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("Hammerbane", fnFileLoader(SKILL_FILE_BREAKDOWN_HAMMERBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("Platebane", fnFileLoader(SKILL_FILE_BREAKDOWN_PLATEBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("Scalebane", fnFileLoader(SKILL_FILE_BREAKDOWN_SCALEBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("Shieldbane", fnFileLoader(SKILL_FILE_BREAKDOWN_SHIELDBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("Spellbane", fnFileLoader(SKILL_FILE_BREAKDOWN_SPELLBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("StudRemover", fnFileLoader(SKILL_FILE_BREAKDOWN_STUDREMOVER, sLocation));
    GetSkillTreeBreakdown().AddBranch("Swordbane", fnFileLoader(SKILL_FILE_BREAKDOWN_SWORDBANE, sLocation));
    GetSkillTreeBreakdown().AddBranch("Threadbare", fnFileLoader(SKILL_FILE_BREAKDOWN_THREADBARE, sLocation));

    // Combat
    GetSkillTreeCombat().AddBranch("Ambidextrous", fnFileLoader(SKILL_FILE_COMBAT_AMBIDEXTROUS, sLocation));
    GetSkillTreeCombat().AddBranch("Avatar", fnFileLoader(SKILL_FILE_COMBAT_AVATAR, sLocation));
    GetSkillTreeCombat().AddBranch("Barbarian", fnFileLoader(SKILL_FILE_COMBAT_BARBARIAN, sLocation));
    GetSkillTreeCombat().AddBranch("Blademaster", fnFileLoader(SKILL_FILE_COMBAT_BLADEMASTER, sLocation));
    GetSkillTreeCombat().AddBranch("Focused", fnFileLoader(SKILL_FILE_COMBAT_FOCUSED, sLocation));
    GetSkillTreeCombat().AddBranch("Mage", fnFileLoader(SKILL_FILE_COMBAT_MAGE, sLocation));
    GetSkillTreeCombat().AddBranch("Rogue", fnFileLoader(SKILL_FILE_COMBAT_ROGUE, sLocation));
    GetSkillTreeCombat().AddBranch("Stalwart", fnFileLoader(SKILL_FILE_COMBAT_STALWART, sLocation));

    // Crafting
    GetSkillTreeCrafting().AddBranch("Bowsmith", fnFileLoader(SKILL_FILE_CRAFTING_BOWSMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Goldsmith", fnFileLoader(SKILL_FILE_CRAFTING_GOLDSMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Hammersmith", fnFileLoader(SKILL_FILE_CRAFTING_HAMMERSMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Platesmith", fnFileLoader(SKILL_FILE_CRAFTING_PLATESMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Scalesmith", fnFileLoader(SKILL_FILE_CRAFTING_SCALESMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Shieldsmith", fnFileLoader(SKILL_FILE_CRAFTING_SHIELDSMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Spellsmith", fnFileLoader(SKILL_FILE_CRAFTING_SPELLSMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Swordsmith", fnFileLoader(SKILL_FILE_CRAFTING_SWORDSMITH, sLocation));
    GetSkillTreeCrafting().AddBranch("Tanner", fnFileLoader(SKILL_FILE_CRAFTING_TANNER, sLocation));
    GetSkillTreeCrafting().AddBranch("Weaver", fnFileLoader(SKILL_FILE_CRAFTING_WEAVER, sLocation));

    // Weapon
    GetSkillTreeWeapon().AddBranch("Bash", fnFileLoader(SKILL_FILE_WEAPON_BASH, sLocation));
    GetSkillTreeWeapon().AddBranch("Block", fnFileLoader(SKILL_FILE_WEAPON_BLOCK, sLocation));
    GetSkillTreeWeapon().AddBranch("Break", fnFileLoader(SKILL_FILE_WEAPON_BREAK, sLocation));
    GetSkillTreeWeapon().AddBranch("Cleave", fnFileLoader(SKILL_FILE_WEAPON_CLEAVE, sLocation));
    GetSkillTreeWeapon().AddBranch("Counter", fnFileLoader(SKILL_FILE_WEAPON_COUNTER, sLocation));
    GetSkillTreeWeapon().AddBranch("Crack", fnFileLoader(SKILL_FILE_WEAPON_CRACK, sLocation));
    GetSkillTreeWeapon().AddBranch("CriticalShot", fnFileLoader(SKILL_FILE_WEAPON_CRITICALSHOT, sLocation));
    GetSkillTreeWeapon().AddBranch("Crush", fnFileLoader(SKILL_FILE_WEAPON_CRUSH, sLocation));
    GetSkillTreeWeapon().AddBranch("Decapitate", fnFileLoader(SKILL_FILE_WEAPON_DECAPITATE, sLocation));
    GetSkillTreeWeapon().AddBranch("Dodge", fnFileLoader(SKILL_FILE_WEAPON_DODGE, sLocation));
    GetSkillTreeWeapon().AddBranch("Drill", fnFileLoader(SKILL_FILE_WEAPON_DRILL, sLocation));
    GetSkillTreeWeapon().AddBranch("Impact", fnFileLoader(SKILL_FILE_WEAPON_IMPACT, sLocation));
    GetSkillTreeWeapon().AddBranch("Impale", fnFileLoader(SKILL_FILE_WEAPON_IMPALE, sLocation));
    GetSkillTreeWeapon().AddBranch("Parry", fnFileLoader(SKILL_FILE_WEAPON_PARRY, sLocation));
    GetSkillTreeWeapon().AddBranch("Pierce", fnFileLoader(SKILL_FILE_WEAPON_PIERCE, sLocation));
    GetSkillTreeWeapon().AddBranch("Riposte", fnFileLoader(SKILL_FILE_WEAPON_RIPOSTE, sLocation));
    GetSkillTreeWeapon().AddBranch("Rush", fnFileLoader(SKILL_FILE_WEAPON_RUSH, sLocation));
    GetSkillTreeWeapon().AddBranch("Sever", fnFileLoader(SKILL_FILE_WEAPON_SEVER, sLocation));
    GetSkillTreeWeapon().AddBranch("Shoot", fnFileLoader(SKILL_FILE_WEAPON_SHOOT, sLocation));
    GetSkillTreeWeapon().AddBranch("Slash", fnFileLoader(SKILL_FILE_WEAPON_SLASH, sLocation));
    GetSkillTreeWeapon().AddBranch("Slice", fnFileLoader(SKILL_FILE_WEAPON_SLICE, sLocation));
    GetSkillTreeWeapon().AddBranch("Slit", fnFileLoader(SKILL_FILE_WEAPON_SLIT, sLocation));
    GetSkillTreeWeapon().AddBranch("Smash", fnFileLoader(SKILL_FILE_WEAPON_SMASH, sLocation));
    GetSkillTreeWeapon().AddBranch("StealthStrike", fnFileLoader(SKILL_FILE_WEAPON_STEALTHSTRIKE, sLocation));

    // Post process skill data
    PostProcessSkills<SkillTreeAffinity>(GetSkillTreeAffinity(), GetAllAffinitySkills());
    PostProcessSkills<SkillTreeAlchemy>(GetSkillTreeAlchemy(), GetAllAlchemySkills());
    PostProcessSkills<SkillTreeBreakdown>(GetSkillTreeBreakdown(), GetAllBreakdownSkills());
    PostProcessSkills<SkillTreeCombat>(GetSkillTreeCombat(), GetAllCombatSkills());
    PostProcessSkills<SkillTreeCrafting>(GetSkillTreeCrafting(), GetAllCraftingSkills());
    PostProcessSkills<SkillTreeWeapon>(GetSkillTreeWeapon(), GetAllWeaponSkills());
}

void SkillManager::UnloadSkillTreesFromMemory()
{
    // Clear all skill data
    GetSkillTreeAffinity().ClearAllData();
    GetSkillTreeAlchemy().ClearAllData();
    GetSkillTreeBreakdown().ClearAllData();
    GetSkillTreeCombat().ClearAllData();
    GetSkillTreeCrafting().ClearAllData();
    GetSkillTreeWeapon().ClearAllData();
}

Bool SkillManager::DoesSkillDataAffinityExist(const TreeIndex& treeIndex) const
{
    return GetSkillTreeAffinity().HasLeaf(treeIndex);
}

Bool SkillManager::DoesSkillDataAlchemyExist(const TreeIndex& treeIndex) const
{
    return GetSkillTreeAlchemy().HasLeaf(treeIndex);
}

Bool SkillManager::DoesSkillDataBreakdownExist(const TreeIndex& treeIndex) const
{
    return GetSkillTreeBreakdown().HasLeaf(treeIndex);
}

Bool SkillManager::DoesSkillDataCombatExist(const TreeIndex& treeIndex) const
{
    return GetSkillTreeCombat().HasLeaf(treeIndex);
}

Bool SkillManager::DoesSkillDataCraftingExist(const TreeIndex& treeIndex) const
{
    return GetSkillTreeCrafting().HasLeaf(treeIndex);
}

Bool SkillManager::DoesSkillDataWeaponExist(const TreeIndex& treeIndex) const
{
    return GetSkillTreeWeapon().HasLeaf(treeIndex);
}

const SkillDataAffinity& SkillManager::RetrieveSkillDataAffinity(const TreeIndex& treeIndex) const
{
    return GetSkillTreeAffinity().GetLeaf(treeIndex);
}

const SkillDataAlchemy& SkillManager::RetrieveSkillDataAlchemy(const TreeIndex& treeIndex) const
{
    return GetSkillTreeAlchemy().GetLeaf(treeIndex);
}

const SkillDataBreakdown& SkillManager::RetrieveSkillDataBreakdown(const TreeIndex& treeIndex) const
{
    return GetSkillTreeBreakdown().GetLeaf(treeIndex);
}

const SkillDataCombat& SkillManager::RetrieveSkillDataCombat(const TreeIndex& treeIndex) const
{
    return GetSkillTreeCombat().GetLeaf(treeIndex);
}

const SkillDataCrafting& SkillManager::RetrieveSkillDataCrafting(const TreeIndex& treeIndex) const
{
    return GetSkillTreeCrafting().GetLeaf(treeIndex);
}

const SkillDataWeapon& SkillManager::RetrieveSkillDataWeapon(const TreeIndex& treeIndex) const
{
    return GetSkillTreeWeapon().GetLeaf(treeIndex);
}

template <class T>
void AddAllSkillLeaves(const T& tree, const String& sBranchName, TreeIndexArray& vLeaves)
{
    auto vNewLeaves = tree.GetAllLeaves(sBranchName);
    vLeaves.insert(vLeaves.end(), vNewLeaves.begin(), vNewLeaves.end());
}

template <class T>
void AddSkillLeavesProgress(const T& tree, const String& sBranchName, const Character& character, TreeIndexArray& vLeaves, Bool bUniqueOnly)
{
    String sRankBase("Rank");
    Int iLeafNumber = character.GetSkillData().GetSkillRankValue(sBranchName);
    auto vNewLeaves = tree.GetLeavesUnderNumber(sBranchName, sRankBase, iLeafNumber, bUniqueOnly);
    vLeaves.insert(vLeaves.end(), vNewLeaves.begin(), vNewLeaves.end());
}

TreeIndexArray SkillManager::GetAllAffinitySkills() const
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Holy", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Fire", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Ice", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Shock", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Dark", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Light", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Force", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Mind", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Earth", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Blood", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Flesh", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>(GetSkillTreeAffinity(), "Wind", vFinal);
    return vFinal;
}

TreeIndexArray SkillManager::GetAllAlchemySkills() const
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Alchemist", vFinal);
    AddAllSkillLeaves<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Chemist", vFinal);
    AddAllSkillLeaves<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Energist", vFinal);
    AddAllSkillLeaves<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Healer", vFinal);
    return vFinal;
}

TreeIndexArray SkillManager::GetAllBreakdownSkills() const
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Bowbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Goldbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Hammerbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Platebane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Scalebane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Shieldbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Spellbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "StudRemover", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Swordbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Threadbare", vFinal);
    return vFinal;
}

TreeIndexArray SkillManager::GetAllCombatSkills() const
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Ambidextrous", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Avatar", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Barbarian", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Blademaster", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Focused", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Mage", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Rogue", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>(GetSkillTreeCombat(), "Stalwart", vFinal);
    return vFinal;
}

TreeIndexArray SkillManager::GetAllCraftingSkills() const
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Bowsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Goldsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Hammersmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Platesmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Scalesmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Shieldsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Spellsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Swordsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Tanner", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>(GetSkillTreeCrafting(), "Weaver", vFinal);
    return vFinal;
}

TreeIndexArray SkillManager::GetAllWeaponSkills() const
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Bash", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Block", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Break", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Cleave", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Counter", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Crack", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "CriticalShot", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Crush", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Decapitate", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Dodge", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Drill", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Impact", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Impale", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Parry", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Pierce", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Riposte", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Rush", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Sever", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Shoot", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Slash", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Slice", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Slit", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "Smash", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>(GetSkillTreeWeapon(), "StealthStrike", vFinal);
    return vFinal;
}

TreeIndexArray SkillManager::GetAffinitySkills(
    const String& sCharID,
    Bool bUniqueOnly /*= false*/) const
{
    // Get skills
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Holy", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Fire", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Ice", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Shock", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Dark", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Light", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Force", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Mind", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Earth", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Blood", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Flesh", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>(GetSkillTreeAffinity(), "Wind", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillManager::GetAlchemySkills(
    const String& sCharID,
    Bool bUniqueOnly /*= false*/) const
{
    // Get skills
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Alchemist", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Chemist", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Energist", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAlchemy>(GetSkillTreeAlchemy(), "Healer", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillManager::GetBreakdownSkills(
    const String& sCharID,
    Bool bUniqueOnly /*= false*/) const
{
    // Get skills
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Bowbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Goldbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Hammerbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Platebane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Scalebane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Shieldbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Spellbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "StudRemover", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Swordbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>(GetSkillTreeBreakdown(), "Threadbare", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillManager::GetCombatSkills(
    const String& sCharID,
    Bool bUniqueOnly /*= false*/) const
{
    // Get skills
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Ambidextrous", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Avatar", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Barbarian", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Blademaster", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Focused", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Mage", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Rogue", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>(GetSkillTreeCombat(), "Stalwart", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillManager::GetCraftingSkills(
    const String& sCharID,
    Bool bUniqueOnly /*= false*/) const
{
    // Get skills
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Bowsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Goldsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Hammersmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Platesmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Scalesmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Shieldsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Spellsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Swordsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Tanner", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>(GetSkillTreeCrafting(), "Weaver", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillManager::GetWeaponSkills(
    const String& sCharID,
    Bool bUniqueOnly /*= false*/) const
{
    // Get skills
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Bash", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Block", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Break", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Cleave", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Counter", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Crack", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "CriticalShot", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Crush", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Decapitate", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Dodge", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Drill", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Impact", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Impale", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Parry", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Pierce", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Riposte", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Rush", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Sever", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Shoot", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Slash", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Slice", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Slit", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "Smash", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>(GetSkillTreeWeapon(), "StealthStrike", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

String SkillManager::GetSkillType(const TreeIndex& treeIndex) const
{
    if(DoesSkillDataAffinityExist(treeIndex))
    {
        return RetrieveSkillDataAffinity(treeIndex).GetSkillType();
    }
    else if(DoesSkillDataAlchemyExist(treeIndex))
    {
        return RetrieveSkillDataAlchemy(treeIndex).GetSkillType();
    }
    else if(DoesSkillDataBreakdownExist(treeIndex))
    {
        return RetrieveSkillDataBreakdown(treeIndex).GetSkillType();
    }
    else if(DoesSkillDataCombatExist(treeIndex))
    {
        return RetrieveSkillDataCombat(treeIndex).GetSkillType();
    }
    else if(DoesSkillDataCraftingExist(treeIndex))
    {
        return RetrieveSkillDataCrafting(treeIndex).GetSkillType();
    }
    else if(DoesSkillDataWeaponExist(treeIndex))
    {
        return RetrieveSkillDataWeapon(treeIndex).GetSkillType();
    }
    return GetNoneTypeForEnum<SkillTreeType>();
}

Bool SkillManager::IsBaseWeaponSkill(const TreeIndex& treeIndex) const
{
    if(DoesSkillDataWeaponExist(treeIndex))
    {
        const SkillDataWeapon& skillData = RetrieveSkillDataWeapon(treeIndex);
        return (
            skillData.GetSkillCostAP() == 0 &&
            skillData.GetActionPoints() == 0 &&
            !skillData.GetWeaponBaseType().empty() &&
            !IsNoneTypeForEnum<SkillWeaponBaseType>(skillData.GetWeaponBaseType())
        );
    }
    return false;
}

Bool SkillManager::IsSkillActionable(const TreeIndex& treeIndex) const
{
    if(DoesSkillDataCombatExist(treeIndex))
    {
        return RetrieveSkillDataCombat(treeIndex).IsActionable();
    }
    else if(DoesSkillDataWeaponExist(treeIndex))
    {
        return RetrieveSkillDataWeapon(treeIndex).IsActionable();
    }
    return false;
}

Bool SkillManager::GenerateSkillCharacterActions(
    const TreeIndex& treeIndex,
    const String& sCharacterID,
    const String& sWeaponSet,
    CharacterActionArray& vActions) const
{
    if(DoesSkillDataCombatExist(treeIndex))
    {
        const SkillDataCombat& skillData = RetrieveSkillDataCombat(treeIndex);
        if(skillData.IsActionable() && skillData.DoesMeetActionRequirements(sCharacterID, sWeaponSet))
        {
            CharacterActionArray vNewActions = skillData.CreateCombatActions(sCharacterID, sWeaponSet);
            vActions.insert(vActions.end(), vNewActions.begin(), vNewActions.end());
            return true;
        }
    }
    else if(DoesSkillDataWeaponExist(treeIndex))
    {
        const SkillDataWeapon& skillData = RetrieveSkillDataWeapon(treeIndex);
        if(skillData.IsActionable() && skillData.DoesMeetActionRequirements(sCharacterID, sWeaponSet))
        {
            CharacterActionArray vNewActions = skillData.CreateWeaponActions(sCharacterID, sWeaponSet);
            vActions.insert(vActions.end(), vNewActions.begin(), vNewActions.end());
            return true;
        }
    }
    return false;
}

void SkillManager::FillSkillStatChangeArrays(
    const String& sCharID,
    TreeIndexArray& vPassives,
    TreeIndexArray& vActives,
    TreeIndexArray& vActionables,
    Bool bUniqueOnly /*= false*/) const
{
    // Get all skill datas
    TreeIndexArray vSkillDataArray;
    TreeIndexArray vSkillDataAffinityArray = GetAffinitySkills(sCharID, bUniqueOnly);
    TreeIndexArray vSkillDataAlchemyArray = GetAlchemySkills(sCharID, bUniqueOnly);
    TreeIndexArray vSkillDataBreakdownArray = GetBreakdownSkills(sCharID, bUniqueOnly);
    TreeIndexArray vSkillDataCombatArray = GetCombatSkills(sCharID, bUniqueOnly);
    TreeIndexArray vSkillDataCraftingArray = GetCraftingSkills(sCharID, bUniqueOnly);
    TreeIndexArray vSkillDataWeaponArray = GetWeaponSkills(sCharID, bUniqueOnly);
    vSkillDataArray.insert(vSkillDataArray.end(), vSkillDataAffinityArray.begin(), vSkillDataAffinityArray.end());
    vSkillDataArray.insert(vSkillDataArray.end(), vSkillDataAlchemyArray.begin(), vSkillDataAlchemyArray.end());
    vSkillDataArray.insert(vSkillDataArray.end(), vSkillDataBreakdownArray.begin(), vSkillDataBreakdownArray.end());
    vSkillDataArray.insert(vSkillDataArray.end(), vSkillDataCombatArray.begin(), vSkillDataCombatArray.end());
    vSkillDataArray.insert(vSkillDataArray.end(), vSkillDataCraftingArray.begin(), vSkillDataCraftingArray.end());
    vSkillDataArray.insert(vSkillDataArray.end(), vSkillDataWeaponArray.begin(), vSkillDataWeaponArray.end());

    // Use a set to make sure that we do not include duplicates
    STDUnorderedSet<String> tAlreadyUsed;

    // Split them into separate lists
    for(const TreeIndex& treeIndex : vSkillDataArray)
    {
        String sIndexKey = treeIndex.GetTreeBranchLeafType();
        Bool bIsActionable = IsSkillActionable(treeIndex);
        Bool bIsBaseWeaponSkill = IsBaseWeaponSkill(treeIndex);
        Bool bIsAlreadyUsed = (tAlreadyUsed.count(sIndexKey) == 1);
        if(bIsActionable && !bIsBaseWeaponSkill && !bIsAlreadyUsed)
        {
            vActionables.push_back(treeIndex);
            tAlreadyUsed.insert(sIndexKey);
        }
        else if(!bIsActionable && !bIsBaseWeaponSkill && !bIsAlreadyUsed)
        {
            for(const StatChange& statChange : GetStatChangesFromSkillTreeIndex(treeIndex))
            {
                if(statChange.IsPassive())
                {
                    vPassives.push_back(treeIndex);
                    tAlreadyUsed.insert(sIndexKey);
                    break;
                }
                else if(statChange.IsActive())
                {
                    vActives.push_back(treeIndex);
                    tAlreadyUsed.insert(sIndexKey);
                    break;
                }
            }
        }
    }
}

};
