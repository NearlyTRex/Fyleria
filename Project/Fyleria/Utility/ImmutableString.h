// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_IMMUTABLE_STRING_H_
#define _GECKO_UTILITY_IMMUTABLE_STRING_H_

// External includes
#include <immutable_string.h>

// Internal includes
#include <Utility/Standard.h>

namespace Gecko
{

// Types
typedef cdmh::immutable_string ImmutableString;
typedef cdmh::immutable_wstring ImmutableWString;
typedef ImmutableString::value_type ImmutableStringValueType;
typedef ImmutableWString::value_type ImmutableWStringValueType;
typedef STDVector<ImmutableString> ImmutableStringArray;
typedef STDVector<ImmutableWString> ImmutableWStringArray;

};

#endif
