-- Configuration
libGraphene_extradir = "Libs/Graphene/extra/"
libGraphene_origdir = "Libs/Graphene/orig/"
libGraphene_srcdir = libGraphene_origdir .. "src/"
libGraphene_incdir = libGraphene_origdir .. "include/"

-- Includes
libGraphene_includedirs = {
    libGraphene_incdir
}
if os.host() == "linux" then
    table.insert(libGraphene_includedirs, libGraphene_extradir .. "linux/")
    table.insert(libGraphene_includedirs, libGraphene_extradir .. "linux/include/")
    table.insert(libGraphene_includedirs, libGraphene_extradir .. "linux/src/")
end

-- Defines
libGraphene_defines = {
    "_FILE_OFFSET_BITS=64",
    "_GNU_SOURCE",
    "GRAPHENE_COMPILATION"
}
libGraphene_debugdefines = {
    "GRAPHENE_ENABLE_DEBUG"
}
libGraphene_releasedefines = {
}

-- Options
libGraphene_buildoptions = {
    "-ffast-math",
    "-fstrict-aliasing",
    "-mfpmath=sse",
    "-msse",
    "-msse2"
}
libGraphene_linkoptions = {
}

-- Libs
libGraphene_libs = {
}

-- Sources
libGraphene_sources = {
    libGraphene_srcdir .. "graphene-alloc.c",
    libGraphene_srcdir .. "graphene-box.c",
    libGraphene_srcdir .. "graphene-euler.c",
    libGraphene_srcdir .. "graphene-frustum.c",
    libGraphene_srcdir .. "graphene-gobject.c",
    libGraphene_srcdir .. "graphene-matrix.c",
    libGraphene_srcdir .. "graphene-plane.c",
    libGraphene_srcdir .. "graphene-point3d.c",
    libGraphene_srcdir .. "graphene-point.c",
    libGraphene_srcdir .. "graphene-quad.c",
    libGraphene_srcdir .. "graphene-quaternion.c",
    libGraphene_srcdir .. "graphene-ray.c",
    libGraphene_srcdir .. "graphene-rect.c",
    libGraphene_srcdir .. "graphene-simd4f.c",
    libGraphene_srcdir .. "graphene-simd4x4f.c",
    libGraphene_srcdir .. "graphene-size.c",
    libGraphene_srcdir .. "graphene-sphere.c",
    libGraphene_srcdir .. "graphene-triangle.c",
    libGraphene_srcdir .. "graphene-vectors.c",
}
