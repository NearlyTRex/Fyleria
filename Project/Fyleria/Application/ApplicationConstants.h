// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_MAIN_APPLICATION_CONSTANTS_H_
#define _GECKO_MAIN_APPLICATION_CONSTANTS_H_

// Internal includes
#include "Utility/Logging.h"
#include "Utility/Types.h"

namespace Gecko
{
    // Application name
    extern const String APPLICATION_NAME_SHORT;
    extern const String APPLICATION_NAME_LONG;

    // Application logger
    extern const String APPLICATION_LOGGER_NAME;
    extern const LoggingLevelType APPLICATION_LOGGER_LEVEL_MAIN;
    extern const LoggingLevelType APPLICATION_LOGGER_LEVEL_TEST;

    // Application config
    extern const String APPLICATION_CONFIG_NAME;
    extern const String APPLICATION_CONFIG_FILE;
};

#endif
