// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterProgressData.h"
#include "Character/CharacterTypes.h"
#include "Skills/SkillTree.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterProgressData::CharacterProgressData()
{
    // Init stat names
    InitAllStatNames();

    // Clear data
    Clear();
}

CharacterProgressData::CharacterProgressData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void CharacterProgressData::Clear()
{
    // Clear stat values
    RESET_STAT_TYPE_VALUES(CharacterProgressStatType, Int);
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
        IndexedString sMatchingStatType;
        if(DoesSkillDataWeaponExist(action.GetSkillTreeIndex()))
        {
            const SkillDataWeapon& skillDataWeapon = RetrieveSkillDataWeapon(action.GetSkillTreeIndex());
            sMatchingStatType = ConvertSkillWeaponTypeToCharacterProgressStatType(skillDataWeapon.GetSkillType());
        }

        // Set new AP value
        if(sMatchingStatType != IndexedString("None"))
        {
            Int iAPValue = 0;
            if(!GetIntStatValue(sMatchingStatType, iAPValue))
            {
                return;
            }

            Int iNewAPValue = iAPValue - iTotalAPCost;
            if(iNewAPValue < 0)
            {
                return;
            }

            if(!SetIntStatValue(sMatchingStatType, iNewAPValue))
            {
                return;
            }
        }
    }
}

void CharacterProgressData::UpdateAvailableAP(const TreeIndexArray& vIndices)
{
    // Action point count type
    struct ActionPointCountEntry
    {
        Int iCount;
        TreeIndex skillIndex;
    };

    // Populate a table of the highest amount of action points
    STDUnorderedMap<IndexedString, ActionPointCountEntry, IndexedStringHasher> tHighestActionPointCounts;
    for(const TreeIndex& index : vIndices)
    {
        // Skill based action points
        if(DoesSkillDataWeaponExist(index) && !IsBaseWeaponSkill(index))
        {
            // Get skill information
            const SkillDataWeapon& skillDataWeapon = RetrieveSkillDataWeapon(index);
            IndexedString sKey = index.GetTreeBranchType();
            Int iActionPoints = skillDataWeapon.GetActionPoints();

            // Update or add new information
            if(tHighestActionPointCounts.count(sKey))
            {
                if(iActionPoints > tHighestActionPointCounts[sKey].iCount)
                {
                    tHighestActionPointCounts[sKey].iCount = iActionPoints;
                    tHighestActionPointCounts[sKey].skillIndex = index;
                }
            }
            else
            {
                ActionPointCountEntry entry;
                entry.iCount = iActionPoints;
                entry.skillIndex = index;
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
            const SkillDataWeapon& skillDataWeapon = RetrieveSkillDataWeapon(skillIndex);
            const IndexedString sMatchingStatType = ConvertSkillWeaponTypeToCharacterProgressStatType(skillDataWeapon.GetSkillType());
            if(sMatchingStatType != IndexedString("None"))
            {
                SetIntStatValue(sMatchingStatType, iActionPoints);
            }
        }
    }
}

static Bool s_bCharacterProgressData_StatNamesInitialized = false;
void CharacterProgressData::InitAllStatNames()
{
    // Check initialization
    if(s_bCharacterProgressData_StatNamesInitialized)
    {
        return;
    }

    // Initialize stats
    INITIALIZE_STAT_TYPE_VALUES(CharacterProgressStatType, Int);

    // Finished
    s_bCharacterProgressData_StatNamesInitialized = true;
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
