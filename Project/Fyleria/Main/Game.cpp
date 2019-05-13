// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

// Internal includes
#include "Main/Game.h"
#include "Interface/Interface.h"
#include "Server/WebSockets.h"
#include "Server/Rest.h"
#include "Stats/StatNames.h"
#include "Utility/Logging.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

bool InitializeGame()
{
    // Initialize stat names
    InitializeAllStatNames();

    // Initialize module
    if (!DLL_InitModule())
    {
        ERROR_STATEMENT("Unable to initialize module");
        return false;
    }
    return true;
}

bool FinalizeGame()
{
    // Finalize module
    if (!DLL_FinalizeModule())
    {
        ERROR_STATEMENT("Unable to finalize module");
        return false;
    }
    return true;
}

void RunGameScript(const char* sScriptFilename)
{
    // Make sure file exists
    if(!DoesPathExist(sScriptFilename))
    {
        return;
    }

    // Run script
    DLL_RunModuleFile(sScriptFilename);
}

void StartGameWebsocketServer(const char* sHostname, int iPort)
{
    // Start server
    WebsocketServer::GetInstance()->SetHostname(sHostname);
    WebsocketServer::GetInstance()->SetPort(iPort);
    WebsocketServer::GetInstance()->Reset();
    WebsocketServer::GetInstance()->Start();
}

void StartGameRestServer(const char* sHostname, const char* sWebRoot, int iPort, int iThreadCount)
{
    // Start server
    RestServer::GetInstance()->SetHostname(sHostname);
    RestServer::GetInstance()->SetWebRoot(sWebRoot);
    RestServer::GetInstance()->SetPort(iPort);
    RestServer::GetInstance()->SetThreadCount(iThreadCount);
    RestServer::GetInstance()->Reset();
    RestServer::GetInstance()->Start();
}

};
