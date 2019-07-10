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

    // Current config name
    MAKE_RAW_TYPE_ACCESSORS(CurrentConfigName, String);

    // Config data
    MAKE_RAW_TYPE_ACCESSORS(UserConfigFile, String);
    MAKE_RAW_TYPE_ACCESSORS(UserConfigFolder, String);
    MAKE_RAW_TYPE_ACCESSORS(UserDataFolder, String);
    MAKE_RAW_TYPE_ACCESSORS(UserCacheFolder, String);
    MAKE_RAW_TYPE_ACCESSORS(UserWebFolder, String);
    MAKE_RAW_TYPE_ACCESSORS(PythonLibraryFile, String);
    MAKE_RAW_TYPE_ACCESSORS(ScreenWidth, Int);
    MAKE_RAW_TYPE_ACCESSORS(ScreenHeight, Int);

    // Configuration map
    MAKE_RAW_TYPE_ACCESSORS(LoadedConfigs, ConfigMappingType);

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
