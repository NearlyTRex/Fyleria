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
}
if os.host() == "linux" then
    table.insert(appFyleria_libs, "Boost")
    table.insert(appFyleria_libs, "FantasyName")
    table.insert(appFyleria_libs, "MicroPather")
    table.insert(appFyleria_libs, "SpdLog")
    table.insert(appFyleria_libs, "Glib")
    table.insert(appFyleria_libs, "Gtk")
    table.insert(appFyleria_libs, "JavaScriptCoreGTK")
    table.insert(appFyleria_libs, "WebKitGTK")
end

-- Sources
appFyleria_sources = {
    appFyleria_srcdir .. "**.h",
    appFyleria_srcdir .. "**.cpp"
}
