// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Config/ConfigManager.h"
#include "Utility/Assert.h"
#include "Utility/Errors.h"
#include "Utility/Converters.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

ConfigManager::ConfigManager()
    : Singleton<ConfigManager>()
{
}

Bool ConfigManager::LoadConfig(const String& sName, const String& sFile)
{
    // Create full path
    ASSERT_ERROR(DoesPathExist(sFile), "Path '%s' could not be loaded for configuration", sFile.c_str());
    if(!DoesPathExist(sFile))
    {
        return false;
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
    auto iSearch = GetLoadedConfigs().find(sName);
    return (iSearch != GetLoadedConfigs().end());
}

const Config& ConfigManager::GetConfig(const String& sName) const
{
    ASSERT_ERROR(DoesConfigExist(sName), "Config with name '%s' was not registered", sName.c_str());
    auto iSearch = GetLoadedConfigs().find(sName);
    if(iSearch != GetLoadedConfigs().end())
    {
        return iSearch->second;
    }
    throw RuntimeError("Invalid or unknown config requested: " + sName);
}

const Config& ConfigManager::GetCurrentConfig() const
{
    return GetConfig(GetCurrentConfigName());
}

String ConfigManager::GetConstructedConfigFilename() const
{
    return GetCanonicalPath(JoinPaths(GetUserConfigFolder(), GetUserConfigFile()));
}

String ConfigManager::GetConstructedPythonLibraryFilename() const
{
    return GetCanonicalPath(JoinPaths(GetUserDataFolder(), GetPythonLibraryFile()));
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

Bool ConfigManager::IsWindows32() const
{
#if defined(_WIN32)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsWindows64() const
{
#if defined(_WIN64)
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

Bool ConfigManager::IsLinux32() const
{
#if defined(__linux__) && defined(__i386__)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsLinux64() const
{
#if defined(__linux__) && defined(__x86_64__)
    return true;
#else
    return false;
#endif
}

Bool ConfigManager::IsMac() const
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
