// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Config/ConfigManager.h"
#include "Utility/Constants.h"
#include "Utility/Types.h"
#include "Utility/Standard.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"
#include "Utility/Filesystem.h"

// Main
int main(int iArgCount, char** vArgList)
{
    // Register signal handler
#ifdef DEBUG
    Gecko::RegisterSignalHandler();
#endif

    // Check data folder
    if(!Gecko::DoesPathExist(Gecko::GetDataDirectory()))
    {
        STDCerr << "Missing data folder, stopping." << STDEndl;
        return EXIT_FAILURE;
    }

    // Run application
    Gecko::Application app;
    app.Run();
    return EXIT_SUCCESS;
}
