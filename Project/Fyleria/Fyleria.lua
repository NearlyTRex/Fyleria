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
    table.insert(appFyleria_libs, "JavaScriptCoreGTK")
    table.insert(appFyleria_libs, "WebKitGTK")
    table.insert(appFyleria_libs, "WTFGTK")
    table.insert(appFyleria_libs, "WebCoreGTK")
    table.insert(appFyleria_libs, "WTFGTK")
    table.insert(appFyleria_libs, "Boost")
    table.insert(appFyleria_libs, "Cairo")
    table.insert(appFyleria_libs, "FantasyName")
    table.insert(appFyleria_libs, "Fontconfig")
    table.insert(appFyleria_libs, "FreeType2")
    table.insert(appFyleria_libs, "GCrypt")
    table.insert(appFyleria_libs, "Glib")
    table.insert(appFyleria_libs, "Harfbuzz")
    table.insert(appFyleria_libs, "Icu")
    table.insert(appFyleria_libs, "JpegTurbo")
    table.insert(appFyleria_libs, "MicroPather")
    table.insert(appFyleria_libs, "PCRE")
    table.insert(appFyleria_libs, "Pixman")
    table.insert(appFyleria_libs, "PNG")
    table.insert(appFyleria_libs, "Soup")
    table.insert(appFyleria_libs, "PSL")
    table.insert(appFyleria_libs, "Glib")
    table.insert(appFyleria_libs, "PCRE")
    table.insert(appFyleria_libs, "SpdLog")
    table.insert(appFyleria_libs, "SQLite")
    table.insert(appFyleria_libs, "Webp")
    table.insert(appFyleria_libs, "XML2")
    table.insert(appFyleria_libs, "XSLT")
    table.insert(appFyleria_libs, "Zlib")
    table.insert(appFyleria_libs, "dw")
    table.insert(appFyleria_libs, "dl")
    table.insert(appFyleria_libs, "rt")
    table.insert(appFyleria_libs, "mount")
    table.insert(appFyleria_libs, "selinux")
    table.insert(appFyleria_libs, "uuid")
    table.insert(appFyleria_libs, "resolv")
    table.insert(appFyleria_libs, "lzma")
    table.insert(appFyleria_libs, "atk-1.0")
    table.insert(appFyleria_libs, "gtk-3")
    table.insert(appFyleria_libs, "gdk-3")
    table.insert(appFyleria_libs, "gdk_pixbuf-2.0")
    table.insert(appFyleria_libs, "gpg-error")
    table.insert(appFyleria_libs, "pthread")
    table.insert(appFyleria_libs, "pango-1.0")
    table.insert(appFyleria_libs, "GL")
    table.insert(appFyleria_libs, "GLU")
    table.insert(appFyleria_libs, "EGL")
    table.insert(appFyleria_libs, "X11")
    table.insert(appFyleria_libs, "Xcomposite")
    table.insert(appFyleria_libs, "Xdamage")
    table.insert(appFyleria_libs, "Xext")
    table.insert(appFyleria_libs, "Xrender")
end

-- Sources
appFyleria_sources = {
    appFyleria_srcdir .. "**.h",
    appFyleria_srcdir .. "**.cpp"
}
