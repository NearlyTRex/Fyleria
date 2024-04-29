// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_ASSERT_H_
#define _GECKO_UTILITY_ASSERT_H_

// External includes
#include <ppk_assert.h>

// External defines
#define RUNTIME_ASSERT PPK_ASSERT
#define RUNTIME_WARNING_ASSERT PPK_ASSERT_WARNING
#define RUNTIME_DEBUG_ASSERT PPK_ASSERT_DEBUG
#define RUNTIME_ERROR_ASSERT PPK_ASSERT_ERROR
#define RUNTIME_FATAL_ASSERT PPK_ASSERT_FATAL
#define STATIC_ASSERT PPK_STATIC_ASSERT

#endif
