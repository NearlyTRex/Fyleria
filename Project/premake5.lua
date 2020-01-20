-- Imports
require "Fyleria/Fyleria"
require "Libs/C/Zlib/Zlib"
require "Libs/C++/Backward/Backward"
require "Libs/C++/BetterEnums/BetterEnums"
require "Libs/C++/Boost/Boost"
require "Libs/C++/Date/Date"
require "Libs/C++/FantasyName/FantasyName"
require "Libs/C++/ImmutableString/ImmutableString"
require "Libs/C++/Json/Json"
require "Libs/C++/LRUCache/LRUCache"
require "Libs/C++/MicroPather/MicroPather"
require "Libs/C++/ObjectThreadsafe/ObjectThreadsafe"
require "Libs/C++/SpdLog/SpdLog"
require "Libs/C++/WebKit/WebKit"
require "utility"

-- Create solution
workspace "all"
    startproject "Fyleria"
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
    runpathdirs(GetAppRunPaths())
    cppdialect(GetCpp17Dialect())
    buildoptions(appFyleria_buildoptions)
    linkoptions(appFyleria_linkoptions)
    includedirs(appFyleria_includedirs)
    includedirs(libBackward_includedirs)
    includedirs(libBoost_includedirs)
    includedirs(libFantasyName_includedirs)
    includedirs(libZlib_includedirs)
    includedirs(libImmutableString_includedirs)
    includedirs(libBetterEnums_includedirs)
    includedirs(libLRUCache_includedirs)
    includedirs(libJson_includedirs)
    includedirs(libObjectThreadsafe_includedirs)
    includedirs(libSpdLog_includedirs)
    includedirs(libWebKit_includedirs)
    libdirs(libWebKit_libdirs)
    defines(appFyleria_defines)
    defines(libBackward_defines)
    defines(libBetterEnums_defines)
    defines(libBoost_defines)
    defines(libLRUCache_defines)
    files(appFyleria_sources)
    links(appFyleria_libs)
    links(libWebKit_libs)
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
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp17Dialect())
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

-- FantasyName
project "FantasyName"
language "C++"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
    cppdialect(GetCpp17Dialect())
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
    cppdialect(GetCpp17Dialect())
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
    cppdialect(GetCpp17Dialect())
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

-- Zlib
project "Zlib"
language "C"
pic "On"
    kind(GetStaticLibraryType())
    runpathdirs(GetLibraryRunPaths())
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
