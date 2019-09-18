-- Imports
require "Fyleria/Fyleria"
require "Libs/Atk/Atk"
require "Libs/BackwardCPP/BackwardCPP"
require "Libs/BetterEnums/BetterEnums"
require "Libs/Boost/Boost"
require "Libs/Brotli/Brotli"
require "Libs/Cairo/Cairo"
require "Libs/Curl/Curl"
require "Libs/ElfUtils/ElfUtils"
require "Libs/Epoxy/Epoxy"
require "Libs/FantasyName/FantasyName"
require "Libs/Fontconfig/Fontconfig"
require "Libs/FFI/FFI"
require "Libs/FreeType2/FreeType2"
require "Libs/GCrypt/GCrypt"
require "Libs/GdkPixbuf/GdkPixbuf"
require "Libs/GPGError/GPGError"
require "Libs/Graphene/Graphene"
require "Libs/Gtk/Gtk"
require "Libs/Glib/Glib"
require "Libs/Harfbuzz/Harfbuzz"
require "Libs/Icu/Icu"
require "Libs/ImmutableString/ImmutableString"
require "Libs/Jpeg/Jpeg"
require "Libs/JpegTurbo/JpegTurbo"
require "Libs/LibreSSL/LibreSSL"
require "Libs/LRUCache/LRUCache"
require "Libs/MicroPather/MicroPather"
require "Libs/ModernCPPJson/ModernCPPJson"
require "Libs/ObjectThreadsafe/ObjectThreadsafe"
require "Libs/OpenCFLite/OpenCFLite"
require "Libs/Pango/Pango"
require "Libs/Pixman/Pixman"
require "Libs/PCRE/PCRE"
require "Libs/PNG/PNG"
require "Libs/PSL/PSL"
require "Libs/PThreadsWin32"
require "Libs/Soup/Soup"
require "Libs/SpdLog/SpdLog"
require "Libs/SQLite/SQLite"
require "Libs/UtilLinux/UtilLinux"
require "Libs/WebKitGTK/WebKitGTK"
require "Libs/Webp/Webp"
require "Libs/XkbCommon/XkbCommon"
require "Libs/XML2/XML2"
require "Libs/XSLT/XSLT"
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
language "C++"
pic "On"
    kind(GetAppType())
    cppdialect(GetCpp17Dialect())
    buildoptions(appFyleria_buildoptions)
    linkoptions(appFyleria_linkoptions)
    includedirs(appFyleria_includedirs)
    includedirs(libBackwardCPP_includedirs)
    includedirs(libBoost_includedirs)
    includedirs(libElfUtils_includedirs)
    includedirs(libFantasyName_includedirs)
    includedirs(libGlib_includedirs)
    includedirs(libCairo_includedirs)
    includedirs(libSoup_includedirs)
    includedirs(libZlib_includedirs)
    includedirs(libWebKitGTK_includedirs_public)
    includedirs(libImmutableString_includedirs)
    includedirs(libBetterEnums_includedirs)
    includedirs(libLRUCache_includedirs)
    includedirs(libModernCPPJson_includedirs)
    includedirs(libObjectThreadsafe_includedirs)
    includedirs(libSpdLog_includedirs)
    defines(appFyleria_defines)
    defines(libBackwardCPP_defines)
    defines(libBetterEnums_defines)
    defines(libBoost_defines)
    defines(libLRUCache_defines)
    files(appFyleria_sources)
    links(appFyleria_libs)
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
    kind(GetSharedLibraryType())
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
    kind(GetSharedLibraryType())
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
    kind(GetSharedLibraryType())
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
    kind(GetSharedLibraryType())
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

