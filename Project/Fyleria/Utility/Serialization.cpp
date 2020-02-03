// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Constants.h"
#include "Utility/Serialization.h"
#include "Utility/Logging.h"
#include "Utility/ManagerSet.h"

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
    SafeObject<ManagerSet>& pManagerSet,
    const String& sFilename,
    const String& sType,
    Json& jsonData,
    const String& sFileRoot)
{
    // Check file type
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch (eFileType)
    {
        case FileType::TextJson:
            return ReadJsonFile(pManagerSet, sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryCBOR:
            return ReadCBORFile(pManagerSet, sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryMsgPack:
            return ReadMsgPackFile(pManagerSet, sFilename, jsonData, sFileRoot);
            break;
        default:
            break;
    }
    return false;
}

Bool ReadJsonFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, Json& jsonData, const String& sFileRoot)
{
    // Read file contents
    String sJsonString;
    if(!pManagerSet->GetFileManager()->ReadFileToString(sFilename, sJsonString, sFileRoot))
    {
        return false;
    }

    // Parse as json
    jsonData = JsonParse(sJsonString);
    return true;
}

Bool ReadCBORFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, Json& jsonData, const String& sFileRoot)
{
    // Read file contents
    FixedUnsigned8Array vBytes;
    if(!pManagerSet->GetFileManager()->ReadFileToByteArray(sFilename, vBytes, sFileRoot))
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

Bool ReadMsgPackFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, Json& jsonData, const String& sFileRoot)
{
    // Read file contents
    FixedUnsigned8Array vBytes;
    if(!pManagerSet->GetFileManager()->ReadFileToByteArray(sFilename, vBytes, sFileRoot))
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
    SafeObject<ManagerSet>& pManagerSet,
    const String& sFilename,
    const String& sType,
    const Json& jsonData,
    const String& sFileRoot)
{
    // Check file type
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch (eFileType)
    {
        case FileType::TextJson:
            return WriteJsonFile(pManagerSet, sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryCBOR:
            return WriteCBORFile(pManagerSet, sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryMsgPack:
            return WriteMsgPackFile(pManagerSet, sFilename, jsonData, sFileRoot);
            break;
        default:
            break;
    }
    return false;
}

Bool WriteJsonFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, const Json& jsonData, const String& sFileRoot)
{
    // Write json file
    return pManagerSet->GetFileManager()->WriteStringToFile(sFilename, jsonData.dump(4), sFileRoot);
}

Bool WriteCBORFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, const Json& jsonData, const String& sFileRoot)
{
    // Write cbor file
    FixedUnsigned8Array vFileBytes = vBinaryMarkersCBR;
    FixedUnsigned8Array vJsonBytes = JsonToCBOR(jsonData);
    vFileBytes.insert(vFileBytes.end(), vJsonBytes.begin(), vJsonBytes.end());
    return pManagerSet->GetFileManager()->WriteByteArrayToFile(sFilename, vFileBytes, sFileRoot);
}

Bool WriteMsgPackFile(SafeObject<ManagerSet>& pManagerSet, const String& sFilename, const Json& jsonData, const String& sFileRoot)
{
    // Write msg pack file
    FixedUnsigned8Array vFileBytes = vBinaryMarkersMSG;
    FixedUnsigned8Array vJsonBytes = JsonToMsgPack(jsonData);
    vFileBytes.insert(vFileBytes.end(), vJsonBytes.begin(), vJsonBytes.end());
    return pManagerSet->GetFileManager()->WriteByteArrayToFile(sFilename, vFileBytes, sFileRoot);
}

};
