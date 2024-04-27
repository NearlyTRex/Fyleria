// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_BATTLE_BATTLE_H_
#define _GECKO_BATTLE_BATTLE_H_

// Internal includes
#include "CharacterAction/CharacterAction.h"
#include "CharacterActionHandler/CharacterActionHandlerSkillAttack.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

// Battle
class Battle
{
public:

    // Constructors
    Battle();
    Battle(const Json& jsonData);

    // Clear all data
    void Clear();

    // Start/end battle
    void Start();
    void Finish();

    // Advance the round
    void AdvanceRound();

    // Determine if battle is over
    Bool IsBattleOver(const String& sPartyID) const;

    // Determine if battle is won
    Bool IsBattleWon() const;

    // Determine if battle is lost
    Bool IsBattleLost() const;

    // Determine if action is skill attack
    Bool IsSkillAttackAction(const CharacterAction& action) const;

    // Adding and processing actions that are chosen by the player
    void AddAction(const CharacterAction& action);
    void ClearAllActions();
    void FinishedAddingActions();

    // Action stages
    void RunCurrentActionSetup();
    void RunCurrentActionFinish();
    void RunCurrentActionGenerateResult();
    void RunCurrentActionApplyResult();
    void FinishedWithCurrentAction();

    // Get action
    const CharacterAction& GetAction(Int iIndex) const;
    CharacterAction& GetAction(Int iIndex);

    // Get current action
    const CharacterAction& GetCurrentAction() const;
    CharacterAction& GetCurrentAction();

    // Are all actions finished
    Bool AreAllActionsFinished() const;

    // Battle status
    MAKE_RAW_TYPE_ACCESSORS(IsBattleStarted, Bool);
    MAKE_RAW_TYPE_ACCESSORS(IsBattleFinished, Bool);
    MAKE_RAW_TYPE_ACCESSORS(IsBattleManuallyWon, Bool);
    MAKE_RAW_TYPE_ACCESSORS(IsBattleManuallyLost, Bool);

    // Current action/round
    MAKE_RAW_TYPE_ACCESSORS(CurrentActionIndex, Int);
    MAKE_RAW_TYPE_ACCESSORS(CurrentRoundIndex, Int);

    // Actions
    MAKE_RAW_TYPE_ACCESSORS(Actions, CharacterActionArray);
    MAKE_RAW_TYPE_ACCESSORS(ActionCount, Int);

    // Party IDs
    MAKE_RAW_TYPE_ACCESSORS(EnemyPartyID, String);
    MAKE_RAW_TYPE_ACCESSORS(AllyPartyID, String);

    // Action handlers
    MAKE_RAW_TYPE_ACCESSORS(SkillAttackHandler, CharacterActionHandlerSkillAttack);
};

// Typedef
MAKE_COMMON_TYPEDEFS(Battle);

// JSON Converters
void to_json(Json& jsonData, const Battle& obj);
void from_json(const Json& jsonData, Battle& obj);

};

#endif
