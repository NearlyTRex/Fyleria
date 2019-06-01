// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Battle/Battle.h"
#include "Battle/BattleEvents.h"
#include "Battle/BattleManager.h"
#include "Utility/Macros.h"
#include "Utility/Python.h"

namespace Gecko
{

SafePtr<BattleManager>& GetBattleManager() { return BattleManager::GetInstance(); }

};

PYBIND11_EMBEDDED_MODULE(GeckoBattle, m)
{
    // Battle.h
    PyBindClass<Gecko::Battle>(m, "Battle")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(Start, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(Finish, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(AdvanceRound, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(IsBattleOver, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(IsBattleWon, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(IsBattleLost, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(AddAction, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(ClearAllActions, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(FinishedAddingActions, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(RunCurrentActionSetup, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(RunCurrentActionFinish, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(RunCurrentActionGenerateResult, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(RunCurrentActionApplyResult, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(FinishedWithCurrentAction, Gecko::Battle)
        WRAPPING_ADD_METHOD_OVERLOADED(GetAction, Gecko::Battle, Gecko::Int)
        WRAPPING_ADD_METHOD_OVERLOADED_CONST(GetAction, Gecko::Battle, Gecko::Int)
        WRAPPING_ADD_METHOD_OVERLOADED_CONST(GetCurrentAction, Gecko::Battle, )
        WRAPPING_ADD_METHOD_OVERLOADED(GetCurrentAction, Gecko::Battle, )
        WRAPPING_ADD_METHOD_SIMPLE(AreAllActionsFinished, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(IsBattleStarted, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(IsBattleFinished, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(IsBattleManuallyWon, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(IsBattleManuallyLost, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(CurrentActionIndex, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(CurrentRoundIndex, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(Actions, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ActionCount, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(EnemyPartyID, Gecko::Battle)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(AllyPartyID, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(IsBattleOver_StoreResult, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(IsBattleWon_StoreResult, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(IsBattleLost_StoreResult, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(GetAction_StoreResult, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(GetCurrentAction_StoreResult, Gecko::Battle)
        WRAPPING_ADD_METHOD_SIMPLE(AreAllActionsFinished_StoreResult, Gecko::Battle)
    ;
    PyBindVector<Gecko::BattleArray>(m, "BattleArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertBattleToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertBattleArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetBattleFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetBattleArrayFromJsonString, Gecko);

    // BattleEvents.h
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleStarted, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleEnded, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleTally, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleFullyCompleted, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleRoundAdvanced, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleGivingDamage, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleTakingDamage, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleChoosingTargets, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleBecomingTarget, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleActionAttackSetup, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleActionDefendSetup, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleActionApplied, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(HandleBattleActionFinished, Gecko);

    // BattleManager.h
    PyBindClass<Gecko::BattleManager>(m, "BattleManager")
        WRAPPING_ADD_METHOD_SIMPLE(CreateBattle, Gecko::BattleManager)
        WRAPPING_ADD_METHOD_SIMPLE(UnloadBattle, Gecko::BattleManager)
        WRAPPING_ADD_METHOD_SIMPLE(DoesBattleExist, Gecko::BattleManager)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(CurrentBattleID, Gecko::BattleManager)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetBattle, Gecko::BattleManager, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetBattle, Gecko::BattleManager, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetCurrentBattle, Gecko::BattleManager, PyBindReturnCopy, )
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetCurrentBattle, Gecko::BattleManager, PyBindReturnRefInternal, )
        WRAPPING_ADD_METHOD_SIMPLE(DoesBattleExist_StoreResult, Gecko::BattleManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetBattle_StoreResult, Gecko::BattleManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetCurrentBattle_StoreResult, Gecko::BattleManager)
    ;

    // Local
    WRAPPING_STANDALONE_METHOD_POLICY(GetBattleManager, Gecko, PyBindReturnCopy);
}
