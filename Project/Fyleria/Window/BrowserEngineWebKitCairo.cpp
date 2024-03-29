// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngineWebKitCairo.h"
#include "Scene/SceneTypes.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"
#include "Utility/ManagerSet.h"

// External includes
#include <WebKit/WKSerializedScriptValue.h>
#include <WebKit/WKPreferencesRef.h>
#include <WebKit/WKPreferencesRefPrivate.h>
#include <JavaScriptCore/JavaScript.h>

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

WKRetainPtr<WKStringRef> ConvertStringToWebKitString(const String& sStr)
{
    return adoptWK(WKStringCreateWithUTF8CString(sStr.data()));
}

WKRetainPtr<WKStringRef> ConvertStringToWebKitString(const WString& sStr)
{
    return ConvertStringToWebKitString(ConvertWideStringToString(sStr));
}

WKRetainPtr<WKURLRef> ConvertStringToWebKitURL(const String& sStr)
{
    return adoptWK(WKURLCreateWithUTF8CString(sStr.data()));
}

WKRetainPtr<WKURLRef> ConvertStringToWebKitURL(const WString& sStr)
{
    return ConvertStringToWebKitURL(ConvertWideStringToString(sStr));
}

String ConvertWebKitStringToString(WKStringRef sWkStr)
{
    String sResult;
    if (!sWkStr)
    {
        return sResult;
    }

    SizeType nBufferSize = WKStringGetMaximumUTF8CStringSize(sWkStr);
    auto pBuffer = makeUniqueWithoutFastMallocCheck<char[]>(nBufferSize);
    SizeType nStringLength = WKStringGetUTF8CString(sWkStr, pBuffer.get(), nBufferSize);
    sResult = String(pBuffer.get(), nStringLength - 1);
    return sResult;
}

String ConvertJavascriptStringToString(JSStringRef sJsStr)
{
    String sResult;
    if (!sJsStr)
    {
        return sResult;
    }

    SizeType nBufferSize = JSStringGetMaximumUTF8CStringSize(sJsStr);
    auto pBuffer = makeUniqueWithoutFastMallocCheck<char[]>(nBufferSize);
    SizeType nStringLength = JSStringGetUTF8CString(sJsStr, pBuffer.get(), nBufferSize);
    sResult = String(pBuffer.get(), nStringLength - 1);
    return sResult;
}

String GetWebKitExceptionString(WKErrorRef pException)
{
    String sResult;
    if (!pException)
    {
        return sResult;
    }

    WKStringRef pJsExceptionString = WKErrorCopyLocalizedDescription(pException);
    sResult = ConvertWebKitStringToString(pJsExceptionString);
    return sResult;
}

