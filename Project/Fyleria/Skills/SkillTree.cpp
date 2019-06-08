// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Skills/SkillTree.h"
#include "Config/ConfigManager.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Stats/StatChange.h"
#include "Utility/Constants.h"
#include "Utility/FantasyName.h"
#include "Utility/Json.h"

namespace Gecko
{

#define POSTPROCESS_SKILLS(tree)                                                            \
{                                                                                           \
    for(const TreeIndex& treeIndex : GetAll##tree##Skills())                                \
    {                                                                                       \
        SkillData##tree& skillData = SkillTree##tree::GetInstance()->GetLeaf(treeIndex);    \
        skillData.SetSkillTreeIndex(treeIndex);                                             \
        for(StatChange& statChange : skillData.GetStatChanges())                            \
        {                                                                                   \
            statChange.SetSkillTreeIndex(treeIndex);                                        \
        }                                                                                   \
    }                                                                                       \
}

void SkillTree::LoadSkillTreesIntoMemory()
{
    // Affinity
    SkillTreeAffinity::GetInstance()->AddBranch(String("Blood"), String(ConfigManager::GetInstance()->GetSkillAffinityBloodFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Dark"), String(ConfigManager::GetInstance()->GetSkillAffinityDarkFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Earth"), String(ConfigManager::GetInstance()->GetSkillAffinityEarthFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Fire"), String(ConfigManager::GetInstance()->GetSkillAffinityFireFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Flesh"), String(ConfigManager::GetInstance()->GetSkillAffinityFleshFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Force"), String(ConfigManager::GetInstance()->GetSkillAffinityForceFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Holy"), String(ConfigManager::GetInstance()->GetSkillAffinityHolyFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Ice"), String(ConfigManager::GetInstance()->GetSkillAffinityIceFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Light"), String(ConfigManager::GetInstance()->GetSkillAffinityLightFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Mind"), String(ConfigManager::GetInstance()->GetSkillAffinityMindFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Shock"), String(ConfigManager::GetInstance()->GetSkillAffinityShockFile()));
    SkillTreeAffinity::GetInstance()->AddBranch(String("Wind"), String(ConfigManager::GetInstance()->GetSkillAffinityWindFile()));

    // Alchemy
    SkillTreeAlchemy::GetInstance()->AddBranch(String("Alchemist"), String(ConfigManager::GetInstance()->GetSkillAlchemyAlchemistFile()));
    SkillTreeAlchemy::GetInstance()->AddBranch(String("Chemist"), String(ConfigManager::GetInstance()->GetSkillAlchemyChemistFile()));
    SkillTreeAlchemy::GetInstance()->AddBranch(String("Energist"), String(ConfigManager::GetInstance()->GetSkillAlchemyEnergistFile()));
    SkillTreeAlchemy::GetInstance()->AddBranch(String("Healer"), String(ConfigManager::GetInstance()->GetSkillAlchemyHealerFile()));

    // Breakdown
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Bowbane"), String(ConfigManager::GetInstance()->GetSkillBreakdownBowbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Goldbane"), String(ConfigManager::GetInstance()->GetSkillBreakdownGoldbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Hammerbane"), String(ConfigManager::GetInstance()->GetSkillBreakdownHammerbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Platebane"), String(ConfigManager::GetInstance()->GetSkillBreakdownPlatebaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Scalebane"), String(ConfigManager::GetInstance()->GetSkillBreakdownScalebaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Shieldbane"), String(ConfigManager::GetInstance()->GetSkillBreakdownShieldbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Spellbane"), String(ConfigManager::GetInstance()->GetSkillBreakdownSpellbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("StudRemover"), String(ConfigManager::GetInstance()->GetSkillBreakdownStudRemoverFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Swordbane"), String(ConfigManager::GetInstance()->GetSkillBreakdownSwordbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch(String("Threadbare"), String(ConfigManager::GetInstance()->GetSkillBreakdownThreadbareFile()));

    // Combat
    SkillTreeCombat::GetInstance()->AddBranch(String("Ambidextrous"), String(ConfigManager::GetInstance()->GetSkillCombatAmbidextrousFile()));
    SkillTreeCombat::GetInstance()->AddBranch(String("Avatar"), String(ConfigManager::GetInstance()->GetSkillCombatAvatarFile()));
    SkillTreeCombat::GetInstance()->AddBranch(String("Barbarian"), String(ConfigManager::GetInstance()->GetSkillCombatBarbarianFile()));
    SkillTreeCombat::GetInstance()->AddBranch(String("Blademaster"), String(ConfigManager::GetInstance()->GetSkillCombatBlademasterFile()));
    SkillTreeCombat::GetInstance()->AddBranch(String("Focused"), String(ConfigManager::GetInstance()->GetSkillCombatFocusedFile()));
    SkillTreeCombat::GetInstance()->AddBranch(String("Mage"), String(ConfigManager::GetInstance()->GetSkillCombatMageFile()));
    SkillTreeCombat::GetInstance()->AddBranch(String("Rogue"), String(ConfigManager::GetInstance()->GetSkillCombatRogueFile()));
    SkillTreeCombat::GetInstance()->AddBranch(String("Stalwart"), String(ConfigManager::GetInstance()->GetSkillCombatStalwartFile()));

    // Crafting
    SkillTreeCrafting::GetInstance()->AddBranch(String("Bowsmith"), String(ConfigManager::GetInstance()->GetSkillCraftingBowsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Goldsmith"), String(ConfigManager::GetInstance()->GetSkillCraftingGoldsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Hammersmith"), String(ConfigManager::GetInstance()->GetSkillCraftingHammersmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Platesmith"), String(ConfigManager::GetInstance()->GetSkillCraftingPlatesmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Scalesmith"), String(ConfigManager::GetInstance()->GetSkillCraftingScalesmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Shieldsmith"), String(ConfigManager::GetInstance()->GetSkillCraftingShieldsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Spellsmith"), String(ConfigManager::GetInstance()->GetSkillCraftingSpellsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Swordsmith"), String(ConfigManager::GetInstance()->GetSkillCraftingSwordsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Tanner"), String(ConfigManager::GetInstance()->GetSkillCraftingTannerFile()));
    SkillTreeCrafting::GetInstance()->AddBranch(String("Weaver"), String(ConfigManager::GetInstance()->GetSkillCraftingWeaverFile()));

    // Weapon
    SkillTreeWeapon::GetInstance()->AddBranch(String("Bash"), String(ConfigManager::GetInstance()->GetSkillWeaponBashFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Block"), String(ConfigManager::GetInstance()->GetSkillWeaponBlockFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Break"), String(ConfigManager::GetInstance()->GetSkillWeaponBreakFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Cleave"), String(ConfigManager::GetInstance()->GetSkillWeaponCleaveFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Counter"), String(ConfigManager::GetInstance()->GetSkillWeaponCounterFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Crack"), String(ConfigManager::GetInstance()->GetSkillWeaponCrackFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("CriticalShot"), String(ConfigManager::GetInstance()->GetSkillWeaponCriticalShotFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Crush"), String(ConfigManager::GetInstance()->GetSkillWeaponCrushFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Decapitate"), String(ConfigManager::GetInstance()->GetSkillWeaponDecapitateFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Dodge"), String(ConfigManager::GetInstance()->GetSkillWeaponDodgeFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Drill"), String(ConfigManager::GetInstance()->GetSkillWeaponDrillFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Impact"), String(ConfigManager::GetInstance()->GetSkillWeaponImpactFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Impale"), String(ConfigManager::GetInstance()->GetSkillWeaponImpaleFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Parry"), String(ConfigManager::GetInstance()->GetSkillWeaponParryFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Pierce"), String(ConfigManager::GetInstance()->GetSkillWeaponPierceFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Riposte"), String(ConfigManager::GetInstance()->GetSkillWeaponRiposteFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Rush"), String(ConfigManager::GetInstance()->GetSkillWeaponRushFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Sever"), String(ConfigManager::GetInstance()->GetSkillWeaponSeverFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Shoot"), String(ConfigManager::GetInstance()->GetSkillWeaponShootFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Slash"), String(ConfigManager::GetInstance()->GetSkillWeaponSlashFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Slice"), String(ConfigManager::GetInstance()->GetSkillWeaponSliceFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Slit"), String(ConfigManager::GetInstance()->GetSkillWeaponSlitFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("Smash"), String(ConfigManager::GetInstance()->GetSkillWeaponSmashFile()));
    SkillTreeWeapon::GetInstance()->AddBranch(String("StealthStrike"), String(ConfigManager::GetInstance()->GetSkillWeaponStealthStrikeFile()));

    // Post process skill data
    POSTPROCESS_SKILLS(Affinity);
    POSTPROCESS_SKILLS(Alchemy);
    POSTPROCESS_SKILLS(Breakdown);
    POSTPROCESS_SKILLS(Combat);
    POSTPROCESS_SKILLS(Crafting);
    POSTPROCESS_SKILLS(Weapon);
}

void SkillTree::UnloadSkillTreesFromMemory()
{
    // Clear all skill data
    SkillTreeAffinity::GetInstance()->ClearAllData();
    SkillTreeAlchemy::GetInstance()->ClearAllData();
    SkillTreeBreakdown::GetInstance()->ClearAllData();
    SkillTreeCombat::GetInstance()->ClearAllData();
    SkillTreeCrafting::GetInstance()->ClearAllData();
    SkillTreeWeapon::GetInstance()->ClearAllData();
}

#define VERIFY_APPLY_STATCHANGES(tree, character_target)                                                        \
{                                                                                                               \
    for(const TreeIndex& treeIndex : GetAll##tree##Skills())                                                    \
    {                                                                                                           \
        SkillData##tree& skillData = SkillTree##tree::GetInstance()->GetLeaf(treeIndex);                        \
        LOG_FORMAT_STATEMENT("Processing skill (SkillRank = '%d', "                                             \
                             "SkillTreeType = '%s', "                                                           \
                             "SkillType = '%s', "                                                               \
                             "SkillName = '%s', "                                                               \
                             "StatChanges = %zu)\n",                                                            \
            skillData.GetSkillRank(),                                                                           \
            #tree,                                                                                              \
            skillData.GetSkillType().c_str(),                                                                   \
            skillData.GetSkillName().c_str(),                                                                   \
            skillData.GetStatChanges().size());                                                                 \
        for(StatChange change : skillData.GetStatChanges())                                                     \
        {                                                                                                       \
            Bool bAll, bOne = false;                                                                            \
            change.SetSourceTargetType(character_target);                                                       \
            change.SetDestinationTargetType(character_target);                                                  \
            change.SetChanceToApply(1.0);                                                                       \
            CharacterManager::GetInstance()->ApplyStatChange(String("Base"), change, bAll, bOne, true);  \
        }                                                                                                       \
    }                                                                                                           \
}

void SkillTree::VerifySkillTrees()
{
    // Log start
    LOG_STATEMENT("Verifying skill trees...");

    // Load character generator
    CharacterGenerator generator;
    generator.RandomizeAll();

    // Generate a character and party
    const String sCharacterID("CharacterID");
    const String sCharacterPartyID("CharacterPartyID");
    const String sCharacterPartyType("Ally");
    CharacterManager::GetInstance()->GenerateCharacter(sCharacterID, generator);
    CharacterPartyManager::GetInstance()->CreateParty(sCharacterPartyID, sCharacterPartyType, true);
    CharacterPartyManager::GetInstance()->GetPartyByID(sCharacterPartyID).AddMember(sCharacterID);
    const String sCharacterTargetType = CharacterManager::GetInstance()->GetCharacter(sCharacterID).GetCharacterTargetType();

    // Apply all stat changes
    VERIFY_APPLY_STATCHANGES(Affinity, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Alchemy, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Breakdown, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Combat, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Crafting, sCharacterTargetType);
    VERIFY_APPLY_STATCHANGES(Weapon, sCharacterTargetType);

    // Cleanup
    CharacterPartyManager::GetInstance()->GetPartyByID(sCharacterPartyID).RemoveMember(sCharacterID);
    CharacterPartyManager::GetInstance()->UnloadParty(sCharacterPartyID);
    CharacterManager::GetInstance()->UnloadCharacter(sCharacterID);
}

Bool SkillTree::DoesSkillDataAffinityExist(const TreeIndex& treeIndex)
{
    return SkillTreeAffinity::GetInstance()->HasLeaf(treeIndex);
}

Bool SkillTree::DoesSkillDataAlchemyExist(const TreeIndex& treeIndex)
{
    return SkillTreeAlchemy::GetInstance()->HasLeaf(treeIndex);
}

Bool SkillTree::DoesSkillDataBreakdownExist(const TreeIndex& treeIndex)
{
    return SkillTreeBreakdown::GetInstance()->HasLeaf(treeIndex);
}

Bool SkillTree::DoesSkillDataCombatExist(const TreeIndex& treeIndex)
{
    return SkillTreeCombat::GetInstance()->HasLeaf(treeIndex);
}

Bool SkillTree::DoesSkillDataCraftingExist(const TreeIndex& treeIndex)
{
    return SkillTreeCrafting::GetInstance()->HasLeaf(treeIndex);
}

Bool SkillTree::DoesSkillDataWeaponExist(const TreeIndex& treeIndex)
{
    return SkillTreeWeapon::GetInstance()->HasLeaf(treeIndex);
}

const SkillDataAffinity& SkillTree::RetrieveSkillDataAffinity(const TreeIndex& treeIndex)
{
    return SkillTreeAffinity::GetInstance()->GetLeaf(treeIndex);
}

const SkillDataAlchemy& SkillTree::RetrieveSkillDataAlchemy(const TreeIndex& treeIndex)
{
    return SkillTreeAlchemy::GetInstance()->GetLeaf(treeIndex);
}

const SkillDataBreakdown& SkillTree::RetrieveSkillDataBreakdown(const TreeIndex& treeIndex)
{
    return SkillTreeBreakdown::GetInstance()->GetLeaf(treeIndex);
}

const SkillDataCombat& SkillTree::RetrieveSkillDataCombat(const TreeIndex& treeIndex)
{
    return SkillTreeCombat::GetInstance()->GetLeaf(treeIndex);
}

const SkillDataCrafting& SkillTree::RetrieveSkillDataCrafting(const TreeIndex& treeIndex)
{
    return SkillTreeCrafting::GetInstance()->GetLeaf(treeIndex);
}

const SkillDataWeapon& SkillTree::RetrieveSkillDataWeapon(const TreeIndex& treeIndex)
{
    return SkillTreeWeapon::GetInstance()->GetLeaf(treeIndex);
}

#define ADD_ALL_SKILL_LEAVES(tree, branch)                                      \
{                                                                               \
    String sBranchName(#branch);                                         \
    auto vLeaves = SkillTree##tree::GetInstance()->GetAllLeaves(sBranchName);   \
    vFinal.insert(vFinal.end(), vLeaves.begin(), vLeaves.end());                \
}

#define ADD_SKILL_LEAVES_PROGRESS(tree, branch)                                                                             \
{                                                                                                                           \
    String sBranchName(#branch);                                                                                     \
    String sRankBase("Rank");                                                                                        \
    Int iLeafNumber = character.GetSkillData().Get##branch##Rank();                                                         \
    auto vLeaves = SkillTree##tree::GetInstance()->GetLeavesUnderNumber(sBranchName, sRankBase, iLeafNumber, bUniqueOnly);  \
    vFinal.insert(vFinal.end(), vLeaves.begin(), vLeaves.end());                                                            \
}

TreeIndexArray SkillTree::GetAllAffinitySkills()
{
    TreeIndexArray vFinal;
    ADD_ALL_SKILL_LEAVES(Affinity, Holy);
    ADD_ALL_SKILL_LEAVES(Affinity, Fire);
    ADD_ALL_SKILL_LEAVES(Affinity, Ice);
    ADD_ALL_SKILL_LEAVES(Affinity, Shock);
    ADD_ALL_SKILL_LEAVES(Affinity, Dark);
    ADD_ALL_SKILL_LEAVES(Affinity, Light);
    ADD_ALL_SKILL_LEAVES(Affinity, Force);
    ADD_ALL_SKILL_LEAVES(Affinity, Mind);
    ADD_ALL_SKILL_LEAVES(Affinity, Earth);
    ADD_ALL_SKILL_LEAVES(Affinity, Blood);
    ADD_ALL_SKILL_LEAVES(Affinity, Flesh);
    ADD_ALL_SKILL_LEAVES(Affinity, Wind);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllAlchemySkills()
{
    TreeIndexArray vFinal;
    ADD_ALL_SKILL_LEAVES(Alchemy, Alchemist);
    ADD_ALL_SKILL_LEAVES(Alchemy, Chemist);
    ADD_ALL_SKILL_LEAVES(Alchemy, Energist);
    ADD_ALL_SKILL_LEAVES(Alchemy, Healer);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllBreakdownSkills()
{
    TreeIndexArray vFinal;
    ADD_ALL_SKILL_LEAVES(Breakdown, Bowbane);
    ADD_ALL_SKILL_LEAVES(Breakdown, Goldbane);
    ADD_ALL_SKILL_LEAVES(Breakdown, Hammerbane);
    ADD_ALL_SKILL_LEAVES(Breakdown, Platebane);
    ADD_ALL_SKILL_LEAVES(Breakdown, Scalebane);
    ADD_ALL_SKILL_LEAVES(Breakdown, Shieldbane);
    ADD_ALL_SKILL_LEAVES(Breakdown, Spellbane);
    ADD_ALL_SKILL_LEAVES(Breakdown, StudRemover);
    ADD_ALL_SKILL_LEAVES(Breakdown, Swordbane);
    ADD_ALL_SKILL_LEAVES(Breakdown, Threadbare);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllCombatSkills()
{
    TreeIndexArray vFinal;
    ADD_ALL_SKILL_LEAVES(Combat, Ambidextrous);
    ADD_ALL_SKILL_LEAVES(Combat, Avatar);
    ADD_ALL_SKILL_LEAVES(Combat, Barbarian);
    ADD_ALL_SKILL_LEAVES(Combat, Blademaster);
    ADD_ALL_SKILL_LEAVES(Combat, Focused);
    ADD_ALL_SKILL_LEAVES(Combat, Mage);
    ADD_ALL_SKILL_LEAVES(Combat, Rogue);
    ADD_ALL_SKILL_LEAVES(Combat, Stalwart);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllCraftingSkills()
{
    TreeIndexArray vFinal;
    ADD_ALL_SKILL_LEAVES(Crafting, Bowsmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Goldsmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Hammersmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Platesmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Scalesmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Shieldsmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Spellsmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Swordsmith);
    ADD_ALL_SKILL_LEAVES(Crafting, Tanner);
    ADD_ALL_SKILL_LEAVES(Crafting, Weaver);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllWeaponSkills()
{
    TreeIndexArray vFinal;
    ADD_ALL_SKILL_LEAVES(Weapon, Bash);
    ADD_ALL_SKILL_LEAVES(Weapon, Block);
    ADD_ALL_SKILL_LEAVES(Weapon, Break);
    ADD_ALL_SKILL_LEAVES(Weapon, Cleave);
    ADD_ALL_SKILL_LEAVES(Weapon, Counter);
    ADD_ALL_SKILL_LEAVES(Weapon, Crack);
    ADD_ALL_SKILL_LEAVES(Weapon, CriticalShot);
    ADD_ALL_SKILL_LEAVES(Weapon, Crush);
    ADD_ALL_SKILL_LEAVES(Weapon, Decapitate);
    ADD_ALL_SKILL_LEAVES(Weapon, Dodge);
    ADD_ALL_SKILL_LEAVES(Weapon, Drill);
    ADD_ALL_SKILL_LEAVES(Weapon, Impact);
    ADD_ALL_SKILL_LEAVES(Weapon, Impale);
    ADD_ALL_SKILL_LEAVES(Weapon, Parry);
    ADD_ALL_SKILL_LEAVES(Weapon, Pierce);
    ADD_ALL_SKILL_LEAVES(Weapon, Riposte);
    ADD_ALL_SKILL_LEAVES(Weapon, Rush);
    ADD_ALL_SKILL_LEAVES(Weapon, Sever);
    ADD_ALL_SKILL_LEAVES(Weapon, Shoot);
    ADD_ALL_SKILL_LEAVES(Weapon, Slash);
    ADD_ALL_SKILL_LEAVES(Weapon, Slice);
    ADD_ALL_SKILL_LEAVES(Weapon, Slit);
    ADD_ALL_SKILL_LEAVES(Weapon, Smash);
    ADD_ALL_SKILL_LEAVES(Weapon, StealthStrike);
    return vFinal;
}

TreeIndexArray SkillTree::GetAffinitySkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Holy);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Fire);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Ice);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Shock);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Dark);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Light);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Force);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Mind);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Earth);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Blood);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Flesh);
        ADD_SKILL_LEAVES_PROGRESS(Affinity, Wind);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetAlchemySkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        ADD_SKILL_LEAVES_PROGRESS(Alchemy, Alchemist);
        ADD_SKILL_LEAVES_PROGRESS(Alchemy, Chemist);
        ADD_SKILL_LEAVES_PROGRESS(Alchemy, Energist);
        ADD_SKILL_LEAVES_PROGRESS(Alchemy, Healer);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetBreakdownSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Bowbane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Goldbane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Hammerbane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Platebane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Scalebane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Shieldbane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Spellbane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, StudRemover);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Swordbane);
        ADD_SKILL_LEAVES_PROGRESS(Breakdown, Threadbare);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetCombatSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Ambidextrous);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Avatar);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Barbarian);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Blademaster);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Focused);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Mage);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Rogue);
        ADD_SKILL_LEAVES_PROGRESS(Combat, Stalwart);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetCraftingSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Bowsmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Goldsmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Hammersmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Platesmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Scalesmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Shieldsmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Spellsmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Swordsmith);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Tanner);
        ADD_SKILL_LEAVES_PROGRESS(Crafting, Weaver);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetWeaponSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Bash);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Block);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Break);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Cleave);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Counter);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Crack);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, CriticalShot);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Crush);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Decapitate);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Dodge);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Drill);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Impact);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Impale);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Parry);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Pierce);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Riposte);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Rush);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Sever);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Shoot);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Slash);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Slice);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Slit);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, Smash);
        ADD_SKILL_LEAVES_PROGRESS(Weapon, StealthStrike);
    }
    return vFinal;
}

String SkillTree::GetSkillType(const TreeIndex& treeIndex)
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
    return (+SkillTreeType::None)._to_string();
}

Bool SkillTree::IsBaseWeaponSkill(const TreeIndex& treeIndex)
{
    if(DoesSkillDataWeaponExist(treeIndex))
    {
        const SkillDataWeapon& skillData = RetrieveSkillDataWeapon(treeIndex);
        return (
            skillData.GetSkillCostAP() == 0 &&
            skillData.GetActionPoints() == 0 &&
            !skillData.GetWeaponBaseType().empty() &&
            skillData.GetWeaponBaseType() != (+SkillWeaponBaseType::None)._to_string()
        );
    }
    return false;
}

Bool SkillTree::IsSkillActionable(const TreeIndex& treeIndex)
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

Bool SkillTree::GenerateSkillCharacterActions(const TreeIndex& treeIndex,
    const String& sCharacterID,
    const String& sWeaponSet,
    CharacterActionArray& vActions)
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

void SkillTree::FillSkillStatChangeArrays(const String& sCharID,
    TreeIndexArray& vPassives,
    TreeIndexArray& vActives,
    TreeIndexArray& vActionables,
    Bool bUniqueOnly /*= false*/)
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
