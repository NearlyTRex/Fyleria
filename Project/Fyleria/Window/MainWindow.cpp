// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/MainWindow.h"
#include "Window/BrowserEngineEdgeHtml.h"
#include "Window/BrowserEngineWebKitGtk.h"

namespace Gecko
{

MainWindow::MainWindow()
{
#if defined(_WIN32) && _WIN32_WINNT >= 0x0A00
    SetBrowserEngine(STDMakeSharedPtr<BrowserEngineEdgeHtml>());
#elif defined(__linux__)
    SetBrowserEngine(STDMakeSharedPtr<BrowserEngineWebKitGtk>());
#endif
}

MainWindow::~MainWindow()
{
}

};
