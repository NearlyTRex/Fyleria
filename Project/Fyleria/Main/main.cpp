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
#include "Utility/Wrapper.h"

namespace Gecko
{

// Get main options
BoostProgramOptionsDescription GetMainOptions()
{
    BoostProgramOptionsDescription options("General options");
    options.add_options()
        ("help,h", "Display this help message")
        ("version,v", "Display the version number")
    ;
    return options;
}

// Handle main options
void HandleMainOptions(const BoostProgramOptionsDescription& options, const BoostProgramOptionsVariablesMap& vm)
{
    // Print help
    if(vm.count("help"))
    {
        STDCout << Application::GetName() << STDEndl;
        STDCout << Application::GetVersionShort() << STDEndl;
        STDCout << options;
        STDExit(EXIT_SUCCESS);
    }

    // Print version
    if(vm.count("version"))
    {
        STDCout << Application::GetVersionLong() << STDEndl;
        STDExit(EXIT_SUCCESS);
    }
}

};

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
        // Create options
        BoostProgramOptionsDescription options;
        options.add(Gecko::GetMainOptions());
        options.add(Gecko::GetWrapperOptions());

        // Parse command line
        BoostProgramOptionsVariablesMap vm;
#if defined(PLATFORM_OS_WINDOWS)
        BoostProgramOptionsCommandLineParser parser(__argc, __argv);
#else
        BoostProgramOptionsCommandLineParser parser(argc, argv);
#endif
        BoostProgramOptionsStore(parser.options(options).allow_unregistered().run(), vm);
        BoostProgramOptionsNotify(vm);

        // Handle options
        Gecko::HandleMainOptions(options, vm);
        Gecko::HandleWrapperOptions(options, vm);

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
