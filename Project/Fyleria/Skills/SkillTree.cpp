// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
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
    // Get config data
    const Config& config = ConfigManager::GetInstance()->GetCurrentConfig();
    String sUserConfigFolder = ConfigManager::GetInstance()->GetUserConfigFolder();

    // Affinity
    SkillTreeAffinity::GetInstance()->AddBranch("Blood", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityBloodFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Dark", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityDarkFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Earth", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityEarthFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Fire", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityFireFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Flesh", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityFleshFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Force", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityForceFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Holy", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityHolyFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Ice", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityIceFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Light", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityLightFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Mind", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityMindFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Shock", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityShockFile()));
    SkillTreeAffinity::GetInstance()->AddBranch("Wind", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAffinityWindFile()));

    // Alchemy
    SkillTreeAlchemy::GetInstance()->AddBranch("Alchemist", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAlchemyAlchemistFile()));
    SkillTreeAlchemy::GetInstance()->AddBranch("Chemist", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAlchemyChemistFile()));
    SkillTreeAlchemy::GetInstance()->AddBranch("Energist", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAlchemyEnergistFile()));
    SkillTreeAlchemy::GetInstance()->AddBranch("Healer", JoinPathsCanonical(sUserConfigFolder, config.GetSkillAlchemyHealerFile()));

    // Breakdown
    SkillTreeBreakdown::GetInstance()->AddBranch("Bowbane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownBowbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Goldbane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownGoldbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Hammerbane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownHammerbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Platebane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownPlatebaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Scalebane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownScalebaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Shieldbane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownShieldbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Spellbane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownSpellbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("StudRemover", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownStudRemoverFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Swordbane", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownSwordbaneFile()));
    SkillTreeBreakdown::GetInstance()->AddBranch("Threadbare", JoinPathsCanonical(sUserConfigFolder, config.GetSkillBreakdownThreadbareFile()));

    // Combat
    SkillTreeCombat::GetInstance()->AddBranch("Ambidextrous", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatAmbidextrousFile()));
    SkillTreeCombat::GetInstance()->AddBranch("Avatar", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatAvatarFile()));
    SkillTreeCombat::GetInstance()->AddBranch("Barbarian", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatBarbarianFile()));
    SkillTreeCombat::GetInstance()->AddBranch("Blademaster", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatBlademasterFile()));
    SkillTreeCombat::GetInstance()->AddBranch("Focused", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatFocusedFile()));
    SkillTreeCombat::GetInstance()->AddBranch("Mage", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatMageFile()));
    SkillTreeCombat::GetInstance()->AddBranch("Rogue", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatRogueFile()));
    SkillTreeCombat::GetInstance()->AddBranch("Stalwart", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCombatStalwartFile()));

    // Crafting
    SkillTreeCrafting::GetInstance()->AddBranch("Bowsmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingBowsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Goldsmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingGoldsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Hammersmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingHammersmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Platesmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingPlatesmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Scalesmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingScalesmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Shieldsmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingShieldsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Spellsmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingSpellsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Swordsmith", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingSwordsmithFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Tanner", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingTannerFile()));
    SkillTreeCrafting::GetInstance()->AddBranch("Weaver", JoinPathsCanonical(sUserConfigFolder, config.GetSkillCraftingWeaverFile()));

    // Weapon
    SkillTreeWeapon::GetInstance()->AddBranch("Bash", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponBashFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Block", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponBlockFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Break", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponBreakFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Cleave", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponCleaveFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Counter", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponCounterFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Crack", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponCrackFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("CriticalShot", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponCriticalShotFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Crush", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponCrushFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Decapitate", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponDecapitateFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Dodge", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponDodgeFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Drill", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponDrillFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Impact", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponImpactFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Impale", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponImpaleFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Parry", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponParryFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Pierce", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponPierceFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Riposte", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponRiposteFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Rush", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponRushFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Sever", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponSeverFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Shoot", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponShootFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Slash", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponSlashFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Slice", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponSliceFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Slit", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponSlitFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("Smash", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponSmashFile()));
    SkillTreeWeapon::GetInstance()->AddBranch("StealthStrike", JoinPathsCanonical(sUserConfigFolder, config.GetSkillWeaponStealthStrikeFile()));

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
    String sBaseType = (+CharacterSegmentType::Base)._to_string();                                              \
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
            CharacterManager::GetInstance()->ApplyStatChange(sBaseType, change, bAll, bOne, true);              \
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
    String sBranchName(#branch);                                                \
    auto vLeaves = SkillTree##tree::GetInstance()->GetAllLeaves(sBranchName);   \
    vFinal.insert(vFinal.end(), vLeaves.begin(), vLeaves.end());                \
}

#define ADD_SKILL_LEAVES_PROGRESS(tree, branch)                                                                             \
{                                                                                                                           \
    String sBranchName(#branch);                                                                                            \
    String sRankBase("Rank");                                                                                               \
    Int iLeafNumber = character.GetSkillData().GetSkillRankValue(#branch);                                                  \
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
    return GetNoneTypeForEnum<SkillTreeType>();
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
            !IsNoneTypeForEnum<SkillWeaponBaseType>(skillData.GetWeaponBaseType())
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
