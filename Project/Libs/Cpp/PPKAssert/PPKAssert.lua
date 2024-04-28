-- Configuration
libPPKAssert_extradir = "Libs/Cpp/PPKAssert/extra/"
libPPKAssert_origdir = "Libs/Cpp/PPKAssert/orig/"
libPPKAssert_srcdir = libPPKAssert_origdir .. "src/"
libPPKAssert_incdir = libPPKAssert_origdir .. "include/"

-- Includes
libPPKAssert_includedirs = {
    libPPKAssert_srcdir
}

-- Defines
libPPKAssert_defines = {
}
libPPKAssert_debugdefines = {
}
libPPKAssert_releasedefines = {
}

-- Libs
libPPKAssert_libs = {
}

-- Options
libPPKAssert_buildoptions = {
}
libPPKAssert_linkoptions = {
}

-- Sources
libPPKAssert_sources = {
    libPPKAssert_srcdir .. "ppk_assert.cpp"
}
