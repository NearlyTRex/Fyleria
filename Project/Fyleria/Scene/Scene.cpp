// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/Scene.h"
#include "Scene/SceneTypes.h"
#include "Scene/SceneManager.h"
#include "Window/MainWindow.h"
#include "Utility/Converters.h"
#include "Utility/Json.h"

namespace Gecko
{

Scene::Scene()
{
}

Scene::~Scene()
{
}

Bool Scene::ParseMessage(const String& sMessage, String& sFunction, StringArray& vArgs)
{
    // Parse json data
    Json jsonData = JsonParse(sMessage);

    // Check function
    if(!jsonData.at("function").is_string())
    {
        return false;
    }

    // Check arguments
    if(!jsonData.at("args").is_array())
    {
        return false;
    }

    // Get function and arguments
    sFunction = jsonData.at("function").get<String>();
    vArgs = jsonData.at("args").get<StringArray>();
    return true;
}

Bool Scene::HandleMessage(const String& sMessage)
{
    // Parse message
    String sFunction;
    StringArray vArgs;
    if(!ParseMessage(sMessage, sFunction, vArgs))
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
            SceneManager::GetInstance()->SwitchToScene(sArg1);
            return true;
        case SceneMessageFunctionType::ProcessForm:
            ProcessForm(ConvertQueryStringToStringMap(sArg1));
            SetHtmlContent(GetPageContent());
            return true;
        case SceneMessageFunctionType::ReloadPage:
            SetHtmlContent(GetPageContent());
            return true;
        default:
            break;
    }

    // Nothing was handled
    return false;
}

void Scene::ProcessForm(const StringMap& tParameters)
{
}

void Scene::RunJavascript(const String& sScript)
{
    // Run javascript
    MainWindow::GetInstance()->GetBrowserEngine()->RunJavascript(sScript);
}

void Scene::SetHtmlContent(const String& sHtml)
{
    // Set html
    MainWindow::GetInstance()->GetBrowserEngine()->SetHtmlContent(sHtml);
}

void Scene::SetPostCallback(const BrowserEngine::JavascriptCallback& fnCallback)
{
    // Set callback
    MainWindow::GetInstance()->GetBrowserEngine()->SetPostJavascriptCallback(fnCallback);
}

void Scene::SetRunResultCallback(const BrowserEngine::JavascriptCallback& fnCallback)
{
    // Set callback
    MainWindow::GetInstance()->GetBrowserEngine()->SetRunResultJavascriptCallback(fnCallback);
}

void Scene::ClearPostCallback()
{
    // Clear callback
    MainWindow::GetInstance()->GetBrowserEngine()->SetPostJavascriptCallback(nullptr);
}

void Scene::ClearRunResultCallback()
{
    // Clear callback
    MainWindow::GetInstance()->GetBrowserEngine()->SetRunResultJavascriptCallback(nullptr);
}

};
