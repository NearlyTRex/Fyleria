// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CONFIG_CONFIG_MANAGER_H_
#define _GECKO_CONFIG_CONFIG_MANAGER_H_

// Internal includes
#include "Config/Config.h"

namespace Gecko
{

// Config manager
class ConfigManager
{
public:

    // Types
    typedef STDUnorderedMap<String, Config> ConfigMappingType;

    // Constructors
    ConfigManager();

    // Load config
    Bool LoadConfig(const String& sName, const Config& config);

    // Load config from file
    Bool LoadConfigFromFile(const String& sName, const String& sFile);

    // Save config to file
    Bool SaveConfigToFile(const String& sName, const String& sFile);

    // Create config
    Bool CreateConfig(const String& sName);

    // Does a config file exist
    Bool DoesConfigFileExist(const String& sFile) const;

    // Does a config exist
    Bool DoesConfigExist(const String& sName) const;

    // Get config
    const Config& GetConfig(const String& sName) const;
    Config& GetConfig(const String& sName);

    // Get current config
    const Config& GetCurrentConfig() const;
    Config& GetCurrentConfig();

    // Current config name
    MAKE_RAW_TYPE_ACCESSORS(CurrentConfigName, String);

    // Configuration map
    MAKE_RAW_TYPE_ACCESSORS(ConfigMap, ConfigMappingType);

    // Platforms
    Bool Is32Bit() const;
    Bool Is64Bit() const;
    Bool IsPosix() const;
    Bool IsWindows() const;
    Bool IsLinux() const;
    Bool IsMacOS() const;
    Bool IsIOS() const;
    Bool IsAndroid() const;
};

};

#endif
