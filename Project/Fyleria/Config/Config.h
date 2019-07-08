// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CONFIG_H_
#define _GECKO_CONFIG_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

class Config
{
public:

    // Constructors
    Config();
    Config(const Json& jsonData);
    Config(const String& jsonString);

    // Destructor
    virtual ~Config();

    // Item file locations
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorChestFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorFeetFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorFingerFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorHandsFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorHeadFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorNeckFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorLegsFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemArmorShieldFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientBarFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientClothFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientCrystalFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientLeatherFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientMailFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientPlateFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientScaleFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientScrewFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientSheetFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientStudFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemIngredientThreadFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemPotionEnergyFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemPotionHealFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemPotionMagicFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemPotionSpeedFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemWeaponBluntFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemWeaponMageFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemWeaponPierceFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ItemWeaponSlashFile, String);

    // Skill file locations
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityBloodFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityDarkFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityEarthFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityFireFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityFleshFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityForceFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityHolyFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityIceFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityLightFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityMindFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityShockFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAffinityWindFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAlchemyAlchemistFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAlchemyChemistFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAlchemyEnergistFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillAlchemyHealerFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownBowbaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownGoldbaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownHammerbaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownPlatebaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownScalebaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownShieldbaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownSpellbaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownStudRemoverFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownSwordbaneFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillBreakdownThreadbareFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatAmbidextrousFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatAvatarFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatBarbarianFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatBlademasterFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatFocusedFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatMageFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatRogueFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCombatStalwartFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingBowsmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingGoldsmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingHammersmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingPlatesmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingScalesmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingShieldsmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingSpellsmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingSwordsmithFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingTannerFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillCraftingWeaverFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponBashFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponBlockFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponBreakFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponCleaveFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponCounterFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponCrackFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponCriticalShotFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponCrushFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponDecapitateFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponDodgeFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponDrillFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponImpactFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponImpaleFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponParryFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponPierceFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponRiposteFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponRushFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponSeverFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponShootFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponSlashFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponSliceFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponSlitFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponSmashFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillWeaponStealthStrikeFile, String);
};

// Typedef
MAKE_TYPE_TYPEDEFS(Config);

// JSON Converters
void to_json(Json& jsonData, const Config& obj);
void from_json(const Json& jsonData, Config& obj);

};

#endif
