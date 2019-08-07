// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Config/ConfigManager.h"
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
        // Check data folder
        if(!Gecko::DoesPathExist(Gecko::GetDataDirectory()))
        {
            STDCerr << "Missing data folder, stopping." << STDEndl;
            return EXIT_FAILURE;
        }

        // Create other folders if they don't already exist
        if(!Gecko::DoesPathExist(Gecko::GetSaveDirectory()))
        {
            Gecko::CreateNewDirectory(Gecko::GetSaveDirectory());
        }
        if(!Gecko::DoesPathExist(Gecko::GetLogDirectory()))
        {
            Gecko::CreateNewDirectory(Gecko::GetLogDirectory());
        }

        // Setup logging
        SETUP_FILE_LOGGING(Log, Gecko::GetLogFile());

        // Run application
        Gecko::Application app;
        app.Run();
        return EXIT_SUCCESS;
    }
    catch (STDException& e)
    {
        STDCerr << e.what() << STDEndl;
    }
    return EXIT_FAILURE;
}
