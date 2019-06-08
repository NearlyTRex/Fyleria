// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

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

CharacterBasicData CharacterGenerator::GenerateBasicData(const String& sCharacterID) const
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

String CharacterGenerator::GenerateFirstName() const
{
    return String(GetUseRandomName() ? GenerateRandomFantasyName(GetCapitalizationToken() + GetFirstNamePattern()) : GetFirstName());
}

String CharacterGenerator::GenerateLastName() const
{
    return String(GetUseRandomName() ? GenerateRandomFantasyName(GetCapitalizationToken() + GetLastNamePattern()) : GetLastName());
}

Int CharacterGenerator::GenerateAge() const
{
    return (GetUseRandomAge() ? GetRandomIntValue<Int>(GetAgeStart(), GetAgeEnd()) : GetAge());
}

String CharacterGenerator::GenerateGender() const
{
    return String(GetUseRandomGender() ? GetRandomEnumValue<CharacterGenderType>() : GetGender());
}

String CharacterGenerator::GenerateHair() const
{
    return String(GetUseRandomHair() ? GetRandomEnumValue<CharacterHairType>() : GetHair());
}

String CharacterGenerator::GenerateEyes() const
{
    return String(GetUseRandomEyes() ? GetRandomEnumValue<CharacterEyeType>() : GetEyes());
}

String CharacterGenerator::GenerateHandedness() const
{
    return String(GetUseRandomHandedness() ? GetRandomEnumValue<CharacterHandednessType>() : GetHandedness());
}

String CharacterGenerator::GenerateBaseRace() const
{
    return String(GetUseRandomBaseRace() ? GetRandomEnumValue<CharacterBaseRaceType>() : GetBaseRace());
}

String CharacterGenerator::GenerateTransformedRace() const
{
    return String(GetUseRandomTransformedRace() ? GetRandomEnumValue<CharacterTransformedRaceType>() : GetTransformedRace());
}

String CharacterGenerator::GeneratePowerSet() const
{
    return String(GetUseRandomPowerSet() ? GetRandomEnumValue<CharacterPowerSetType>() : GetPowerSet());
}

void CharacterGenerator::RandomizeBasics()
{
    String sRandomNamePattern = GetRandomNamePattern();
    SetFirstNamePattern(sRandomNamePattern);
    SetLastNamePattern(sRandomNamePattern);
    SetAgeStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetAgeEnd(GetRandomIntValue<Int>(GetAgeEnd() + 1, INT_MAX));
    SetUseRandomName(true);
    SetUseRandomAge(true);
    SetUseRandomGender(true);
    SetUseRandomHair(true);
    SetUseRandomEyes(true);
    SetUseRandomHandedness(true);
    SetUseRandomBaseRace(true);
    SetUseRandomTransformedRace(true);
    SetUseRandomPowerSet(true);
}

void CharacterGenerator::RandomizeMeters()
{
    SetHPStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetHPEnd(GetRandomIntValue<Int>(GetHPStart() + 1, INT_MAX));
    SetMPStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetMPEnd(GetRandomIntValue<Int>(GetMPStart() + 1, INT_MAX));
    SetEPStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetEPEnd(GetRandomIntValue<Int>(GetEPStart() + 1, INT_MAX));
    SetHPRegenStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetHPRegenEnd(GetRandomIntValue<Int>(GetHPRegenStart() + 1, INT_MAX));
    SetMPRegenStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetMPRegenEnd(GetRandomIntValue<Int>(GetMPRegenStart() + 1, INT_MAX));
    SetEPRegenStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetEPRegenEnd(GetRandomIntValue<Int>(GetEPRegenStart() + 1, INT_MAX));
    SetSpeedStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetSpeedEnd(GetRandomIntValue<Int>(GetSpeedStart() + 1, INT_MAX));
}

void CharacterGenerator::RandomizeScoring()
{
    SetBluntATKStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetBluntATKEnd(GetRandomIntValue<Int>(GetBluntATKStart() + 1, INT_MAX));
    SetBluntDEFStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetBluntDEFEnd(GetRandomIntValue<Int>(GetBluntDEFStart() + 1, INT_MAX));
    SetPierceATKStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetPierceATKEnd(GetRandomIntValue<Int>(GetPierceATKStart() + 1, INT_MAX));
    SetPierceDEFStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetPierceDEFEnd(GetRandomIntValue<Int>(GetPierceDEFStart() + 1, INT_MAX));
    SetSlashATKStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetSlashATKEnd(GetRandomIntValue<Int>(GetSlashATKStart() + 1, INT_MAX));
    SetSlashDEFStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetSlashDEFEnd(GetRandomIntValue<Int>(GetSlashDEFStart() + 1, INT_MAX));
    SetEnergyATKStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetEnergyATKEnd(GetRandomIntValue<Int>(GetEnergyATKStart() + 1, INT_MAX));
    SetEnergyDEFStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetEnergyDEFEnd(GetRandomIntValue<Int>(GetEnergyDEFStart() + 1, INT_MAX));
    SetMagicATKStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetMagicATKEnd(GetRandomIntValue<Int>(GetMagicATKStart() + 1, INT_MAX));
    SetMagicDEFStart(GetRandomIntValue<Int>(1, INT_MAX));
    SetMagicDEFEnd(GetRandomIntValue<Int>(GetMagicDEFStart() + 1, INT_MAX));
}

void CharacterGenerator::RandomizeAll()
{
    RandomizeBasics();
    RandomizeMeters();
    RandomizeScoring();
}

MAKE_JSON_BASIC_TYPE_CONVERTERS_IMPL(CharacterGenerator);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterGenerator, CharacterGenerator);

};
