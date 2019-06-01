// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Skills/SkillData.h"
#include "CharacterAction/CharacterAction.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Utility/Templates.h"

namespace Gecko
{

SkillData::SkillData()
{
}

SkillData::SkillData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void SkillData::Clear()
{
    // Run types
    SetRunTypes({});

    // Data class
    SetDataClass(IndexedString(""));

    // Skill rank
    SetSkillRank(0);

    // Skill name
    SetSkillName(IndexedString(""));

    // Skill description
    SetSkillDescription(IndexedString(""));

    // Skill type
    SetSkillType(IndexedString("None"));

    // Skill costs
    SetSkillCostAP(0);
    SetSkillCostHP(0);

    // Skill index
    SetSkillTreeIndex({});

    // Stat changes
    SetStatChanges({});
}

Bool SkillData::IsActionable() const
{
    // First check that all the necessary information is filled out
    if(GetRunTypes().empty() ||
       GetDataClass().empty() ||
       GetSkillName().empty() ||
       GetSkillDescription().empty() ||
       GetSkillType().empty())
    {
        return false;
    }

    // Check special case for base attacks
    if(GetSkillRank() == 0)
    {
        return true;
    }

    // Check costs
    if(GetSkillCostAP() > 0 ||
       GetSkillCostHP() > 0)
    {
        return true;
    }
    return false;
}

void SkillData::GetNumberOfAttackAndDefendRequirements(Int& iAttacks, Int& iDefends) const
{
    for(const StatChange& change : GetStatChanges())
    {
        iAttacks += (change.DoesHaveAttackRequirements()) ? 1 : 0;
        iDefends += (change.DoesHaveDefendRequirements()) ? 1 : 0;
    }
}

Bool SkillData::DoesHaveOnlyAttackRequirements() const
{
    Int iAttacks = 0;
    Int iDefends = 0;
    GetNumberOfAttackAndDefendRequirements(iAttacks, iDefends);
    return (iAttacks > 0 && iDefends == 0);
}

Bool SkillData::DoesHaveOnlyDefendRequirements() const
{
    Int iAttacks = 0;
    Int iDefends = 0;
    GetNumberOfAttackAndDefendRequirements(iAttacks, iDefends);
    return (iAttacks == 0 && iDefends > 0);
}

Bool SkillData::GetIntersectingRequirementTypes(
    const IndexedStringArray& vPrimaryActionTypes,
    const IndexedStringArray& vSecondaryActionTypes,
    IndexedStringArray& vPrimaryAttackIntersections,
    IndexedStringArray& vPrimaryDefendIntersections,
    IndexedStringArray& vSecondaryAttackIntersections,
    IndexedStringArray& vSecondaryDefendIntersections) const
{
    // Get intersections
    for(const StatChange& change : GetStatChanges())
    {
        if(change.DoesHaveAttackRequirements() && !vPrimaryActionTypes.empty())
        {
            IndexedStringArray vIntersect = change.GetIntersectingAttackRequirements(vPrimaryActionTypes);
            vPrimaryAttackIntersections.insert(vPrimaryAttackIntersections.end(), vIntersect.begin(), vIntersect.end());
        }
        if(change.DoesHaveAttackRequirements() && !vSecondaryActionTypes.empty())
        {
            IndexedStringArray vIntersect = change.GetIntersectingAttackRequirements(vSecondaryActionTypes);
            vSecondaryAttackIntersections.insert(vSecondaryAttackIntersections.end(), vIntersect.begin(), vIntersect.end());
        }
        if(change.DoesHaveDefendRequirements() && !vPrimaryActionTypes.empty())
        {
            IndexedStringArray vIntersect = change.GetIntersectingDefendRequirements(vPrimaryActionTypes);
            vPrimaryDefendIntersections.insert(vPrimaryDefendIntersections.end(), vIntersect.begin(), vIntersect.end());
        }
        if(change.DoesHaveDefendRequirements() && !vSecondaryActionTypes.empty())
        {
            IndexedStringArray vIntersect = change.GetIntersectingDefendRequirements(vSecondaryActionTypes);
            vSecondaryDefendIntersections.insert(vSecondaryDefendIntersections.end(), vIntersect.begin(), vIntersect.end());
        }
    }

    // Remove duplicates
    RemoveVectorDuplicates<IndexedString>(vPrimaryAttackIntersections);
    RemoveVectorDuplicates<IndexedString>(vPrimaryDefendIntersections);
    RemoveVectorDuplicates<IndexedString>(vSecondaryAttackIntersections);
    RemoveVectorDuplicates<IndexedString>(vSecondaryDefendIntersections);

    // Return true if at least one of them is not empty
    return (
        !vPrimaryAttackIntersections.empty() ||
        !vPrimaryDefendIntersections.empty() ||
        !vSecondaryAttackIntersections.empty() ||
        !vSecondaryDefendIntersections.empty()
    );
}

Bool SkillData::DoesMeetActionRequirements(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    // Check character
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return false;
    }

