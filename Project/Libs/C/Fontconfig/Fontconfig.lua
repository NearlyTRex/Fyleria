-- Configuration
libFontconfig_extradir = "Libs/C/Fontconfig/extra/"
libFontconfig_origdir = "Libs/C/Fontconfig/orig/"
libFontconfig_srcdir = libFontconfig_origdir
libFontconfig_incdir = libFontconfig_origdir

-- Includes
libFontconfig_includedirs = {
    libFontconfig_incdir,
}
if os.host() == "linux" then
    table.insert(libFontconfig_includedirs, libFontconfig_extradir .. "linux/")
    table.insert(libFontconfig_includedirs, libFontconfig_extradir .. "linux/src/")
end

-- Defines
libFontconfig_defines = {
    "HAVE_CONFIG_H",
    "PIC",
    "FONTCONFIG_PATH=\"Data/Fontconfig\"",
    "FC_TEMPLATEDIR=\"Data/Fontconfig/Templates\"",
    "FC_CACHEDIR=\"Data/Fontconfig/Cache\""
}
libFontconfig_debugdefines = {
}
libFontconfig_releasedefines = {
}

-- Options
libFontconfig_buildoptions = {
}
libFontconfig_linkoptions = {
}

-- Libs
libFontconfig_libs = {
    "FreeType2"
}

-- Sources
libFontconfig_sources = {
    libFontconfig_srcdir .. "src/fcarch.c",
    libFontconfig_srcdir .. "src/fcatomic.c",
    libFontconfig_srcdir .. "src/fccache.c",
    libFontconfig_srcdir .. "src/fccfg.c",
    libFontconfig_srcdir .. "src/fccharset.c",
    libFontconfig_srcdir .. "src/fccompat.c",
    libFontconfig_srcdir .. "src/fcdbg.c",
    libFontconfig_srcdir .. "src/fcdefault.c",
    libFontconfig_srcdir .. "src/fcdir.c",
    libFontconfig_srcdir .. "src/fcformat.c",
    libFontconfig_srcdir .. "src/fcfreetype.c",
    libFontconfig_srcdir .. "src/fcfs.c",
    libFontconfig_srcdir .. "src/fcptrlist.c",
    libFontconfig_srcdir .. "src/fchash.c",
    libFontconfig_srcdir .. "src/fcinit.c",
    libFontconfig_srcdir .. "src/fclang.c",
    libFontconfig_srcdir .. "src/fclist.c",
    libFontconfig_srcdir .. "src/fcmatch.c",
    libFontconfig_srcdir .. "src/fcmatrix.c",
    libFontconfig_srcdir .. "src/fcname.c",
    libFontconfig_srcdir .. "src/fcobjs.c",
    libFontconfig_srcdir .. "src/fcpat.c",
    libFontconfig_srcdir .. "src/fcrange.c",
    libFontconfig_srcdir .. "src/fcserialize.c",
    libFontconfig_srcdir .. "src/fcstat.c",
    libFontconfig_srcdir .. "src/fcstr.c",
    libFontconfig_srcdir .. "src/fcweight.c",
    libFontconfig_srcdir .. "src/fcxml.c",
    libFontconfig_srcdir .. "src/ftglue.c"
}
