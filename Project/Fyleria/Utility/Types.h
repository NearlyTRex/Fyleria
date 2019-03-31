// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_TYPES_H_
#define _GECKO_UTILITY_TYPES_H_

// Posix-style OS
#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#include <unistd.h>
#endif

// Internal includes
#include <Utility/Standard.h>
#include <Utility/Boost.h>

namespace Gecko
{

// Types
typedef std::random_device RandomDevice;
typedef std::mt19937 RandomGenerator;
typedef size_t SizeType;
typedef char Byte;
typedef wchar_t WByte;
typedef bool Bool;
typedef short Short;
typedef int Int;
typedef long Long;
typedef unsigned char UByte;
typedef unsigned short UShort;
typedef unsigned int UInt;
typedef unsigned long ULong;
typedef unsigned long long ULongLong;
typedef float Float;
typedef double Double;
typedef std::uint8_t FixedUnsigned8;
typedef std::uint16_t FixedUnsigned16;
typedef std::uint32_t FixedUnsigned32;
typedef std::uint64_t FixedUnsigned64;
typedef std::int8_t FixedSigned8;
typedef std::int16_t FixedSigned16;
typedef std::int32_t FixedSigned32;
typedef std::int64_t FixedSigned64;
typedef std::string String;
typedef std::wstring WString;
typedef std::ifstream InputFile;
typedef std::ofstream OutputFile;
typedef std::istringstream InputStringStream;
typedef std::ostringstream OutputStringStream;
typedef GeckoVector<Byte> ByteArray;
typedef GeckoVector<WByte> WByteArray;
typedef GeckoVector<Bool> BoolArray;
typedef GeckoVector<Short> ShortArray;
typedef GeckoVector<Int> IntArray;
typedef GeckoVector<UByte> UByteArray;
typedef GeckoVector<UShort> UShortArray;
typedef GeckoVector<UInt> UIntArray;
typedef GeckoVector<Float> FloatArray;
typedef GeckoVector<Double> DoubleArray;
typedef GeckoVector<FixedUnsigned8> FixedUnsigned8Array;
typedef GeckoVector<FixedUnsigned16> FixedUnsigned16Array;
typedef GeckoVector<FixedUnsigned32> FixedUnsigned32Array;
typedef GeckoVector<FixedUnsigned64> FixedUnsigned64Array;
typedef GeckoVector<FixedSigned8> FixedSigned8Array;
typedef GeckoVector<FixedSigned16> FixedSigned16Array;
typedef GeckoVector<FixedSigned32> FixedSigned32Array;
typedef GeckoVector<FixedSigned64> FixedSigned64Array;
typedef GeckoVector<String> StringArray;
typedef GeckoVector<WString> WStringArray;
typedef GeckoVector<InputFile> InputFileArray;
typedef GeckoVector<OutputFile> OutputFileArray;

};

#endif
