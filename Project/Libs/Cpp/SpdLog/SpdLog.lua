-- Configuration
libSpdLog_extradir = "Libs/Cpp/SpdLog/extra/"
libSpdLog_origdir = "Libs/Cpp/SpdLog/orig/"
libSpdLog_srcdir = libSpdLog_origdir .. "src/"
libSpdLog_incdir = libSpdLog_origdir .. "include/"

-- Includes
libSpdLog_includedirs = {
    libSpdLog_incdir
}

-- Defines
libSpdLog_defines = {
    "SPDLOG_COMPILED_LIB"
}
libSpdLog_debugdefines = {
}
libSpdLog_releasedefines = {
}

-- Libs
libSpdLog_libs = {
}

-- Options
libSpdLog_buildoptions = {
}
libSpdLog_linkoptions = {
}

-- Sources
libSpdLog_sources = {
    libSpdLog_srcdir .. "**.cpp"
}
