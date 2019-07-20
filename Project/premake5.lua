-- Imports
require "Fyleria/Fyleria"
require "Libs/Assert/Assert"
require "Libs/BackwardCPP/BackwardCPP"
require "Libs/BetterEnums/BetterEnums"
require "Libs/Boost/Boost"
require "Libs/FantasyName/FantasyName"
require "Libs/ImmutableString/ImmutableString"
require "Libs/MicroPather/MicroPather"
require "Libs/ModernCPPJson/ModernCPPJson"
require "Libs/ObjectThreadsafe/ObjectThreadsafe"
require "Libs/PyBind/PyBind"
require "Libs/Python3/Python3"
require "Libs/TinyXML2/TinyXML2"
require "Libs/TMXParser/TMXParser"
require "Libs/URIParser/URIParser"
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
    includedirs(libAssert_includedirs)
    includedirs(libBackwardCPP_includedirs)
    includedirs(libBoost_includedirs)
    includedirs(libFantasyName_includedirs)
    includedirs(libImmutableString_includedirs)
    includedirs(libBetterEnums_includedirs)
    includedirs(libModernCPPJson_includedirs)
    includedirs(libObjectThreadsafe_includedirs)
    includedirs(libPistache_includedirs)
    includedirs(libPyBind_includedirs)
    includedirs(libPython3_includedirs)
    includedirs(libURIParser_includedirs)
    includedirs(libZlib_includedirs)
    defines(appFyleria_defines)
    defines(libBackwardCPP_defines)
    defines(libBetterEnums_defines)
    defines(libPython3_defines)
    files(appFyleria_sources)
    links(appFyleria_libs)
    links(libBackwardCPP_libs)
    links(libPython3_libs)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("FyleriaMain"))
filter "configurations:Debug*"
    defines(appFyleria_debugdefines)
filter "configurations:Release*"
    defines(appFyleria_releasedefines)

-- Assert
project "Assert"
language "C++"
pic "On"
    kind(GetLibraryType())
    includedirs(libAssert_includedirs)
    files(libAssert_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("Assert"))
filter "configurations:Debug*"
    defines(libAssert_debugdefines)
filter "configurations:Release*"
    defines(libAssert_releasedefines)

-- BackwardCPP
project "BackwardCPP"
language "C++"
pic "On"
    kind(GetLibraryType())
    includedirs(libBackwardCPP_includedirs)
    files(libBackwardCPP_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("BackwardCPP"))

-- Boost
project "Boost"
language "C++"
pic "On"
    kind(GetLibraryType())
    includedirs(libBoost_includedirs)
    files(libBoost_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("Boost"))

-- FantasyName
project "FantasyName"
language "C++"
pic "On"
    kind(GetLibraryType())
    includedirs(libFantasyName_includedirs)
    defines(libFantasyName_defines)
    files(libFantasyName_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("FantasyName"))
filter "configurations:Debug*"
    defines(libFantasyName_debugdefines)
filter "configurations:Release*"
    defines(libFantasyName_releasedefines)

-- MicroPather
project "MicroPather"
language "C++"
pic "On"
    kind(GetLibraryType())
    includedirs(libMicroPather_includedirs)
    files(libMicroPather_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("MicroPather"))
filter "configurations:Debug*"
    defines(libMicroPather_debugdefines)
filter "configurations:Release*"
    defines(libMicroPather_releasedefines)

-- Python3
project "Python3"
language "C"
pic "On"
    kind(GetLibraryType())
    includedirs(libPython3_includedirs)
    includedirs(libZlib_includedirs)
    defines(libPython3_defines)
    files(libPython3_sources)
    links(libPython3_libs)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("Python3"))
filter "configurations:Debug*"
    defines(libPython3_debugdefines)
filter "configurations:Release*"
    defines(libPython3_releasedefines)

-- TinyXML2
project "TinyXML2"
language "C++"
pic "On"
    kind(GetLibraryType())
    includedirs(libTinyXML2_includedirs)
    files(libTinyXML2_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("TinyXML2"))

-- TMXParser
project "TMXParser"
language "C++"
pic "On"
    kind(GetLibraryType())
    includedirs(libTMXParser_includedirs)
    includedirs(libTinyXML2_includedirs)
    files(libTMXParser_sources)
    links(libTMXParser_libs)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("TMXParser"))

-- URIParser
project "URIParser"
language "C"
pic "On"
    kind(GetLibraryType())
    includedirs(libURIParser_includedirs)
    files(libURIParser_sources)
    links(libURIParser_libs)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("URIParser"))

-- Zlib
project "Zlib"
language "C"
pic "On"
    kind(GetLibraryType())
    includedirs(libZlib_includedirs)
    defines(libZlib_defines)
    files(libZlib_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("Zlib"))
filter "configurations:Debug*"
    defines(libZlib_debugdefines)
filter "configurations:Release*"
    defines(libZlib_releasedefines)
