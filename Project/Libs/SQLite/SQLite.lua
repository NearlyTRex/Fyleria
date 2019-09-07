-- Configuration
libSQLite_extradir = "Libs/SQLite/extra/"
libSQLite_origdir = "Libs/SQLite/orig/"
libSQLite_srcdir = libSQLite_origdir
libSQLite_incdir = libSQLite_origdir

-- Includes
libSQLite_includedirs = {
    libSQLite_extradir
}
if os.host() == "linux" then
    table.insert(libSQLite_includedirs, libSQLite_extradir .. "linux/")
end

-- Defines
libSQLite_defines = {
    "_HAVE_SQLITE_CONFIG_H",
    "BUILD_sqlite",
    "SQLITE_THREADSAFE",
    "SQLITE_ENABLE_JSON1",
    "SQLITE_HAVE_ZLIB",
    "SQLITE_TEMP_STORE"
}
libSQLite_debugdefines = {
}
libSQLite_releasedefines = {
    "NDEBUG"
}
if os.host() == "linux" then
    table.insert(libSQLite_defines, "SQLITE_OS_UNIX")
end

-- Options
libSQLite_buildoptions = {
}
libSQLite_linkoptions = {
}

-- Sources
libSQLite_sources = {
    libSQLite_extradir .. "sqlite3.c"
}
