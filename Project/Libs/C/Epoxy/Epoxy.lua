-- Configuration
libEpoxy_extradir = "Libs/Epoxy/extra/"
libEpoxy_origdir = "Libs/Epoxy/orig/"
libEpoxy_srcdir = libEpoxy_origdir .. "src/"
libEpoxy_incdir = libEpoxy_origdir .. "include/"

-- Includes
libEpoxy_includedirs = {
    libEpoxy_incdir,
    libEpoxy_srcdir
}
if os.host() == "linux" then
    table.insert(libEpoxy_includedirs, libEpoxy_extradir .. "linux/")
    table.insert(libEpoxy_includedirs, libEpoxy_extradir .. "linux/include/")
    table.insert(libEpoxy_includedirs, libEpoxy_extradir .. "linux/src/")
end

-- Defines
libEpoxy_defines = {
    "_FILE_OFFSET_BITS=64"
}
libEpoxy_debugdefines = {
}
libEpoxy_releasedefines = {
}

-- Options
libEpoxy_buildoptions = {
    "-fno-strict-aliasing"
}
libEpoxy_linkoptions = {
}

-- Libs
libEpoxy_libs = {
}

-- Sources
libEpoxy_sources = {
    libEpoxy_srcdir .. "dispatch_common.c",
    libEpoxy_srcdir .. "dispatch_egl.c",
    libEpoxy_srcdir .. "dispatch_glx.c"
}
if os.host() == "linux" then
    table.insert(libEpoxy_sources, libEpoxy_extradir .. "linux/src/egl_generated_dispatch.c")
    table.insert(libEpoxy_sources, libEpoxy_extradir .. "linux/src/gl_generated_dispatch.c")
    table.insert(libEpoxy_sources, libEpoxy_extradir .. "linux/src/glx_generated_dispatch.c")
end
