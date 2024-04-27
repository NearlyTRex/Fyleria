// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Window/BrowserEngineWebView.h"
#include "Scene/SceneConstants.h"
#include "Application/Application.h"

// External includes
#include "webview.h"
#undef Bool

namespace Gecko
{

BrowserEngineWebView::BrowserEngineWebView()
{
}

BrowserEngineWebView::~BrowserEngineWebView()
{
}

Bool BrowserEngineWebView::Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
    // Create web view
#ifdef DEBUG
    SetWebView(STDMakeSharedPtr<webview::webview>(true, nullptr));
#else
    SetWebView(STDMakeSharedPtr<webview::webview>(false, nullptr));
#endif

    // Get internal web view
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView == nullptr)
    {
        return false;
    }

    // Set title
    pWebView->set_title(sTitle);

    // Set sizing
    if(bResizable)
    {
        pWebView->set_size(iWidth, iHeight, WEBVIEW_HINT_NONE);
    }
    else
    {
        pWebView->set_size(iWidth, iHeight, WEBVIEW_HINT_FIXED);
    }

    // Navigate to starting page
    Navigate(STARTING_URI);

    // Switch to starting scene
    GetManagers()->GetSceneManager()->SwitchToScene(STARTING_SCENE);

    // Run window
    pWebView->run();
    return true;
}

void BrowserEngineWebView::Shutdown()
{
    // Call parent
    BrowserEngine::Shutdown();

    // Shutdown
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->terminate();
    }
}

void BrowserEngineWebView::Navigate(const String& sUrl)
{
    // Navigate to url
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->navigate(sUrl);
    }
}

void BrowserEngineWebView::PreloadJavascript(const String& sScript)
{
    // Preload javascript
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->init(sScript);
    }
}

void BrowserEngineWebView::RunJavascript(const String& sScript)
{
    // Run javascript
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->eval(sScript);
    }
}

void BrowserEngineWebView::LoadHtmlContent(const String& sHtml)
{
    // Load html content
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->set_html(sHtml);
    }
}

void BrowserEngineWebView::RunMainLoopIteration(Bool bBlocking)
{
    // Run main loop iteration
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        // Window was closed
        if (!pWebView->window().has_value())
        {
            // Mark as shutting down
            GetIsShuttingDown() = true;
        }
    }
}

void BrowserEngineWebView::BindSynchronousFunction(const String& sName, SynchronousFunction fnFunc)
{
    // Call parent
    BrowserEngine::BindSynchronousFunction(sName, fnFunc);

    // Bind synchronous function
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->bind(sName, fnFunc);
    }
}

void BrowserEngineWebView::BindAsynchronousFunction(const String& sName, AsynchronousFunction fnFunc, void* pArg)
{
    // Call parent
    BrowserEngine::BindAsynchronousFunction(sName, fnFunc, pArg);

    // Bind asynchronous function
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->bind(sName, fnFunc, pArg);
    }
}

void BrowserEngineWebView::UnbindFunction(const String& sName)
{
    // Call parent
    BrowserEngine::UnbindFunction(sName);

    // Unbind function
    webview::webview* pWebView = static_cast<webview::webview*>(GetWebView().get());
    if (pWebView)
    {
        pWebView->unbind(sName);
    }
}

void BrowserEngineWebView::UnbindAllFunctions()
{
    // Call parent
    BrowserEngine::UnbindAllFunctions();
}

};
