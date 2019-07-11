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

template <class T>
void PostProcessSkills(const TreeIndexArray& vTreeIndices)
{
    for(auto& treeIndex : vTreeIndices)
    {
        auto& skillData = T::GetInstance()->GetLeaf(treeIndex);
        skillData.SetSkillTreeIndex(treeIndex);
        for(auto& statChange : skillData.GetStatChanges())
        {
            statChange.SetSkillTreeIndex(treeIndex);
        }
    }
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
    PostProcessSkills<SkillTreeAffinity>(GetAllAffinitySkills());
    PostProcessSkills<SkillTreeAlchemy>(GetAllAlchemySkills());
    PostProcessSkills<SkillTreeBreakdown>(GetAllBreakdownSkills());
    PostProcessSkills<SkillTreeCombat>(GetAllCombatSkills());
    PostProcessSkills<SkillTreeCrafting>(GetAllCraftingSkills());
    PostProcessSkills<SkillTreeWeapon>(GetAllWeaponSkills());
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

template <class T>
void VerifyApplyStatChanges(const TreeIndexArray& vTreeIndices, const String& sCharacterTargetType)
{
    String sBaseType = (+CharacterSegmentType::Base)._to_string();
    for(auto& treeIndex : vTreeIndices)
    {
        auto& skillData = T::GetInstance()->GetLeaf(treeIndex);
        LOG_FORMAT_STATEMENT("Processing skill (SkillRank = '%d', "
                             "SkillTreeType = '%s', "
                             "SkillType = '%s', "
                             "SkillName = '%s', "
                             "StatChanges = %zu)\n",
            skillData.GetSkillRank(),
            T::GetTreeType().c_str(),
            skillData.GetSkillType().c_str(),
            skillData.GetSkillName().c_str(),
            skillData.GetStatChanges().size());
        for(auto change : skillData.GetStatChanges())
        {
            Bool bAll, bOne = false;
            change.SetSourceTargetType(sCharacterTargetType);
            change.SetDestinationTargetType(sCharacterTargetType);
            change.SetChanceToApply(1.0);
            CharacterManager::GetInstance()->ApplyStatChange(sBaseType, change, bAll, bOne, true);
        }
    }
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
    VerifyApplyStatChanges<SkillTreeAffinity>(GetAllAffinitySkills(), sCharacterTargetType);
    VerifyApplyStatChanges<SkillTreeAlchemy>(GetAllAlchemySkills(), sCharacterTargetType);
    VerifyApplyStatChanges<SkillTreeBreakdown>(GetAllBreakdownSkills(), sCharacterTargetType);
    VerifyApplyStatChanges<SkillTreeCombat>(GetAllCombatSkills(), sCharacterTargetType);
    VerifyApplyStatChanges<SkillTreeCrafting>(GetAllCraftingSkills(), sCharacterTargetType);
    VerifyApplyStatChanges<SkillTreeWeapon>(GetAllWeaponSkills(), sCharacterTargetType);

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

template <class T>
void AddAllSkillLeaves(const String& sBranchName, TreeIndexArray& vLeaves)
{
    auto vNewLeaves = T::GetInstance()->GetAllLeaves(sBranchName);
    vLeaves.insert(vLeaves.end(), vNewLeaves.begin(), vNewLeaves.end());
}

template <class T>
void AddSkillLeavesProgress(const String& sBranchName, const Character& character, TreeIndexArray& vLeaves, Bool bUniqueOnly)
{
    String sRankBase("Rank");
    Int iLeafNumber = character.GetSkillData().GetSkillRankValue(sBranchName);
    auto vNewLeaves = T::GetInstance()->GetLeavesUnderNumber(sBranchName, sRankBase, iLeafNumber, bUniqueOnly);
    vLeaves.insert(vLeaves.end(), vNewLeaves.begin(), vNewLeaves.end());
}

TreeIndexArray SkillTree::GetAllAffinitySkills()
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeAffinity>("Holy", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Fire", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Ice", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Shock", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Dark", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Light", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Force", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Mind", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Earth", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Blood", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Flesh", vFinal);
    AddAllSkillLeaves<SkillTreeAffinity>("Wind", vFinal);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllAlchemySkills()
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeAlchemy>("Alchemist", vFinal);
    AddAllSkillLeaves<SkillTreeAlchemy>("Chemist", vFinal);
    AddAllSkillLeaves<SkillTreeAlchemy>("Energist", vFinal);
    AddAllSkillLeaves<SkillTreeAlchemy>("Healer", vFinal);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllBreakdownSkills()
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeBreakdown>("Bowbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Goldbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Hammerbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Platebane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Scalebane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Shieldbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Spellbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("StudRemover", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Swordbane", vFinal);
    AddAllSkillLeaves<SkillTreeBreakdown>("Threadbare", vFinal);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllCombatSkills()
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeCombat>("Ambidextrous", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>("Avatar", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>("Barbarian", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>("Blademaster", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>("Focused", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>("Mage", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>("Rogue", vFinal);
    AddAllSkillLeaves<SkillTreeCombat>("Stalwart", vFinal);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllCraftingSkills()
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeCrafting>("Bowsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Goldsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Hammersmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Platesmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Scalesmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Shieldsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Spellsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Swordsmith", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Tanner", vFinal);
    AddAllSkillLeaves<SkillTreeCrafting>("Weaver", vFinal);
    return vFinal;
}

TreeIndexArray SkillTree::GetAllWeaponSkills()
{
    TreeIndexArray vFinal;
    AddAllSkillLeaves<SkillTreeWeapon>("Bash", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Block", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Break", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Cleave", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Counter", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Crack", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("CriticalShot", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Crush", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Decapitate", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Dodge", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Drill", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Impact", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Impale", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Parry", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Pierce", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Riposte", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Rush", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Sever", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Shoot", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Slash", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Slice", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Slit", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("Smash", vFinal);
    AddAllSkillLeaves<SkillTreeWeapon>("StealthStrike", vFinal);
    return vFinal;
}

TreeIndexArray SkillTree::GetAffinitySkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeAffinity>("Holy", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Fire", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Ice", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Shock", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Dark", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Light", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Force", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Mind", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Earth", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Blood", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Flesh", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAffinity>("Wind", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetAlchemySkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeAlchemy>("Alchemist", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAlchemy>("Chemist", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAlchemy>("Energist", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeAlchemy>("Healer", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetBreakdownSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Bowbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Goldbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Hammerbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Platebane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Scalebane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Shieldbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Spellbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("StudRemover", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Swordbane", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeBreakdown>("Threadbare", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetCombatSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeCombat>("Ambidextrous", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>("Avatar", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>("Barbarian", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>("Blademaster", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>("Focused", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>("Mage", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>("Rogue", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCombat>("Stalwart", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetCraftingSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeCrafting>("Bowsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Goldsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Hammersmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Platesmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Scalesmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Shieldsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Spellsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Swordsmith", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Tanner", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeCrafting>("Weaver", character, vFinal, bUniqueOnly);
    }
    return vFinal;
}

TreeIndexArray SkillTree::GetWeaponSkills(const String& sCharID, Bool bUniqueOnly /*= false*/)
{
    TreeIndexArray vFinal;
    if(!sCharID.empty())
    {
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharID);
        AddSkillLeavesProgress<SkillTreeWeapon>("Bash", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Block", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Break", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Cleave", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Counter", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Crack", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("CriticalShot", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Crush", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Decapitate", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Dodge", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Drill", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Impact", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Impale", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Parry", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Pierce", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Riposte", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Rush", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Sever", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Shoot", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Slash", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Slice", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Slit", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("Smash", character, vFinal, bUniqueOnly);
        AddSkillLeavesProgress<SkillTreeWeapon>("StealthStrike", character, vFinal, bUniqueOnly);
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
