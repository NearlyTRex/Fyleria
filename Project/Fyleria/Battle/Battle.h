// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_BATTLE_H_
#define _GECKO_BATTLE_H_

#include "CharacterAction/CharacterAction.h"
#include "Module/ModuleResultManager.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

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
    Bool IsBattleOver(const IndexedString& sPartyID) const;
    MAKE_MODULE_RESULT_VARIANT_A1(IsBattleOver, const IndexedString&, sPartyID);

    // Determine if battle is won
    Bool IsBattleWon() const;
    MAKE_MODULE_RESULT_VARIANT(IsBattleWon);

    // Determine if battle is lost
    Bool IsBattleLost() const;
    MAKE_MODULE_RESULT_VARIANT(IsBattleLost);

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
    MAKE_MODULE_RESULT_VARIANT_A1(GetAction, Int, iIndex);

    // Get current action
    const CharacterAction& GetCurrentAction() const;
    CharacterAction& GetCurrentAction();
    MAKE_MODULE_RESULT_VARIANT(GetCurrentAction);

    // Are all actions finished
    Bool AreAllActionsFinished() const;
    MAKE_MODULE_RESULT_VARIANT(AreAllActionsFinished);

    // Battle status
    MAKE_RAW_BASIC_TYPE_ACCESSORS(IsBattleStarted, Bool);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(IsBattleFinished, Bool);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(IsBattleManuallyWon, Bool);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(IsBattleManuallyLost, Bool);

    // Current action/round
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CurrentActionIndex, Int);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CurrentRoundIndex, Int);

    // Actions
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Actions, CharacterActionArray);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ActionCount, Int);

    // Party names
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(EnemyPartyID, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(AllyPartyID, IndexedString);
};

// Typedef
MAKE_TYPE_TYPEDEFS(Battle);

// JSON Converters
void to_json(Json& jsonData, const Battle& obj);
void from_json(const Json& jsonData, Battle& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(Battle, Battle);

};

#endif
