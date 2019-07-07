// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "CharacterData/CharacterProgressData.h"
#include "Character/CharacterTypes.h"
#include "Skills/SkillTree.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterProgressData::CharacterProgressData()
{
}

CharacterProgressData::CharacterProgressData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterProgressData::~CharacterProgressData()
{
}

void CharacterProgressData::ApplyTakenDamage(Int iDamage)
{
    Int iNewHealthPoints = ClipValue<Int>(GetHealthPointsCurrent() - iDamage, 0, GetHealthPointsMax());
    SetHealthPointsCurrent(iNewHealthPoints);
}

void CharacterProgressData::ApplyRegeneration(Bool bCanRegenHP, Bool bCanRegenMP, Bool bCanRegenEP)
{
    // Get new values
    Int iNewHP = ClipValue<Int>(GetHealthPointsCurrent() + GetHealthRegen(), 0, GetHealthPointsMax());
    Int iNewMP = ClipValue<Int>(GetMagicPointsCurrent() + GetMagicRegen(), -GetMagicPointsMax(), GetMagicPointsMax());
    Int iNewEP = ClipValue<Int>(GetEnergyPointsCurrent() + GetEnergyRegen(), -GetEnergyPointsMax(), GetEnergyPointsMax());

    // Apply new values
    if(bCanRegenHP) { SetHealthPointsCurrent(iNewHP); }
    if(bCanRegenMP) { SetMagicPointsCurrent(iNewMP); }
    if(bCanRegenEP) { SetEnergyPointsCurrent(iNewEP); }
}

void CharacterProgressData::ApplyActionCost(const CharacterAction& action)
{
    // Get total costs
    const Int iTotalHPCost = action.GetCostHP() + GetHealthCostDelta();
    const Int iTotalMPCost = action.GetCostMP() + GetMagicCostDelta();
    const Int iTotalEPCost = action.GetCostHP() + GetEnergyCostDelta();
    const Int iTotalAPCost = action.GetCostAP();

    // Apply HP/MP/EP costs
    if(iTotalHPCost > 0) { SetHealthPointsCurrent(GetHealthPointsCurrent() - iTotalHPCost); }
    if(iTotalMPCost > 0) { SetMagicPointsCurrent(GetMagicPointsCurrent() - iTotalMPCost); }
    if(iTotalEPCost > 0) { SetEnergyPointsCurrent(GetEnergyPointsCurrent() - iTotalEPCost); }

    // Apply AP cost
    if(iTotalAPCost > 0)
    {
        // Get matching stat type
        String sMatchingStatType;
        if(SkillTree::DoesSkillDataWeaponExist(action.GetSkillTreeIndex()))
        {
            const SkillDataWeapon& skillDataWeapon = SkillTree::RetrieveSkillDataWeapon(action.GetSkillTreeIndex());
            sMatchingStatType = ConvertSkillWeaponTypeToCharacterProgressStatType(skillDataWeapon.GetSkillType());
        }

        // Set new AP value
        if(!IsNoneTypeForEnum<CharacterProgressStatType_Int>(sMatchingStatType))
        {
            Int iAPValue = 0;
            if(!GetStatValue(sMatchingStatType, iAPValue))
            {
                return;
            }

            Int iNewAPValue = iAPValue - iTotalAPCost;
            if(iNewAPValue < 0)
            {
                return;
            }

            if(!SetStatValue(sMatchingStatType, iNewAPValue))
            {
                return;
            }
        }
    }
}

void CharacterProgressData::UpdateAvailableAP(const String& sCharacterID)
{
    // Action point count type
    struct ActionPointCountEntry
    {
        Int iCount;
        TreeIndex skillIndex;
    };

    // Get weapon skills
    TreeIndexArray vWeaponSkills = SkillTree::GetWeaponSkills(sCharacterID, true);
    if(vWeaponSkills.empty())
    {
        return;
    }

    // Populate a table of the highest amount of action points
    STDUnorderedMap<String, ActionPointCountEntry> tHighestActionPointCounts;
    for(const TreeIndex& treeIndex : vWeaponSkills)
    {
        // Skill based action points
        if(SkillTree::DoesSkillDataWeaponExist(treeIndex) && !SkillTree::IsBaseWeaponSkill(treeIndex))
        {
            // Get skill information
            const SkillDataWeapon& skillDataWeapon = SkillTree::RetrieveSkillDataWeapon(treeIndex);
            String sKey = treeIndex.GetTreeBranchType();
            Int iActionPoints = skillDataWeapon.GetActionPoints();

            // Update or add new information
            if(tHighestActionPointCounts.count(sKey))
            {
                if(iActionPoints > tHighestActionPointCounts[sKey].iCount)
                {
                    tHighestActionPointCounts[sKey].iCount = iActionPoints;
                    tHighestActionPointCounts[sKey].skillIndex = treeIndex;
                }
            }
            else
            {
                ActionPointCountEntry entry;
                entry.iCount = iActionPoints;
                entry.skillIndex = treeIndex;
                tHighestActionPointCounts[sKey] = entry;
            }
        }
    }

    // Now that we have the highest action point values, record them as AP
    for(auto it = tHighestActionPointCounts.begin(); it != tHighestActionPointCounts.end(); it++)
    {
        Int iActionPoints = it->second.iCount;
        const TreeIndex& skillIndex = it->second.skillIndex;
        if(!skillIndex.empty())
        {
            // Update AP in each area
            const SkillDataWeapon& skillDataWeapon = SkillTree::RetrieveSkillDataWeapon(skillIndex);
            const String sMatchingStatType = ConvertSkillWeaponTypeToCharacterProgressStatType(skillDataWeapon.GetSkillType());
            if(!IsNoneTypeForEnum<CharacterProgressStatType_Int>(sMatchingStatType))
            {
                SetStatValue(sMatchingStatType, iActionPoints);
            }
        }
    }
}

void CharacterProgressData::InitAllStatNames()
{
    // Initialize stat type names
    INITIALIZE_STAT_TYPE_NAMES(CharacterProgressStatType, Int);
}

Bool CharacterProgressData::operator==(const CharacterProgressData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterProgressData::operator!=(const CharacterProgressData& other) const
{
    return not operator==(other);
}

void to_json(Json& jsonData, const CharacterProgressData& obj)
{
    // Stat values
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterProgressStatType, Int);
}

void from_json(const Json& jsonData, CharacterProgressData& obj)
{
    // Stat values
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterProgressStatType, Int);
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterProgressData, CharacterProgressData);

};
