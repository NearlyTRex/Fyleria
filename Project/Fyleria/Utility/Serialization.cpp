// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Utility/Serialization.h"
#include "Utility/Logging.h"
#include "Application/Application.h"

namespace Gecko
{

const FixedUnsigned8Array vBinaryMarkersCBR = {'C', 'B', 'R'};
const FixedUnsigned8Array vBinaryMarkersMSG = {'M', 'S', 'G'};

Bool IsCBOR(const FixedUnsigned8Array& vBytes)
{
    // Check header size
    if(vBytes.size() < vBinaryMarkersCBR.size())
    {
        return false;
    }

    // Check header bytes
    for(UInt i = 0; i < vBinaryMarkersCBR.size(); i++)
    {
        if(vBytes[i] != vBinaryMarkersCBR[i])
        {
            return false;
        }
    }
    return true;
}

Bool IsMsgPack(const FixedUnsigned8Array& vBytes)
{
    // Check header size
    if(vBytes.size() < vBinaryMarkersMSG.size())
    {
        return false;
    }

    // Check header bytes
    for(UInt i = 0; i < vBinaryMarkersMSG.size(); i++)
    {
        if(vBytes[i] != vBinaryMarkersMSG[i])
        {
            return false;
        }
    }
    return true;
}

Bool RemoveCBORHeader(FixedUnsigned8Array& vBytes)
{
    // Check header size
    if(vBytes.size() < vBinaryMarkersCBR.size())
    {
        return false;
    }

    // Erase header bytes
    vBytes.erase(vBytes.begin() + vBinaryMarkersCBR.size());
    return true;
}

Bool RemoveMsgPackHeader(FixedUnsigned8Array& vBytes)
{
    // Check header size
    if(vBytes.size() < vBinaryMarkersMSG.size())
    {
        return false;
    }

    // Erase header bytes
    vBytes.erase(vBytes.begin() + vBinaryMarkersMSG.size());
    return true;
}

Bool ReadSerializedFile(
    const String& sPath,
    const String& sType,
    Json& jsonData,
    const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Check file type
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch (eFileType)
    {
        case FileType::TextJson:
            return ReadJsonFile(sFullPath, jsonData);
            break;
        case FileType::BinaryCBOR:
            return ReadCBORFile(sFullPath, jsonData);
            break;
        case FileType::BinaryMsgPack:
            return ReadMsgPackFile(sFullPath, jsonData);
            break;
        default:
            break;
    }
    return false;
}

Bool ReadJsonFile(const String& sPath, Json& jsonData, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Read file contents
    String sJsonString;
    if(!GetManagers()->GetFileManager()->ReadFileToString(sFullPath, sJsonString))
    {
        return false;
    }

    // Parse as json
    jsonData = JsonParse(sJsonString);
    return true;
}

Bool ReadCBORFile(const String& sPath, Json& jsonData, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Read file contents
    FixedUnsigned8Array vBytes;
    if(!GetManagers()->GetFileManager()->ReadFileToByteArray(sFullPath, vBytes))
    {
        return false;
    }

    // Remove header
    if(!RemoveCBORHeader(vBytes))
    {
        return false;
    }

    // Parse as json
    jsonData = JsonFromCBOR(vBytes);
    return true;
}

Bool ReadMsgPackFile(const String& sPath, Json& jsonData, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Read file contents
    FixedUnsigned8Array vBytes;
    if(!GetManagers()->GetFileManager()->ReadFileToByteArray(sFullPath, vBytes))
    {
        return false;
    }

    // Remove header
    if(!RemoveMsgPackHeader(vBytes))
    {
        return false;
    }

    // Parse as json
    jsonData = JsonFromMsgPack(vBytes);
    return true;
}

Bool WriteSerializedFile(
    const String& sPath,
    const String& sType,
    const Json& jsonData,
    const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Check file type
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch (eFileType)
    {
        case FileType::TextJson:
            return WriteJsonFile(sFullPath, jsonData);
            break;
        case FileType::BinaryCBOR:
            return WriteCBORFile(sFullPath, jsonData);
            break;
        case FileType::BinaryMsgPack:
            return WriteMsgPackFile(sFullPath, jsonData);
            break;
        default:
            break;
    }
    return false;
}

Bool WriteJsonFile(const String& sPath, const Json& jsonData, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Write json file
    return GetManagers()->GetFileManager()->WriteStringToFile(sFullPath, jsonData.dump(4));
}

Bool WriteCBORFile(const String& sPath, const Json& jsonData, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Write cbor file
    FixedUnsigned8Array vFileBytes = vBinaryMarkersCBR;
    FixedUnsigned8Array vJsonBytes = JsonToCBOR(jsonData);
    vFileBytes.insert(vFileBytes.end(), vJsonBytes.begin(), vJsonBytes.end());
    return GetManagers()->GetFileManager()->WriteByteArrayToFile(sFullPath, vFileBytes);
}

Bool WriteMsgPackFile(const String& sPath, const Json& jsonData, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(GetManagers()->GetFileManager()->IsRelativePath(sPath))
    {
        sFullPath = GetManagers()->GetFileManager()->JoinPaths(sFileRoot, sPath);
    }

    // Write msg pack file
    FixedUnsigned8Array vFileBytes = vBinaryMarkersMSG;
    FixedUnsigned8Array vJsonBytes = JsonToMsgPack(jsonData);
    vFileBytes.insert(vFileBytes.end(), vJsonBytes.begin(), vJsonBytes.end());
    return GetManagers()->GetFileManager()->WriteByteArrayToFile(sFullPath, vFileBytes);
}

};
