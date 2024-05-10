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

#define MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(name, type)                                                                  \
type Get##name##Base() const { return GetStatValue<type>(#name "Base"); }                                               \
type Get##name##Current() const { return GetStatValue<type>(#name "Current"); }                                         \
void Set##name##Base(const type& var##name) { SetStatValue(#name "Base", var##name); }                                  \
void Set##name##Current(const type& var##name) { SetStatValue(#name "Current", var##name); }

#define APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(name)                                                                      \
{                                                                                                                       \
    Set##name##Current(Get##name##Base());                                                                              \
}

#define APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(name)                                                                      \
{                                                                                                                       \
    Set##name##Base(Get##name##Current());                                                                              \
}

//======================================================================================================================

#endif
