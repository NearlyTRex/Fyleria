// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_SINGLETON_H_
#define _GECKO_UTILITY_SINGLETON_H_

// Internal includes
#include "Utility/ObjectThreadsafe.h"

namespace Gecko
{

// Singleton
template<typename T>
class Singleton
{
public:

    // Constructors
    Singleton() = default;
    ~Singleton() = default;

    // Get instance
    static SafePtr<T>& GetInstance()
    {
        return m_pInstance;
    }

private:

    // Instance
    static SafePtr<T> m_pInstance;

    // Deleted
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

// Singleton instance
template<typename T>
SafePtr<T> Singleton<T>::m_pInstance = {};

};

#endif
