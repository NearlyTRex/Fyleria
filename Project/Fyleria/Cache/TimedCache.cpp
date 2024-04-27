// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Cache/TimedCache.h"

namespace Gecko
{

TimedCache::TimedCache()
{
}

TimedCache::~TimedCache()
{
}

Bool TimedCache::Initialize(ULong uCapacity, Double fTimeToLive)
{
    STDDuration<Double, STDRatioMilli> duration(fTimeToLive);
    SetMemCache(STDMakeSharedPtr<MemCacheType>(duration, uCapacity));
    if(!GetMemCache())
    {
        return false;
    }
    return true;
}

Bool TimedCache::ContainsKey(const CacheKey& key)
{
    if(GetMemCache())
    {
        return GetMemCache()->contains(key);
    }
    return false;
}

Bool TimedCache::SetValue(const CacheKey& key, const String& sValue)
{
    if(GetMemCache())
    {
        GetMemCache()->insert(key, sValue);
        return true;
    }
    return false;
}

Bool TimedCache::GetValue(const CacheKey& key, String& sValue)
{
    if(GetMemCache())
    {
        sValue = GetMemCache()->lookup(key);
        return true;
    }
    return false;
}

Bool TimedCache::EraseValue(const CacheKey& key)
{
    if(GetMemCache())
    {
        return GetMemCache()->erase(key);
    }
    return false;
}

Bool TimedCache::Shrink(SizeType uNewCapacity)
{
    if(GetMemCache())
    {
        GetMemCache()->shrink(uNewCapacity);
        return true;
    }
    return false;
}

Bool TimedCache::Resize(SizeType uNewCapacity)
{
    if(GetMemCache())
    {
        GetMemCache()->capacity(uNewCapacity);
        return true;
    }
    return false;
}

SizeType TimedCache::GetCapacity() const
{
    if(GetMemCache())
    {
        return GetMemCache()->capacity();
    }
    return 0;
}

SizeType TimedCache::GetSize() const
{
    if(GetMemCache())
    {
        return GetMemCache()->size();
    }
    return 0;
}

SizeType TimedCache::GetSpaceLeft() const
{
    if(GetMemCache())
    {
        return GetMemCache()->space_left();
    }
    return 0;
}

Bool TimedCache::Clear()
{
    if(GetMemCache())
    {
        GetMemCache()->clear();
        return true;
    }
    return false;
}

Bool TimedCache::ClearExpired()
{
    if(GetMemCache())
    {
        GetMemCache()->clear_expired();
        return true;
    }
    return false;
}

Bool TimedCache::IsEmpty() const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_empty();
    }
    return false;
}

Bool TimedCache::IsFull() const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_full();
    }
    return false;
}

Bool TimedCache::IsExpired(const CacheKey& key) const
{
    if(GetMemCache())
    {
        return GetMemCache()->has_expired(key);
    }
    return false;
}

Bool TimedCache::AreAllExpired() const
{
    if(GetMemCache())
    {
        return GetMemCache()->all_expired();
    }
    return false;
}

Bool TimedCache::IsValid(const CacheKey& key) const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_valid(GetMemCache()->find(key));
    }
    return false;
}

};
