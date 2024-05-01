// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "TestFixture/TestFixtureAppLoaded.h"
#include "Application/Application.h"
#include "Application/ApplicationConstants.h"
#include "Utility/Logging.h"

namespace Gecko
{

TestFixtureAppLoaded::TestFixtureAppLoaded()
    : TestFixtureAppStarted()
{
    Setup();
}

TestFixtureAppLoaded::~TestFixtureAppLoaded()
{
    Teardown();
}

void TestFixtureAppLoaded::Setup()
{
    // Check data directory
    GetApplication().CheckDataDirectory();

    // Initialize logging
    GetApplication().InitializeLogging(APPLICATION_LOGGER_NAME, APPLICATION_LOGGER_LEVEL_TEST);

    // Initialize config
    GetApplication().InitializeConfig(APPLICATION_CONFIG_NAME, APPLICATION_CONFIG_FILE);

    // Initialize saves
    GetApplication().InitializeSaves();

    // Initialize trees
    GetApplication().InitializeTrees();
}

void TestFixtureAppLoaded::Teardown()
{
    // Finalize app
    GetApplication().Finalize();
}

};
