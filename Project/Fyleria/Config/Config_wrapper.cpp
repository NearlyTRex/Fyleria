// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Config/Config.h"
#include "Config/ConfigManager.h"
#include "Utility/Macros.h"
#include "Utility/Python.h"

namespace Gecko
{
    // Manager lambdas
    auto fnLoadConfig = MAKE_MANAGER_RETURN_LAMBDA_A2(ConfigManager, LoadConfig, Bool, const String&, const String&);
    auto fnDoesConfigExist = MAKE_MANAGER_RETURN_LAMBDA_A1(ConfigManager, DoesConfigExist, Bool, const String&);
    auto fnGetConfig = MAKE_MANAGER_RETURN_LAMBDA_A1(ConfigManager, GetConfig, const Config&, const String&);
    auto fnGetCurrentConfig = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetCurrentConfig, const Config&);
    auto fnGetConstructedConfigFilename = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetConstructedConfigFilename, String);
    auto fnGetConstructedPythonLibraryFilename = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetConstructedPythonLibraryFilename, String);
    auto fnGetCurrentConfigName = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetCurrentConfigName, const String&);
    auto fnSetCurrentConfigName = MAKE_MANAGER_VOID_LAMBDA_A1(ConfigManager, SetCurrentConfigName, const String&);
    auto fnGetUserConfigFile = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetUserConfigFile, const String&);
    auto fnGetUserConfigFolder = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetUserConfigFolder, const String&);
    auto fnGetUserDataFolder = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetUserDataFolder, const String&);
    auto fnGetUserCacheFolder = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetUserCacheFolder, const String&);
    auto fnGetUserWebFolder = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetUserWebFolder, const String&);
    auto fnGetPythonLibraryFile = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetPythonLibraryFile, const String&);
    auto fnGetScreenWidth = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetScreenWidth, Int);
    auto fnGetScreenHeight = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, GetScreenHeight, Int);
    auto fnIsPosix = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsPosix, Bool);
    auto fnIsWindows = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsWindows, Bool);
    auto fnIsWindows32 = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsWindows32, Bool);
    auto fnIsWindows64 = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsWindows64, Bool);
    auto fnIsLinux = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsLinux, Bool);
    auto fnIsLinux32 = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsLinux32, Bool);
    auto fnIsLinux64 = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsLinux64, Bool);
    auto fnIsMac = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsMac, Bool);
    auto fnIsIOS = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsIOS, Bool);
    auto fnIsAndroid = MAKE_MANAGER_RETURN_LAMBDA(ConfigManager, IsAndroid, Bool);
};

PYBIND11_EMBEDDED_MODULE(GeckoConfig, m)
{
    // Config.h
    PyBindClass<Gecko::Config, Gecko::SerializableToJson>(m, "Config")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_CONSTRUCTOR_ARGS(const Gecko::String&)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorChestFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorFeetFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorFingerFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorHandsFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorHeadFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorNeckFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorLegsFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemArmorShieldFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientBarFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientClothFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientCrystalFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientLeatherFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientMailFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientPlateFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientScaleFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientScrewFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientSheetFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientStudFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemIngredientThreadFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemPotionEnergyFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemPotionHealFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemPotionMagicFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemPotionSpeedFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemWeaponBluntFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemWeaponMageFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemWeaponPierceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ItemWeaponSlashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityBloodFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityDarkFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityEarthFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityFireFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityFleshFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityForceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityHolyFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityIceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityLightFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityMindFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityShockFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAffinityWindFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAlchemyAlchemistFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAlchemyChemistFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAlchemyEnergistFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillAlchemyHealerFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownBowbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownGoldbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownHammerbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownPlatebaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownScalebaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownShieldbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownSpellbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownStudRemoverFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownSwordbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillBreakdownThreadbareFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatAmbidextrousFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatAvatarFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatBarbarianFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatBlademasterFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatFocusedFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatMageFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatRogueFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCombatStalwartFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingBowsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingGoldsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingHammersmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingPlatesmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingScalesmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingShieldsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingSpellsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingSwordsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingTannerFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCraftingWeaverFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponBashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponBlockFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponBreakFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponCleaveFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponCounterFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponCrackFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponCriticalShotFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponCrushFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponDecapitateFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponDodgeFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponDrillFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponImpactFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponImpaleFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponParryFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponPierceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponRiposteFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponRushFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponSeverFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponShootFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponSlashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponSliceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponSlitFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponSmashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillWeaponStealthStrikeFile, Gecko::Config)
    ;
    PyBindVector<Gecko::ConfigArray>(m, "ConfigArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertConfigToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertConfigArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetConfigFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetConfigArrayFromJsonString, Gecko);

    // ConfigManager.h
    WRAPPING_STANDALONE_LAMBDA(LoadConfig, Gecko::fnLoadConfig);
    WRAPPING_STANDALONE_LAMBDA(DoesConfigExist, Gecko::fnDoesConfigExist);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetConfig, Gecko::fnGetConfig, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetCurrentConfig, Gecko::fnGetCurrentConfig, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetConstructedConfigFilename, Gecko::fnGetConstructedConfigFilename, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetConstructedPythonLibraryFilename, Gecko::fnGetConstructedPythonLibraryFilename, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetCurrentConfigName, Gecko::fnGetCurrentConfigName, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA(SetCurrentConfigName, Gecko::fnSetCurrentConfigName);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetUserConfigFile, Gecko::fnGetUserConfigFile, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetUserConfigFolder, Gecko::fnGetUserConfigFolder, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetUserDataFolder, Gecko::fnGetUserDataFolder, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetUserCacheFolder, Gecko::fnGetUserCacheFolder, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetUserWebFolder, Gecko::fnGetUserWebFolder, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA_POLICY(GetPythonLibraryFile, Gecko::fnGetPythonLibraryFile, PyBindReturnCopy);
    WRAPPING_STANDALONE_LAMBDA(GetScreenWidth, Gecko::fnGetScreenWidth);
    WRAPPING_STANDALONE_LAMBDA(GetScreenHeight, Gecko::fnGetScreenHeight);
    WRAPPING_STANDALONE_LAMBDA(IsPosix, Gecko::fnIsPosix);
    WRAPPING_STANDALONE_LAMBDA(IsWindows, Gecko::fnIsWindows);
    WRAPPING_STANDALONE_LAMBDA(IsWindows32, Gecko::fnIsWindows32);
    WRAPPING_STANDALONE_LAMBDA(IsWindows64, Gecko::fnIsWindows64);
    WRAPPING_STANDALONE_LAMBDA(IsLinux, Gecko::fnIsLinux);
    WRAPPING_STANDALONE_LAMBDA(IsLinux32, Gecko::fnIsLinux32);
    WRAPPING_STANDALONE_LAMBDA(IsLinux64, Gecko::fnIsLinux64);
    WRAPPING_STANDALONE_LAMBDA(IsMac, Gecko::fnIsMac);
    WRAPPING_STANDALONE_LAMBDA(IsIOS, Gecko::fnIsIOS);
    WRAPPING_STANDALONE_LAMBDA(IsAndroid, Gecko::fnIsAndroid);
}