-- Atk
project "Atk"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    cppdialect(GetCpp17Dialect())
    includedirs(libAtk_includedirs)
    defines(libAtk_defines)
    files(libAtk_sources)
    links(libAtk_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Atk"))
filter "configurations:Debug*"
    defines(libAtk_debugdefines)
filter "configurations:Release*"
    defines(libAtk_releasedefines)

-- Cairo
project "Cairo"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    cppdialect(GetCpp17Dialect())
    buildoptions(libCairo_buildoptions)
    linkoptions(libCairo_linkoptions)
    includedirs(libCairo_includedirs)
    includedirs(libFontconfig_includedirs)
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

-- ElfUtils
project "ElfUtils"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libElfUtils_buildoptions)
    linkoptions(libElfUtils_linkoptions)
    includedirs(libElfUtils_includedirs)
    defines(libElfUtils_defines)
    files(libElfUtils_sources)
    links(libElfUtils_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("ElfUtils"))
filter "configurations:Debug*"
    defines(libElfUtils_debugdefines)
filter "configurations:Release*"
    defines(libFreeType2_releasedefines)

-- Epoxy
project "Epoxy"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libEpoxy_buildoptions)
    linkoptions(libEpoxy_linkoptions)
    includedirs(libEpoxy_includedirs)
    defines(libEpoxy_defines)
    files(libEpoxy_sources)
    links(libEpoxy_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Epoxy"))
filter "configurations:Debug*"
    defines(libEpoxy_debugdefines)
filter "configurations:Release*"
    defines(libFreeType2_releasedefines)

-- FFI
project "FFI"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libFFI_buildoptions)
    linkoptions(libFFI_linkoptions)
    includedirs(libFFI_includedirs)
    defines(libFFI_defines)
    files(libFFI_sources)
    links(libFFI_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("FFI"))
filter "configurations:Debug*"
    defines(libFFI_debugdefines)
filter "configurations:Release*"
    defines(libFreeType2_releasedefines)

-- Fontconfig
project "Fontconfig"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libFontconfig_buildoptions)
    linkoptions(libFontconfig_linkoptions)
    includedirs(libFontconfig_includedirs)
    includedirs(libFreeType2_includedirs)
    includedirs(libXML2_includedirs)
    defines(libFontconfig_defines)
    files(libFontconfig_sources)
    links(libFontconfig_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Fontconfig"))
filter "configurations:Debug*"
    defines(libFontconfig_debugdefines)
filter "configurations:Release*"
    defines(libFontconfig_releasedefines)

-- FreeType2
project "FreeType2"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libFreeType2_buildoptions)
    linkoptions(libFreeType2_linkoptions)
    includedirs(libFreeType2_includedirs)
    includedirs(libPNG_includedirs)
    defines(libFreeType2_defines)
    files(libFreeType2_sources)
    links(libFreeType2_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("FreeType2"))
filter "configurations:Debug*"
    defines(libFreeType2_debugdefines)
filter "configurations:Release*"
    defines(libFreeType2_releasedefines)

-- GCrypt
project "GCrypt"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libGCrypt_buildoptions)
    linkoptions(libGCrypt_linkoptions)
    includedirs(libGCrypt_includedirs)
    defines(libGCrypt_defines)
    files(libGCrypt_sources)
    links(libGCrypt_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("GCrypt"))
filter "configurations:Debug*"
    defines(libGCrypt_debugdefines)
filter "configurations:Release*"
    defines(libGCrypt_releasedefines)

