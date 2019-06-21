// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_SERVER_HTTP_HANDLER_H_
#define _GECKO_WEB_SERVER_HTTP_HANDLER_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Enum.h"
#include "Utility/Http.h"
#include "Utility/Singleton.h"

namespace Gecko
{

// Web server http handler
class WebServerHttpHandler : public HttpHandler
{
    HTTP_PROTOTYPE(WebServerHttpHandler)

public:

    // Constructor
    WebServerHttpHandler(const String& sWebRoot);

    // Request handler
    void onRequest(const HttpRequest& request, HttpResponseWriter response) override;

private:

    // Web root
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(WebRoot, String);

    // Callbacks
    void DoOptions_RequestToRun(const HttpRequest& request, HttpResponseWriter& response);
    void DoPost_RunModuleFile(const HttpRequest& request, HttpResponseWriter& response);
    void DoPost_RunModuleFileResults(const HttpRequest& request, HttpResponseWriter& response);
    void DoPost_RunModuleCommand(const HttpRequest& request, HttpResponseWriter& response);
    void DoPost_RunModuleCommandResults(const HttpRequest& request, HttpResponseWriter& response);
    void DoPost_SetCurrentModuleResultID(const HttpRequest& request, HttpResponseWriter& response);
    void DoPost_ClearModuleResult(const HttpRequest& request, HttpResponseWriter& response);
    void DoPost_ClearAllModuleResults(const HttpRequest& request, HttpResponseWriter& response);
    void DoGet_DoesModuleResultExist(const HttpRequest& request, HttpResponseWriter& response);
    void DoGet_GetModuleResultSize(const HttpRequest& request, HttpResponseWriter& response);
    void DoGet_GetModuleResults(const HttpRequest& request, HttpResponseWriter& response);

    // Special handlers
    void DoRequest_ServeTool(const HttpRequest& request, HttpResponseWriter& response);
    void DoRequest_ServeFile(const HttpRequest& request, HttpResponseWriter& response);

    // Handle response
    void HandleResponse(const HttpCode& code, HttpResponseWriter& response, const String& sResponse, const String& sMimeType);

    // Send results back to the user
    Bool SendResultsToUser(HttpResponseWriter& response, const String& sResultsID, Bool bKeepResults);
    Bool SendFileToUser(HttpResponseWriter& response, const String& sFile);

    // Get optional parameter
    template <class T>
    Bool GetOptionalParameter(
        const HttpRequest& request,
        const String& sParam,
        T& result) const;

    // Get required parameter
    template <class T>
    Bool GetRequiredParameter(
        const HttpRequest& request,
        HttpResponseWriter& response,
        const String& sParam,
        T& result);
};

};

#endif
