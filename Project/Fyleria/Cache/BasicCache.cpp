// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

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
}

Bool BasicCache::ContainsKey(const String& sKey)
{
    if(GetMemCache())
    {
        return GetMemCache()->contains(sKey);
    }
    return false;
}

Bool BasicCache::SetValue(const String& sKey, const String& sValue)
{
    if(GetMemCache())
    {
        GetMemCache()->insert(sKey, sValue);
        return true;
    }
    return false;
}

Bool BasicCache::GetValue(const String& sKey, String& sValue)
{
    if(GetMemCache())
    {
        sValue = GetMemCache()->lookup(sKey);
        return true;
    }
    return false;
}

Bool BasicCache::EraseValue(const String& sKey)
{
    if(GetMemCache())
    {
        return GetMemCache()->erase(sKey);
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

Bool BasicCache::IsExpired(const String& sKey) const
{
    return false;
}

Bool BasicCache::AreAllExpired() const
{
    return false;
}

Bool BasicCache::IsValid(const String& sKey) const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_valid(GetMemCache()->find(sKey));
    }
    return false;
}

};
