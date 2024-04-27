// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CACHE_BASIC_CACHE_H_
#define _GECKO_CACHE_BASIC_CACHE_H_

// Internal includes
#include "Cache/CacheInterface.h"

namespace Gecko
{

// Basic cache
class BasicCache : public CacheInterface
{
public:

    // Typedefs
    typedef RawMemCacheBasicType<CacheKey, String> MemCacheType;
    typedef STDSharedPtr<MemCacheType> MemCacheTypeSharedPtr;

    // Constructors
    BasicCache();

    // Destructor
    virtual ~BasicCache();

    // Initialize
    virtual Bool Initialize(ULong uCapacity);

    // Determine if key exists
    virtual Bool ContainsKey(const CacheKey& key) override;

    // Set value
    virtual Bool SetValue(const CacheKey& key, const String& sValue) override;

    // Get value
    virtual Bool GetValue(const CacheKey& key, String& sValue) override;

    // Erase value
    virtual Bool EraseValue(const CacheKey& key) override;

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
    virtual Bool IsExpired(const CacheKey& key) const override;

    // Determine if all elements are expired
    virtual Bool AreAllExpired() const override;

    // Determine if the given value is valid
    virtual Bool IsValid(const CacheKey& key) const override;

    // Mem cache
    MAKE_RAW_TYPE_ACCESSORS(MemCache, MemCacheTypeSharedPtr);
};

// Typedef
MAKE_COMMON_TYPEDEFS(BasicCache);

};

#endif
