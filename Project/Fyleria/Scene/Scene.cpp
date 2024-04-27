// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/Scene.h"
#include "Scene/SceneMacros.h"
#include "Scene/SceneConstants.h"
#include "File/FileConstants.h"
#include "Application/Application.h"
#include "Window/MainWindow.h"
#include "Utility/Tags.h"
#include "Utility/Json.h"

namespace Gecko
{

Scene::Scene(const String& sSceneID)
{
    SetSceneID(sSceneID);
}

Scene::~Scene()
{
}

void Scene::Bind()
{
    // Bind functions
    BIND_SYNCHRONOUS_FUNCTION_ARG1_NORETURN(SwitchToScene, String, scene_id);
    BIND_SYNCHRONOUS_FUNCTION_NORETURN(Shutdown);
}

void Scene::Unbind()
{
    // Unbind all functions
    UnbindAllFunctions();
}

void Scene::Start()
{
    // Add jQuery
    AddScriptFile(THIRDPARTY_FILE_JQUERY_JS);

    // Add jQueryTerminal
#if DEBUG
    AddStyleFile(THIRDPARTY_FILE_JQUERY_TERMINAL_CSS);
    AddScriptFile(THIRDPARTY_FILE_JQUERY_TERMINAL_JS);
#endif

    // Add Phaser
    AddScriptFile(THIRDPARTY_FILE_PHASER_JS);

    // Release features
#if NDEBUG
    AddStyle(COMMON_CSS_DISABLE_USER_SELECTIONS);
    AddScript(COMMON_JS_DISABLE_SUBMIT_ACTIONS);
    AddScript(COMMON_JS_DISABLE_CONTEXT_MENU);
    AddScript(COMMON_JS_DISABLE_CTRL_SHORTCUTS);
#endif

    // Debug features
#if DEBUG
    AddScript(COMMON_JS_DISABLE_SUBMIT_ACTIONS);
    AddMarkup(COMMON_HTML_SCENE_SELECTOR);
    AddScript(GetDebugConsole().GenerateConsoleJavaScript());
    AddMarkup(GetDebugConsole().GenerateConsoleHTML());
#endif
}

void Scene::Finish()
{
    // Clear injectables
    SetInjectableStyles("");
    SetInjectableScripts("");
    SetInjectableMarkups("");

    // Clear main page contents
    SetMainPageContents("");
}

void Scene::Display()
{
    // Get page contents
    String sPageContents(GetMainPageContents());

    // Replace tokens
    BoostReplaceAll(sPageContents, TOKEN_URI_BASE, GetManagers()->GetFileManager()->GetUriPath(GetManagers()->GetFileManager()->GetDataDirectory()));
    BoostReplaceAll(sPageContents, TOKEN_URI_LIBS, GetManagers()->GetFileManager()->GetUriPath(GetManagers()->GetFileManager()->GetDataLibsDirectory()));
    BoostReplaceAll(sPageContents, TOKEN_URI_MAIN, GetManagers()->GetFileManager()->GetUriPath(GetManagers()->GetFileManager()->GetDataLibsMainDirectory()));
    BoostReplaceAll(sPageContents, TOKEN_URI_THIRDPARTY, GetManagers()->GetFileManager()->GetUriPath(GetManagers()->GetFileManager()->GetDataLibsThirdPartyDirectory()));
    BoostReplaceAll(sPageContents, TOKEN_INJECTED_STYLES, GetInjectableStyles());
    BoostReplaceAll(sPageContents, TOKEN_INJECTED_SCRIPTS, GetInjectableScripts());
    BoostReplaceAll(sPageContents, TOKEN_INJECTED_MARKUPS, GetInjectableMarkups());

    // Load contents
    MainWindow::GetInstance()->GetBrowserEngine()->LoadHtmlContent(sPageContents);
}

void Scene::SwitchToScene(const String& sSceneID)
{
    GetManagers()->GetSceneManager()->SwitchToScene(sSceneID);
}

void Scene::Shutdown()
{
    MainWindow::GetInstance()->GetBrowserEngine()->Shutdown();
}

void Scene::Navigate(const String& sUrl)
{
    MainWindow::GetInstance()->GetBrowserEngine()->Navigate(sUrl);
}

void Scene::PreloadJavascript(const String& sScript)
{
    MainWindow::GetInstance()->GetBrowserEngine()->PreloadJavascript(sScript);
}

void Scene::RunJavascript(const String& sScript)
{
    MainWindow::GetInstance()->GetBrowserEngine()->RunJavascript(sScript);
}

void Scene::LoadHtmlContent(const String& sHtml)
{
    MainWindow::GetInstance()->GetBrowserEngine()->LoadHtmlContent(sHtml);
}

void Scene::BindSynchronousFunction(const String& sName, const StringArray& vArgs, BrowserEngine::SynchronousFunction fnFunc)
{
    MainWindow::GetInstance()->GetBrowserEngine()->BindSynchronousFunction(sName, fnFunc);
#if DEBUG
    GetDebugConsole().AddCommand(sName, vArgs);
#endif
}

void Scene::BindAsynchronousFunction(const String& sName, const StringArray& vArgs, BrowserEngine::AsynchronousFunction fnFunc, void* pArg)
{
    MainWindow::GetInstance()->GetBrowserEngine()->BindAsynchronousFunction(sName, fnFunc, pArg);
#if DEBUG
    GetDebugConsole().AddCommand(sName, vArgs);
#endif
}

void Scene::UnbindFunction(const String& sName)
{
    MainWindow::GetInstance()->GetBrowserEngine()->UnbindFunction(sName);
}

void Scene::UnbindAllFunctions()
{
    MainWindow::GetInstance()->GetBrowserEngine()->UnbindAllFunctions();
}

void Scene::AddStyle(const String& sStyle)
{
    GetInjectableStyles().append(MakeInlineStylesheetTag(sStyle));
}

void Scene::AddStyleFile(const String& sFile)
{
    GetInjectableStyles().append(MakeFileStylesheetTag(sFile, GetManagers()->GetFileManager()->GetDataLibsDirectory()));
}

void Scene::AddScript(const String& sScript)
{
    GetInjectableScripts().append(MakeInlineJavascriptTag(sScript));
}

void Scene::AddScriptFile(const String& sFile)
{
    GetInjectableScripts().append(MakeFileJavascriptTag(sFile, GetManagers()->GetFileManager()->GetDataLibsDirectory()));
}

void Scene::AddMarkup(const String& sMarkup)
{
    GetInjectableScripts().append(sMarkup);
}

void Scene::AddMarkupFile(const String& sFile)
{
    String sFileContents;
    if (GetManagers()->GetFileManager()->ReadFileToString(sFile, sFileContents, GetManagers()->GetFileManager()->GetDataLibsDirectory()))
    {
        GetInjectableMarkups().append(sFileContents);
    }
}

void Scene::SetMainPageContent()
{
    String sFileContents;
    if (GetManagers()->GetFileManager()->ReadFileToString(GetManagers()->GetFileManager()->GetScenePageFile(GetSceneID()), sFileContents))
    {
        GetMainPageContents().assign(sFileContents);
    }
}

};
