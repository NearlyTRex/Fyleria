-- Imports
require "Libs/C/CJSMin/CJSMin"
require "Libs/C/Zlib/Zlib"
require "Libs/Cpp/Backward/Backward"
require "Libs/Cpp/BetterEnums/BetterEnums"
require "Libs/Cpp/Boost/Boost"
require "Libs/Cpp/Date/Date"
require "Libs/Cpp/FantasyName/FantasyName"
require "Libs/Cpp/ImmutableString/ImmutableString"
require "Libs/Cpp/Json/Json"
require "Libs/Cpp/LRUCache/LRUCache"
require "Libs/Cpp/MicroPather/MicroPather"
require "Libs/Cpp/ObjectThreadsafe/ObjectThreadsafe"
require "Libs/Cpp/SpdLog/SpdLog"
require "Libs/Cpp/WebView/WebView"

-- Configuration
libFyleria_srcdir = "Fyleria/"

-- Includes
libFyleria_includedirs = {
    libFyleria_srcdir
}
for k,v in pairs(libBackward_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libBoost_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libCJSMin_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libFantasyName_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libZlib_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libImmutableString_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libBetterEnums_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libLRUCache_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libJson_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libObjectThreadsafe_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libSpdLog_includedirs) do table.insert(libFyleria_includedirs, v) end
for k,v in pairs(libWebView_includedirs) do table.insert(libFyleria_includedirs, v) end

-- Defines
libFyleria_defines = {
}
libFyleria_debugdefines = {
    "DEBUG"
}
libFyleria_releasedefines = {
    "NDEBUG"
}
if os.host() == "windows" then
    table.insert(libFyleria_defines, "NOMINMAX")
    table.insert(libFyleria_defines, "_CRT_SECURE_NO_WARNINGS")
    table.insert(libFyleria_defines, "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING")
    table.insert(libFyleria_defines, "_SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING")
    table.insert(libFyleria_defines, "_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING")
end

-- Options
libFyleria_buildoptions = {
}
libFyleria_linkoptions = {
}
if os.host() == "windows" then
    table.insert(libFyleria_buildoptions, "/bigobj")
elseif os.host() == "linux" then
    table.insert(libFyleria_buildoptions, "-Wall")
    table.insert(libFyleria_buildoptions, "-Wfatal-errors")
    table.insert(libFyleria_buildoptions, "`pkg-config --cflags gtk+-3.0`")
    table.insert(libFyleria_buildoptions, "`pkg-config --cflags glib-2.0`")
    table.insert(libFyleria_buildoptions, "`pkg-config --cflags webkit2gtk-4.1`")
    table.insert(libFyleria_buildoptions, "`pkg-config --cflags javascriptcoregtk-4.1`")
end

-- Libs
libFyleria_libs = {
}
appFyleria_libs = {
    "FyleriaLib",
    "Boost",
    "CJSMin",
    "FantasyName",
    "MicroPather",
    "SpdLog",
    "Zlib"
}
if os.host() == "linux" then
    table.insert(appFyleria_libs, "atk-1.0")
    table.insert(appFyleria_libs, "cairo-gobject")
    table.insert(appFyleria_libs, "cairo")
    table.insert(appFyleria_libs, "dw")
    table.insert(appFyleria_libs, "gdk_pixbuf-2.0")
    table.insert(appFyleria_libs, "gdk-3")
    table.insert(appFyleria_libs, "gio-2.0")
    table.insert(appFyleria_libs, "glib-2.0")
    table.insert(appFyleria_libs, "gmodule-2.0")
    table.insert(appFyleria_libs, "gobject-2.0")
    table.insert(appFyleria_libs, "gtk-3")
    table.insert(appFyleria_libs, "harfbuzz")
    table.insert(appFyleria_libs, "javascriptcoregtk-4.1")
    table.insert(appFyleria_libs, "pango-1.0")
    table.insert(appFyleria_libs, "pangocairo-1.0")
    table.insert(appFyleria_libs, "pthread")
    table.insert(appFyleria_libs, "soup-3.0")
    table.insert(appFyleria_libs, "webkit2gtk-4.1")
end

-- Sources
libFyleria_sources = {
    libFyleria_srcdir .. "Application/**.cpp",
    libFyleria_srcdir .. "Battle/**.cpp",
    libFyleria_srcdir .. "Cache/**.cpp",
    libFyleria_srcdir .. "Character/**.cpp",
    libFyleria_srcdir .. "CharacterAction/**.cpp",
    libFyleria_srcdir .. "CharacterActionHandler/**.cpp",
    libFyleria_srcdir .. "CharacterData/**.cpp",
    libFyleria_srcdir .. "CharacterParty/**.cpp",
    libFyleria_srcdir .. "Config/**.cpp",
    libFyleria_srcdir .. "File/**.cpp",
    libFyleria_srcdir .. "Item/**.cpp",
    libFyleria_srcdir .. "Recipe/**.cpp",
    libFyleria_srcdir .. "Save/**.cpp",
    libFyleria_srcdir .. "Scene/**.cpp",
    libFyleria_srcdir .. "Simulator/**.cpp",
    libFyleria_srcdir .. "Skill/**.cpp",
    libFyleria_srcdir .. "Stat/**.cpp",
    libFyleria_srcdir .. "Utility/**.cpp",
    libFyleria_srcdir .. "Window/**.cpp"
}
appFyleria_sources = {
    libFyleria_srcdir .. "Main/main.cpp"
}
appFyleriaTest_sources = {
    libFyleria_srcdir .. "Test/**.cpp",
    libFyleria_srcdir .. "TestFixture/**.cpp",
    libFyleria_srcdir .. "TestSample/**.cpp",
    libFyleria_srcdir .. "Main/main-test.cpp"
}
