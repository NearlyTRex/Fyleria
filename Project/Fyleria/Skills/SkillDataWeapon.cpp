// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Skills/SkillDataWeapon.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "CharacterParty/CharacterPartyManager.h"

namespace Gecko
{

SkillDataWeapon::SkillDataWeapon()
    : SkillData()
{
    // Weapon base type
    SetWeaponBaseType(IndexedString("None"));

    // Amount of action points available
    SetActionPoints(0);
}

SkillDataWeapon::SkillDataWeapon(const Json& jsonData)
    : SkillData(jsonData)
{
    from_json(jsonData, *this);
}

CharacterActionArray SkillDataWeapon::CreateWeaponActions(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    // Skip base actions
    CharacterActionArray vNewActions;
    if(SkillTree::IsBaseWeaponSkill(GetSkillTreeIndex()))
    {
        return vNewActions;
    }

    // Check character
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return vNewActions;
    }

    // Get character
    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);
    const CharacterParty& party = CharacterPartyManager::GetInstance()->GetPartyByID(character.GetPartyID());
    const CharacterPartyMember& partyMember = party.GetMemberByID(sCharacterID);

    // Get equipped item information
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
        return vNewActions;
    }

    // Get intersecting requirements
    IndexedStringArray vPrimaryAttackIntersections;
    IndexedStringArray vPrimaryDefendIntersections;
    IndexedStringArray vSecondaryAttackIntersections;
    IndexedStringArray vSecondaryDefendIntersections;
    if(!GetIntersectingRequirementTypes(
        vPrimaryActionTypes,
        vSecondaryActionTypes,
        vPrimaryAttackIntersections,
        vPrimaryDefendIntersections,
        vSecondaryAttackIntersections,
        vSecondaryDefendIntersections))
    {
        return vNewActions;
    }

    // Get item types
    IndexedString sPrimaryItemType = ItemTree::RetrieveItemType(primaryItemIndex);
    IndexedString sSecondaryItemType = ItemTree::RetrieveItemType(secondaryItemIndex);
    IndexedString sPrimaryItemActionType = ConvertItemTypeToCharacterActionType(sPrimaryItemType);
    IndexedString sSecondaryItemActionType = ConvertItemTypeToCharacterActionType(sSecondaryItemType);
    if(sPrimaryItemActionType.IsNone() && sSecondaryItemActionType.IsNone())
    {
        return vNewActions;
    }

    // Create a list of action combinations
    struct ActionCombination
    {
        IndexedStringArray vActionTypes;
        IndexedString sHandType;
    };
    STDVector<ActionCombination> vCombinations;

    // Get preliminary info for checking combinations
    Bool bHavePrimaryAction = !sPrimaryItemActionType.IsNone();
    Bool bHaveSecondaryAction = !sSecondaryItemActionType.IsNone();
    Bool bOnlyAttackReqs = DoesHaveOnlyAttackRequirements();

    // Add attack combinations from primary hand
    if(bHavePrimaryAction && bOnlyAttackReqs)
    {
        for(const IndexedString& sActionType : vPrimaryAttackIntersections)
        {
            ActionCombination newCombination;
            newCombination.vActionTypes = {sPrimaryItemActionType, sActionType};
            newCombination.sHandType = IndexedString("Primary");
            vCombinations.push_back(newCombination);
        }
    }

    // Add attack combinations from secondary hand
    if(bHaveSecondaryAction && bOnlyAttackReqs)
    {
        for(const IndexedString& sActionType : vSecondaryAttackIntersections)
        {
            ActionCombination newCombination;
            newCombination.vActionTypes = {sSecondaryItemActionType, sActionType};
            newCombination.sHandType = IndexedString("Secondary");
            vCombinations.push_back(newCombination);
        }
    }

    // Setup new actions
    for(auto& newAction : CreateBaseActions(sCharacterID, sWeaponSet))
    {
        // Create new actions out of each combination
        for(const ActionCombination& combination : vCombinations)
        {
            CharacterActionEntry newEntry;
            newEntry.SetActionTypes(combination.vActionTypes);
            newEntry.SetHandType(combination.sHandType);
            newAction.GetActionEntries().push_back(newEntry);
            vNewActions.push_back(newAction);
        }
    }
    return vNewActions;
}

void to_json(Json& jsonData, const SkillDataWeapon& obj)
{
}

void from_json(const Json& jsonData, SkillDataWeapon& obj)
{
    // Weapon base type
    obj.SetWeaponBaseType(GET_JSON_DATA_OR_DEFAULT(WeaponBaseType, IndexedString, IndexedString("None")));

    // Amount of action points available
    obj.SetActionPoints(GET_JSON_DATA_OR_DEFAULT(ActionPoints, Int, 0));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(SkillDataWeapon, SkillDataWeapon);

};
