// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

// Internal includes
#include "Main/Game.h"
#include "Config/ConfigManager.h"
#include "Items/ItemTree.h"
#include "Skills/SkillTree.h"
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
    // Initialize module
    if (!DLL_InitModule())
    {
        ERROR_STATEMENT("Unable to initialize module");
        return false;
    }

    // Initialize stat names
    InitializeAllStatNames();

    // Load trees
    LoadItemTreesIntoMemory();
    LoadSkillTreesIntoMemory();
    return true;
}

bool FinalizeGame()
{
    // Unload trees
    UnloadItemTreesFromMemory();
    UnloadSkillTreesFromMemory();

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

void StartGameWebsocketServer()
{
    // Initialize game
    if(!InitializeGame())
    {
        return;
    }

    // Start server
    WebsocketServer::GetInstance()->SetHostname(ConfigManager::GetInstance()->GetWebHostname());
    WebsocketServer::GetInstance()->SetPort(ConfigManager::GetInstance()->GetWebsocketPort());
    WebsocketServer::GetInstance()->Reset();
    WebsocketServer::GetInstance()->Start();

    // Finalize game
    FinalizeGame();
}

void StartGameRestServer()
{
    // Initialize game
    if(!InitializeGame())
    {
        return;
    }

    // Start server
    RestServer::GetInstance()->SetHostname(ConfigManager::GetInstance()->GetWebHostname());
    RestServer::GetInstance()->SetWebRoot(ConfigManager::GetInstance()->GetWebFolder());
    RestServer::GetInstance()->SetPort(ConfigManager::GetInstance()->GetRestPort());
    RestServer::GetInstance()->SetThreadCount(ConfigManager::GetInstance()->GetServerThreads());
    RestServer::GetInstance()->Reset();
    RestServer::GetInstance()->Start();

    // Finalize game
    FinalizeGame();
}

void StopGameWebsocketServer()
{
    // Stop server
    WebsocketServer::GetInstance()->Stop();
}

void StopGameRestServer()
{
    // Stop server
    RestServer::GetInstance()->Stop();
}

};
