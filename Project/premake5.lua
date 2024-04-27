-- Imports
require "Fyleria/Fyleria"
require "utility"
require "options"

-- Create solution
workspace "all"
    startproject "FyleriaMain"
    location(GetBuildLocation())
    toolset(GetBuildToolset())
    architecture(GetArchitecture())
    configurations { "Debug32", "Release32", "Debug64", "Release64" }
filter "configurations:Debug*"
    symbols "On"
    targetsuffix(GetTargetDebugSuffix())
filter "configurations:Release*"
    optimize "Full"
    targetsuffix(GetTargetReleaseSuffix())

-- FyleriaMain
project "FyleriaMain"
language "C++"
pic "On"
    kind(GetAppType())
    runpathdirs(GetAppRunPaths())
    cppdialect(GetCpp17Dialect())
    buildoptions(libFyleria_buildoptions)
    includedirs(libFyleria_includedirs)
    defines(libFyleria_defines)
    defines(libBoost_defines)
    files(appFyleria_sources)
    links(appFyleria_libs)
    targetdir(GetAppTargetDirectory())
    targetname(GetTargetName("FyleriaMain"))
filter "configurations:Debug*"
    defines(libFyleria_debugdefines)
filter "configurations:Release*"
    defines(libFyleria_releasedefines)

-- FyleriaTest
project "FyleriaTest"
language "C++"
pic "On"
    kind(GetConsoleAppType())
    runpathdirs(GetAppRunPaths())
    cppdialect(GetCpp17Dialect())
    buildoptions(libFyleria_buildoptions)
    includedirs(libFyleria_includedirs)
    defines(libFyleria_defines)
    defines(libBoost_defines)
    files(appFyleriaTest_sources)
    links(appFyleria_libs)
    targetdir(GetAppTargetDirectory())
    targetname(GetTargetName("FyleriaTest"))
filter "configurations:Debug*"
    defines(libFyleria_debugdefines)
filter "configurations:Release*"
    defines(libFyleria_releasedefines)

-- FyleriaLib
project "FyleriaLib"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp17Dialect())
    buildoptions(libFyleria_buildoptions)
    includedirs(libFyleria_includedirs)
    defines(libFyleria_defines)
    defines(libBackward_defines)
    defines(libBetterEnums_defines)
    defines(libBoost_defines)
    defines(libLRUCache_defines)
    files(libFyleria_sources)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("FyleriaLib"))
filter "configurations:Debug*"
    defines(libFyleria_debugdefines)
filter "configurations:Release*"
    defines(libFyleria_releasedefines)

-- Boost
project "Boost"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp20Dialect())
    buildoptions(libBoost_buildoptions)
    includedirs(libBoost_includedirs)
    defines(libBoost_defines)
    files(libBoost_sources)
    links(libBoost_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Boost"))
filter "configurations:Debug*"
    defines(libBoost_debugdefines)
filter "configurations:Release*"
    defines(libBoost_releasedefines)

-- CJSMin
project "CJSMin"
language "C"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    buildoptions(libCJSMin_buildoptions)
    includedirs(libCJSMin_includedirs)
    defines(libCJSMin_defines)
    files(libCJSMin_sources)
    links(libCJSMin_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("CJSMin"))
filter "configurations:Debug*"
    defines(libCJSMin_debugdefines)
filter "configurations:Release*"
    defines(libCJSMin_releasedefines)

-- FantasyName
project "FantasyName"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp20Dialect())
    buildoptions(libFantasyName_buildoptions)
    includedirs(libFantasyName_includedirs)
    defines(libFantasyName_defines)
    files(libFantasyName_sources)
    links(libFantasyName_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("FantasyName"))
filter "configurations:Debug*"
    defines(libFantasyName_debugdefines)
filter "configurations:Release*"
    defines(libFantasyName_releasedefines)

-- MicroPather
project "MicroPather"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp20Dialect())
    buildoptions(libMicroPather_buildoptions)
    includedirs(libMicroPather_includedirs)
    defines(libMicroPather_defines)
    files(libMicroPather_sources)
    links(libMicroPather_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("MicroPather"))
filter "configurations:Debug*"
    defines(libMicroPather_debugdefines)
filter "configurations:Release*"
    defines(libMicroPather_releasedefines)

-- SpdLog
project "SpdLog"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp20Dialect())
    buildoptions(libSpdLog_buildoptions)
    includedirs(libSpdLog_includedirs)
    defines(libSpdLog_defines)
    files(libSpdLog_sources)
    links(libSpdLog_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("SpdLog"))
filter "configurations:Debug*"
    defines(libSpdLog_debugdefines)
filter "configurations:Release*"
    defines(libSpdLog_releasedefines)

-- WebView
project "WebView"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp20Dialect())
    buildoptions(libWebView_buildoptions)
    includedirs(libWebView_includedirs)
    defines(libWebView_defines)
    files(libWebView_sources)
    links(libWebView_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("WebView"))
filter "configurations:Debug*"
    defines(libWebView_debugdefines)
filter "configurations:Release*"
    defines(libWebView_releasedefines)

-- Zlib
project "Zlib"
language "C"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    buildoptions(libZlib_buildoptions)
    includedirs(libZlib_includedirs)
    defines(libZlib_defines)
    files(libZlib_sources)
    links(libZlib_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Zlib"))
filter "configurations:Debug*"
    defines(libZlib_debugdefines)
filter "configurations:Release*"
    defines(libZlib_releasedefines)
