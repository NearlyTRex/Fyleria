// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngineWebKitGtk.h"
#include "Scene/SceneTypes.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

// Linux only
#if defined(PLATFORM_OS_LINUX)

namespace Gecko
{

BrowserEngineWebKitGtk::BrowserEngineWebKitGtk()
{
}

BrowserEngineWebKitGtk::~BrowserEngineWebKitGtk()
{
}

Bool BrowserEngineWebKitGtk::Init(SafeObject<ManagerSet>& pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
    // Initialize gtk
    if(!gtk_init_check(0, nullptr))
    {
        return false;
    }

    // Create top level window
    SetMainWindow(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    if(GetMainWindow() == nullptr)
    {
        return false;
    }

    // Create web view
    SetWebView(webkit_web_view_new());
    if(GetWebView() == nullptr)
    {
        return false;
    }

    // Get user content manager
    WebKitUserContentManager* pManager = webkit_web_view_get_user_content_manager(WEBKIT_WEB_VIEW(GetWebView()));
    if(pManager == nullptr)
    {
        return false;
    }

    // Create destroy handler
    auto fnDestroyHandler = +[](GtkWidget* pWidget, gpointer pArg)
    {
        // Get engine instance
        auto* pEngine = static_cast<BrowserEngineWebKitGtk*>(pArg);
        if(!pEngine)
        {
            return;
        }

        // Shutdown
        pEngine->Shutdown();
    };

    // Create message handler
    auto fnMessageHandler = +[](WebKitUserContentManager* pManager, WebKitJavascriptResult* pResult, gpointer pArg)
    {
        // Get engine instance
        auto* pEngine = static_cast<BrowserEngineWebKitGtk*>(pArg);
        if(!pEngine)
        {
            return;
        }

        // Call callback
        auto fnCallback = pEngine->GetPostJavascriptCallback();
        if(fnCallback)
        {
            fnCallback(pEngine->GetJavascriptResultString(pResult));
        }
    };

    // Register destroy handler
    g_signal_connect(G_OBJECT(GetMainWindow()), "destroy", G_CALLBACK(fnDestroyHandler), this);

    // Register message handler
    g_signal_connect(pManager, "script-message-received::external", G_CALLBACK(fnMessageHandler), this);
    webkit_user_content_manager_register_script_message_handler(pManager, "external");

    // Inject starting javascript / css
    InjectSystemJavascript("window.external={invoke:function(s){window.webkit.messageHandlers.external.postMessage(s);}}");

    // Add view
    gtk_container_add(GTK_CONTAINER(GetMainWindow()), GTK_WIDGET(GetWebView()));
    gtk_widget_grab_focus(GTK_WIDGET(GetWebView()));

    // Update settings
    WebKitSettings* pSettings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(GetWebView()));
    webkit_settings_set_auto_load_images(pSettings, true);
    webkit_settings_set_enable_frame_flattening(pSettings, true);
    webkit_settings_set_enable_html5_database(pSettings, true);
    webkit_settings_set_enable_html5_local_storage(pSettings, true);
    webkit_settings_set_enable_hyperlink_auditing(pSettings, false);
    webkit_settings_set_enable_java(pSettings, false);
    webkit_settings_set_enable_javascript(pSettings, true);
    webkit_settings_set_enable_javascript_markup(pSettings, true);
    webkit_settings_set_enable_offline_web_application_cache(pSettings, true);
    webkit_settings_set_enable_plugins(pSettings, false);
    webkit_settings_set_enable_xss_auditor(pSettings, false);
    webkit_settings_set_javascript_can_open_windows_automatically(pSettings, true);
    webkit_settings_set_load_icons_ignoring_image_load_setting(pSettings, false);
    webkit_settings_set_enable_developer_extras(pSettings, true);
    webkit_settings_set_enable_resizable_text_areas(pSettings, true);
    webkit_settings_set_enable_tabs_to_links(pSettings, false);
    webkit_settings_set_enable_fullscreen(pSettings, true);
    webkit_settings_set_enable_webaudio(pSettings, true);
    webkit_settings_set_enable_webgl(pSettings, true);
    webkit_settings_set_allow_modal_dialogs(pSettings, true);
    webkit_settings_set_javascript_can_access_clipboard(pSettings, true);
    webkit_settings_set_enable_page_cache(pSettings, true);
    webkit_settings_set_enable_smooth_scrolling(pSettings, true);
    webkit_settings_set_enable_accelerated_2d_canvas(pSettings, true);
    webkit_settings_set_enable_write_console_messages_to_stdout(pSettings, true);
    webkit_settings_set_enable_media_stream(pSettings, true);
    webkit_settings_set_enable_mock_capture_devices(pSettings, true);
    webkit_settings_set_enable_mediasource(pSettings, true);
    webkit_settings_set_enable_media_capabilities(pSettings, true);
    webkit_settings_set_allow_file_access_from_file_urls(pSettings, true);
    webkit_settings_set_allow_universal_access_from_file_urls(pSettings, true);
    webkit_settings_set_hardware_acceleration_policy(pSettings, WEBKIT_HARDWARE_ACCELERATION_POLICY_ON_DEMAND);
    webkit_settings_set_enable_back_forward_navigation_gestures(pSettings, true);

    // Set title
    gtk_window_set_title(GTK_WINDOW(GetMainWindow()), sTitle.c_str());

    // Set sizing
    gtk_window_set_resizable(GTK_WINDOW(GetMainWindow()), !!bResizable);
    if(bResizable)
    {
        gtk_window_set_default_size(GTK_WINDOW(GetMainWindow()), iWidth, iHeight);
    }
    else
    {
        gtk_widget_set_size_request(GetMainWindow(), iWidth, iHeight);
    }

    // Show window
    gtk_widget_show_all(GetMainWindow());

    // Navigate to starting page
    Navigate(STARTING_URI);

    // Switch to starting scene
    pManagerSet->GetSceneManager()->SwitchToScene(GetManagers(), (+SceneType::Intro)._to_string());
    return true;
}

void BrowserEngineWebKitGtk::Navigate(const String& sUrl)
{
    // Navigate to the url
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(GetWebView()), sUrl.c_str());
}

