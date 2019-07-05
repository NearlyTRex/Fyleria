-- Configuration
appFyleria_srcdir = "Fyleria/"

-- Includes
appFyleria_includedirs = {
    appFyleria_srcdir
}

-- Defines
appFyleria_defines = {
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
    table.insert(appFyleria_buildoptions, "`pkg-config --cflags gtk+-3.0 webkit2gtk-4.0`")
    table.insert(appFyleria_linkoptions, "`pkg-config --libs gtk+-3.0 webkit2gtk-4.0`")
end

-- Libs
appFyleria_libs = {
    "Assert",
    "BackwardCPP",
    "Boost",
    "FantasyName",
    "MicroPather",
    "Python3",
    "TinyXML2",
    "TMXParser",
    "Zlib"
}

-- Sources
appFyleria_sources = {
    appFyleria_srcdir .. "**.cpp"
}
