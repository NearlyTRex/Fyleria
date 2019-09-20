-- Configuration
libGdkPixbuf_extradir = "Libs/GdkPixbuf/extra/"
libGdkPixbuf_origdir = "Libs/GdkPixbuf/orig/"
libGdkPixbuf_srcdir = libGdkPixbuf_origdir
libGdkPixbuf_incdir = libGdkPixbuf_origdir

-- Includes
libGdkPixbuf_includedirs = {
    libGdkPixbuf_incdir
}

-- Defines
libGdkPixbuf_defines = {
    "HAVE_CONFIG_H",
    "_FILE_OFFSET_BITS=64",
    "_POSIX_C_SOURCE=200809L",
    "_DEFAULT_SOURCE",
    "_XOPEN_SOURCE",
    "STDC_HEADERS",
    "G_LOG_DOMAIN=\"GdkPixbuf\"",
    "G_LOG_STRUCTURED=1",
    "GDK_PIXBUF_COMPILATION",
    "GDK_PIXBUF_STATIC_COMPILATION",
    "GDK_PIXBUF_PREFIX=\"gdkpixbuf\"",
    "GDK_PIXBUF_LOCALEDIR=\"locale\"",
    "GDK_PIXBUF_LIBDIR=\"lib\"",
    "GDK_PIXBUF_BINARY_VERSION=\"2.10.0\"",
    "GDK_PIXBUF_ENABLE_BACKEND",
    "PIXBUF_LIBDIR=\"lib\"",
    "BUILT_MODULES_DIR=\"modules\""
}
libGdkPixbuf_debugdefines = {
}
libGdkPixbuf_releasedefines = {
}

-- Options
libGdkPixbuf_buildoptions = {
}
libGdkPixbuf_linkoptions = {
}

-- Libs
libGdkPixbuf_libs = {
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-animation.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-buffer-queue.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-csource.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-data.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-io.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-loader.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-pixdata.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-scale.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-scaled-anim.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-simple-anim.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixbuf-util.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/gdk-pixdata.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-ani-animation.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-ani.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-bmp.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-gif-animation.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-gif.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-icns.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-ico.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-png.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-pnm.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-qtif.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-tga.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-xbm.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/io-xpm.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/lzw.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/pixops/pixops.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/pixops/pixops.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/pixops/timescale.c",
     libGdkPixbuf_srcdir .. "gdk-pixbuf/queryloaders.c",
}
