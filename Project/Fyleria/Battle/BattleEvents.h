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
void HandleBattleStarted(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);
void HandleBattleEnded(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);
void HandleBattleTally(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);
void HandleBattleFullyCompleted(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);
void HandleBattleRoundAdvanced(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID);

// Handle giving/taking damage during battle
void HandleBattleGivingDamage(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, Int iAmount);
void HandleBattleTakingDamage(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, Int iAmount);

// Handle choosing/becoming target during battle
void HandleBattleChoosingTargets(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const StringArray& vDestTargets);
void HandleBattleBecomingTarget(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const String& sSourceTarget);

// Handle battle action is initiated/received and finished
void HandleBattleActionAttackSetup(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const CharacterAction& action);
void HandleBattleActionDefendSetup(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const CharacterAction& action);
void HandleBattleActionApplied(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const CharacterAction& action);
void HandleBattleActionFinished(SafeObject<ManagerSet>& pManagerSet, const String& sCharacterID, const CharacterAction& action);

};

#endif
