// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_SERIALIZATION_H_
#define _GECKO_UTILITY_SERIALIZATION_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/Macros.h"

namespace Gecko
{

// File type
MAKE_ENUM(FileType, Int,
    None,
    TextJson,
    BinaryCBOR,
    BinaryMsgPack
);
MAKE_ENUM_CONVERTERS_PROTO(FileType);

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
    const String& sPath,
    const String& sType,
    Json& jsonData,
    const String& sFileRoot = "");

// Read a file into a json object
Bool ReadJsonFile(const String& sPath, Json& jsonData, const String& sFileRoot = "");

// Read a CBOR file into a json object
Bool ReadCBORFile(const String& sPath, Json& jsonData, const String& sFileRoot = "");

// Read a MsgPack file into a json object
Bool ReadMsgPackFile(const String& sPath, Json& jsonData, const String& sFileRoot = "");

// Write serialized file
Bool WriteSerializedFile(
    const String& sPath,
    const String& sType,
    const Json& jsonData,
    const String& sFileRoot = "");

// Write a json object to a file
Bool WriteJsonFile(const String& sPath, const Json& jsonData, const String& sFileRoot = "");

// Write a json object to a CBOR file
Bool WriteCBORFile(const String& sPath, const Json& jsonData, const String& sFileRoot = "");

// Write a json object to a MsgPack file
Bool WriteMsgPackFile(const String& sPath, const Json& jsonData, const String& sFileRoot = "");

};

#endif
