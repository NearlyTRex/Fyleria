// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Character/CharacterGenerator.h"
#include "Character/CharacterTypes.h"
#include "Utility/FantasyName.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterGenerator::CharacterGenerator()
    : SerializableToJson()
{
}

CharacterGenerator::CharacterGenerator(const Json& jsonData)
    : SerializableToJson(jsonData)
{
}

CharacterBasicData CharacterGenerator::GenerateBasicData(const IndexedString& sCharacterID) const
{
    // Create basic data
    CharacterBasicData basicData;

    // Character ID
    basicData.SetCharacterID(sCharacterID);

    // Basic character data
    basicData.SetFirstName(GenerateFirstName());
    basicData.SetLastName(GenerateLastName());
    basicData.SetAge(GenerateAge());
    basicData.SetGender(GenerateGender());
    basicData.SetHair(GenerateHair());
    basicData.SetEyes(GenerateEyes());
    basicData.SetHandedness(GenerateHandedness());
    basicData.SetBaseRace(GenerateBaseRace());
    basicData.SetTransformedRace(GenerateTransformedRace());
    basicData.SetPowerSet(GeneratePowerSet());
    return basicData;
}

CharacterProgressData CharacterGenerator::GenerateProgressData() const
{
    // Create progress data
    CharacterProgressData progressData;

    // Meters
    progressData.SetHealthPointsMax(GetRandomIntValue<Int>(GetHPStart(), GetHPEnd()));
    progressData.SetMagicPointsMax(GetRandomIntValue<Int>(GetMPStart(), GetMPEnd()));
    progressData.SetEnergyPointsMax(GetRandomIntValue<Int>(GetEPStart(), GetEPEnd()));
    progressData.SetHealthPointsCurrent(progressData.GetHealthPointsMax());
    progressData.SetMagicPointsCurrent(progressData.GetMagicPointsMax());
    progressData.SetEnergyPointsCurrent(progressData.GetEnergyPointsMax());
    progressData.SetHealthRegen(GetRandomIntValue<Int>(GetHPRegenStart(), GetHPRegenEnd()));
    progressData.SetMagicRegen(GetRandomIntValue<Int>(GetMPRegenStart(), GetMPRegenEnd()));
    progressData.SetEnergyRegen(GetRandomIntValue<Int>(GetEPRegenStart(), GetEPRegenEnd()));
    progressData.SetSpeed(GetRandomIntValue<Int>(GetSpeedStart(), GetSpeedEnd()));

    // Attack and Defense Scoring
    progressData.SetBluntAttack(GetRandomIntValue<Int>(GetBluntATKStart(), GetBluntATKEnd()));
    progressData.SetBluntDefense(GetRandomIntValue<Int>(GetBluntDEFStart(), GetBluntDEFEnd()));
    progressData.SetPierceAttack(GetRandomIntValue<Int>(GetPierceATKStart(), GetPierceATKEnd()));
    progressData.SetPierceDefense(GetRandomIntValue<Int>(GetPierceDEFStart(), GetPierceDEFEnd()));
    progressData.SetSlashAttack(GetRandomIntValue<Int>(GetSlashATKStart(), GetSlashATKEnd()));
    progressData.SetSlashDefense(GetRandomIntValue<Int>(GetSlashDEFStart(), GetSlashDEFEnd()));
    progressData.SetEnergyAttack(GetRandomIntValue<Int>(GetEnergyATKStart(), GetEnergyATKEnd()));
    progressData.SetEnergyDefense(GetRandomIntValue<Int>(GetEnergyDEFStart(), GetEnergyDEFEnd()));
    progressData.SetMagicAttack(GetRandomIntValue<Int>(GetMagicATKStart(), GetMagicATKEnd()));
    progressData.SetMagicDefense(GetRandomIntValue<Int>(GetMagicDEFStart(), GetMagicDEFEnd()));
    return progressData;
}

IndexedString CharacterGenerator::GenerateFirstName() const
{
    return IndexedString(GetUseRandomName() ? GenerateRandomFantasyName(GetFirstNamePattern()) : GetFirstName());
}

IndexedString CharacterGenerator::GenerateLastName() const
{
    return IndexedString(GetUseRandomName() ? GenerateRandomFantasyName(GetLastNamePattern()) : GetLastName());
}

Int CharacterGenerator::GenerateAge() const
{
    return GetRandomIntValue<Int>(GetAgeStart(), GetAgeEnd());
}

IndexedString CharacterGenerator::GenerateGender() const
{
    return IndexedString(GetUseRandomGender() ? GetRandomEnumValue<CharacterGenderType>() : GetGender());
}

IndexedString CharacterGenerator::GenerateHair() const
{
    return IndexedString(GetUseRandomHair() ? GetRandomEnumValue<CharacterHairType>() : GetHair());
}

IndexedString CharacterGenerator::GenerateEyes() const
{
    return IndexedString(GetUseRandomEyes() ? GetRandomEnumValue<CharacterEyeType>() : GetEyes());
}

IndexedString CharacterGenerator::GenerateHandedness() const
{
    return IndexedString(GetUseRandomHandedness() ? GetRandomEnumValue<CharacterHandednessType>() : GetHandedness());
}

IndexedString CharacterGenerator::GenerateBaseRace() const
{
    return IndexedString(GetUseRandomBaseRace() ? GetRandomEnumValue<CharacterBaseRaceType>() : GetBaseRace());
}

IndexedString CharacterGenerator::GenerateTransformedRace() const
{
    return IndexedString(GetUseRandomTransformedRace() ? GetRandomEnumValue<CharacterTransformedRaceType>() : GetTransformedRace());
}

IndexedString CharacterGenerator::GeneratePowerSet() const
{
    return IndexedString(GetUseRandomPowerSet() ? GetRandomEnumValue<CharacterPowerSetType>() : GetPowerSet());
}

MAKE_JSON_BASIC_TYPE_CONVERTERS_IMPL(CharacterGenerator);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterGenerator, CharacterGenerator);

};
