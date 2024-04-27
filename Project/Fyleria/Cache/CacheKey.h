// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CACHE_CACHE_KEY_H_
#define _GECKO_CACHE_CACHE_KEY_H_

// Internal includes
#include "Utility/Types.h"

namespace Gecko
{

// Cache key type
typedef ULongLong CacheKey;

// Generate cache key
// Based on Jenkins's one_at_a_time hash
// https://en.wikipedia.org/wiki/Jenkins_hash_function
template<class T>
CacheKey GenerateCacheKey(const T& value)
{
    CacheKey cacheKey = 0;
    for(auto it = value.cbegin(); it != value.cend(); it++)
    {
        cacheKey += *it;
        cacheKey += (cacheKey << 10);
        cacheKey ^= (cacheKey >> 6);
    }
    cacheKey += (cacheKey << 3);
    cacheKey ^= (cacheKey >> 11);
    cacheKey += (cacheKey << 15);
    return cacheKey;
}

};

#endif
