// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Constants.h"
#include "Utility/Logging.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

void SetupLogging(Bool bConsole, Bool bFile)
{
    // Set logging thread pool
    InitLoggingThreadPool(8192, 1);

    // Get logging file
    String sLoggingFile = Gecko::JoinPaths(Gecko::GetLogDirectory(), Gecko::GetLogFile());

    // Create logger
    if(bConsole && bFile)
    {
        // Create console sink
        auto pConsoleSink = STDMakeSharedPtr<ColorStdOutSinkType>();
        pConsoleSink->set_level(LoggingLevelWarning);

        // Create file sink
        auto pFileSink = STDMakeSharedPtr<FileSinkType>(sLoggingFile, true);
        pFileSink->set_level(LoggingLevelTrace);

        // Create multi sink logger
        STDVector<SinkPtrType> vSinks {pConsoleSink, pFileSink};
        auto pMultiSinkLogger = STDMakeSharedPtr<AsyncLoggerType>(
            LOGGER_NAME,
            vSinks.begin(),
            vSinks.end(),
            LoggingThreadPool(),
            LoggingAsyncOverflowPolicyBlock
        );
        SetDefaultLogger(pMultiSinkLogger);
    }
    else if(bConsole)
    {
        // Create console logger
        auto pConsoleLogger = CreateStdOutColorLogger(LOGGER_NAME);
        pConsoleLogger->set_level(LoggingLevelWarning);
        SetDefaultLogger(pConsoleLogger);
    }
    else if(bFile)
    {
        // Create file logger
        auto pFileLogger = CreateBasicLogger(LOGGER_NAME, sLoggingFile);
        pFileLogger->set_level(LoggingLevelTrace);
        SetDefaultLogger(pFileLogger);
    }
}

};
