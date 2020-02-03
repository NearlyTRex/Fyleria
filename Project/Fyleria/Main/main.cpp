// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Utility/Converters.h"
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
        // Create application
        Gecko::Application app;

        // Add dll directory
#if defined(PLATFORM_OS_WINDOWS)
        auto sBinDir = app.GetManagers()->GetFileManager()->GetBinDirectory();
        SetDllDirectory(Gecko::ConvertStringToWideString(sBinDir).c_str());
#endif

        // Create save folder
        Gecko::String sSaveDirectory = app.GetManagers()->GetFileManager()->GetSaveDirectory();
        if(!app.GetManagers()->GetFileManager()->DoesPathExist(sSaveDirectory))
        {
            app.GetManagers()->GetFileManager()->CreateNewDirectory(sSaveDirectory);
        }

        // Create log folder
        Gecko::String sLogDirectory = app.GetManagers()->GetFileManager()->GetLogDirectory();
        if(!app.GetManagers()->GetFileManager()->DoesPathExist(sLogDirectory))
        {
            app.GetManagers()->GetFileManager()->CreateNewDirectory(sLogDirectory);
        }

        // Setup logging
        Gecko::String sLogFile = app.GetManagers()->GetFileManager()->GetLogFile();
        Gecko::String sFullLogFile = app.GetManagers()->GetFileManager()->JoinPaths(sLogDirectory, sLogFile);
        Gecko::SetupLogging(sFullLogFile);

        // Check data folder
        Gecko::String sDataDirectory = app.GetManagers()->GetFileManager()->GetDataDirectory();
        if(!app.GetManagers()->GetFileManager()->DoesPathExist(sDataDirectory))
        {
            ERROR_STATEMENT("Missing data folder, stopping.");
            return EXIT_FAILURE;
        }

        // Run application
        return app.Run();
    }
    catch (STDException& e)
    {
        ERROR_FORMAT_STATEMENT("Caught exception: {}", e.what());
        return EXIT_FAILURE;
    }
}
