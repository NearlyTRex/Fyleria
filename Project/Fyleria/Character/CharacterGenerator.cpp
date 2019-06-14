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
    // Basics
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
    // Meters
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
    // Attack and Defense Scoring
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
    // Combat Skills
    SetBarbarianRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBarbarianRankEnd(GetRandomIntValue<UByte>(GetBarbarianRankStart() + 1, DEFAULT_MAX_RANK));
    SetMageRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetMageRankEnd(GetRandomIntValue<UByte>(GetMageRankStart() + 1, DEFAULT_MAX_RANK));
    SetRogueRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetRogueRankEnd(GetRandomIntValue<UByte>(GetRogueRankStart() + 1, DEFAULT_MAX_RANK));
    SetBlademasterRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBlademasterRankEnd(GetRandomIntValue<UByte>(GetBlademasterRankStart() + 1, DEFAULT_MAX_RANK));
    SetAvatarRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetAvatarRankEnd(GetRandomIntValue<UByte>(GetAvatarRankStart() + 1, DEFAULT_MAX_RANK));
    SetAmbidextrousRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetAmbidextrousRankEnd(GetRandomIntValue<UByte>(GetAmbidextrousRankStart() + 1, DEFAULT_MAX_RANK));
    SetFocusedRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetFocusedRankEnd(GetRandomIntValue<UByte>(GetFocusedRankStart() + 1, DEFAULT_MAX_RANK));
    SetStalwartRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetStalwartRankEnd(GetRandomIntValue<UByte>(GetStalwartRankStart() + 1, DEFAULT_MAX_RANK));

    // Weapon Skills
    SetSlashRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSlashRankEnd(GetRandomIntValue<UByte>(GetSlashRankStart() + 1, DEFAULT_MAX_RANK));
    SetSeverRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSeverRankEnd(GetRandomIntValue<UByte>(GetSeverRankStart() + 1, DEFAULT_MAX_RANK));
    SetSliceRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSliceRankEnd(GetRandomIntValue<UByte>(GetSliceRankStart() + 1, DEFAULT_MAX_RANK));
    SetSlitRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSlitRankEnd(GetRandomIntValue<UByte>(GetSlitRankStart() + 1, DEFAULT_MAX_RANK));
    SetCleaveRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetCleaveRankEnd(GetRandomIntValue<UByte>(GetCleaveRankStart() + 1, DEFAULT_MAX_RANK));
    SetDecapitateRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetDecapitateRankEnd(GetRandomIntValue<UByte>(GetDecapitateRankStart() + 1, DEFAULT_MAX_RANK));
    SetParryRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetParryRankEnd(GetRandomIntValue<UByte>(GetParryRankStart() + 1, DEFAULT_MAX_RANK));
    SetRiposteRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetRiposteRankEnd(GetRandomIntValue<UByte>(GetRiposteRankStart() + 1, DEFAULT_MAX_RANK));
    SetBashRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBashRankEnd(GetRandomIntValue<UByte>(GetBashRankStart() + 1, DEFAULT_MAX_RANK));
    SetSmashRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSmashRankEnd(GetRandomIntValue<UByte>(GetSmashRankStart() + 1, DEFAULT_MAX_RANK));
    SetCrushRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetCrushRankEnd(GetRandomIntValue<UByte>(GetCrushRankStart() + 1, DEFAULT_MAX_RANK));
    SetImpactRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetImpactRankEnd(GetRandomIntValue<UByte>(GetImpactRankStart() + 1, DEFAULT_MAX_RANK));
    SetBreakRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBreakRankEnd(GetRandomIntValue<UByte>(GetBreakRankStart() + 1, DEFAULT_MAX_RANK));
    SetCrackRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetCrackRankEnd(GetRandomIntValue<UByte>(GetCrackRankStart() + 1, DEFAULT_MAX_RANK));
    SetBlockRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBlockRankEnd(GetRandomIntValue<UByte>(GetBlockRankStart() + 1, DEFAULT_MAX_RANK));
    SetRushRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetRushRankEnd(GetRandomIntValue<UByte>(GetRushRankStart() + 1, DEFAULT_MAX_RANK));
    SetPierceRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetPierceRankEnd(GetRandomIntValue<UByte>(GetPierceRankStart() + 1, DEFAULT_MAX_RANK));
    SetDrillRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetDrillRankEnd(GetRandomIntValue<UByte>(GetDrillRankStart() + 1, DEFAULT_MAX_RANK));
    SetShootRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetShootRankEnd(GetRandomIntValue<UByte>(GetShootRankStart() + 1, DEFAULT_MAX_RANK));
    SetImpaleRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetImpaleRankEnd(GetRandomIntValue<UByte>(GetImpaleRankStart() + 1, DEFAULT_MAX_RANK));
    SetStealthStrikeRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetStealthStrikeRankEnd(GetRandomIntValue<UByte>(GetStealthStrikeRankStart() + 1, DEFAULT_MAX_RANK));
    SetCriticalShotRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetCriticalShotRankEnd(GetRandomIntValue<UByte>(GetCriticalShotRankStart() + 1, DEFAULT_MAX_RANK));
    SetDodgeRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetDodgeRankEnd(GetRandomIntValue<UByte>(GetDodgeRankStart() + 1, DEFAULT_MAX_RANK));
    SetCounterRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetCounterRankEnd(GetRandomIntValue<UByte>(GetCounterRankStart() + 1, DEFAULT_MAX_RANK));

    // Alchemy Skills
    SetHealerRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetHealerRankEnd(GetRandomIntValue<UByte>(GetHealerRankStart() + 1, DEFAULT_MAX_RANK));
    SetAlchemistRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetAlchemistRankEnd(GetRandomIntValue<UByte>(GetAlchemistRankStart() + 1, DEFAULT_MAX_RANK));
    SetEnergistRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetEnergistRankEnd(GetRandomIntValue<UByte>(GetEnergistRankStart() + 1, DEFAULT_MAX_RANK));
    SetChemistRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetChemistRankEnd(GetRandomIntValue<UByte>(GetChemistRankStart() + 1, DEFAULT_MAX_RANK));

    // Crafting Skills
    SetHammersmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetHammersmithRankEnd(GetRandomIntValue<UByte>(GetHammersmithRankStart() + 1, DEFAULT_MAX_RANK));
    SetSpellsmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSpellsmithRankEnd(GetRandomIntValue<UByte>(GetSpellsmithRankStart() + 1, DEFAULT_MAX_RANK));
    SetBowsmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBowsmithRankEnd(GetRandomIntValue<UByte>(GetBowsmithRankStart() + 1, DEFAULT_MAX_RANK));
    SetSwordsmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSwordsmithRankEnd(GetRandomIntValue<UByte>(GetSwordsmithRankStart() + 1, DEFAULT_MAX_RANK));
    SetWeaverRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetWeaverRankEnd(GetRandomIntValue<UByte>(GetWeaverRankStart() + 1, DEFAULT_MAX_RANK));
    SetTannerRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetTannerRankEnd(GetRandomIntValue<UByte>(GetTannerRankStart() + 1, DEFAULT_MAX_RANK));
    SetScalesmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetScalesmithRankEnd(GetRandomIntValue<UByte>(GetScalesmithRankStart() + 1, DEFAULT_MAX_RANK));
    SetPlatesmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetPlatesmithRankEnd(GetRandomIntValue<UByte>(GetPlatesmithRankStart() + 1, DEFAULT_MAX_RANK));
    SetGoldsmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetGoldsmithRankEnd(GetRandomIntValue<UByte>(GetGoldsmithRankStart() + 1, DEFAULT_MAX_RANK));
    SetShieldsmithRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetShieldsmithRankEnd(GetRandomIntValue<UByte>(GetShieldsmithRankStart() + 1, DEFAULT_MAX_RANK));

    // Breakdown Skills
    SetHammerbaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetHammerbaneRankEnd(GetRandomIntValue<UByte>(GetHammerbaneRankStart() + 1, DEFAULT_MAX_RANK));
    SetSpellbaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSpellbaneRankEnd(GetRandomIntValue<UByte>(GetSpellbaneRankStart() + 1, DEFAULT_MAX_RANK));
    SetBowbaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBowbaneRankEnd(GetRandomIntValue<UByte>(GetBowbaneRankStart() + 1, DEFAULT_MAX_RANK));
    SetSwordbaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetSwordbaneRankEnd(GetRandomIntValue<UByte>(GetSwordbaneRankStart() + 1, DEFAULT_MAX_RANK));
    SetThreadbareRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetThreadbareRankEnd(GetRandomIntValue<UByte>(GetThreadbareRankStart() + 1, DEFAULT_MAX_RANK));
    SetStudRemoverRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetStudRemoverRankEnd(GetRandomIntValue<UByte>(GetStudRemoverRankStart() + 1, DEFAULT_MAX_RANK));
    SetScalebaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetScalebaneRankEnd(GetRandomIntValue<UByte>(GetScalebaneRankStart() + 1, DEFAULT_MAX_RANK));
    SetPlatebaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetPlatebaneRankEnd(GetRandomIntValue<UByte>(GetPlatebaneRankStart() + 1, DEFAULT_MAX_RANK));
    SetGoldbaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetGoldbaneRankEnd(GetRandomIntValue<UByte>(GetGoldbaneRankStart() + 1, DEFAULT_MAX_RANK));
    SetShieldbaneRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetShieldbaneRankEnd(GetRandomIntValue<UByte>(GetShieldbaneRankStart() + 1, DEFAULT_MAX_RANK));

    // Affinity Skills
    SetHolyRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetHolyRankEnd(GetRandomIntValue<UByte>(GetHolyRankStart() + 1, DEFAULT_MAX_RANK));
    SetFireRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetFireRankEnd(GetRandomIntValue<UByte>(GetFireRankStart() + 1, DEFAULT_MAX_RANK));
    SetIceRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetIceRankEnd(GetRandomIntValue<UByte>(GetIceRankStart() + 1, DEFAULT_MAX_RANK));
    SetShockRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetShockRankEnd(GetRandomIntValue<UByte>(GetShockRankStart() + 1, DEFAULT_MAX_RANK));
    SetDarkRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetDarkRankEnd(GetRandomIntValue<UByte>(GetDarkRankStart() + 1, DEFAULT_MAX_RANK));
    SetLightRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetLightRankEnd(GetRandomIntValue<UByte>(GetLightRankStart() + 1, DEFAULT_MAX_RANK));
    SetForceRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetForceRankEnd(GetRandomIntValue<UByte>(GetForceRankStart() + 1, DEFAULT_MAX_RANK));
    SetMindRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetMindRankEnd(GetRandomIntValue<UByte>(GetMindRankStart() + 1, DEFAULT_MAX_RANK));
    SetEarthRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetEarthRankEnd(GetRandomIntValue<UByte>(GetEarthRankStart() + 1, DEFAULT_MAX_RANK));
    SetBloodRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetBloodRankEnd(GetRandomIntValue<UByte>(GetBloodRankStart() + 1, DEFAULT_MAX_RANK));
    SetFleshRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetFleshRankEnd(GetRandomIntValue<UByte>(GetFleshRankStart() + 1, DEFAULT_MAX_RANK));
    SetWindRankStart(GetRandomIntValue<UByte>(1, DEFAULT_MAX_RANK));
    SetWindRankEnd(GetRandomIntValue<UByte>(GetWindRankStart() + 1, DEFAULT_MAX_RANK));
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
