// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_TRACING_H_
#define _GECKO_UTILITY_TRACING_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Json.h"
#include "Utility/Logging.h"

// Tracer
namespace Gecko
{
class Tracer
{
public:

    // Constructors
    Tracer(const String& sFunctionName, const String& sFileName, UInt uLineNumber)
    {
        // Store trace info
        SetFunctionName(sFunctionName);
        SetFileName(sFileName);
        SetLineNumber(uLineNumber);

        // Trace entering function
        TRACE_FORMAT_STATEMENT("Entering function {} ({}:{})", GetFunctionName(), GetFileName(), GetLineNumber());
    }

    // Destructor
    ~Tracer()
    {
        // Trace leaving function
        TRACE_FORMAT_STATEMENT("Leaving function {}", GetFunctionName());
    }

    // Deleted
    Tracer() = delete;
    Tracer(Tracer const&) = delete;
    Tracer(Tracer&&) = delete;
    Tracer& operator=(Tracer const&) = delete;
    Tracer& operator=(Tracer&&) = delete;

    // Function name
    MAKE_RAW_TYPE_ACCESSORS(FunctionName, String);

    // File name
    MAKE_RAW_TYPE_ACCESSORS(FileName, String);

    // Line number
    MAKE_RAW_TYPE_ACCESSORS(LineNumber, UInt);
};

};

// Trace macro
#ifdef DEBUG
    #define TRACE_CALL() Gecko::Tracer _tracer_object__ ## __COUNTER__ {__func__, __FILE__, __LINE__}
#else
    #define TRACE_CALL()
#endif

#endif
