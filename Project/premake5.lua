-- Imports
require "Fyleria/Fyleria"
require "Libs/BackwardCPP/BackwardCPP"
require "Libs/BetterEnums/BetterEnums"
require "Libs/Boost/Boost"
require "Libs/Brotli/Brotli"
require "Libs/Cairo/Cairo"
require "Libs/Curl/Curl"
require "Libs/FantasyName/FantasyName"
require "Libs/FreeType2/FreeType2"
require "Libs/GCrypt/GCrypt"
require "Libs/GPGError/GPGError"
require "Libs/Harbuzz/Harbuzz"
require "Libs/Icu/Icu"
require "Libs/ImmutableString/ImmutableString"
require "Libs/JpegTurbo/JpegTurbo"
require "Libs/LibreSSL/LibreSSL"
require "Libs/LRUCache/LRUCache"
require "Libs/MicroPather/MicroPather"
require "Libs/ModernCPPJson/ModernCPPJson"
require "Libs/ObjectThreadsafe/ObjectThreadsafe"
require "Libs/OpenCFLite/OpenCFLite"
require "Libs/Pixman/Pixman"
require "Libs/PNG/PNG"
require "Libs/PSL/PSL"
require "Libs/PThreadsWin32"
require "Libs/SpdLog/SpdLog"
require "Libs/SQLite/SQLite"
require "Libs/WebKitGTK/WebKitGTK"
require "Libs/Webp/Webp"
require "Libs/XML2/XML2"
require "Libs/XSLT/XSLT"
require "Libs/Zlib/Zlib"
require "utility"

-- Create solution
workspace "all"
    startproject "Fyleria"
    cppdialect(GetCppDialect())
    location(GetBuildLocation())
    toolset(GetBuildToolset())
    configurations { "Debug32", "Release32", "Debug64", "Release64" }
filter "configurations:*32"
    architecture "x86"
filter "configurations:*64"
    architecture "x86_64"
filter "configurations:Debug*"
    symbols "On"
    targetsuffix(GetTargetDebugSuffix())
filter "configurations:Release*"
    optimize "Full"
    targetsuffix(GetTargetReleaseSuffix())

-- Fyleria
project "Fyleria"
language "C++"
pic "On"
    kind(GetAppType())
    buildoptions(appFyleria_buildoptions)
    linkoptions(appFyleria_linkoptions)
    includedirs(appFyleria_includedirs)
    includedirs(libBackwardCPP_includedirs)
    includedirs(libBoost_includedirs)
    includedirs(libFantasyName_includedirs)
    includedirs(libImmutableString_includedirs)
    includedirs(libBetterEnums_includedirs)
    includedirs(libLRUCache_includedirs)
    includedirs(libModernCPPJson_includedirs)
    includedirs(libObjectThreadsafe_includedirs)
    includedirs(libSpdLog_includedirs)
    includedirs(libZlib_includedirs)
    defines(appFyleria_defines)
    defines(libBackwardCPP_defines)
    defines(libBetterEnums_defines)
    defines(libBoost_defines)
    defines(libLRUCache_defines)
    files(appFyleria_sources)
    links(appFyleria_libs)
    links(libBackwardCPP_libs)
    targetdir(GetAppTargetDirectory())
    targetname(GetTargetName("FyleriaMain"))
filter "configurations:Debug*"
    defines(appFyleria_debugdefines)
filter "configurations:Release*"
    defines(appFyleria_releasedefines)

