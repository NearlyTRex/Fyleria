// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Time.h"

namespace Gecko
{

String GetFormattedTimestamp(const TimeType& time, const String& sFormat)
{
    String sTimestamp;
#if defined(PLATFORM_OS_WINDOWS)
    TimeInfo info;
    localtime_s(&info, &time);
    sTimestamp = BoostLexicalCast<String>(STDPutTime(&info, sFormat.c_str()));
#else
    sTimestamp = BoostLexicalCast<String>(STDPutTime(STDLocalTime(&time), sFormat.c_str()));
#endif
    return sTimestamp;
}

};
