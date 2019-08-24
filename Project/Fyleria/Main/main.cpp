// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Utility/Logging.h"
#include "Utility/Types.h"
#include "Utility/Standard.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"

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
        // Create manager set
        auto pManagerSet = STDMakeSharedPtr<Gecko::ManagerSet>();

        // Get file manager
        Gecko::FileManager& fileManager = pManagerSet->GetFileManager();

        // Create save folder
        if(!fileManager.DoesPathExist(fileManager.GetSaveDirectory()))
        {
            fileManager.CreateNewDirectory(fileManager.GetSaveDirectory());
        }

        // Create log folder
        if(!fileManager.DoesPathExist(fileManager.GetLogDirectory()))
        {
            fileManager.CreateNewDirectory(fileManager.GetLogDirectory());
        }

        // Setup logging
        Gecko::SetupLogging(fileManager.JoinPaths(fileManager.GetLogDirectory(), fileManager.GetLogFile()));

        // Check data folder
        if(!fileManager.DoesPathExist(fileManager.GetDataDirectory()))
        {
            ERROR_STATEMENT("Missing data folder, stopping.");
            return EXIT_FAILURE;
        }

        // Run application
        Gecko::Application app;
        app.SetManagers(pManagerSet);
        return app.Run();
    }
    catch (STDException& e)
    {
        ERROR_FORMAT_STATEMENT("Caught exception: {}", e.what());
        return EXIT_FAILURE;
    }
}
