-- Configuration
libBetterEnums_extradir = "Libs/Cpp/BetterEnums/extra/"
libBetterEnums_origdir = "Libs/Cpp/BetterEnums/orig/"
libBetterEnums_srcdir = libBetterEnums_origdir
libBetterEnums_incdir = libBetterEnums_origdir

-- Includes
libBetterEnums_includedirs = {
    libBetterEnums_incdir,
    libBetterEnums_extradir
}

-- Defines
libBetterEnums_defines = {
    "BETTER_ENUMS_MACRO_FILE=\"enum_macros.h\""
}
libBetterEnums_debugdefines = {
}
libBetterEnums_releasedefines = {
}

-- Options
libBetterEnums_buildoptions = {
}
libBetterEnums_linkoptions = {
}

-- Libs
libBetterEnums_libs = {
}
