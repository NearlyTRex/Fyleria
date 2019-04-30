// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Battle/BattleEvents.h"
#include "Character/CharacterManager.h"

namespace Gecko
{

void HandleBattleStarted(const IndexedString& sCharacterID)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Clear active changes
    character.ClearActiveChanges();

    // Reset prolonged stat changes
    character.GetStatChangeData().SetProlongedStatChanges({});

    // Reset skill tracking
    character.GetSkillUseData().SetSkillUseTrackingMap({});

    // Reset attack/defend counters
    character.GetBattleDataBase().SetAttackCounter(0);
    character.GetBattleDataBase().SetDefendCounter(0);
}

void HandleBattleEnded(const IndexedString& sCharacterID)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Clear active changes
    character.ClearActiveChanges();

    // Reset prolonged stat changes
    character.GetStatChangeData().SetProlongedStatChanges({});

    // Reset attack/defend counters
    character.GetBattleDataBase().SetAttackCounter(0);
    character.GetBattleDataBase().SetDefendCounter(0);
}

void HandleBattleTally(const IndexedString& sCharacterID)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Regenerate character data on the tally screen
    // The calling code should capture the state before and after this
    // then see the difference as something to display to the player
    // We DO
    // - Update skill rankings because they could have used skills
    // - Update available changes because skills could have changed
    // - Update available actions because skills could have changed
    // We DO NOT
    // - Update equipment ratings, because equipment does not change
    // - Update available AP, because you only refill AP when resting
    character.RegenerateCharacterData(
        true, /* bUpdateSkillRankings */
        false, /* bUpdateEquipmentRatings */
        true, /* bUpdateAvailableChanges */
        true, /* bUpdateAvailableActions */
        false /* bUpdateAvailableAP */
    );
}

void HandleBattleFullyCompleted(const IndexedString& sCharacterID)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterProgressData& progressData = character.GetProgressDataSegment(sSegment);
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Finish battle
        battleData.FinishBattle(progressData);
    }

    // Reset skill tracking
    character.GetSkillUseData().SetSkillUseTrackingMap({});
}

void HandleBattleRoundAdvanced(const IndexedString& sCharacterID)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterProgressData& progressData = character.GetProgressDataSegment(sSegment);
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Advance round
        battleData.AdvanceRound(progressData);
    }

    // Remove expired prolonged stat changes
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges();
}

void HandleBattleGivingDamage(const IndexedString& sCharacterID, Int iAmount)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Skip invalid damage
    if(iAmount <= 0)
    {
        return;
    }

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update damage given
        battleData.ApplyGivenDamage(iAmount);
    }

    // Update attack counter
    character.GetBattleDataBase().SetAttackCounter(character.GetBattleDataBase().GetAttackCounter() + 1);

    // Remove expired prolonged stat changes
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges();
}

void HandleBattleTakingDamage(const IndexedString& sCharacterID, Int iAmount)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Skip invalid damage
    if(iAmount <= 0)
    {
        return;
    }

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterProgressData& progressData = character.GetProgressDataSegment(sSegment);
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update damage taken
        progressData.ApplyTakenDamage(iAmount);
        battleData.ApplyTakenDamage(iAmount);

        // Apply new status
        battleData.ApplyNewStatus(progressData);
    }

    // Update defend counter
    character.GetBattleDataBase().SetDefendCounter(character.GetBattleDataBase().GetDefendCounter() + 1);

    // Remove expired prolonged stat changes
    character.GetStatChangeData().RemoveAllExpiredProlongedStatChanges();
}

void HandleBattleChoosingTargets(const IndexedString& sCharacterID, const IndexedStringArray& vDestTargets)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update most recent action targets
        battleData.SetMostRecentActionTargets(vDestTargets);

        // Update attack targets this round
        IndexedStringArray vTargetsThisRound = battleData.GetActionTargetsThisRound();
        vTargetsThisRound.insert(vTargetsThisRound.end(), vDestTargets.begin(), vDestTargets.end());
        battleData.SetActionTargetsThisRound(vTargetsThisRound);
    }
}

void HandleBattleBecomingTarget(const IndexedString& sCharacterID, const IndexedString& sSourceTarget)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Update most recent action source
        battleData.SetMostRecentActionSource(sSourceTarget);

        // Update action sources this round
        battleData.GetActionSourcesThisRound().push_back(sSourceTarget);
    }
}

void HandleBattleActionAttackSetup(const IndexedString& sCharacterID, const CharacterAction& action)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Set targets for this action
        battleData.SetActionTargetsThisAction(battleData.GetMostRecentActionTargets());
        battleData.SetActionSourceThisAction(IndexedString(""));
    }

    // Apply active changes
    character.ApplyActiveChanges(action);
}

void HandleBattleActionDefendSetup(const IndexedString& sCharacterID, const CharacterAction& action)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Set targets for this action
        battleData.SetActionTargetsThisAction({});
        battleData.SetActionSourceThisAction(battleData.GetMostRecentActionSource());
    }

    // Apply active changes
    character.ApplyActiveChanges(action);
}

void HandleBattleActionApplied(const IndexedString& sCharacterID, const CharacterAction& action)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Store previous action types
    character.GetBattleDataBase().SetPreviousActionTypes(action.GetAllActionTypes());
}

void HandleBattleActionFinished(const IndexedString& sCharacterID, const CharacterAction& action)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get character
    Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Update character data across non-active segments
    const IndexedStringArray vSegments = {IndexedString("Base"), IndexedString("Passive")};
    for(const IndexedString& sSegment : vSegments)
    {
        // Get appropriate segments
        CharacterProgressData& progressData = character.GetProgressDataSegment(sSegment);
        CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

        // Apply costs
        progressData.ApplyActionCost(action);

        // If this was a skill action, we should track it
        if(!action.GetSkillTreeIndex().empty())
        {
            character.GetSkillUseData().AddSkillUse(GetSkillType(action.GetSkillTreeIndex()), 1);
        }

        // Apply new status
        battleData.ApplyNewStatus(progressData);

        // Clear action targets
        battleData.SetActionTargetsThisAction({});
        battleData.SetActionSourceThisAction(IndexedString(""));
    }

    // Clear active changes
    character.ClearActiveChanges();
}

};
