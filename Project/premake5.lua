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
require "Libs/Zlib/Zlib"
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
kind "ConsoleApp"
language "C++"
pic "On"
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
kind "SharedLib"
language "C++"
pic "On"
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
kind "SharedLib"
language "C++"
pic "On"
    includedirs(libBackwardCPP_includedirs)
    files(libBackwardCPP_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("BackwardCPP"))

-- Boost
project "Boost"
kind "SharedLib"
language "C++"
pic "On"
    includedirs(libBoost_includedirs)
    files(libBoost_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("Boost"))

-- FantasyName
project "FantasyName"
kind "SharedLib"
language "C++"
pic "On"
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
kind "SharedLib"
language "C++"
pic "On"
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
kind "SharedLib"
language "C"
pic "On"
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
kind "SharedLib"
language "C++"
pic "On"
    includedirs(libTinyXML2_includedirs)
    files(libTinyXML2_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("TinyXML2"))

-- TMXParser
project "TMXParser"
kind "SharedLib"
language "C++"
pic "On"
    includedirs(libTMXParser_includedirs)
    includedirs(libTinyXML2_includedirs)
    files(libTMXParser_sources)
    links(libTMXParser_libs)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("TMXParser"))

-- Zlib
project "Zlib"
kind "SharedLib"
language "C"
pic "On"
    includedirs(libZlib_includedirs)
    defines(libZlib_defines)
    files(libZlib_sources)
    targetdir(GetTargetDirectory())
    targetname(GetTargetName("Zlib"))
filter "configurations:Debug*"
    defines(libZlib_debugdefines)
filter "configurations:Release*"
    defines(libZlib_releasedefines)
