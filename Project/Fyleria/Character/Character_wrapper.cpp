// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Character/Character.h"
#include "Character/CharacterGenerator.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "Utility/Macros.h"
#include "Utility/Python.h"

namespace Gecko
{

CharacterManager* GetCharacterManager() { return CharacterManager::GetInstance(); }

};

PYBIND11_MAKE_OPAQUE(Gecko::CharacterGeneratorArray);
PYBIND11_MAKE_OPAQUE(Gecko::CharacterArray);

PYBIND11_EMBEDDED_MODULE(GeckoCharacter, m)
{
    // CharacterGenerator.h
    PyBindClass<Gecko::CharacterGenerator, Gecko::SerializableToJson>(m, "CharacterGenerator")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FirstName, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(LastName, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(FirstNamePattern, Gecko::CharacterGenerator)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(LastNamePattern, Gecko::CharacterGenerator)
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
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetProgressSegment, Gecko::Character, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetProgressSegment, Gecko::Character, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetBattleSegment, Gecko::Character, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetBattleSegment, Gecko::Character, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_SIMPLE(GetBoolStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetIntStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetFloatStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetStringStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(GetStringArrayStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(SetBoolStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(SetIntStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(SetFloatStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(SetStringStatValue, Gecko::Character)
        WRAPPING_ADD_METHOD_SIMPLE(SetStringArrayStatValue, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ProgressDataBase, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ProgressDataPassives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ProgressDataActives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BattleDataBase, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BattleDataPassives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BattleDataActives, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(BasicData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ActionData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(ItemData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SkillData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(SkillUseData, Gecko::Character)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(StatChangeData, Gecko::Character)
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
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY(GetCharacter, Gecko::CharacterManager, PyBindReturnRefInternal, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(GetCharacter, Gecko::CharacterManager, PyBindReturnCopy, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_SIMPLE(ApplyStatChange, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(ApplyStatChangeEntry, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, Gecko::Float)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, Gecko::Int)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, Gecko::Bool)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&)
        WRAPPING_ADD_METHOD_OVERLOADED(ApplyStatChangeEntryOperation, Gecko::CharacterManager, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedStringArray&)
        WRAPPING_ADD_METHOD_SIMPLE(DoesStatChangeEntryUseDelta, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsStatFloat, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsStatInt, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsStatBool, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsStatString, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(IsStatStringArray, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetSourceStatChangeEntryValues, Gecko::CharacterManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetDestStatChangeEntryValues, Gecko::CharacterManager)
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
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterProgressStatTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCharacterBattleStatTypeNames, Gecko);
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
    WRAPPING_STANDALONE_METHOD_POLICY(GetCharacterManager, Gecko, PyBindReturnAutoRef);
}
