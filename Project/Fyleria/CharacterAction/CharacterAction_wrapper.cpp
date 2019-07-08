// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "CharacterAction/CharacterAction.h"
#include "CharacterAction/CharacterActionResult.h"
#include "Utility/Macros.h"
#include "Utility/Python.h"

PYBIND11_MAKE_OPAQUE(Gecko::CharacterActionResultArray);
PYBIND11_MAKE_OPAQUE(Gecko::CharacterActionEntryArray);
PYBIND11_MAKE_OPAQUE(Gecko::CharacterActionArray);

PYBIND11_EMBEDDED_MODULE(GeckoCharacterAction, m)
{
    // CharacterActionResult.h
    PyBindClass<Gecko::CharacterActionResult>(m, "CharacterActionResult")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FinalDamage, Gecko::CharacterActionResult)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(HasTargetDefendedSuccessfully, Gecko::CharacterActionResult)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(HaveMultipleAttacksSucceeded, Gecko::CharacterActionResult)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(NumAttacksOnTarget, Gecko::CharacterActionResult)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(IndividualAttackIsCriticalCausedArray, Gecko::CharacterActionResult)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(IndividualAttackIsCriticalBlockedArray, Gecko::CharacterActionResult)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(IndividualAttackTargetDamageArray, Gecko::CharacterActionResult)
    ;
    PyBindVector<Gecko::CharacterActionResultArray>(m, "CharacterActionResultArray");

    // CharacterActionEntry.h
    PyBindClass<Gecko::CharacterActionEntry>(m, "CharacterActionEntry")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ActionTypes, Gecko::CharacterActionEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(HandType, Gecko::CharacterActionEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(IsHandTypeShield, Gecko::CharacterActionEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(DestinationTargetType, Gecko::CharacterActionEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(DestinationCharacterIDs, Gecko::CharacterActionEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(Results, Gecko::CharacterActionEntry)
    ;
    PyBindVector<Gecko::CharacterActionEntryArray>(m, "CharacterActionEntryArray");

    // CharacterAction.h
    PyBindClass<Gecko::CharacterAction>(m, "CharacterAction")
        WRAPPING_ADD_METHOD_SIMPLE(GetAllCharacterIDs, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(GetAllActionTypes, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(GetAllDestinationTargetTypes, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(AreAllCharacterIDsValid, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(PrepareCharacterIDs, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(RunType, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Order, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(CostAP, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(CostHP, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(CostMP, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(CostEP, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(WeaponSet, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(PreviousActionTypes, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SkillTreeIndex, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ItemTreeIndex, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(ItemAmount, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SourceTargetType, Gecko::CharacterAction)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SourceCharacterID, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(GetAllCharacterIDs_StoreResult, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(GetAllActionTypes_StoreResult, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(GetAllDestinationTargetTypes_StoreResult, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(AreAllCharacterIDsValid_StoreResult, Gecko::CharacterAction)
        WRAPPING_ADD_METHOD_SIMPLE(PrepareCharacterIDs_StoreResult, Gecko::CharacterAction)
    ;
    PyBindVector<Gecko::CharacterActionArray>(m, "CharacterActionArray");
}
