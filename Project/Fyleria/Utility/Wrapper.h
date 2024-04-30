// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_WRAPPER_H_
#define _GECKO_UTILITY_WRAPPER_H_

// Internal includes
#include "Utility/Boost.h"
#include "Utility/Types.h"

namespace Gecko
{

// Get wrapper options
BoostProgramOptionsDescription GetWrapperOptions();

// Handle wrapper options
void HandleWrapperOptions(const BoostProgramOptionsDescription& options, const BoostProgramOptionsVariablesMap& vm);

// Write wrapper files
void WriteWrapperFiles();

};

#endif
