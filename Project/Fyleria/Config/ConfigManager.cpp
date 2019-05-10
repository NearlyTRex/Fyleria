// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Config/ConfigManager.h"
#include "Utility/Assert.h"
#include "Utility/Converters.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

Config ConfigManager::s_EmptyConfig = {};

ConfigManager::ConfigManager()
    : Singleton<ConfigManager>()
{
}

Bool ConfigManager::LoadConfig(const String& sName, const String& sFile)
{
    // Create full path
    String sPathConfigFile = JoinPaths(GetUserConfigFolder(), sFile);
    ASSERT_ERROR(DoesFileExist(sPathConfigFile), "Path '%s' could not be loaded for configuration", sPathConfigFile.c_str());
    if(!DoesFileExist(sPathConfigFile))
    {
        return false;
    }

    // Read json data into config object
    Json jsonData;
    if(!ReadJsonFile(IndexedString(sPathConfigFile), jsonData))
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
    return (iSearch != GetLoadedConfigs().end()) ? iSearch->second : s_EmptyConfig;
}

const Config& ConfigManager::GetCurrentConfig() const
{
    return GetConfig(GetCurrentConfigName());
}

String ConfigManager::GetPythonLib() const
{
    return JoinPaths(GetUserConfigFolder(), GetCurrentConfig().GetPythonLib());
}

WString ConfigManager::GetPythonLibW() const
{
    return ConvertStringToWideString(GetPythonLib());
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
