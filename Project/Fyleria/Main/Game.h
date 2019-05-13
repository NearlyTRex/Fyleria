// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_GAME_H_
#define _GECKO_GAME_H_

namespace Gecko
{

// Initialize game
bool InitializeGame();

// Finalize game
bool FinalizeGame();

// Run game script
void RunGameScript(const char* sScriptFilename);

// Start web socket server
void StartGameWebsocketServer(const char* sHostname, int iPort);

// Start rest server
void StartGameRestServer(const char* sHostname, const char* sWebRoot, int iPort, int iThreadCount);

};

#endif
