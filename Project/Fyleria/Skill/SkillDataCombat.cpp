// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Skill/SkillDataCombat.h"
#include "Character/CharacterTypes.h"
#include "Character/CharacterTypeConverters.h"
#include "Application/Application.h"
#include "Utility/JsonMacros.h"

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

SkillDataCombat::~SkillDataCombat()
{
}

void SkillDataCombat::Clear()
{
    // Base clear
    SkillData::Clear();
}

CharacterActionArray SkillDataCombat::CreateCombatActions(
    const String& sCharacterID,
    const String& sWeaponSet) const
{
    // Check character
    CharacterActionArray vNewActions;
    if(!GetManagers()->GetCharacterManager()->DoesCharacterExist(sCharacterID))
    {
        return vNewActions;
    }

    // Get character
    const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);
    if(character.GetPartyID().empty())
    {
        return vNewActions;
    }

    // Get party
    const CharacterParty& party = GetManagers()->GetCharacterPartyManager()->GetPartyByID(character.GetPartyID());
    const CharacterPartyMember& partyMember = party.GetMemberByID(sCharacterID);

    // Get equipped item information
    TreeIndex primaryItemIndex;
    TreeIndex secondaryItemIndex;
    StringArray vPrimaryActionTypes;
    StringArray vSecondaryActionTypes;
    if(!partyMember.GetHandInfoByWeaponSet(
        sWeaponSet,
        primaryItemIndex,
        secondaryItemIndex,
        vPrimaryActionTypes,
        vSecondaryActionTypes))
    {
        return vNewActions;
    }

    // Get item types
    const String sPrimaryItemType = GetManagers()->GetItemManager()->RetrieveItemType(primaryItemIndex);
    const String sSecondaryItemType = GetManagers()->GetItemManager()->RetrieveItemType(secondaryItemIndex);
    const String sPrimaryItemActionType = ConvertItemTypeToCharacterActionType(sPrimaryItemType);
    const String sSecondaryItemActionType = ConvertItemTypeToCharacterActionType(sSecondaryItemType);
    const String sActionNoneType = GetNoneTypeForEnum<CharacterActionType>();
    const String sHandPrimaryType = GetEnumString(CharacterHandType::Primary);
    const String sHandSecondaryType = GetEnumString(CharacterHandType::Secondary);
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
            newEntryPrimary.SetHandType(sHandPrimaryType);
            newAction.GetActionEntries().push_back(newEntryPrimary);

            // Create secondary entry
            CharacterActionEntry newEntrySecondary;
            newEntrySecondary.SetActionTypes({sSecondaryItemActionType});
            newEntrySecondary.SetHandType(sHandSecondaryType);
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
            const String sActionTypeToUse = (bUsePrimary) ? sPrimaryItemActionType : sSecondaryItemActionType;
            const String sHandTypeToUse = (bUsePrimary) ? sHandPrimaryType : sHandSecondaryType;
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
            Bool bUsePrimary = (sPrimaryItemActionType != sActionNoneType && GetManagers()->GetItemManager()->IsItemShield(primaryItemIndex));
            const String sActionTypeToUse = (bUsePrimary) ? sPrimaryItemActionType : sSecondaryItemActionType;
            const String sHandTypeToUse = (bUsePrimary) ? sHandPrimaryType : sHandSecondaryType;
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

};
