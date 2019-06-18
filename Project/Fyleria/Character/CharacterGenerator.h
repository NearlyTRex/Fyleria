// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_GENERATOR_H_
#define _GECKO_CHARACTER_GENERATOR_H_

#include "CharacterData/CharacterBasicData.h"
#include "CharacterData/CharacterProgressData.h"
#include "CharacterData/CharacterBattleData.h"
#include "CharacterData/CharacterSkillData.h"
#include "Utility/Macros.h"
#include "Utility/Json.h"
#include "Utility/Serializable.h"

namespace Gecko
{

class CharacterGenerator : public SerializableToJson
{
public:

    // Constructors
    CharacterGenerator();
    explicit CharacterGenerator(const Json& jsonData);
    explicit CharacterGenerator(const String& jsonString);

    // Destructor
    virtual ~CharacterGenerator();

    // Generate character data
    CharacterBasicData GenerateBasicData(const String& sCharacterID) const;
    CharacterProgressData GenerateProgressData() const;
    CharacterSkillData GenerateSkillData() const;
    String GenerateFirstName() const;
    String GenerateLastName() const;
    Int GenerateAge() const;
    String GenerateGender() const;
    String GenerateHair() const;
    String GenerateEyes() const;
    String GenerateHandedness() const;
    String GenerateBaseRace() const;
    String GenerateTransformedRace() const;
    String GeneratePowerSet() const;
    String GenerateWeaponSet() const;

    // Randomization
    void RandomizeBasics();
    void RandomizeMeters();
    void RandomizeScoring();
    void RandomizeRanks();
    void RandomizeAll();

    // Basics
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FirstName, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(LastName, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FirstNamePattern, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(LastNamePattern, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Age, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AgeStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AgeEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Gender, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Hair, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Eyes, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Handedness, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BaseRace, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(TransformedRace, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PowerSet, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(WeaponSet, String);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomName, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomAge, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomGender, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomHair, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomEyes, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomHandedness, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomBaseRace, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomTransformedRace, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomPowerSet, Bool);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(UseRandomWeaponSet, Bool);

    // Meters
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HPStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HPEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MPStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MPEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EPStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EPEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HPRegenStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HPRegenEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MPRegenStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MPRegenEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EPRegenStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EPRegenEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SpeedStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SpeedEnd, Int);

    // Attack and Defense Scoring
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BluntATKStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BluntATKEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BluntDEFStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BluntDEFEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PierceATKStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PierceATKEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PierceDEFStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PierceDEFEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlashATKStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlashATKEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlashDEFStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlashDEFEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EnergyATKStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EnergyATKEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EnergyDEFStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EnergyDEFEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MagicATKStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MagicATKEnd, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MagicDEFStart, Int);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MagicDEFEnd, Int);

    // Combat Skills
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BarbarianRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BarbarianRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MageRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MageRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(RogueRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(RogueRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BlademasterRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BlademasterRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AvatarRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AvatarRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AmbidextrousRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AmbidextrousRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FocusedRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FocusedRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(StalwartRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(StalwartRankEnd, UByte);

    // Weapon Skills
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlashRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlashRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SeverRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SeverRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SliceRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SliceRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlitRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SlitRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CleaveRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CleaveRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DecapitateRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DecapitateRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ParryRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ParryRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(RiposteRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(RiposteRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BashRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BashRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SmashRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SmashRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CrushRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CrushRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ImpactRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ImpactRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BreakRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BreakRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CrackRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CrackRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BlockRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BlockRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(RushRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(RushRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PierceRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PierceRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DrillRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DrillRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShootRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShootRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ImpaleRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ImpaleRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(StealthStrikeRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(StealthStrikeRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CriticalShotRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CriticalShotRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DodgeRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DodgeRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CounterRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(CounterRankEnd, UByte);

    // Alchemy Skills
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HealerRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HealerRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AlchemistRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(AlchemistRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EnergistRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EnergistRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ChemistRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ChemistRankEnd, UByte);

    // Crafting Skills
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HammersmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HammersmithRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SpellsmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SpellsmithRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BowsmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BowsmithRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SwordsmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SwordsmithRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(WeaverRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(WeaverRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(TannerRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(TannerRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ScalesmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ScalesmithRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PlatesmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PlatesmithRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(GoldsmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(GoldsmithRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShieldsmithRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShieldsmithRankEnd, UByte);

    // Breakdown Skills
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HammerbaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HammerbaneRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SpellbaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SpellbaneRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BowbaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BowbaneRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SwordbaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(SwordbaneRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ThreadbareRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ThreadbareRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(StudRemoverRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(StudRemoverRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ScalebaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ScalebaneRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PlatebaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(PlatebaneRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(GoldbaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(GoldbaneRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShieldbaneRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShieldbaneRankEnd, UByte);

    // Affinity Skills
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HolyRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(HolyRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FireRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FireRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(IceRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(IceRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShockRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ShockRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DarkRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(DarkRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(LightRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(LightRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ForceRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(ForceRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MindRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(MindRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EarthRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(EarthRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BloodRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(BloodRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FleshRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(FleshRankEnd, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(WindRankStart, UByte);
    MAKE_JSON_BASIC_TYPE_ACCESSORS(WindRankEnd, UByte);
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterGenerator);

// JSON Converters
MAKE_JSON_OBJ_TYPE_CONVERTERS_DECL(CharacterGenerator);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterGenerator, CharacterGenerator);

};

#endif
