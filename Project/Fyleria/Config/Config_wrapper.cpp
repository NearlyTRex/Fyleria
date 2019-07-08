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
    PyBindClass<Gecko::Config>(m, "Config")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_CONSTRUCTOR_ARGS(const Gecko::String&)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorChestFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorFeetFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorFingerFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorHandsFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorHeadFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorNeckFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorLegsFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemArmorShieldFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientBarFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientClothFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientCrystalFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientLeatherFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientMailFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientPlateFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientScaleFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientScrewFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientSheetFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientStudFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemIngredientThreadFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemPotionEnergyFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemPotionHealFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemPotionMagicFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemPotionSpeedFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemWeaponBluntFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemWeaponMageFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemWeaponPierceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(ItemWeaponSlashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityBloodFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityDarkFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityEarthFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityFireFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityFleshFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityForceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityHolyFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityIceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityLightFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityMindFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityShockFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAffinityWindFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAlchemyAlchemistFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAlchemyChemistFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAlchemyEnergistFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillAlchemyHealerFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownBowbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownGoldbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownHammerbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownPlatebaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownScalebaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownShieldbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownSpellbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownStudRemoverFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownSwordbaneFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillBreakdownThreadbareFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatAmbidextrousFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatAvatarFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatBarbarianFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatBlademasterFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatFocusedFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatMageFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatRogueFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCombatStalwartFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingBowsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingGoldsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingHammersmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingPlatesmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingScalesmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingShieldsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingSpellsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingSwordsmithFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingTannerFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillCraftingWeaverFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponBashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponBlockFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponBreakFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponCleaveFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponCounterFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponCrackFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponCriticalShotFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponCrushFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponDecapitateFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponDodgeFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponDrillFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponImpactFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponImpaleFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponParryFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponPierceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponRiposteFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponRushFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponSeverFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponShootFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponSlashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponSliceFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponSlitFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponSmashFile, Gecko::Config)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillWeaponStealthStrikeFile, Gecko::Config)
    ;
    PyBindVector<Gecko::ConfigArray>(m, "ConfigArray");

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
