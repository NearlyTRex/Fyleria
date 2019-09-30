-- Configuration
libCairo_extradir = "Libs/Cairo/extra/"
libCairo_origdir = "Libs/Cairo/orig/"
libCairo_srcdir = libCairo_origdir
libCairo_incdir = libCairo_origdir

-- Includes
libCairo_includedirs = {
    libCairo_incdir .. "src",
    libCairo_incdir .. "util/cairo-gobject/",
    libCairo_incdir .. "util/cairo-script/"
}
if os.host() == "linux" then
    table.insert(libCairo_includedirs, libCairo_extradir .. "linux/")
    table.insert(libCairo_includedirs, libCairo_extradir .. "linux/src/")
end

-- Defines
libCairo_defines = {
    "HAVE_CONFIG_H",
    "PIC",
    "_REENTRANT",
    "_FORTIFY_SOURCE=2",
    "LIBDIR=\"lib\"",
    "CAIRO_TRACE_OUTDIR=\"trace\""
}
libCairo_debugdefines = {
}
libCairo_releasedefines = {
}

-- Options
libCairo_buildoptions = {
}
libCairo_linkoptions = {
}
if os.host() == "windows" then
    table.insert(libCairo_buildoptions, "/bigobj")
elseif os.host() == "linux" then
    table.insert(libCairo_buildoptions, "-Wno-attributes")
    table.insert(libCairo_buildoptions, "-fno-common")
    table.insert(libCairo_buildoptions, "-fno-strict-aliasing")
end

-- Libs
libCairo_libs = {
}
if os.host() == "linux" then
    table.insert(libCairo_libs, "EGL")
    table.insert(libCairo_libs, "GL")
    table.insert(libCairo_libs, "GLX")
    table.insert(libCairo_libs, "xcb")
    table.insert(libCairo_libs, "xcb-render")
    table.insert(libCairo_libs, "xcb-shm")
    table.insert(libCairo_libs, "xcb-composite")
end

