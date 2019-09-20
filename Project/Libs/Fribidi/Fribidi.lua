-- Configuration
libFribidi_extradir = "Libs/Fribidi/extra/"
libFribidi_origdir = "Libs/Fribidi/orig/"
libFribidi_srcdir = libFribidi_origdir
libFribidi_incdir = libFribidi_origdir

-- Includes
libFribidi_includedirs = {
    libFribidi_incdir
}

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
    libFribidi_srcdir .. "lib/fribidi-arabic.c",
    libFribidi_srcdir .. "lib/fribidi-bidi.c",
    libFribidi_srcdir .. "lib/fribidi-bidi-types.c",
    libFribidi_srcdir .. "lib/fribidi-brackets.c",
    libFribidi_srcdir .. "lib/fribidi.c",
    libFribidi_srcdir .. "lib/fribidi-char-sets.c",
    libFribidi_srcdir .. "lib/fribidi-char-sets-cap-rtl.c",
    libFribidi_srcdir .. "lib/fribidi-char-sets-cp1255.c",
    libFribidi_srcdir .. "lib/fribidi-char-sets-cp1256.c",
    libFribidi_srcdir .. "lib/fribidi-char-sets-iso8859-6.c",
    libFribidi_srcdir .. "lib/fribidi-char-sets-iso8859-8.c",
    libFribidi_srcdir .. "lib/fribidi-char-sets-utf8.c",
    libFribidi_srcdir .. "lib/fribidi-deprecated.c",
    libFribidi_srcdir .. "lib/fribidi-joining.c",
    libFribidi_srcdir .. "lib/fribidi-joining-types.c",
    libFribidi_srcdir .. "lib/fribidi-mirroring.c",
    libFribidi_srcdir .. "lib/fribidi-run.c",
    libFribidi_srcdir .. "lib/fribidi-shape.c",
}
