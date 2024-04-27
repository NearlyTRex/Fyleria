// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Application/Application.h"
#include "Application/ApplicationConstants.h"
#include "Utility/Errors.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"
#include "Utility/Version.h"
#include "Utility/Wrapper.h"

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
        // Create program description
        BoostProgramOptionsDescription description{Gecko::APPLICATION_NAME_LONG};
        description.add_options()
            ("help,h", "Display this help message")
            ("version,v", "Display the version number")
#ifdef DEBUG
            ("generate_wrappers,g", "Generate wrapper files")
#endif
        ;

        // Parse command line
        BoostProgramOptionsVariablesMap vm;
#if defined(PLATFORM_OS_WINDOWS)
        BoostProgramOptionsStore(BoostProgramOptionsCommandLineParser(__argc, __argv).options(description).allow_unregistered().run(), vm);
#else
        BoostProgramOptionsStore(BoostProgramOptionsCommandLineParser(argc, argv).options(description).allow_unregistered().run(), vm);
#endif
        BoostProgramOptionsNotify(vm);

        // Print help
        if(vm.count("help"))
        {
            STDCout << description;
            return EXIT_SUCCESS;
        }

        // Print version
        if(vm.count("version"))
        {
            STDCout << GetVersionString() << STDEndl;
            return EXIT_SUCCESS;
        }

#ifdef DEBUG
        // Generate wrappers
        if(vm.count("generate_wrappers"))
        {
            Gecko::WriteWrapperFiles();
            return EXIT_SUCCESS;
        }
#endif

        // Create application
        Gecko::Application app;

        // Run application
        app.Initialize();
        app.Run();
        app.Finalize();
        return EXIT_SUCCESS;
    }
    catch (Gecko::GeneralError& e)
    {
        ERROR_FORMAT_STATEMENT("Caught exception: {}", e.what());
        return EXIT_FAILURE;
    }
    catch (STDException& e)
    {
        ERROR_FORMAT_STATEMENT("Caught exception: {}", e.what());
        return EXIT_FAILURE;
    }
}
