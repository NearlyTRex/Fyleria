// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Stats/StatChange.h"
#include "Stats/StatChangeEntry.h"
#include "Stats/ProlongedStatChange.h"
#include "Stats/StatTypeHolder.h"
#include "Utility/Macros.h"
#include "Utility/Serializable.h"
#include "Utility/Python.h"

PYBIND11_EMBEDDED_MODULE(GeckoStats, m)
{
    // ProlongedStatChange.h
    PyBindClass<Gecko::ProlongedStatChange, Gecko::SerializableToJson>(m, "ProlongedStatChange")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(StatChangeEntry, Gecko::ProlongedStatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Round, Gecko::ProlongedStatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Attack, Gecko::ProlongedStatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Defend, Gecko::ProlongedStatChange)
    ;
    PyBindVector<Gecko::ProlongedStatChangeArray>(m, "ProlongedStatChangeArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertProlongedStatChangeToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertProlongedStatChangeArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetProlongedStatChangeFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetProlongedStatChangeArrayFromJsonString, Gecko);

    // StatTypeHolder.h
    PyBindClass<Gecko::StatTypeHolder>(m, "StatTypeHolder")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(GetBoolStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(GetByteStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(GetShortStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(GetIntStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(GetFloatStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(GetDoubleStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(GetIndexedStringStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(GetIndexedStringArrayStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetBoolStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetByteStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetShortStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetIntStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetFloatStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetDoubleStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetIndexedStringStatValue, Gecko::StatTypeHolder)
        WRAPPING_ADD_METHOD_SIMPLE(SetIndexedStringArrayStatValue, Gecko::StatTypeHolder)
    ;

    // StatChange.h
    PyBindClass<Gecko::StatChange>(m, "StatChange")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(IsActive, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(IsPassive, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(DoesHaveActiveRequirements, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(DoesHaveItemEquippedRequirements, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(DoesHaveItemUsedRequirements, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(DoesHaveAttackRequirements, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(DoesHaveDefendRequirements, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(DoesMeetItemEquippedRequirements, Gecko::StatChange)
        WRAPPING_ADD_METHOD_SIMPLE(DoesMeetItemUsedRequirements, Gecko::StatChange)
        WRAPPING_ADD_METHOD_OVERLOADED_CONST(DoesMeetAttackRequirements, Gecko::StatChange, const Gecko::IndexedStringArray&)
        WRAPPING_ADD_METHOD_OVERLOADED_CONST(DoesMeetAttackRequirements, Gecko::StatChange, const Gecko::IndexedStringArray&, const Gecko::IndexedStringArray&)
        WRAPPING_ADD_METHOD_OVERLOADED_CONST(DoesMeetDefendRequirements, Gecko::StatChange, const Gecko::IndexedStringArray&)
        WRAPPING_ADD_METHOD_OVERLOADED_CONST(DoesMeetDefendRequirements, Gecko::StatChange, const Gecko::IndexedStringArray&, const Gecko::IndexedStringArray&)
        WRAPPING_ADD_METHOD_SIMPLE(GetResolvedCharacterArrays, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SkillTreeIndex, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ItemTreeIndex, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(ChanceToApply, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(RoundAmount, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(AttackAmount, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(DefendAmount, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredItemEquippedTypesOR, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredItemEquippedTypesAND, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredItemUsedTypesOR, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredItemUsedTypesAND, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredAttackTypesOR, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredAttackTypesAND, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredDefendTypesOR, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredDefendTypesAND, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredPreviousAttackTypesOR, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredPreviousAttackTypesAND, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredPreviousDefendTypesOR, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredPreviousDefendTypesAND, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredEquippedWeaponCount, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(RequiredEquippedShieldCount, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(DestinationIsSource, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SourceTargetType, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(DestinationTargetType, Gecko::StatChange)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(StatChangeEntries, Gecko::StatChange)
    ;
    PyBindVector<Gecko::StatChangeArray>(m, "StatChangeArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertStatChangeToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertStatChangeArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetStatChangeFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetStatChangeArrayFromJsonString, Gecko);

    // StatChangeEntry.h
    PyBindClass<Gecko::StatChangeEntry>(m, "StatChangeEntry")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Round, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Attack, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Defend, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(DeltaFloat, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(DeltaInt, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FullPercent, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FullFloat, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FullInt, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FullBool, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(FullString, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(FullFloatArray, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(FullIntArray, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(FullBoolArray, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(FullStringArray, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(OperationType, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SourceStatType, Gecko::StatChangeEntry)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(DestinationStatType, Gecko::StatChangeEntry)
    ;
    PyBindVector<Gecko::StatChangeEntryArray>(m, "StatChangeEntryArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertStatChangeEntryToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertStatChangeEntryArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetStatChangeEntryFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetStatChangeEntryArrayFromJsonString, Gecko);

    // StatChange.h
    WRAPPING_STANDALONE_METHOD_POLICY(GetStatChangesFromTreeIndex, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_POLICY(GetStatChangesFromSkillTreeIndex, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_POLICY(GetStatChangesFromItemTreeIndex, Gecko, PyBindReturnCopy);
}
