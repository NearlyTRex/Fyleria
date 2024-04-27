-- Configuration
libCJSMin_extradir = "Libs/C/CJSMin/extra/"
libCJSMin_origdir = "Libs/C/CJSMin/orig/"
libCJSMin_srcdir = libCJSMin_origdir
libCJSMin_incdir = libCJSMin_origdir

-- Includes
libCJSMin_includedirs = {
    libCJSMin_incdir,
    libCJSMin_extradir
}

-- Defines
libCJSMin_defines = {
}
libCJSMin_debugdefines = {
}
libCJSMin_releasedefines = {
}

-- Options
libCJSMin_buildoptions = {
}
libCJSMin_linkoptions = {
}

-- Libs
libCJSMin_libs = {
}

-- Sources
libCJSMin_sources = {
    libCJSMin_srcdir .. "jsmin.c"
}
