-- Configuration
libJpeg_extradir = "Libs/C/Jpeg/extra/"
libJpeg_origdir = "Libs/C/Jpeg/orig/"
libJpeg_srcdir = libJpeg_origdir
libJpeg_incdir = libJpeg_origdir

-- Includes
libJpeg_includedirs = {
    libJpeg_incdir
}
if os.host() == "linux" then
    table.insert(libJpeg_includedirs, libJpeg_extradir .. "linux/")
end

-- Defines
libJpeg_defines = {
}
libJpeg_debugdefines = {
}
libJpeg_releasedefines = {
}

-- Options
libJpeg_buildoptions = {
}
libJpeg_linkoptions = {
}

-- Libs
libJpeg_libs = {
}

-- Sources
libJpeg_sources = {
    libJpeg_srcdir .. "jaricom.c",
    libJpeg_srcdir .. "jcapimin.c",
    libJpeg_srcdir .. "jcapistd.c",
    libJpeg_srcdir .. "jcarith.c",
    libJpeg_srcdir .. "jccoefct.c",
    libJpeg_srcdir .. "jccolor.c",
    libJpeg_srcdir .. "jcdctmgr.c",
    libJpeg_srcdir .. "jchuff.c",
    libJpeg_srcdir .. "jcinit.c",
    libJpeg_srcdir .. "jcmainct.c",
    libJpeg_srcdir .. "jcmarker.c",
    libJpeg_srcdir .. "jcmaster.c",
    libJpeg_srcdir .. "jcomapi.c",
    libJpeg_srcdir .. "jcparam.c",
    libJpeg_srcdir .. "jcprepct.c",
    libJpeg_srcdir .. "jcsample.c",
    libJpeg_srcdir .. "jctrans.c",
    libJpeg_srcdir .. "jdapimin.c",
    libJpeg_srcdir .. "jdapistd.c",
    libJpeg_srcdir .. "jdarith.c",
    libJpeg_srcdir .. "jdatadst.c",
    libJpeg_srcdir .. "jdatasrc.c",
    libJpeg_srcdir .. "jdcoefct.c",
    libJpeg_srcdir .. "jdcolor.c",
    libJpeg_srcdir .. "jddctmgr.c",
    libJpeg_srcdir .. "jdhuff.c",
    libJpeg_srcdir .. "jdinput.c",
    libJpeg_srcdir .. "jdmainct.c",
    libJpeg_srcdir .. "jdmarker.c",
    libJpeg_srcdir .. "jdmaster.c",
    libJpeg_srcdir .. "jdmerge.c",
    libJpeg_srcdir .. "jdpostct.c",
    libJpeg_srcdir .. "jdsample.c",
    libJpeg_srcdir .. "jdtrans.c",
    libJpeg_srcdir .. "jerror.c",
    libJpeg_srcdir .. "jfdctflt.c",
    libJpeg_srcdir .. "jfdctfst.c",
    libJpeg_srcdir .. "jfdctint.c",
    libJpeg_srcdir .. "jidctflt.c",
    libJpeg_srcdir .. "jidctfst.c",
    libJpeg_srcdir .. "jidctint.c",
    libJpeg_srcdir .. "jquant1.c",
    libJpeg_srcdir .. "jquant2.c",
    libJpeg_srcdir .. "jutils.c",
    libJpeg_srcdir .. "jmemmgr.c",
    libJpeg_srcdir .. "jmemnobs.c"
}