static void JavascriptFinishedHandler(GObject* pObject, GAsyncResult* pAsyncResult, gpointer pUserData)
{
    // Get finished javascript result
    GError* pError = nullptr;
    WebKitJavascriptResult* pResult = webkit_web_view_run_javascript_finish(
        WEBKIT_WEB_VIEW(pObject),
        pAsyncResult,
        &pError);
    if(!pResult)
    {
        ERROR_FORMAT_STATEMENT("Error running javascript: {}", pError->message);
        g_error_free(pError);
        return;
    }

    // Get engine instance
    auto* pEngine = static_cast<BrowserEngineWebKitGtk*>(pUserData);
    if(!pEngine)
    {
        return;
    }

    // Call callback
    auto fnCallback = pEngine->GetRunResultJavascriptCallback();
    if(fnCallback)
    {
        fnCallback(pEngine->GetJavascriptResultString(pResult));
    }

    // Dereference javascript result
    webkit_javascript_result_unref(pResult);
}

void BrowserEngineWebKitGtk::RunJavascript(const String& sScript)
{
    // Run javascript
    if(GetRunResultJavascriptCallback())
    {
        webkit_web_view_run_javascript(
            WEBKIT_WEB_VIEW(GetWebView()),
            sScript.c_str(),
            NULL,
            JavascriptFinishedHandler,
            this);
    }
    else
    {
        webkit_web_view_run_javascript(
            WEBKIT_WEB_VIEW(GetWebView()),
            sScript.c_str(),
            NULL,
            NULL,
            NULL);
    }
}

void BrowserEngineWebKitGtk::SetHtmlContent(const String& sHtml)
{
    // Set document html
    String sHtmlContent(sHtml);
    BoostReplaceAll(sHtmlContent, INJECTED_STYLES_TOKEN, GetUserStyles());
    BoostReplaceAll(sHtmlContent, INJECTED_SCRIPTS_TOKEN, GetSystemScripts() + GetUserScripts());
    BoostReplaceAll(sHtmlContent, INJECTED_MARKUP_TOKEN, GetUserMarkup());
    webkit_web_view_load_html(
        WEBKIT_WEB_VIEW(GetWebView()),
        sHtmlContent.c_str(),
        FILE_URI_BASE);
}

void BrowserEngineWebKitGtk::RunMainLoopIteration(Bool bBlocking)
{
    // Do one iteration
    gtk_main_iteration_do(bBlocking);
}

String BrowserEngineWebKitGtk::GetJavascriptResultString(WebKitJavascriptResult* pResult)
{
    // Output string
    String sResult;

    // Ensure a valid result first
    if(!pResult)
    {
        ERROR_STATEMENT("Error running javascript: Result was invalid");
        return sResult;
    }

    // Get js value
    JSCValue* pValue = webkit_javascript_result_get_js_value(pResult);

    // Check that it is a string first
    if(jsc_value_is_string(pValue))
    {
        // Get string value
        gchar* sJsString = jsc_value_to_string(pValue);

        // Check for js exception
        JSCException* pException = jsc_context_get_exception(jsc_value_get_context(pValue));
        if(pException)
        {
            ERROR_FORMAT_STATEMENT("Error running javascript: {}", jsc_exception_get_message(pException));
        }
        else
        {
            sResult = sJsString;
        }

        // Free string
        g_free(sJsString);
    }
    else
    {
        ERROR_STATEMENT("Error running javascript: Unexpected return value");
    }
    return sResult;
}

};

#endif /* PLATFORM_OS_LINUX */
