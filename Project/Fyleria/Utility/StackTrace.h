// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_STACKTRACE_H_
#define _GECKO_UTILITY_STACKTRACE_H_

// Internal includes
#include "Utility/Types.h"

// System includes
#include <signal.h>

// External includes
#include <backward.hpp>

namespace Gecko
{

// Signal handler
typedef backward::SignalHandling SignalHandler;

// Stack trace
typedef backward::StackTrace StackTraceGenerator;
typedef backward::Printer StackTracePrinter;
typedef backward::TraceResolver StackTraceResolver;
typedef backward::ResolvedTrace StackResolvedTrace;

// Get stack trace signals
IntArray GetStackTraceSignals();

};

#endif
