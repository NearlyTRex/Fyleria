// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Skills/SkillDataCombat.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "CharacterParty/CharacterPartyManager.h"

namespace Gecko
{

SkillDataCombat::SkillDataCombat()
    : SkillData()
{
}

SkillDataCombat::SkillDataCombat(const Json& jsonData)
    : SkillData(jsonData)
{
    from_json(jsonData, *this);
}

void SkillDataCombat::Clear()
{
    // Base clear
    SkillData::Clear();
}

CharacterActionArray SkillDataCombat::CreateCombatActions(const String& sCharacterID, const String& sWeaponSet) const
{
    // Check character
    CharacterActionArray vNewActions;
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

    // Setup new actions
    for(auto& newAction : CreateBaseActions(sCharacterID, sWeaponSet))
    {
        // Ambidextrous - Twin Attack
        // Ambidextrous - Split Focus
        // Attack two targets with both primary and secondary weapons
        if(GetDataClass() == String("TwinAttack") ||
           GetDataClass() == String("SplitFocus"))
        {
            // Create primary entry
            CharacterActionEntry newEntryPrimary;
            newEntryPrimary.SetActionTypes({sPrimaryItemActionType});
            newEntryPrimary.SetHandType(String("Primary"));
            newAction.GetActionEntries().push_back(newEntryPrimary);

            // Create secondary entry
            CharacterActionEntry newEntrySecondary;
            newEntrySecondary.SetActionTypes({sSecondaryItemActionType});
            newEntrySecondary.SetHandType(String("Secondary"));
            newAction.GetActionEntries().push_back(newEntrySecondary);
        }

        // Focused - Focused Strike
        // Focused - Deadly Retribution
        // Attack a single target with primary or secondary weapon, whichever one is equipped
        else if(GetDataClass() == String("FocusedStrike") ||
                GetDataClass() == String("DeadlyRetribution"))
        {
            // Create entry
            CharacterActionEntry newEntry;
            Bool bUsePrimary = (sPrimaryItemActionType != sActionNoneType);
            String sActionTypeToUse = (bUsePrimary) ? sPrimaryItemActionType : sSecondaryItemActionType;
            String sHandTypeToUse = (bUsePrimary) ? String("Primary") : String("Secondary");
            newEntry.SetActionTypes({sActionTypeToUse});
            newEntry.SetHandType(sHandTypeToUse);
            newAction.GetActionEntries().push_back(newEntry);
        }

        // Stalwart - Shield Punch
        // Stalwart - Shield Charge
        // Attack a single target with primary or secondary shield, whichever one is the shield
        else if(GetDataClass() == String("ShieldPunch") ||
                GetDataClass() == String("ShieldCharge"))
        {
            // Create entry
            CharacterActionEntry newEntry;
            Bool bUsePrimary = (sPrimaryItemActionType != sActionNoneType && ItemTree::IsItemShield(primaryItemIndex));
            String sActionTypeToUse = (bUsePrimary) ? sPrimaryItemActionType : sSecondaryItemActionType;
            String sHandTypeToUse = (bUsePrimary) ? String("Primary") : String("Secondary");
            newEntry.SetActionTypes({sActionTypeToUse});
            newEntry.SetHandType(sHandTypeToUse);
            newEntry.SetIsHandTypeShield(true);
            newAction.GetActionEntries().push_back(newEntry);
        }

        // Add new action
        if(!newAction.GetActionEntries().empty())
        {
            vNewActions.push_back(newAction);
        }
    }
    return vNewActions;
}

void to_json(Json& jsonData, const SkillDataCombat& obj)
{
}

void from_json(const Json& jsonData, SkillDataCombat& obj)
{
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(SkillDataCombat, SkillDataCombat);

};
