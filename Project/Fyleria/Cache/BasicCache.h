// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BASIC_CACHE_H_
#define _GECKO_BASIC_CACHE_H_

// Internal includes
#include "Cache/CacheInterface.h"

namespace Gecko
{

// Basic cache
class BasicCache : public CacheInterface
{
public:

    // Typedefs
    typedef RawMemCacheBasicType<String, String> MemCacheType;
    typedef STDSharedPtr<MemCacheType> MemCacheTypeSharedPtr;

    // Constructors
    BasicCache();

    // Destructor
    virtual ~BasicCache();

    // Initialize
    virtual Bool Initialize(ULong uCapacity);

    // Determine if key exists
    virtual Bool ContainsKey(const String& sKey) override;

    // Set value
    virtual Bool SetValue(const String& sKey, const String& sValue) override;

    // Get value
    virtual Bool GetValue(const String& sKey, String& sValue) override;

    // Erase value
    virtual Bool EraseValue(const String& sKey) override;

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
    virtual Bool IsExpired(const String& sKey) const override;

    // Determine if all elements are expired
    virtual Bool AreAllExpired() const override;

    // Determine if the given value is valid
    virtual Bool IsValid(const String& sKey) const override;

    // Mem cache
    MAKE_RAW_TYPE_ACCESSORS(MemCache, MemCacheTypeSharedPtr);
};

// Typedef
MAKE_COMMON_TYPEDEFS(BasicCache);

};

#endif
