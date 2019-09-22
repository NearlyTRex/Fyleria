-- Configuration
libGPGError_extradir = "Libs/GPGError/extra/"
libGPGError_origdir = "Libs/GPGError/orig/"
libGPGError_srcdir = libGPGError_origdir .. "src/"
libGPGError_incdir = libGPGError_origdir .. "src"

-- Includes
libGPGError_includedirs = {
    libGPGError_incdir
}
if os.host() == "linux" then
    table.insert(libGPGError_includedirs, libGPGError_extradir .. "linux/")
    table.insert(libGPGError_includedirs, libGPGError_extradir .. "linux/src/")
end

-- Defines
libGPGError_defines = {
    "HAVE_CONFIG_H",
    "LOCALEDIR=\"locale\""
}
libGPGError_debugdefines = {
}
libGPGError_releasedefines = {
}

-- Options
libGPGError_buildoptions = {
}
libGPGError_linkoptions = {
}

-- Libs
libGPGError_libs = {
}

-- Sources
libGPGError_sources = {
    libGPGError_srcdir .. "argparse.c",
    libGPGError_srcdir .. "b64dec.c",
    libGPGError_srcdir .. "b64enc.c",
    libGPGError_srcdir .. "code-from-errno.c",
    libGPGError_srcdir .. "code-to-errno.c",
    libGPGError_srcdir .. "estream.c",
    libGPGError_srcdir .. "estream-printf.c",
    libGPGError_srcdir .. "gpg-error.c",
    libGPGError_srcdir .. "init.c",
    libGPGError_srcdir .. "logging.c",
    libGPGError_srcdir .. "posix-lock.c",
    libGPGError_srcdir .. "posix-thread.c",
    libGPGError_srcdir .. "spawn-posix.c",
    libGPGError_srcdir .. "strerror.c",
    libGPGError_srcdir .. "strerror-sym.c",
    libGPGError_srcdir .. "strsource.c",
    libGPGError_srcdir .. "strsource-sym.c",
    libGPGError_srcdir .. "syscall-clamp.c",
    libGPGError_srcdir .. "sysutils.c",
    libGPGError_srcdir .. "version.c",
    libGPGError_srcdir .. "visibility.c",
}
