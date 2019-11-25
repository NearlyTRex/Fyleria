-- Configuration
libHarfbuzz_extradir = "Libs/Harfbuzz/extra/"
libHarfbuzz_origdir = "Libs/Harfbuzz/orig/"
libHarfbuzz_srcdir = libHarfbuzz_origdir .. "src/"
libHarfbuzz_incdir = libHarfbuzz_origdir .. "src/"

-- Includes
libHarfbuzz_includedirs = {
    libHarfbuzz_incdir
}
if os.host() == "linux" then
    table.insert(libHarfbuzz_includedirs, libHarfbuzz_extradir .. "linux/")
end

-- Defines
libHarfbuzz_defines = {
    "HAVE_CONFIG_H"
}
libHarfbuzz_debugdefines = {
}
libHarfbuzz_releasedefines = {
}

-- Options
libHarfbuzz_buildoptions = {
    "-fno-rtti",
    "-fno-exceptions",
    "-fno-threadsafe-statics",
    "-fvisibility-inlines-hidden"
}
libHarfbuzz_linkoptions = {
}

-- Libs
libHarfbuzz_libs = {
    "Icu",
    "IcuData"
}

-- Sources
libHarfbuzz_sources = {
    libHarfbuzz_srcdir .. "hb-aat-layout.cc",
    libHarfbuzz_srcdir .. "hb-aat-map.cc",
    libHarfbuzz_srcdir .. "hb-blob.cc",
    libHarfbuzz_srcdir .. "hb-buffer-serialize.cc",
    libHarfbuzz_srcdir .. "hb-buffer.cc",
    libHarfbuzz_srcdir .. "hb-common.cc",
    libHarfbuzz_srcdir .. "hb-face.cc",
    libHarfbuzz_srcdir .. "hb-fallback-shape.cc",
    libHarfbuzz_srcdir .. "hb-font.cc",
    libHarfbuzz_srcdir .. "hb-icu.cc",
    libHarfbuzz_srcdir .. "hb-map.cc",
    libHarfbuzz_srcdir .. "hb-ot-cff1-table.cc",
    libHarfbuzz_srcdir .. "hb-ot-cff2-table.cc",
    libHarfbuzz_srcdir .. "hb-ot-color.cc",
    libHarfbuzz_srcdir .. "hb-ot-face.cc",
    libHarfbuzz_srcdir .. "hb-ot-font.cc",
    libHarfbuzz_srcdir .. "hb-ot-layout.cc",
    libHarfbuzz_srcdir .. "hb-ot-map.cc",
    libHarfbuzz_srcdir .. "hb-ot-math.cc",
    libHarfbuzz_srcdir .. "hb-ot-meta.cc",
    libHarfbuzz_srcdir .. "hb-ot-metrics.cc",
    libHarfbuzz_srcdir .. "hb-ot-name.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-arabic.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-default.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-hangul.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-hebrew.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-indic-table.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-indic.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-khmer.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-myanmar.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-thai.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-use-table.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-use.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-complex-vowel-constraints.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-fallback.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape-normalize.cc",
    libHarfbuzz_srcdir .. "hb-ot-shape.cc",
    libHarfbuzz_srcdir .. "hb-ot-tag.cc",
    libHarfbuzz_srcdir .. "hb-ot-var.cc",
    libHarfbuzz_srcdir .. "hb-set.cc",
    libHarfbuzz_srcdir .. "hb-shape-plan.cc",
    libHarfbuzz_srcdir .. "hb-shape.cc",
    libHarfbuzz_srcdir .. "hb-shaper.cc",
    libHarfbuzz_srcdir .. "hb-static.cc",
    libHarfbuzz_srcdir .. "hb-ucd.cc",
    libHarfbuzz_srcdir .. "hb-unicode.cc",
    libHarfbuzz_srcdir .. "hb-warning.cc",
    libHarfbuzz_srcdir .. "hb-glib.cc",
    libHarfbuzz_srcdir .. "hb-ft.cc"
}
