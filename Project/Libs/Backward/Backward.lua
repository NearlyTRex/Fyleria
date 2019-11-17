-- Configuration
libBackwardCPP_extradir = "Libs/BackwardCPP/extra/"
libBackwardCPP_origdir = "Libs/BackwardCPP/orig/"
libBackwardCPP_srcdir = libBackwardCPP_origdir
libBackwardCPP_incdir = libBackwardCPP_origdir

-- Includes
libBackwardCPP_includedirs = {
    libBackwardCPP_incdir
}

-- Defines
libBackwardCPP_defines = {
}
libBackwardCPP_debugdefines = {
}
libBackwardCPP_releasedefines = {
}
if os.host() == "linux" then
    table.insert(libBackwardCPP_defines, "BACKWARD_HAS_DW=1")
    table.insert(libBackwardCPP_defines, "BACKWARD_HAS_UNWIND=1")
end

-- Options
libBackwardCPP_buildoptions = {
}
libBackwardCPP_linkoptions = {
}

-- Libs
libBackwardCPP_libs = {
}

-- Sources
libBackwardCPP_sources = {
    libBackwardCPP_srcdir .. "backward.cpp",
}
