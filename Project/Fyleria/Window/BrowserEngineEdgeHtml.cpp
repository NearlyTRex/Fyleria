// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Windows 10 only
#if defined(_WIN32) && _WIN32_WINNT >= 0x0A00

// Internal includes
#include "Window/BrowserEngineEdgeHtml.h"
#include "Config/ConfigManager.h"
#include "Utility/Filesystem.h"
#include "Utility/Constants.h"

namespace Gecko
{

BrowserEngineEdgeHtml::BrowserEngineEdgeHtml()
{
}

BrowserEngineEdgeHtml::~BrowserEngineEdgeHtml()
{
}

Bool BrowserEngineEdgeHtml::Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
    // Create message handler
    auto fnMessageHandler = +[](HWND pWindowHandle, UINT iMessage, WPARAM iWordParam, LPARAM iLongParam) -> Int
    {
        // Get engine instance
        auto* pEngine = static_cast<BrowserEngineWebKitGtk*>(GetWindowLongPtr(pWindowHandle, GWLP_USERDATA));
        if(!pEngine)
        {
            return -1;
        }

        // Handle window message
        switch(iMessage)
        {
            case WM_SIZE:
                RECT clientArea;
                if(GetClientRect(pEngine->GetMainWindow(), &clientArea))
                {
                    Rect bounds(
                        clientArea.left,
                        clientArea.top,
                        clientArea.right - clientArea.left,
                        clientArea.bottom - clientArea.top
                    );
                    pEngine->GetWebViewControl().Bounds(bounds);
                }
                break;
            case WM_CLOSE:
                DestroyWindow(pWindowHandle);
                break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProc(pWindowHandle, iMessage, iWordParam, iLongParam);
        }
        return 0;
    };

    // Create window class
    WNDCLASSEX windowClass;
    ZeroMemory(&windowClass, sizeof(WNDCLASSEX));
    const String& sWindowClassName = "webview";

    // Register window class
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.hInstance = GetModuleHandle(nullptr);
    windowClass.lpszClassName = sWindowClassName.c_str();
    windowClass.lpfnWndProc = (WNDPROC)(fnMessageHandler);
    if(!RegisterClassEx(&windowClass))
    {
        return false;
    }

    // Create main window
    SetMainWindow(CreateWindow(
        sWindowClassName.c_str(),
        sTitle.c_str(),
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
    SetWindowText(GetMainWindow(), sTitle.c_str());

    // Set sizing
    RECT sizeRect;
    sizeRect.left = 0;
    sizeRect.top = 0;
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

    // Show window
    ShowWindow(GetMainWindow(), SW_SHOW);
    UpdateWindow(GetMainWindow());
    SetFocus(GetMainWindow());

    // Initialize windows runtime to single thread
    winrt::init_apartment(winrt::apartment_type::single_threaded);

    // Create script notify handler
    auto fnScriptNotifyHandler = [this](const auto& sender, const auto& args)
    {
        // Call callback
        auto fnCallback = this->GetPostJavascriptCallback();
        if(fnCallback)
        {
            fnCallback(winrt::to_string(args.Value()));
        }
    };

    // Create navigation starting handler
    auto fnNavigationStartingHandler = [this](const auto& sender, const auto& args)
    {
        // Inject javascript
        this->GetWebViewControl().AddInitializeScript(winrt::to_hstring(this->GetInjectedJavascript()));
    };

    // Create navigation completed handler
    auto fnNavigationCompletedHandler = [this](const auto& sender, const auto& args)
    {
    };

    // Create content loading handler
    auto fnContentLoadingHandler = [this](const auto& sender, const auto& args)
    {
    };

    // Create DOM content loaded handler
    auto fnDOMContentLoadedHandler = [this](const auto& sender, const auto& args)
    {
    };

    // Create new window requested handler
    auto fnNewWindowRequestedHandler = [this](const auto& sender, const auto& args)
    {
        this->GetWebViewControl().Navigate(args.Uri());
    }

    // Create web view control completion handler
    auto fnCompletionHandler = [this](const auto& sender, const auto& args)
    {
        this->SetWebViewControl(sender.GetResults());
        this->GetWebViewControl().Settings().IsScriptNotifyAllowed(true);
        this->GetWebViewControl().Settings().IsJavaScriptEnabled(true);
        this->GetWebViewControl().IsVisible(true);
        this->GetWebViewControl().ScriptNotify(fnScriptNotifyHandler);
        this->GetWebViewControl().NavigationStarting(fnNavigationStartingHandler);
        this->GetWebViewControl().NavigationCompleted(fnNavigationCompletedHandler);
        this->GetWebViewControl().ContentLoading(fnContentLoadingHandler);
        this->GetWebViewControl().DOMContentLoaded(fnDOMContentLoadedHandler);
		this->GetWebViewControl().NewWindowRequested(fnNewWindowRequestedHandler);
        this->InjectJavascript("(function(){window.external.invoke = s => window.external.notify(s)})();");
    };

    // Create web view control process
    SetWebViewControlProcess(winrt::Windows::Web::UI::Interop::WebViewControlProcess());

    // Create web view control
    GetWebViewControlProcess().CreateWebViewControlAsync(
        static_cast<int64_t>(GetMainWindow()),
        Rect()
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
    GetWebViewControl().Navigate(Uri(winrt::to_hstring(sUrl)));
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
    String sFileContents = GetFileContents(JoinPathsCanonical(FOLDER_DATA, sFile));
    InjectStylesheet(sFileContents);
}

void BrowserEngineEdgeHtml::InjectJavascript(const String& sScript)
{
    // Add to injectable javascript
    SetInjectedJavascript(GetInjectedJavascript() + sScript);
}

void BrowserEngineEdgeHtml::InjectJavascriptFile(const String& sFile)
{
    // Inject file contents
    String sFileContents = GetFileContents(JoinPathsCanonical(FOLDER_DATA, sFile));
    InjectJavascript(sFileContents);
}

void BrowserEngineEdgeHtml::RemoveAllInjectedData()
{
    // Clear injectable javascript
    GetInjectedJavascript().clear();
}

void BrowserEngineEdgeHtml::RunJavascript(const String& sScript)
{
}

void BrowserEngineEdgeHtml::SetHtmlContent(const String& sHtml)
{
    // Navigate to the given html string
    GetWebViewControl().NavigateToString(sHtml);
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

#endif
