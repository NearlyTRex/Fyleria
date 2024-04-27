// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_TIME_H_
#define _GECKO_UTILITY_TIME_H_

// Internal includes
#include "Utility/Types.h"

namespace Gecko
{

// Get formatted timestamp
String GetFormattedTimestamp(const TimeType& time, const String& sFormat);

};

#endif
