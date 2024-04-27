// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Cache/CacheManager.h"
#include "Utility/Errors.h"

namespace Gecko
{

CacheManager::CacheManager()
{
}

Bool CacheManager::CreateBasicCache(ULong uID, ULong uCapacity)
{
    // Check if cache exists
    if(DoesBasicCacheExist(uID))
    {
        THROW_RUNTIME_ERROR("Cache '" + BoostLexicalCast<String>(uID) + "' was already registered");
    }

    // Create a new cache
    BasicCache newCache;
    newCache.Initialize(uCapacity);
    GetBasicCacheMap().insert({uID, newCache});
    return true;
}

Bool CacheManager::CreateTimedCache(ULong uID, ULong uCapacity, Double fTimeToLive)
{
    // Check if cache exists
    if(DoesTimedCacheExist(uID))
    {
        THROW_RUNTIME_ERROR("Cache '" + BoostLexicalCast<String>(uID) + "' was already registered");
    }

    // Create a new cache
    TimedCache newCache;
    newCache.Initialize(uCapacity, fTimeToLive);
    GetTimedCacheMap().insert({uID, newCache});
    return true;
}

Bool CacheManager::RemoveBasicCache(ULong uID)
{
    // Check if cache exists
    if(!DoesBasicCacheExist(uID))
    {
        THROW_RUNTIME_ERROR("Cache '" + BoostLexicalCast<String>(uID) + "' was not found");
    }

    // Remove cache
    GetBasicCacheMap().erase(uID);
    return true;
}

Bool CacheManager::RemoveTimedCache(ULong uID)
{
    // Check if cache exists
    if(!DoesTimedCacheExist(uID))
    {
        THROW_RUNTIME_ERROR("Cache '" + BoostLexicalCast<String>(uID) + "' was not found");
    }

    // Remove cache
    GetTimedCacheMap().erase(uID);
    return true;
}

Bool CacheManager::DoesBasicCacheExist(ULong uID) const
{
    // Determine if cache exists
    auto iSearch = GetBasicCacheMap().find(uID);
    return (iSearch != GetBasicCacheMap().end());
}

Bool CacheManager::DoesTimedCacheExist(ULong uID) const
{
    // Determine if cache exists
    auto iSearch = GetTimedCacheMap().find(uID);
    return (iSearch != GetTimedCacheMap().end());
}

const BasicCache& CacheManager::GetBasicCache(ULong uID) const
{
    // Get cache
    auto iSearch = GetBasicCacheMap().find(uID);
    if(iSearch != GetBasicCacheMap().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown cache requested: " + BoostLexicalCast<String>(uID));
}

BasicCache& CacheManager::GetBasicCache(ULong uID)
{
    // Get cache
    return const_cast<BasicCache&>(static_cast<const CacheManager&>(*this).GetBasicCache(uID));
}

const TimedCache& CacheManager::GetTimedCache(ULong uID) const
{
    // Get cache
    auto iSearch = GetTimedCacheMap().find(uID);
    if(iSearch != GetTimedCacheMap().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown cache requested: " + BoostLexicalCast<String>(uID));
}

TimedCache& CacheManager::GetTimedCache(ULong uID)
{
    // Get cache
    return const_cast<TimedCache&>(static_cast<const CacheManager&>(*this).GetTimedCache(uID));
}

};
