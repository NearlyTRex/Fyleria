add_library(Zlib STATIC
    orig/adler32.c
    orig/compress.c
    orig/crc32.c
    orig/deflate.c
    orig/gzclose.c
    orig/gzlib.c
    orig/gzread.c
    orig/gzwrite.c
    orig/infback.c
    orig/inffast.c
    orig/inflate.c
    orig/inftrees.c
    orig/trees.c
    orig/uncompr.c
    orig/zutil.c)
target_include_directories(Zlib PUBLIC orig)
target_compile_definitions(Zlib PRIVATE $<$<CONFIG:Debug>:DEBUG>)
if(WIN32)
    target_compile_definitions(Zlib PRIVATE _CRT_SECURE_NO_WARNINGS _CRT_SECURE_NO_DEPRECATE _CRT_NONSTDC_NO_DEPRECATE)
else()
    target_compile_definitions(Zlib PRIVATE HAVE_UNISTD_H HAVE_STDARG_H)
endif()
