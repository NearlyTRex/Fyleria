// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Battle/BattleEvents.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

void HandleBattleStarted(ManagerSet* pManagerSet, const String& sCharacterID)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Clear active changes
    character.ClearActiveChanges();

    // Reset prolonged stat changes
    character.GetStatChangeData().SetProlongedStatChanges({});

    // Reset attack/defend counters
    character.GetBattleData().SetAttackCounter(0);
    character.GetBattleData().SetDefendCounter(0);
}

void HandleBattleEnded(ManagerSet* pManagerSet, const String& sCharacterID)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Clear active changes
    character.ClearActiveChanges();

    // Reset prolonged stat changes
    character.GetStatChangeData().SetProlongedStatChanges({});

    // Reset attack/defend counters
    character.GetBattleData().SetAttackCounter(0);
    character.GetBattleData().SetDefendCounter(0);
}

void HandleBattleTally(ManagerSet* pManagerSet, const String& sCharacterID)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Regenerate character data on the tally screen
    // The calling code should capture the state before and after this
    // then see the difference as something to display to the player
    // We DO
    // - Update available changes because skills could have changed
    // - Update available actions because skills could have changed
    // We DO NOT
    // - Update equipment ratings, because equipment does not change
    // - Update available AP, because you only refill AP when resting
    character.RegenerateCharacterData(
        pManagerSet,
        false, /* bUpdateEquipmentRatings */
        true, /* bUpdateAvailableChanges */
        true, /* bUpdateAvailableActions */
        false /* bUpdateAvailableAP */
    );
}

void HandleBattleFullyCompleted(ManagerSet* pManagerSet, const String& sCharacterID)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Finish battle
        battleData.FinishBattle(pManagerSet, sCharacterID, sSegment);
    }
}

void HandleBattleRoundAdvanced(ManagerSet* pManagerSet, const String& sCharacterID)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Advance round
        battleData.AdvanceRound(pManagerSet, sCharacterID, sSegment);
    }

    // Remove expired prolonged stat changes
    Int iCurrentRound = pManagerSet->GetBattleManager()->GetCurrentBattle().GetCurrentRoundIndex();
    Int iCurrentAttack = character.GetBattleData().GetAttackCounter();
    Int iCurrentDefend = character.GetBattleData().GetDefendCounter();
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges(iCurrentRound, iCurrentAttack, iCurrentDefend);
}

void HandleBattleGivingDamage(ManagerSet* pManagerSet, const String& sCharacterID, Int iAmount)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Skip invalid damage
    if(iAmount <= 0)
    {
        return;
    }

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update damage given
        battleData.ApplyGivenDamage(iAmount);
    }

    // Update attack counter
    character.GetBattleData().SetAttackCounter(character.GetBattleData().GetAttackCounter() + 1);

    // Remove expired prolonged stat changes
    Int iCurrentRound = pManagerSet->GetBattleManager()->GetCurrentBattle().GetCurrentRoundIndex();
    Int iCurrentAttack = character.GetBattleData().GetAttackCounter();
    Int iCurrentDefend = character.GetBattleData().GetDefendCounter();
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges(iCurrentRound, iCurrentAttack, iCurrentDefend);
}

void HandleBattleTakingDamage(ManagerSet* pManagerSet, const String& sCharacterID, Int iAmount)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Skip invalid damage
    if(iAmount <= 0)
    {
        return;
    }

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterProgressData& progressData = character.GetProgressDataSegment(sSegment);
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update damage taken
        progressData.ApplyTakenDamage(iAmount);
        battleData.ApplyTakenDamage(iAmount);

        // Apply new status
        battleData.ApplyNewStatus(pManagerSet, sCharacterID, sSegment);
    }

    // Update defend counter
    character.GetBattleData().SetDefendCounter(character.GetBattleData().GetDefendCounter() + 1);

    // Remove expired prolonged stat changes
    Int iCurrentRound = pManagerSet->GetBattleManager()->GetCurrentBattle().GetCurrentRoundIndex();
    Int iCurrentAttack = character.GetBattleData().GetAttackCounter();
    Int iCurrentDefend = character.GetBattleData().GetDefendCounter();
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges(iCurrentRound, iCurrentAttack, iCurrentDefend);
}

void HandleBattleChoosingTargets(ManagerSet* pManagerSet, const String& sCharacterID, const StringArray& vDestTargets)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update most recent action targets
        battleData.SetMostRecentActionTargets(vDestTargets);

        // Update attack targets this round
        StringArray vTargetsThisRound = battleData.GetActionTargetsThisRound();
        vTargetsThisRound.insert(vTargetsThisRound.end(), vDestTargets.begin(), vDestTargets.end());
        battleData.SetActionTargetsThisRound(vTargetsThisRound);
    }
}

void HandleBattleBecomingTarget(ManagerSet* pManagerSet, const String& sCharacterID, const String& sSourceTarget)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update most recent action source
        battleData.SetMostRecentActionSource(sSourceTarget);

        // Update action sources this round
        battleData.GetActionSourcesThisRound().push_back(sSourceTarget);
    }
}

void HandleBattleActionAttackSetup(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Set targets for this action
        battleData.SetActionTargetsThisAction(battleData.GetMostRecentActionTargets());
        battleData.SetActionSourceThisAction("");
    }

    // Apply active changes
    character.ApplyActiveChanges(pManagerSet, action);
}

void HandleBattleActionDefendSetup(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Set targets for this action
        battleData.SetActionTargetsThisAction({});
        battleData.SetActionSourceThisAction(battleData.GetMostRecentActionSource());
    }

    // Apply active changes
    character.ApplyActiveChanges(pManagerSet, action);
}

void HandleBattleActionApplied(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Store previous action types
    character.GetBattleData().SetPreviousActionTypes(action.GetAllActionTypes());
}

void HandleBattleActionFinished(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Get character
    Character& character = pManagerSet->GetCharacterManager()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const StringArray vSegments = {
        (+CharacterSegmentType::Base)._to_string(),
        (+CharacterSegmentType::Passive)._to_string()
    };
    for(const String& sSegment : vSegments)
    {
        // Get character data
        CharacterActionData& actionData = character.GetActionData();
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Apply costs
        actionData.ApplyActionCost(pManagerSet, sCharacterID, sSegment, action);

        // If this was a skill action, we should track it
        if(!action.GetSkillTreeIndex().empty())
        {
            character.GetSkillData().UpdateSkillValue(pManagerSet->GetSkillManager()->GetSkillType(action.GetSkillTreeIndex()), 1);
        }

        // Apply new status
        battleData.ApplyNewStatus(pManagerSet, sCharacterID, sSegment);

        // Clear action targets
        battleData.SetActionTargetsThisAction({});
        battleData.SetActionSourceThisAction("");
    }

    // Clear active changes
    character.ClearActiveChanges();
}

};
