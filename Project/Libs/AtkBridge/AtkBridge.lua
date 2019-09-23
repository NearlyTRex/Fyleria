-- Configuration
libAtkBridge_extradir = "Libs/AtkBridge/extra/"
libAtkBridge_origdir = "Libs/AtkBridge/orig/"
libAtkBridge_srcdir = libAtkBridge_origdir
libAtkBridge_incdir = libAtkBridge_origdir

-- Includes
libAtkBridge_includedirs = {
    libAtkBridge_incdir,
    libAtkBridge_incdir .. "atk-adaptor/",
    libAtkBridge_incdir .. "atk-adaptor/adaptors/",
}
if os.host() == "linux" then
    table.insert(libAtkBridge_includedirs, "/usr/include/dbus-1.0/")
    table.insert(libAtkBridge_includedirs, "/usr/lib/x86_64-linux-gnu/dbus-1.0/include/")
    table.insert(libAtkBridge_includedirs, libAtkBridge_extradir .. "linux/")
end

-- Defines
libAtkBridge_defines = {
    "_FILE_OFFSET_BITS=64",
    "_DEFAULT_SOURCE",
    "ATK_DISABLE_DEPRECATION_WARNINGS"
}
libAtkBridge_debugdefines = {
}
libAtkBridge_releasedefines = {
}

-- Options
libAtkBridge_buildoptions = {
}
libAtkBridge_linkoptions = {
}

-- Libs
libAtkBridge_libs = {
}

-- Sources
libAtkBridge_sources = {
    libAtkBridge_srcdir .. "atk-adaptor/accessible-cache.c",
    libAtkBridge_srcdir .. "atk-adaptor/accessible-leasing.c",
    libAtkBridge_srcdir .. "atk-adaptor/accessible-register.c",
    libAtkBridge_srcdir .. "atk-adaptor/accessible-stateset.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/accessible-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/action-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/application-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/cache-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/collection-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/component-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/document-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/editabletext-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/hyperlink-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/hypertext-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/image-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/selection-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/socket-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/table-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/table-cell-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/text-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/adaptors/value-adaptor.c",
    libAtkBridge_srcdir .. "atk-adaptor/bridge.c",
    libAtkBridge_srcdir .. "atk-adaptor/event.c",
    libAtkBridge_srcdir .. "atk-adaptor/gtk-2.0/module.c",
    libAtkBridge_srcdir .. "atk-adaptor/introspection.c",
    libAtkBridge_srcdir .. "atk-adaptor/object.c",
    libAtkBridge_srcdir .. "atk-adaptor/spi-dbus.c",
    libAtkBridge_srcdir .. "droute/droute.c",
    libAtkBridge_srcdir .. "droute/droute-pairhash.c",
    libAtkBridge_srcdir .. "droute/droute-test.c",
    libAtkBridge_srcdir .. "droute/droute-variant.c",
}
