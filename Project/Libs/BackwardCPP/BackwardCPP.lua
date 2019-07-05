-- Configuration
libBackwardCPP_extradir = "Libs/BackwardCPP/extra/"
libBackwardCPP_origdir = "Libs/BackwardCPP/orig/"
libBackwardCPP_srcdir = libBackwardCPP_origdir
libBackwardCPP_incdir = libBackwardCPP_origdir

-- Includes
libBackwardCPP_includedirs = {
    libBackwardCPP_incdir
}

-- Sources
libBackwardCPP_sources = {
    libBackwardCPP_srcdir .. "backward.cpp",
}

-- Defines
libBackwardCPP_defines = {
}
if os.host() == "linux" then
    table.insert(libBackwardCPP_defines, "BACKWARD_HAS_DW=1")
end

-- Libs
libBackwardCPP_libs = {
}
if os.host() == "linux" then
    table.insert(libBackwardCPP_libs, "dw")
end
