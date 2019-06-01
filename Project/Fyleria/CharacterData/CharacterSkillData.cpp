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
    node[IndexedString("GetRank")] = BoostBind(&CharacterSkillData::Get##name##Rank, this);         \
    node[IndexedString("SetRank")] = BoostBind(&CharacterSkillData::Set##name##Rank, this);         \
    node[IndexedString("GetCurrent")] = BoostBind(&CharacterSkillData::Get##name##Current, this);   \
    node[IndexedString("SetCurrent")] = BoostBind(&CharacterSkillData::Set##name##Current, this);   \
    GetSkillFunctionMap()[IndexedString(#name)] = node;                                             \
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
        GetSkillSet##skill##Function(IndexedString(sSkillType))(value); \
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
        const IndexedString& sSkillType = it->first;
        UInt uUseCount = it->second;
        if(sSkillType.IsNone() || uUseCount == 0)
        {
            continue;
        }

        UpdateSkillRanking(sSkillType);
    }
}

Bool CharacterSkillData::UpdateSkillRanking(const IndexedString& sSkillType)
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

void CharacterSkillData::AddSkillUse(const IndexedString& sSkillType, UInt uNum)
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

UInt CharacterSkillData::GetSkillUseCount(const IndexedString& sSkillType) const
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
    const IndexedString& sSkillType) const
{
    return GetSkillFunctionMap().at(sSkillType);
}

const CharacterSkillData::CharacterSkillFunctionType& CharacterSkillData::GetSkillFunction(
    const IndexedString& sSkillType,
    const IndexedString& sNodeType) const
{
    return GetSkillFunctions(sSkillType).at(sNodeType);
}

UByteGetFunction CharacterSkillData::GetSkillGetRankFunction(const IndexedString& sSkillType) const
{
    return BoostAnyCast<UByteGetFunction>(GetSkillFunction(sSkillType, IndexedString("GetRank")));
}

UByteSetFunction CharacterSkillData::GetSkillSetRankFunction(const IndexedString& sSkillType) const
{
    return BoostAnyCast<UByteSetFunction>(GetSkillFunction(sSkillType, IndexedString("SetRank")));
}

UByteGetFunction CharacterSkillData::GetSkillGetCurrentFunction(const IndexedString& sSkillType) const
{
    return BoostAnyCast<UByteGetFunction>(GetSkillFunction(sSkillType, IndexedString("GetCurrent")));
}

UByteSetFunction CharacterSkillData::GetSkillSetCurrentFunction(const IndexedString& sSkillType) const
{
    return BoostAnyCast<UByteSetFunction>(GetSkillFunction(sSkillType, IndexedString("SetCurrent")));
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
    SET_JSON_DATA_IF_NOT_DEFAULT(BarbarianCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BarbarianRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(MageCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(MageRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(RogueCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(RogueRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BlademasterCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BlademasterRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(AvatarCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(AvatarRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(AmbidextrousCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(AmbidextrousRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FocusedCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FocusedRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(StalwartCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(StalwartRank, 0);

    // Weapon Skills
    SET_JSON_DATA_IF_NOT_DEFAULT(SlashCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SlashRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SeverCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SeverRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SliceCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SliceRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SlitCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SlitRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CleaveCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CleaveRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DecapitateCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DecapitateRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ParryCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ParryRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(RiposteCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(RiposteRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BashCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BashRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SmashCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SmashRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CrushCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CrushRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ImpactCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ImpactRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BreakCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BreakRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CrackCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CrackRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BlockCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BlockRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(RushCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(RushRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PierceCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PierceRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DrillCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DrillRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShootCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShootRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ImpaleCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ImpaleRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(StealthStrikeCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(StealthStrikeRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CriticalShotCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CriticalShotRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DodgeCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DodgeRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CounterCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CounterRank, 0);

    // Alchemy Skills
    SET_JSON_DATA_IF_NOT_DEFAULT(HealerCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(HealerRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(AlchemistCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(AlchemistRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(EnergistCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(EnergistRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ChemistCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ChemistRank, 0);

    // Crafting Skills
    SET_JSON_DATA_IF_NOT_DEFAULT(HammersmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(HammersmithRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SpellsmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SpellsmithRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BowsmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BowsmithRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SwordsmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SwordsmithRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(WeaverCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(WeaverRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(TannerCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(TannerRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ScalesmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ScalesmithRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PlatesmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PlatesmithRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(GoldsmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(GoldsmithRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShieldsmithCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShieldsmithRank, 0);

    // Breakdown Skills
    SET_JSON_DATA_IF_NOT_DEFAULT(HammerbaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(HammerbaneRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SpellbaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SpellbaneRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BowbaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BowbaneRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SwordbaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SwordbaneRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ThreadbareCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ThreadbareRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(StudRemoverCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(StudRemoverRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ScalebaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ScalebaneRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PlatebaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PlatebaneRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(GoldbaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(GoldbaneRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShieldbaneCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShieldbaneRank, 0);

    // Affinity Skills
    SET_JSON_DATA_IF_NOT_DEFAULT(HolyCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(HolyRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FireCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FireRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(IceCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(IceRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShockCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ShockRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DarkCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DarkRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(LightCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(LightRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ForceCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(ForceRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(MindCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(MindRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(EarthCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(EarthRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BloodCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(BloodRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FleshCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FleshRank, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(WindCurrent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(WindRank, 0);
}

void from_json(const Json& jsonData, CharacterSkillData& obj)
{
    // Combat Skills
    obj.SetBarbarianCurrent(GET_JSON_DATA_OR_DEFAULT(BarbarianCurrent, Int, 0));
    obj.SetBarbarianRank(GET_JSON_DATA_OR_DEFAULT(BarbarianRank, Int, 0));
    obj.SetMageCurrent(GET_JSON_DATA_OR_DEFAULT(MageCurrent, Int, 0));
    obj.SetMageRank(GET_JSON_DATA_OR_DEFAULT(MageRank, Int, 0));
    obj.SetRogueCurrent(GET_JSON_DATA_OR_DEFAULT(RogueCurrent, Int, 0));
    obj.SetRogueRank(GET_JSON_DATA_OR_DEFAULT(RogueRank, Int, 0));
    obj.SetBlademasterCurrent(GET_JSON_DATA_OR_DEFAULT(BlademasterCurrent, Int, 0));
    obj.SetBlademasterRank(GET_JSON_DATA_OR_DEFAULT(BlademasterRank, Int, 0));
    obj.SetAvatarCurrent(GET_JSON_DATA_OR_DEFAULT(AvatarCurrent, Int, 0));
    obj.SetAvatarRank(GET_JSON_DATA_OR_DEFAULT(AvatarRank, Int, 0));
    obj.SetAmbidextrousCurrent(GET_JSON_DATA_OR_DEFAULT(AmbidextrousCurrent, Int, 0));
    obj.SetAmbidextrousRank(GET_JSON_DATA_OR_DEFAULT(AmbidextrousRank, Int, 0));
    obj.SetFocusedCurrent(GET_JSON_DATA_OR_DEFAULT(FocusedCurrent, Int, 0));
    obj.SetFocusedRank(GET_JSON_DATA_OR_DEFAULT(FocusedRank, Int, 0));
    obj.SetStalwartCurrent(GET_JSON_DATA_OR_DEFAULT(StalwartCurrent, Int, 0));
    obj.SetStalwartRank(GET_JSON_DATA_OR_DEFAULT(StalwartRank, Int, 0));

    // Weapon Skills
    obj.SetSlashCurrent(GET_JSON_DATA_OR_DEFAULT(SlashCurrent, Int, 0));
    obj.SetSlashRank(GET_JSON_DATA_OR_DEFAULT(SlashRank, Int, 0));
    obj.SetSeverCurrent(GET_JSON_DATA_OR_DEFAULT(SeverCurrent, Int, 0));
    obj.SetSeverRank(GET_JSON_DATA_OR_DEFAULT(SeverRank, Int, 0));
    obj.SetSliceCurrent(GET_JSON_DATA_OR_DEFAULT(SliceCurrent, Int, 0));
    obj.SetSliceRank(GET_JSON_DATA_OR_DEFAULT(SliceRank, Int, 0));
    obj.SetSlitCurrent(GET_JSON_DATA_OR_DEFAULT(SlitCurrent, Int, 0));
    obj.SetSlitRank(GET_JSON_DATA_OR_DEFAULT(SlitRank, Int, 0));
    obj.SetCleaveCurrent(GET_JSON_DATA_OR_DEFAULT(CleaveCurrent, Int, 0));
    obj.SetCleaveRank(GET_JSON_DATA_OR_DEFAULT(CleaveRank, Int, 0));
    obj.SetDecapitateCurrent(GET_JSON_DATA_OR_DEFAULT(DecapitateCurrent, Int, 0));
    obj.SetDecapitateRank(GET_JSON_DATA_OR_DEFAULT(DecapitateRank, Int, 0));
    obj.SetParryCurrent(GET_JSON_DATA_OR_DEFAULT(ParryCurrent, Int, 0));
    obj.SetParryRank(GET_JSON_DATA_OR_DEFAULT(ParryRank, Int, 0));
    obj.SetRiposteCurrent(GET_JSON_DATA_OR_DEFAULT(RiposteCurrent, Int, 0));
    obj.SetRiposteRank(GET_JSON_DATA_OR_DEFAULT(RiposteRank, Int, 0));
    obj.SetBashCurrent(GET_JSON_DATA_OR_DEFAULT(BashCurrent, Int, 0));
    obj.SetBashRank(GET_JSON_DATA_OR_DEFAULT(BashRank, Int, 0));
    obj.SetSmashCurrent(GET_JSON_DATA_OR_DEFAULT(SmashCurrent, Int, 0));
    obj.SetSmashRank(GET_JSON_DATA_OR_DEFAULT(SmashRank, Int, 0));
    obj.SetCrushCurrent(GET_JSON_DATA_OR_DEFAULT(CrushCurrent, Int, 0));
    obj.SetCrushRank(GET_JSON_DATA_OR_DEFAULT(CrushRank, Int, 0));
    obj.SetImpactCurrent(GET_JSON_DATA_OR_DEFAULT(ImpactCurrent, Int, 0));
    obj.SetImpactRank(GET_JSON_DATA_OR_DEFAULT(ImpactRank, Int, 0));
    obj.SetBreakCurrent(GET_JSON_DATA_OR_DEFAULT(BreakCurrent, Int, 0));
    obj.SetBreakRank(GET_JSON_DATA_OR_DEFAULT(BreakRank, Int, 0));
    obj.SetCrackCurrent(GET_JSON_DATA_OR_DEFAULT(CrackCurrent, Int, 0));
    obj.SetCrackRank(GET_JSON_DATA_OR_DEFAULT(CrackRank, Int, 0));
    obj.SetBlockCurrent(GET_JSON_DATA_OR_DEFAULT(BlockCurrent, Int, 0));
    obj.SetBlockRank(GET_JSON_DATA_OR_DEFAULT(BlockRank, Int, 0));
    obj.SetRushCurrent(GET_JSON_DATA_OR_DEFAULT(RushCurrent, Int, 0));
    obj.SetRushRank(GET_JSON_DATA_OR_DEFAULT(RushRank, Int, 0));
    obj.SetPierceCurrent(GET_JSON_DATA_OR_DEFAULT(PierceCurrent, Int, 0));
    obj.SetPierceRank(GET_JSON_DATA_OR_DEFAULT(PierceRank, Int, 0));
    obj.SetDrillCurrent(GET_JSON_DATA_OR_DEFAULT(DrillCurrent, Int, 0));
    obj.SetDrillRank(GET_JSON_DATA_OR_DEFAULT(DrillRank, Int, 0));
    obj.SetShootCurrent(GET_JSON_DATA_OR_DEFAULT(ShootCurrent, Int, 0));
    obj.SetShootRank(GET_JSON_DATA_OR_DEFAULT(ShootRank, Int, 0));
    obj.SetImpaleCurrent(GET_JSON_DATA_OR_DEFAULT(ImpaleCurrent, Int, 0));
    obj.SetImpaleRank(GET_JSON_DATA_OR_DEFAULT(ImpaleRank, Int, 0));
    obj.SetStealthStrikeCurrent(GET_JSON_DATA_OR_DEFAULT(StealthStrikeCurrent, Int, 0));
    obj.SetStealthStrikeRank(GET_JSON_DATA_OR_DEFAULT(StealthStrikeRank, Int, 0));
    obj.SetCriticalShotCurrent(GET_JSON_DATA_OR_DEFAULT(CriticalShotCurrent, Int, 0));
    obj.SetCriticalShotRank(GET_JSON_DATA_OR_DEFAULT(CriticalShotRank, Int, 0));
    obj.SetDodgeCurrent(GET_JSON_DATA_OR_DEFAULT(DodgeCurrent, Int, 0));
    obj.SetDodgeRank(GET_JSON_DATA_OR_DEFAULT(DodgeRank, Int, 0));
    obj.SetCounterCurrent(GET_JSON_DATA_OR_DEFAULT(CounterCurrent, Int, 0));
    obj.SetCounterRank(GET_JSON_DATA_OR_DEFAULT(CounterRank, Int, 0));

    // Alchemy Skills
    obj.SetHealerCurrent(GET_JSON_DATA_OR_DEFAULT(HealerCurrent, Int, 0));
    obj.SetHealerRank(GET_JSON_DATA_OR_DEFAULT(HealerRank, Int, 0));
    obj.SetAlchemistCurrent(GET_JSON_DATA_OR_DEFAULT(AlchemistCurrent, Int, 0));
    obj.SetAlchemistRank(GET_JSON_DATA_OR_DEFAULT(AlchemistRank, Int, 0));
    obj.SetEnergistCurrent(GET_JSON_DATA_OR_DEFAULT(EnergistCurrent, Int, 0));
    obj.SetEnergistRank(GET_JSON_DATA_OR_DEFAULT(EnergistRank, Int, 0));
    obj.SetChemistCurrent(GET_JSON_DATA_OR_DEFAULT(ChemistCurrent, Int, 0));
    obj.SetChemistRank(GET_JSON_DATA_OR_DEFAULT(ChemistRank, Int, 0));

    // Crafting Skills
    obj.SetHammersmithCurrent(GET_JSON_DATA_OR_DEFAULT(HammersmithCurrent, Int, 0));
    obj.SetHammersmithRank(GET_JSON_DATA_OR_DEFAULT(HammersmithRank, Int, 0));
    obj.SetSpellsmithCurrent(GET_JSON_DATA_OR_DEFAULT(SpellsmithCurrent, Int, 0));
    obj.SetSpellsmithRank(GET_JSON_DATA_OR_DEFAULT(SpellsmithRank, Int, 0));
    obj.SetBowsmithCurrent(GET_JSON_DATA_OR_DEFAULT(BowsmithCurrent, Int, 0));
    obj.SetBowsmithRank(GET_JSON_DATA_OR_DEFAULT(BowsmithRank, Int, 0));
    obj.SetSwordsmithCurrent(GET_JSON_DATA_OR_DEFAULT(SwordsmithCurrent, Int, 0));
    obj.SetSwordsmithRank(GET_JSON_DATA_OR_DEFAULT(SwordsmithRank, Int, 0));
    obj.SetWeaverCurrent(GET_JSON_DATA_OR_DEFAULT(WeaverCurrent, Int, 0));
    obj.SetWeaverRank(GET_JSON_DATA_OR_DEFAULT(WeaverRank, Int, 0));
    obj.SetTannerCurrent(GET_JSON_DATA_OR_DEFAULT(TannerCurrent, Int, 0));
    obj.SetTannerRank(GET_JSON_DATA_OR_DEFAULT(TannerRank, Int, 0));
    obj.SetScalesmithCurrent(GET_JSON_DATA_OR_DEFAULT(ScalesmithCurrent, Int, 0));
    obj.SetScalesmithRank(GET_JSON_DATA_OR_DEFAULT(ScalesmithRank, Int, 0));
    obj.SetPlatesmithCurrent(GET_JSON_DATA_OR_DEFAULT(PlatesmithCurrent, Int, 0));
    obj.SetPlatesmithRank(GET_JSON_DATA_OR_DEFAULT(PlatesmithRank, Int, 0));
    obj.SetGoldsmithCurrent(GET_JSON_DATA_OR_DEFAULT(GoldsmithCurrent, Int, 0));
    obj.SetGoldsmithRank(GET_JSON_DATA_OR_DEFAULT(GoldsmithRank, Int, 0));
    obj.SetShieldsmithCurrent(GET_JSON_DATA_OR_DEFAULT(ShieldsmithCurrent, Int, 0));
    obj.SetShieldsmithRank(GET_JSON_DATA_OR_DEFAULT(ShieldsmithRank, Int, 0));

    // Breakdown Skills
    obj.SetHammerbaneCurrent(GET_JSON_DATA_OR_DEFAULT(HammerbaneCurrent, Int, 0));
    obj.SetHammerbaneRank(GET_JSON_DATA_OR_DEFAULT(HammerbaneRank, Int, 0));
    obj.SetSpellbaneCurrent(GET_JSON_DATA_OR_DEFAULT(SpellbaneCurrent, Int, 0));
    obj.SetSpellbaneRank(GET_JSON_DATA_OR_DEFAULT(SpellbaneRank, Int, 0));
    obj.SetBowbaneCurrent(GET_JSON_DATA_OR_DEFAULT(BowbaneCurrent, Int, 0));
    obj.SetBowbaneRank(GET_JSON_DATA_OR_DEFAULT(BowbaneRank, Int, 0));
    obj.SetSwordbaneCurrent(GET_JSON_DATA_OR_DEFAULT(SwordbaneCurrent, Int, 0));
    obj.SetSwordbaneRank(GET_JSON_DATA_OR_DEFAULT(SwordbaneRank, Int, 0));
    obj.SetThreadbareCurrent(GET_JSON_DATA_OR_DEFAULT(ThreadbareCurrent, Int, 0));
    obj.SetThreadbareRank(GET_JSON_DATA_OR_DEFAULT(ThreadbareRank, Int, 0));
    obj.SetStudRemoverCurrent(GET_JSON_DATA_OR_DEFAULT(StudRemoverCurrent, Int, 0));
    obj.SetStudRemoverRank(GET_JSON_DATA_OR_DEFAULT(StudRemoverRank, Int, 0));
    obj.SetScalebaneCurrent(GET_JSON_DATA_OR_DEFAULT(ScalebaneCurrent, Int, 0));
    obj.SetScalebaneRank(GET_JSON_DATA_OR_DEFAULT(ScalebaneRank, Int, 0));
    obj.SetPlatebaneCurrent(GET_JSON_DATA_OR_DEFAULT(PlatebaneCurrent, Int, 0));
    obj.SetPlatebaneRank(GET_JSON_DATA_OR_DEFAULT(PlatebaneRank, Int, 0));
    obj.SetGoldbaneCurrent(GET_JSON_DATA_OR_DEFAULT(GoldbaneCurrent, Int, 0));
    obj.SetGoldbaneRank(GET_JSON_DATA_OR_DEFAULT(GoldbaneRank, Int, 0));
    obj.SetShieldbaneCurrent(GET_JSON_DATA_OR_DEFAULT(ShieldbaneCurrent, Int, 0));
    obj.SetShieldbaneRank(GET_JSON_DATA_OR_DEFAULT(ShieldbaneRank, Int, 0));

    // Affinity Skills
    obj.SetHolyCurrent(GET_JSON_DATA_OR_DEFAULT(HolyCurrent, Int, 0));
    obj.SetHolyRank(GET_JSON_DATA_OR_DEFAULT(HolyRank, Int, 0));
    obj.SetFireCurrent(GET_JSON_DATA_OR_DEFAULT(FireCurrent, Int, 0));
    obj.SetFireRank(GET_JSON_DATA_OR_DEFAULT(FireRank, Int, 0));
    obj.SetIceCurrent(GET_JSON_DATA_OR_DEFAULT(IceCurrent, Int, 0));
    obj.SetIceRank(GET_JSON_DATA_OR_DEFAULT(IceRank, Int, 0));
    obj.SetShockCurrent(GET_JSON_DATA_OR_DEFAULT(ShockCurrent, Int, 0));
    obj.SetShockRank(GET_JSON_DATA_OR_DEFAULT(ShockRank, Int, 0));
    obj.SetDarkCurrent(GET_JSON_DATA_OR_DEFAULT(DarkCurrent, Int, 0));
    obj.SetDarkRank(GET_JSON_DATA_OR_DEFAULT(DarkRank, Int, 0));
    obj.SetLightCurrent(GET_JSON_DATA_OR_DEFAULT(LightCurrent, Int, 0));
    obj.SetLightRank(GET_JSON_DATA_OR_DEFAULT(LightRank, Int, 0));
    obj.SetForceCurrent(GET_JSON_DATA_OR_DEFAULT(ForceCurrent, Int, 0));
    obj.SetForceRank(GET_JSON_DATA_OR_DEFAULT(ForceRank, Int, 0));
    obj.SetMindCurrent(GET_JSON_DATA_OR_DEFAULT(MindCurrent, Int, 0));
    obj.SetMindRank(GET_JSON_DATA_OR_DEFAULT(MindRank, Int, 0));
    obj.SetEarthCurrent(GET_JSON_DATA_OR_DEFAULT(EarthCurrent, Int, 0));
    obj.SetEarthRank(GET_JSON_DATA_OR_DEFAULT(EarthRank, Int, 0));
    obj.SetBloodCurrent(GET_JSON_DATA_OR_DEFAULT(BloodCurrent, Int, 0));
    obj.SetBloodRank(GET_JSON_DATA_OR_DEFAULT(BloodRank, Int, 0));
    obj.SetFleshCurrent(GET_JSON_DATA_OR_DEFAULT(FleshCurrent, Int, 0));
    obj.SetFleshRank(GET_JSON_DATA_OR_DEFAULT(FleshRank, Int, 0));
    obj.SetWindCurrent(GET_JSON_DATA_OR_DEFAULT(WindCurrent, Int, 0));
    obj.SetWindRank(GET_JSON_DATA_OR_DEFAULT(WindRank, Int, 0));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterSkillData, CharacterSkillData);

};
