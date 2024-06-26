-- Configuration
libZlib_extradir = "Libs/C/Zlib/extra/"
libZlib_origdir = "Libs/C/Zlib/orig/"
libZlib_srcdir = libZlib_origdir
libZlib_incdir = libZlib_origdir

-- Includes
libZlib_includedirs = {
    libZlib_incdir
}

-- Defines
libZlib_defines = {
}
if os.host() == "windows" then
    table.insert(libZlib_defines, "_CRT_SECURE_NO_WARNINGS")
    table.insert(libZlib_defines, "_CRT_SECURE_NO_DEPRECATE")
    table.insert(libZlib_defines, "_CRT_NONSTDC_NO_DEPRECATE")
elseif os.host() == "linux" then
    table.insert(libZlib_defines, "HAVE_UNISTD_H")
    table.insert(libZlib_defines, "HAVE_STDARG_H")
end
libZlib_debugdefines = {
    "DEBUG"
}
libZlib_releasedefines = {
    "NDEBUG"
}

-- Libs
libZlib_libs = {
}

-- Options
libZlib_buildoptions = {
}
libZlib_linkoptions = {
}

-- Sources
libZlib_sources = {
    libZlib_srcdir .. "adler32.c",
    libZlib_srcdir .. "compress.c",
    libZlib_srcdir .. "crc32.c",
    libZlib_srcdir .. "deflate.c",
    libZlib_srcdir .. "gzclose.c",
    libZlib_srcdir .. "gzlib.c",
    libZlib_srcdir .. "gzread.c",
    libZlib_srcdir .. "gzwrite.c",
    libZlib_srcdir .. "infback.c",
    libZlib_srcdir .. "inffast.c",
    libZlib_srcdir .. "inflate.c",
    libZlib_srcdir .. "inftrees.c",
    libZlib_srcdir .. "trees.c",
    libZlib_srcdir .. "uncompr.c",
    libZlib_srcdir .. "zutil.c",
}
