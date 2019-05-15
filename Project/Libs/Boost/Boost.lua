-- Configuration
libBoost_extradir = "Libs/Boost/extra/"
libBoost_origdir = "Libs/Boost/orig/"
libBoost_srcdir = libBoost_origdir .. "libs/"
libBoost_incdir = libBoost_origdir

-- Includes
libBoost_includedirs = {
    libBoost_incdir
}

-- Libs
libBoost_libs = {
}

-- Sources
libBoost_sources = {
    libBoost_srcdir .. "filesystem/src/codecvt_error_category.cpp",
    libBoost_srcdir .. "filesystem/src/operations.cpp",
    libBoost_srcdir .. "filesystem/src/path.cpp",
    libBoost_srcdir .. "filesystem/src/path_traits.cpp",
    libBoost_srcdir .. "filesystem/src/portability.cpp",
    libBoost_srcdir .. "filesystem/src/unique_path.cpp",
    libBoost_srcdir .. "filesystem/src/utf8_codecvt_facet.cpp",
    libBoost_srcdir .. "program_options/src/cmdline.cpp",
    libBoost_srcdir .. "program_options/src/config_file.cpp",
    libBoost_srcdir .. "program_options/src/convert.cpp",
    libBoost_srcdir .. "program_options/src/options_description.cpp",
    libBoost_srcdir .. "program_options/src/parsers.cpp",
    libBoost_srcdir .. "program_options/src/positional_options.cpp",
    libBoost_srcdir .. "program_options/src/split.cpp",
    libBoost_srcdir .. "program_options/src/utf8_codecvt_facet.cpp",
    libBoost_srcdir .. "program_options/src/value_semantic.cpp",
    libBoost_srcdir .. "program_options/src/variables_map.cpp",
    libBoost_srcdir .. "thread/src/future.cpp",
    libBoost_srcdir .. "thread/src/tss_null.cpp",
    libBoost_srcdir .. "system/src/error_code.cpp"
}
if os.host() == "windows" then
    table.insert(libBoost_sources, libBoost_srcdir .. "filesystem/src/windows_file_codecvt.cpp")
    table.insert(libBoost_sources, libBoost_srcdir .. "program_options/src/winmain.cpp")
    table.insert(libBoost_sources, libBoost_srcdir .. "thread/src/win32/thread_primitives.cpp")
else
    table.insert(libBoost_sources, libBoost_srcdir .. "thread/src/pthread/once.cpp")
    table.insert(libBoost_sources, libBoost_srcdir .. "thread/src/pthread/thread.cpp")
end
