// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Utility/Serializable.h"

namespace Gecko
{

SerializableToJson::SerializableToJson()
    : m_Data()
{
}

SerializableToJson::SerializableToJson(const Json& jsonData)
    : m_Data(jsonData)
{
}

void SerializableToJson::FromJson(const Json& jsonData)
{
    m_Data = jsonData;
}

void SerializableToJson::FromJsonString(const String& sJsonString)
{
    m_Data = JsonParse(sJsonString.c_str());
}

const Json& SerializableToJson::ToJson() const
{
    return m_Data;
}

String SerializableToJson::ToJsonString(Int iIndent /*= -1*/) const
{
    return m_Data.dump(iIndent);
}

void SerializableToJson::FromCBOR(const FixedUnsigned8Array& vCBOR)
{
    m_Data = JsonFromCBOR(vCBOR);
}

void SerializableToJson::FromMsgPack(const FixedUnsigned8Array& vMsgPack)
{
    m_Data = JsonFromMsgPack(vMsgPack);
}

FixedUnsigned8Array SerializableToJson::ToCBOR() const
{
    return JsonToCBOR(m_Data);
}

FixedUnsigned8Array SerializableToJson::ToMsgPack() const
{
    return JsonToMsgPack(m_Data);
}

Bool SerializableToJson::FromFile(const IndexedString& sFilename)
{
    return ReadJsonFile(sFilename, m_Data);
}

Bool SerializableToJson::FromCBORFile(const IndexedString& sFilename)
{
    return ReadCBORFile(sFilename, m_Data);
}

Bool SerializableToJson::FromMsgPackFile(const IndexedString& sFilename)
{
    return ReadMsgPackFile(sFilename, m_Data);
}

Bool SerializableToJson::ToFile(const IndexedString& sFilename) const
{
    return WriteJsonFile(sFilename, m_Data);
}

Bool SerializableToJson::ToCBORFile(const IndexedString& sFilename) const
{
    return WriteCBORFile(sFilename, m_Data);
}

Bool SerializableToJson::ToMsgPackFile(const IndexedString& sFilename) const
{
    return WriteMsgPackFile(sFilename, m_Data);
}

void SerializableToJson::Reset()
{
}

SerializableToJson::operator Json() const
{
    return m_Data;
}

void SerializableToJson::Clear()
{
    m_Data.clear();
}

Bool SerializableToJson::IsEmpty() const
{
    return m_Data.empty();
}

UInt SerializableToJson::GetSize() const
{
    return m_Data.size();
}

};
