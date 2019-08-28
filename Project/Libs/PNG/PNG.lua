-- Configuration
libPNG_extradir = "Libs/PNG/extra/"
libPNG_origdir = "Libs/PNG/orig/"
libPNG_srcdir = libPNG_origdir
libPNG_incdir = libPNG_origdir

-- Includes
libPNG_includedirs = {
    libPNG_incdir
}
if os.host() == "linux" then
    table.insert(libPNG_includedirs, libPNG_extradir .. "linux/")
end

-- Defines
libPNG_defines = {
    "HAVE_CONFIG_H",
    "PIC"
}
libPNG_debugdefines = {
}
libPNG_releasedefines = {
}

-- Options
libPNG_buildoptions = {
}
libPNG_linkoptions = {
}

-- Sources
libPNG_sources = {
    libPNG_srcdir .. "png.c",
    libPNG_srcdir .. "pngerror.c",
    libPNG_srcdir .. "pngget.c",
    libPNG_srcdir .. "pngmem.c",
    libPNG_srcdir .. "pngpread.c",
    libPNG_srcdir .. "pngread.c",
    libPNG_srcdir .. "pngrio.c",
    libPNG_srcdir .. "pngrtran.c",
    libPNG_srcdir .. "pngrutil.c",
    libPNG_srcdir .. "pngset.c",
    libPNG_srcdir .. "pngtrans.c",
    libPNG_srcdir .. "pngwio.c",
    libPNG_srcdir .. "pngwrite.c",
    libPNG_srcdir .. "pngwtran.c",
    libPNG_srcdir .. "pngwutil.c",
    libPNG_srcdir .. "mips/mips_init.c",
    libPNG_srcdir .. "mips/filter_msa_intrinsics.c",
    libPNG_srcdir .. "intel/intel_init.c",
    libPNG_srcdir .. "intel/filter_sse2_intrinsics.c",
    libPNG_srcdir .. "powerpc/powerpc_init.c",
    libPNG_srcdir .. "powerpc/filter_vsx_intrinsics.c"
}
