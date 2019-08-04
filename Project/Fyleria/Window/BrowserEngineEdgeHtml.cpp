// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngineEdgeHtml.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneTypes.h"
#include "Config/ConfigManager.h"
#include "Utility/Filesystem.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"

// EdgeHTML is available for Windows 10 only
#if defined(PLATFORM_OS_WINDOWS_10)

namespace Gecko
{

BrowserEngineEdgeHtml::BrowserEngineEdgeHtml()
{
}

BrowserEngineEdgeHtml::~BrowserEngineEdgeHtml()
{
}

LRESULT CALLBACK WndProcStatic(HWND pWindowHandle, UINT uMessage, WPARAM iWordParam, LPARAM iLongParam)
{
    // Get engine instance
    auto* pEngine = reinterpret_cast<BrowserEngineEdgeHtml*>(GetWindowLongPtr(pWindowHandle, GWLP_USERDATA));
    if(!pEngine)
    {
        return DefWindowProc(pWindowHandle, uMessage, iWordParam, iLongParam);
    }

    // Handle window message
    Bool bHandled = false;
    switch(uMessage)
    {
        case WM_CLOSE:
        {
            // Destroy window
            DestroyWindow(pWindowHandle);
            bHandled = true;
            break;
        }
        case WM_DESTROY:
        {
            // Stop program
            PostQuitMessage(0);
            bHandled = true;
            break;
        }
        default:
        {
            break;
        }
    }
    return (bHandled) ? 0 : DefWindowProc(pWindowHandle, uMessage, iWordParam, iLongParam);
}

Bool BrowserEngineEdgeHtml::Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
    // Initialize windows runtime to single thread
    winrt::init_apartment(winrt::apartment_type::single_threaded);

    // Create window class
    WNDCLASSEX windowClass;
    ZeroMemory(&windowClass, sizeof(WNDCLASSEX));
    const WString& sWindowClassName = L"webview";

    // Register window class
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.hInstance = GetModuleHandle(nullptr);
    windowClass.lpszClassName = sWindowClassName.c_str();
    windowClass.lpfnWndProc = WndProcStatic;
    if(!RegisterClassEx(&windowClass))
    {
        return false;
    }

    // Create main window
    SetMainWindow(CreateWindow(
        sWindowClassName.c_str(),
        ConvertStringToWideString(sTitle).c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        iWidth,
        iHeight,
        nullptr,
        nullptr,
        GetModuleHandle(nullptr),
        nullptr)
    );

    // Check if window was created
    if(!GetMainWindow())
    {
        return false;
    }

    // Store window pointer
    SetWindowLongPtr(GetMainWindow(), GWLP_USERDATA, (LONG_PTR)this);

    // Set title
    SetWindowText(GetMainWindow(), ConvertStringToWideString(sTitle).c_str());

    // Set sizing
    RECT sizeRect;
    sizeRect.left = 50;
    sizeRect.top = 50;
    sizeRect.right = iWidth;
    sizeRect.bottom = iHeight;
    AdjustWindowRect(&sizeRect, WS_OVERLAPPEDWINDOW, 0);

    // Set window position
    SetWindowPos(
        GetMainWindow(),
        nullptr,
        sizeRect.left,
        sizeRect.top,
        sizeRect.right - sizeRect.left,
        sizeRect.bottom - sizeRect.top,
        SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED
    );

    // Inject starting javascript / css
    InjectJavascript("(function(){window.external.invoke = s => window.external.notify(s)})();");
    InjectJavascriptFile(LIB_FILE_COMMON_JS);
    InjectStylesheetFile(LIB_FILE_BOOTSTRAP_CSS);
    InjectJavascriptFile(LIB_FILE_BOOTSTRAP_JS);
    InjectJavascriptFile(LIB_FILE_JQUERY_JS);
    InjectJavascriptFile(LIB_FILE_PHASER_JS);