-- Glib
project "Glib"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libGlib_buildoptions)
    linkoptions(libGlib_linkoptions)
    includedirs(libGlib_includedirs)
    includedirs(libFFI_includedirs)
    defines(libGlib_defines)
    files(libGlib_sources)
    links(libGlib_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Glib"))
filter "configurations:Debug*"
    defines(libGlib_debugdefines)
filter "configurations:Release*"
    defines(libGlib_releasedefines)

-- Harfbuzz
project "Harfbuzz"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    includedirs(libHarfbuzz_includedirs)
    includedirs(libFontconfig_includedirs)
    includedirs(libFreeType2_includedirs)
    includedirs(libGlib_includedirs)
    defines(libHarfbuzz_defines)
    files(libHarfbuzz_sources)
    links(libHarfbuzz_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Harfbuzz"))
filter "configurations:Debug*"
    defines(libHarfbuzz_debugdefines)
filter "configurations:Release*"
    defines(libHarfbuzz_releasedefines)

-- Icu
project "Icu"
language "C++"
pic "On"
    kind(GetSharedLibraryType())
    includedirs(libIcu_includedirs)
    defines(libIcu_defines_Icu)
    files(libIcu_sources_Icu)
    links(libIcu_libs_Icu)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Icu"))
filter "configurations:Debug*"
    defines(libIcu_debugdefines_Icu)
filter "configurations:Release*"
    defines(libIcu_releasedefines_Icu)

-- Icu Data
project "IcuData"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    includedirs(libIcu_includedirs)
    defines(libIcu_defines_IcuData)
    files(libIcu_sources_IcuData)
    links(libIcu_libs_IcuData)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("IcuData"))
filter "configurations:Debug*"
    defines(libIcu_debugdefines_IcuData)
filter "configurations:Release*"
    defines(libIcu_releasedefines_IcuData)

-- Jpeg
project "Jpeg"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    includedirs(libJpeg_includedirs)
    defines(libJpeg_defines)
    files(libJpeg_sources)
    links(libJpeg_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Jpeg"))
filter "configurations:Debug*"
    defines(libJpeg_debugdefines)
filter "configurations:Release*"
    defines(libJpeg_releasedefines)

-- Pixman
project "Pixman"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libPixman_buildoptions)
    linkoptions(libPixman_linkoptions)
    includedirs(libPixman_includedirs)
    defines(libPixman_defines)
    files(libPixman_sources)
    links(libPixman_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Pixman"))
filter "configurations:Debug*"
    defines(libPixman_debugdefines)
filter "configurations:Release*"
    defines(libPixman_releasedefines)

-- PCRE
project "PCRE"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libPCRE_buildoptions)
    linkoptions(libPCRE_linkoptions)
    includedirs(libPCRE_includedirs)
    defines(libPCRE_defines)
    files(libPCRE_sources)
    links(libPCRE_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("PCRE"))
filter "configurations:Debug*"
    defines(libPCRE_debugdefines)
filter "configurations:Release*"
    defines(libPCRE_releasedefines)

-- PNG
project "PNG"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libPNG_buildoptions)
    linkoptions(libPNG_linkoptions)
    includedirs(libPNG_includedirs)
    includedirs(libZlib_includedirs)
    defines(libPNG_defines)
    files(libPNG_sources)
    links(libPNG_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("PNG"))
filter "configurations:Debug*"
    defines(libPNG_debugdefines)
filter "configurations:Release*"
    defines(libPNG_releasedefines)

-- PSL
project "PSL"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libPSL_buildoptions)
    linkoptions(libPSL_linkoptions)
    includedirs(libPSL_includedirs)
    defines(libPSL_defines)
    files(libPSL_sources)
    links(libPSL_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("PSL"))
filter "configurations:Debug*"
    defines(libPSL_debugdefines)
filter "configurations:Release*"
    defines(libPSL_releasedefines)

-- Soup
project "Soup"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    includedirs(libSoup_includedirs)
    includedirs(libGlib_includedirs)
    includedirs(libXML2_includedirs)
    includedirs(libSQLite_includedirs)
    includedirs(libPSL_includedirs)
    defines(libSoup_defines)
    files(libSoup_sources)
    links(libSoup_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Soup"))
filter "configurations:Debug*"
    defines(libSoup_debugdefines)
filter "configurations:Release*"
    defines(libSoup_releasedefines)

-- SQLite
project "SQLite"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libSQLite_buildoptions)
    linkoptions(libSQLite_linkoptions)
    includedirs(libSQLite_includedirs)
    defines(libSQLite_defines)
    files(libSQLite_sources)
    links(libSQLite_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("SQLite"))
filter "configurations:Debug*"
    defines(libSQLite_debugdefines)
filter "configurations:Release*"
    defines(libSQLite_releasedefines)

-- Webp
project "Webp"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libWebp_buildoptions)
    linkoptions(libWebp_linkoptions)
    includedirs(libWebp_includedirs)
    defines(libWebp_defines)
    files(libWebp_sources)
    links(libWebp_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("Webp"))
filter "configurations:Debug*"
    defines(libWebp_debugdefines)
filter "configurations:Release*"
    defines(libWebp_releasedefines)

