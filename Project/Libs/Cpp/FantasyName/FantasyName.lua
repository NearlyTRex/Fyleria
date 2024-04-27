-- Configuration
libFantasyName_extradir = "Libs/Cpp/FantasyName/extra/"
libFantasyName_origdir = "Libs/Cpp/FantasyName/orig/"
libFantasyName_srcdir = libFantasyName_origdir .. "c++/"
libFantasyName_incdir = libFantasyName_origdir .. "c++/"

-- Includes
libFantasyName_includedirs = {
    libFantasyName_incdir
}

-- Defines
libFantasyName_defines = {
    "HAVE_CXX14"
}
libFantasyName_debugdefines = {
}
libFantasyName_releasedefines = {
}
if os.host() == "windows" then
    table.insert(libFantasyName_defines, "_CRT_SECURE_NO_WARNINGS")
end

-- Options
libFantasyName_buildoptions = {
}
libFantasyName_linkoptions = {
}

-- Libs
libFantasyName_libs = {
}

-- Sources
libFantasyName_sources = {
    libFantasyName_srcdir .. "namegen.cc",
}
