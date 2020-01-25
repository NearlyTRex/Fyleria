-- Configuration
libBackward_extradir = "Libs/Cpp/Backward/extra/"
libBackward_origdir = "Libs/Cpp/Backward/orig/"
libBackward_srcdir = libBackward_origdir
libBackward_incdir = libBackward_origdir

-- Includes
libBackward_includedirs = {
    libBackward_incdir
}

-- Defines
libBackward_defines = {
}
libBackward_debugdefines = {
}
libBackward_releasedefines = {
}
if os.host() == "linux" then
    table.insert(libBackward_defines, "BACKWARD_HAS_DW=1")
    table.insert(libBackward_defines, "BACKWARD_HAS_UNWIND=1")
end

-- Options
libBackward_buildoptions = {
}
libBackward_linkoptions = {
}

-- Libs
libBackward_libs = {
}

-- Sources
libBackward_sources = {
    libBackward_srcdir .. "backward.cpp",
}
