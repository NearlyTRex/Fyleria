-- Configuration
libFribidi_extradir = "Libs/Fribidi/extra/"
libFribidi_origdir = "Libs/Fribidi/orig/"
libFribidi_srcdir = libFribidi_origdir .. "lib/"
libFribidi_incdir = libFribidi_origdir .. "lib/"

-- Includes
libFribidi_includedirs = {
    libFribidi_incdir
}
if os.host() == "linux" then
    table.insert(libFribidi_includedirs, libFribidi_extradir .. "linux/")
    table.insert(libFribidi_includedirs, libFribidi_extradir .. "linux/gen.tab/")
    table.insert(libFribidi_includedirs, libFribidi_extradir .. "linux/lib/")
end

-- Defines
libFribidi_defines = {
    "HAVE_CONFIG_H",
    "_FILE_OFFSET_BITS=64",
    "FRIBIDI_ENTRY=extern __attribute__ ((visibility (\"default\")))",
}
libFribidi_debugdefines = {
    "DEBUG"
}
libFribidi_releasedefines = {
}

-- Options
libFribidi_buildoptions = {
}
libFribidi_linkoptions = {
}

-- Libs
libFribidi_libs = {
}

-- Sources
libFribidi_sources = {
    libFribidi_srcdir .. "fribidi-arabic.c",
    libFribidi_srcdir .. "fribidi-bidi.c",
    libFribidi_srcdir .. "fribidi-bidi-types.c",
    libFribidi_srcdir .. "fribidi-brackets.c",
    libFribidi_srcdir .. "fribidi.c",
    libFribidi_srcdir .. "fribidi-char-sets.c",
    libFribidi_srcdir .. "fribidi-char-sets-cap-rtl.c",
    libFribidi_srcdir .. "fribidi-char-sets-cp1255.c",
    libFribidi_srcdir .. "fribidi-char-sets-cp1256.c",
    libFribidi_srcdir .. "fribidi-char-sets-iso8859-6.c",
    libFribidi_srcdir .. "fribidi-char-sets-iso8859-8.c",
    libFribidi_srcdir .. "fribidi-char-sets-utf8.c",
    libFribidi_srcdir .. "fribidi-deprecated.c",
    libFribidi_srcdir .. "fribidi-joining.c",
    libFribidi_srcdir .. "fribidi-joining-types.c",
    libFribidi_srcdir .. "fribidi-mirroring.c",
    libFribidi_srcdir .. "fribidi-run.c",
    libFribidi_srcdir .. "fribidi-shape.c",
}
