-- Configuration
libXML2_extradir = "Libs/XML2/extra/"
libXML2_origdir = "Libs/XML2/orig/"
libXML2_srcdir = libXML2_origdir
libXML2_incdir = libXML2_origdir .. "include/"

-- Includes
libXML2_includedirs = {
    libXML2_incdir
}
if os.host() == "linux" then
    table.insert(libXML2_includedirs, libXML2_extradir .. "linux/")
end

-- Defines
libXML2_defines = {
    "HAVE_CONFIG_H",
    "LIBXML_STATIC"
}
libXML2_debugdefines = {
}
libXML2_releasedefines = {
}

-- Options
libXML2_buildoptions = {
    "-fno-exceptions"
}
libXML2_linkoptions = {
}

-- Libs
libXML2_libs = {
    "Icu",
    "IcuData",
    "Zlib"
}

-- Sources
libXML2_sources = {
    libXML2_srcdir .. "buf.c",
    libXML2_srcdir .. "c14n.c",
    libXML2_srcdir .. "catalog.c",
    libXML2_srcdir .. "chvalid.c",
    libXML2_srcdir .. "debugXML.c",
    libXML2_srcdir .. "dict.c",
    libXML2_srcdir .. "encoding.c",
    libXML2_srcdir .. "entities.c",
    libXML2_srcdir .. "error.c",
    libXML2_srcdir .. "globals.c",
    libXML2_srcdir .. "hash.c",
    libXML2_srcdir .. "HTMLparser.c",
    libXML2_srcdir .. "HTMLtree.c",
    libXML2_srcdir .. "legacy.c",
    libXML2_srcdir .. "list.c",
    libXML2_srcdir .. "nanoftp.c",
    libXML2_srcdir .. "nanohttp.c",
    libXML2_srcdir .. "parser.c",
    libXML2_srcdir .. "parserInternals.c",
    libXML2_srcdir .. "pattern.c",
    libXML2_srcdir .. "relaxng.c",
    libXML2_srcdir .. "SAX2.c",
    libXML2_srcdir .. "SAX.c",
    libXML2_srcdir .. "schematron.c",
    libXML2_srcdir .. "threads.c",
    libXML2_srcdir .. "tree.c",
    libXML2_srcdir .. "uri.c",
    libXML2_srcdir .. "valid.c",
    libXML2_srcdir .. "xinclude.c",
    libXML2_srcdir .. "xlink.c",
    libXML2_srcdir .. "xmlIO.c",
    libXML2_srcdir .. "xmllint.c",
    libXML2_srcdir .. "xmlmemory.c",
    libXML2_srcdir .. "xmlmodule.c",
    libXML2_srcdir .. "xmlreader.c",
    libXML2_srcdir .. "xmlregexp.c",
    libXML2_srcdir .. "xmlsave.c",
    libXML2_srcdir .. "xmlschemas.c",
    libXML2_srcdir .. "xmlschemastypes.c",
    libXML2_srcdir .. "xmlstring.c",
    libXML2_srcdir .. "xmlunicode.c",
    libXML2_srcdir .. "xmlwriter.c",
    libXML2_srcdir .. "xpath.c",
    libXML2_srcdir .. "xpointer.c",
    libXML2_srcdir .. "xzlib.c"
}
