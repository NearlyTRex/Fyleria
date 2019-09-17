-- Configuration
libJpegTurbo_extradir = "Libs/JpegTurbo/extra/"
libJpegTurbo_origdir = "Libs/JpegTurbo/orig/"
libJpegTurbo_srcdir = libJpegTurbo_origdir
libJpegTurbo_incdir = libJpegTurbo_origdir

-- Includes
libJpegTurbo_includedirs = {
    libJpegTurbo_incdir
}
if os.host() == "linux" then
    table.insert(libJpegTurbo_includedirs, libJpegTurbo_extradir .. "linux/")
end

-- Assembly
libJpegTurbo_asm_def = "-DBMP_SUPPORTED -DPPM_SUPPORTED "
libJpegTurbo_asm_inc_x86_64 =
    "-I ../" .. libJpegTurbo_incdir .. "simd/nasm/ " ..
    "-I ../" .. libJpegTurbo_incdir .. "simd/x86_64/ "
libJpegTurbo_asm_inc_linux = "-I ../" .. libJpegTurbo_extradir .. "linux/ "

-- Defines
libJpegTurbo_defines = {
    "BMP_SUPPORTED",
    "PPM_SUPPORTED"
}
libJpegTurbo_debugdefines = {
}
libJpegTurbo_releasedefines = {
}

-- Options
libJpegTurbo_buildoptions = {
}
libJpegTurbo_linkoptions = {
}

-- Libs
libJpegTurbo_libs = {
}

-- Sources
libJpegTurbo_sources = {
    libJpegTurbo_srcdir .. "jcapimin.c",
    libJpegTurbo_srcdir .. "jcapistd.c",
    libJpegTurbo_srcdir .. "jccoefct.c",
    libJpegTurbo_srcdir .. "jccolor.c",
    libJpegTurbo_srcdir .. "jcdctmgr.c",
    libJpegTurbo_srcdir .. "jchuff.c",
    libJpegTurbo_srcdir .. "jcicc.c",
    libJpegTurbo_srcdir .. "jcinit.c",
    libJpegTurbo_srcdir .. "jcmainct.c",
    libJpegTurbo_srcdir .. "jcmarker.c",
    libJpegTurbo_srcdir .. "jcmaster.c",
    libJpegTurbo_srcdir .. "jcomapi.c",
    libJpegTurbo_srcdir .. "jcparam.c",
    libJpegTurbo_srcdir .. "jcphuff.c",
    libJpegTurbo_srcdir .. "jcprepct.c",
    libJpegTurbo_srcdir .. "jcsample.c",
    libJpegTurbo_srcdir .. "jctrans.c",
    libJpegTurbo_srcdir .. "jdapimin.c",
    libJpegTurbo_srcdir .. "jdapistd.c",
    libJpegTurbo_srcdir .. "jdatadst.c",
    libJpegTurbo_srcdir .. "jdatasrc.c",
    libJpegTurbo_srcdir .. "jdcoefct.c",
    libJpegTurbo_srcdir .. "jdcolor.c",
    libJpegTurbo_srcdir .. "jddctmgr.c",
    libJpegTurbo_srcdir .. "jdhuff.c",
    libJpegTurbo_srcdir .. "jdicc.c",
    libJpegTurbo_srcdir .. "jdinput.c",
    libJpegTurbo_srcdir .. "jdmainct.c",
    libJpegTurbo_srcdir .. "jdmarker.c",
    libJpegTurbo_srcdir .. "jdmaster.c",
    libJpegTurbo_srcdir .. "jdmerge.c",
    libJpegTurbo_srcdir .. "jdphuff.c",
    libJpegTurbo_srcdir .. "jdpostct.c",
    libJpegTurbo_srcdir .. "jdsample.c",
    libJpegTurbo_srcdir .. "jdtrans.c",
    libJpegTurbo_srcdir .. "jerror.c",
    libJpegTurbo_srcdir .. "jfdctflt.c",
    libJpegTurbo_srcdir .. "jfdctfst.c",
    libJpegTurbo_srcdir .. "jfdctint.c",
    libJpegTurbo_srcdir .. "jidctflt.c",
    libJpegTurbo_srcdir .. "jidctfst.c",
    libJpegTurbo_srcdir .. "jidctint.c",
    libJpegTurbo_srcdir .. "jidctred.c",
    libJpegTurbo_srcdir .. "jquant1.c",
    libJpegTurbo_srcdir .. "jquant2.c",
    libJpegTurbo_srcdir .. "jutils.c",
    libJpegTurbo_srcdir .. "jmemmgr.c",
    libJpegTurbo_srcdir .. "jmemnobs.c",
    libJpegTurbo_srcdir .. "jaricom.c",
    libJpegTurbo_srcdir .. "jcarith.c",
    libJpegTurbo_srcdir .. "jdarith.c",
    libJpegTurbo_srcdir .. "turbojpeg.c",
    libJpegTurbo_srcdir .. "transupp.c",
    libJpegTurbo_srcdir .. "jdatadst-tj.c",
    libJpegTurbo_srcdir .. "jdatasrc-tj.c",
    libJpegTurbo_srcdir .. "rdbmp.c",
    libJpegTurbo_srcdir .. "rdppm.c",
    libJpegTurbo_srcdir .. "wrbmp.c",
    libJpegTurbo_srcdir .. "wrppm.c",
}
libJpegTurbo_sources_x86_64 = {
    libJpegTurbo_srcdir .. "simd/x86_64/jsimd.c",
    libJpegTurbo_srcdir .. "simd/x86_64/jsimdcpu.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jfdctflt-sse.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jccolor-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jcgray-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jchuff-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jcphuff-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jcsample-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jdcolor-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jdmerge-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jdsample-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jfdctfst-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jfdctint-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jidctflt-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jidctfst-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jidctint-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jidctred-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jquantf-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jquanti-sse2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jccolor-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jcgray-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jcsample-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jdcolor-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jdmerge-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jdsample-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jfdctint-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jidctint-avx2.asm",
    libJpegTurbo_srcdir .. "simd/x86_64/jquanti-avx2.asm"
}
