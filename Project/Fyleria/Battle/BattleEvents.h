// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_H_
#define _GECKO_CHARACTER_H_

#include "Utility/Types.h"
#include "Utility/IndexedString.h"
#include "CharacterAction/CharacterAction.h"

namespace Gecko
{

// Handle battle starts/ends/advances round
void HandleBattleStarted(const IndexedString& sCharacterID);
void HandleBattleEnded(const IndexedString& sCharacterID);
void HandleBattleTally(const IndexedString& sCharacterID);
void HandleBattleFullyCompleted(const IndexedString& sCharacterID);
void HandleBattleRoundAdvanced(const IndexedString& sCharacterID);

// Handle giving/taking damage during battle
void HandleBattleGivingDamage(const IndexedString& sCharacterID, Int iAmount);
void HandleBattleTakingDamage(const IndexedString& sCharacterID, Int iAmount);

// Handle choosing/becoming target during battle
void HandleBattleChoosingTargets(const IndexedString& sCharacterID, const IndexedStringArray& vDestTargets);
void HandleBattleBecomingTarget(const IndexedString& sCharacterID, const IndexedString& sSourceTarget);

// Handle battle action is initiated/received and finished
void HandleBattleActionAttackSetup(const IndexedString& sCharacterID, const CharacterAction& action);
void HandleBattleActionDefendSetup(const IndexedString& sCharacterID, const CharacterAction& action);
void HandleBattleActionApplied(const IndexedString& sCharacterID, const CharacterAction& action);
void HandleBattleActionFinished(const IndexedString& sCharacterID, const CharacterAction& action);

};
