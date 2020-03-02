// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/Scene.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Utility/Converters.h"
#include "Utility/Json.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

Scene::Scene()
{
}

Scene::~Scene()
{
}

Bool Scene::ParseMessage(SafeObject<ManagerSet>& pManagerSet, const String& sMessage, String& sFunction, StringArray& vArgs)
{
    // Parse json data
    Json jsonData = JsonParse(sMessage);

    // Keys
    const String sKeyFunction = (+SceneMessageKeyType::Function)._to_string();
    const String sKeyArgs = (+SceneMessageKeyType::Args)._to_string();

    // Check function
    if(!jsonData.at(sKeyFunction).is_string())
    {
        return false;
    }

    // Check arguments
    if(!jsonData.at(sKeyArgs).is_array())
    {
        return false;
    }

    // Get function and arguments
    sFunction = jsonData.at(sKeyFunction).get<String>();
    vArgs = jsonData.at(sKeyArgs).get<StringArray>();
    return true;
}

Bool Scene::HandleMessage(SafeObject<ManagerSet>& pManagerSet, const String& sMessage, String& sFunction, StringArray& vArgs)
{
    // Parse message
    if(!ParseMessage(pManagerSet, sMessage, sFunction, vArgs))
    {
        return false;
    }

    // Set arguments
    const String sArg1 = (vArgs.size() >= 1) ? vArgs[0] : "";
    const String sArg2 = (vArgs.size() >= 2) ? vArgs[1] : "";
    const String sArg3 = (vArgs.size() >= 3) ? vArgs[2] : "";

    // Check scene function
    const SceneMessageFunctionType eFunctionType = GetEnumFromStringOrNone<SceneMessageFunctionType>(sFunction);
    switch(eFunctionType)
    {
        case SceneMessageFunctionType::SwitchToScene:
        {
            pManagerSet->GetSceneManager()->SwitchToScene(pManagerSet, sArg1);
            return true;
        }
        case SceneMessageFunctionType::SubmitForm:
        {
            String sProcessedPage;
            if(ProcessForm(pManagerSet, sArg1, sArg2, sProcessedPage))
            {
                LoadHtmlContent(sProcessedPage);
            }
            return true;
        }
        default:
        {
            break;
        }
    }

    // Nothing was handled
    return false;
}

Bool Scene::ProcessForm(SafeObject<ManagerSet>& pManagerSet, const String& sAction, const String& sParameters, String& sProcessedPage)
{
    // Check input data
    if(sAction.empty() || sParameters.empty())
    {
        ERROR_STATEMENT("Invalid action or parameters");
        return false;
    }

    // Check page handler
    if(GetPageHandler())
    {
        try
        {
            // Notify user
            LOG_FORMAT_STATEMENT("Processing form action '{}'", sAction.c_str());

            // Get parameters
            StringMap tParameters = ConvertQueryStringToStringMap(sParameters);
            tParameters.insert({"action", sAction});

            // Update page content
            GetPageHandler()->UpdatePageContent(pManagerSet, tParameters);
            sProcessedPage = GetPageHandler()->GetPageContent();

            // Notify user
            LOG_FORMAT_STATEMENT("Processing of action '{}' completed", sAction.c_str());
            return true;
        }
        catch(STDException& e)
        {
            // Print exception
            ERROR_FORMAT_STATEMENT("Caught exception: '{}'", e.what());
        }
        catch(GeneralError& e)
        {
            // Print exception
            ERROR_FORMAT_STATEMENT("Caught exception: '{}'", e.what().c_str());
        }
    }
    return false;
}

void Scene::LoadHtmlFromHandler(const WebPageHandlerSharedPtr& pHandler)
{
    // Load html from handler
    if(pHandler)
    {
        String sHandlerContents = pHandler->GetPageContent();
        LoadHtmlContent(sHandlerContents);
    }
}

void Scene::InjectStylesheetFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject stylesheet file
    MainWindow::GetInstance()->GetBrowserEngine()->InjectLocalStylesheetFile(pManagerSet, sFile, sFileRoot);
}

