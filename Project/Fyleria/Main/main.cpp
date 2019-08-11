// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Utility/Logging.h"
#include "Utility/Types.h"
#include "Utility/Standard.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"
#include "Utility/Filesystem.h"

// Main
#if defined(PLATFORM_OS_WINDOWS)
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
    // Register signal handler
#ifdef DEBUG
    Gecko::RegisterSignalHandler();
#endif

    try
    {
        // Create save folder
        if(!Gecko::DoesPathExist(Gecko::GetSaveDirectory()))
        {
            Gecko::CreateNewDirectory(Gecko::GetSaveDirectory());
        }

        // Create log folder
        if(!Gecko::DoesPathExist(Gecko::GetLogDirectory()))
        {
            Gecko::CreateNewDirectory(Gecko::GetLogDirectory());
        }

        // Setup logging
#if defined(PLATFORM_OS_WINDOWS)
        Gecko::SetupLogging(false, true);
#else
        Gecko::SetupLogging(true, true);
#endif

        // Check data folder
        if(!Gecko::DoesPathExist(Gecko::GetDataDirectory()))
        {
            ERROR_STATEMENT("Missing data folder, stopping.");
            return EXIT_FAILURE;
        }

        // Run application
        Gecko::Application app;
        return app.Run();
    }
    catch (STDException& e)
    {
        ERROR_FORMAT_STATEMENT("Caught exception: {}", e.what());
        return EXIT_FAILURE;
    }
}
