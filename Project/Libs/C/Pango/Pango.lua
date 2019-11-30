-- Configuration
libPango_extradir = "Libs/C/Pango/extra/"
libPango_origdir = "Libs/C/Pango/orig/"
libPango_srcdir = libPango_origdir
libPango_incdir = libPango_origdir

-- Includes
libPango_includedirs = {
    libPango_incdir,
    libPango_incdir .. "pango/"
}
if os.host() == "linux" then
    table.insert(libPango_includedirs, libPango_extradir .. "linux/")
    table.insert(libPango_includedirs, libPango_extradir .. "linux/pango/")
end

-- Defines
libPango_defines = {
    "_FILE_OFFSET_BITS=64",
    "_POSIX_C_SOURCE=200809L",
    "_POSIX_THREAD_SAFE_FUNCTIONS",
    "_GNU_SOURCE",
    "G_LOG_DOMAIN=\"Pango\"",
    "G_LOG_USE_STRUCTURED=1",
    "PANGO_COMPILATION",
    "PANGO_DISABLE_DEPRECATION_WARNINGS",
    "SYSCONFDIR=\"sysconf\"",
    "LIBDIR=\"lib\""
}
libPango_debugdefines = {
    "PANGO_ENABLE_DEBUG"
}
libPango_releasedefines = {
}

-- Options
libPango_buildoptions = {
    "-fno-strict-aliasing"
}
libPango_linkoptions = {
}

-- Libs
libPango_libs = {
    "Fribidi"
}

-- Sources
libPango_sources = {
    libPango_srcdir .. "pango/break.c",
    libPango_srcdir .. "pango/ellipsize.c",
    libPango_srcdir .. "pango/fonts.c",
    libPango_srcdir .. "pango/glyphstring.c",
    libPango_srcdir .. "pango/modules.c",
    libPango_srcdir .. "pango/pango-attributes.c",
    libPango_srcdir .. "pango/pango-bidi-type.c",
    libPango_srcdir .. "pango/pangocairo-context.c",
    libPango_srcdir .. "pango/pangocairo-fcfont.c",
    libPango_srcdir .. "pango/pangocairo-fcfontmap.c",
    libPango_srcdir .. "pango/pangocairo-font.c",
    libPango_srcdir .. "pango/pangocairo-fontmap.c",
    libPango_srcdir .. "pango/pangocairo-render.c",
    libPango_srcdir .. "pango/pango-color.c",
    libPango_srcdir .. "pango/pango-context.c",
    libPango_srcdir .. "pango/pango-coverage.c",
    libPango_srcdir .. "pango/pango-emoji.c",
    libPango_srcdir .. "pango/pango-engine.c",
    libPango_srcdir .. "pango/pangofc-decoder.c",
    libPango_srcdir .. "pango/pangofc-font.c",
    libPango_srcdir .. "pango/pangofc-fontmap.c",
    libPango_srcdir .. "pango/pangofc-shape.c",
    libPango_srcdir .. "pango/pango-fontmap.c",
    libPango_srcdir .. "pango/pango-fontset.c",
    libPango_srcdir .. "pango/pangoft2.c",
    libPango_srcdir .. "pango/pangoft2-fontmap.c",
    libPango_srcdir .. "pango/pangoft2-render.c",
    libPango_srcdir .. "pango/pango-glyph-item.c",
    libPango_srcdir .. "pango/pango-gravity.c",
    libPango_srcdir .. "pango/pango-item.c",
    libPango_srcdir .. "pango/pango-language.c",
    libPango_srcdir .. "pango/pango-layout.c",
    libPango_srcdir .. "pango/pango-markup.c",
    libPango_srcdir .. "pango/pango-matrix.c",
    libPango_srcdir .. "pango/pango-ot-buffer.c",
    libPango_srcdir .. "pango/pango-ot-info.c",
    libPango_srcdir .. "pango/pango-ot-ruleset.c",
    libPango_srcdir .. "pango/pango-ot-tag.c",
    libPango_srcdir .. "pango/pango-renderer.c",
    libPango_srcdir .. "pango/pango-script.c",
    libPango_srcdir .. "pango/pango-tabs.c",
    libPango_srcdir .. "pango/pango-utils.c",
    libPango_srcdir .. "pango/reorder-items.c",
    libPango_srcdir .. "pango/shape.c"
}
if os.host() == "linux" then
    table.insert(libPango_sources, libPango_extradir .. "linux/pango/pango-enum-types.c")
end
