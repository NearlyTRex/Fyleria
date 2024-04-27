// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CACHE_CACHE_MANAGER_H_
#define _GECKO_CACHE_CACHE_MANAGER_H_

// Internal includes
#include "Cache/BasicCache.h"
#include "Cache/TimedCache.h"

namespace Gecko
{

// CacheManager
class CacheManager
{
public:

    // Types
    typedef STDUnorderedMap<ULong, BasicCache> BasicCacheMappingType;
    typedef STDUnorderedMap<ULong, TimedCache> TimedCacheMappingType;

    // Constructors
    CacheManager();

    // Create basic cache
    Bool CreateBasicCache(ULong uID, ULong uCapacity);

    // Create timed cache
    Bool CreateTimedCache(ULong uID, ULong uCapacity, Double fTimeToLive);

    // Remove basic cache
    Bool RemoveBasicCache(ULong uID);

    // Remove timed cache
    Bool RemoveTimedCache(ULong uID);

    // Does a basic cache exist
    Bool DoesBasicCacheExist(ULong uID) const;

    // Does a timed cache exist
    Bool DoesTimedCacheExist(ULong uID) const;

    // Get basic cache
    const BasicCache& GetBasicCache(ULong uID) const;
    BasicCache& GetBasicCache(ULong uID);

    // Get timed cache
    const TimedCache& GetTimedCache(ULong uID) const;
    TimedCache& GetTimedCache(ULong uID);

    // Basic cache map
    MAKE_RAW_TYPE_ACCESSORS(BasicCacheMap, BasicCacheMappingType);

    // Timed cache map
    MAKE_RAW_TYPE_ACCESSORS(TimedCacheMap, TimedCacheMappingType);
};

};

#endif
