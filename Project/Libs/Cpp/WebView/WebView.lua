-- Configuration
libWebView_extradir = "Libs/Cpp/WebView/extra/"
libWebView_origdir = "Libs/Cpp/WebView/orig/"
libWebView_srcdir = libWebView_origdir
libWebView_incdir = libWebView_origdir

-- Includes
libWebView_includedirs = {
    libWebView_incdir
}
if os.host() == "windows" then
    table.insert(libWebView_includedirs, libWebView_extradir .. "webview2/build/native/include")
end

-- Defines
libWebView_defines = {
    "WEBVIEW_STATIC"
}
libWebView_debugdefines = {
}
libWebView_releasedefines = {
}

-- Libs
libWebView_libs = {
}

-- Options
libWebView_buildoptions = {
}
libWebView_linkoptions = {
}
if os.host() == "linux" then
    table.insert(libWebView_buildoptions, "`pkg-config --cflags webkit2gtk-4.1`")
    table.insert(libWebView_buildoptions, "`pkg-config --cflags javascriptcoregtk-4.1`")
end

-- Sources
libWebView_sources = {
    libWebView_srcdir .. "webview.cc",
    libWebView_srcdir .. "webview.h"
}
