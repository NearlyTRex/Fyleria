// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Config/ConfigManager.h"
#include "Utility/Errors.h"
#include "Utility/Converters.h"
#include "Utility/Serialization.h"
#include "Application/Application.h"

namespace Gecko
{

ConfigManager::ConfigManager()
{
}

Bool ConfigManager::LoadConfig(const String& sName, const Config& config)
{
    // Add config
    GetConfigMap().insert({sName, config});

    // Check config
    return DoesConfigExist(sName);
}

Bool ConfigManager::LoadConfigFromFile(const String& sName, const String& sFile)
{
    // Read json data into config object
    Json jsonData;
    if(!ReadJsonFile(sFile, jsonData, GetManagers()->GetFileManager()->GetDataDirectory()))
    {
        return false;
    }

    // Add config
    GetConfigMap().insert({sName, Config(jsonData)});

    // Check config
    return DoesConfigExist(sName);
}

Bool ConfigManager::SaveConfigToFile(const String& sName, const String& sFile)
{
    // Write json data from config object
    Json jsonData = GetConfig(sName);
    return WriteJsonFile(sFile, jsonData, GetManagers()->GetFileManager()->GetDataDirectory());
}

Bool ConfigManager::CreateConfig(const String& sName)
{
    // Create config
    GetConfigMap().insert({sName, Config()});

    // Check config
    return DoesConfigExist(sName);
}

Bool ConfigManager::DoesConfigFileExist(const String& sFile) const
{
    // Determine if config file exists
    String sFullPath = GetManagers()->GetFileManager()->JoinPaths(GetManagers()->GetFileManager()->GetDataDirectory(), sFile);
    return GetManagers()->GetFileManager()->IsFile(sFullPath);
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

Config& ConfigManager::GetConfig(const String& sName)
{
    // Get config
    return const_cast<Config&>(static_cast<const ConfigManager&>(*this).GetConfig(sName));
}

const Config& ConfigManager::GetCurrentConfig() const
{
    // Get current config
    return GetConfig(GetCurrentConfigName());
}

Config& ConfigManager::GetCurrentConfig()
{
    // Get current config
    return const_cast<Config&>(static_cast<const ConfigManager&>(*this).GetCurrentConfig());
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
