// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_SERIALIZABLE_H_
#define _GECKO_UTILITY_SERIALIZABLE_H_

#include "Utility/Serialization.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

class SerializableToJson
{
public:

    // Constructors
    SerializableToJson();
    SerializableToJson(const Json& jsonData);

    // Destructor
    virtual ~SerializableToJson();

    // Serialization from/to json
    virtual void FromJson(const Json& jsonData);
    virtual void FromJsonString(const String& sJsonString);
    virtual const Json& ToJson() const;
    virtual String ToJsonString(Int iIndent = -1) const;

    // Serialization from/to CBOR/MsgPack
    virtual void FromCBOR(const FixedUnsigned8Array& vCBOR);
    virtual void FromMsgPack(const FixedUnsigned8Array& vMsgPack);
    virtual FixedUnsigned8Array ToCBOR() const;
    virtual FixedUnsigned8Array ToMsgPack() const;

    // Serialization from/to file
    virtual Bool FromFile(const String& sFilename);
    virtual Bool FromCBORFile(const String& sFilename);
    virtual Bool FromMsgPackFile(const String& sFilename);
    virtual Bool ToFile(const String& sFilename) const;
    virtual Bool ToCBORFile(const String& sFilename) const;
    virtual Bool ToMsgPackFile(const String& sFilename) const;

    // Reseting internal data
    virtual void Reset();

    // Other information
    virtual void Clear();
    virtual Bool IsEmpty() const;
    virtual UInt GetSize() const;

protected:

    // JSON data
    Json m_Data;
};

};

#endif
