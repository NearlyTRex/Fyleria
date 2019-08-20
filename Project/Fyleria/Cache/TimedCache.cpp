// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

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
    return false;
}

Bool TimedCache::ContainsKey(const String& sKey)
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::SetValue(const String& sKey, const String& sValue)
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::GetValue(const String& sKey, String& sValue)
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::EraseValue(const String& sKey)
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::Shrink(SizeType uNewCapacity)
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::Resize(SizeType uNewCapacity)
{
    if(GetMemCache())
    {

    }
    return false;
}

SizeType TimedCache::GetCapacity() const
{
    if(GetMemCache())
    {

    }
    return 0;
}

SizeType TimedCache::GetSize() const
{
    if(GetMemCache())
    {

    }
    return 0;
}

SizeType TimedCache::GetSpaceLeft() const
{
    if(GetMemCache())
    {

    }
    return 0;
}

Bool TimedCache::Clear()
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::ClearExpired()
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::IsEmpty() const
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::IsFull() const
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::IsExpired(const String& sKey) const
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::AreAllExpired() const
{
    if(GetMemCache())
    {

    }
    return false;
}

Bool TimedCache::IsValid(const String& sKey) const
{
    if(GetMemCache())
    {

    }
    return false;
}

};
