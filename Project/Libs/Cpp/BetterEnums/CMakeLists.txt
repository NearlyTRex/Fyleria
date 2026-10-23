add_library(BetterEnums INTERFACE)
target_include_directories(BetterEnums INTERFACE orig extra)
target_compile_definitions(BetterEnums INTERFACE "BETTER_ENUMS_MACRO_FILE=\"enum_macros.h\"")
