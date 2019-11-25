-- Configuration
libAtk_extradir = "Libs/Atk/extra/"
libAtk_origdir = "Libs/Atk/orig/"
libAtk_srcdir = libAtk_origdir
libAtk_incdir = libAtk_origdir

-- Includes
libAtk_includedirs = {
    libAtk_incdir,
    libAtk_incdir .. "atk/"
}
if os.host() == "linux" then
    table.insert(libAtk_includedirs, libAtk_extradir .. "linux/")
    table.insert(libAtk_includedirs, libAtk_extradir .. "linux/atk/")
end

-- Defines
libAtk_defines = {
    "_FILE_OFFSET_BITS=64",
    "G_DISABLE_SINGLE_INCLUDES",
    "ATK_DISABLE_SINGLE_INCLUDES",
    "G_LOG_DOMAIN=\"Atk\"",
    "G_LOG_USE_STRUCTURED=1",
    "GLIB_DISABLE_DEPRECATION_WARNINGS",
    "ATK_DISABLE_DEPRECATION_WARNINGS",
    "ATK_COMPILATION",
    "ATK_LOCALEDIR=\"locale\""
}
libAtk_debugdefines = {
}
libAtk_releasedefines = {
}

-- Options
libAtk_buildoptions = {
}
libAtk_linkoptions = {
}

-- Libs
libAtk_libs = {
}

-- Sources
libAtk_sources = {
    libAtk_srcdir .. "atk/atkaction.c",
    libAtk_srcdir .. "atk/atkcomponent.c",
    libAtk_srcdir .. "atk/atkdocument.c",
    libAtk_srcdir .. "atk/atkeditabletext.c",
    libAtk_srcdir .. "atk/atkgobjectaccessible.c",
    libAtk_srcdir .. "atk/atkhyperlink.c",
    libAtk_srcdir .. "atk/atkhyperlinkimpl.c",
    libAtk_srcdir .. "atk/atkhypertext.c",
    libAtk_srcdir .. "atk/atkimage.c",
    libAtk_srcdir .. "atk/atkmisc.c",
    libAtk_srcdir .. "atk/atknoopobject.c",
    libAtk_srcdir .. "atk/atknoopobjectfactory.c",
    libAtk_srcdir .. "atk/atkobject.c",
    libAtk_srcdir .. "atk/atkobjectfactory.c",
    libAtk_srcdir .. "atk/atkplug.c",
    libAtk_srcdir .. "atk/atkprivate.c",
    libAtk_srcdir .. "atk/atkrange.c",
    libAtk_srcdir .. "atk/atkregistry.c",
    libAtk_srcdir .. "atk/atkrelation.c",
    libAtk_srcdir .. "atk/atkrelationset.c",
    libAtk_srcdir .. "atk/atkselection.c",
    libAtk_srcdir .. "atk/atksocket.c",
    libAtk_srcdir .. "atk/atkstate.c",
    libAtk_srcdir .. "atk/atkstateset.c",
    libAtk_srcdir .. "atk/atkstreamablecontent.c",
    libAtk_srcdir .. "atk/atktable.c",
    libAtk_srcdir .. "atk/atktablecell.c",
    libAtk_srcdir .. "atk/atktext.c",
    libAtk_srcdir .. "atk/atkutil.c",
    libAtk_srcdir .. "atk/atkvalue.c",
    libAtk_srcdir .. "atk/atkversion.c",
    libAtk_srcdir .. "atk/atkwindow.c",
}
if os.host() == "linux" then
    table.insert(libAtk_sources, libAtk_extradir .. "linux/atk/atk-enum-types.c")
    table.insert(libAtk_sources, libAtk_extradir .. "linux/atk/atkmarshal.c")
end
