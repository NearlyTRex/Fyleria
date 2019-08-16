-- Configuration
libCachelot_extradir = "Libs/Cachelot/extra/"
libCachelot_origdir = "Libs/Cachelot/orig/"
libCachelot_srcdir = libCachelot_origdir .. "src/cachelot/"
libCachelot_incdir = libCachelot_origdir .. "src/"

-- Includes
libCachelot_includedirs = {
    libCachelot_incdir,
    libCachelot_extradir
}

-- Defines
libCachelot_defines = {
    "HAVE_CONFIG_H"
}
libCachelot_debugdefines = {
}
libCachelot_releasedefines = {
}

-- Sources
libCachelot_sources = {
    libCachelot_srcdir .. "common.cpp",
    libCachelot_srcdir .. "item.cpp",
    libCachelot_srcdir .. "stats.cpp"
}