String GetJavascriptExceptionString(JSValueRef pException, JSGlobalContextRef pContext)
{
    String sResult;
    if (!pException || !pContext)
    {
        return sResult;
    }

    JSStringRef pJsExceptionString = JSValueToStringCopy(pContext, pException, nullptr);
    sResult = ConvertJavascriptStringToString(pJsExceptionString);
    JSStringRelease(pJsExceptionString);
    return sResult;
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

Bool BrowserEngineWebKitCairo::Init(SafeObject<ManagerSet>& pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
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
    WKPreferencesSetJavaScriptEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableJavaScript());
    WKPreferencesSetJavaScriptMarkupEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableJavaScriptMarkup());
    WKPreferencesSetLoadsImagesAutomatically(GetWebKitPreferences().get(), GetPreferences().GetEnableAutomaticImageLoading());
    WKPreferencesSetLoadsSiteIconsIgnoringImageLoadingPreference(GetWebKitPreferences().get(), GetPreferences().GetEnableSiteIcons());
    WKPreferencesSetOfflineWebApplicationCacheEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnablePageCache());
    WKPreferencesSetLocalStorageEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableLocalStorage());
    WKPreferencesSetDatabasesEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableDatabases());
    WKPreferencesSetXSSAuditorEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableXSSAuditing());
    WKPreferencesSetFrameFlatteningEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableFrameFlattening());
    WKPreferencesSetPluginsEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnablePlugins());
    WKPreferencesSetJavaEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableJava());
    WKPreferencesSetJavaScriptCanOpenWindowsAutomatically(GetWebKitPreferences().get(), GetPreferences().GetEnableJavaScriptWindowControl());
    WKPreferencesSetHyperlinkAuditingEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableHyperlinkAuditing());
    WKPreferencesSetPrivateBrowsingEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnablePrivateBrowsing());
    WKPreferencesSetDeveloperExtrasEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableDeveloperExtras());
    WKPreferencesSetTextAreasAreResizable(GetWebKitPreferences().get(), GetPreferences().GetEnableTextAreasResizing());
    WKPreferencesSetTabsToLinks(GetWebKitPreferences().get(), GetPreferences().GetEnableTabsToLinks());
    WKPreferencesSetDNSPrefetchingEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableDNSPrefetching());
    WKPreferencesSetAuthorAndUserStylesEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableAuthorAndUserStyles());
    WKPreferencesSetShouldPrintBackgrounds(GetWebKitPreferences().get(), GetPreferences().GetEnablePrintBackgrounds());
    WKPreferencesSetJavaScriptCanAccessClipboard(GetWebKitPreferences().get(), GetPreferences().GetEnableJavaScriptClipboardAccess());
    WKPreferencesSetFullScreenEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableFullScreen());
    WKPreferencesSetAVFoundationEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableAVFoundation());
    WKPreferencesSetWebAudioEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableWebAudio());
    WKPreferencesSetBackspaceKeyNavigationEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableBackspaceKeyNavigation());
    WKPreferencesSetCaretBrowsingEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableCaretBrowsing());
    WKPreferencesSetShouldDisplaySubtitles(GetWebKitPreferences().get(), GetPreferences().GetEnableSubtitleDisplay());
    WKPreferencesSetShouldDisplayCaptions(GetWebKitPreferences().get(), GetPreferences().GetEnableCaptionDisplay());
    WKPreferencesSetShouldDisplayTextDescriptions(GetWebKitPreferences().get(), GetPreferences().GetEnableTextDescriptionDisplay());
    WKPreferencesSetNotificationsEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableNotifications());
    WKPreferencesSetShouldRespectImageOrientation(GetWebKitPreferences().get(), GetPreferences().GetEnableRespectImageOrientation());
    WKPreferencesSetEncodingDetectorEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableEncodingDetector());
    WKPreferencesSetTextAutosizingEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableTextAutosizing());
    WKPreferencesSetQTKitEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableQTKit());
    WKPreferencesSetAsynchronousSpellCheckingEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableAsynchronousSpellChecking());
    WKPreferencesSetMediaStreamEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableMediaStream());
    WKPreferencesSetMediaDevicesEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableMediaDevices());
    WKPreferencesSetPeerConnectionEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnablePeerConnection());
    WKPreferencesSetSpatialNavigationEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableSpatialNavigation());
    WKPreferencesSetIgnoreViewportScalingConstraints(GetWebKitPreferences().get(), GetPreferences().GetEnableIgnoreViewportScalingConstraints());
    WKPreferencesSetAllowsAirPlayForMediaPlayback(GetWebKitPreferences().get(), GetPreferences().GetEnableAirPlay());
    WKPreferencesSetApplePayEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableApplePay());
    WKPreferencesSetMediaCapabilitiesEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableMediaCapabilities());
    WKPreferencesSetRestrictedHTTPResponseAccess(GetWebKitPreferences().get(), GetPreferences().GetEnableRestrictHTTPResponseAccess());
    WKPreferencesSetCrossOriginResourcePolicyEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableCrossOriginResourcePolicy());
    WKPreferencesSetCaptureAudioInUIProcessEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableCaptureAudioInUIProcess());
    WKPreferencesSetCaptureAudioInGPUProcessEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableCaptureAudioInGPUProcess());
    WKPreferencesSetCaptureVideoInUIProcessEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableCaptureVideoInUIProcess());
    WKPreferencesSetCaptureVideoInGPUProcessEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableCaptureVideoInGPUProcess());
    WKPreferencesSetRemotePlaybackEnabled(GetWebKitPreferences().get(), GetPreferences().GetEnableRemotePlayback());
    WKPreferencesSetShouldUseServiceWorkerShortTimeout(GetWebKitPreferences().get(), GetPreferences().GetEnableServiceWorkerShortTimeout());

    // Create webkit page configuration
    SetWebKitPageConfiguration(adoptWK(WKPageConfigurationCreate()));
    WKPageConfigurationSetPreferences(GetWebKitPageConfiguration().get(), GetWebKitPreferences().get());

    // Create webkit page group
    SetWebKitPageGroup(adoptWK(WKPageGroupCreateWithIdentifier(ConvertStringToWebKitString(sWindowClassName).get())));
    WKPageConfigurationSetPageGroup(GetWebKitPageConfiguration().get(), GetWebKitPageGroup().get());
    WKPageGroupSetPreferences(GetWebKitPageGroup().get(), GetWebKitPreferences().get());

    // Create webkit context
    SetWebKitContext(adoptWK(WKContextCreateWithConfiguration(nullptr)));
    WKPageConfigurationSetContext(GetWebKitPageConfiguration().get(), GetWebKitContext().get());

    // Create webkit view
    RECT viewRect;
    viewRect.left = 0;
    viewRect.top = 0;
    viewRect.right = iWidth;
    viewRect.bottom = iHeight;
    SetWebKitView(adoptWK(WKViewCreate(viewRect, GetWebKitPageConfiguration().get(), GetMainWindow())));
    WKViewSetIsInWindow(GetWebKitView().get(), true);

    // Setup page navigation client
    GetWebKitPageNavigationClient().base.version = 0;
    GetWebKitPageNavigationClient().base.clientInfo = this;
    WKPageSetPageNavigationClient(WKViewGetPage(GetWebKitView().get()), &GetWebKitPageNavigationClient().base);

    // Setup page ui client
    GetWebKitPageUIClient().base.version = 13;
    GetWebKitPageUIClient().base.clientInfo = this;
    WKPageSetPageUIClient(WKViewGetPage(GetWebKitView().get()), &GetWebKitPageUIClient().base);

    // Setup page state client
    GetWebKitPageStateClient().base.version = 0;
    GetWebKitPageStateClient().base.clientInfo = this;
    WKPageSetPageStateClient(WKViewGetPage(GetWebKitView().get()), &GetWebKitPageStateClient().base);

    // Show window
    ShowWindow(GetMainWindow(), SW_SHOW);
    UpdateWindow(GetMainWindow());
    SetFocus(GetMainWindow());

    // Navigate to starting page
    Navigate(STARTING_URI);

    // Switch to starting scene
    pManagerSet->GetSceneManager()->SwitchToScene(pManagerSet, STARTING_SCENE);
    return true;
}

