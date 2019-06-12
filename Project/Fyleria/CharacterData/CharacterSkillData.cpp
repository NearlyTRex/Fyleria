// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "CharacterData/CharacterSkillData.h"
#include "Utility/Constants.h"

namespace Gecko
{

CharacterSkillData::CharacterSkillData()
{
}

CharacterSkillData::CharacterSkillData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

#define SET_SKILL_FUNCTION_NODE(name)                                                               \
{                                                                                                   \
    CharacterSkillFunctionNodeType node;                                                            \
    node[String("GetRank")] = BoostBind(&CharacterSkillData::Get##name##Rank, this);         \
    node[String("SetRank")] = BoostBind(&CharacterSkillData::Set##name##Rank, this);         \
    node[String("GetCurrent")] = BoostBind(&CharacterSkillData::Get##name##Current, this);   \
    node[String("SetCurrent")] = BoostBind(&CharacterSkillData::Set##name##Current, this);   \
    GetSkillFunctionMap()[String(#name)] = node;                                             \
}

void CharacterSkillData::SetupSkillFunctions()
{
    // Combat Skills
    SET_SKILL_FUNCTION_NODE(Barbarian);
    SET_SKILL_FUNCTION_NODE(Mage);
    SET_SKILL_FUNCTION_NODE(Rogue);
    SET_SKILL_FUNCTION_NODE(Blademaster);
    SET_SKILL_FUNCTION_NODE(Avatar);
    SET_SKILL_FUNCTION_NODE(Ambidextrous);
    SET_SKILL_FUNCTION_NODE(Focused);
    SET_SKILL_FUNCTION_NODE(Stalwart);

    // Weapon Skills
    SET_SKILL_FUNCTION_NODE(Slash);
    SET_SKILL_FUNCTION_NODE(Sever);
    SET_SKILL_FUNCTION_NODE(Slice);
    SET_SKILL_FUNCTION_NODE(Slit);
    SET_SKILL_FUNCTION_NODE(Cleave);
    SET_SKILL_FUNCTION_NODE(Decapitate);
    SET_SKILL_FUNCTION_NODE(Parry);
    SET_SKILL_FUNCTION_NODE(Riposte);
    SET_SKILL_FUNCTION_NODE(Bash);
    SET_SKILL_FUNCTION_NODE(Smash);
    SET_SKILL_FUNCTION_NODE(Impact);
    SET_SKILL_FUNCTION_NODE(Crush);
    SET_SKILL_FUNCTION_NODE(Break);
    SET_SKILL_FUNCTION_NODE(Crack);
    SET_SKILL_FUNCTION_NODE(Block);
    SET_SKILL_FUNCTION_NODE(Rush);
    SET_SKILL_FUNCTION_NODE(Pierce);
    SET_SKILL_FUNCTION_NODE(Drill);
    SET_SKILL_FUNCTION_NODE(Shoot);
    SET_SKILL_FUNCTION_NODE(Impale);
    SET_SKILL_FUNCTION_NODE(StealthStrike);
    SET_SKILL_FUNCTION_NODE(CriticalShot);
    SET_SKILL_FUNCTION_NODE(Dodge);
    SET_SKILL_FUNCTION_NODE(Counter);

    // Alchemy Skills
    SET_SKILL_FUNCTION_NODE(Healer);
    SET_SKILL_FUNCTION_NODE(Alchemist);
    SET_SKILL_FUNCTION_NODE(Energist);
    SET_SKILL_FUNCTION_NODE(Chemist);

    // Crafting Skills
    SET_SKILL_FUNCTION_NODE(Hammersmith);
    SET_SKILL_FUNCTION_NODE(Spellsmith);
    SET_SKILL_FUNCTION_NODE(Bowsmith);
    SET_SKILL_FUNCTION_NODE(Swordsmith);
    SET_SKILL_FUNCTION_NODE(Weaver);
    SET_SKILL_FUNCTION_NODE(Tanner);
    SET_SKILL_FUNCTION_NODE(Scalesmith);
    SET_SKILL_FUNCTION_NODE(Platesmith);
    SET_SKILL_FUNCTION_NODE(Goldsmith);
    SET_SKILL_FUNCTION_NODE(Shieldsmith);

    // Breakdown Skills
    SET_SKILL_FUNCTION_NODE(Hammerbane);
    SET_SKILL_FUNCTION_NODE(Spellbane);
    SET_SKILL_FUNCTION_NODE(Bowbane);
    SET_SKILL_FUNCTION_NODE(Swordbane);
    SET_SKILL_FUNCTION_NODE(Threadbare);
    SET_SKILL_FUNCTION_NODE(StudRemover);
    SET_SKILL_FUNCTION_NODE(Scalebane);
    SET_SKILL_FUNCTION_NODE(Platebane);
    SET_SKILL_FUNCTION_NODE(Goldbane);
    SET_SKILL_FUNCTION_NODE(Shieldbane);

    // Affinity Skills
    SET_SKILL_FUNCTION_NODE(Holy);
    SET_SKILL_FUNCTION_NODE(Fire);
    SET_SKILL_FUNCTION_NODE(Ice);
    SET_SKILL_FUNCTION_NODE(Shock);
    SET_SKILL_FUNCTION_NODE(Dark);
    SET_SKILL_FUNCTION_NODE(Light);
    SET_SKILL_FUNCTION_NODE(Force);
    SET_SKILL_FUNCTION_NODE(Mind);
    SET_SKILL_FUNCTION_NODE(Earth);
    SET_SKILL_FUNCTION_NODE(Blood);
    SET_SKILL_FUNCTION_NODE(Flesh);
    SET_SKILL_FUNCTION_NODE(Wind);
}

void CharacterSkillData::Clear()
{
    SetAllSkillCurrentValues(0);
    SetAllSkillRankValues(0);
    SetSkillUseTrackingMap({});
}

#define CHARACTER_SET_SKILL_VALUE(type, skill, value)                   \
{                                                                       \
    for(auto&& sSkillType : type::_names())                             \
    {                                                                   \
        GetSkillSet##skill##Function(String(sSkillType))(value); \
    }                                                                   \
}

void CharacterSkillData::SetAllSkillCurrentValues(UByte uValue)
{
    CHARACTER_SET_SKILL_VALUE(SkillWeaponType, Current, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAlchemyType, Current, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillBreakdownType, Current, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCombatType, Current, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCraftingType, Current, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAffinityType, Current, uValue);
}

void CharacterSkillData::SetAllSkillRankValues(UByte uValue)
{
    CHARACTER_SET_SKILL_VALUE(SkillWeaponType, Rank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAlchemyType, Rank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillBreakdownType, Rank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCombatType, Rank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCraftingType, Rank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAffinityType, Rank, uValue);
}

void CharacterSkillData::UpdateUsedSkills()
{
    auto& tSkillTracking = GetSkillUseTrackingMap();
    for(auto it = tSkillTracking.begin(); it != tSkillTracking.end(); it++)
    {
        const String& sSkillType = it->first;
        UInt uUseCount = it->second;
        if(sSkillType == "None" || uUseCount == 0)
        {
            continue;
        }

        UpdateSkillRanking(sSkillType);
    }
}

Bool CharacterSkillData::UpdateSkillRanking(const String& sSkillType)
{
    auto GetRank = GetSkillGetRankFunction(sSkillType);
    auto SetRank = GetSkillSetRankFunction(sSkillType);
    auto GetCurrent = GetSkillGetCurrentFunction(sSkillType);
    auto SetCurrent = GetSkillSetCurrentFunction(sSkillType);

    UByte uRank = GetRank();
    if(uRank >= MAX_SKILL_RANK)
    {
        return false;
    }

    UByte uCurrent = GetCurrent();
    SetCurrent(uCurrent + 1);
    if(static_cast<UInt>(uCurrent + 1) >= SKILL_RANK_UPGRADE_AMOUNT)
    {
        SetCurrent(0);
        SetRank(uRank + 1);
    }
    return true;
}

void CharacterSkillData::AddSkillUse(const String& sSkillType, UInt uNum)
{
    auto& tTrackingMap = GetSkillUseTrackingMap();
    if(tTrackingMap.count(sSkillType))
    {
        tTrackingMap[sSkillType] = tTrackingMap[sSkillType] + uNum;
    }
    else
    {
        tTrackingMap[sSkillType] = uNum;
    }
}

UInt CharacterSkillData::GetSkillUseCount(const String& sSkillType) const
{
    auto& tTrackingMap = GetSkillUseTrackingMap();
    auto iSearch = tTrackingMap.find(sSkillType);
    if(iSearch != tTrackingMap.end())
    {
        return iSearch->second;
    }
    return 0;
}

const CharacterSkillData::CharacterSkillFunctionNodeType& CharacterSkillData::GetSkillFunctions(
    const String& sSkillType) const
{
    return GetSkillFunctionMap().at(sSkillType);
}

const CharacterSkillData::CharacterSkillFunctionType& CharacterSkillData::GetSkillFunction(
    const String& sSkillType,
    const String& sNodeType) const
{
    return GetSkillFunctions(sSkillType).at(sNodeType);
}

UByteGetFunction CharacterSkillData::GetSkillGetRankFunction(const String& sSkillType) const
{
    return BoostAnyCast<UByteGetFunction>(GetSkillFunction(sSkillType, String("GetRank")));
}

UByteSetFunction CharacterSkillData::GetSkillSetRankFunction(const String& sSkillType) const
{
    return BoostAnyCast<UByteSetFunction>(GetSkillFunction(sSkillType, String("SetRank")));
}

UByteGetFunction CharacterSkillData::GetSkillGetCurrentFunction(const String& sSkillType) const
{
    return BoostAnyCast<UByteGetFunction>(GetSkillFunction(sSkillType, String("GetCurrent")));
}

UByteSetFunction CharacterSkillData::GetSkillSetCurrentFunction(const String& sSkillType) const
{
    return BoostAnyCast<UByteSetFunction>(GetSkillFunction(sSkillType, String("SetCurrent")));
}

Bool CharacterSkillData::operator==(const CharacterSkillData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterSkillData::operator!=(const CharacterSkillData& other) const
{
    return not operator==(other);
}

void to_json(Json& jsonData, const CharacterSkillData& obj)
{
    // Combat Skills
    SET_JSON_DATA(BarbarianCurrent);
    SET_JSON_DATA(BarbarianRank);
    SET_JSON_DATA(MageCurrent);
    SET_JSON_DATA(MageRank);
    SET_JSON_DATA(RogueCurrent);
    SET_JSON_DATA(RogueRank);
    SET_JSON_DATA(BlademasterCurrent);
    SET_JSON_DATA(BlademasterRank);
    SET_JSON_DATA(AvatarCurrent);
    SET_JSON_DATA(AvatarRank);
    SET_JSON_DATA(AmbidextrousCurrent);
    SET_JSON_DATA(AmbidextrousRank);
    SET_JSON_DATA(FocusedCurrent);
    SET_JSON_DATA(FocusedRank);
    SET_JSON_DATA(StalwartCurrent);
    SET_JSON_DATA(StalwartRank);

    // Weapon Skills
    SET_JSON_DATA(SlashCurrent);
    SET_JSON_DATA(SlashRank);
    SET_JSON_DATA(SeverCurrent);
    SET_JSON_DATA(SeverRank);
    SET_JSON_DATA(SliceCurrent);
    SET_JSON_DATA(SliceRank);
    SET_JSON_DATA(SlitCurrent);
    SET_JSON_DATA(SlitRank);
    SET_JSON_DATA(CleaveCurrent);
    SET_JSON_DATA(CleaveRank);
    SET_JSON_DATA(DecapitateCurrent);
    SET_JSON_DATA(DecapitateRank);
    SET_JSON_DATA(ParryCurrent);
    SET_JSON_DATA(ParryRank);
    SET_JSON_DATA(RiposteCurrent);
    SET_JSON_DATA(RiposteRank);
    SET_JSON_DATA(BashCurrent);
    SET_JSON_DATA(BashRank);
    SET_JSON_DATA(SmashCurrent);
    SET_JSON_DATA(SmashRank);
    SET_JSON_DATA(CrushCurrent);
    SET_JSON_DATA(CrushRank);
    SET_JSON_DATA(ImpactCurrent);
    SET_JSON_DATA(ImpactRank);
    SET_JSON_DATA(BreakCurrent);
    SET_JSON_DATA(BreakRank);
    SET_JSON_DATA(CrackCurrent);
    SET_JSON_DATA(CrackRank);
    SET_JSON_DATA(BlockCurrent);
    SET_JSON_DATA(BlockRank);
    SET_JSON_DATA(RushCurrent);
    SET_JSON_DATA(RushRank);
    SET_JSON_DATA(PierceCurrent);
    SET_JSON_DATA(PierceRank);
    SET_JSON_DATA(DrillCurrent);
    SET_JSON_DATA(DrillRank);
    SET_JSON_DATA(ShootCurrent);
    SET_JSON_DATA(ShootRank);
    SET_JSON_DATA(ImpaleCurrent);
    SET_JSON_DATA(ImpaleRank);
    SET_JSON_DATA(StealthStrikeCurrent);
    SET_JSON_DATA(StealthStrikeRank);
    SET_JSON_DATA(CriticalShotCurrent);
    SET_JSON_DATA(CriticalShotRank);
    SET_JSON_DATA(DodgeCurrent);
    SET_JSON_DATA(DodgeRank);
    SET_JSON_DATA(CounterCurrent);
    SET_JSON_DATA(CounterRank);

    // Alchemy Skills
    SET_JSON_DATA(HealerCurrent);
    SET_JSON_DATA(HealerRank);
    SET_JSON_DATA(AlchemistCurrent);
    SET_JSON_DATA(AlchemistRank);
    SET_JSON_DATA(EnergistCurrent);
    SET_JSON_DATA(EnergistRank);
    SET_JSON_DATA(ChemistCurrent);
    SET_JSON_DATA(ChemistRank);

    // Crafting Skills
    SET_JSON_DATA(HammersmithCurrent);
    SET_JSON_DATA(HammersmithRank);
    SET_JSON_DATA(SpellsmithCurrent);
    SET_JSON_DATA(SpellsmithRank);
    SET_JSON_DATA(BowsmithCurrent);
    SET_JSON_DATA(BowsmithRank);
    SET_JSON_DATA(SwordsmithCurrent);
    SET_JSON_DATA(SwordsmithRank);
    SET_JSON_DATA(WeaverCurrent);
    SET_JSON_DATA(WeaverRank);
    SET_JSON_DATA(TannerCurrent);
    SET_JSON_DATA(TannerRank);
    SET_JSON_DATA(ScalesmithCurrent);
    SET_JSON_DATA(ScalesmithRank);
    SET_JSON_DATA(PlatesmithCurrent);
    SET_JSON_DATA(PlatesmithRank);
    SET_JSON_DATA(GoldsmithCurrent);
    SET_JSON_DATA(GoldsmithRank);
    SET_JSON_DATA(ShieldsmithCurrent);
    SET_JSON_DATA(ShieldsmithRank);

    // Breakdown Skills
    SET_JSON_DATA(HammerbaneCurrent);
    SET_JSON_DATA(HammerbaneRank);
    SET_JSON_DATA(SpellbaneCurrent);
    SET_JSON_DATA(SpellbaneRank);
    SET_JSON_DATA(BowbaneCurrent);
    SET_JSON_DATA(BowbaneRank);
    SET_JSON_DATA(SwordbaneCurrent);
    SET_JSON_DATA(SwordbaneRank);
    SET_JSON_DATA(ThreadbareCurrent);
    SET_JSON_DATA(ThreadbareRank);
    SET_JSON_DATA(StudRemoverCurrent);
    SET_JSON_DATA(StudRemoverRank);
    SET_JSON_DATA(ScalebaneCurrent);
    SET_JSON_DATA(ScalebaneRank);
    SET_JSON_DATA(PlatebaneCurrent);
    SET_JSON_DATA(PlatebaneRank);
    SET_JSON_DATA(GoldbaneCurrent);
    SET_JSON_DATA(GoldbaneRank);
    SET_JSON_DATA(ShieldbaneCurrent);
    SET_JSON_DATA(ShieldbaneRank);

    // Affinity Skills
    SET_JSON_DATA(HolyCurrent);
    SET_JSON_DATA(HolyRank);
    SET_JSON_DATA(FireCurrent);
    SET_JSON_DATA(FireRank);
    SET_JSON_DATA(IceCurrent);
    SET_JSON_DATA(IceRank);
    SET_JSON_DATA(ShockCurrent);
    SET_JSON_DATA(ShockRank);
    SET_JSON_DATA(DarkCurrent);
    SET_JSON_DATA(DarkRank);
    SET_JSON_DATA(LightCurrent);
    SET_JSON_DATA(LightRank);
    SET_JSON_DATA(ForceCurrent);
    SET_JSON_DATA(ForceRank);
    SET_JSON_DATA(MindCurrent);
    SET_JSON_DATA(MindRank);
    SET_JSON_DATA(EarthCurrent);
    SET_JSON_DATA(EarthRank);
    SET_JSON_DATA(BloodCurrent);
    SET_JSON_DATA(BloodRank);
    SET_JSON_DATA(FleshCurrent);
    SET_JSON_DATA(FleshRank);
    SET_JSON_DATA(WindCurrent);
    SET_JSON_DATA(WindRank);
}

void from_json(const Json& jsonData, CharacterSkillData& obj)
{
    // Combat Skills
    SET_OBJ_DATA(BarbarianCurrent, Int, 0);
    SET_OBJ_DATA(BarbarianRank, Int, 0);
    SET_OBJ_DATA(MageCurrent, Int, 0);
    SET_OBJ_DATA(MageRank, Int, 0);
    SET_OBJ_DATA(RogueCurrent, Int, 0);
    SET_OBJ_DATA(RogueRank, Int, 0);
    SET_OBJ_DATA(BlademasterCurrent, Int, 0);
    SET_OBJ_DATA(BlademasterRank, Int, 0);
    SET_OBJ_DATA(AvatarCurrent, Int, 0);
    SET_OBJ_DATA(AvatarRank, Int, 0);
    SET_OBJ_DATA(AmbidextrousCurrent, Int, 0);
    SET_OBJ_DATA(AmbidextrousRank, Int, 0);
    SET_OBJ_DATA(FocusedCurrent, Int, 0);
    SET_OBJ_DATA(FocusedRank, Int, 0);
    SET_OBJ_DATA(StalwartCurrent, Int, 0);
    SET_OBJ_DATA(StalwartRank, Int, 0);

    // Weapon Skills
    SET_OBJ_DATA(SlashCurrent, Int, 0);
    SET_OBJ_DATA(SlashRank, Int, 0);
    SET_OBJ_DATA(SeverCurrent, Int, 0);
    SET_OBJ_DATA(SeverRank, Int, 0);
    SET_OBJ_DATA(SliceCurrent, Int, 0);
    SET_OBJ_DATA(SliceRank, Int, 0);
    SET_OBJ_DATA(SlitCurrent, Int, 0);
    SET_OBJ_DATA(SlitRank, Int, 0);
    SET_OBJ_DATA(CleaveCurrent, Int, 0);
    SET_OBJ_DATA(CleaveRank, Int, 0);
    SET_OBJ_DATA(DecapitateCurrent, Int, 0);
    SET_OBJ_DATA(DecapitateRank, Int, 0);
    SET_OBJ_DATA(ParryCurrent, Int, 0);
    SET_OBJ_DATA(ParryRank, Int, 0);
    SET_OBJ_DATA(RiposteCurrent, Int, 0);
    SET_OBJ_DATA(RiposteRank, Int, 0);
    SET_OBJ_DATA(BashCurrent, Int, 0);
    SET_OBJ_DATA(BashRank, Int, 0);
    SET_OBJ_DATA(SmashCurrent, Int, 0);
    SET_OBJ_DATA(SmashRank, Int, 0);
    SET_OBJ_DATA(CrushCurrent, Int, 0);
    SET_OBJ_DATA(CrushRank, Int, 0);
    SET_OBJ_DATA(ImpactCurrent, Int, 0);
    SET_OBJ_DATA(ImpactRank, Int, 0);
    SET_OBJ_DATA(BreakCurrent, Int, 0);
    SET_OBJ_DATA(BreakRank, Int, 0);
    SET_OBJ_DATA(CrackCurrent, Int, 0);
    SET_OBJ_DATA(CrackRank, Int, 0);
    SET_OBJ_DATA(BlockCurrent, Int, 0);
    SET_OBJ_DATA(BlockRank, Int, 0);
    SET_OBJ_DATA(RushCurrent, Int, 0);
    SET_OBJ_DATA(RushRank, Int, 0);
    SET_OBJ_DATA(PierceCurrent, Int, 0);
    SET_OBJ_DATA(PierceRank, Int, 0);
    SET_OBJ_DATA(DrillCurrent, Int, 0);
    SET_OBJ_DATA(DrillRank, Int, 0);
    SET_OBJ_DATA(ShootCurrent, Int, 0);
    SET_OBJ_DATA(ShootRank, Int, 0);
    SET_OBJ_DATA(ImpaleCurrent, Int, 0);
    SET_OBJ_DATA(ImpaleRank, Int, 0);
    SET_OBJ_DATA(StealthStrikeCurrent, Int, 0);
    SET_OBJ_DATA(StealthStrikeRank, Int, 0);
    SET_OBJ_DATA(CriticalShotCurrent, Int, 0);
    SET_OBJ_DATA(CriticalShotRank, Int, 0);
    SET_OBJ_DATA(DodgeCurrent, Int, 0);
    SET_OBJ_DATA(DodgeRank, Int, 0);
    SET_OBJ_DATA(CounterCurrent, Int, 0);
    SET_OBJ_DATA(CounterRank, Int, 0);

    // Alchemy Skills
    SET_OBJ_DATA(HealerCurrent, Int, 0);
    SET_OBJ_DATA(HealerRank, Int, 0);
    SET_OBJ_DATA(AlchemistCurrent, Int, 0);
    SET_OBJ_DATA(AlchemistRank, Int, 0);
    SET_OBJ_DATA(EnergistCurrent, Int, 0);
    SET_OBJ_DATA(EnergistRank, Int, 0);
    SET_OBJ_DATA(ChemistCurrent, Int, 0);
    SET_OBJ_DATA(ChemistRank, Int, 0);

    // Crafting Skills
    SET_OBJ_DATA(HammersmithCurrent, Int, 0);
    SET_OBJ_DATA(HammersmithRank, Int, 0);
    SET_OBJ_DATA(SpellsmithCurrent, Int, 0);
    SET_OBJ_DATA(SpellsmithRank, Int, 0);
    SET_OBJ_DATA(BowsmithCurrent, Int, 0);
    SET_OBJ_DATA(BowsmithRank, Int, 0);
    SET_OBJ_DATA(SwordsmithCurrent, Int, 0);
    SET_OBJ_DATA(SwordsmithRank, Int, 0);
    SET_OBJ_DATA(WeaverCurrent, Int, 0);
    SET_OBJ_DATA(WeaverRank, Int, 0);
    SET_OBJ_DATA(TannerCurrent, Int, 0);
    SET_OBJ_DATA(TannerRank, Int, 0);
    SET_OBJ_DATA(ScalesmithCurrent, Int, 0);
    SET_OBJ_DATA(ScalesmithRank, Int, 0);
    SET_OBJ_DATA(PlatesmithCurrent, Int, 0);
    SET_OBJ_DATA(PlatesmithRank, Int, 0);
    SET_OBJ_DATA(GoldsmithCurrent, Int, 0);
    SET_OBJ_DATA(GoldsmithRank, Int, 0);
    SET_OBJ_DATA(ShieldsmithCurrent, Int, 0);
    SET_OBJ_DATA(ShieldsmithRank, Int, 0);

    // Breakdown Skills
    SET_OBJ_DATA(HammerbaneCurrent, Int, 0);
    SET_OBJ_DATA(HammerbaneRank, Int, 0);
    SET_OBJ_DATA(SpellbaneCurrent, Int, 0);
    SET_OBJ_DATA(SpellbaneRank, Int, 0);
    SET_OBJ_DATA(BowbaneCurrent, Int, 0);
    SET_OBJ_DATA(BowbaneRank, Int, 0);
    SET_OBJ_DATA(SwordbaneCurrent, Int, 0);
    SET_OBJ_DATA(SwordbaneRank, Int, 0);
    SET_OBJ_DATA(ThreadbareCurrent, Int, 0);
    SET_OBJ_DATA(ThreadbareRank, Int, 0);
    SET_OBJ_DATA(StudRemoverCurrent, Int, 0);
    SET_OBJ_DATA(StudRemoverRank, Int, 0);
    SET_OBJ_DATA(ScalebaneCurrent, Int, 0);
    SET_OBJ_DATA(ScalebaneRank, Int, 0);
    SET_OBJ_DATA(PlatebaneCurrent, Int, 0);
    SET_OBJ_DATA(PlatebaneRank, Int, 0);
    SET_OBJ_DATA(GoldbaneCurrent, Int, 0);
    SET_OBJ_DATA(GoldbaneRank, Int, 0);
    SET_OBJ_DATA(ShieldbaneCurrent, Int, 0);
    SET_OBJ_DATA(ShieldbaneRank, Int, 0);

    // Affinity Skills
    SET_OBJ_DATA(HolyCurrent, Int, 0);
    SET_OBJ_DATA(HolyRank, Int, 0);
    SET_OBJ_DATA(FireCurrent, Int, 0);
    SET_OBJ_DATA(FireRank, Int, 0);
    SET_OBJ_DATA(IceCurrent, Int, 0);
    SET_OBJ_DATA(IceRank, Int, 0);
    SET_OBJ_DATA(ShockCurrent, Int, 0);
    SET_OBJ_DATA(ShockRank, Int, 0);
    SET_OBJ_DATA(DarkCurrent, Int, 0);
    SET_OBJ_DATA(DarkRank, Int, 0);
    SET_OBJ_DATA(LightCurrent, Int, 0);
    SET_OBJ_DATA(LightRank, Int, 0);
    SET_OBJ_DATA(ForceCurrent, Int, 0);
    SET_OBJ_DATA(ForceRank, Int, 0);
    SET_OBJ_DATA(MindCurrent, Int, 0);
    SET_OBJ_DATA(MindRank, Int, 0);
    SET_OBJ_DATA(EarthCurrent, Int, 0);
    SET_OBJ_DATA(EarthRank, Int, 0);
    SET_OBJ_DATA(BloodCurrent, Int, 0);
    SET_OBJ_DATA(BloodRank, Int, 0);
    SET_OBJ_DATA(FleshCurrent, Int, 0);
    SET_OBJ_DATA(FleshRank, Int, 0);
    SET_OBJ_DATA(WindCurrent, Int, 0);
    SET_OBJ_DATA(WindRank, Int, 0);
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterSkillData, CharacterSkillData);

};
