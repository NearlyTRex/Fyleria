// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_STANDARD_H_
#define _GECKO_UTILITY_STANDARD_H_

// Standard includes
#include <atomic>
#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <memory>
#include <fstream>
#include <limits>
#include <random>
#include <iterator>
#include <locale>
#include <codecvt>
#include <mutex>
#include <chrono>
#include <type_traits>
#include <csignal>

// Internal include
#include "Utility/Platform.h"

// Standard defines
#define STDCout std::cout
#define STDCerr std::cerr
#define STDEndl std::endl
#define STDStringLiterals std::string_literals
#define STDTime std::time
#define STDLocalTime std::localtime
#define STDPutTime std::put_time
#define STDIsSpace std::isspace
#define STDIsAlphaNumeric std::isalpha
#define STDToUpper std::toupper
#define STDToLower std::tolower
#define STDHash std::hash
#define STDPair std::pair
#define STDVector std::vector
#define STDMap std::map
#define STDUnorderedMap std::unordered_map
#define STDSet std::set
#define STDUnorderedSet std::unordered_set
#define STDList std::list
#define STDFunction std::function
#define STDSharedPtr std::shared_ptr
#define STDUniquePtr std::unique_ptr
#define STDMakeSharedPtr std::make_shared
#define STDMakeUniquePtr std::make_unique
#define STDMakePair std::make_pair
#define STDDistance std::distance
#define STDMoveData std::move
#define STDCopyData std::copy
#define STDFillData std::fill
#define STDFindData std::find
#define STDCountData std::count
#define STDRemoveData std::remove
#define STDClampData std::clamp
#define STDSortData std::sort
#define STDUniqueData std::unique
#define STDShuffleData std::shuffle
#define STDLess std::less
#define STDMin std::min
#define STDMax std::max
#define STDIsSame std::is_same
#define STDStaticAssert std:static_assert
#define STDWStringConvert std::wstring_convert
#define STDUTF8AndUTF16Conversion std::codecvt_utf8_utf16
#define STDSetIntersection std::set_intersection
#define STDInserter std::inserter
#define STDBackInserter std::back_inserter
#define STDToString std::to_string
#define STDStringToInt std::stoi
#define STDStringToLong std::stol
#define STDStringToUnsignedLong std::stoul
#define STDStringToUnsignedLongLong std::stoull
#define STDReferenceWrapper std::reference_wrapper
#define STDNumericLimits std::numeric_limits
#define STDFmod std::fmod
#define STDRound std::round
#define STDGenerateCanonical std::generate_canonical
#define STDUniformIntDistribution std::uniform_int_distribution
#define STDUniformRealDistribution std::uniform_real_distribution
#define STDIOSFlagInputOperations std::ios::in
#define STDIOSFlagOutputOperations std::ios::out
#define STDIOSFlagBinaryMode std::ios::binary
#define STDIOSFlagPosAtBeginning std::ios::beg
#define STDIOSFlagPosAtEnd std::ios::ate
#define STDIOSFlagAppendToEnd std::ios::app
#define STDIOSFlagTruncate std::ios::trunc
#define STDInputFileStreamFlagInput std::ifstream::in
#define STDInputFileStreamFlagOutput std::ifstream::out
#define STDInputFileStreamFlagBinary std::ifstream::binary
#define STDInputFileStreamFlagAte std::ifstream::ate
#define STDInputFileStreamFlagAppend std::ifstream::app
#define STDInputFileStreamFlagTruncate std::ifstream::trunc
#define STDOutputFileStreamFlagInput std::ofstream::in
#define STDOutputFileStreamFlagOutput std::ofstream::out
#define STDOutputFileStreamFlagBinary std::ofstream::binary
#define STDOutputFileStreamFlagAte std::ofstream::ate
#define STDOutputFileStreamFlagAppend std::ofstream::app
#define STDOutputFileStreamFlagTruncate std::ofstream::trunc
#define STDOutputStream std::ostream
#define STDInputStream std::istream
#define STDOutputStringStream std::ostringstream
#define STDInputStringStream std::istringstream
#define STDBindFunc std::bind
#define STDSignal std::signal
#define STDRaise std::raise
#define STDPlaceholder1 std::placeholders::_1
#define STDPlaceholder2 std::placeholders::_2
#define STDPlaceholder3 std::placeholders::_3
#define STDAtomic std::atomic
#define STDMutex std::mutex
#define STDThread std::thread
#define STDConditionVariable std::condition_variable
#define STDRecursiveMutex std::recursive_mutex
#define STDLockGuard std::lock_guard
#define STDUniqueLock std::unique_lock
#define STDException std::exception
#define STDLogicErrorException std::logic_error
#define STDRuntimeErrorException std::runtime_error
#define STDInvalidArgumentException std::invalid_argument
#define STDTimePoint std::chrono::time_point<std::chrono::steady_clock>
#define STDGetCurrentTimePoint std::chrono::steady_clock::now
#define STDDurationCast std::chrono::duration_cast
#define STDDuration std::chrono::duration
#define STDTimeDurationNanoseconds std::chrono::nanoseconds
#define STDTimeDurationMicroseconds std::chrono::microseconds
#define STDTimeDurationMilliseconds std::chrono::milliseconds
#define STDTimeDurationSeconds std::chrono::seconds
#define STDTimeDurationMinutes std::chrono::minutes
#define STDTimeDurationHours std::chrono::hours
#define STDRatioPico std::pico
#define STDRatioNano std::nano
#define STDRatioMicro std::micro
#define STDRatioMilli std::milli
#define STDRatioCenti std::centi
#define STDRatioDeci std::deci
#define STDRatioDeca std::deca
#define STDRatioHecto std::hecto
#define STDRatioKilo std::kilo
#define STDRatioMega std::mega
#define STDRatioGiga std::giga
#define STDRatioTera std::tera
#define STDSetFill std::setfill
#define STDSetWidth std::setw
#define STDHex std::hex
#define STDFixed std::fixed
#define STDSetPrecision std::setprecision
#define STDEnableSharedFromThis std::enable_shared_from_this
#define STDGetSharedThis shared_from_this

#endif
