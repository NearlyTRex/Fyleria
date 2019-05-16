// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_GAME_H_
#define _GECKO_GAME_H_

namespace Gecko
{

// Initialize game
bool InitializeGame(const char* sConfigFile, const char* sConfigDir, const char* sDataDir, const char* sCacheDir);

// Finalize game
bool FinalizeGame();

// Run game script
void RunGameScript(const char* sScriptFilename);

// Start web socket server
void StartGameWebsocketServer(const char* sHostname, int iPort);

// Start rest server
void StartGameRestServer(const char* sHostname, const char* sWebRoot, int iPort, int iThreadCount);

// Stop web socket server
void StopGameWebsocketServer();

// Stop rest server
void StopGameRestServer();

};

#endif
