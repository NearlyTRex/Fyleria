-- Configuration
libPCRE_extradir = "Libs/PCRE/extra/"
libPCRE_origdir = "Libs/PCRE/orig/"
libPCRE_srcdir = libPCRE_origdir
libPCRE_incdir = libPCRE_origdir

-- Includes
libPCRE_includedirs = {
    libPCRE_incdir
}
if os.host() == "linux" then
    table.insert(libPCRE_includedirs, libPCRE_extradir .. "linux/")
end

-- Defines
libPCRE_defines = {
}
libPCRE_debugdefines = {
}
libPCRE_releasedefines = {
}

-- Options
libPCRE_buildoptions = {
}
libPCRE_linkoptions = {
}

-- Sources
libPCRE_sources = {
    libPCRE_srcdir .. "pcre_config.c"
}