-- Sources
libCairo_sources = {
    libCairo_srcdir .. "src/cairo-analysis-surface.c",
    libCairo_srcdir .. "src/cairo-arc.c",
    libCairo_srcdir .. "src/cairo-array.c",
    libCairo_srcdir .. "src/cairo-atomic.c",
    libCairo_srcdir .. "src/cairo-base64-stream.c",
    libCairo_srcdir .. "src/cairo-base85-stream.c",
    libCairo_srcdir .. "src/cairo-bentley-ottmann-rectangular.c",
    libCairo_srcdir .. "src/cairo-bentley-ottmann-rectilinear.c",
    libCairo_srcdir .. "src/cairo-bentley-ottmann.c",
    libCairo_srcdir .. "src/cairo-botor-scan-converter.c",
    libCairo_srcdir .. "src/cairo-boxes-intersect.c",
    libCairo_srcdir .. "src/cairo-boxes.c",
    libCairo_srcdir .. "src/cairo-cache.c",
    libCairo_srcdir .. "src/cairo-clip-boxes.c",
    libCairo_srcdir .. "src/cairo-clip-polygon.c",
    libCairo_srcdir .. "src/cairo-clip-region.c",
    libCairo_srcdir .. "src/cairo-clip-surface.c",
    libCairo_srcdir .. "src/cairo-clip-tor-scan-converter.c",
    libCairo_srcdir .. "src/cairo-clip.c",
    libCairo_srcdir .. "src/cairo-color.c",
    libCairo_srcdir .. "src/cairo-composite-rectangles.c",
    libCairo_srcdir .. "src/cairo-compositor.c",
    libCairo_srcdir .. "src/cairo-contour.c",
    libCairo_srcdir .. "src/cairo-damage.c",
    libCairo_srcdir .. "src/cairo-debug.c",
    libCairo_srcdir .. "src/cairo-default-context.c",
    libCairo_srcdir .. "src/cairo-device.c",
    libCairo_srcdir .. "src/cairo-error.c",
    libCairo_srcdir .. "src/cairo-fallback-compositor.c",
    libCairo_srcdir .. "src/cairo-fixed.c",
    libCairo_srcdir .. "src/cairo-font-face-twin-data.c",
    libCairo_srcdir .. "src/cairo-font-face-twin.c",
    libCairo_srcdir .. "src/cairo-font-face.c",
    libCairo_srcdir .. "src/cairo-font-options.c",
    libCairo_srcdir .. "src/cairo-freed-pool.c",
    libCairo_srcdir .. "src/cairo-freelist.c",
    libCairo_srcdir .. "src/cairo-gstate.c",
    libCairo_srcdir .. "src/cairo-hash.c",
    libCairo_srcdir .. "src/cairo-hull.c",
    libCairo_srcdir .. "src/cairo-image-compositor.c",
    libCairo_srcdir .. "src/cairo-image-info.c",
    libCairo_srcdir .. "src/cairo-image-source.c",
    libCairo_srcdir .. "src/cairo-image-surface.c",
    libCairo_srcdir .. "src/cairo-line.c",
    libCairo_srcdir .. "src/cairo-lzw.c",
    libCairo_srcdir .. "src/cairo-mask-compositor.c",
    libCairo_srcdir .. "src/cairo-matrix.c",
    libCairo_srcdir .. "src/cairo-mempool.c",
    libCairo_srcdir .. "src/cairo-mesh-pattern-rasterizer.c",
    libCairo_srcdir .. "src/cairo-misc.c",
    libCairo_srcdir .. "src/cairo-mono-scan-converter.c",
    libCairo_srcdir .. "src/cairo-mutex.c",
    libCairo_srcdir .. "src/cairo-no-compositor.c",
    libCairo_srcdir .. "src/cairo-observer.c",
    libCairo_srcdir .. "src/cairo-output-stream.c",
    libCairo_srcdir .. "src/cairo-paginated-surface.c",
    libCairo_srcdir .. "src/cairo-path-bounds.c",
    libCairo_srcdir .. "src/cairo-path-fill.c",
    libCairo_srcdir .. "src/cairo-path-fixed.c",
    libCairo_srcdir .. "src/cairo-path-in-fill.c",
    libCairo_srcdir .. "src/cairo-path-stroke-boxes.c",
    libCairo_srcdir .. "src/cairo-path-stroke-polygon.c",
    libCairo_srcdir .. "src/cairo-path-stroke-traps.c",
    libCairo_srcdir .. "src/cairo-path-stroke-tristrip.c",
    libCairo_srcdir .. "src/cairo-path-stroke.c",
    libCairo_srcdir .. "src/cairo-path.c",
    libCairo_srcdir .. "src/cairo-pattern.c",
    libCairo_srcdir .. "src/cairo-pen.c",
    libCairo_srcdir .. "src/cairo-polygon-intersect.c",
    libCairo_srcdir .. "src/cairo-polygon-reduce.c",
    libCairo_srcdir .. "src/cairo-polygon.c",
    libCairo_srcdir .. "src/cairo-raster-source-pattern.c",
    libCairo_srcdir .. "src/cairo-recording-surface.c",
    libCairo_srcdir .. "src/cairo-rectangle.c",
    libCairo_srcdir .. "src/cairo-rectangular-scan-converter.c",
    libCairo_srcdir .. "src/cairo-region.c",
    libCairo_srcdir .. "src/cairo-rtree.c",
    libCairo_srcdir .. "src/cairo-scaled-font.c",
    libCairo_srcdir .. "src/cairo-shape-mask-compositor.c",
    libCairo_srcdir .. "src/cairo-slope.c",
    libCairo_srcdir .. "src/cairo-spans-compositor.c",
    libCairo_srcdir .. "src/cairo-spans.c",
    libCairo_srcdir .. "src/cairo-spline.c",
    libCairo_srcdir .. "src/cairo-stroke-dash.c",
    libCairo_srcdir .. "src/cairo-stroke-style.c",
    libCairo_srcdir .. "src/cairo-surface-clipper.c",
    libCairo_srcdir .. "src/cairo-surface-fallback.c",
    libCairo_srcdir .. "src/cairo-surface-observer.c",
    libCairo_srcdir .. "src/cairo-surface-offset.c",
    libCairo_srcdir .. "src/cairo-surface-snapshot.c",
    libCairo_srcdir .. "src/cairo-surface-subsurface.c",
    libCairo_srcdir .. "src/cairo-surface-wrapper.c",
    libCairo_srcdir .. "src/cairo-surface.c",
    libCairo_srcdir .. "src/cairo-time.c",
    libCairo_srcdir .. "src/cairo-tor-scan-converter.c",
    libCairo_srcdir .. "src/cairo-tor22-scan-converter.c",
    libCairo_srcdir .. "src/cairo-toy-font-face.c",
    libCairo_srcdir .. "src/cairo-traps-compositor.c",
    libCairo_srcdir .. "src/cairo-traps.c",
    libCairo_srcdir .. "src/cairo-tristrip.c",
    libCairo_srcdir .. "src/cairo-unicode.c",
    libCairo_srcdir .. "src/cairo-user-font.c",
    libCairo_srcdir .. "src/cairo-version.c",
    libCairo_srcdir .. "src/cairo-wideint.c",
    libCairo_srcdir .. "src/cairo.c",
    libCairo_srcdir .. "src/cairo-cff-subset.c",
    libCairo_srcdir .. "src/cairo-scaled-font-subsets.c",
    libCairo_srcdir .. "src/cairo-truetype-subset.c",
    libCairo_srcdir .. "src/cairo-type1-fallback.c",
    libCairo_srcdir .. "src/cairo-type1-glyph-names.c",
    libCairo_srcdir .. "src/cairo-type1-subset.c",
    libCairo_srcdir .. "src/cairo-type3-glyph-surface.c",
    libCairo_srcdir .. "src/cairo-pdf-operators.c",
    libCairo_srcdir .. "src/cairo-pdf-shading.c",
    libCairo_srcdir .. "src/cairo-tag-attributes.c",
    libCairo_srcdir .. "src/cairo-deflate-stream.c",
    libCairo_srcdir .. "src/cairo-xlib-display.c",
    libCairo_srcdir .. "src/cairo-xlib-core-compositor.c",
    libCairo_srcdir .. "src/cairo-xlib-fallback-compositor.c",
    libCairo_srcdir .. "src/cairo-xlib-render-compositor.c",
    libCairo_srcdir .. "src/cairo-xlib-screen.c",
    libCairo_srcdir .. "src/cairo-xlib-source.c",
    libCairo_srcdir .. "src/cairo-xlib-surface.c",
    libCairo_srcdir .. "src/cairo-xlib-surface-shm.c",
    libCairo_srcdir .. "src/cairo-xlib-visual.c",
    libCairo_srcdir .. "src/cairo-xlib-xcb-surface.c",
    libCairo_srcdir .. "src/cairo-xcb-connection.c",
    libCairo_srcdir .. "src/cairo-xcb-connection-core.c",
    libCairo_srcdir .. "src/cairo-xcb-connection-render.c",
    libCairo_srcdir .. "src/cairo-xcb-connection-shm.c",
    libCairo_srcdir .. "src/cairo-xcb-screen.c",
    libCairo_srcdir .. "src/cairo-xcb-shm.c",
    libCairo_srcdir .. "src/cairo-xcb-surface.c",
    libCairo_srcdir .. "src/cairo-xcb-surface-core.c",
    libCairo_srcdir .. "src/cairo-xcb-surface-render.c",
    libCairo_srcdir .. "src/cairo-xcb-resources.c",
    libCairo_srcdir .. "src/cairo-png.c",
    libCairo_srcdir .. "src/cairo-gl-composite.c",
    libCairo_srcdir .. "src/cairo-gl-device.c",
    libCairo_srcdir .. "src/cairo-gl-dispatch.c",
    libCairo_srcdir .. "src/cairo-gl-glyphs.c",
    libCairo_srcdir .. "src/cairo-gl-gradient.c",
    libCairo_srcdir .. "src/cairo-gl-info.c",
    libCairo_srcdir .. "src/cairo-gl-msaa-compositor.c",
    libCairo_srcdir .. "src/cairo-gl-operand.c",
    libCairo_srcdir .. "src/cairo-gl-shaders.c",
    libCairo_srcdir .. "src/cairo-gl-source.c",
    libCairo_srcdir .. "src/cairo-gl-spans-compositor.c",
    libCairo_srcdir .. "src/cairo-gl-surface.c",
    libCairo_srcdir .. "src/cairo-gl-traps-compositor.c",
    libCairo_srcdir .. "src/cairo-egl-context.c",
    libCairo_srcdir .. "src/cairo-glx-context.c",
    libCairo_srcdir .. "src/cairo-script-surface.c",
    libCairo_srcdir .. "src/cairo-ft-font.c",
    libCairo_srcdir .. "src/cairo-ps-surface.c",
    libCairo_srcdir .. "src/cairo-pdf-surface.c",
    libCairo_srcdir .. "src/cairo-pdf-interchange.c",
    libCairo_srcdir .. "src/cairo-tag-stack.c",
    libCairo_srcdir .. "src/cairo-svg-surface.c",
    libCairo_srcdir .. "util/cairo-missing/strndup.c",
    libCairo_srcdir .. "util/cairo-missing/getline.c",
    libCairo_srcdir .. "util/cairo-gobject/cairo-gobject-enums.c",
    libCairo_srcdir .. "util/cairo-gobject/cairo-gobject-structs.c",
    libCairo_srcdir .. "util/cairo-script/cairo-script-file.c",
    libCairo_srcdir .. "util/cairo-script/cairo-script-hash.c",
    libCairo_srcdir .. "util/cairo-script/cairo-script-interpreter.c",
    libCairo_srcdir .. "util/cairo-script/cairo-script-objects.c",
    libCairo_srcdir .. "util/cairo-script/cairo-script-operators.c",
    libCairo_srcdir .. "util/cairo-script/cairo-script-scanner.c",
    libCairo_srcdir .. "util/cairo-script/cairo-script-stack.c",
}
