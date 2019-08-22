// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Constants.h"
#include "Utility/Logging.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

void SetupLogging(const String& sFile)
{
    // Set logging thread pool
    InitLoggingThreadPool(8192, 1);

    // Create logger
#if defined(PLATFORM_OS_WINDOWS)
    auto pFileLogger = CreateBasicLogger(LOGGER_NAME, sFile);
    pFileLogger->set_level(LoggingLevelTrace);
    SetDefaultLogger(pFileLogger);
#else
    auto pConsoleSink = STDMakeSharedPtr<ColorStdOutSinkType>();
    auto pFileSink = STDMakeSharedPtr<FileSinkType>(sFile, true);
    pConsoleSink->set_level(LoggingLevelWarning);
    pFileSink->set_level(LoggingLevelTrace);
    STDVector<SinkPtrType> vSinks {pConsoleSink, pFileSink};
    auto pMultiSinkLogger = STDMakeSharedPtr<AsyncLoggerType>(
        LOGGER_NAME,
        vSinks.begin(),
        vSinks.end(),
        LoggingThreadPool(),
        LoggingAsyncOverflowPolicyBlock
    );
    SetDefaultLogger(pMultiSinkLogger);
#endif
}

};
