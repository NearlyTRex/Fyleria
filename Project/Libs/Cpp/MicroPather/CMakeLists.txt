add_library(MicroPather STATIC orig/micropather.cpp)
target_compile_features(MicroPather PRIVATE cxx_std_20)
target_include_directories(MicroPather PUBLIC orig)
target_compile_definitions(MicroPather PRIVATE $<$<CONFIG:Debug>:DEBUG>)
