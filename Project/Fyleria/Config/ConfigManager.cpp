// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Config/ConfigManager.h"
#include "Utility/Errors.h"
#include "Utility/Converters.h"
#include "Utility/Serialization.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

ConfigManager::ConfigManager()
{
}

Bool ConfigManager::LoadConfig(ManagerSet* pManagerSet, const String& sName, const String& sFile)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Read json data into config object
    Json jsonData;
    if(!ReadJsonFile(pManagerSet, sFile, jsonData, pManagerSet->GetFileManager()->GetDataDirectory()))
    {
        THROW_RUNTIME_ERROR("Path '" + sFile + "' could not be loaded for configuration");
    }

    // Add config
    GetConfigMap().insert({sName, Config(jsonData)});
    return true;
}

Bool ConfigManager::DoesConfigExist(const String& sName) const
{
    // Determine if config exists
    auto iSearch = GetConfigMap().find(sName);
    return (iSearch != GetConfigMap().end());
}

const Config& ConfigManager::GetConfig(const String& sName) const
{
    // Check if config exists
    if(!DoesConfigExist(sName))
    {
        THROW_RUNTIME_ERROR("Config with name '" + sName + "' was not found");
    }

    // Get config
    auto iSearch = GetConfigMap().find(sName);
    if(iSearch != GetConfigMap().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown config requested: " + sName);
}

const Config& ConfigManager::GetCurrentConfig() const
{
    // Get current config
    return GetConfig(GetCurrentConfigName());
}

Bool ConfigManager::Is32Bit() const
{
#if defined(PLATFORM_32_BIT)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::Is64Bit() const
{
#if defined(PLATFORM_64_BIT)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsPosix() const
{
#if defined(PLATFORM_POSIX)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsWindows() const
{
#if defined(PLATFORM_OS_WINDOWS)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsLinux() const
{
#if defined(PLATFORM_OS_LINUX)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsMacOS() const
{
#if defined(PLATFORM_OS_MACOS)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsIOS() const
{
#if defined(PLATFORM_OS_IOS)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsAndroid() const
{
#if defined(PLATFORM_OS_ANDROID)
    return true;
#else
    return false;
#endif
}

};
