// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Window/MainWindow.h"
#include "Window/BrowserEngineWebView.h"

namespace Gecko
{

MainWindow::MainWindow()
{
    SetBrowserEngine(STDMakeSharedPtr<BrowserEngineWebView>());
}

MainWindow::~MainWindow()
{
}

};
