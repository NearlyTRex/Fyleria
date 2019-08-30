-- Configuration
libJpegTurbo_extradir = "Libs/JpegTurbo/extra/"
libJpegTurbo_origdir = "Libs/JpegTurbo/orig/"
libJpegTurbo_srcdir = libJpegTurbo_origdir
libJpegTurbo_incdir = libJpegTurbo_origdir

-- Includes
libJpegTurbo_includedirs = {
    libJpegTurbo_incdir,
}

-- Defines
libJpegTurbo_defines = {
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
    libJpegTurbo_srcdir .. "wrppm.c"

}
