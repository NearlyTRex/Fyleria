// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Cache/CacheKey.h"
#include "Utility/Constants.h"

namespace Gecko
{

// Cache mutex
STDMutex gCacheKeyMutex;

CacheKeyType GenerateCacheKeyFromString(const String& sString)
{
    // Lock access
    STDLockGuard<STDMutex> lock(gCacheKeyMutex);

    // Cache key counter
    static CacheKeyType cacheKeyCounter = CACHE_KEY_STRING_RANGE_START;

    // Mapping from string to cache key
    static STDUnorderedMap<String, CacheKeyType> tCacheKeyMap = {};

    // Return existing key if already present
    auto iSearch = tCacheKeyMap.find(sString);
    if(iSearch != tCacheKeyMap.end())
    {
        return iSearch->second;
    }

    // Store key
    CacheKeyType cacheKey = cacheKeyCounter;
    tCacheKeyMap.insert({sString, cacheKey});

    // Update key counter
    cacheKeyCounter++;

    // Return key
    return cacheKey;
}

};
