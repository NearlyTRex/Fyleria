// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_MAIN_APPLICATION_H_
#define _GECKO_MAIN_APPLICATION_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Macros.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

// Get managers
SafeObject<ManagerSet>& GetManagers();

// Application
class Application
{
public:

    // Constructor
    Application();

    // Destructor
    virtual ~Application();

    // Get application name
    static String GetName();

    // Get application version
    static String GetVersionShort();
    static String GetVersionLong();

    // Initialize
    void Initialize();
    void InitializeForSimulator();
    void InitializeForTesting();

    // Finalize
    void Finalize();

    // Run application
    void Run();

private:

    // Check data directory
    void CheckDataDirectory();

    // Initialize subsystems
    void InitializeLogging(const String& sLogName, LoggingLevelType eLogLevel);
    void InitializeConfig(const String& sConfigName, const String& sConfigFile);
    void InitializeSaves();
    void InitializeTrees();
    void InitializeWindow();

    // Finalize subsystems
    void FinalizeLogging();
    void FinalizeCharacters();
    void FinalizeTrees();
};

};

#endif
