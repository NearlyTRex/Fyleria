// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_SKILL_DATA_H_
#define _GECKO_CHARACTER_SKILL_DATA_H_

#include "Character/CharacterTypes.h"
#include "Skills/SkillTypes.h"

namespace Gecko
{

class CharacterSkillData
{
public:

    // Types
    typedef BoostAny CharacterSkillFunctionType;
    typedef STDUnorderedMap<IndexedString, CharacterSkillFunctionType, IndexedStringHasher> CharacterSkillFunctionNodeType;
    typedef STDUnorderedMap<IndexedString, CharacterSkillFunctionNodeType, IndexedStringHasher> CharacterSkillFunctionMapType;
    typedef STDUnorderedMap<IndexedString, UInt, IndexedStringHasher> CharacterSkillUseTrackingMapType;

    // Constructors
    CharacterSkillData();
    CharacterSkillData(const Json& jsonData);

    // Setup skill functions
    void SetupSkillFunctions();

    // Clear all data
    void Clear();

    // Set all skill data to a specific value
    void SetAllSkillCurrentValues(UByte uValue);
    void SetAllSkillRankValues(UByte uValue);

    // Update used skills
    void UpdateUsedSkills();

    // Update skill ranking
    Bool UpdateSkillRanking(const IndexedString& sSkillType);

    // Add skill use
    void AddSkillUse(const IndexedString& sSkillType, UInt uNum);

    // Get number of skill uses
    UInt GetSkillUseCount(const IndexedString& sSkillType) const;

    // Get skill Rank/current functions
    const CharacterSkillFunctionNodeType& GetSkillFunctions(const IndexedString& sSkillType) const;
    const CharacterSkillFunctionType& GetSkillFunction(const IndexedString& sSkillType, const IndexedString& sNodeType) const;
    UByteGetFunction GetSkillGetRankFunction(const IndexedString& sSkillType) const;
    UByteSetFunction GetSkillSetRankFunction(const IndexedString& sSkillType) const;
    UByteGetFunction GetSkillGetCurrentFunction(const IndexedString& sSkillType) const;
    UByteSetFunction GetSkillSetCurrentFunction(const IndexedString& sSkillType) const;

    // Skill map
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillFunctionMap, CharacterSkillFunctionMapType);

    // Skill use tracking
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillUseTrackingMap, CharacterSkillUseTrackingMapType);

    // Combat Skills
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BarbarianCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BarbarianRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(MageCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(MageRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RogueCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RogueRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BlademasterCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BlademasterRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AvatarCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AvatarRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AmbidextrousCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AmbidextrousRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FocusedCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FocusedRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(StalwartCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(StalwartRank, UByte);

    // Weapon Skills
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SlashCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SlashRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SeverCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SeverRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SliceCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SliceRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SlitCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SlitRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CleaveCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CleaveRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DecapitateCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DecapitateRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ParryCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ParryRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RiposteCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RiposteRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BashCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BashRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SmashCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SmashRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CrushCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CrushRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ImpactCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ImpactRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BreakCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BreakRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CrackCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CrackRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BlockCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BlockRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RushCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(RushRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(PierceCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(PierceRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DrillCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DrillRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShootCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShootRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ImpaleCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ImpaleRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(StealthStrikeCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(StealthStrikeRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CriticalShotCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CriticalShotRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DodgeCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DodgeRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CounterCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(CounterRank, UByte);

    // Alchemy Skills
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HealerCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HealerRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AlchemistCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AlchemistRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(EnergistCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(EnergistRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ChemistCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ChemistRank, UByte);

    // Crafting Skills
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HammersmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HammersmithRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SpellsmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SpellsmithRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BowsmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BowsmithRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SwordsmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SwordsmithRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(WeaverCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(WeaverRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(TannerCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(TannerRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ScalesmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ScalesmithRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(PlatesmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(PlatesmithRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(GoldsmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(GoldsmithRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShieldsmithCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShieldsmithRank, UByte);

    // Breakdown Skills
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HammerbaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HammerbaneRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SpellbaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SpellbaneRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BowbaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BowbaneRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SwordbaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(SwordbaneRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ThreadbareCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ThreadbareRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(StudRemoverCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(StudRemoverRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ScalebaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ScalebaneRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(PlatebaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(PlatebaneRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(GoldbaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(GoldbaneRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShieldbaneCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShieldbaneRank, UByte);

    // Affinity Skills
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HolyCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(HolyRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FireCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FireRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(IceCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(IceRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShockCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ShockRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DarkCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DarkRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(LightCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(LightRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ForceCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ForceRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(MindCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(MindRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(EarthCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(EarthRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BloodCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(BloodRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FleshCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FleshRank, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(WindCurrent, UByte);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(WindRank, UByte);

    // Comparisons
    Bool operator==(const CharacterSkillData& other) const;
    Bool operator!=(const CharacterSkillData& other) const;
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterSkillData);

// JSON Converters
void to_json(Json& jsonData, const CharacterSkillData& obj);
void from_json(const Json& jsonData, CharacterSkillData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterSkillData, CharacterSkillData);

};

#endif
