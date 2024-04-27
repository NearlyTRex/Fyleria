// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_TEST_FIXTURE_TEST_FIXTURE_H_
#define _GECKO_TEST_FIXTURE_TEST_FIXTURE_H_

// Internal includes
#include "Application/Application.h"

namespace Gecko
{

// TestFixture
class TestFixture
{
public:

    // Constructor
    TestFixture();

    // Destructor
    virtual ~TestFixture();

    // Setup
    virtual void Setup() = 0;

    // Teardown
    virtual void Teardown() = 0;
};

};

#endif
