// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Battle/BattleEvents.h"
#include "Application/Application.h"

namespace Gecko
{

void HandleBattleStarted(const String& sCharacterID)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Regenerate character data
    character.RegenerateSpecificCharacterData({
        CharacterRegenerationType::CurrentStats,
        CharacterRegenerationType::EquipmentRatings,
        CharacterRegenerationType::AvailableChanges,
        CharacterRegenerationType::AvailableActions
    });

    // Reset prolonged stat changes
    character.GetStatChangeData().SetProlongedStatChanges({});

    // Reset attack/defend counters
    character.GetBattleData().SetAttackCounter(0);
    character.GetBattleData().SetDefendCounter(0);
}

void HandleBattleEnded(const String& sCharacterID)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Regenerate character data
    character.RegenerateSpecificCharacterData({
        CharacterRegenerationType::CurrentStats,
        CharacterRegenerationType::EquipmentRatings,
        CharacterRegenerationType::AvailableChanges,
        CharacterRegenerationType::AvailableActions
    });

    // Reset prolonged stat changes
    character.GetStatChangeData().SetProlongedStatChanges({});

    // Reset attack/defend counters
    character.GetBattleData().SetAttackCounter(0);
    character.GetBattleData().SetDefendCounter(0);
}

void HandleBattleTally(const String& sCharacterID)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Regenerate character data on the tally screen
    // The calling code should capture the state before and after this
    // then see the difference as something to display to the player
    character.RegenerateSpecificCharacterData(IntUnorderedSet({
        CharacterRegenerationType::CurrentStats
    }));
}

void HandleBattleFullyCompleted(const String& sCharacterID)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterBattleData& battleData = character.GetBattleData();

    // Finish battle
    battleData.FinishBattle(sCharacterID);
}

void HandleBattleRoundAdvanced(const String& sCharacterID)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterBattleData& battleData = character.GetBattleData();

    // Advance round
    battleData.AdvanceRound(sCharacterID);

    // Remove expired prolonged stat changes
    Int iCurrentRound = GetManagers()->GetBattleManager()->GetCurrentBattle().GetCurrentRoundIndex();
    Int iCurrentAttack = character.GetBattleData().GetAttackCounter();
    Int iCurrentDefend = character.GetBattleData().GetDefendCounter();
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges(iCurrentRound, iCurrentAttack, iCurrentDefend);
}

void HandleBattleGivingDamage(const String& sCharacterID, Int iAmount)
{
    // Skip invalid damage
    if(iAmount <= 0)
    {
        return;
    }

    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterBattleData& battleData = character.GetBattleData();

    // Update damage given
    battleData.ApplyGivenDamage(iAmount);

    // Update attack counter
    character.GetBattleData().SetAttackCounter(character.GetBattleData().GetAttackCounter() + 1);

    // Remove expired prolonged stat changes
    Int iCurrentRound = GetManagers()->GetBattleManager()->GetCurrentBattle().GetCurrentRoundIndex();
    Int iCurrentAttack = character.GetBattleData().GetAttackCounter();
    Int iCurrentDefend = character.GetBattleData().GetDefendCounter();
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges(iCurrentRound, iCurrentAttack, iCurrentDefend);
}

void HandleBattleTakingDamage(const String& sCharacterID, Int iAmount)
{
    // Skip invalid damage
    if(iAmount <= 0)
    {
        return;
    }

    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterProgressData& progressData = character.GetProgressData();
    CharacterBattleData& battleData = character.GetBattleData();
    CharacterStatusEffectData& statusEffectData = character.GetStatusEffectData();

    // Apply health change
    progressData.ApplyHealthChange(-iAmount);

    // Update damage taken
    battleData.ApplyTakenDamage(iAmount);

    // Update status
    statusEffectData.UpdateStatus(sCharacterID);

    // Update defend counter
    character.GetBattleData().SetDefendCounter(character.GetBattleData().GetDefendCounter() + 1);

    // Remove expired prolonged stat changes
    Int iCurrentRound = GetManagers()->GetBattleManager()->GetCurrentBattle().GetCurrentRoundIndex();
    Int iCurrentAttack = character.GetBattleData().GetAttackCounter();
    Int iCurrentDefend = character.GetBattleData().GetDefendCounter();
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges(iCurrentRound, iCurrentAttack, iCurrentDefend);
}

void HandleBattleChoosingTargets(const String& sCharacterID, const StringArray& vDestTargets)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterBattleData& battleData = character.GetBattleData();

    // Update most recent action targets
    battleData.SetMostRecentActionTargets(vDestTargets);

    // Update attack targets this round
    StringArray vTargetsThisRound = battleData.GetActionTargetsThisRound();
    vTargetsThisRound.insert(vTargetsThisRound.end(), vDestTargets.begin(), vDestTargets.end());
    battleData.SetActionTargetsThisRound(vTargetsThisRound);
}

void HandleBattleBecomingTarget(const String& sCharacterID, const String& sSourceTarget)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterBattleData& battleData = character.GetBattleData();

    // Update most recent action source
    battleData.SetMostRecentActionSource(sSourceTarget);

    // Update action sources this round
    battleData.GetActionSourcesThisRound().push_back(sSourceTarget);
}

void HandleBattleActionAttackSetup(const String& sCharacterID, const CharacterAction& action)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterBattleData& battleData = character.GetBattleData();

    // Set targets for this action
    battleData.SetActionTargetsThisAction(battleData.GetMostRecentActionTargets());
    battleData.SetActionSourceThisAction("");

    // Apply active changes
    character.ApplyActiveChanges(action);
}

void HandleBattleActionDefendSetup(const String& sCharacterID, const CharacterAction& action)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterBattleData& battleData = character.GetBattleData();

    // Set targets for this action
    battleData.SetActionTargetsThisAction({});
    battleData.SetActionSourceThisAction(battleData.GetMostRecentActionSource());

    // Apply active changes
    character.ApplyActiveChanges(action);
}

void HandleBattleActionApplied(const String& sCharacterID, const CharacterAction& action)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Store previous action types
    character.GetBattleData().SetPreviousActionTypes(action.GetAllActionTypes());
}

void HandleBattleActionFinished(const String& sCharacterID, const CharacterAction& action)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterActionData& actionData = character.GetActionData();
    CharacterBattleData& battleData = character.GetBattleData();
    CharacterStatusEffectData& statusEffectData = character.GetStatusEffectData();

    // Apply costs
    actionData.ApplyActionCost(sCharacterID, action);

    // If this was a skill action, we should track it
    if(!action.GetSkillTreeIndex().empty())
    {
        character.GetSkillData().UpdateSkillValue(GetManagers()->GetSkillManager()->GetSkillType(action.GetSkillTreeIndex()), 1);
    }

    // Update status
    statusEffectData.UpdateStatus(sCharacterID);

    // Clear action targets
    battleData.SetActionTargetsThisAction({});
    battleData.SetActionSourceThisAction("");

    // Regenerate character data
    character.RegenerateSpecificCharacterData(IntUnorderedSet({
        CharacterRegenerationType::CurrentStats,
    }));
}

};
