-- Configuration
libPSL_extradir = "Libs/PSL/extra/"
libPSL_origdir = "Libs/PSL/orig/"
libPSL_srcdir = libPSL_origdir .. "src/"
libPSL_incdir = libPSL_origdir .. "include/"

-- Includes
libPSL_includedirs = {
}
if os.host() == "linux" then
    table.insert(libPSL_includedirs, libPSL_extradir .. "linux/")
    table.insert(libPSL_includedirs, libPSL_extradir .. "linux/include/")
    table.insert(libPSL_includedirs, libPSL_extradir .. "linux/src/")
end

-- Defines
libPSL_defines = {
    "_FILE_OFFSET_BITS=64",
    "HAVE_CONFIG_H",
    "BUILDING_PSL",
    "PSL_STATIC",
    "PSL_DISTFILE=\"Project/Libs/PSL/extra/list/public_suffix_list.dat\"",
}
libPSL_debugdefines = {
}
libPSL_releasedefines = {
}

-- Options
libPSL_buildoptions = {
}
libPSL_linkoptions = {
}

-- Libs
libPSL_libs = {
}

-- Sources
libPSL_sources = {
    libPSL_srcdir .. "lookup_string_in_fixed_set.c",
    libPSL_srcdir .. "psl.c"
}
