-- Configuration
libFreeType2_extradir = "Libs/FreeType2/extra/"
libFreeType2_origdir = "Libs/FreeType2/orig/"
libFreeType2_srcdir = libFreeType2_origdir .. "src/"
libFreeType2_incdir = libFreeType2_origdir .. "include/"

-- Includes
libFreeType2_includedirs = {
    libFreeType2_incdir,
    libFreeType2_extradir .. "linux/"
}

-- Defines
libFreeType2_defines = {
    "PIC",
    "FT2_BUILD_LIBRARY",
    "FT_CONFIG_MODULES_H=\"ftmodule.h\"",
    "FT_CONFIG_CONFIG_H=\"ftconfig.h\"",
    "FT_CONFIG_OPTIONS_H=\"ftoption.h\""
}
libFreeType2_debugdefines = {
}
libFreeType2_releasedefines = {
}

-- Options
libFreeType2_buildoptions = {
}
libFreeType2_linkoptions = {
}
if os.host() == "linux" then
    table.insert(libFreeType2_buildoptions, "-fvisibility=hidden -pedantic -ansi")
end

-- Sources
libFreeType2_sources = {
    libFreeType2_srcdir .. "autofit/autofit.c",
    libFreeType2_srcdir .. "base/ftdebug.c",
    libFreeType2_srcdir .. "base/ftinit.c",
    libFreeType2_srcdir .. "base/ftbase.c",
    libFreeType2_srcdir .. "base/ftbbox.c",
    libFreeType2_srcdir .. "base/ftbdf.c",
    libFreeType2_srcdir .. "base/ftbitmap.c",
    libFreeType2_srcdir .. "base/ftcid.c",
    libFreeType2_srcdir .. "base/ftfstype.c",
    libFreeType2_srcdir .. "base/ftgasp.c",
    libFreeType2_srcdir .. "base/ftglyph.c",
    libFreeType2_srcdir .. "base/ftgxval.c",
    libFreeType2_srcdir .. "base/ftmm.c",
    libFreeType2_srcdir .. "base/ftotval.c",
    libFreeType2_srcdir .. "base/ftpatent.c",
    libFreeType2_srcdir .. "base/ftpfr.c",
    libFreeType2_srcdir .. "base/ftstroke.c",
    libFreeType2_srcdir .. "base/ftsynth.c",
    libFreeType2_srcdir .. "base/fttype1.c",
    libFreeType2_srcdir .. "base/ftwinfnt.c",
    libFreeType2_srcdir .. "base/ftsystem.c",
    libFreeType2_srcdir .. "bdf/bdf.c",
    libFreeType2_srcdir .. "cache/ftcache.c",
    libFreeType2_srcdir .. "cff/cff.c",
    libFreeType2_srcdir .. "cid/type1cid.c",
    libFreeType2_srcdir .. "lzw/ftlzw.c",
    libFreeType2_srcdir .. "pcf/pcf.c",
    libFreeType2_srcdir .. "pfr/pfr.c",
    libFreeType2_srcdir .. "psaux/psaux.c",
    libFreeType2_srcdir .. "pshinter/pshinter.c",
    libFreeType2_srcdir .. "psnames/psnames.c",
    libFreeType2_srcdir .. "raster/raster.c",
    libFreeType2_srcdir .. "sfnt/sfnt.c",
    libFreeType2_srcdir .. "smooth/smooth.c",
    libFreeType2_srcdir .. "truetype/truetype.c",
    libFreeType2_srcdir .. "type1/type1.c",
    libFreeType2_srcdir .. "type42/type42.c",
    libFreeType2_srcdir .. "winfonts/winfnt.c",
}
