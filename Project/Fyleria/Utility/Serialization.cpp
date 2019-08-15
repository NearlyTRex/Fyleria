// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Constants.h"
#include "Utility/Serialization.h"
#include "Utility/Logging.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

const FixedUnsigned8Array vBinaryMarkersCBR = {'C', 'B', 'R'};
const FixedUnsigned8Array vBinaryMarkersMSG = {'M', 'S', 'G'};

Bool IsCBOR(const FixedUnsigned8Array& vBytes)
{
    if(vBytes.size() < vBinaryMarkersCBR.size())
    {
        return false;
    }

    for(UInt i = 0; i < vBinaryMarkersCBR[i]; i++)
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
    if(vBytes.size() < vBinaryMarkersMSG.size())
    {
        return false;
    }

    for(UInt i = 0; i < vBinaryMarkersMSG[i]; i++)
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
    if(vBytes.size() < vBinaryMarkersCBR.size())
    {
        return false;
    }
    vBytes.erase(vBytes.begin() + vBinaryMarkersCBR.size());
    return true;
}

Bool RemoveMsgPackHeader(FixedUnsigned8Array& vBytes)
{
    if(vBytes.size() < vBinaryMarkersMSG.size())
    {
        return false;
    }
    vBytes.erase(vBytes.begin() + vBinaryMarkersMSG.size());
    return true;
}

Bool ReadSerializedFile(const String& sFilename, const String& sType, Json& jsonData, const String& sFileRoot)
{
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch (eFileType)
    {
        case FileType::TextJson:
            return ReadJsonFile(sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryCBOR:
            return ReadCBORFile(sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryMsgPack:
            return ReadMsgPackFile(sFilename, jsonData, sFileRoot);
            break;
        default:
            break;
    }
    return false;
}

Bool ReadJsonFile(const String& sFilename, Json& jsonData, const String& sFileRoot)
{
    // Read file contents
    String sJsonString;
    if(!ReadFileToString(sFilename, sJsonString, sFileRoot))
    {
        return false;
    }

    // Parse as json
    jsonData = JsonParse(sJsonString);
    return true;
}

Bool ReadCBORFile(const String& sFilename, Json& jsonData, const String& sFileRoot)
{
    FixedUnsigned8Array vBytes;
    if(!ReadFileToByteArray(sFilename, vBytes, sFileRoot))
    {
        return false;
    }

    if(!IsCBOR(vBytes))
    {
        return false;
    }

    if(!RemoveCBORHeader(vBytes))
    {
        return false;
    }

    jsonData = JsonFromCBOR(vBytes);
    return true;
}

Bool ReadMsgPackFile(const String& sFilename, Json& jsonData, const String& sFileRoot)
{
    FixedUnsigned8Array vBytes;
    if(!ReadFileToByteArray(sFilename, vBytes, sFileRoot))
    {
        return false;
    }

    if(!IsMsgPack(vBytes))
    {
        return false;
    }

    if(!RemoveMsgPackHeader(vBytes))
    {
        return false;
    }

    jsonData = JsonFromMsgPack(vBytes);
    return true;
}

Bool WriteSerializedFile(const String& sFilename, const String& sType, const Json& jsonData, const String& sFileRoot)
{
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch (eFileType)
    {
        case FileType::TextJson:
            return WriteJsonFile(sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryCBOR:
            return WriteCBORFile(sFilename, jsonData, sFileRoot);
            break;
        case FileType::BinaryMsgPack:
            return WriteMsgPackFile(sFilename, jsonData, sFileRoot);
            break;
        default:
            break;
    }
    return false;
}

Bool WriteJsonFile(const String& sFilename, const Json& jsonData, const String& sFileRoot)
{
    return WriteStringToFile(sFilename, jsonData.dump(4), sFileRoot);
}

Bool WriteCBORFile(const String& sFilename, const Json& jsonData, const String& sFileRoot)
{
    FixedUnsigned8Array vFileBytes = vBinaryMarkersCBR;
    FixedUnsigned8Array vJsonBytes = JsonToCBOR(jsonData);
    vFileBytes.insert(vFileBytes.end(), vJsonBytes.begin(), vJsonBytes.end());
    return WriteByteArrayToFile(sFilename, vFileBytes, sFileRoot);
}

Bool WriteMsgPackFile(const String& sFilename, const Json& jsonData, const String& sFileRoot)
{
    FixedUnsigned8Array vFileBytes = vBinaryMarkersMSG;
    FixedUnsigned8Array vJsonBytes = JsonToMsgPack(jsonData);
    vFileBytes.insert(vFileBytes.end(), vJsonBytes.begin(), vJsonBytes.end());
    return WriteByteArrayToFile(sFilename, vFileBytes, sFileRoot);
}

};
