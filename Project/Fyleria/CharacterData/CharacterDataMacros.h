// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_DATA_MACROS_H_
#define _GECKO_CHARACTER_CHARACTER_DATA_MACROS_H_

//======================================================================================================================

#define MAKE_STAT_TYPE_ACCESSORS(name, type)                                                                            \
type Get##name() const { return GetStatValue<type>(#name); }                                                            \
void Set##name(const type& var##name) { SetStatValue(#name, var##name); }

//======================================================================================================================

#endif
