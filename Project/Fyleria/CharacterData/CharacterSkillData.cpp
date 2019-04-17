// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterSkillData.h"

namespace Gecko
{

CharacterSkillData::CharacterSkillData()
{
}

CharacterSkillData::~CharacterSkillData()
{
}

void CharacterSkillData::Clear()
{
    SetAllSkillCurrentValues(0);
    SetAllSkillRankingValues(0);
}

#define CHARACTER_SET_SKILL_VALUE(type, method, value)                      \
{                                                                           \
    for(auto&& sSkillType : type::_names())                                 \
    {                                                                       \
        CharacterSkillFunctionNode node = GetSkillFunctions(sSkillType);    \
        if(node.IsValid()) { node.method(*this, value); }                   \
    }                                                                       \
}

void CharacterSkillData::SetAllSkillCurrentValues(UByte uValue)
{
    CHARACTER_SET_SKILL_VALUE(SkillWeaponType, SetCurrent, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAlchemyType, SetCurrent, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillBreakdownType, SetCurrent, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCombatType, SetCurrent, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCraftingType, SetCurrent, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAffinityType, SetCurrent, uValue);
}

void CharacterSkillData::SetAllSkillRankingValues(UByte uValue)
{
    CHARACTER_SET_SKILL_VALUE(SkillWeaponType, SetRank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAlchemyType, SetRank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillBreakdownType, SetRank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCombatType, SetRank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillCraftingType, SetRank, uValue);
    CHARACTER_SET_SKILL_VALUE(SkillAffinityType, SetRank, uValue);
}

Bool UpdateSkillRanking(const IndexedString& sSkillType)
{
    CharacterSkillFunctionNode node = GetSkillFunctions(sSkillType);
    if(!node.IsValid())
    {
        return false;
    }

    UByte uRank = node.GetRank(*this);
    if(uRank >= s_kuMaxSkillRank)
    {
        return false;
    }

    UByte uCurrent = node.GetCurrent(*this);
    node.SetCurrent(*this, uCurrent + 1);
    if(static_cast<UInt>(uCurrent + 1) >= s_kuSkillRankUpgradeAmount)
    {
        node.SetCurrent(*this, 0);
        node.SetRank(*this, uRank + 1);
    }
    return true;
}

#define RETURN_SKILL_FUNCTION_NODE(name)                             \
{                                                                    \
    CharacterSkillFunctionNode node;                                 \
    node.fnGetCurrent = &CharacterSkillData::Get##name##Current;     \
    node.fnGetRank = &CharacterSkillData::Get##name##Rank;           \
    node.fnSetCurrent = &CharacterSkillData::Set##name##Current;     \
    node.fnSetRank = &CharacterSkillData::Set##name##Rank;           \
    return node;                                                     \
}

CharacterSkillData::CharacterSkillFunctionNode CharacterSkillData::GetSkillFunctions(const IndexedString& sSkillType) const
{
    SkillWeaponType eSkillWeaponType = IsValidSkillWeaponType(sSkillType) ? StringToSkillWeaponType(sSkillType) : +SkillWeaponType::None;
    switch(eSkillWeaponType)
    {
        case SkillWeaponType::Slash: RETURN_SKILL_FUNCTION_NODE(Slash);
        case SkillWeaponType::Sever: RETURN_SKILL_FUNCTION_NODE(Sever);
        case SkillWeaponType::Slice: RETURN_SKILL_FUNCTION_NODE(Slice);
        case SkillWeaponType::Slit: RETURN_SKILL_FUNCTION_NODE(Slit);
        case SkillWeaponType::Cleave: RETURN_SKILL_FUNCTION_NODE(Cleave);
        case SkillWeaponType::Decapitate: RETURN_SKILL_FUNCTION_NODE(Decapitate);
        case SkillWeaponType::Parry: RETURN_SKILL_FUNCTION_NODE(Parry);
        case SkillWeaponType::Riposte: RETURN_SKILL_FUNCTION_NODE(Riposte);
        case SkillWeaponType::Bash: RETURN_SKILL_FUNCTION_NODE(Bash);
        case SkillWeaponType::Smash: RETURN_SKILL_FUNCTION_NODE(Smash);
        case SkillWeaponType::Impact: RETURN_SKILL_FUNCTION_NODE(Impact);
        case SkillWeaponType::Crush: RETURN_SKILL_FUNCTION_NODE(Crush);
        case SkillWeaponType::Break: RETURN_SKILL_FUNCTION_NODE(Break);
        case SkillWeaponType::Crack: RETURN_SKILL_FUNCTION_NODE(Crack);
        case SkillWeaponType::Block: RETURN_SKILL_FUNCTION_NODE(Block);
        case SkillWeaponType::Rush: RETURN_SKILL_FUNCTION_NODE(Rush);
        case SkillWeaponType::Pierce: RETURN_SKILL_FUNCTION_NODE(Pierce);
        case SkillWeaponType::Drill: RETURN_SKILL_FUNCTION_NODE(Drill);
        case SkillWeaponType::Shoot: RETURN_SKILL_FUNCTION_NODE(Shoot);
        case SkillWeaponType::Impale: RETURN_SKILL_FUNCTION_NODE(Impale);
        case SkillWeaponType::StealthStrike: RETURN_SKILL_FUNCTION_NODE(StealthStrike);
        case SkillWeaponType::CriticalShot: RETURN_SKILL_FUNCTION_NODE(CriticalShot);
        case SkillWeaponType::Dodge: RETURN_SKILL_FUNCTION_NODE(Dodge);
        case SkillWeaponType::Counter: RETURN_SKILL_FUNCTION_NODE(Counter);
        default:
            break;
    }

    SkillAlchemyType eSkillAlchemyType = IsValidSkillAlchemyType(sSkillType) ? StringToSkillAlchemyType(sSkillType) : +SkillAlchemyType::None;
    switch(eSkillAlchemyType)
    {
        case SkillAlchemyType::Healer: RETURN_SKILL_FUNCTION_NODE(Healer);
        case SkillAlchemyType::Alchemist: RETURN_SKILL_FUNCTION_NODE(Alchemist);
        case SkillAlchemyType::Energist: RETURN_SKILL_FUNCTION_NODE(Energist);
        case SkillAlchemyType::Chemist: RETURN_SKILL_FUNCTION_NODE(Chemist);
        default:
            break;
    }

    SkillBreakdownType eSkillBreakdownType = IsValidSkillBreakdownType(sSkillType) ? StringToSkillBreakdownType(sSkillType) : +SkillBreakdownType::None;
    switch(eSkillBreakdownType)
    {
        case SkillBreakdownType::Hammerbane: RETURN_SKILL_FUNCTION_NODE(Hammerbane);
        case SkillBreakdownType::Spellbane: RETURN_SKILL_FUNCTION_NODE(Spellbane);
        case SkillBreakdownType::Bowbane: RETURN_SKILL_FUNCTION_NODE(Bowbane);
        case SkillBreakdownType::Swordbane: RETURN_SKILL_FUNCTION_NODE(Swordbane);
        case SkillBreakdownType::Threadbare: RETURN_SKILL_FUNCTION_NODE(Threadbare);
        case SkillBreakdownType::StudRemover: RETURN_SKILL_FUNCTION_NODE(StudRemover);
        case SkillBreakdownType::Scalebane: RETURN_SKILL_FUNCTION_NODE(Scalebane);
        case SkillBreakdownType::Platebane: RETURN_SKILL_FUNCTION_NODE(Platebane);
        case SkillBreakdownType::Goldbane: RETURN_SKILL_FUNCTION_NODE(Goldbane);
        case SkillBreakdownType::Shieldbane: RETURN_SKILL_FUNCTION_NODE(Shieldbane);
        default:
            break;
    }

    SkillCombatType eSkillCombatType = IsValidSkillCombatType(sSkillType) ? StringToSkillCombatType(sSkillType) : +SkillCombatType::None;
    switch(eSkillCombatType)
    {
        case SkillCombatType::Barbarian: RETURN_SKILL_FUNCTION_NODE(Barbarian);
        case SkillCombatType::Mage: RETURN_SKILL_FUNCTION_NODE(Mage);
        case SkillCombatType::Rogue: RETURN_SKILL_FUNCTION_NODE(Rogue);
        case SkillCombatType::Blademaster: RETURN_SKILL_FUNCTION_NODE(Blademaster);
        case SkillCombatType::Avatar: RETURN_SKILL_FUNCTION_NODE(Avatar);
        case SkillCombatType::Ambidextrous: RETURN_SKILL_FUNCTION_NODE(Ambidextrous);
        case SkillCombatType::Focused: RETURN_SKILL_FUNCTION_NODE(Focused);
        case SkillCombatType::Stalwart: RETURN_SKILL_FUNCTION_NODE(Stalwart);
        default:
            break;
    }

    SkillCraftingType eSkillCraftingType = IsValidSkillCraftingType(sSkillType) ? StringToSkillCraftingType(sSkillType) : +SkillCraftingType::None;
    switch(eSkillCraftingType)
    {
        case SkillCraftingType::Hammersmith: RETURN_SKILL_FUNCTION_NODE(Hammersmith);
        case SkillCraftingType::Spellsmith: RETURN_SKILL_FUNCTION_NODE(Spellsmith);
        case SkillCraftingType::Bowsmith: RETURN_SKILL_FUNCTION_NODE(Bowsmith);
        case SkillCraftingType::Swordsmith: RETURN_SKILL_FUNCTION_NODE(Swordsmith);
        case SkillCraftingType::Weaver: RETURN_SKILL_FUNCTION_NODE(Weaver);
        case SkillCraftingType::Tanner: RETURN_SKILL_FUNCTION_NODE(Tanner);
        case SkillCraftingType::Scalesmith: RETURN_SKILL_FUNCTION_NODE(Scalesmith);
        case SkillCraftingType::Platesmith: RETURN_SKILL_FUNCTION_NODE(Platesmith);
        case SkillCraftingType::Goldsmith: RETURN_SKILL_FUNCTION_NODE(Goldsmith);
        case SkillCraftingType::Shieldsmith: RETURN_SKILL_FUNCTION_NODE(Shieldsmith);
        default:
            break;
    }

    SkillAffinityType eSkillAffinityType = IsValidSkillAffinityType(sSkillType) ? StringToSkillAffinityType(sSkillType) : +SkillAffinityType::None;
    switch(eSkillAffinityType)
    {
        case SkillAffinityType::Holy: RETURN_SKILL_FUNCTION_NODE(Holy);
        case SkillAffinityType::Fire: RETURN_SKILL_FUNCTION_NODE(Fire);
        case SkillAffinityType::Ice: RETURN_SKILL_FUNCTION_NODE(Ice);
        case SkillAffinityType::Shock: RETURN_SKILL_FUNCTION_NODE(Shock);
        case SkillAffinityType::Dark: RETURN_SKILL_FUNCTION_NODE(Dark);
        case SkillAffinityType::Light: RETURN_SKILL_FUNCTION_NODE(Light);
        case SkillAffinityType::Force: RETURN_SKILL_FUNCTION_NODE(Force);
        case SkillAffinityType::Mind: RETURN_SKILL_FUNCTION_NODE(Mind);
        case SkillAffinityType::Earth: RETURN_SKILL_FUNCTION_NODE(Earth);
        case SkillAffinityType::Blood: RETURN_SKILL_FUNCTION_NODE(Blood);
        case SkillAffinityType::Flesh: RETURN_SKILL_FUNCTION_NODE(Flesh);
        case SkillAffinityType::Wind: RETURN_SKILL_FUNCTION_NODE(Wind);
        default:
            break;
    }
    return CharacterSkillFunctionNode();
}

Bool CharacterSkillData::operator==(const CharacterSkillData& other) const
{
    return false;
}

Bool CharacterSkillData::operator!=(const CharacterSkillData& other) const
{
    return false;
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
    // Get current configuration
    const Config& config = ConfigManager::GetInstance()->GetCurrentConfig();

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
