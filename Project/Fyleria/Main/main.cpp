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
        // Create manager set
        auto pManagerSet = STDMakeSharedPtr<Gecko::ManagerSet>();

        // Add dll directory
#if defined(PLATFORM_OS_WINDOWS)
        auto sBinDir = pManagerSet->GetFileManager()->GetBinDirectory();
        SetDllDirectory(Gecko::ConvertStringToWideString(sBinDir).c_str());
#endif

        // Create save folder
        Gecko::String sSaveDirectory = pManagerSet->GetFileManager()->GetSaveDirectory();
        if(!pManagerSet->GetFileManager()->DoesPathExist(sSaveDirectory))
        {
            pManagerSet->GetFileManager()->CreateNewDirectory(sSaveDirectory);
        }

        // Create log folder
        Gecko::String sLogDirectory = pManagerSet->GetFileManager()->GetLogDirectory();
        if(!pManagerSet->GetFileManager()->DoesPathExist(sLogDirectory))
        {
            pManagerSet->GetFileManager()->CreateNewDirectory(sLogDirectory);
        }

        // Setup logging
        Gecko::String sLogFile = pManagerSet->GetFileManager()->GetLogFile();
        Gecko::String sFullLogFile = pManagerSet->GetFileManager()->JoinPaths(sLogDirectory, sLogFile);
        Gecko::SetupLogging(sFullLogFile);

        // Check data folder
        Gecko::String sDataDirectory = pManagerSet->GetFileManager()->GetDataDirectory();
        if(!pManagerSet->GetFileManager()->DoesPathExist(sDataDirectory))
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
