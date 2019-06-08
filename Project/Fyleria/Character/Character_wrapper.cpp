// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Character/Character.h"
#include "Character/CharacterGenerator.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "Utility/Macros.h"
#include "Utility/Python.h"

namespace Gecko
{

SafePtr<CharacterManager>& GetCharacterManager() { return CharacterManager::GetInstance(); }

};

PYBIND11_MAKE_OPAQUE(Gecko::CharacterGeneratorArray);
PYBIND11_MAKE_OPAQUE(Gecko::CharacterArray);

PYBIND11_EMBEDDED_MODULE(GeckoCharacter, m)
{
    // CharacterGenerator.h
    PyBindClass<Gecko::CharacterGenerator, Gecko::SerializableToJson>(m, "CharacterGenerator")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(GenerateBasicData, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateProgressData, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateFirstName, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateLastName, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateAge, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateGender, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateHair, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateEyes, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateHandedness, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateBaseRace, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateTransformedRace, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(GeneratePowerSet, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(RandomizeBasics, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(RandomizeMeters, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(RandomizeScoring, Gecko::CharacterGenerator)
        WRAPPING_ADD_METHOD_SIMPLE(RandomizeAll, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FirstName, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(LastName, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FirstNamePattern, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(LastNamePattern, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Age, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(AgeStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(AgeEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Gender, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Hair, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Eyes, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Handedness, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(BaseRace, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(TransformedRace, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(PowerSet, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomName, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomGender, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomHair, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomEyes, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomHandedness, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomBaseRace, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomTransformedRace, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(UseRandomPowerSet, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(HPStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(HPEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MPStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MPEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EPStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EPEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(HPRegenStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(HPRegenEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MPRegenStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MPRegenEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EPRegenStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EPRegenEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(SpeedStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(SpeedEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(BluntATKStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(BluntATKEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(BluntDEFStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(BluntDEFEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(PierceATKStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(PierceATKEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(PierceDEFStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(PierceDEFEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(SlashATKStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(SlashATKEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(SlashDEFStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(SlashDEFEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EnergyATKStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EnergyATKEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EnergyDEFStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(EnergyDEFEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MagicATKStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MagicATKEnd, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MagicDEFStart, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(MagicDEFEnd, Gecko::CharacterGenerator)
    ;
    PyBindVector<Gecko::CharacterGeneratorArray>(m, "CharacterGeneratorArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterGeneratorToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterGeneratorArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterGeneratorFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterGeneratorArrayFromJsonString, Gecko);

    // Character.h
    PyBindClass<Gecko::Character>(m, "Character")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(RegenerateCharacterData, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetCharacterID, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetPartyID, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetCharacterTargetType, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetCurrentWeaponSet, Gecko::Character)
        WRAPPING_ADD_METHOD_POLICY(GetEquippedItems, Gecko::Character, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_POLICY(GetAvailableActions, Gecko::Character, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_POLICY(GetPassiveChanges, Gecko::Character, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_POLICY(GetActiveChanges, Gecko::Character, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_POLICY(GetActionableChanges, Gecko::Character, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetProgressDataSegment, Gecko::Character, PyBindReturnCopy, const Gecko::String&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetProgressDataSegment, Gecko::Character, PyBindReturnRefInternal, const Gecko::String&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetBattleDataSegment, Gecko::Character, PyBindReturnCopy, const Gecko::String&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetBattleDataSegment, Gecko::Character, PyBindReturnRefInternal, const Gecko::String&)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ProgressDataBase, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ProgressDataPassives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ProgressDataActives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BattleDataBase, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BattleDataPassives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BattleDataActives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BasicData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ActionData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SkillData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(StatChangeData, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetCharacterID_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetPartyID_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetCharacterTargetType_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetCurrentWeaponSet_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetEquippedItems_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetAvailableActions_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetPassiveChanges_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetActiveChanges_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetActionableChanges_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetProgressDataSegment_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetBattleDataSegment_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetProgressDataBase_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetProgressDataPassives_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetProgressDataActives_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetBattleDataBase_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetBattleDataPassives_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetBattleDataActives_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetBasicData_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetActionData_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetSkillData_StoreResult, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetStatChangeData_StoreResult, Gecko::Character)
    ;
    PyBindVector<Gecko::CharacterArray>(m, "CharacterArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterArrayFromJsonString, Gecko);

    // CharacterManager.h
    PyBindClass<Gecko::CharacterManager>(m, "CharacterManager")
        WRAPPING_ADD_METHOD_SIMPLE(LoadCharacter, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(LoadCharacterFromFile, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(SaveCharacterToFile, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(CreateCharacter, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(UnloadCharacter, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(DoesCharacterExist, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(GenerateCharacter, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsValidCharacterID, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetCharacter, Gecko::CharacterManager, PyBindReturnCopy, const Gecko::String&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetCharacter, Gecko::CharacterManager, PyBindReturnRefInternal, const Gecko::String&)
        WRAPPING_ADD_METHOD_SIMPLE(ApplyStatChange, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(ApplyStatChangeEntry, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::String&, const Gecko::String&, const Gecko::String&, const Gecko::String&, Gecko::Float)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::String&, const Gecko::String&, const Gecko::String&, const Gecko::String&, Gecko::Int)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::String&, const Gecko::String&, const Gecko::String&, const Gecko::String&, Gecko::Bool)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::String&, const Gecko::String&, const Gecko::String&, const Gecko::String&, const Gecko::String&)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::String&, const Gecko::String&, const Gecko::String&, const Gecko::String&, const Gecko::StringArray&)
        WRAPPING_ADD_METHOD_SIMPLE(DoesStatChangeEntryUseDelta, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetDeltaStatChangeEntryValues, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetFullStatChangeEntryValues, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(DoesCharacterExist_StoreResult, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsValidCharacterID_StoreResult, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetCharacter_StoreResult, Gecko::CharacterManager)
    ;

    // CharacterTypes.h
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterEquipmentTypeToCharacterWeaponSetType, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertCharacterTargetTypeToCharacterPartyType, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertItemTypeToCharacterActionType, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertItemTypeToCharacterEquipTypes, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillWeaponBaseTypeToCharacterActionType, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillWeaponTypeToCharacterActionType, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterTreeIndexTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterSegmentTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBasicStatType_StringNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBasicStatType_IntNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterProgressStatType_IntNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBattleStatType_StringNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBattleStatType_StringArrayNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBattleStatType_BoolNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBattleStatType_IntNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBattleStatType_FloatNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterStatusTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBaseRaceTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterTransformedRaceTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPowerSetTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterWeaponSetTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterGenderTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterHairTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterEyeTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterHandednessTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterHandTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterEquipmentTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterTargetTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterPartyTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterActionTypeNames, Gecko);

    // Local
    WRAPPING_STANDALONE_METHOD_POLICY(GetCharacterManager, Gecko, PyBindReturnCopy);
}