-- Boost
project "Boost"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    includedirs(libBoost_includedirs)
    defines(libBoost_defines)
    files(libBoost_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Boost"))
filter "configurations:Debug*"
    defines(libBoost_debugdefines)
filter "configurations:Release*"
    defines(libBoost_releasedefines)

-- Cairo
project "Cairo"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libCairo_buildoptions)
    linkoptions(libCairo_linkoptions)
    includedirs(libCairo_includedirs)
    includedirs(libFreeType2_includedirs)
    includedirs(libPixman_includedirs)
    defines(libCairo_defines)
    files(libCairo_sources)
    links(libCairo_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Cairo"))
filter "configurations:Debug*"
    defines(libCairo_debugdefines)
filter "configurations:Release*"
    defines(libCairo_releasedefines)

-- FantasyName
project "FantasyName"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    includedirs(libFantasyName_includedirs)
    defines(libFantasyName_defines)
    files(libFantasyName_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("FantasyName"))
filter "configurations:Debug*"
    defines(libFantasyName_debugdefines)
filter "configurations:Release*"
    defines(libFantasyName_releasedefines)

-- FreeType2
project "FreeType2"
language "C"
pic "On"
    kind(GetStaticLibraryType())
    buildoptions(libFreeType2_buildoptions)
    linkoptions(libFreeType2_linkoptions)
    includedirs(libFreeType2_includedirs)
    defines(libFreeType2_defines)
    files(libFreeType2_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("FreeType2"))
filter "configurations:Debug*"
    defines(libFreeType2_debugdefines)
filter "configurations:Release*"
    defines(libFreeType2_releasedefines)

-- MicroPather
project "MicroPather"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    includedirs(libMicroPather_includedirs)
    defines(libMicroPather_defines)
    files(libMicroPather_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("MicroPather"))
filter "configurations:Debug*"
    defines(libMicroPather_debugdefines)
filter "configurations:Release*"
    defines(libMicroPather_releasedefines)

-- Pixman
project "Pixman"
language "C"
pic "On"
    kind(GetStaticLibraryType())
    buildoptions(libPixman_buildoptions)
    linkoptions(libPixman_linkoptions)
    includedirs(libPixman_includedirs)
    defines(libPixman_defines)
    files(libPixman_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Pixman"))
filter "configurations:Debug*"
    defines(libPixman_debugdefines)
filter "configurations:Release*"
    defines(libPixman_releasedefines)

-- PNG
project "PNG"
language "C"
pic "On"
    kind(GetStaticLibraryType())
    buildoptions(libPNG_buildoptions)
    linkoptions(libPNG_linkoptions)
    includedirs(libPNG_includedirs)
    includedirs(libZlib_includedirs)
    defines(libPNG_defines)
    files(libPNG_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("PNG"))
filter "configurations:Debug*"
    defines(libPNG_debugdefines)
filter "configurations:Release*"
    defines(libPNG_releasedefines)

-- SpdLog
project "SpdLog"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    includedirs(libSpdLog_includedirs)
    defines(libSpdLog_defines)
    files(libSpdLog_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("SpdLog"))
filter "configurations:Debug*"
    defines(libSpdLog_debugdefines)
filter "configurations:Release*"
    defines(libSpdLog_releasedefines)

-- WebKitGTK
project "WebKitGTK"
language "C++"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libWebKitGTK_buildoptions_WebKitGTK)
    linkoptions(libWebKitGTK_linkoptions_WebKitGTK)
    includedirs(libWebKitGTK_includedirs_WebKitGTK)
    defines(libWebKitGTK_defines_WebKitGTK)
    files(libWebKitGTK_sources_WebKitGTK)
    links(libWebKitGTK_libs_WebKitGTK)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("WebKitGTK"))
filter "configurations:Debug*"
    defines(libWebKitGTK_debugdefines_WebKitGTK)
filter "configurations:Release*"
    defines(libWebKitGTK_releasedefines_WebKitGTK)

-- JavaScriptCoreGTK
project "JavaScriptCoreGTK"
language "C++"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libWebKitGTK_buildoptions_JavaScriptCoreGTK)
    linkoptions(libWebKitGTK_linkoptions_JavaScriptCoreGTK)
    includedirs(libWebKitGTK_includedirs_JavaScriptCoreGTK)
    defines(libWebKitGTK_defines_JavaScriptCoreGTK)
    files(libWebKitGTK_sources_JavaScriptCoreGTK)
    links(libWebKitGTK_libs_JavaScriptCoreGTK)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("JavaScriptCoreGTK"))
filter "configurations:Debug*"
    defines(libWebKitGTK_debugdefines_JavaScriptCoreGTK)
filter "configurations:Release*"
    defines(libWebKitGTK_releasedefines_JavaScriptCoreGTK)

-- Zlib
project "Zlib"
language "C"
pic "On"
    kind(GetStaticLibraryType())
    includedirs(libZlib_includedirs)
    defines(libZlib_defines)
    files(libZlib_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Zlib"))
filter "configurations:Debug*"
    defines(libZlib_debugdefines)
filter "configurations:Release*"
    defines(libZlib_releasedefines)
