// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_SERIALIZATION_H_
#define _GECKO_UTILITY_SERIALIZATION_H_

#include "Utility/IndexedString.h"
#include "Utility/Types.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/Macros.h"

namespace Gecko
{

// Read a binary file into a string
Bool ReadBinaryFile(const IndexedString& sFilename, FixedUnsigned8Array& vBytes);

// Write a string to a binary file
Bool WriteBinaryFile(const IndexedString& sFilename, const FixedUnsigned8Array& vBytes);

// Determine if bytes represent a CBOR file
Bool IsCBOR(const FixedUnsigned8Array& vBytes);

// Determine if bytes represent a MsgPack file
Bool IsMsgPack(const FixedUnsigned8Array& vBytes);

// Remove CBOR header
Bool RemoveCBORHeader(FixedUnsigned8Array& vBytes);

// Remove MsgPack header
Bool RemoveMsgPackHeader(FixedUnsigned8Array& vBytes);

// Read serialized file
Bool ReadSerializedFile(const IndexedString& sFilename, const IndexedString& sType, Json& jsonData);

// Read a file into a json object
Bool ReadJsonFile(const IndexedString& sFilename, Json& jsonData);
Bool ReadJsonFile(const IndexedString& sFilename, String& jsonString);

// Read a CBOR file into a json object
Bool ReadCBORFile(const IndexedString& sFilename, Json& jsonData);

// Read a MsgPack file into a json object
Bool ReadMsgPackFile(const IndexedString& sFilename, Json& jsonData);

// Write serialized file
Bool WriteSerializedFile(const IndexedString& sFilename, const IndexedString& sType, const Json& jsonData);

// Write a json object to a file
Bool WriteJsonFile(const IndexedString& sFilename, const Json& jsonData);
Bool WriteJsonFile(const IndexedString& sFilename, const String& jsonString);

// Write a json object to a CBOR file
Bool WriteCBORFile(const IndexedString& sFilename, const Json& jsonData);

// Write a json object to a MsgPack file
Bool WriteMsgPackFile(const IndexedString& sFilename, const Json& jsonData);

};

#endif
