// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_SERIALIZATION_H_
#define _GECKO_UTILITY_SERIALIZATION_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/Macros.h"

namespace Gecko
{

// Manager set
class ManagerSet;

// Determine if bytes represent a CBOR file
Bool IsCBOR(const FixedUnsigned8Array& vBytes);

// Determine if bytes represent a MsgPack file
Bool IsMsgPack(const FixedUnsigned8Array& vBytes);

// Remove CBOR header
Bool RemoveCBORHeader(FixedUnsigned8Array& vBytes);

// Remove MsgPack header
Bool RemoveMsgPackHeader(FixedUnsigned8Array& vBytes);

// Read serialized file
Bool ReadSerializedFile(
    SafeObject<ManagerSet>& pManagerSet,
    const String& sFilename,
    const String& sType,
    Json& jsonData,
    const String& sFileRoot);

// Read a file into a json object
Bool ReadJsonFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, Json& jsonData, const String& sFileRoot);

// Read a CBOR file into a json object
Bool ReadCBORFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, Json& jsonData, const String& sFileRoot);

// Read a MsgPack file into a json object
Bool ReadMsgPackFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, Json& jsonData, const String& sFileRoot);

// Write serialized file
Bool WriteSerializedFile(
    SafeObject<ManagerSet>& pManagerSet,
    const String& sFilename,
    const String& sType,
    const Json& jsonData,
    const String& sFileRoot);

// Write a json object to a file
Bool WriteJsonFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, const Json& jsonData, const String& sFileRoot);

// Write a json object to a CBOR file
Bool WriteCBORFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, const Json& jsonData, const String& sFileRoot);

// Write a json object to a MsgPack file
Bool WriteMsgPackFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, const Json& jsonData, const String& sFileRoot);

};

#endif