void BrowserEngineWebKitCairo::Navigate(const String& sUrl)
{
    // Navigate to the url
    WKPageLoadURL(WKViewGetPage(GetWebKitView().get()), WKURLCreateWithUTF8CString(sUrl.data()));
}

static void JavascriptFinishedHandler(WKSerializedScriptValueRef pResult, WKErrorRef pError, void* pUserData)
{
    // Check error
    if (pError)
    {
        ERROR_FORMAT_STATEMENT("Error running javascript: {}", GetWebKitExceptionString(pError));
        return;
    }

    // Get engine instance
    auto* pEngine = static_cast<BrowserEngineWebKitCairo*>(pUserData);
    if (!pEngine)
    {
        ERROR_STATEMENT("Error running javascript: Unable to retrieve browser engine");
        return;
    }

    // Call callback
    auto fnCallback = pEngine->GetRunResultJavascriptCallback();
    if (fnCallback->IsSet())
    {
        fnCallback->GetCallback()(pEngine->GetJavascriptResultString(pResult));
    }
}

void BrowserEngineWebKitCairo::RunJavascript(const String& sScript)
{
    // Run javascript
    if (GetRunResultJavascriptCallback()->IsSet())
    {
        WKPageRunJavaScriptInMainFrame(
            WKViewGetPage(GetWebKitView().get()),
            ConvertStringToWebKitString(sScript).get(),
            this,
            JavascriptFinishedHandler);
    }
    else
    {
        WKPageRunJavaScriptInMainFrame(
            WKViewGetPage(GetWebKitView().get()),
            ConvertStringToWebKitString(sScript).get(),
            nullptr,
            nullptr);
    }
}

void BrowserEngineWebKitCairo::LoadHtmlContent(const String& sHtml)
{
    // Load html
    WKPageLoadHTMLString(
        WKViewGetPage(GetWebKitView().get()),
        ConvertStringToWebKitString(CreateLoadableHtmlPage(sHtml)).get(),
        ConvertStringToWebKitURL(FILE_URI_BASE).get());
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

String BrowserEngineWebKitCairo::GetJavascriptResultString(WKSerializedScriptValueRef pResult)
{
    // Context wrapper
    class JavaScriptGlobalContext
    {
    public:
        JavaScriptGlobalContext() { m_pContext = JSGlobalContextCreate(nullptr); }
        ~JavaScriptGlobalContext() { JSGlobalContextRelease(m_pContext); }
        JSGlobalContextRef get() { return m_pContext; }
    private:
        JSGlobalContextRef m_pContext;
    };

    // Output string
    String sResult;

    // Ensure a valid result first
    if (!pResult)
    {
        ERROR_STATEMENT("Error running javascript: Result was invalid");
        return sResult;
    }

    // Create script context
    JavaScriptGlobalContext jsContext;
    if (!jsContext.get())
    {
        ERROR_STATEMENT("Error running javascript: Unable to create context");
        return sResult;
    }

    // Get deserialized value
    JSValueRef pJsException = nullptr;
    JSValueRef pDeserializedValue = WKSerializedScriptValueDeserialize(pResult, jsContext.get(), &pJsException);
    if (!pDeserializedValue)
    {
        ERROR_FORMAT_STATEMENT("Error running javascript: {}", GetJavascriptExceptionString(pJsException, jsContext.get()));
        return sResult;
    }

    // Get result string
    pJsException = nullptr;
    JSStringRef pJsResultString = JSValueToStringCopy(jsContext.get(), pDeserializedValue, &pJsException);
    if (pJsResultString)
    {
        sResult = ConvertJavascriptStringToString(pJsResultString);
        JSStringRelease(pJsResultString);
    }
    else
    {
        ERROR_FORMAT_STATEMENT("Error running javascript: {}", GetJavascriptExceptionString(pJsException, jsContext.get()));
    }
    return sResult;
}

void BrowserEngineWebKitCairo::OnMessageReceived(WKSerializedScriptValueRef sMessage)
{

}

};

#endif /* PLATFORM_OS_WINDOWS */