-- XML2
project "XML2"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libXML2_buildoptions)
    linkoptions(libXML2_linkoptions)
    includedirs(libXML2_includedirs)
    defines(libXML2_defines)
    files(libXML2_sources)
    links(libXML2_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("XML2"))
filter "configurations:Debug*"
    defines(libXML2_debugdefines)
filter "configurations:Release*"
    defines(libXML2_releasedefines)

-- XSLT
project "XSLT"
language "C"
pic "On"
    kind(GetSharedLibraryType())
    buildoptions(libXSLT_buildoptions)
    linkoptions(libXSLT_linkoptions)
    includedirs(libXSLT_includedirs)
    includedirs(libXML2_includedirs)
    defines(libXSLT_defines)
    files(libXSLT_sources)
    links(libXSLT_libs)
    targetdir(GetLibraryTargetDirectory())
    targetname(GetTargetName("XSLT"))
filter "configurations:Debug*"
    defines(libXSLT_debugdefines)
filter "configurations:Release*"
    defines(libXSLT_releasedefines)

-- Zlib
project "Zlib"
language "C"
pic "On"
    kind(GetSharedLibraryType())
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

--------------------- WebKitGTK ---------------------
-- WTFGTK
if os.host() == "linux" then
    project "WTFGTK"
    language "C++"
    pic "On"
        kind(GetSharedLibraryType())
        cppdialect(GetCpp14Dialect())
        buildoptions(libWebKitGTK_buildoptions_Libraries)
        linkoptions(libWebKitGTK_linkoptions_Libraries)
        includedirs(libWebKitGTK_includedirs_WTFGTK)
        includedirs(libWebKitGTK_includedirs_public)
        includedirs(libGlib_includedirs)
        includedirs(libIcu_includedirs)
        defines(libWebKitGTK_defines_WTFGTK)
        files(libWebKitGTK_sources_WTFGTK)
        links(libWebKitGTK_libs_WTFGTK)
        targetdir(GetLibraryTargetDirectory())
        targetname(GetTargetName("WTFGTK"))
    filter "configurations:Debug*"
        defines(libWebKitGTK_debugdefines_WTFGTK)
    filter "configurations:Release*"
        defines(libWebKitGTK_releasedefines_WTFGTK)
end

-- WebCoreGTK
if os.host() == "linux" then
    project "WebCoreGTK"
    language "C++"
    pic "On"
        kind(GetSharedLibraryType())
        cppdialect(GetCpp14Dialect())
        buildoptions(libWebKitGTK_buildoptions_Libraries)
        linkoptions(libWebKitGTK_linkoptions_Libraries)
        includedirs(libWebKitGTK_includedirs_WebCoreGTK)
        includedirs(libWebKitGTK_includedirs_WTFGTK)
        includedirs(libWebKitGTK_includedirs_public)
        includedirs(libGlib_includedirs)
        includedirs(libIcu_includedirs)
        includedirs(libSoup_includedirs)
        includedirs(libSQLite_includedirs)
        includedirs(libJpeg_includedirs)
        includedirs(libPNG_includedirs)
        includedirs(libWebp_includedirs)
        includedirs(libCairo_includedirs)
        includedirs(libFontconfig_includedirs)
        includedirs(libFreeType2_includedirs)
        includedirs(libGCrypt_includedirs)
        includedirs(libHarfbuzz_includedirs)
        includedirs(libXML2_includedirs)
        includedirs(libXSLT_includedirs)
        defines(libWebKitGTK_defines_WebCoreGTK)
        files(libWebKitGTK_sources_WebCoreGTK)
        links(libWebKitGTK_libs_WebCoreGTK)
        targetdir(GetLibraryTargetDirectory())
        targetname(GetTargetName("WebCoreGTK"))
    filter "configurations:Debug*"
        defines(libWebKitGTK_debugdefines_WebCoreGTK)
    filter "configurations:Release*"
        defines(libWebKitGTK_releasedefines_WebCoreGTK)
end

