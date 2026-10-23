# Programs go to Bin, next to Data, which is where they look for it at runtime.
# Names carry the platform and configuration, so builds of each can share Bin:
# FyleriaMain_linux_x86_64_release.

string(TOLOWER "${CMAKE_SYSTEM_NAME}" FYLERIA_OS)
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" FYLERIA_ARCH)
if(FYLERIA_ARCH STREQUAL "amd64")
    set(FYLERIA_ARCH x86_64)
endif()

set(FYLERIA_BIN_DIR "${PROJECT_SOURCE_DIR}/Bin")

function(fyleria_program target)
    set(name "${target}_${FYLERIA_OS}_${FYLERIA_ARCH}")
    set_target_properties(${target} PROPERTIES
        OUTPUT_NAME_DEBUG "${name}_debug"
        OUTPUT_NAME_RELEASE "${name}_release"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${FYLERIA_BIN_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${FYLERIA_BIN_DIR}")
endfunction()
