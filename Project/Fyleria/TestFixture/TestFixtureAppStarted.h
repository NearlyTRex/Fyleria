// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_TEST_FIXTURE_TEST_FIXTURE_APP_STARTED_H_
#define _GECKO_TEST_FIXTURE_TEST_FIXTURE_APP_STARTED_H_

// Internal includes
#include "TestFixture/TestFixture.h"
#include "Application/Application.h"

namespace Gecko
{

// TestFixtureAppStarted
class TestFixtureAppStarted : public TestFixture
{
public:

    // Constructor
    TestFixtureAppStarted();

    // Destructor
    virtual ~TestFixtureAppStarted();

    // Setup
    virtual void Setup() override;

    // Teardown
    virtual void Teardown() override;

    // Application
    MAKE_RAW_TYPE_ACCESSORS(Application, Application);
};

};

#endif
