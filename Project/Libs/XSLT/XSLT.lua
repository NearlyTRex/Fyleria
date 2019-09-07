-- Configuration
libXSLT_extradir = "Libs/XSLT/extra/"
libXSLT_origdir = "Libs/XSLT/orig/"
libXSLT_srcdir = libXSLT_origdir .. "libxslt/"
libXSLT_incdir = libXSLT_origdir .. "libxslt/"

-- Includes
libXSLT_includedirs = {
    libXSLT_incdir
}
if os.host() == "linux" then
    table.insert(libXSLT_includedirs, libXSLT_extradir .. "linux/")
end

-- Defines
libXSLT_defines = {
    "HAVE_CONFIG_H",
    "LIBXSLT_STATIC"
}
libXSLT_debugdefines = {
}
libXSLT_releasedefines = {
}

-- Options
libXSLT_buildoptions = {
}
libXSLT_linkoptions = {
}

-- Sources
libXSLT_sources = {
    libXSLT_srcdir .. "attributes.c",
    libXSLT_srcdir .. "attrvt.c",
    libXSLT_srcdir .. "documents.c",
    libXSLT_srcdir .. "extensions.c",
    libXSLT_srcdir .. "extra.c",
    libXSLT_srcdir .. "functions.c",
    libXSLT_srcdir .. "imports.c",
    libXSLT_srcdir .. "keys.c",
    libXSLT_srcdir .. "namespaces.c",
    libXSLT_srcdir .. "numbers.c",
    libXSLT_srcdir .. "pattern.c",
    libXSLT_srcdir .. "preproc.c",
    libXSLT_srcdir .. "security.c",
    libXSLT_srcdir .. "templates.c",
    libXSLT_srcdir .. "transform.c",
    libXSLT_srcdir .. "variables.c",
    libXSLT_srcdir .. "xslt.c",
    libXSLT_srcdir .. "xsltlocale.c",
    libXSLT_srcdir .. "xsltutils.c"
}
