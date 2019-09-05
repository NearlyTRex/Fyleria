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
if os.host() == "windows" then
    table.insert(appFyleria_defines, "NOMINMAX")
    table.insert(appFyleria_defines, "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING")
    table.insert(appFyleria_defines, "_SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING")
end

-- Options
appFyleria_buildoptions = {
}
appFyleria_linkoptions = {
}
if os.host() == "windows" then
    table.insert(appFyleria_buildoptions, "/bigobj")
elseif os.host() == "linux" then
    table.insert(appFyleria_buildoptions, "-Wall")
    table.insert(appFyleria_buildoptions, "-Wfatal-errors")
end

-- Libs
appFyleria_libs = {
    "Boost",
    "FantasyName",
    "MicroPather",
    "SpdLog"
}
if os.host() == "windows" then
    table.insert(appFyleria_libs, "windowsapp")
elseif os.host() == "linux" then
    table.insert(appFyleria_libs, "pthread")
    table.insert(appFyleria_libs, "gtk-3")
    table.insert(appFyleria_libs, "ffi")
    table.insert(appFyleria_libs, "pcre")
    table.insert(appFyleria_libs, "Cairo")
    table.insert(appFyleria_libs, "FreeType2")
    table.insert(appFyleria_libs, "Glib")
    table.insert(appFyleria_libs, "JpegTurbo")
    table.insert(appFyleria_libs, "Pixman")
    table.insert(appFyleria_libs, "PNG")
    table.insert(appFyleria_libs, "Soup")
    table.insert(appFyleria_libs, "XML2")
    table.insert(appFyleria_libs, "Zlib")
    table.insert(appFyleria_libs, "JavaScriptCoreGTK")
    table.insert(appFyleria_libs, "WebKitGTK")
end

-- Sources
appFyleria_sources = {
    appFyleria_srcdir .. "**.h",
    appFyleria_srcdir .. "**.cpp"
}
