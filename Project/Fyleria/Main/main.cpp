// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

// System includes
#include <string>
#include <iostream>
#include <cstdlib>

// Local includes
#include "Main/Application.h"
#include "Main/Game.h"
#include "Utility/StackTrace.h"

// Main
int main(int argc, char** argv)
{
    // Register signal handler
#ifdef DEBUG
    Gecko::SignalHandler signalHandler(Gecko::GetStackTraceSignals());
#endif

    // Initialize
    if(!Gecko::InitializeGame())
    {
        return EXIT_FAILURE;
    }

    // Finalize
    if(!Gecko::FinalizeGame())
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
