// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Config/Config.h"

namespace Gecko
{

Config::Config()
{
}

Config::Config(const Json& jsonData)
{
    from_json(jsonData, *this);
}

Config::Config(const String& jsonString)
{
    from_json(JsonParse(jsonString), *this);
}

Config::~Config()
{
}

void to_json(Json& jsonData, const Config& obj)
{
    // Item file locations
    SET_JSON_DATA(ItemArmorChestFile);
    SET_JSON_DATA(ItemArmorFeetFile);
    SET_JSON_DATA(ItemArmorFingerFile);
    SET_JSON_DATA(ItemArmorHandsFile);
    SET_JSON_DATA(ItemArmorHeadFile);
    SET_JSON_DATA(ItemArmorNeckFile);
    SET_JSON_DATA(ItemArmorLegsFile);
    SET_JSON_DATA(ItemArmorShieldFile);
    SET_JSON_DATA(ItemIngredientBarFile);
    SET_JSON_DATA(ItemIngredientClothFile);
    SET_JSON_DATA(ItemIngredientCrystalFile);
    SET_JSON_DATA(ItemIngredientLeatherFile);
    SET_JSON_DATA(ItemIngredientMailFile);
    SET_JSON_DATA(ItemIngredientPlateFile);
    SET_JSON_DATA(ItemIngredientScaleFile);
    SET_JSON_DATA(ItemIngredientScrewFile);
    SET_JSON_DATA(ItemIngredientSheetFile);
    SET_JSON_DATA(ItemIngredientStudFile);
    SET_JSON_DATA(ItemIngredientThreadFile);
    SET_JSON_DATA(ItemPotionEnergyFile);
    SET_JSON_DATA(ItemPotionHealFile);
    SET_JSON_DATA(ItemPotionMagicFile);
    SET_JSON_DATA(ItemPotionSpeedFile);
    SET_JSON_DATA(ItemWeaponBluntFile);
    SET_JSON_DATA(ItemWeaponMageFile);
    SET_JSON_DATA(ItemWeaponPierceFile);
    SET_JSON_DATA(ItemWeaponSlashFile);

    // Skill file locations
    SET_JSON_DATA(SkillAffinityBloodFile);
    SET_JSON_DATA(SkillAffinityDarkFile);
    SET_JSON_DATA(SkillAffinityEarthFile);
    SET_JSON_DATA(SkillAffinityFireFile);
    SET_JSON_DATA(SkillAffinityFleshFile);
    SET_JSON_DATA(SkillAffinityForceFile);
    SET_JSON_DATA(SkillAffinityHolyFile);
    SET_JSON_DATA(SkillAffinityIceFile);
    SET_JSON_DATA(SkillAffinityLightFile);
    SET_JSON_DATA(SkillAffinityMindFile);
    SET_JSON_DATA(SkillAffinityShockFile);
    SET_JSON_DATA(SkillAffinityWindFile);
    SET_JSON_DATA(SkillAlchemyAlchemistFile);
    SET_JSON_DATA(SkillAlchemyChemistFile);
    SET_JSON_DATA(SkillAlchemyEnergistFile);
    SET_JSON_DATA(SkillAlchemyHealerFile);
    SET_JSON_DATA(SkillBreakdownBowbaneFile);
    SET_JSON_DATA(SkillBreakdownGoldbaneFile);
    SET_JSON_DATA(SkillBreakdownHammerbaneFile);
    SET_JSON_DATA(SkillBreakdownPlatebaneFile);
    SET_JSON_DATA(SkillBreakdownScalebaneFile);
    SET_JSON_DATA(SkillBreakdownShieldbaneFile);
    SET_JSON_DATA(SkillBreakdownSpellbaneFile);
    SET_JSON_DATA(SkillBreakdownStudRemoverFile);
    SET_JSON_DATA(SkillBreakdownSwordbaneFile);
    SET_JSON_DATA(SkillBreakdownThreadbareFile);
    SET_JSON_DATA(SkillCombatAmbidextrousFile);
    SET_JSON_DATA(SkillCombatAvatarFile);
    SET_JSON_DATA(SkillCombatBarbarianFile);
    SET_JSON_DATA(SkillCombatBlademasterFile);
    SET_JSON_DATA(SkillCombatFocusedFile);
    SET_JSON_DATA(SkillCombatMageFile);
    SET_JSON_DATA(SkillCombatRogueFile);
    SET_JSON_DATA(SkillCombatStalwartFile);
    SET_JSON_DATA(SkillCraftingBowsmithFile);
    SET_JSON_DATA(SkillCraftingGoldsmithFile);
    SET_JSON_DATA(SkillCraftingHammersmithFile);
    SET_JSON_DATA(SkillCraftingPlatesmithFile);
    SET_JSON_DATA(SkillCraftingScalesmithFile);
    SET_JSON_DATA(SkillCraftingShieldsmithFile);
    SET_JSON_DATA(SkillCraftingSpellsmithFile);
    SET_JSON_DATA(SkillCraftingSwordsmithFile);
    SET_JSON_DATA(SkillCraftingTannerFile);
    SET_JSON_DATA(SkillCraftingWeaverFile);
    SET_JSON_DATA(SkillWeaponBashFile);
    SET_JSON_DATA(SkillWeaponBlockFile);
    SET_JSON_DATA(SkillWeaponBreakFile);
    SET_JSON_DATA(SkillWeaponCleaveFile);
    SET_JSON_DATA(SkillWeaponCounterFile);
    SET_JSON_DATA(SkillWeaponCrackFile);
    SET_JSON_DATA(SkillWeaponCriticalShotFile);
    SET_JSON_DATA(SkillWeaponCrushFile);
    SET_JSON_DATA(SkillWeaponDecapitateFile);
    SET_JSON_DATA(SkillWeaponDodgeFile);
    SET_JSON_DATA(SkillWeaponDrillFile);
    SET_JSON_DATA(SkillWeaponImpactFile);
    SET_JSON_DATA(SkillWeaponImpaleFile);
    SET_JSON_DATA(SkillWeaponParryFile);
    SET_JSON_DATA(SkillWeaponPierceFile);
    SET_JSON_DATA(SkillWeaponRiposteFile);
    SET_JSON_DATA(SkillWeaponRushFile);
    SET_JSON_DATA(SkillWeaponSeverFile);
    SET_JSON_DATA(SkillWeaponShootFile);
    SET_JSON_DATA(SkillWeaponSlashFile);
    SET_JSON_DATA(SkillWeaponSliceFile);
    SET_JSON_DATA(SkillWeaponSlitFile);
    SET_JSON_DATA(SkillWeaponSmashFile);
    SET_JSON_DATA(SkillWeaponStealthStrikeFile);
}

void from_json(const Json& jsonData, Config& obj)
{
    // Item file locations
    SET_OBJ_DATA(ItemArmorChestFile, String);
    SET_OBJ_DATA(ItemArmorFeetFile, String);
    SET_OBJ_DATA(ItemArmorFingerFile, String);
    SET_OBJ_DATA(ItemArmorHandsFile, String);
    SET_OBJ_DATA(ItemArmorHeadFile, String);
    SET_OBJ_DATA(ItemArmorNeckFile, String);
    SET_OBJ_DATA(ItemArmorLegsFile, String);
    SET_OBJ_DATA(ItemArmorShieldFile, String);
    SET_OBJ_DATA(ItemIngredientBarFile, String);
    SET_OBJ_DATA(ItemIngredientClothFile, String);
    SET_OBJ_DATA(ItemIngredientCrystalFile, String);
    SET_OBJ_DATA(ItemIngredientLeatherFile, String);
    SET_OBJ_DATA(ItemIngredientMailFile, String);
    SET_OBJ_DATA(ItemIngredientPlateFile, String);
    SET_OBJ_DATA(ItemIngredientScaleFile, String);
    SET_OBJ_DATA(ItemIngredientScrewFile, String);
    SET_OBJ_DATA(ItemIngredientSheetFile, String);
    SET_OBJ_DATA(ItemIngredientStudFile, String);
    SET_OBJ_DATA(ItemIngredientThreadFile, String);
    SET_OBJ_DATA(ItemPotionEnergyFile, String);
    SET_OBJ_DATA(ItemPotionHealFile, String);
    SET_OBJ_DATA(ItemPotionMagicFile, String);
    SET_OBJ_DATA(ItemPotionSpeedFile, String);
    SET_OBJ_DATA(ItemWeaponBluntFile, String);
    SET_OBJ_DATA(ItemWeaponMageFile, String);
    SET_OBJ_DATA(ItemWeaponPierceFile, String);
    SET_OBJ_DATA(ItemWeaponSlashFile, String);

    // Skill file locations
    SET_OBJ_DATA(SkillAffinityBloodFile, String);
    SET_OBJ_DATA(SkillAffinityDarkFile, String);
    SET_OBJ_DATA(SkillAffinityEarthFile, String);
    SET_OBJ_DATA(SkillAffinityFireFile, String);
    SET_OBJ_DATA(SkillAffinityFleshFile, String);
    SET_OBJ_DATA(SkillAffinityForceFile, String);
    SET_OBJ_DATA(SkillAffinityHolyFile, String);
    SET_OBJ_DATA(SkillAffinityIceFile, String);
    SET_OBJ_DATA(SkillAffinityLightFile, String);
    SET_OBJ_DATA(SkillAffinityMindFile, String);
    SET_OBJ_DATA(SkillAffinityShockFile, String);
    SET_OBJ_DATA(SkillAffinityWindFile, String);
    SET_OBJ_DATA(SkillAlchemyAlchemistFile, String);
    SET_OBJ_DATA(SkillAlchemyChemistFile, String);
    SET_OBJ_DATA(SkillAlchemyEnergistFile, String);
    SET_OBJ_DATA(SkillAlchemyHealerFile, String);
    SET_OBJ_DATA(SkillBreakdownBowbaneFile, String);
    SET_OBJ_DATA(SkillBreakdownGoldbaneFile, String);
    SET_OBJ_DATA(SkillBreakdownHammerbaneFile, String);
    SET_OBJ_DATA(SkillBreakdownPlatebaneFile, String);
    SET_OBJ_DATA(SkillBreakdownScalebaneFile, String);
    SET_OBJ_DATA(SkillBreakdownShieldbaneFile, String);
    SET_OBJ_DATA(SkillBreakdownSpellbaneFile, String);
    SET_OBJ_DATA(SkillBreakdownStudRemoverFile, String);
    SET_OBJ_DATA(SkillBreakdownSwordbaneFile, String);
    SET_OBJ_DATA(SkillBreakdownThreadbareFile, String);
    SET_OBJ_DATA(SkillCombatAmbidextrousFile, String);
    SET_OBJ_DATA(SkillCombatAvatarFile, String);
    SET_OBJ_DATA(SkillCombatBarbarianFile, String);
    SET_OBJ_DATA(SkillCombatBlademasterFile, String);
    SET_OBJ_DATA(SkillCombatFocusedFile, String);
    SET_OBJ_DATA(SkillCombatMageFile, String);
    SET_OBJ_DATA(SkillCombatRogueFile, String);
    SET_OBJ_DATA(SkillCombatStalwartFile, String);
    SET_OBJ_DATA(SkillCraftingBowsmithFile, String);
    SET_OBJ_DATA(SkillCraftingGoldsmithFile, String);
    SET_OBJ_DATA(SkillCraftingHammersmithFile, String);
    SET_OBJ_DATA(SkillCraftingPlatesmithFile, String);
    SET_OBJ_DATA(SkillCraftingScalesmithFile, String);
    SET_OBJ_DATA(SkillCraftingShieldsmithFile, String);
    SET_OBJ_DATA(SkillCraftingSpellsmithFile, String);
    SET_OBJ_DATA(SkillCraftingSwordsmithFile, String);
    SET_OBJ_DATA(SkillCraftingTannerFile, String);
    SET_OBJ_DATA(SkillCraftingWeaverFile, String);
    SET_OBJ_DATA(SkillWeaponBashFile, String);
    SET_OBJ_DATA(SkillWeaponBlockFile, String);
    SET_OBJ_DATA(SkillWeaponBreakFile, String);
    SET_OBJ_DATA(SkillWeaponCleaveFile, String);
    SET_OBJ_DATA(SkillWeaponCounterFile, String);
    SET_OBJ_DATA(SkillWeaponCrackFile, String);
    SET_OBJ_DATA(SkillWeaponCriticalShotFile, String);
    SET_OBJ_DATA(SkillWeaponCrushFile, String);
    SET_OBJ_DATA(SkillWeaponDecapitateFile, String);
    SET_OBJ_DATA(SkillWeaponDodgeFile, String);
    SET_OBJ_DATA(SkillWeaponDrillFile, String);
    SET_OBJ_DATA(SkillWeaponImpactFile, String);
    SET_OBJ_DATA(SkillWeaponImpaleFile, String);
    SET_OBJ_DATA(SkillWeaponParryFile, String);
    SET_OBJ_DATA(SkillWeaponPierceFile, String);
    SET_OBJ_DATA(SkillWeaponRiposteFile, String);
    SET_OBJ_DATA(SkillWeaponRushFile, String);
    SET_OBJ_DATA(SkillWeaponSeverFile, String);
    SET_OBJ_DATA(SkillWeaponShootFile, String);
    SET_OBJ_DATA(SkillWeaponSlashFile, String);
    SET_OBJ_DATA(SkillWeaponSliceFile, String);
    SET_OBJ_DATA(SkillWeaponSlitFile, String);
    SET_OBJ_DATA(SkillWeaponSmashFile, String);
    SET_OBJ_DATA(SkillWeaponStealthStrikeFile, String);
}

};
