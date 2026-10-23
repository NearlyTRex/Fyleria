# Copies the prebuilt scripts and styles the scenes load into Data/Libs/ThirdParty
set(THIRDPARTY_DIR "${PROJECT_SOURCE_DIR}/Data/Libs/ThirdParty")
set(THIRDPARTY_FILES
    "Bootstrap|Bootstrap/orig/dist/css/bootstrap.min.css"
    "Bootstrap|Bootstrap/orig/dist/css/bootstrap.min.css.map"
    "Bootstrap|Bootstrap/orig/dist/js/bootstrap.min.js"
    "Bootstrap|Bootstrap/orig/dist/js/bootstrap.min.js.map"
    "jQuery|jQuery/orig/dist/jquery.min.js"
    "jQueryTerminal|jQueryTerminal/orig/css/jquery.terminal.min.css"
    "jQueryTerminal|jQueryTerminal/orig/css/jquery.terminal.min.css.map"
    "jQueryTerminal|jQueryTerminal/orig/js/jquery.terminal.min.js"
    "jQueryTerminal|jQueryTerminal/orig/js/jquery.terminal.min.js.map"
    "Phaser|Phaser/orig/dist/phaser.min.js")

set(THIRDPARTY_OUTPUTS)
foreach(entry IN LISTS THIRDPARTY_FILES)
    string(REPLACE "|" ";" entry "${entry}")
    list(GET entry 0 library)
    list(GET entry 1 source)
    cmake_path(GET source FILENAME name)
    set(output "${THIRDPARTY_DIR}/${library}/${name}")
    add_custom_command(
        OUTPUT "${output}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${THIRDPARTY_DIR}/${library}"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/${source}" "${output}"
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${source}"
        VERBATIM)
    list(APPEND THIRDPARTY_OUTPUTS "${output}")
endforeach()

add_custom_target(ThirdPartyData ALL DEPENDS ${THIRDPARTY_OUTPUTS})
