// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PROGRESS_DATA_H_
#define _GECKO_CHARACTER_PROGRESS_DATA_H_

#include "CharacterAction/CharacterAction.h"
#include "Stats/StatTypeHolder.h"

namespace Gecko
{

// Character progress data
class CharacterProgressData : public StatTypeHolder
{
public:

    // Constructors
    CharacterProgressData();
    CharacterProgressData(const Json& jsonData);

    // Clear all data
    void Clear();

    // Apply damage
    void ApplyTakenDamage(Int iDamage);

    // Apply regeneration
    void ApplyRegeneration(Bool bCanRegenHP, Bool bCanRegenMP, Bool bCanRegenEP);

    // Apply cost of action
    void ApplyActionCost(const CharacterAction& action);

    // Update available AP
    void UpdateAvailableAP(const IndexedString& sCharacterID);

    // Stat names
    static void InitAllStatNames();

    // Int stats
    MAKE_STAT_TYPE_ACCESSORS(HealthPointsCurrent, Int);
    MAKE_STAT_TYPE_ACCESSORS(MagicPointsCurrent, Int);
    MAKE_STAT_TYPE_ACCESSORS(EnergyPointsCurrent, Int);
    MAKE_STAT_TYPE_ACCESSORS(HealthPointsMax, Int);
    MAKE_STAT_TYPE_ACCESSORS(MagicPointsMax, Int);
    MAKE_STAT_TYPE_ACCESSORS(EnergyPointsMax, Int);
    MAKE_STAT_TYPE_ACCESSORS(HealthRegen, Int);
    MAKE_STAT_TYPE_ACCESSORS(MagicRegen, Int);
    MAKE_STAT_TYPE_ACCESSORS(EnergyRegen, Int);
    MAKE_STAT_TYPE_ACCESSORS(HealthCostDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(MagicCostDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(EnergyCostDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(Speed, Int);
    MAKE_STAT_TYPE_ACCESSORS(AmberValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(RubyValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(DiamondValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(CitrineValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(OnyxValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(QuartzValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(SapphireValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(AmethystValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(EmeraldValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(GarnetValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(IvoryValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(OpalValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(BluntAttack, Int);
    MAKE_STAT_TYPE_ACCESSORS(BluntDefense, Int);
    MAKE_STAT_TYPE_ACCESSORS(MagicAttack, Int);
    MAKE_STAT_TYPE_ACCESSORS(MagicDefense, Int);
    MAKE_STAT_TYPE_ACCESSORS(PierceAttack, Int);
    MAKE_STAT_TYPE_ACCESSORS(PierceDefense, Int);
    MAKE_STAT_TYPE_ACCESSORS(SlashAttack, Int);
    MAKE_STAT_TYPE_ACCESSORS(SlashDefense, Int);
    MAKE_STAT_TYPE_ACCESSORS(EnergyAttack, Int);
    MAKE_STAT_TYPE_ACCESSORS(EnergyDefense, Int);
    MAKE_STAT_TYPE_ACCESSORS(SlashPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SeverPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SlicePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SlitPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CleavePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(DecapitatePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ParryPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(RipostePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(BashPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SmashPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ImpactPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CrushPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(BreakPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CrackPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(BlockPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(RushPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(PiercePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(DrillPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ShootPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ImpalePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(StealthStrikePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CriticalShotPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(DodgePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CounterPoints, Int);

    // Comparisons
    Bool operator==(const CharacterProgressData& other) const;
    Bool operator!=(const CharacterProgressData& other) const;
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterProgressData);

// JSON Converters
void to_json(Json& jsonData, const CharacterProgressData& obj);
void from_json(const Json& jsonData, CharacterProgressData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterProgressData, CharacterProgressData);

};

#endif
