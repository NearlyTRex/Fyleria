// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CACHE_MANAGER_H_
#define _GECKO_CACHE_MANAGER_H_

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
    typedef STDUnorderedMap<String, BasicCache> BasicCacheMappingType;
    typedef STDUnorderedMap<String, TimedCache> TimedCacheMappingType;

    // Constructors
    CacheManager();

    // Create basic cache
    Bool CreateBasicCache(const String& sName, ULong uCapacity);

    // Create timed cache
    Bool CreateTimedCache(const String& sName, ULong uCapacity, Double fTimeToLive);

    // Does a basic cache exist
    Bool DoesBasicCacheExist(const String& sName) const;

    // Does a timed cache exist
    Bool DoesTimedCacheExist(const String& sName) const;

    // Get basic cache
    const BasicCache& GetBasicCache(const String& sName) const;
    BasicCache& GetBasicCache(const String& sName);

    // Get timed cache
    const TimedCache& GetTimedCache(const String& sName) const;
    TimedCache& GetTimedCache(const String& sName);

    // Basic cache map
    MAKE_RAW_TYPE_ACCESSORS(BasicCacheMap, BasicCacheMappingType);

    // Timed cache map
    MAKE_RAW_TYPE_ACCESSORS(TimedCacheMap, TimedCacheMappingType);
};

};

#endif
