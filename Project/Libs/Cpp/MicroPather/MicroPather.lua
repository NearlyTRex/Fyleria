-- Configuration
libMicroPather_extradir = "Libs/Cpp/MicroPather/extra/"
libMicroPather_origdir = "Libs/Cpp/MicroPather/orig/"
libMicroPather_srcdir = libMicroPather_origdir
libMicroPather_incdir = libMicroPather_origdir

-- Includes
libMicroPather_includedirs = {
    libMicroPather_incdir
}

-- Defines
libMicroPather_defines = {
}
libMicroPather_debugdefines = {
    "DEBUG"
}
libMicroPather_releasedefines = {
}

-- Libs
libMicroPather_libs = {
}

-- Options
libMicroPather_buildoptions = {
}
libMicroPather_linkoptions = {
}

-- Sources
libMicroPather_sources = {
    libMicroPather_srcdir .. "micropather.cpp"
}
