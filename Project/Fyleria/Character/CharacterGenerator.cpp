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

CharacterGenerator::CharacterGenerator(const String& jsonString)
    : SerializableToJson(JsonParse(jsonString))
{
}

CharacterBasicData CharacterGenerator::GenerateBasicData(const String& sCharacterID) const
{
    // Create basic data
    CharacterBasicData basicData;
    basicData.Clear();

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
    progressData.Clear();

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

CharacterSkillData CharacterGenerator::GenerateSkillData() const
{
    // Create skill data
    CharacterSkillData skillData;
    skillData.Clear();

    // Combat Skills
    skillData.SetBarbarianRank(GetRandomIntValue<UByte>(GetBarbarianRankStart(), GetBarbarianRankEnd()));
    skillData.SetMageRank(GetRandomIntValue<UByte>(GetMageRankStart(), GetMageRankEnd()));
    skillData.SetRogueRank(GetRandomIntValue<UByte>(GetRogueRankStart(), GetRogueRankEnd()));
    skillData.SetBlademasterRank(GetRandomIntValue<UByte>(GetBlademasterRankStart(), GetBlademasterRankEnd()));
    skillData.SetAvatarRank(GetRandomIntValue<UByte>(GetAvatarRankStart(), GetAvatarRankEnd()));
    skillData.SetAmbidextrousRank(GetRandomIntValue<UByte>(GetAmbidextrousRankStart(), GetAmbidextrousRankEnd()));
    skillData.SetFocusedRank(GetRandomIntValue<UByte>(GetFocusedRankStart(), GetFocusedRankEnd()));
    skillData.SetStalwartRank(GetRandomIntValue<UByte>(GetStalwartRankStart(), GetStalwartRankEnd()));

    // Weapon Skills
    skillData.SetSlashRank(GetRandomIntValue<UByte>(GetSlashRankStart(), GetSlashRankEnd()));
    skillData.SetSeverRank(GetRandomIntValue<UByte>(GetSeverRankStart(), GetSeverRankEnd()));
    skillData.SetSliceRank(GetRandomIntValue<UByte>(GetSliceRankStart(), GetSliceRankEnd()));
    skillData.SetSlitRank(GetRandomIntValue<UByte>(GetSlitRankStart(), GetSlitRankEnd()));
    skillData.SetCleaveRank(GetRandomIntValue<UByte>(GetCleaveRankStart(), GetCleaveRankEnd()));
    skillData.SetDecapitateRank(GetRandomIntValue<UByte>(GetDecapitateRankStart(), GetDecapitateRankEnd()));
    skillData.SetParryRank(GetRandomIntValue<UByte>(GetParryRankStart(), GetParryRankEnd()));
    skillData.SetRiposteRank(GetRandomIntValue<UByte>(GetRiposteRankStart(), GetRiposteRankEnd()));
    skillData.SetBashRank(GetRandomIntValue<UByte>(GetBashRankStart(), GetBashRankEnd()));
    skillData.SetSmashRank(GetRandomIntValue<UByte>(GetSmashRankStart(), GetSmashRankEnd()));
    skillData.SetCrushRank(GetRandomIntValue<UByte>(GetCrushRankStart(), GetCrushRankEnd()));
    skillData.SetImpactRank(GetRandomIntValue<UByte>(GetImpactRankStart(), GetImpactRankEnd()));
    skillData.SetBreakRank(GetRandomIntValue<UByte>(GetBreakRankStart(), GetBreakRankEnd()));
    skillData.SetCrackRank(GetRandomIntValue<UByte>(GetCrackRankStart(), GetCrackRankEnd()));
    skillData.SetBlockRank(GetRandomIntValue<UByte>(GetBlockRankStart(), GetBlockRankEnd()));
    skillData.SetRushRank(GetRandomIntValue<UByte>(GetRushRankStart(), GetRushRankEnd()));
    skillData.SetPierceRank(GetRandomIntValue<UByte>(GetPierceRankStart(), GetPierceRankEnd()));
    skillData.SetDrillRank(GetRandomIntValue<UByte>(GetDrillRankStart(), GetDrillRankEnd()));
    skillData.SetShootRank(GetRandomIntValue<UByte>(GetShootRankStart(), GetShootRankEnd()));
    skillData.SetImpaleRank(GetRandomIntValue<UByte>(GetImpaleRankStart(), GetImpaleRankEnd()));
    skillData.SetStealthStrikeRank(GetRandomIntValue<UByte>(GetStealthStrikeRankStart(), GetStealthStrikeRankEnd()));
    skillData.SetCriticalShotRank(GetRandomIntValue<UByte>(GetCriticalShotRankStart(), GetCriticalShotRankEnd()));
    skillData.SetDodgeRank(GetRandomIntValue<UByte>(GetDodgeRankStart(), GetDodgeRankEnd()));
    skillData.SetCounterRank(GetRandomIntValue<UByte>(GetCounterRankStart(), GetCounterRankEnd()));

    // Alchemy Skills
    skillData.SetHealerRank(GetRandomIntValue<UByte>(GetHealerRankStart(), GetHealerRankEnd()));
    skillData.SetAlchemistRank(GetRandomIntValue<UByte>(GetAlchemistRankStart(), GetAlchemistRankEnd()));
    skillData.SetEnergistRank(GetRandomIntValue<UByte>(GetEnergistRankStart(), GetEnergistRankEnd()));
    skillData.SetChemistRank(GetRandomIntValue<UByte>(GetChemistRankStart(), GetChemistRankEnd()));

    // Crafting Skills
    skillData.SetHammersmithRank(GetRandomIntValue<UByte>(GetHammersmithRankStart(), GetHammersmithRankEnd()));
    skillData.SetSpellsmithRank(GetRandomIntValue<UByte>(GetSpellsmithRankStart(), GetSpellsmithRankEnd()));
    skillData.SetBowsmithRank(GetRandomIntValue<UByte>(GetBowsmithRankStart(), GetBowsmithRankEnd()));
    skillData.SetSwordsmithRank(GetRandomIntValue<UByte>(GetSwordsmithRankStart(), GetSwordsmithRankEnd()));
    skillData.SetWeaverRank(GetRandomIntValue<UByte>(GetWeaverRankStart(), GetWeaverRankEnd()));
    skillData.SetTannerRank(GetRandomIntValue<UByte>(GetTannerRankStart(), GetTannerRankEnd()));
    skillData.SetScalesmithRank(GetRandomIntValue<UByte>(GetScalesmithRankStart(), GetScalesmithRankEnd()));
    skillData.SetPlatesmithRank(GetRandomIntValue<UByte>(GetPlatesmithRankStart(), GetPlatesmithRankEnd()));
    skillData.SetGoldsmithRank(GetRandomIntValue<UByte>(GetGoldsmithRankStart(), GetGoldsmithRankEnd()));
    skillData.SetShieldsmithRank(GetRandomIntValue<UByte>(GetShieldsmithRankStart(), GetShieldsmithRankEnd()));

    // Breakdown Skills
    skillData.SetHammerbaneRank(GetRandomIntValue<UByte>(GetHammerbaneRankStart(), GetHammerbaneRankEnd()));
    skillData.SetSpellbaneRank(GetRandomIntValue<UByte>(GetSpellbaneRankStart(), GetSpellbaneRankEnd()));
    skillData.SetBowbaneRank(GetRandomIntValue<UByte>(GetBowbaneRankStart(), GetBowbaneRankEnd()));
    skillData.SetSwordbaneRank(GetRandomIntValue<UByte>(GetSwordbaneRankStart(), GetSwordbaneRankEnd()));
    skillData.SetThreadbareRank(GetRandomIntValue<UByte>(GetThreadbareRankStart(), GetThreadbareRankEnd()));
    skillData.SetStudRemoverRank(GetRandomIntValue<UByte>(GetStudRemoverRankStart(), GetStudRemoverRankEnd()));
    skillData.SetScalebaneRank(GetRandomIntValue<UByte>(GetScalebaneRankStart(), GetScalebaneRankEnd()));
    skillData.SetPlatebaneRank(GetRandomIntValue<UByte>(GetPlatebaneRankStart(), GetPlatebaneRankEnd()));
    skillData.SetGoldbaneRank(GetRandomIntValue<UByte>(GetGoldbaneRankStart(), GetGoldbaneRankEnd()));
    skillData.SetShieldbaneRank(GetRandomIntValue<UByte>(GetShieldbaneRankStart(), GetShieldbaneRankEnd()));

    // Affinity Skills
    skillData.SetHolyRank(GetRandomIntValue<UByte>(GetHolyRankStart(), GetHolyRankEnd()));
    skillData.SetFireRank(GetRandomIntValue<UByte>(GetFireRankStart(), GetFireRankEnd()));
    skillData.SetIceRank(GetRandomIntValue<UByte>(GetIceRankStart(), GetIceRankEnd()));
    skillData.SetShockRank(GetRandomIntValue<UByte>(GetShockRankStart(), GetShockRankEnd()));
    skillData.SetDarkRank(GetRandomIntValue<UByte>(GetDarkRankStart(), GetDarkRankEnd()));
    skillData.SetLightRank(GetRandomIntValue<UByte>(GetLightRankStart(), GetLightRankEnd()));
    skillData.SetForceRank(GetRandomIntValue<UByte>(GetForceRankStart(), GetForceRankEnd()));
    skillData.SetMindRank(GetRandomIntValue<UByte>(GetMindRankStart(), GetMindRankEnd()));
    skillData.SetEarthRank(GetRandomIntValue<UByte>(GetEarthRankStart(), GetEarthRankEnd()));
    skillData.SetBloodRank(GetRandomIntValue<UByte>(GetBloodRankStart(), GetBloodRankEnd()));
    skillData.SetFleshRank(GetRandomIntValue<UByte>(GetFleshRankStart(), GetFleshRankEnd()));
    skillData.SetWindRank(GetRandomIntValue<UByte>(GetWindRankStart(), GetWindRankEnd()));
    return skillData;
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
    SetAgeStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_AGE));
    SetAgeEnd(GetRandomIntValue<Int>(GetAgeStart() + 1, DEFAULT_MAX_AGE));
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
    SetHPStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_METER));
    SetHPEnd(GetRandomIntValue<Int>(GetHPStart() + 1, DEFAULT_MAX_METER));
    SetMPStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_METER));
    SetMPEnd(GetRandomIntValue<Int>(GetMPStart() + 1, DEFAULT_MAX_METER));
    SetEPStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_METER));
    SetEPEnd(GetRandomIntValue<Int>(GetEPStart() + 1, DEFAULT_MAX_METER));
    SetHPRegenStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_METER));
    SetHPRegenEnd(GetRandomIntValue<Int>(GetHPRegenStart() + 1, DEFAULT_MAX_METER));
    SetMPRegenStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_METER));
    SetMPRegenEnd(GetRandomIntValue<Int>(GetMPRegenStart() + 1, DEFAULT_MAX_METER));
    SetEPRegenStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_METER));
    SetEPRegenEnd(GetRandomIntValue<Int>(GetEPRegenStart() + 1, DEFAULT_MAX_METER));
    SetSpeedStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_METER));
    SetSpeedEnd(GetRandomIntValue<Int>(GetSpeedStart() + 1, DEFAULT_MAX_METER));
}

