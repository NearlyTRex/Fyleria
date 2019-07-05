// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/MainWindow.h"
#if defined(__linux__)
    #include "Window/BrowserEngineWebKitGtk.h"
#endif

namespace Gecko
{

MainWindow::MainWindow()
{
#if defined(__linux__)
    SetBrowserEngine(STDMakeSharedPtr<BrowserEngineWebKitGtk>());
#endif
}

MainWindow::~MainWindow()
{
}

};
