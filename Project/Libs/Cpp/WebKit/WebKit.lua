-- Configuration
libWebKit_extradir = "Libs/C++/WebKit/extra/"
libWebKit_origdir = "Libs/C++/WebKit/orig/"
libWebKit_srcdir = libWebKit_origdir
libWebKit_incdir = libWebKit_origdir

-- Include dirs
libWebKit_includedirs = {
}
if os.host() == "windows" then
    table.insert(libWebKit_includedirs, libWebKit_incdir .. "WebKitBuild/Release/ANGLE/Headers")
    table.insert(libWebKit_includedirs, libWebKit_incdir .. "WebKitBuild/Release/PAL/Headers")
    table.insert(libWebKit_includedirs, libWebKit_incdir .. "WebKitBuild/Release/WTF/Headers")
    table.insert(libWebKit_includedirs, libWebKit_incdir .. "WebKitBuild/Release/JavaScriptCore/Headers")
    table.insert(libWebKit_includedirs, libWebKit_incdir .. "WebKitBuild/Release/WebKitLegacy/Headers")
	table.insert(libWebKit_includedirs, libWebKit_incdir .. "WebKitBuild/Release/WebKit/Headers")
end

-- Lib dirs
libWebKit_libdirs = {
}
if os.host() == "windows" then
    table.insert(libWebKit_libdirs, libWebKit_origdir .. "WebKitBuild/Release/lib64")
end

-- Defines
libWebKit_defines = {
}
libWebKit_debugdefines = {
}
libWebKit_releasedefines = {
}

-- Build options
libWebKit_buildoptions = {
}

-- Link options
libWebKit_linkoptions = {
}

-- Libs
libWebKit_libs = {
}
if os.host() == "windows" then
    table.insert(libWebKit_libs, "ANGLE.lib")
    table.insert(libWebKit_libs, "PAL.lib")
    table.insert(libWebKit_libs, "WTF.lib")
    table.insert(libWebKit_libs, "JavaScriptCore.lib")
    table.insert(libWebKit_libs, "WebKit2.lib")
end

-- Sources
libWebKit_sources = {
}
