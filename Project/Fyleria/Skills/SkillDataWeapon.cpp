// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Skills/SkillDataWeapon.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "CharacterParty/CharacterPartyManager.h"

namespace Gecko
{

SkillDataWeapon::SkillDataWeapon()
    : SkillData()
{
}

SkillDataWeapon::SkillDataWeapon(const Json& jsonData)
    : SkillData(jsonData)
{
    from_json(jsonData, *this);
}

void SkillDataWeapon::Clear()
{
    // Base clear
    SkillData::Clear();

    // Weapon base type
    SetWeaponBaseType("");

    // Amount of action points available
    SetActionPoints(0);
}

CharacterActionArray SkillDataWeapon::CreateWeaponActions(const String& sCharacterID, const String& sWeaponSet) const
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
    StringArray vPrimaryActionTypes;
    StringArray vSecondaryActionTypes;
    if(!partyMember.GetHandInfoByWeaponSet(sWeaponSet,
       primaryItemIndex,
       secondaryItemIndex,
       vPrimaryActionTypes,
       vSecondaryActionTypes))
    {
        return vNewActions;
    }

    // Get intersecting requirements
    StringArray vPrimaryAttackIntersections;
    StringArray vPrimaryDefendIntersections;
    StringArray vSecondaryAttackIntersections;
    StringArray vSecondaryDefendIntersections;
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
    String sPrimaryItemType = ItemTree::RetrieveItemType(primaryItemIndex);
    String sSecondaryItemType = ItemTree::RetrieveItemType(secondaryItemIndex);
    String sPrimaryItemActionType = ConvertItemTypeToCharacterActionType(sPrimaryItemType);
    String sSecondaryItemActionType = ConvertItemTypeToCharacterActionType(sSecondaryItemType);
    String sActionNoneType = (+CharacterActionType::None)._to_string();
    if(sPrimaryItemActionType == sActionNoneType && sSecondaryItemActionType == sActionNoneType)
    {
        return vNewActions;
    }

    // Create a list of action combinations
    struct ActionCombination
    {
        StringArray vActionTypes;
        String sHandType;
    };
    STDVector<ActionCombination> vCombinations;

    // Get preliminary info for checking combinations
    Bool bHavePrimaryAction = sPrimaryItemActionType != sActionNoneType;
    Bool bHaveSecondaryAction = sSecondaryItemActionType != sActionNoneType;
    Bool bOnlyAttackReqs = DoesHaveOnlyAttackRequirements();

    // Add attack combinations from primary hand
    if(bHavePrimaryAction && bOnlyAttackReqs)
    {
        for(const String& sActionType : vPrimaryAttackIntersections)
        {
            ActionCombination newCombination;
            newCombination.vActionTypes = {sPrimaryItemActionType, sActionType};
            newCombination.sHandType = String("Primary");
            vCombinations.push_back(newCombination);
        }
    }

    // Add attack combinations from secondary hand
    if(bHaveSecondaryAction && bOnlyAttackReqs)
    {
        for(const String& sActionType : vSecondaryAttackIntersections)
        {
            ActionCombination newCombination;
            newCombination.vActionTypes = {sSecondaryItemActionType, sActionType};
            newCombination.sHandType = String("Secondary");
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
    // Weapon base type
    SET_JSON_DATA(WeaponBaseType);

    // Amount of action points available
    SET_JSON_DATA(ActionPoints);
}

void from_json(const Json& jsonData, SkillDataWeapon& obj)
{
    // Weapon base type
    SET_OBJ_DATA(WeaponBaseType, String, "");

    // Amount of action points available
    SET_OBJ_DATA(ActionPoints, Int, 0);
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(SkillDataWeapon, SkillDataWeapon);

};
