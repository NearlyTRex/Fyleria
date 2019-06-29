// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/Scene.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
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

    // Check scene function
    const SceneMessageFunctionType eFunctionType = GetEnumFromStringOrNone<SceneMessageFunctionType>(sFunction);
    switch(eFunctionType)
    {
        case SceneMessageFunctionType::SwitchScene:
            break;
        case SceneMessageFunctionType::ReloadHtml:
            break;
        default:
            break;
    }

    // Nothing was handled
    return false;
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
