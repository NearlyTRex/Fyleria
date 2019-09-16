-- Configuration
libCairo_extradir = "Libs/Cairo/extra/"
libCairo_origdir = "Libs/Cairo/orig/"
libCairo_srcdir = libCairo_origdir .. "src/"
libCairo_incdir = libCairo_origdir .. "src/"

-- Includes
libCairo_includedirs = {
    libCairo_incdir
}
if os.host() == "linux" then
    table.insert(libCairo_includedirs, libCairo_extradir .. "linux/")
end

-- Defines
libCairo_defines = {
    "HAVE_CONFIG_H"
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
end

-- Sources
libCairo_sources = {
    libCairo_srcdir .. "cairo.c",
    libCairo_srcdir .. "cairo-analysis-surface.c",
    libCairo_srcdir .. "cairo-arc.c",
    libCairo_srcdir .. "cairo-array.c",
    libCairo_srcdir .. "cairo-atomic.c",
    libCairo_srcdir .. "cairo-base64-stream.c",
    libCairo_srcdir .. "cairo-base85-stream.c",
    libCairo_srcdir .. "cairo-bentley-ottmann.c",
    libCairo_srcdir .. "cairo-bentley-ottmann-rectangular.c",
    libCairo_srcdir .. "cairo-bentley-ottmann-rectilinear.c",
    libCairo_srcdir .. "cairo-botor-scan-converter.c",
    libCairo_srcdir .. "cairo-boxes-intersect.c",
    libCairo_srcdir .. "cairo-boxes.c",
    libCairo_srcdir .. "cairo-cache.c",
    libCairo_srcdir .. "cairo-cff-subset.c",
    libCairo_srcdir .. "cairo-clip-boxes.c",
    libCairo_srcdir .. "cairo-clip.c",
    libCairo_srcdir .. "cairo-clip-polygon.c",
    libCairo_srcdir .. "cairo-clip-region.c",
    libCairo_srcdir .. "cairo-clip-surface.c",
    libCairo_srcdir .. "cairo-clip-tor-scan-converter.c",
    libCairo_srcdir .. "cairo-color.c",
    libCairo_srcdir .. "cairo-composite-rectangles.c",
    libCairo_srcdir .. "cairo-compositor.c",
    libCairo_srcdir .. "cairo-contour.c",
    libCairo_srcdir .. "cairo-damage.c",
    libCairo_srcdir .. "cairo-debug.c",
    libCairo_srcdir .. "cairo-default-context.c",
    libCairo_srcdir .. "cairo-deflate-stream.c",
    libCairo_srcdir .. "cairo-device.c",
    libCairo_srcdir .. "cairo-egl-context.c",
    libCairo_srcdir .. "cairo-error.c",
    libCairo_srcdir .. "cairo-fallback-compositor.c",
    libCairo_srcdir .. "cairo-fixed.c",
    libCairo_srcdir .. "cairo-font-face.c",
    libCairo_srcdir .. "cairo-font-face-twin-data.c",
    libCairo_srcdir .. "cairo-font-face-twin.c",
    libCairo_srcdir .. "cairo-font-options.c",
    libCairo_srcdir .. "cairo-freed-pool.c",
    libCairo_srcdir .. "cairo-freelist.c",
    libCairo_srcdir .. "cairo-ft-font.c",
    libCairo_srcdir .. "cairo-gl-composite.c",
    libCairo_srcdir .. "cairo-gl-device.c",
    libCairo_srcdir .. "cairo-gl-dispatch.c",
    libCairo_srcdir .. "cairo-gl-glyphs.c",
    libCairo_srcdir .. "cairo-gl-gradient.c",
    libCairo_srcdir .. "cairo-gl-info.c",
    libCairo_srcdir .. "cairo-gl-msaa-compositor.c",
    libCairo_srcdir .. "cairo-gl-operand.c",
    libCairo_srcdir .. "cairo-gl-shaders.c",
    libCairo_srcdir .. "cairo-gl-source.c",
    libCairo_srcdir .. "cairo-gl-spans-compositor.c",
    libCairo_srcdir .. "cairo-gl-surface.c",
    libCairo_srcdir .. "cairo-gl-traps-compositor.c",
    libCairo_srcdir .. "cairo-glx-context.c",
    libCairo_srcdir .. "cairo-gstate.c",
    libCairo_srcdir .. "cairo-hash.c",
    libCairo_srcdir .. "cairo-hull.c",
    libCairo_srcdir .. "cairo-image-compositor.c",
    libCairo_srcdir .. "cairo-image-info.c",
    libCairo_srcdir .. "cairo-image-source.c",
    libCairo_srcdir .. "cairo-image-surface.c",
    libCairo_srcdir .. "cairo-line.c",
    libCairo_srcdir .. "cairo-lzw.c",
    libCairo_srcdir .. "cairo-mask-compositor.c",
    libCairo_srcdir .. "cairo-matrix.c",
    libCairo_srcdir .. "cairo-mempool.c",
    libCairo_srcdir .. "cairo-mesh-pattern-rasterizer.c",
    libCairo_srcdir .. "cairo-misc.c",
    libCairo_srcdir .. "cairo-mono-scan-converter.c",
    libCairo_srcdir .. "cairo-mutex.c",
    libCairo_srcdir .. "cairo-no-compositor.c",
    libCairo_srcdir .. "cairo-observer.c",
    libCairo_srcdir .. "cairo-output-stream.c",
    libCairo_srcdir .. "cairo-paginated-surface.c",
    libCairo_srcdir .. "cairo-path-bounds.c",
    libCairo_srcdir .. "cairo-path-fill.c",
    libCairo_srcdir .. "cairo-path-fixed.c",
    libCairo_srcdir .. "cairo-path-in-fill.c",
    libCairo_srcdir .. "cairo-path.c",
    libCairo_srcdir .. "cairo-path-stroke-boxes.c",
    libCairo_srcdir .. "cairo-path-stroke.c",
    libCairo_srcdir .. "cairo-path-stroke-polygon.c",
    libCairo_srcdir .. "cairo-path-stroke-traps.c",
    libCairo_srcdir .. "cairo-path-stroke-tristrip.c",
    libCairo_srcdir .. "cairo-pattern.c",
    libCairo_srcdir .. "cairo-pdf-interchange.c",
    libCairo_srcdir .. "cairo-pdf-operators.c",
    libCairo_srcdir .. "cairo-pdf-shading.c",
    libCairo_srcdir .. "cairo-pdf-surface.c",
    libCairo_srcdir .. "cairo-pen.c",
    libCairo_srcdir .. "cairo-png.c",
    libCairo_srcdir .. "cairo-polygon-intersect.c",
    libCairo_srcdir .. "cairo-polygon.c",
    libCairo_srcdir .. "cairo-polygon-reduce.c",
    libCairo_srcdir .. "cairo-ps-surface.c",
    libCairo_srcdir .. "cairo-raster-source-pattern.c",
    libCairo_srcdir .. "cairo-recording-surface.c",
    libCairo_srcdir .. "cairo-rectangle.c",
    libCairo_srcdir .. "cairo-rectangular-scan-converter.c",
    libCairo_srcdir .. "cairo-region.c",
    libCairo_srcdir .. "cairo-rtree.c",
    libCairo_srcdir .. "cairo-scaled-font.c",
    libCairo_srcdir .. "cairo-scaled-font-subsets.c",
    libCairo_srcdir .. "cairo-script-surface.c",
    libCairo_srcdir .. "cairo-shape-mask-compositor.c",
    libCairo_srcdir .. "cairo-slope.c",
    libCairo_srcdir .. "cairo-spans-compositor.c",
    libCairo_srcdir .. "cairo-spans.c",
    libCairo_srcdir .. "cairo-spline.c",
    libCairo_srcdir .. "cairo-stroke-dash.c",
    libCairo_srcdir .. "cairo-stroke-style.c",
    libCairo_srcdir .. "cairo-surface-clipper.c",
    libCairo_srcdir .. "cairo-surface-fallback.c",
    libCairo_srcdir .. "cairo-surface.c",
    libCairo_srcdir .. "cairo-surface-observer.c",
    libCairo_srcdir .. "cairo-surface-offset.c",
    libCairo_srcdir .. "cairo-surface-snapshot.c",
    libCairo_srcdir .. "cairo-surface-subsurface.c",
    libCairo_srcdir .. "cairo-surface-wrapper.c",
    libCairo_srcdir .. "cairo-svg-surface.c",
    libCairo_srcdir .. "cairo-tag-attributes.c",
    libCairo_srcdir .. "cairo-tag-stack.c",
    libCairo_srcdir .. "cairo-time.c",
    libCairo_srcdir .. "cairo-tor22-scan-converter.c",
    libCairo_srcdir .. "cairo-tor-scan-converter.c",
    libCairo_srcdir .. "cairo-toy-font-face.c",
    libCairo_srcdir .. "cairo-traps-compositor.c",
    libCairo_srcdir .. "cairo-traps.c",
    libCairo_srcdir .. "cairo-tristrip.c",
    libCairo_srcdir .. "cairo-truetype-subset.c",
    libCairo_srcdir .. "cairo-type1-fallback.c",
    libCairo_srcdir .. "cairo-type1-glyph-names.c",
    libCairo_srcdir .. "cairo-type1-subset.c",
    libCairo_srcdir .. "cairo-type3-glyph-surface.c",
    libCairo_srcdir .. "cairo-unicode.c",
    libCairo_srcdir .. "cairo-user-font.c",
    libCairo_srcdir .. "cairo-version.c",
    libCairo_srcdir .. "cairo-wideint.c",
    libCairo_srcdir .. "cairo-xlib-core-compositor.c",
    libCairo_srcdir .. "cairo-xlib-display.c",
    libCairo_srcdir .. "cairo-xlib-fallback-compositor.c",
    libCairo_srcdir .. "cairo-xlib-render-compositor.c",
    libCairo_srcdir .. "cairo-xlib-screen.c",
    libCairo_srcdir .. "cairo-xlib-source.c",
    libCairo_srcdir .. "cairo-xlib-surface.c",
    libCairo_srcdir .. "cairo-xlib-surface-shm.c",
    libCairo_srcdir .. "cairo-xlib-visual.c",
    libCairo_srcdir .. "cairo-xlib-xcb-surface.c",
}
