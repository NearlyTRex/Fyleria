// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Config/ConfigManager.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

ConfigManager::ConfigManager()
    : Singleton<ConfigManager>()
    , m_Empty()
    , m_tConfigs()
    , m_sCurrentConfigName("")
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
    m_tConfigs[sName] = Config(jsonData);
    return true;
}

Bool ConfigManager::DoesConfigExist(const String& sName) const
{
    auto iSearch = m_tConfigs.find(sName);
    return (iSearch != m_tConfigs.end());
}

const Config& ConfigManager::GetConfig(const String& sName) const
{
    ASSERT_ERROR(DoesConfigExist(sName), "Config with name '%s' was not registered", sName.c_str());
    auto iSearch = m_tConfigs.find(sName);
    return (iSearch != m_tConfigs.end()) ? iSearch->second : m_Empty;
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

const String& ConfigManager::GetCurrentConfigName() const
{
    return m_sCurrentConfigName;
}

void ConfigManager::SetCurrentConfigName(const String& sName)
{
    m_sCurrentConfigName = sName;
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
