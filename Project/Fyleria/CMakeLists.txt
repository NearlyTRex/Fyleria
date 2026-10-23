# Version, from git describe when CMake configures the build
execute_process(
    COMMAND git describe --dirty --always --tags
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    OUTPUT_VARIABLE FYLERIA_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET)
if(NOT FYLERIA_VERSION)
    set(FYLERIA_VERSION unknown)
endif()
string(TIMESTAMP FYLERIA_BUILD_DATE "%Y-%m-%d %H:%M:%S")
set(FYLERIA_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
configure_file("${PROJECT_SOURCE_DIR}/cmake/Version.h.in" "${FYLERIA_GENERATED_DIR}/Utility/Version.h" @ONLY)
configure_file("${PROJECT_SOURCE_DIR}/cmake/Version.cpp.in" "${FYLERIA_GENERATED_DIR}/Utility/Version.cpp" @ONLY)

# Settings shared by the library and the programs
add_library(FyleriaOptions INTERFACE)
target_compile_features(FyleriaOptions INTERFACE cxx_std_17)
target_compile_definitions(FyleriaOptions INTERFACE $<IF:$<CONFIG:Debug>,DEBUG,NDEBUG>)
if(MSVC)
    target_compile_options(FyleriaOptions INTERFACE /bigobj)
    target_compile_definitions(FyleriaOptions INTERFACE
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
        _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
        _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING
        _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)
else()
    target_compile_options(FyleriaOptions INTERFACE -Wall -Wfatal-errors)
endif()

# Library
file(GLOB_RECURSE FYLERIA_LIB_SOURCES CONFIGURE_DEPENDS
    Application/*.cpp
    Battle/*.cpp
    Cache/*.cpp
    Character/*.cpp
    CharacterAction/*.cpp
    CharacterActionHandler/*.cpp
    CharacterData/*.cpp
    CharacterParty/*.cpp
    Config/*.cpp
    File/*.cpp
    Item/*.cpp
    Recipe/*.cpp
    Save/*.cpp
    Scene/*.cpp
    Simulator/*.cpp
    Skill/*.cpp
    Stat/*.cpp
    Utility/*.cpp
    Window/*.cpp)
# The old Setup.py wrote the version into the source tree
list(FILTER FYLERIA_LIB_SOURCES EXCLUDE REGEX "/Utility/Version\\.cpp$")
add_library(FyleriaLib STATIC ${FYLERIA_LIB_SOURCES} "${FYLERIA_GENERATED_DIR}/Utility/Version.cpp")
target_include_directories(FyleriaLib PUBLIC "${FYLERIA_GENERATED_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
find_package(Threads REQUIRED)
target_link_libraries(FyleriaLib PUBLIC
    FyleriaOptions
    Backward
    BetterEnums
    Boost
    CJSMin
    Date
    FantasyName
    ImmutableString
    Json
    LRUCache
    MicroPather
    ObjectThreadsafe
    PPKAssert
    SpdLog
    WebView
    Zlib
    Threads::Threads)

# Game
add_executable(FyleriaMain WIN32 Main/main.cpp)
target_link_libraries(FyleriaMain PRIVATE FyleriaLib)
add_dependencies(FyleriaMain ThirdPartyData)
fyleria_program(FyleriaMain)

# Unit tests
file(GLOB_RECURSE FYLERIA_TEST_SOURCES CONFIGURE_DEPENDS
    Test/*.cpp
    TestFixture/*.cpp
    TestSample/*.cpp)
add_executable(FyleriaTest ${FYLERIA_TEST_SOURCES} Main/main-test.cpp)
target_link_libraries(FyleriaTest PRIVATE FyleriaLib)
fyleria_program(FyleriaTest)
