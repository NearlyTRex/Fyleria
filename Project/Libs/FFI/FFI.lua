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
    "HAVE_CONFIG_H",
    "FFI_BUILDING"
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
    libFFI_srcdir .. "closures.c",
    libFFI_srcdir .. "java_raw_api.c",
    libFFI_srcdir .. "prep_cif.c",
    libFFI_srcdir .. "raw_api.c",
    libFFI_srcdir .. "types.c",
    libFFI_srcdir .. "x86/ffi.c",
    libFFI_srcdir .. "x86/ffi64.c",
    libFFI_srcdir .. "x86/ffiw64.c",
    libFFI_srcdir .. "x86/win64.S",
    libFFI_srcdir .. "x86/unix64.S",
}
