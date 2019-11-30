-- Configuration
libPixman_extradir = "Libs/C/Pixman/extra/"
libPixman_origdir = "Libs/C/Pixman/orig/"
libPixman_srcdir = libPixman_origdir .. "pixman/"
libPixman_incdir = libPixman_origdir .. "pixman/"

-- Includes
libPixman_includedirs = {
    libPixman_incdir
}
if os.host() == "linux" then
    table.insert(libPixman_includedirs, libPixman_extradir .. "linux/")
end

-- Defines
libPixman_defines = {
    "HAVE_CONFIG_H"
}
libPixman_debugdefines = {
}
libPixman_releasedefines = {
}

-- Options
libPixman_buildoptions = {
}
libPixman_linkoptions = {
}
if os.host() == "linux" then
    table.insert(libPixman_buildoptions, "-mssse3")
end

-- Libs
libPixman_libs = {
}

-- Sources
libPixman_sources = {
    libPixman_srcdir .. "pixman.c",
    libPixman_srcdir .. "pixman-access-accessors.c",
    libPixman_srcdir .. "pixman-access.c",
    libPixman_srcdir .. "pixman-arm.c",
    libPixman_srcdir .. "pixman-bits-image.c",
    libPixman_srcdir .. "pixman-combine32.c",
    libPixman_srcdir .. "pixman-combine-float.c",
    libPixman_srcdir .. "pixman-conical-gradient.c",
    libPixman_srcdir .. "pixman-edge-accessors.c",
    libPixman_srcdir .. "pixman-edge.c",
    libPixman_srcdir .. "pixman-fast-path.c",
    libPixman_srcdir .. "pixman-filter.c",
    libPixman_srcdir .. "pixman-general.c",
    libPixman_srcdir .. "pixman-glyph.c",
    libPixman_srcdir .. "pixman-gradient-walker.c",
    libPixman_srcdir .. "pixman-image.c",
    libPixman_srcdir .. "pixman-implementation.c",
    libPixman_srcdir .. "pixman-linear-gradient.c",
    libPixman_srcdir .. "pixman-matrix.c",
    libPixman_srcdir .. "pixman-mmx.c",
    libPixman_srcdir .. "pixman-mips.c",
    libPixman_srcdir .. "pixman-noop.c",
    libPixman_srcdir .. "pixman-ppc.c",
    libPixman_srcdir .. "pixman-radial-gradient.c",
    libPixman_srcdir .. "pixman-region16.c",
    libPixman_srcdir .. "pixman-region32.c",
    libPixman_srcdir .. "pixman-solid-fill.c",
    libPixman_srcdir .. "pixman-sse2.c",
    libPixman_srcdir .. "pixman-ssse3.c",
    libPixman_srcdir .. "pixman-timer.c",
    libPixman_srcdir .. "pixman-trap.c",
    libPixman_srcdir .. "pixman-utils.c",
    libPixman_srcdir .. "pixman-x86.c",
}
