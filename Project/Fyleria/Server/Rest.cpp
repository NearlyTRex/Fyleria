// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Server/Rest.h"
#include "Interface/Interface.h"
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
        if (request.resource() == "/api/does_module_result_exist")
        {
            DoGet_DoesModuleResultExist(request, response);
        }
        else if (request.resource() == "/api/get_module_result_size")
        {
            DoGet_GetModuleResultSize(request, response);
        }
        else if (request.resource() == "/api/get_module_results")
        {
            DoGet_GetModuleResults(request, response);
        }
        else
        {
            DoGet_ServeFile(request, response);
        }
    }
    else if (request.method() == HttpMethodPost)
    {
        if (request.resource() == "/api/run_module_file")
        {
            DoPost_RunModuleFile(request, response);
        }
        else if (request.resource() == "/api/run_module_file_results")
        {
            DoPost_RunModuleFileResults(request, response);
        }
        else if (request.resource() == "/api/run_module_command")
        {
            DoPost_RunModuleCommand(request, response);
        }
        else if (request.resource() == "/api/run_module_command_results")
        {
            DoPost_RunModuleCommandResults(request, response);
        }
        else if (request.resource() == "/api/clear_module_results")
        {
            DoPost_ClearModuleResult(request, response);
        }
        else if (request.resource() == "/api/clear_all_module_results")
        {
            DoPost_ClearAllModuleResults(request, response);
        }
        else
        {
            String sMessage = (BoostFormatString("Unknown POST resource '%1%'.") % request.resource()).str();
            HandleResponse(HttpCodeMethodNotAllowed, response, sMessage);
        }
    }
    else if (request.method() == HttpMethodOptions)
    {
        DoOptions_RequestToRun(request, response);
    }
    else
    {
        String sMessage = (BoostFormatString("Unhandled method '%1%'.") % methodString(request.method())).str();
        HandleResponse(HttpCodeMethodNotAllowed, response, sMessage);
    }
}

void CustomHttpHandler::DoOptions_RequestToRun(const HttpRequest& request, HttpResponseWriter& response)
{
    HandleResponse(HttpCodeOk, response, "");
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
        HandleResponse(HttpCodeConflict, response, sMessage);
        return;
    }

    // Send results
    Json return_json;
    return_json["return_value"] = return_value;
    HandleResponse(HttpCodeOk, response, return_json.dump());
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
    LOG_STATEMENT("Calling DLL_RunModuleFileResults");
    bool return_value = DLL_RunModuleFileResults(sInputFile.c_str(), sInputResultsId.c_str());
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Could not run file '%1%'.") % sInputFile).str();
        HandleResponse(HttpCodeConflict, response, sMessage);
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
        HandleResponse(HttpCodeConflict, response, sMessage);
        return;
    }

    // Send results
    Json return_json;
    return_json["return_value"] = return_value;
    HandleResponse(HttpCodeOk, response, return_json.dump());
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
    LOG_STATEMENT("Calling DLL_RunModuleCommandResults");
    bool return_value = DLL_RunModuleCommandResults(sInputCommand.c_str(), sInputResultsId.c_str());
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Could not run command '%1%'.") % sInputCommand).str();
        HandleResponse(HttpCodeConflict, response, sMessage);
        return;
    }

    // Send results
    SendResultsToUser(response, sInputResultsId, bKeepResults);
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
    HandleResponse(HttpCodeOk, response, return_json.dump());
}

void CustomHttpHandler::DoPost_ClearAllModuleResults(const HttpRequest& request, HttpResponseWriter& response)
{
    // Run method
    LOG_STATEMENT("Calling DLL_ClearAllModuleResults");
    DLL_ClearAllModuleResults();

    // Send results
    Json return_json;
    return_json["return_value"] = true;
    HandleResponse(HttpCodeOk, response, return_json.dump());
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
    HandleResponse(HttpCodeOk, response, return_json.dump());
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
    HandleResponse(HttpCodeOk, response, return_json.dump());
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

void CustomHttpHandler::DoGet_ServeFile(const HttpRequest& request, HttpResponseWriter& response)
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
    HandleResponse(HttpCodeNotFound, response, sMessage);
    return;
}

void CustomHttpHandler::HandleResponse(const HttpCode& code, HttpResponseWriter& response, const String& sResponse)
{
    // Send response
    response.headers()
        .add<HttpHeaderAccessControlAllowOrigin>("*")
        .add<HttpHeaderAccessControlAllowMethods>("GET, POST, OPTIONS")
        .add<HttpHeaderAccessControlAllowHeaders>("Content-Type")
        .add<HttpHeaderContentType>(MIME(Text, Plain));
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
        HandleResponse(HttpCodeConflict, response, sMessage);
        return false;
    }

    // Get result
    LOG_STATEMENT("Calling DLL_GetModuleResults");
    bool return_value = DLL_GetModuleResults(sResultsID.c_str(), sResultsStr, uResultsLen);
    if (!return_value)
    {
        String sMessage = (BoostFormatString("Failed retrieving result for '%1%'.") % sResultsID).str();
        HandleResponse(HttpCodeConflict, response, sMessage);
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
    HandleResponse(HttpCodeOk, response, sResults);
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
void CustomHttpHandler::GetOptionalParameter(const HttpRequest& request, const String& sParam, T& result) const
{
    // Determine parameter location
    Json jsonBody = (!request.body().empty()) ? JsonParse(request.body()) : Json();
    Bool bParamInQuery = request.query().has(sParam);
    Bool bParamInBody = (jsonBody.find(sParam) != jsonBody.end());

    // Optional parameter
    if (bParamInQuery)
    {
        result = BoostLexicalCast<T>(request.query().get(sParam).get());
    }
    else if (bParamInBody)
    {
        result = jsonBody[sParam].get<T>();
    }
}

template <class T>
Bool CustomHttpHandler::GetRequiredParameter(const HttpRequest& request, HttpResponseWriter& response, const String& sParam, T& result)
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
    LOG_FORMAT_STATEMENT("%s\n", sMessage.c_str());
    HandleResponse(HttpCodeBadRequest, response, sMessage);
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
    SetShutdown(false);
    SetClosing(false);
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
    SetShutdown(true);
    SetClosing(false);
}

};
