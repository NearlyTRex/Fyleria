// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngineWebKitCairo.h"
#include "Scene/SceneTypes.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"
#include "Utility/ManagerSet.h"

// Windows only
#if defined(PLATFORM_OS_WINDOWS)

namespace Gecko
{

BrowserEngineWebKitCairo::BrowserEngineWebKitCairo()
{
}

BrowserEngineWebKitCairo::~BrowserEngineWebKitCairo()
{
}

WKRetainPtr<WKStringRef> CreateWebKitString(const String& str)
{
    return adoptWK(WKStringCreateWithUTF8CString(str.data()));
}

LRESULT CALLBACK WndProcStatic(HWND pWindowHandle, UINT uMessage, WPARAM iWordParam, LPARAM iLongParam)
{
    // Handle window message
    Bool bHandled = false;
    switch (uMessage)
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

Bool BrowserEngineWebKitCairo::Init(ManagerSet* pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
    // Store manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);
    SetManagers(pManagerSet);
 
    // Create window class
    WNDCLASSEX windowClass;
    ZeroMemory(&windowClass, sizeof(WNDCLASSEX));
    const WString& sWindowClassName = L"WebKitCairo";

    // Register window class
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.hCursor = LoadCursor(0, IDC_ARROW);
    windowClass.hInstance = GetModuleHandle(nullptr);
    windowClass.lpszClassName = sWindowClassName.c_str();
    windowClass.lpfnWndProc = WndProcStatic;
    if (!RegisterClassEx(&windowClass))
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
    if (!GetMainWindow())
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

    // Create webkit preferences
    SetWebKitPreferences(adoptWK(WKPreferencesCreate()));
    WKPreferencesSetMediaCapabilitiesEnabled(GetWebKitPreferences().get(), false);
    WKPreferencesSetDeveloperExtrasEnabled(GetWebKitPreferences().get(), true);

    // Create webkit page configuration
    SetWebKitPageConfiguration(adoptWK(WKPageConfigurationCreate()));
    WKPageConfigurationSetPreferences(GetWebKitPageConfiguration().get(), GetWebKitPreferences().get());

    // Create webkit page group
    SetWebKitPageGroup(adoptWK(WKPageGroupCreateWithIdentifier(CreateWebKitString("WebKitCairo").get())));
    WKPageConfigurationSetPageGroup(GetWebKitPageConfiguration().get(), GetWebKitPageGroup().get());
    WKPageGroupSetPreferences(GetWebKitPageGroup().get(), GetWebKitPreferences().get());
    
    // Create webkit context
    SetWebKitContext(adoptWK(WKContextCreateWithConfiguration(nullptr)));
    WKPageConfigurationSetContext(GetWebKitPageConfiguration().get(), GetWebKitContext().get());

    // Create webkit view
    RECT rect = {};
    SetWebKitView(adoptWK(WKViewCreate(rect, GetWebKitPageConfiguration().get(), GetMainWindow())));
    WKViewSetIsInWindow(GetWebKitView().get(), true);

    // Create webkit page
    SetWebKitPage(adoptWK(WKViewGetPage(GetWebKitView().get())));

    // Setup page navigation client
    GetWebKitPageNavigationClient().base.version = 0;
    GetWebKitPageNavigationClient().base.clientInfo = this;
    WKPageSetPageNavigationClient(GetWebKitPage().get(), &GetWebKitPageNavigationClient().base);

    // Setup page ui client
    GetWebKitPageUIClient().base.version = 13;
    GetWebKitPageUIClient().base.clientInfo = this;
    WKPageSetPageUIClient(GetWebKitPage().get(), &GetWebKitPageUIClient().base);

    // Setup page state client
    GetWebKitPageStateClient().base.version = 0;
    GetWebKitPageStateClient().base.clientInfo = this;
    WKPageSetPageStateClient(GetWebKitPage().get(), &GetWebKitPageStateClient().base);

    // Show window
    ShowWindow(GetMainWindow(), SW_SHOW);
    UpdateWindow(GetMainWindow());
    SetFocus(GetMainWindow());
    return true;
}

void BrowserEngineWebKitCairo::Shutdown()
{
    // Mark as shutting down
    SetIsShuttingDown(true);
}

void BrowserEngineWebKitCairo::Navigate(const String& sUrl)
{
}

void BrowserEngineWebKitCairo::InjectSystemJavascript(const String& sScript)
{
}

void BrowserEngineWebKitCairo::InjectUserStylesheet(const String& sStyle)
{
}

void BrowserEngineWebKitCairo::InjectUserStylesheetFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::InjectUserJavascript(const String& sScript)
{
}

void BrowserEngineWebKitCairo::InjectUserJavascriptFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::InjectUserHtml(const String& sHtml)
{
}

void BrowserEngineWebKitCairo::InjectUserHtmlFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::RemoveAllUserInjectedData()
{
}

void BrowserEngineWebKitCairo::RunJavascript(const String& sScript)
{
}

void BrowserEngineWebKitCairo::SetHtmlContent(const String& sHtml)
{
}

void BrowserEngineWebKitCairo::SetHtmlContentFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::RunMainLoopIteration(Bool bBlocking)
{
    // Create message
    MSG message;
    ZeroMemory(&message, sizeof(MSG));

    // Fill message
    if (bBlocking)
    {
        GetMessage(&message, 0, 0, 0);
    }
    else
    {
        PeekMessage(&message, 0, 0, 0, PM_REMOVE);
    }

    // Check message contents
    switch (message.message)
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

#endif /* PLATFORM_OS_WINDOWS */
