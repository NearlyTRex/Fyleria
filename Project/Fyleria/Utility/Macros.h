// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_MACROS_H_
#define _GECKO_UTILITY_MACROS_H_

//======================================================================================================================

#define THROW_LOGIC_ERROR(message) { throw LogicError(message, __FILE__, __LINE__); }
#define THROW_RUNTIME_ERROR(message) { throw RuntimeError(message, __FILE__, __LINE__); }
#define THROW_INVALID_MANAGER_ERROR() { throw InvalidManagerError(__FILE__, __LINE__); }
#define CHECK_MANAGER_SET_PTR(ptr) { if(!ptr) { THROW_INVALID_MANAGER_ERROR(); } }

//======================================================================================================================

#define MAKE_COMMON_TYPEDEFS(type)                                                                                      \
typedef type* type##Ptr;                                                                                                \
typedef SafeObject<type> Safe##type;                                                                                    \
typedef STDSharedPtr<type> type##SharedPtr;                                                                             \
typedef STDReferenceWrapper<type> type##Ref;                                                                            \
typedef STDVector<type> type##Array;                                                                                    \
typedef STDVector<type##Ptr> type##PtrArray;                                                                            \
typedef STDVector<type##Ref> type##RefArray;                                                                            \
typedef STDVector<type##SharedPtr> type##SharedPtrArray

//======================================================================================================================

#define MAKE_PRIMITIVE_TYPE_ACCESSORS(name, type)                                                                       \
type m_var##name {};                                                                                                    \
type Get##name() { return m_var##name; }                                                                                \
void Set##name(type varValue) { m_var##name = varValue; }

#define MAKE_PRIMITIVE_TYPE_ACCESSORS_GET_ONLY(name, type)                                                              \
type m_var##name {};                                                                                                    \
type Get##name() { return m_var##name; }

#define MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE(name, type, value)                                                  \
type m_var##name = value;                                                                                               \
type Get##name() { return m_var##name; }                                                                                \
void Set##name(type varValue) { m_var##name = varValue; }

#define MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(name, type, value)                                         \
type m_var##name = value;                                                                                               \
type Get##name() { return m_var##name; }

#define MAKE_RAW_TYPE_ACCESSORS(name, type)                                                                             \
type m_var##name {};                                                                                                    \
const type& Get##name() const { return m_var##name; }                                                                   \
type& Get##name() { return m_var##name; }                                                                               \
void Set##name(const type& varValue) { m_var##name = varValue; }

#define MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(name, type)                                                                    \
type m_var##name {};                                                                                                    \
const type& Get##name() const { return m_var##name; }                                                                   \
type& Get##name() { return m_var##name; }

#define MAKE_RAW_TYPE_ACCESSORS_INITIAL_VALUE(name, type, value)                                                        \
type m_var##name = value;                                                                                               \
const type& Get##name() const { return m_var##name; }                                                                   \
type& Get##name() { return m_var##name; }                                                                               \
void Set##name(const type& varValue) { m_var##name = varValue; }

#define MAKE_RAW_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(name, type, value)                                               \
type m_var##name = value;                                                                                               \
const type& Get##name() const { return m_var##name; }                                                                   \
type& Get##name() { return m_var##name; }

//======================================================================================================================

#endif
