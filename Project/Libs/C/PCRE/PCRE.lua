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
    "HAVE_CONFIG_H"
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

-- Libs
libPCRE_libs = {
}

-- Sources
libPCRE_sources = {
    libPCRE_srcdir .. "pcre_byte_order.c",
    libPCRE_srcdir .. "pcre_compile.c",
    libPCRE_srcdir .. "pcre_config.c",
    libPCRE_srcdir .. "pcre_dfa_exec.c",
    libPCRE_srcdir .. "pcre_exec.c",
    libPCRE_srcdir .. "pcre_fullinfo.c",
    libPCRE_srcdir .. "pcre_get.c",
    libPCRE_srcdir .. "pcre_globals.c",
    libPCRE_srcdir .. "pcre_jit_compile.c",
    libPCRE_srcdir .. "pcre_maketables.c",
    libPCRE_srcdir .. "pcre_newline.c",
    libPCRE_srcdir .. "pcre_ord2utf8.c",
    libPCRE_srcdir .. "pcre_refcount.c",
    libPCRE_srcdir .. "pcre_string_utils.c",
    libPCRE_srcdir .. "pcre_study.c",
    libPCRE_srcdir .. "pcre_tables.c",
    libPCRE_srcdir .. "pcre_ucd.c",
    libPCRE_srcdir .. "pcre_valid_utf8.c",
    libPCRE_srcdir .. "pcre_version.c",
    libPCRE_srcdir .. "pcre_xclass.c",
    libPCRE_extradir .. "pcre_chartables.c",
}
