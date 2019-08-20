// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Cache/CacheManager.h"
#include "Utility/Errors.h"

namespace Gecko
{

CacheManager::CacheManager()
{
}

Bool CacheManager::CreateBasicCache(const String& sName, ULong uCapacity)
{
    return false;
}

Bool CacheManager::CreateTimedCache(const String& sName, ULong uCapacity, Double fTimeToLive)
{
    return false;
}

Bool CacheManager::DoesBasicCacheExist(const String& sName) const
{
    // Determine if cache exists
    auto iSearch = GetBasicCacheMap().find(sName);
    return (iSearch != GetBasicCacheMap().end());
}

Bool CacheManager::DoesTimedCacheExist(const String& sName) const
{
    // Determine if cache exists
    auto iSearch = GetTimedCacheMap().find(sName);
    return (iSearch != GetTimedCacheMap().end());
}

const BasicCache& CacheManager::GetBasicCache(const String& sName) const
{
    // Get cache
    auto iSearch = GetBasicCacheMap().find(sName);
    if(iSearch != GetBasicCacheMap().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown cache requested: " + sName);
}

BasicCache& CacheManager::GetBasicCache(const String& sName)
{
    // Get cache
    return const_cast<BasicCache&>(static_cast<const CacheManager&>(*this).GetBasicCache(sName));
}

const TimedCache& CacheManager::GetTimedCache(const String& sName) const
{
    // Get cache
    auto iSearch = GetTimedCacheMap().find(sName);
    if(iSearch != GetTimedCacheMap().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown cache requested: " + sName);
}

TimedCache& CacheManager::GetTimedCache(const String& sName)
{
    // Get cache
    return const_cast<TimedCache&>(static_cast<const CacheManager&>(*this).GetTimedCache(sName));
}

};
