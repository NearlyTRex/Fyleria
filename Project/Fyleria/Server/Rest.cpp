// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Server/Rest.h"
#include "Interface/Interface.h"
#include "Web/WebPageManager.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"
#include "Utility/Macros.h"
#include "Utility/Types.h"
#include "Utility/Json.h"
#include "Utility/Filesystem.h"
#include "Utility/Logging.h"
#include "Utility/Templates.h"

namespace Gecko
{

CustomHttpHandler::CustomHttpHandler(const String& sWebRoot)
    : HttpHandler()
{
    SetWebRoot(sWebRoot);
}

void CustomHttpHandler::onRequest(const HttpRequest& request, HttpResponseWriter response)
{
    LOG_FORMAT_STATEMENT("Rest Handler Request: Method(%s) Resource(%s) Query(%s) Body(%s)\n",
        methodString(request.method()),
        request.resource().c_str(),
        Json(request.query().parameters()).dump().c_str(),
        request.body().c_str());
    if (request.method() == HttpMethodGet)
    {
        if (request.resource() == WEB_ENDPOINT_DOES_MODULE_RESULT_EXIST)
        {
            DoGet_DoesModuleResultExist(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_GET_MODULE_RESULT_SIZE)
        {
            DoGet_GetModuleResultSize(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_GET_MODULE_RESULTS)
        {
            DoGet_GetModuleResults(request, response);
        }
        else if (StartsWith(request.resource(), String(WEB_PAGE_TOOL_BASE)))
        {
            DoRequest_ServeTool(request, response);
        }
        else
        {
            DoRequest_ServeFile(request, response);
        }
    }
    else if (request.method() == HttpMethodPost)
    {
        if (request.resource() == WEB_ENDPOINT_RUN_MODULE_FILE)
        {
            DoPost_RunModuleFile(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_RUN_MODULE_FILE_RESULTS)
        {
            DoPost_RunModuleFileResults(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_RUN_MODULE_COMMAND)
        {
            DoPost_RunModuleCommand(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_RUN_MODULE_COMMAND_RESULTS)
        {
            DoPost_RunModuleCommandResults(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_SET_CURRENT_MODULE_RESULT_ID)
        {
            DoPost_SetCurrentModuleResultID(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_CLEAR_MODULE_RESULTS)
        {
            DoPost_ClearModuleResult(request, response);
        }
        else if (request.resource() == WEB_ENDPOINT_CLEAR_ALL_MODULE_RESULTS)
        {
            DoPost_ClearAllModuleResults(request, response);
        }
        else if (StartsWith(request.resource(), String(WEB_PAGE_TOOL_BASE)))
        {
            DoRequest_ServeTool(request, response);
        }
        else
        {
            String sMessage = (BoostFormatString("Unknown POST resource '%1%'.") % request.resource()).str();
            HandleResponse(HttpCodeMethodNotAllowed, response, sMessage, "text/plain");
        }
    }
    else if (request.method() == HttpMethodOptions)
    {
        DoOptions_RequestToRun(request, response);
    }
    else
    {
        String sMessage = (BoostFormatString("Unhandled method '%1%'.") % methodString(request.method())).str();
        HandleResponse(HttpCodeMethodNotAllowed, response, sMessage, "text/plain");
    }
}

void CustomHttpHandler::DoOptions_RequestToRun(const HttpRequest& request, HttpResponseWriter& response)
{
    HandleResponse(HttpCodeOk, response, "", "text/plain");
}

void CustomHttpHandler::DoPost_RunModuleFile(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputFile = "";
    if(!GetRequiredParameter(request, response, "file", sInputFile))
    {
        return;
    }

    // Run method
    LOG_STATEMENT("Calling DLL_RunModuleFile");
    bool return_value = DLL_RunModuleFile(sInputFile.c_str());
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Could not run file '%1%'.") % sInputFile).str();
        HandleResponse(HttpCodeInternalServerError, response, sMessage, "text/plain");
        return;
    }

    // Send results
    Json return_json;
    return_json["return_value"] = return_value;
    HandleResponse(HttpCodeOk, response, return_json.dump(), "application/json");
}

void CustomHttpHandler::DoPost_RunModuleFileResults(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputFile = "";
    String sInputResultsId = "";
    if(!GetRequiredParameter(request, response, "file", sInputFile) ||
       !GetRequiredParameter(request, response, "results_id", sInputResultsId))
    {
        return;
    }

    // Get keep results
    Bool bKeepResults = false;
    GetOptionalParameter(request, "keep_results", bKeepResults);

    // Run method
    LOG_STATEMENT("Calling DLL_RunModuleFile");
    bool return_value = DLL_RunModuleFile(sInputFile.c_str());
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Could not run file '%1%'.") % sInputFile).str();
        HandleResponse(HttpCodeInternalServerError, response, sMessage, "text/plain");
        return;
    }

    // Send results
    SendResultsToUser(response, sInputResultsId, bKeepResults);
}

void CustomHttpHandler::DoPost_RunModuleCommand(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputCommand = "";
    if(!GetRequiredParameter(request, response, "command", sInputCommand))
    {
        return;
    }

    // Run method
    LOG_STATEMENT("Calling DLL_RunModuleCommand");
    bool return_value = DLL_RunModuleCommand(sInputCommand.c_str());
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Could not run command '%1%'.") % sInputCommand).str();
        HandleResponse(HttpCodeInternalServerError, response, sMessage, "text/plain");
        return;
    }

    // Send results
    Json return_json;
    return_json["return_value"] = return_value;
    HandleResponse(HttpCodeOk, response, return_json.dump(), "application/json");
}

void CustomHttpHandler::DoPost_RunModuleCommandResults(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputCommand = "";
    String sInputResultsId = "";
    if(!GetRequiredParameter(request, response, "command", sInputCommand) ||
       !GetRequiredParameter(request, response, "results_id", sInputResultsId))
    {
        return;
    }

    // Get keep results
    Bool bKeepResults = false;
    GetOptionalParameter(request, "keep_results", bKeepResults);

    // Run method
    LOG_STATEMENT("Calling DLL_RunModuleCommand");
    bool return_value = DLL_RunModuleCommand(sInputCommand.c_str());
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Could not run command '%1%'.") % sInputCommand).str();
        HandleResponse(HttpCodeInternalServerError, response, sMessage, "text/plain");
        return;
    }

    // Send results
    SendResultsToUser(response, sInputResultsId, bKeepResults);
}

void CustomHttpHandler::DoPost_SetCurrentModuleResultID(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputResultsId = "";
    if(!GetRequiredParameter(request, response, "results_id", sInputResultsId))
    {
        return;
    }

    // Run method
    LOG_STATEMENT("Calling DLL_SetCurrentModuleResultID");
    DLL_SetCurrentModuleResultID(sInputResultsId.c_str());

    // Send results
    Json return_json;
    return_json["return_value"] = true;
    HandleResponse(HttpCodeOk, response, return_json.dump(), "application/json");
}

void CustomHttpHandler::DoPost_ClearModuleResult(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputResultsId = "";
    if(!GetRequiredParameter(request, response, "results_id", sInputResultsId))
    {
        return;
    }

    // Run method
    LOG_STATEMENT("Calling DLL_ClearModuleResult");
    DLL_ClearModuleResult(sInputResultsId.c_str());

    // Send results
    Json return_json;
    return_json["return_value"] = true;
    HandleResponse(HttpCodeOk, response, return_json.dump(), "application/json");
}

void CustomHttpHandler::DoPost_ClearAllModuleResults(const HttpRequest& request, HttpResponseWriter& response)
{
    // Run method
    LOG_STATEMENT("Calling DLL_ClearAllModuleResults");
    DLL_ClearAllModuleResults();

    // Send results
    Json return_json;
    return_json["return_value"] = true;
    HandleResponse(HttpCodeOk, response, return_json.dump(), "application/json");
}

void CustomHttpHandler::DoGet_DoesModuleResultExist(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputResultsId = "";
    if(!GetRequiredParameter(request, response, "results_id", sInputResultsId))
    {
        return;
    }

    // Run method
    LOG_STATEMENT("Calling DLL_DoesModuleResultExist");
    bool return_value = DLL_DoesModuleResultExist(sInputResultsId.c_str());

    // Send results
    Json return_json;
    return_json["return_value"] = return_value;
    HandleResponse(HttpCodeOk, response, return_json.dump(), "application/json");
}

void CustomHttpHandler::DoGet_GetModuleResultSize(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputResultsId = "";
    if(!GetRequiredParameter(request, response, "results_id", sInputResultsId))
    {
        return;
    }

    // Run method
    LOG_STATEMENT("Calling DLL_GetModuleResultSize");
    unsigned int return_value = DLL_GetModuleResultSize(sInputResultsId.c_str());

    // Send results
    Json return_json;
    return_json["return_value"] = return_value;
    HandleResponse(HttpCodeOk, response, return_json.dump(), "application/json");
}

void CustomHttpHandler::DoGet_GetModuleResults(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get input
    String sInputResultsId = "";
    if(!GetRequiredParameter(request, response, "results_id", sInputResultsId))
    {
        return;
    }

    // Send results
    SendResultsToUser(response, sInputResultsId, true);
}

void CustomHttpHandler::DoRequest_ServeTool(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get request resource string
    const String sResource = request.resource();

    // Retrieve GET/POST parameters
    StringMap tGetParams = ConvertQueryStringToStringMap(request.query().as_str());
    StringMap tPostParams = ConvertQueryStringToStringMap(request.body());
    StringMap tAllParams;
    tAllParams.insert(tGetParams.begin(), tGetParams.end());
    tAllParams.insert(tPostParams.begin(), tPostParams.end());

    // Check for available tools
    String sOutput;
    if(sResource == WEB_PAGE_TOOL_CHARACTER_MANAGER)
    {
        WebPageManager::GetInstance()->GetCharacterManagerPage().UpdatePageContent(tAllParams);
        sOutput = WebPageManager::GetInstance()->GetCharacterManagerPage().GetPageContent();
    }
    else if(sResource == WEB_PAGE_TOOL_PARTY_MANAGER)
    {
        WebPageManager::GetInstance()->GetPartyManagerPage().UpdatePageContent(tAllParams);
        sOutput = WebPageManager::GetInstance()->GetPartyManagerPage().GetPageContent();
    }
    else if(sResource == WEB_PAGE_TOOL_SAVE_MANAGER)
    {
        WebPageManager::GetInstance()->GetSaveManagerPage().UpdatePageContent(tAllParams);
        sOutput = WebPageManager::GetInstance()->GetSaveManagerPage().GetPageContent();
    }

    // Handle unknown tools
    if(sOutput.empty())
    {
        String sMessage = (BoostFormatString("The requested URL '%1%' was not found on this server.") % sResource).str();
        HandleResponse(HttpCodeNotFound, response, sMessage, "text/plain");
        return;
    }

    // Send output
    HandleResponse(HttpCodeOk, response, sOutput, "text/html");
    return;
}

void CustomHttpHandler::DoRequest_ServeFile(const HttpRequest& request, HttpResponseWriter& response)
{
    // Get request resource string
    const String sResource = request.resource();

    // Check if resource string ends with directory
    if(EndsWith(sResource, String("/")))
    {
        // List of all valid index files
        const StringArray vValidIndexFiles = {
            "index.html", "index.htm", "index.shtml", "index.php", "index.cgi",
            "default.html", "default.htm", "home.html", "home.htm", "placeholder.html"
        };

        // Find the first valid index file
        for (auto& sIndexFile : vValidIndexFiles)
        {
            // Get file path
            String sResourceFile(GetCanonicalPath(JoinPaths(GetWebRoot(), sResource + sIndexFile)));

            // Try serving file
            if(SendFileToUser(response, sResourceFile))
            {
                return;
            }
        }
    }
    else
    {
        // Get file path
        String sResourceFile(GetCanonicalPath(JoinPaths(GetWebRoot(), sResource)));

        // Try serving file
        if(SendFileToUser(response, sResourceFile))
        {
            return;
        }
    }

    // File was not found
    String sMessage = (BoostFormatString("The requested URL '%1%' was not found on this server.") % sResource).str();
    HandleResponse(HttpCodeNotFound, response, sMessage, "text/plain");
    return;
}

void CustomHttpHandler::HandleResponse(const HttpCode& code, HttpResponseWriter& response, const String& sResponse, const String& sMimeType)
{
    // Send response
    LOG_FORMAT_STATEMENT("Sending response: code(%d), text(%s), mime(%s)\n", static_cast<int>(code), sResponse.c_str(), sMimeType.c_str());
    response.headers()
        .add<HttpHeaderAccessControlAllowOrigin>("*")
        .add<HttpHeaderAccessControlAllowMethods>("GET, POST, OPTIONS")
        .add<HttpHeaderAccessControlAllowHeaders>("Content-Type")
        .add<HttpHeaderContentType>(HttpMediaType::fromString(sMimeType));
    response.send(code, sResponse);
}

Bool CustomHttpHandler::SendResultsToUser(HttpResponseWriter& response, const String& sResultsID, Bool bKeepResults)
{
    // Get results size
    LOG_STATEMENT("Calling DLL_GetModuleResultSize");
    unsigned int uResultsLen = DLL_GetModuleResultSize(sResultsID.c_str());
    char sResultsStr[uResultsLen + 1] = {0};
    if (!uResultsLen)
    {
        String sMessage = (BoostFormatString("The result size of '%1%' was zero.") % uResultsLen).str();
        HandleResponse(HttpCodeNotAcceptable, response, sMessage, "text/plain");
        return false;
    }

    // Get result
    LOG_STATEMENT("Calling DLL_GetModuleResults");
    bool return_value = DLL_GetModuleResults(sResultsID.c_str(), sResultsStr, uResultsLen);
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Failed retrieving result for '%1%'.") % sResultsID).str();
        HandleResponse(HttpCodeNotAcceptable, response, sMessage, "text/plain");
        return false;
    }

    // Handle results
    String sResults = sResultsStr;
    if (!bKeepResults)
    {
        LOG_STATEMENT("Calling DLL_ClearModuleResult");
        DLL_ClearModuleResult(sResultsID.c_str());
    }

    // Send results
    HandleResponse(HttpCodeOk, response, sResults, "application/json");
    return true;
}

Bool CustomHttpHandler::SendFileToUser(HttpResponseWriter& response, const String& sFile)
{
    // Check file existence
    if(!DoesPathExist(sFile) || !IsFile(sFile))
    {
        ERROR_FORMAT_STATEMENT("File '%s' does not exist\n", sFile.c_str());
        return false;
    }

    // Send file
    LOG_FORMAT_STATEMENT("Serving file '%s'\n", sFile.c_str());
    HttpServeFile(response, sFile.c_str());
    return true;
}

template <class T>
Bool CustomHttpHandler::GetOptionalParameter(
    const HttpRequest& request,
    const String& sParam,
    T& result) const
{
    // Determine parameter location
    Json jsonBody = (!request.body().empty()) ? JsonParse(request.body()) : Json();
    Bool bParamInQuery = request.query().has(sParam);
    Bool bParamInBody = (jsonBody.find(sParam) != jsonBody.end());

    // Optional parameter
    if (bParamInQuery)
    {
        result = BoostLexicalCast<T>(request.query().get(sParam).get());
        return true;
    }
    else if (bParamInBody)
    {
        result = jsonBody[sParam].get<T>();
        return true;
    }
    return false;
}

template <class T>
Bool CustomHttpHandler::GetRequiredParameter(
    const HttpRequest& request,
    HttpResponseWriter& response,
    const String& sParam,
    T& result)
{
    // Determine parameter location
    Json jsonBody = (!request.body().empty()) ? JsonParse(request.body()) : Json();
    Bool bParamInQuery = request.query().has(sParam);
    Bool bParamInBody = (jsonBody.find(sParam) != jsonBody.end());

    // Required parameter
    if (bParamInQuery)
    {
        result = BoostLexicalCast<T>(request.query().get(sParam).get());
        return true;
    }
    else if (bParamInBody)
    {
        result = jsonBody[sParam].get<T>();
        return true;
    }

    // Missing parameter so it must be a bad request
    String sMessage = (BoostFormatString("Missing required parameter '%1%'.") % sParam).str();
    HandleResponse(HttpCodeBadRequest, response, sMessage, "text/plain");
    return false;
}

RestServer::RestServer()
    : Singleton<RestServer>()
{
}

void RestServer::Reset()
{
    LOG_STATEMENT("Resetting server");
    ASSERT_ERROR(!GetHostname().empty(), "Host cannot be empty");
    ASSERT_ERROR(GetPort() > 0, "Port must be a positive integer");
    ASSERT_ERROR(GetThreadCount() > 0, "Thread count must be a positive integer");
    SetEndpoint(STDMakeSharedPtr<HttpEndpoint>(HttpAddress(GetHostname(), GetPort())));
    if (GetEndpoint())
    {
        auto options = HttpEndpoint::options()
            .threads(GetThreadCount())
            .maxPayload(16384)
            .flags(TcpOptionReuseAddr);
        GetEndpoint()->init(options);
    }
}

void RestServer::Start()
{
    // Check that endpoint exists
    if (!GetEndpoint())
    {
        return;
    }

    // Setting up server
    LOG_STATEMENT("Setting up server");

    // Set handlers
    auto pHandler = HttpMakeHandler<CustomHttpHandler>(GetWebRoot());
    GetEndpoint()->setHandler(pHandler);

    // Start listening
    LOG_FORMAT_STATEMENT("Now serving at http://%s:%d\n", GetHostname().c_str(), GetPort());

    // Start the server accept loop
    GetEndpoint()->serveThreaded();
}

void RestServer::Stop()
{
    // Check that endpoint exists
    if (!GetEndpoint())
    {
        return;
    }

    // Halt server
    GetEndpoint()->shutdown();
    LOG_STATEMENT("Halting server...");
}

};
