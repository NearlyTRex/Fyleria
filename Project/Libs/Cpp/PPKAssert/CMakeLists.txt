add_library(PPKAssert STATIC orig/src/ppk_assert.cpp)
target_compile_features(PPKAssert PRIVATE cxx_std_20)
target_include_directories(PPKAssert PUBLIC orig/src)
