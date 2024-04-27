// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_LOGGING_H_
#define _GECKO_UTILITY_LOGGING_H_

// External includes
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>

// Internal includes
#include "Utility/Types.h"

// SpdLog function defines
#define LoggingThreadPool spdlog::thread_pool
#define InitLoggingThreadPool spdlog::init_thread_pool
#define CreateBasicLogger spdlog::basic_logger_mt<spdlog::async_factory>
#define CreateRotatingLogger spdlog::rotating_logger_mt<spdlog::async_factory>
#define CreateStdOutColorLogger spdlog::stdout_color_mt<spdlog::async_factory>
#define CreateStdErrColorLogger spdlog::stderr_color_mt<spdlog::async_factory>
#define RegisterLogger spdlog::register_logger
#define DropLogger spdlog::drop
#define DropAllLoggers spdlog::drop_all
#define ShutdownLoggers spdlog::shutdown
#define GetDefaultLogger spdlog::default_logger
#define SetDefaultLogger spdlog::set_default_logger
#define SetLoggingLevel spdlog::set_level
#define SetLoggingPattern spdlog::set_pattern
#define SetLoggingFlush spdlog::flush_every
#define WriteTraceLogEntry spdlog::trace
#define WriteDebugLogEntry spdlog::debug
#define WriteInfoLogEntry spdlog::info
#define WriteErrorLogEntry spdlog::error
#define WriteWarningLogEntry spdlog::warn
#define WriteCriticalLogEntry spdlog::critical
#define SinkInitList spdlog::sinks_init_list

// SpdLog type defines
#define LoggerType spdlog::logger
#define AsyncLoggerType spdlog::async_logger
#define ColorStdOutSinkType spdlog::sinks::stdout_color_sink_mt
#define ColorStdErrSinkType spdlog::sinks::stderr_color_sink_mt
#define FileSinkType spdlog::sinks::basic_file_sink_mt
#define SinkPtrType spdlog::sink_ptr

// SpdLog levels
#define LoggingLevelType spdlog::level::level_enum
#define LoggingLevelTrace spdlog::level::trace
#define LoggingLevelDebug spdlog::level::debug
#define LoggingLevelInfo spdlog::level::info
#define LoggingLevelWarning spdlog::level::warn
#define LoggingLevelError spdlog::level::err
#define LoggingLevelCritical spdlog::level::critical
#define LoggingLevelOff stdlog::level::off

// SpdLog policies
#define LoggingAsyncOverflowPolicyBlock spdlog::async_overflow_policy::block
#define LoggingAsyncOverflowPolicyDiscardOldest spdlog::async_overflow_policy::overrun_oldest

// Write a logging statement
#define LOG_STATEMENT(string) WriteInfoLogEntry(string)
#define LOG_FORMAT_STATEMENT(string, ...) WriteInfoLogEntry(string, __VA_ARGS__)
#define LOG_WFORMAT_STATEMENT(string, ...) WriteInfoLogEntry(string, __VA_ARGS__)
#define LOG_FORMAT_STATEMENT_NARGS(string) WriteInfoLogEntry(string)
#define LOG_WFORMAT_STATEMENT_NARGS(string) WriteInfoLogEntry(string)

// Write a warning statement
#define WARNING_STATEMENT(string) WriteWarningLogEntry(string)
#define WARNING_FORMAT_STATEMENT(string, ...) WriteWarningLogEntry(string, __VA_ARGS__)
#define WARNING_WFORMAT_STATEMENT(string, ...) WriteWarningLogEntry(string, __VA_ARGS__)
#define WARNING_FORMAT_STATEMENT_NARGS(string) WriteWarningLogEntry(string)
#define WARNING_WFORMAT_STATEMENT_NARGS(string) WriteWarningLogEntry(string)

// Write an error statement
#define ERROR_STATEMENT(string) WriteErrorLogEntry(string)
#define ERROR_FORMAT_STATEMENT(string, ...) WriteErrorLogEntry(string, __VA_ARGS__)
#define ERROR_WFORMAT_STATEMENT(string, ...) WriteErrorLogEntry(string, __VA_ARGS__)
#define ERROR_FORMAT_STATEMENT_NARGS(string) WriteErrorLogEntry(string)
#define ERROR_WFORMAT_STATEMENT_NARGS(string) WriteErrorLogEntry(string)

namespace Gecko
{

// Setup logging
void SetupLogging(const String& sName, const String& sFile, LoggingLevelType eLevel = LoggingLevelTrace);

// Shutdown logging
void ShutdownLogging();

};

#endif
