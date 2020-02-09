// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BROWSER_ENGINE_PREFERENCES_H_
#define _GECKO_BROWSER_ENGINE_PREFERENCES_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Macros.h"

namespace Gecko
{

    // Browser engine preferences
    class BrowserEnginePreferences
    {
    public:

        // Constructor
        BrowserEnginePreferences();

        // Preferences
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableAVFoundation, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableAccelerated2DCanvas, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableAirPlayForMediaPlayback, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableApplePay, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableAsynchronousSpellChecking, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableAuthorAndUserStyles, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableAutomaticImageLoading, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableBackspaceKeyNavigation, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableCaptureAudioInGPUProcess, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableCaptureAudioInUIProcess, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableCaptureVideoInGPUProcess, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableCaptureVideoInUIProcess, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableCaretBrowsing, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableConsoleMessages, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableCrossOriginResourcePolicy, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableDNSPrefetching, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableDatabases, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableDeveloperExtras, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableEncodingDetector, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableFileAccessFromFileUrls, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableFrameFlattening, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableFullScreen, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableHyperlinkAuditing, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableJava, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableJavaScript, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableJavaScriptClipboardAccess, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableJavaScriptMarkup, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableJavaScriptWindowControl, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableLegacyEncryptedMediaAPI, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableLocalStorage, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableMediaCapabilities, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableMediaDevices, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableMediaStream, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableModalDialogs, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableNotifications, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnablePageCache, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnablePeerConnection, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnablePlugins, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnablePrivateBrowsing, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableProcessSwapOnNavigation, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableQTKit, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableRemotePlayback, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableSiteIcons, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableSmoothScrolling, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableSpatialNavigation, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableTabsToLinks, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableTextAreasResizing, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableTextAutosizing, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableUniversalAccessFromFileUrls, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableWebAudio, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableWebGL, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableWebSQL, Bool, true);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(EnableXSSAuditor, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(IgnoreViewportScalingConstraints, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(RestrictHTTPResponseAccess, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(ShouldDisplayCaptions, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(ShouldDisplaySubtitles, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(ShouldDisplayTextDescriptions, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(ShouldPrintBackgrounds, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(ShouldRespectImageOrientation, Bool, false);
        MAKE_PRIMITIVE_TYPE_ACCESSORS_INITIAL_VALUE_GET_ONLY(ShouldUseServiceWorkerShortTimeout, Bool, false);
    };
};

#endif
