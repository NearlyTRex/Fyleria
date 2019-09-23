-- Configuration
libAtkCore_extradir = "Libs/AtkCore/extra/"
libAtkCore_origdir = "Libs/AtkCore/orig/"
libAtkCore_srcdir = libAtkCore_origdir
libAtkCore_incdir = libAtkCore_origdir

-- Includes
libAtkCore_includedirs = {
    libAtkCore_incdir
}
if os.host() == "linux" then
    table.insert(libAtkCore_includedirs, libAtkCore_extradir .. "linux/")
    table.insert(libAtkCore_includedirs, libAtkCore_extradir .. "linux/atspi/")
end

-- Defines
libAtkCore_defines = {
}
libAtkCore_debugdefines = {
}
libAtkCore_releasedefines = {
}

-- Options
libAtkCore_buildoptions = {
}
libAtkCore_linkoptions = {
}

-- Libs
libAtkCore_libs = {
}

-- Sources
libAtkCore_sources = {
    libAtkCore_srcdir .. "atspi/atspi-accessible.c",
    libAtkCore_srcdir .. "atspi/atspi-action.c",
    libAtkCore_srcdir .. "atspi/atspi-application.c",
    libAtkCore_srcdir .. "atspi/atspi-collection.c",
    libAtkCore_srcdir .. "atspi/atspi-component.c",
    libAtkCore_srcdir .. "atspi/atspi-device-listener.c",
    libAtkCore_srcdir .. "atspi/atspi-document.c",
    libAtkCore_srcdir .. "atspi/atspi-editabletext.c",
    libAtkCore_srcdir .. "atspi/atspi-event-listener.c",
    libAtkCore_srcdir .. "atspi/atspi-gmain.c",
    libAtkCore_srcdir .. "atspi/atspi-gmain.c",
    libAtkCore_srcdir .. "atspi/atspi-hyperlink.c",
    libAtkCore_srcdir .. "atspi/atspi-hypertext.c",
    libAtkCore_srcdir .. "atspi/atspi-image.c",
    libAtkCore_srcdir .. "atspi/atspi-matchrule.c",
    libAtkCore_srcdir .. "atspi/atspi-misc.c",
    libAtkCore_srcdir .. "atspi/atspi-mutter.c",
    libAtkCore_srcdir .. "atspi/atspi-object.c",
    libAtkCore_srcdir .. "atspi/atspi-registry.c",
    libAtkCore_srcdir .. "atspi/atspi-relation.c",
    libAtkCore_srcdir .. "atspi/atspi-selection.c",
    libAtkCore_srcdir .. "atspi/atspi-stateset.c",
    libAtkCore_srcdir .. "atspi/atspi-table.c",
    libAtkCore_srcdir .. "atspi/atspi-table-cell.c",
    libAtkCore_srcdir .. "atspi/atspi-text.c",
    libAtkCore_srcdir .. "atspi/atspi-value.c",
}
if os.host() == "linux" then
    table.insert(libAtkCore_sources, libAtkCore_extradir .. "linux/atspi/atspi-enum-types.c")
    table.insert(libAtkCore_sources, libAtkCore_extradir .. "linux/atspi/atspimarshal.c")
end
