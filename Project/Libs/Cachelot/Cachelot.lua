-- Configuration
libCachelot_extradir = "Libs/Cachelot/extra/"
libCachelot_origdir = "Libs/Cachelot/orig/"
libCachelot_srcdir = libCachelot_origdir .. "src/cachelot/"
libCachelot_incdir = libCachelot_origdir .. "src/"

-- Includes
libCachelot_includedirs = {
    libCachelot_incdir
}

-- Defines
libCachelot_defines = {
}
libCachelot_debugdefines = {
}
libCachelot_releasedefines = {
}

-- Sources
libCachelot_sources = {
    libCachelot_srcdir .. "**.cpp"
}
