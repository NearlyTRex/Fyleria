// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Config/ConfigManager.h"
#include "Utility/Assert.h"
#include "Utility/Errors.h"
#include "Utility/Converters.h"
#include "Utility/Filesystem.h"
#include "Utility/Serialization.h"

namespace Gecko
{

ConfigManager::ConfigManager()
    : Singleton<ConfigManager>()
{
}

Bool ConfigManager::LoadConfig(const String& sName, const String& sFile)
{
    // Check if file exists
    if(!DoesPathExist(sFile))
    {
        THROW_RUNTIME_ERROR("Path '" + sFile + "' could not be loaded for configuration");
    }

    // Read json data into config object
    Json jsonData;
    if(!ReadJsonFile(sFile, jsonData))
    {
        return false;
    }

    // Add config
    GetLoadedConfigs().insert({sName, Config(jsonData)});
    return true;
}

Bool ConfigManager::DoesConfigExist(const String& sName) const
{
    // Determine if config exists
    auto iSearch = GetLoadedConfigs().find(sName);
    return (iSearch != GetLoadedConfigs().end());
}

const Config& ConfigManager::GetConfig(const String& sName) const
{
    // Check if config exists
    if(!DoesConfigExist(sName))
    {
        THROW_RUNTIME_ERROR("Config with name '" + sName + "' was not registered");
    }

    // Get config
    auto iSearch = GetLoadedConfigs().find(sName);
    if(iSearch != GetLoadedConfigs().end())
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
#if defined(__i386__) || defined(_WIN32)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::Is64Bit() const
{
#if defined(__x86_64__) || defined(_WIN64)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsPosix() const
{
#if defined(_POSIX_VERSION)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsWindows() const
{
#if defined(_WIN64) || defined(_WIN32)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsLinux() const
{
#if defined(__linux__)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsMacOS() const
{
#if TARGET_OS_MAC == 1
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsIOS() const
{
#if (TARGET_IPHONE_SIMULATOR == 1) || (TARGET_OS_IPHONE == 1)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsAndroid() const
{
#if defined(__ANDROID__)
    return true;
#else
    return false;
#endif
}

};
