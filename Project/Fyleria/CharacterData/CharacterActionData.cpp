// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterActionData.h"
#include "CharacterData/CharacterDataTypes.h"
#include "Character/CharacterTypes.h"
#include "Character/CharacterTypeConverters.h"
#include "Application/Application.h"
#include "Stat/StatTypeTemplates.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

CharacterActionData::CharacterActionData()
{
}

CharacterActionData::CharacterActionData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterActionData::~CharacterActionData()
{
}

void CharacterActionData::Clear()
{
    // Stats
    StatTypeHolder::Clear();

    // List of character actions
    GetAvailableActions().clear();
}

void CharacterActionData::UpdateAvailableActions(const String& sCharacterID)
{
    // Get character
    const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Clear stored actions
    CharacterActionArray& vAvailableActions = GetAvailableActions();
    vAvailableActions.clear();

    // Look at each type of tree index
    for(auto& sIndexTreeType : CharacterTreeIndexType::_names())
    {
        // Skip invalid tree types
        if(IsNoneTypeForEnum<CharacterTreeIndexType>(sIndexTreeType))
        {
            continue;
        }

        // Look at each active change index of that type
        for(const TreeIndex& treeIndex : character.GetActionableChanges(sIndexTreeType))
        {
            // Look at each weapon set
            for(auto& sWeaponSet : CharacterWeaponSetType::_names())
            {
                // Skip invalid weapon sets
                if(IsNoneTypeForEnum<CharacterWeaponSetType>(sWeaponSet))
                {
                    continue;
                }

                // Add skill actions
                CharacterActionArray vSkillActions;
                if(GetManagers()->GetSkillManager()->GenerateSkillCharacterActions(treeIndex, sCharacterID, sWeaponSet, vSkillActions))
                {
                   vAvailableActions.insert(vAvailableActions.end(), vSkillActions.begin(), vSkillActions.end());
                }

                // Add item actions
                CharacterActionArray vItemActions;
                if(GetManagers()->GetItemManager()->GenerateItemCharacterActions(treeIndex, sCharacterID, sWeaponSet, vItemActions))
                {
                   vAvailableActions.insert(vAvailableActions.end(), vItemActions.begin(), vItemActions.end());
                }
            }
        }
    }
}

void CharacterActionData::ApplyActionCost(
    const String& sCharacterID,
    const CharacterAction& action)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get progress data
    CharacterProgressData& progressData = character.GetProgressData();

    // Get total costs
    const Int iTotalHPCost = action.GetCostHP() + progressData.GetHealthCostDelta();
    const Int iTotalMPCost = action.GetCostMP() + progressData.GetMagicCostDelta();
    const Int iTotalEPCost = action.GetCostHP() + progressData.GetEnergyCostDelta();
    const Int iTotalAPCost = action.GetCostAP();

    // Apply HP/MP/EP costs
    if(iTotalHPCost > 0) { progressData.SetHealthPointsCurrent(progressData.GetHealthPointsCurrent() - iTotalHPCost); }
    if(iTotalMPCost > 0) { progressData.SetMagicPointsCurrent(progressData.GetMagicPointsCurrent() - iTotalMPCost); }
    if(iTotalEPCost > 0) { progressData.SetEnergyPointsCurrent(progressData.GetEnergyPointsCurrent() - iTotalEPCost); }

    // Apply AP cost
    if(iTotalAPCost > 0)
    {
        // Get matching stat type
        String sMatchingStatType;
        if(GetManagers()->GetSkillManager()->DoesSkillDataWeaponExist(action.GetSkillTreeIndex()))
        {
            const SkillDataWeapon& skillDataWeapon = GetManagers()->GetSkillManager()->RetrieveSkillDataWeapon(action.GetSkillTreeIndex());
            sMatchingStatType = ConvertSkillWeaponTypeToCharacterActionStatType(skillDataWeapon.GetSkillType());
        }

        // Set new AP value
        if(!IsNoneTypeForEnum<CharacterActionDataType_Int>(sMatchingStatType))
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

void CharacterActionData::UpdateAvailableAP(const String& sCharacterID)
{
    // Action point count type
    struct ActionPointCountEntry
    {
        Int iCount;
        TreeIndex skillIndex;
    };

    // Get weapon skills
    TreeIndexArray vWeaponSkills = GetManagers()->GetSkillManager()->GetWeaponSkills(sCharacterID, true);
    if(vWeaponSkills.empty())
    {
        return;
    }

    // Populate a table of the highest amount of action points
    STDUnorderedMap<String, ActionPointCountEntry> tHighestActionPointCounts;
    for(const TreeIndex& treeIndex : vWeaponSkills)
    {
        // Skill based action points
        if(GetManagers()->GetSkillManager()->DoesSkillDataWeaponExist(treeIndex) && !GetManagers()->GetSkillManager()->IsBaseWeaponSkill(treeIndex))
        {
            // Get skill information
            const SkillDataWeapon& skillDataWeapon = GetManagers()->GetSkillManager()->RetrieveSkillDataWeapon(treeIndex);
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
            const SkillDataWeapon& skillDataWeapon = GetManagers()->GetSkillManager()->RetrieveSkillDataWeapon(skillIndex);
            const String sMatchingStatType = ConvertSkillWeaponTypeToCharacterActionStatType(skillDataWeapon.GetSkillType());
            if(!IsNoneTypeForEnum<CharacterActionDataType_Int>(sMatchingStatType))
            {
                SetStatValue(sMatchingStatType, iActionPoints);
            }
        }
    }
}

void CharacterActionData::InitAllStatNames()
{
    // Initialize stat type names
    InitializeStatTypeNames<CharacterActionDataType_Int>(GetIntStatNames());
}

Bool CharacterActionData::operator==(const CharacterActionData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterActionData::operator!=(const CharacterActionData& other) const
{
    return !operator==(other);
}

void to_json(Json& jsonData, const CharacterActionData& obj)
{
    // Stat values
    SetJsonValuesFromStatTypeValues<CharacterActionDataType_Int, Int>(jsonData, obj.GetIntStats());

    // List of character actions
    SET_JSON_DATA(AvailableActions);
}

void from_json(const Json& jsonData, CharacterActionData& obj)
{
    // Stat values
    SetStatTypeValuesFromJsonValues<CharacterActionDataType_Int, Int>(jsonData, obj.GetIntStats());

    // List of character actions
    SET_OBJ_DATA(AvailableActions, CharacterActionArray);
}

};
