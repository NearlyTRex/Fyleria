// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Cache/BasicCache.h"

namespace Gecko
{

BasicCache::BasicCache()
{
}

BasicCache::~BasicCache()
{
}

Bool BasicCache::Initialize(ULong uCapacity)
{
    SetMemCache(STDMakeSharedPtr<MemCacheType>(uCapacity));
    if(!GetMemCache())
    {
        return false;
    }
    return true;
}

Bool BasicCache::ContainsKey(const CacheKey& key)
{
    if(GetMemCache())
    {
        return GetMemCache()->contains(key);
    }
    return false;
}

Bool BasicCache::SetValue(const CacheKey& key, const String& sValue)
{
    if(GetMemCache())
    {
        GetMemCache()->insert(key, sValue);
        return true;
    }
    return false;
}

Bool BasicCache::GetValue(const CacheKey& key, String& sValue)
{
    if(GetMemCache())
    {
        sValue = GetMemCache()->lookup(key);
        return true;
    }
    return false;
}

Bool BasicCache::EraseValue(const CacheKey& key)
{
    if(GetMemCache())
    {
        return GetMemCache()->erase(key);
    }
    return false;
}

Bool BasicCache::Shrink(SizeType uNewCapacity)
{
    if(GetMemCache())
    {
        GetMemCache()->shrink(uNewCapacity);
        return true;
    }
    return false;
}

Bool BasicCache::Resize(SizeType uNewCapacity)
{
    if(GetMemCache())
    {
        GetMemCache()->capacity(uNewCapacity);
        return true;
    }
    return false;
}

SizeType BasicCache::GetCapacity() const
{
    if(GetMemCache())
    {
        return GetMemCache()->capacity();
    }
    return 0;
}

SizeType BasicCache::GetSize() const
{
    if(GetMemCache())
    {
        return GetMemCache()->size();
    }
    return 0;
}

SizeType BasicCache::GetSpaceLeft() const
{
    if(GetMemCache())
    {
        return GetMemCache()->space_left();
    }
    return 0;
}

Bool BasicCache::Clear()
{
    if(GetMemCache())
    {
        GetMemCache()->clear();
        return true;
    }
    return false;
}

Bool BasicCache::ClearExpired()
{
    return false;
}

Bool BasicCache::IsEmpty() const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_empty();
    }
    return false;
}

Bool BasicCache::IsFull() const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_full();
    }
    return false;
}

Bool BasicCache::IsExpired(const CacheKey& key) const
{
    return false;
}

Bool BasicCache::AreAllExpired() const
{
    return false;
}

Bool BasicCache::IsValid(const CacheKey& key) const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_valid(GetMemCache()->find(key));
    }
    return false;
}

};
