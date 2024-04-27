// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_TEST_FIXTURE_TEST_FIXTURE_APP_LOADED_H_
#define _GECKO_TEST_FIXTURE_TEST_FIXTURE_APP_LOADED_H_

// Internal includes
#include "TestFixture/TestFixtureAppStarted.h"

namespace Gecko
{

// TestFixtureAppLoaded
class TestFixtureAppLoaded : public TestFixtureAppStarted
{
public:

    // Constructor
    TestFixtureAppLoaded();

    // Destructor
    virtual ~TestFixtureAppLoaded();

    // Setup
    virtual void Setup() override;

    // Teardown
    virtual void Teardown() override;
};

};

#endif
