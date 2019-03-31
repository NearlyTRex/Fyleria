-- Configuration
appFyleria_srcdir = "Fyleria/"

-- Includes
appFyleria_includedirs = {
    appFyleria_srcdir
}
if os.host() == "linux" then
    table.insert(appFyleria_includedirs, "/usr/include/qt5/")
    table.insert(appFyleria_includedirs, "/usr/include/x86_64-linux-gnu/qt5/")
end

-- Defines
appFyleria_defines = {
    "NO_DLL",
    "QT_NO_VERSION_TAGGING"
}
appFyleria_debugdefines = {
    "DEBUG"
}
appFyleria_releasedefines = {
    "NDEBUG"
}

-- Options
appFyleria_buildoptions = {
}
appFyleria_linkoptions = {
}
if os.host() == "linux" then
    table.insert(appFyleria_buildoptions, "-Wall")
    table.insert(appFyleria_buildoptions, "-Wfatal-errors")
end

-- Libs
appFyleria_libs = {
    "Assert",
    "BackwardCPP",
    "Boost",
    "FantasyName",
    "MicroPather",
    "PyBind",
    "Python3",
    "TinyXML2",
    "TMXParser",
    "Websocketpp",
    "Zlib"
}
if os.host() == "windows" or _OPTIONS["with-mingw32"] or _OPTIONS["with-mingw64"] then
    table.insert(appFyleria_libs, "wsock32")
    table.insert(appFyleria_libs, "ws2_32")
else
    table.insert(appFyleria_libs, "pthread")
    table.insert(appFyleria_libs, "util")
    table.insert(appFyleria_libs, "Qt5Gui")
    table.insert(appFyleria_libs, "Qt5WebKit")
    table.insert(appFyleria_libs, "Qt5Xml")
    table.insert(appFyleria_libs, "Qt5Widgets")
    table.insert(appFyleria_libs, "Qt5WebKitWidgets")
    table.insert(appFyleria_libs, "Qt5Core")
    table.insert(appFyleria_libs, "Qt5Network")
end

-- Sources
appFyleria_sources = {
    appFyleria_srcdir .. "**.cpp"
}