    // Create web view control completion handler
    auto fnCompletionHandler = [this](
        const winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Web::UI::Interop::WebViewControl>& sender,
        winrt::Windows::Foundation::AsyncStatus args
    )
    {
        // Set web view control
        SetWebViewControl(sender.GetResults());

        // Update settings
        GetWebViewControl().Settings().IsScriptNotifyAllowed(true);
        GetWebViewControl().Settings().IsJavaScriptEnabled(true);
        GetWebViewControl().IsVisible(true);

        // Set script notify handler
        GetWebViewControl().ScriptNotify([this](
            const winrt::Windows::Web::UI::IWebViewControl& sender,
            winrt::Windows::Web::UI::IWebViewControlScriptNotifyEventArgs args)
            {
                // Call callback
                auto fnCallback = GetPostJavascriptCallback();
                if (fnCallback)
                {
                    fnCallback(winrt::to_string(args.Value()));
                }
            }
        );

        // Set navigation starting handler
        GetWebViewControl().NavigationStarting([this](
            const winrt::Windows::Web::UI::IWebViewControl& sender,
            winrt::Windows::Web::UI::IWebViewControlNavigationStartingEventArgs args)
            {
            }
        );

        // Set navigation completed handler
        GetWebViewControl().NavigationCompleted([this](
            const winrt::Windows::Web::UI::IWebViewControl& sender,
            winrt::Windows::Web::UI::IWebViewControlNavigationCompletedEventArgs args)
            {
            }
        );

        // Set content loading handler
        GetWebViewControl().ContentLoading([this](
            const winrt::Windows::Web::UI::IWebViewControl& sender,
            winrt::Windows::Web::UI::IWebViewControlContentLoadingEventArgs args)
            {
            }
        );

        // Set DOM content loaded handler
        GetWebViewControl().DOMContentLoaded([this](
            const winrt::Windows::Web::UI::IWebViewControl& sender,
            winrt::Windows::Web::UI::IWebViewControlDOMContentLoadedEventArgs args)
            {
            }
        );

        // Set new window requested handler
        GetWebViewControl().NewWindowRequested([this](
            const winrt::Windows::Web::UI::IWebViewControl& sender,
            winrt::Windows::Web::UI::IWebViewControlNewWindowRequestedEventArgs args)
            {
                // Navigate to the new URI
                GetWebViewControl().Navigate(args.Uri());
            }
        );

        // Show window
        ShowWindow(GetMainWindow(), SW_SHOW);
        UpdateWindow(GetMainWindow());
        SetFocus(GetMainWindow());

        // Navigate to starting page
        Navigate(STARTING_URI);

        // Switch to starting scene
        SceneManager::GetInstance()->SwitchToScene((+SceneType::Intro)._to_string());
    };

    // Create web view control process
    SetWebViewControlProcess(winrt::Windows::Web::UI::Interop::WebViewControlProcess());

    // Create web view control
    GetWebViewControlProcess().CreateWebViewControlAsync(
        (FixedSigned64)GetMainWindow(),
        winrt::Windows::Foundation::Rect()
    ).Completed(fnCompletionHandler);
    return true;
}

void BrowserEngineEdgeHtml::Shutdown()
{
    // Mark as shutting down
    SetIsShuttingDown(true);
}

void BrowserEngineEdgeHtml::Navigate(const String& sUrl)
{
    // Navigate to url
    GetWebViewControl().Navigate(winrt::Windows::Foundation::Uri::Uri(winrt::to_hstring(sUrl)));
}

void BrowserEngineEdgeHtml::InjectStylesheet(const String& sStyle)
{
    // Create injectable javascript
    String sScript;
    sScript += "(function(e){";
    sScript += "var t = document.createElement('style');";
    sScript += "var d = document.head || document.getElementsByTagName('head')[0];";
    sScript += "t.setAttribute('type','text/css');";
    sScript += "t.styleSheet ? t.styleSheet.cssText = e : t.appendChild(document.createTextNode(e));";
    sScript += "d.appendChild(t);";
    sScript += "})(\"" + sStyle + "\")";

    // Inject javascript
    InjectJavascript(sScript);
}

void BrowserEngineEdgeHtml::InjectStylesheetFile(const String& sFile)
{
    // Inject file contents
    String sFileContents = GetFileContents(JoinPathsCanonical(GetDataDirectory(), sFile));
    InjectStylesheet(sFileContents);
}

void BrowserEngineEdgeHtml::InjectJavascript(const String& sScript)
{
    // Add to injectable javascript
    String sJavascript = GetInjectedJavascript();
    SetInjectedJavascript(sJavascript + sScript);
}

void BrowserEngineEdgeHtml::InjectJavascriptFile(const String& sFile)
{
    // Inject file contents
    String sFileContents = GetFileContents(JoinPathsCanonical(GetDataDirectory(), sFile));
    InjectJavascript(sFileContents);
}

void BrowserEngineEdgeHtml::RemoveAllInjectedData()
{
    // Clear injectable javascript
    SetInjectedJavascript("");
}

void BrowserEngineEdgeHtml::RunJavascript(const String& sScript)
{
}

void BrowserEngineEdgeHtml::SetHtmlContent(const String& sHtml)
{
    // Navigate to the given html string
    GetWebViewControl().NavigateToString(winrt::to_hstring(sHtml));
}

void BrowserEngineEdgeHtml::SetHtmlContentFile(const String& sFile)
{
    // Set document html
    String sFileContents = GetFileContents(sFile);
    SetHtmlContent(sFileContents);
}

void BrowserEngineEdgeHtml::RunMainLoopIteration(Bool bBlocking)
{
    // Create message
    MSG message;
    ZeroMemory(&message, sizeof(MSG));

    // Fill message
    if(bBlocking)
    {
        GetMessage(&message, 0, 0, 0);
    }
    else
    {
        PeekMessage(&message, 0, 0, 0, PM_REMOVE);
    }

    // Check message contents
    switch(message.message)
    {
        case WM_QUIT:
            Shutdown();
            break;
        default:
            TranslateMessage(&message);
            DispatchMessage(&message);
            break;
    }
}

};

#endif /* PLATFORM_OS_WINDOWS_10 */