-- JavaScriptCoreGTK
if os.host() == "linux" then
    project "JavaScriptCoreGTK"
    language "C++"
    pic "On"
        kind(GetSharedLibraryType())
        cppdialect(GetCpp14Dialect())
        buildoptions(libWebKitGTK_buildoptions_Libraries)
        linkoptions(libWebKitGTK_linkoptions_Libraries)
        includedirs(libWebKitGTK_includedirs_JavaScriptCoreGTK)
        includedirs(libWebKitGTK_includedirs_WebCoreGTK)
        includedirs(libWebKitGTK_includedirs_WTFGTK)
        includedirs(libWebKitGTK_includedirs_public)
        includedirs(libGlib_includedirs)
        includedirs(libIcu_includedirs)
        defines(libWebKitGTK_defines_JavaScriptCoreGTK)
        files(libWebKitGTK_sources_JavaScriptCoreGTK)
        links(libWebKitGTK_libs_JavaScriptCoreGTK)
        targetdir(GetLibraryTargetDirectory())
        targetname(GetTargetName("JavaScriptCoreGTK"))
    filter "configurations:Debug*"
        defines(libWebKitGTK_debugdefines_JavaScriptCoreGTK)
    filter "configurations:Release*"
        defines(libWebKitGTK_releasedefines_JavaScriptCoreGTK)
end

-- WebKitGTK
if os.host() == "linux" then
    project "WebKitGTK"
    language "C++"
    pic "On"
        kind(GetSharedLibraryType())
        cppdialect(GetCpp14Dialect())
        buildoptions(libWebKitGTK_buildoptions_Libraries)
        linkoptions(libWebKitGTK_linkoptions_Libraries)
        includedirs(libWebKitGTK_includedirs_WebKitGTK)
        includedirs(libWebKitGTK_includedirs_WebCoreGTK)
        includedirs(libWebKitGTK_includedirs_JavaScriptCoreGTK)
        includedirs(libWebKitGTK_includedirs_WTFGTK)
        includedirs(libWebKitGTK_includedirs_public)
        includedirs(libGlib_includedirs)
        includedirs(libIcu_includedirs)
        includedirs(libSoup_includedirs)
        includedirs(libSQLite_includedirs)
        includedirs(libCairo_includedirs)
        includedirs(libFontconfig_includedirs)
        includedirs(libFreeType2_includedirs)
        includedirs(libHarfbuzz_includedirs)
        defines(libWebKitGTK_defines_WebKitGTK)
        files(libWebKitGTK_sources_WebKitGTK)
        links(libWebKitGTK_libs_WebKitGTK)
        targetdir(GetLibraryTargetDirectory())
        targetname(GetTargetName("WebKitGTK"))
    filter "configurations:Debug*"
        defines(libWebKitGTK_debugdefines_WebKitGTK)
    filter "configurations:Release*"
        defines(libWebKitGTK_releasedefines_WebKitGTK)
end

-- NetworkProcessGTK
if os.host() == "linux" then
    project "NetworkProcessGTK"
    language "C++"
    pic "On"
        kind(GetAppType())
        cppdialect(GetCpp14Dialect())
        buildoptions(libWebKitGTK_buildoptions_Processes)
        linkoptions(libWebKitGTK_linkoptions_Processes)
        includedirs(libWebKitGTK_includedirs_WebKitGTK)
        includedirs(libWebKitGTK_includedirs_WebCoreGTK)
        includedirs(libWebKitGTK_includedirs_JavaScriptCoreGTK)
        includedirs(libWebKitGTK_includedirs_WTFGTK)
        includedirs(libWebKitGTK_includedirs_public)
        defines(libWebKitGTK_defines_WebKitGTK)
        files(libWebKitGTK_sources_NetworkProcess)
        links(libWebKitGTK_libs_Processes)
        targetdir(GetAppTargetDirectory())
        targetname(GetTargetName("NetworkProcessGTK"))
    filter "configurations:Debug*"
        defines(libWebKitGTK_debugdefines_WebKitGTK)
    filter "configurations:Release*"
        defines(libWebKitGTK_releasedefines_WebKitGTK)
end
--------------------- WebKitGTK ---------------------
