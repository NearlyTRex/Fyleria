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
    if(!GetMemCache())
    {
        return false;
    }
    return true;
}

Bool BasicCache::ContainsKey(Int iKey)
{
    if(GetMemCache())
    {
        return GetMemCache()->contains(iKey);
    }
    return false;
}

Bool BasicCache::SetValue(Int iKey, const String& sValue)
{
    if(GetMemCache())
    {
        GetMemCache()->insert(iKey, sValue);
        return true;
    }
    return false;
}

Bool BasicCache::GetValue(Int iKey, String& sValue)
{
    if(GetMemCache())
    {
        sValue = GetMemCache()->lookup(iKey);
        return true;
    }
    return false;
}

Bool BasicCache::EraseValue(Int iKey)
{
    if(GetMemCache())
    {
        return GetMemCache()->erase(iKey);
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

Bool BasicCache::IsExpired(Int iKey) const
{
    return false;
}

Bool BasicCache::AreAllExpired() const
{
    return false;
}

Bool BasicCache::IsValid(Int iKey) const
{
    if(GetMemCache())
    {
        return GetMemCache()->is_valid(GetMemCache()->find(iKey));
    }
    return false;
}

};
