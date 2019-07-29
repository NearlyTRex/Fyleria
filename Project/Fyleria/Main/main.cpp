// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// System includes
#include <string>
#include <iostream>
#include <cstdlib>

// Internal includes
#include "Main/Application.h"
#include "Config/ConfigManager.h"
#include "Utility/Constants.h"
#include "Utility/Types.h"
#include "Utility/Standard.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"

// Main
int main(int iArgCount, char** vArgList)
{
    // Register signal handler
#ifdef DEBUG
    Gecko::RegisterSignalHandler();
#endif

    // Run application
    Gecko::Application app;
    app.Run();
    return EXIT_SUCCESS;
}
