// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Utility/Converters.h"
#include "Utility/Boost.h"
#include "Utility/Errors.h"

namespace Gecko
{

WString ConvertStringToWideString(const String& sString)
{
    STDWStringConvert<STDUTF8AndUTF16Conversion<WByte>> converter;
    return converter.from_bytes(sString);
}

String ConvertWideStringToString(const WString& sWideString)
{
    STDWStringConvert<STDUTF8AndUTF16Conversion<WByte>> converter;
    return converter.to_bytes(sWideString);
}

String ConvertGameTimeToString(ULongLong uTime)
{
    const UInt uSecondMax = 60;
    const UInt uMinuteMax = 60;
    const UInt uHourMax = 12;
    ULongLong uLeftover = 0;
    ULongLong uDays = 0;
    ULong uHours = 0;
    ULong uMinutes = 0;
    ULong uSeconds = 0;

    // Calculate days and get leftover for hours
    uDays = static_cast<ULongLong>(uTime / (uSecondMax * uMinuteMax * uHourMax));
    uLeftover = static_cast<ULongLong>(uTime % (uSecondMax * uMinuteMax * uHourMax));

    // Calculate hours and get leftover for minutes
    uHours = static_cast<ULongLong>(uLeftover / (uSecondMax * uMinuteMax));
    uLeftover = static_cast<ULongLong>(uLeftover % (uSecondMax * uMinuteMax));

    // Calcualte minutes and get leftover for seconds
    uMinutes = static_cast<ULongLong>(uLeftover / uSecondMax);
    uLeftover = static_cast<ULongLong>(uLeftover % uSecondMax);

    // Use leftover for seconds
    uSeconds = uLeftover;

    // Return formatted string
    OutputStringStream ssOutput;
    ssOutput << uDays << ":";
    ssOutput << STDSetFill('0') << STDSetWidth(2) << uHours << ':';
    ssOutput << STDSetFill('0') << STDSetWidth(2) << uMinutes << ':';
    ssOutput << STDSetFill('0') << STDSetWidth(2) << uSeconds;
    return ssOutput.str();
}

String ConvertToUrlEncodedString(const String& sString)
{
    OutputStringStream sStrStream;
    for(SizeType i = 0; i < sString.length(); i++)
    {
        Short iVal = sString.at(i);
        if(
            iVal == 45 || // hyphen
            (iVal >= 48 && iVal <= 57) || // 0-9
            (iVal >= 65 && iVal <= 90) || // A-Z
            iVal == 95 || // underscore
            (iVal >= 97 && iVal <= 122) || // a-z
            iVal == 126 // tilde
        )
        {
            sStrStream << sString.at(i);
        }
        else
        {
            sStrStream << ConvertByteToHexString(sString.at(i));
        }
    }
    return sStrStream.str();
}

String ConvertToUrlDecodedString(const String& sString)
{
    OutputStringStream sStrStream;
    for(SizeType i = 0; i < sString.length(); i++)
    {
        if(sString.at(i) == '%')
        {
            String sTempStr(sString.substr(i + 1, 2));
            sStrStream << ConvertHexStringToByte(sTempStr);
            i += 2;
        }
        else
        {
            sStrStream << sString.at(i);
        }
    }
    return sStrStream.str();
}

String ConvertByteToHexString(UByte uByte)
{
    Short iVal = uByte;
    StringStream sStrStream;
    sStrStream << "%" << STDSetWidth(2) << STDSetFill('0') << STDHex << iVal;
    return sStrStream.str();
}

UByte ConvertHexStringToByte(const String& sString)
{
    Short iVal = 0;
    if(!sString.empty())
    {
        InputStringStream sStrStream(sString);
        sStrStream >> STDHex >> iVal;
        if(sStrStream.fail())
        {
            throw RuntimeError("Stream decode failure");
        }
    }
    return static_cast<UByte>(iVal);
}

StringArray ConvertStringToTokenList(const String& sString, const String& sChars)
{
    StringArray vTokens;
    BoostCharSeparator<Byte> charSeparator(sChars.c_str());
    BoostTokenizer<BoostCharSeparator<Byte>> tokens(sString, charSeparator);
    for (const auto& t : tokens)
    {
        vTokens.push_back(t);
    }
    return vTokens;
}

StringMap ConvertQueryStringToStringMap(const String& sQuery)
{
    StringMap tMap;
    StringArray vQuerySegments = ConvertStringToTokenList(ConvertToUrlDecodedString(sQuery), "&");
    for(auto& sSegment : vQuerySegments)
    {
        StringArray vParts = ConvertStringToTokenList(sSegment, "=");
        if(vParts.size() == 2)
        {
            tMap.insert({vParts[0], vParts[1]});
        }
    }
    return tMap;
}

};
