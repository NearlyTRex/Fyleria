-- Configuration
libWebp_extradir = "Libs/Webp/extra/"
libWebp_origdir = "Libs/Webp/orig/"
libWebp_srcdir = libWebp_origdir ..  "src/"
libWebp_incdir = libWebp_origdir

-- Includes
libWebp_includedirs = {
    libWebp_incdir
}
if os.host() == "linux" then
    table.insert(libWebp_includedirs, libWebp_extradir .. "linux/")
end

-- Defines
libWebp_defines = {
    "HAVE_CONFIG_H"
}
libWebp_debugdefines = {
}
libWebp_releasedefines = {
}

-- Options
libWebp_buildoptions = {
}
libWebp_linkoptions = {
}
if os.host() == "linux" then
    table.insert(libWebp_buildoptions, "-msse2")
end

-- Libs
libWebp_libs = {
}

-- Sources
libWebp_sources = {
    libWebp_srcdir .. "dec/alpha_dec.c",
    libWebp_srcdir .. "dec/buffer_dec.c",
    libWebp_srcdir .. "dec/frame_dec.c",
    libWebp_srcdir .. "dec/idec_dec.c",
    libWebp_srcdir .. "dec/io_dec.c",
    libWebp_srcdir .. "dec/quant_dec.c",
    libWebp_srcdir .. "dec/tree_dec.c",
    libWebp_srcdir .. "dec/vp8_dec.c",
    libWebp_srcdir .. "dec/vp8l_dec.c",
    libWebp_srcdir .. "dec/webp_dec.c",
    libWebp_srcdir .. "enc/alpha_enc.c",
    libWebp_srcdir .. "enc/analysis_enc.c",
    libWebp_srcdir .. "enc/backward_references_cost_enc.c",
    libWebp_srcdir .. "enc/backward_references_enc.c",
    libWebp_srcdir .. "enc/config_enc.c",
    libWebp_srcdir .. "enc/cost_enc.c",
    libWebp_srcdir .. "enc/filter_enc.c",
    libWebp_srcdir .. "enc/frame_enc.c",
    libWebp_srcdir .. "enc/histogram_enc.c",
    libWebp_srcdir .. "enc/iterator_enc.c",
    libWebp_srcdir .. "enc/near_lossless_enc.c",
    libWebp_srcdir .. "enc/picture_enc.c",
    libWebp_srcdir .. "enc/picture_csp_enc.c",
    libWebp_srcdir .. "enc/picture_psnr_enc.c",
    libWebp_srcdir .. "enc/picture_rescale_enc.c",
    libWebp_srcdir .. "enc/picture_tools_enc.c",
    libWebp_srcdir .. "enc/predictor_enc.c",
    libWebp_srcdir .. "enc/quant_enc.c",
    libWebp_srcdir .. "enc/syntax_enc.c",
    libWebp_srcdir .. "enc/token_enc.c",
    libWebp_srcdir .. "enc/tree_enc.c",
    libWebp_srcdir .. "enc/vp8l_enc.c",
    libWebp_srcdir .. "enc/webp_enc.c",
    libWebp_srcdir .. "dsp/alpha_processing.c",
    libWebp_srcdir .. "dsp/cpu.c",
    libWebp_srcdir .. "dsp/dec.c",
    libWebp_srcdir .. "dsp/dec_clip_tables.c",
    libWebp_srcdir .. "dsp/filters.c",
    libWebp_srcdir .. "dsp/lossless.c",
    libWebp_srcdir .. "dsp/rescaler.c",
    libWebp_srcdir .. "dsp/upsampling.c",
    libWebp_srcdir .. "dsp/yuv.c",
    libWebp_srcdir .. "dsp/cost.c",
    libWebp_srcdir .. "dsp/enc.c",
    libWebp_srcdir .. "dsp/lossless_enc.c",
    libWebp_srcdir .. "dsp/ssim.c",
    libWebp_srcdir .. "dsp/cost_sse2.c",
    libWebp_srcdir .. "dsp/enc_sse2.c",
    libWebp_srcdir .. "dsp/lossless_enc_sse2.c",
    libWebp_srcdir .. "dsp/ssim_sse2.c",
    libWebp_srcdir .. "dsp/alpha_processing_sse2.c",
    libWebp_srcdir .. "dsp/dec_sse2.c",
    libWebp_srcdir .. "dsp/filters_sse2.c",
    libWebp_srcdir .. "dsp/lossless_sse2.c",
    libWebp_srcdir .. "dsp/rescaler_sse2.c",
    libWebp_srcdir .. "dsp/upsampling_sse2.c",
    libWebp_srcdir .. "dsp/yuv_sse2.c",
    libWebp_srcdir .. "dsp/enc_sse41.c",
    libWebp_srcdir .. "dsp/lossless_enc_sse41.c",
    libWebp_srcdir .. "dsp/alpha_processing_sse41.c",
    libWebp_srcdir .. "dsp/dec_sse41.c",
    libWebp_srcdir .. "dsp/upsampling_sse41.c",
    libWebp_srcdir .. "dsp/yuv_sse41.c",
    libWebp_srcdir .. "dsp/cost_neon.c",
    libWebp_srcdir .. "dsp/enc_neon.c",
    libWebp_srcdir .. "dsp/lossless_enc_neon.c",
    libWebp_srcdir .. "dsp/alpha_processing_neon.c",
    libWebp_srcdir .. "dsp/dec_neon.c",
    libWebp_srcdir .. "dsp/filters_neon.c",
    libWebp_srcdir .. "dsp/lossless_neon.c",
    libWebp_srcdir .. "dsp/rescaler_neon.c",
    libWebp_srcdir .. "dsp/upsampling_neon.c",
    libWebp_srcdir .. "dsp/yuv_neon.c",
    libWebp_srcdir .. "dsp/enc_msa.c",
    libWebp_srcdir .. "dsp/lossless_enc_msa.c",
    libWebp_srcdir .. "dsp/dec_msa.c",
    libWebp_srcdir .. "dsp/filters_msa.c",
    libWebp_srcdir .. "dsp/lossless_msa.c",
    libWebp_srcdir .. "dsp/rescaler_msa.c",
    libWebp_srcdir .. "dsp/upsampling_msa.c",
    libWebp_srcdir .. "dsp/cost_mips32.c",
    libWebp_srcdir .. "dsp/enc_mips32.c",
    libWebp_srcdir .. "dsp/lossless_enc_mips32.c",
    libWebp_srcdir .. "dsp/dec_mips32.c",
    libWebp_srcdir .. "dsp/rescaler_mips32.c",
    libWebp_srcdir .. "dsp/yuv_mips32.c",
    libWebp_srcdir .. "dsp/cost_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/enc_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/lossless_enc_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/alpha_processing_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/dec_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/filters_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/lossless_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/rescaler_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/upsampling_mips_dsp_r2.c",
    libWebp_srcdir .. "dsp/yuv_mips_dsp_r2.c",
    libWebp_srcdir .. "utils/bit_reader_utils.c",
    libWebp_srcdir .. "utils/color_cache_utils.c",
    libWebp_srcdir .. "utils/filters_utils.c",
    libWebp_srcdir .. "utils/huffman_utils.c",
    libWebp_srcdir .. "utils/quant_levels_dec_utils.c",
    libWebp_srcdir .. "utils/rescaler_utils.c",
    libWebp_srcdir .. "utils/random_utils.c",
    libWebp_srcdir .. "utils/thread_utils.c",
    libWebp_srcdir .. "utils/utils.c",
    libWebp_srcdir .. "utils/bit_writer_utils.c",
    libWebp_srcdir .. "utils/huffman_encode_utils.c",
    libWebp_srcdir .. "utils/quant_levels_utils.c",
    libWebp_srcdir .. "demux/anim_decode.c",
    libWebp_srcdir .. "demux/demux.c",
    -- libWebp_origdir .. "imageio/imageio_util.c",
    -- libWebp_origdir .. "imageio/image_dec.c",
    -- libWebp_origdir .. "imageio/jpegdec.c",
    -- libWebp_origdir .. "imageio/metadata.c",
    -- libWebp_origdir .. "imageio/pngdec.c",
    -- libWebp_origdir .. "imageio/pnmdec.c",
    -- libWebp_origdir .. "imageio/tiffdec.c",
    -- libWebp_origdir .. "imageio/webpdec.c",
    -- libWebp_origdir .. "imageio/wicdec.c",
    -- libWebp_origdir .. "imageio/image_enc.c",
}
