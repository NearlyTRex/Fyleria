// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_CONVERTERS_H_
#define _GECKO_UTILITY_CONVERTERS_H_

// Internal includes
#include "Utility/Types.h"

namespace Gecko
{

// Convert string to wide string
WString ConvertStringToWideString(const String& sString);

// Convert wide string to string
String ConvertWideStringToString(const WString& sWideString);

// Convert game time to string
String ConvertGameTimeToString(ULongLong uTime);

};

#endif
