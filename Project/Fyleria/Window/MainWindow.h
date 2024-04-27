// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_WINDOW_MAIN_WINDOW_H_
#define _GECKO_WINDOW_MAIN_WINDOW_H_

// Internal includes
#include "Window/BrowserEngine.h"
#include "Utility/Types.h"
#include "Utility/Singleton.h"

namespace Gecko
{

// Main window class
class MainWindow : public Singleton<MainWindow>
{
public:

    // Constructor
    MainWindow();

    // Destructor
    virtual ~MainWindow();

    // Browser engine
    MAKE_RAW_TYPE_ACCESSORS(BrowserEngine, BrowserEngineSharedPtr);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(MainWindow);

};

#endif
