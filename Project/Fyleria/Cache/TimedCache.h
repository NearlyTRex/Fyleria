// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_TIMED_CACHE_H_
#define _GECKO_TIMED_CACHE_H_

// Internal includes
#include "Cache/CacheInterface.h"

namespace Gecko
{

// Timed cache
class TimedCache : public CacheInterface
{
public:

    // Typedefs
    typedef RawMemCacheTimedType<CacheKeyType, String> MemCacheType;
    typedef STDSharedPtr<MemCacheType> MemCacheTypeSharedPtr;

    // Constructors
    TimedCache();

    // Destructor
    virtual ~TimedCache();

    // Initialize
    virtual Bool Initialize(ULong uCapacity, Double fTimeToLive);

    // Determine if key exists
    virtual Bool ContainsKey(const CacheKeyType& key) override;

    // Set value
    virtual Bool SetValue(const CacheKeyType& key, const String& sValue) override;

    // Get value
    virtual Bool GetValue(const CacheKeyType& key, String& sValue) override;

    // Erase value
    virtual Bool EraseValue(const CacheKeyType& key) override;

    // Shrink to the given number of elements
    virtual Bool Shrink(SizeType uNewCapacity) override;

    // Resize capacity
    virtual Bool Resize(SizeType uNewCapacity) override;

    // Get capacity
    virtual SizeType GetCapacity() const override;

    // Get the number of elements
    virtual SizeType GetSize() const override;

    // Get the number of remaining elements
    virtual SizeType GetSpaceLeft() const override;

    // Clear all values
    virtual Bool Clear() override;

    // Clear all expired values
    virtual Bool ClearExpired() override;

    // Determine if empty
    virtual Bool IsEmpty() const override;

    // Determine if full
    virtual Bool IsFull() const override;

    // Determine if the given value is expired
    virtual Bool IsExpired(const CacheKeyType& key) const override;

    // Determine if all elements are expired
    virtual Bool AreAllExpired() const override;

    // Determine if the given value is valid
    virtual Bool IsValid(const CacheKeyType& key) const override;

    // Mem cache
    MAKE_RAW_TYPE_ACCESSORS(MemCache, MemCacheTypeSharedPtr);
};

// Typedef
MAKE_COMMON_TYPEDEFS(TimedCache);

};

#endif