    // Get character
    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);
    const CharacterParty& party = CharacterPartyManager::GetInstance()->GetPartyByID(character.GetPartyID());
    const CharacterPartyMember& partyMember = party.GetMemberByID(sCharacterID);

    // Get action types
    TreeIndex primaryItemIndex;
    TreeIndex secondaryItemIndex;
    IndexedStringArray vPrimaryActionTypes;
    IndexedStringArray vSecondaryActionTypes;
    if(!partyMember.GetHandInfoByWeaponSet(sWeaponSet,
        primaryItemIndex,
        secondaryItemIndex,
        vPrimaryActionTypes,
        vSecondaryActionTypes))
    {
        return false;
    }

    // Check each of the stat changes against the equipped items and their action types
    for(const StatChange& change : GetStatChanges())
    {
        if(change.DoesHaveItemEquippedRequirements())
        {
            return change.DoesMeetItemEquippedRequirements(sCharacterID, sWeaponSet);
        }
        else if(change.DoesHaveAttackRequirements() && !vPrimaryActionTypes.empty())
        {
            return change.DoesMeetAttackRequirements(vPrimaryActionTypes);
        }
        else if(change.DoesHaveAttackRequirements() && !vSecondaryActionTypes.empty())
        {
            return change.DoesMeetAttackRequirements(vSecondaryActionTypes);
        }
    }
    return false;
}

CharacterActionArray SkillData::CreateBaseActions(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    // Check character
    CharacterActionArray vNewActions;
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return vNewActions;
    }

    // Get character
    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Create actions
    for(auto& sType : GetRunTypes())
    {
        CharacterAction newAction;
        newAction.SetRunType(sType);
        newAction.SetCostAP(GetSkillCostAP());
        newAction.SetCostHP(GetSkillCostHP());
        newAction.SetWeaponSet(sWeaponSet);
        newAction.SetSkillTreeIndex(GetSkillTreeIndex());
        newAction.SetSourceTargetType(character.GetCharacterTargetType());
        newAction.SetSourceCharacterID(sCharacterID);
        vNewActions.push_back(newAction);
    }
    return vNewActions;
}

void to_json(Json& jsonData, const SkillData& obj)
{
    // Run types
    SET_JSON_DATA_IF_NOT_EMPTY(RunTypes);

    // Data class
    SET_JSON_DATA_IF_NOT_DEFAULT(DataClass, IndexedString(""));

    // Skill rank
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillRank, 0);

    // Skill name
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillName, IndexedString(""));

    // Skill description
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillDescription, IndexedString(""));

    // Skill type
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillType, IndexedString("None"));

    // Skill costs
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillCostAP, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillCostHP, 0);

    // Skill index
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillTreeIndex, TreeIndex());

    // Stat changes
    SET_JSON_DATA_IF_NOT_EMPTY(StatChanges);
}

void from_json(const Json& jsonData, SkillData& obj)
{
    // Run types
    obj.SetRunTypes(GET_JSON_DATA_OR_DEFAULT(RunTypes, IndexedStringArray, IndexedStringArray()));

    // Data class
    obj.SetDataClass(GET_JSON_DATA_OR_DEFAULT(DataClass, IndexedString, IndexedString("")));

    // Skill rank
    obj.SetSkillRank(GET_JSON_DATA_OR_DEFAULT(SkillRank, Int, 0));

    // Skill name
    obj.SetSkillName(GET_JSON_DATA_OR_DEFAULT(SkillName, IndexedString, IndexedString("")));

    // Skill description
    obj.SetSkillDescription(GET_JSON_DATA_OR_DEFAULT(SkillDescription, IndexedString, IndexedString("")));

    // Skill type
    obj.SetSkillType(GET_JSON_DATA_OR_DEFAULT(SkillType, IndexedString, IndexedString("None")));

    // Skill costs
    obj.SetSkillCostAP(GET_JSON_DATA_OR_DEFAULT(SkillCostAP, Int, 0));
    obj.SetSkillCostHP(GET_JSON_DATA_OR_DEFAULT(SkillCostHP, Int, 0));

    // Skill index
    obj.SetSkillTreeIndex(GET_JSON_DATA_OR_DEFAULT(SkillTreeIndex, TreeIndex, TreeIndex()));

    // Stat changes
    obj.SetStatChanges(GET_JSON_DATA_OR_DEFAULT(StatChanges, StatChangeArray, StatChangeArray()));
}

};
