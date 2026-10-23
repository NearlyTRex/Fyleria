# Only the compiled parts the engine uses; the rest of Boost is header-only
add_library(Boost STATIC
    orig/libs/filesystem/src/codecvt_error_category.cpp
    orig/libs/filesystem/src/directory.cpp
    orig/libs/filesystem/src/exception.cpp
    orig/libs/filesystem/src/operations.cpp
    orig/libs/filesystem/src/path.cpp
    orig/libs/filesystem/src/path_traits.cpp
    orig/libs/filesystem/src/portability.cpp
    orig/libs/filesystem/src/unique_path.cpp
    orig/libs/filesystem/src/utf8_codecvt_facet.cpp
    orig/libs/program_options/src/cmdline.cpp
    orig/libs/program_options/src/config_file.cpp
    orig/libs/program_options/src/convert.cpp
    orig/libs/program_options/src/options_description.cpp
    orig/libs/program_options/src/parsers.cpp
    orig/libs/program_options/src/positional_options.cpp
    orig/libs/program_options/src/split.cpp
    orig/libs/program_options/src/utf8_codecvt_facet.cpp
    orig/libs/program_options/src/value_semantic.cpp
    orig/libs/program_options/src/variables_map.cpp
    orig/libs/system/src/error_code.cpp)
if(WIN32)
    target_sources(Boost PRIVATE
        orig/libs/filesystem/src/windows_file_codecvt.cpp
        orig/libs/program_options/src/winmain.cpp)
endif()
target_compile_features(Boost PRIVATE cxx_std_20)
target_include_directories(Boost PUBLIC orig)
target_compile_definitions(Boost PUBLIC BOOST_ALL_NO_LIB)
