// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Window/BrowserEngine.h"

namespace Gecko
{

BrowserEngine::BrowserEngine()
{
}

BrowserEngine::~BrowserEngine()
{
}

void BrowserEngine::Shutdown()
{
    // Mark as shutting down
    GetIsShuttingDown() = true;
}

void BrowserEngine::BindSynchronousFunction(const String& sName, SynchronousFunction fnFunc)
{
    // Add bound function
    GetBoundFunctions()->insert(sName);
}

void BrowserEngine::BindAsynchronousFunction(const String& sName, AsynchronousFunction fnFunc, void* pArg)
{
    // Add bound function
    GetBoundFunctions()->insert(sName);
}

void BrowserEngine::UnbindFunction(const String& sName)
{
    // Remove bound function
    GetBoundFunctions()->erase(sName);
}

void BrowserEngine::UnbindAllFunctions()
{
    // Get all bound functions
    StringArray vFunctions;
    for (auto it = GetBoundFunctions()->begin(); it != GetBoundFunctions()->end(); it++)
    {
        vFunctions.push_back(*it);
    }

    // Unbind all functions
    for (String& sName : vFunctions)
    {
        UnbindFunction(sName);
    }
}

};
