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
    // Initialize app
    GetApplication().InitializeForTesting();
}

void TestFixtureAppLoaded::Teardown()
{
    // Finalize app
    GetApplication().Finalize();
}

};