void CharacterGenerator::RandomizeScoring()
{
    SetBluntATKStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetBluntATKEnd(GetRandomIntValue<Int>(GetBluntATKStart() + 1, DEFAULT_MAX_SCORING));
    SetBluntDEFStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetBluntDEFEnd(GetRandomIntValue<Int>(GetBluntDEFStart() + 1, DEFAULT_MAX_SCORING));
    SetPierceATKStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetPierceATKEnd(GetRandomIntValue<Int>(GetPierceATKStart() + 1, DEFAULT_MAX_SCORING));
    SetPierceDEFStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetPierceDEFEnd(GetRandomIntValue<Int>(GetPierceDEFStart() + 1, DEFAULT_MAX_SCORING));
    SetSlashATKStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetSlashATKEnd(GetRandomIntValue<Int>(GetSlashATKStart() + 1, DEFAULT_MAX_SCORING));
    SetSlashDEFStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetSlashDEFEnd(GetRandomIntValue<Int>(GetSlashDEFStart() + 1, DEFAULT_MAX_SCORING));
    SetEnergyATKStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetEnergyATKEnd(GetRandomIntValue<Int>(GetEnergyATKStart() + 1, DEFAULT_MAX_SCORING));
    SetEnergyDEFStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetEnergyDEFEnd(GetRandomIntValue<Int>(GetEnergyDEFStart() + 1, DEFAULT_MAX_SCORING));
    SetMagicATKStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetMagicATKEnd(GetRandomIntValue<Int>(GetMagicATKStart() + 1, DEFAULT_MAX_SCORING));
    SetMagicDEFStart(GetRandomIntValue<Int>(1, DEFAULT_MAX_SCORING));
    SetMagicDEFEnd(GetRandomIntValue<Int>(GetMagicDEFStart() + 1, DEFAULT_MAX_SCORING));
}

void CharacterGenerator::RandomizeRanks()
{
}

void CharacterGenerator::RandomizeAll()
{
    RandomizeBasics();
    RandomizeMeters();
    RandomizeScoring();
    RandomizeRanks();
}

MAKE_JSON_OBJ_TYPE_CONVERTERS_IMPL(CharacterGenerator);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterGenerator, CharacterGenerator);

};
