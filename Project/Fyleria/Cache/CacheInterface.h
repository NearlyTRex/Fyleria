// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CACHE_CACHE_INTERFACE_H_
#define _GECKO_CACHE_CACHE_INTERFACE_H_

// Internal includes
#include "Cache/CacheKey.h"
#include "Utility/Types.h"
#include "Utility/Macros.h"
#include "Utility/MemCache.h"

namespace Gecko
{

// Cache interface
class CacheInterface
{
public:

    // Determine if key exists
    virtual Bool ContainsKey(const CacheKey& key) = 0;

    // Set value
    virtual Bool SetValue(const CacheKey& key, const String& sValue) = 0;

    // Get value
    virtual Bool GetValue(const CacheKey& key, String& sValue) = 0;

    // Erase value
    virtual Bool EraseValue(const CacheKey& key) = 0;

    // Shrink to the given number of elements
    virtual Bool Shrink(SizeType uNewCapacity) = 0;

    // Resize capacity
    virtual Bool Resize(SizeType uNewCapacity) = 0;

    // Get capacity
    virtual SizeType GetCapacity() const = 0;

    // Get the number of elements
    virtual SizeType GetSize() const = 0;

    // Get the number of remaining elements
    virtual SizeType GetSpaceLeft() const = 0;

    // Clear all values
    virtual Bool Clear() = 0;

    // Clear all expired values
    virtual Bool ClearExpired() = 0;

    // Determine if empty
    virtual Bool IsEmpty() const = 0;

    // Determine if full
    virtual Bool IsFull() const = 0;

    // Determine if the given value is expired
    virtual Bool IsExpired(const CacheKey& key) const = 0;

    // Determine if all elements are expired
    virtual Bool AreAllExpired() const = 0;

    // Determine if the given value is valid
    virtual Bool IsValid(const CacheKey& key) const = 0;
};

};

#endif
