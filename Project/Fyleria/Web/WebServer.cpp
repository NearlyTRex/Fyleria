// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebServer.h"
#include "Web/WebServerHttpHandler.h"
#include "Interface/Interface.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"
#include "Utility/Macros.h"
#include "Utility/Types.h"
#include "Utility/Json.h"
#include "Utility/Filesystem.h"
#include "Utility/Logging.h"
#include "Utility/Templates.h"

namespace Gecko
{

WebServer::WebServer()
    : Singleton<WebServer>()
{
}

void WebServer::Reset()
{
    LOG_STATEMENT("Resetting server");
    ASSERT_ERROR(!GetHostname().empty(), "Host cannot be empty");
    ASSERT_ERROR(GetPort() > 0, "Port must be a positive integer");
    ASSERT_ERROR(GetThreadCount() > 0, "Thread count must be a positive integer");
    SetEndpoint(STDMakeSharedPtr<HttpEndpoint>(HttpAddress(GetHostname(), GetPort())));
    if (GetEndpoint())
    {
        auto options = HttpEndpoint::options()
            .threads(GetThreadCount())
            .maxPayload(WEB_SERVER_MAX_PAYLOAD_SIZE)
            .flags(TcpOptionReuseAddr);
        GetEndpoint()->init(options);
    }
}

void WebServer::Start()
{
    // Check that endpoint exists
    if (!GetEndpoint())
    {
        return;
    }

    // Setting up server
    LOG_STATEMENT("Setting up server");

    // Set handlers
    auto pHandler = HttpMakeHandler<WebServerHttpHandler>(GetWebRoot());
    GetEndpoint()->setHandler(pHandler);

    // Start listening
    LOG_FORMAT_STATEMENT("Now serving at http://%s:%d\n", GetHostname().c_str(), GetPort());

    // Start the server accept loop
    GetEndpoint()->serveThreaded();
}

void WebServer::Stop()
{
    // Check that endpoint exists
    if (!GetEndpoint())
    {
        return;
    }

    // Halt server
    GetEndpoint()->shutdown();
    LOG_STATEMENT("Halting server...");
}

};
