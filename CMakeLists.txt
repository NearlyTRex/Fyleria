cmake_minimum_required(VERSION 3.25)

project(Fyleria LANGUAGES C CXX)

# Debug and Release only, so every generator offers the same two configurations
set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING "" FORCE)

# Compiler options
set(CMAKE_CXX_EXTENSIONS OFF)
if(MSVC)
    add_compile_options(/utf-8)
endif()

# Helpers
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(FyleriaOutput)

# Third party
add_subdirectory(Project/Libs)

# Engine
add_subdirectory(Project/Fyleria)

# Tests
enable_testing()
add_test(NAME FyleriaTest COMMAND FyleriaTest)
