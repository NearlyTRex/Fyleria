// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Utility/Logging.h"

namespace Gecko
{

void SetupLogging(const String& sName, const String& sFile, LoggingLevelType eLevel)
{
    // Set logging thread pool
    InitLoggingThreadPool(8192, 1);

    // Create logger
#if defined(PLATFORM_OS_WINDOWS)
    auto pFileLogger = CreateBasicLogger(
        sName,
        sFile
    );
    pFileLogger->set_level(eLevel);
    SetDefaultLogger(pFileLogger);
#else
    auto pConsoleSink = STDMakeSharedPtr<ColorStdOutSinkType>();
    auto pFileSink = STDMakeSharedPtr<FileSinkType>(sFile, true);
    pConsoleSink->set_level(eLevel);
    pFileSink->set_level(eLevel);
    STDVector<SinkPtrType> vSinks {pConsoleSink, pFileSink};
    auto pMultiSinkLogger = STDMakeSharedPtr<AsyncLoggerType>(
        sName,
        vSinks.begin(),
        vSinks.end(),
        LoggingThreadPool(),
        LoggingAsyncOverflowPolicyBlock
    );
    SetDefaultLogger(pMultiSinkLogger);
#endif
}

void ShutdownLogging()
{
    // Shutdown logger
    ShutdownLoggers();
}

};
