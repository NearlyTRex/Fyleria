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

// Server closing mutexes
STDMutex g_close_websocket_server_mutex;
STDMutex g_close_rest_server_mutex;

// Server closing condition variables
STDConditionVariable g_should_close_websocket_server;
STDConditionVariable g_should_close_rest_server;

bool InitializeGame()
{
    // Initialize module
    if (!DLL_InitModule())
    {
        ERROR_STATEMENT("Unable to initialize module");
        return false;
    }

    // Initialize stat names
    LOG_STATEMENT("Initializing stat names...");
    InitializeAllStatNames();
    LOG_STATEMENT("Finished initializing stat names");

    // Load trees into memory
    LOG_STATEMENT("Loading trees into memory...");
    LoadSkillTreesIntoMemory();
    LoadItemTreesIntoMemory();
    LOG_STATEMENT("Finished loading trees into memory");
    return true;
}

bool FinalizeGame()
{
    // Unload trees from memory
    LOG_STATEMENT("Unloading trees from memory...");
    UnloadSkillTreesFromMemory();
    UnloadItemTreesFromMemory();
    LOG_STATEMENT("Finished unloading trees from memory");

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
    if(!DoesPathExist(sScriptFilename) || !IsFile(sScriptFilename))
    {
        return;
    }

    // Initialize game
    if(!InitializeGame())
    {
        return;
    }

    // Run script
    DLL_RunModuleFile(sScriptFilename);

    // Finalize game
    FinalizeGame();
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

    // Wait to finish
    STDUniqueLock<STDMutex> lock(g_close_rest_server_mutex);
    g_should_close_rest_server.wait(lock);

    // Finalize game
    FinalizeGame();
}

void StopGameWebsocketServer()
{
    // Notify server to close
    g_should_close_websocket_server.notify_one();
}

void StopGameRestServer()
{
    // Notify server to close
    g_should_close_rest_server.notify_one();
}

};
