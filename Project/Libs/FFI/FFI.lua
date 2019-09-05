-- Configuration
libFFI_extradir = "Libs/FFI/extra/"
libFFI_origdir = "Libs/FFI/orig/"
libFFI_srcdir = libFFI_origdir .. "src/"
libFFI_incdir = libFFI_origdir .. "include/"

-- Includes
libFFI_includedirs = {
    libFFI_incdir
}
if os.host() == "linux" then
    table.insert(libFFI_includedirs, libFFI_extradir .. "linux/")
end

-- Defines
libFFI_defines = {
}
libFFI_debugdefines = {
}
libFFI_releasedefines = {
}

-- Options
libFFI_buildoptions = {
}
libFFI_linkoptions = {
}

-- Sources
libFFI_sources = {
    libFFI_srcdir .. "types.c"
}
