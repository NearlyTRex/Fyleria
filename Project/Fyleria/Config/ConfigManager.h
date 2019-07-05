// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CONFIG_MANAGER_H_
#define _GECKO_CONFIG_MANAGER_H_

// Internal includes
#include "Config/Config.h"
#include "Utility/Singleton.h"

namespace Gecko
{

class ConfigManager : public Singleton<ConfigManager>
{
public:

    // Types
    typedef STDUnorderedMap<String, Config> ConfigMappingType;

    // Constructors
    ConfigManager();

    // Load config
    Bool LoadConfig(const String& sName, const String& sFile);

    // Does a config exist
    Bool DoesConfigExist(const String& sName) const;

    // Get config
    const Config& GetConfig(const String& sName) const;
    const Config& GetCurrentConfig() const;

    // Get constructed config file name
    String GetConstructedConfigFilename() const;

    // Get constructed python library file name
    String GetConstructedPythonLibraryFilename() const;

    // Item file locations
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorChestFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorFeetFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorFingerFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorHandsFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorHeadFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorNeckFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorLegsFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemArmorShieldFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientBarFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientClothFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientCrystalFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientLeatherFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientMailFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientPlateFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientScaleFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientScrewFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientSheetFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientStudFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemIngredientThreadFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemPotionEnergyFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemPotionHealFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemPotionMagicFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemPotionSpeedFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemWeaponBluntFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemWeaponMageFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemWeaponPierceFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(ItemWeaponSlashFile);

    // Skill file locations
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityBloodFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityDarkFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityEarthFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityFireFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityFleshFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityForceFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityHolyFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityIceFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityLightFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityMindFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityShockFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAffinityWindFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAlchemyAlchemistFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAlchemyChemistFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAlchemyEnergistFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillAlchemyHealerFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownBowbaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownGoldbaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownHammerbaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownPlatebaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownScalebaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownShieldbaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownSpellbaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownStudRemoverFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownSwordbaneFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillBreakdownThreadbareFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatAmbidextrousFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatAvatarFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatBarbarianFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatBlademasterFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatFocusedFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatMageFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatRogueFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCombatStalwartFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingBowsmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingGoldsmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingHammersmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingPlatesmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingScalesmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingShieldsmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingSpellsmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingSwordsmithFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingTannerFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillCraftingWeaverFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponBashFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponBlockFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponBreakFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponCleaveFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponCounterFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponCrackFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponCriticalShotFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponCrushFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponDecapitateFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponDodgeFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponDrillFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponImpactFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponImpaleFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponParryFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponPierceFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponRiposteFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponRushFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponSeverFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponShootFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponSlashFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponSliceFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponSlitFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponSmashFile);
    MAKE_CURRENT_CONFIG_SHORTCUT_STRING(SkillWeaponStealthStrikeFile);

    // Current config name
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentConfigName, String);

    // Config data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(UserConfigFile, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(UserConfigFolder, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(UserDataFolder, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(UserCacheFolder, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(UserWebFolder, String);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PythonLibraryFile, String);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ScreenWidth, Int);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ScreenHeight, Int);

    // Configuration map
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(LoadedConfigs, ConfigMappingType);

    // Platforms
    Bool IsPosix() const;
    Bool IsWindows() const;
    Bool IsWindows32() const;
    Bool IsWindows64() const;
    Bool IsLinux() const;
    Bool IsLinux32() const;
    Bool IsLinux64() const;
    Bool IsMac() const;
    Bool IsIOS() const;
    Bool IsAndroid() const;
};

};

#endif
