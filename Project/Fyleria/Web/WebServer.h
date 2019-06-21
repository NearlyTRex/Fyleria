// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_SERVER_H_
#define _GECKO_WEB_SERVER_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Enum.h"
#include "Utility/Http.h"
#include "Utility/Singleton.h"

namespace Gecko
{

// Web server
class WebServer : public Singleton<WebServer>
{
public:

    // Constructor
    WebServer();

    // Reset server
    void Reset();

    // Start server
    void Start();

    // Stop server
    void Stop();

    // Host name
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Hostname, String);

    // Web root
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(WebRoot, String);

    // Port number
    MAKE_RAW_BASIC_TYPE_ACCESSORS(Port, Int);

    // Thread count
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ThreadCount, Int);

    // Endpoint
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Endpoint, STDSharedPtr<HttpEndpoint>);
};

};

#endif
