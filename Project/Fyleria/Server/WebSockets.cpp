// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Server/WebSockets.h"
#include "Interface/Interface.h"
#include "Utility/Errors.h"
#include "Utility/Macros.h"
#include "Utility/Logging.h"
#include "Utility/Templates.h"

namespace Gecko
{

WebsocketServer::WebsocketServer()
    : Singleton<WebsocketServer>()
{
}

WebsocketServer::~WebsocketServer()
{
    if(GetServerRunThread().get() && GetServerRunThread()->joinable())
    {
        GetServerRunThread()->join();
    }
}

void WebsocketServer::Reset()
{
    // Reset server
    LOG_STATEMENT("Resetting server");
    SetServer(STDMakeSharedPtr<WebsocketAsioServer>());
}

void WebsocketServer::Start()
{
    // Check that server exists
    if (!GetServer())
    {
        return;
    }

    // Setting up server
    LOG_STATEMENT("Setting up server");

    // Set channels
    GetServer()->clear_access_channels(WebsocketAccessLogAll);
    GetServer()->set_access_channels(WebsocketAccessLogAll);
    GetServer()->clear_error_channels(WebsocketErrorLogAll);
    GetServer()->set_error_channels(WebsocketErrorLogAll);

    // Initialize ASIO
    GetServer()->init_asio();
    GetServer()->set_reuse_addr(true);

    // Set handlers
    GetServer()->set_open_handler(STDBindFunc(&WebsocketServer::OnOpen, this, STDPlaceholder1));
    GetServer()->set_close_handler(STDBindFunc(&WebsocketServer::OnClose, this, STDPlaceholder1));
    GetServer()->set_message_handler(STDBindFunc(&WebsocketServer::OnMessage, this, STDPlaceholder1, STDPlaceholder2));

    // Start listening
    ASSERT_ERROR(!GetHostname().empty(), "Host cannot be empty");
    ASSERT_ERROR(GetPort() > 0, "Port must be a positive integer");
    GetServer()->listen(GetHostname(), STDToString(GetPort()));
    LOG_FORMAT_STATEMENT("Now serving at ws://%s:%d\n", GetHostname().c_str(), GetPort());

    // Start the server accept loop
    GetServer()->start_accept();
    SetServerRunThread(STDMakeSharedPtr<STDThread>([=]() { GetServer()->run(); } ));
    SetShutdown(false);
}

void WebsocketServer::Stop()
{
    // Check that server exists
    if (!GetServer())
    {
        return;
    }

    // Halt server
    GetServer()->stop();
    LOG_STATEMENT("Halting server...");
    SetShutdown(true);
    SetClosing(false);
}

void WebsocketServer::OnOpen(WebsocketConnectionHandlePtr pHandle)
{
    // Lock access
    STDLockGuard<STDMutex> lock(GetConnectionMutex());

    // Stop from closing
    SetClosing(false);

    // Add connection to map
    auto pSharedHandle = pHandle.lock();
    WebsocketRawConnectionPtr pConnection = pSharedHandle.get();
    LOG_FORMAT_STATEMENT("Opening connection to %p\n", (void*)pConnection);
    GetConnectionMap().insert({pConnection, pHandle});
}

void WebsocketServer::OnClose(WebsocketConnectionHandlePtr pHandle)
{
    // Lock access
    STDLockGuard<STDMutex> lock(GetConnectionMutex());

    // Start closing
    SetClosing(true);

    // Remove connection from map
    auto pSharedHandle = pHandle.lock();
    WebsocketRawConnectionPtr pConnection = pSharedHandle.get();
    LOG_FORMAT_STATEMENT("Closing connection to %p\n", (void*)pConnection);
    GetConnectionMap().erase(pConnection);
}

void WebsocketServer::OnMessage(WebsocketConnectionHandlePtr pHandle, WebsocketAsioMessagePtr pMessage)
{
    // Lock access
    STDLockGuard<STDMutex> lock(GetConnectionMutex());

    // Ignore if closing
    if (GetClosing())
    {
        return;
    }

    // Parse message payload
    Json jsonData = JsonParse(pMessage->get_payload());
    auto sJsonDataStr = jsonData.dump();
    auto pSharedHandle = pHandle.lock();
    LOG_FORMAT_STATEMENT("Handing message to %p: %s\n", (void*)pSharedHandle.get(), sJsonDataStr.c_str());

    // Output json
    Json outputJsonData;

    // Built-in functions
    outputJsonData = HandleBuiltinFunctionCall(pHandle, jsonData);

    // Builtin function was handled
    if (outputJsonData["is_handled"] == true)
    {
        LOG_FORMAT_STATEMENT("Message %p was handled by built-in function call\n", (void*)pMessage.get());
        SendPayload(pHandle, outputJsonData);
        return;
    }

    // Module functions
    try
    {
        outputJsonData = HandleModuleFunctionCall(pHandle, jsonData);
    }
    catch (GeneralError& error)
    {
        outputJsonData["error_code"] = error.code()._to_integral();
        outputJsonData["error_message"] = error.what();
        outputJsonData["is_handled"] = true;
    }

    // Module function was handled
    if (outputJsonData["is_handled"] == true)
    {
        LOG_FORMAT_STATEMENT("Message %p was handled by module function call\n", (void*)pMessage.get());
        SendPayload(pHandle, outputJsonData);
        return;
    }

    // Message was not handled
    LOG_FORMAT_STATEMENT("Message %p was not handled\n", (void*)pMessage.get());
}

void WebsocketServer::SendPayload(WebsocketRawConnectionPtr pConnection, const Json& jsonData)
{
    // Ignore if closing
    if (GetClosing())
    {
        return;
    }

    // Find connection handle
    auto it = GetConnectionMap().find(pConnection);
    if (it == GetConnectionMap().end())
    {
        return;
    }

    // Send payload
    SendPayload(it->second, jsonData);
}

void WebsocketServer::SendPayload(WebsocketConnectionHandlePtr pHandle, const Json& jsonData)
{
    // Ignore if closing
    if (GetClosing())
    {
        return;
    }

    // Try to send original payload
    try
    {
        auto sJsonDataStr = jsonData.dump();
        auto pSharedHandle = pHandle.lock();
        LOG_FORMAT_STATEMENT("Sending message to %p: %s\n", (void*)pSharedHandle.get(), sJsonDataStr.c_str());
        GetServer()->send(pHandle, sJsonDataStr, WebsocketFrameOpcodeText);
    }
    catch (WebsocketException& e)
    {
        ERROR_FORMAT_STATEMENT("Websocket error %d : %s\n", e.code().value(), e.what());
        ERROR_FORMAT_STATEMENT("Original payload: \n%s\n", jsonData.dump(4).c_str());
    }
}

Json WebsocketServer::HandleBuiltinFunctionCall(WebsocketConnectionHandlePtr pHandle, const Json& jsonData)
{
    // Create output data
    Json outputData(jsonData);
    outputData["is_response"] = true;
    outputData["is_handled"] = false;
    outputData["error_code"] = 0;
    outputData["error_message"] = "";
    outputData["return_value"] = 0;
    outputData["results"] = "";

    // Get function name
    const String sFunctionName = jsonData["function"];
    if (sFunctionName.empty())
    {
        LOG_STATEMENT("No built-in function name specified");
        outputData["error_code"] = (+WebsocketErrorType::NoFunctionSpecified)._to_integral();
        outputData["error_message"] = (+WebsocketErrorType::NoFunctionSpecified)._to_string();
        return outputData;
    }

    // Shutdown
    if (sFunctionName == "shutdown")
    {
        // Halt server
        Stop();
        outputData["is_handled"] = true;
        return outputData;
    }
    return outputData;
}

Json WebsocketServer::HandleModuleFunctionCall(WebsocketConnectionHandlePtr pHandle, const Json& jsonData)
{
    // Create output data
    Json outputData(jsonData);
    outputData["is_response"] = true;
    outputData["is_handled"] = false;
    outputData["error_code"] = 0;
    outputData["error_message"] = "";
    outputData["return_value"] = 0;
    outputData["results"] = "";

    // Get function name
    const String sFunctionName = jsonData["function"];
    if (sFunctionName.empty())
    {
        LOG_STATEMENT("No module function name specified");
        outputData["error_code"] = (+WebsocketErrorType::NoFunctionSpecified)._to_integral();
        outputData["error_message"] = (+WebsocketErrorType::NoFunctionSpecified)._to_string();
        return outputData;
    }

    // Get arguments
    const Json functionArguments = jsonData["args"];
    const Bool bHaveFile = (functionArguments.find("file") != functionArguments.end());
    const Bool bHaveCommand = (functionArguments.find("command") != functionArguments.end());
    const Bool bHaveResultsId = (functionArguments.find("results_id") != functionArguments.end());
    const Bool bHaveKeepResults = (functionArguments.find("keep_results") != functionArguments.end());
    const String sInputFile = (bHaveFile) ? functionArguments["file"] : "";
    const String sInputCommand = (bHaveCommand) ? functionArguments["command"] : "";
    const String sInputResultsId = (bHaveResultsId) ? functionArguments["results_id"] : "";
    const Bool bKeepResults = (bHaveKeepResults) ? functionArguments["keep_results"].get<Bool>() : false;

    // Run module file
    if (sFunctionName == "run_module_file")
    {
        if (!bHaveFile)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_RunModuleFile");
        bool return_value = DLL_RunModuleFile(sInputFile.c_str());
        outputData["return_value"] = return_value;
        outputData["is_handled"] = true;
        return outputData;
    }

    // Run module file and get results
    else if (sFunctionName == "run_module_file_results")
    {
        if (!bHaveFile || !bHaveCommand)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_RunModuleFile");
        bool return_value = DLL_RunModuleFile(sInputFile.c_str());
        if (!return_value)
        {
            outputData["return_value"] = return_value;
            outputData["is_handled"] = true;
            outputData["results"] = "";
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_GetModuleResultSize");
        unsigned int uResultsLen = DLL_GetModuleResultSize(sInputResultsId.c_str());
        char sResultsStr[uResultsLen + 1];
        STDFillData(sResultsStr, sResultsStr + uResultsLen + 1, 0);

        LOG_STATEMENT("Calling DLL_GetModuleResults");
        return_value = DLL_GetModuleResults(sInputResultsId.c_str(), sResultsStr, uResultsLen);
        outputData["return_value"] = return_value;
        outputData["is_handled"] = true;
        outputData["results"] = String(sResultsStr);

        if (!bKeepResults)
        {
            LOG_STATEMENT("Calling DLL_ClearModuleResult");
            DLL_ClearModuleResult(sInputResultsId.c_str());
        }
        return outputData;
    }

    // Run module file
    else if (sFunctionName == "run_module_command")
    {
        if (!bHaveCommand)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_RunModuleCommand");
        bool return_value = DLL_RunModuleCommand(sInputCommand.c_str());
        outputData["return_value"] = return_value;
        outputData["is_handled"] = true;
        return outputData;
    }

    // Run module file and get results
    else if (sFunctionName == "run_module_command_results")
    {
        if (!bHaveCommand || !bHaveResultsId)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_RunModuleCommand");
        bool return_value = DLL_RunModuleCommand(sInputCommand.c_str());
        if (!return_value)
        {
            outputData["return_value"] = return_value;
            outputData["is_handled"] = true;
            outputData["results"] = "";
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_GetModuleResultSize");
        unsigned int uResultsLen = DLL_GetModuleResultSize(sInputResultsId.c_str());
        char sResultsStr[uResultsLen + 1];
        STDFillData(sResultsStr, sResultsStr + uResultsLen + 1, 0);

        LOG_STATEMENT("Calling DLL_GetModuleResults");
        return_value = DLL_GetModuleResults(sInputResultsId.c_str(), sResultsStr, uResultsLen);
        outputData["return_value"] = return_value;
        outputData["is_handled"] = true;
        outputData["results"] = String(sResultsStr);

        if (!bKeepResults)
        {
            LOG_STATEMENT("Calling DLL_ClearModuleResult");
            DLL_ClearModuleResult(sInputResultsId.c_str());
        }
        return outputData;
    }

    // Set current module results ID
    else if (sFunctionName == "set_current_module_result_id")
    {
        if (!bHaveResultsId)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_SetCurrentModuleResultID");
        DLL_SetCurrentModuleResultID(sInputResultsId.c_str());
        outputData["is_handled"] = true;
        return outputData;
    }

    // Clear module results
    else if (sFunctionName == "clear_module_results")
    {
        if (!bHaveResultsId)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_ClearModuleResult");
        DLL_ClearModuleResult(sInputResultsId.c_str());
        outputData["is_handled"] = true;
        return outputData;
    }

    // Clear all module results
    else if (sFunctionName == "clear_all_module_results")
    {
        LOG_STATEMENT("Calling DLL_ClearAllModuleResults");
        DLL_ClearAllModuleResults();
        outputData["is_handled"] = true;
        return outputData;
    }

    // Does module result exist
    else if (sFunctionName == "does_module_result_exist")
    {
        if (!bHaveResultsId)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_DoesModuleResultExist");
        bool return_value = DLL_DoesModuleResultExist(sInputResultsId.c_str());
        outputData["return_value"] = return_value;
        outputData["is_handled"] = true;
        return outputData;
    }

    // Get module result size
    else if (sFunctionName == "get_module_result_size")
    {
        if (!bHaveResultsId)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_GetModuleResultSize");
        unsigned int return_value = DLL_GetModuleResultSize(sInputResultsId.c_str());
        outputData["return_value"] = return_value;
        outputData["is_handled"] = true;
        return outputData;
    }

    // Get module results
    else if (sFunctionName == "get_module_results")
    {
        if (!bHaveResultsId)
        {
            LOG_STATEMENT("Missing required arguments");
            outputData["error_code"] = (+WebsocketErrorType::MissingRequiredArguments)._to_integral();
            outputData["error_message"] = (+WebsocketErrorType::MissingRequiredArguments)._to_string();
            return outputData;
        }

        LOG_STATEMENT("Calling DLL_GetModuleResultSize");
        unsigned int uResultsLen = DLL_GetModuleResultSize(sInputResultsId.c_str());
        char sResultsStr[uResultsLen + 1];
        STDFillData(sResultsStr, sResultsStr + uResultsLen + 1, 0);

        LOG_STATEMENT("Calling DLL_GetModuleResults");
        bool return_value = DLL_GetModuleResults(sInputResultsId.c_str(), sResultsStr, uResultsLen);
        outputData["return_value"] = return_value;
        outputData["is_handled"] = true;
        outputData["results"] = String(sResultsStr);
        return outputData;
    }

    // Verify module data
    else if (sFunctionName == "verify_module_data")
    {
        LOG_STATEMENT("Calling DLL_VerifyModuleData");
        DLL_VerifyModuleData();
        outputData["is_handled"] = true;
        return outputData;
    }
    return outputData;
}

};
