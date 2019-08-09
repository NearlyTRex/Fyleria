// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BATTLE_EVENTS_H_
#define _GECKO_BATTLE_EVENTS_H_

// Internal includes
#include "Utility/Types.h"
#include "CharacterAction/CharacterAction.h"

namespace Gecko
{

// Manager set
class ManagerSet;

// Handle battle starts/ends/advances round
void HandleBattleStarted(ManagerSet* pManagerSet, const String& sCharacterID);
void HandleBattleEnded(ManagerSet* pManagerSet, const String& sCharacterID);
void HandleBattleTally(ManagerSet* pManagerSet, const String& sCharacterID);
void HandleBattleFullyCompleted(ManagerSet* pManagerSet, const String& sCharacterID);
void HandleBattleRoundAdvanced(ManagerSet* pManagerSet, const String& sCharacterID);

// Handle giving/taking damage during battle
void HandleBattleGivingDamage(ManagerSet* pManagerSet, const String& sCharacterID, Int iAmount);
void HandleBattleTakingDamage(ManagerSet* pManagerSet, const String& sCharacterID, Int iAmount);

// Handle choosing/becoming target during battle
void HandleBattleChoosingTargets(ManagerSet* pManagerSet, const String& sCharacterID, const StringArray& vDestTargets);
void HandleBattleBecomingTarget(ManagerSet* pManagerSet, const String& sCharacterID, const String& sSourceTarget);

// Handle battle action is initiated/received and finished
void HandleBattleActionAttackSetup(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action);
void HandleBattleActionDefendSetup(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action);
void HandleBattleActionApplied(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action);
void HandleBattleActionFinished(ManagerSet* pManagerSet, const String& sCharacterID, const CharacterAction& action);

};

#endif
