// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CACHE_KEY_H_
#define _GECKO_CACHE_KEY_H_

// Internal includes
#include "Utility/Types.h"

namespace Gecko
{

// Cache key type
typedef ULongLong CacheKeyType;

// Generate cache key from string
CacheKeyType GenerateCacheKeyFromString(const String& sString);

};

#endif
