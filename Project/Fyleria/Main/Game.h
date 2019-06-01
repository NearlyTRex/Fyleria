// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

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
void StartGameWebsocketServer();

// Start rest server
void StartGameRestServer();

// Stop web socket server
void StopGameWebsocketServer();

// Stop rest server
void StopGameRestServer();

};

#endif