void Scene::InjectJavascriptFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject javascript file
    MainWindow::GetInstance()->GetBrowserEngine()->InjectLocalJavascriptFile(pManagerSet, sFile, sFileRoot);
}

void Scene::InjectHtmlFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject html file
    MainWindow::GetInstance()->GetBrowserEngine()->InjectLocalHtmlFile(pManagerSet, sFile, sFileRoot);
}

void Scene::InjectCommonData(SafeObject<ManagerSet>& pManagerSet)
{
    // Libs location
    String sLocation = pManagerSet->GetFileManager()->GetDataLibsDirectory();

    // Inject css
    InjectStylesheetFile(pManagerSet, LIB_FILE_BOOTSTRAP_CSS, sLocation);
#if DEBUG
    InjectStylesheetFile(pManagerSet, LIB_FILE_JQUERY_TERMINAL_CSS, sLocation);
#endif

    // Inject javascript
    InjectJavascriptFile(pManagerSet, LIB_FILE_BOOTSTRAP_JS, sLocation);
    InjectJavascriptFile(pManagerSet, LIB_FILE_JQUERY_JS, sLocation);
    InjectJavascriptFile(pManagerSet, LIB_FILE_COMMON_JS, sLocation);
#if DEBUG
    InjectJavascriptFile(pManagerSet, LIB_FILE_JQUERY_TERMINAL_JS, sLocation);
    InjectJavascriptFile(pManagerSet, LIB_FILE_JQUERY_MOUSEWHEEL_JS, sLocation);
    InjectJavascriptFile(pManagerSet, LIB_FILE_POLYFILL_KEYBOARD_JS, sLocation);
    InjectJavascriptFile(pManagerSet, LIB_FILE_DEBUG_JS, sLocation);
#endif

    // Inject markup
#if DEBUG
    InjectHtmlFile(pManagerSet, LIB_FILE_DEBUG_HTML, sLocation);
#endif
}

void Scene::RemoveAllInjectedData()
{
    // Remove all injected data
    MainWindow::GetInstance()->GetBrowserEngine()->RemoveAllLocalInjectedData();
}

void Scene::RunJavascript(const String& sScript)
{
    // Run javascript
    MainWindow::GetInstance()->GetBrowserEngine()->RunJavascript(sScript);
}

void Scene::LoadHtmlContent(const String& sHtml)
{
    // Set html
    MainWindow::GetInstance()->GetBrowserEngine()->LoadHtmlContent(sHtml);
}

void Scene::LoadHtmlContentFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Set html content file
    MainWindow::GetInstance()->GetBrowserEngine()->LoadHtmlContentFile(pManagerSet, sFile, sFileRoot);
}

void Scene::DefineJavascriptShortcut(const String& sFunction, const String& sArgs)
{
    // Define shortcut
    MainWindow::GetInstance()->GetBrowserEngine()->DefineJavascriptShortcut(sFunction, sArgs);
}

void Scene::ClearJavascriptShortcut(const String& sFunction)
{
    // Clear shortcut
    MainWindow::GetInstance()->GetBrowserEngine()->ClearJavascriptShortcut(sFunction);
}

void Scene::SetPostCallback(const BrowserEngine::JavascriptCallback& fnCallback)
{
    // Set callback
    MainWindow::GetInstance()->GetBrowserEngine()->GetPostJavascriptCallback()->SetCallback(fnCallback);
}

void Scene::SetRunResultCallback(const BrowserEngine::JavascriptCallback& fnCallback)
{
    // Set callback
    MainWindow::GetInstance()->GetBrowserEngine()->GetRunResultJavascriptCallback()->SetCallback(fnCallback);
}

void Scene::ClearPostCallback()
{
    // Clear callback
    MainWindow::GetInstance()->GetBrowserEngine()->GetPostJavascriptCallback()->SetCallback(nullptr);
}

void Scene::ClearRunResultCallback()
{
    // Clear callback
    MainWindow::GetInstance()->GetBrowserEngine()->GetRunResultJavascriptCallback()->SetCallback(nullptr);
}

};
