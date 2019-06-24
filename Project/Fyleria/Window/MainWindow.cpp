// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

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

Bool MainWindow::Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
    if(GetBrowserEngine())
    {
        return GetBrowserEngine()->Init(sTitle, iWidth, iHeight, bResizable);
    }
    return false;
}

void MainWindow::Shutdown()
{
    if(GetBrowserEngine())
    {
        GetBrowserEngine()->Shutdown();
    }
}

Bool MainWindow::IsShuttingDown() const
{
    if(GetBrowserEngine())
    {
        return GetBrowserEngine()->GetIsShuttingDown();
    }
    return false;
}

void MainWindow::Navigate(const String& sUrl)
{
    if(GetBrowserEngine())
    {
        GetBrowserEngine()->Navigate(sUrl);
    }
}

void MainWindow::InjectJavascript(const String& sScript)
{
    if(GetBrowserEngine())
    {
        GetBrowserEngine()->InjectJavascript(sScript);
    }
}

void MainWindow::RunJavascript(const String& sScript)
{
    if(GetBrowserEngine())
    {
        GetBrowserEngine()->RunJavascript(sScript);
    }
}

void MainWindow::RunMainLoopIteration(Bool bBlocking)
{
    if(GetBrowserEngine())
    {
        GetBrowserEngine()->RunMainLoopIteration(bBlocking);
    }
}

void MainWindow::SetPostCallback(const BrowserEngine::JavascriptCallback& fnCallback)
{
    if(GetBrowserEngine())
    {
        GetBrowserEngine()->SetPostJavascriptCallback(fnCallback);
    }
}

void MainWindow::SetRunResultCallback(const BrowserEngine::JavascriptCallback& fnCallback)
{
    if(GetBrowserEngine())
    {
        GetBrowserEngine()->SetRunResultJavascriptCallback(fnCallback);
    }
}

};
