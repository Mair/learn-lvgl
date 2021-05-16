#include "../lvgl/lvgl.h"

/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifndef WEATHER_20
#define WEATHER_20 1
#endif

#if WEATHER_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+F0C2 "" */
    0x0, 0x0, 0x0, 0x0, 0x46, 0x63, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5,
    0xef, 0xff, 0xfd, 0x50, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xff, 0xff, 0xff, 0xff,
    0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0xec, 0x50,
    0x0, 0x0, 0x0, 0x0, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x60, 0x0, 0x0, 0x0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0, 0x0,
    0x3, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x20, 0x0, 0x5, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x40,
    0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x70, 0xaf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x4e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xee, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc2, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5,
    0x4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf9, 0x0, 0x2, 0xae, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc5,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F0E7 "" */
    0x1, 0x44, 0x44, 0x44, 0x10, 0x0, 0x0, 0xaf,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0xd, 0xff, 0xff,
    0xff, 0x80, 0x0, 0x0, 0xff, 0xff, 0xff, 0xf3,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xfe, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0x90, 0x0, 0x0, 0x5f,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0x8, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf6, 0xaf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x5c, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0xef, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xb,
    0xff, 0xff, 0xff, 0xff, 0xf9, 0x0, 0x0, 0x0,
    0x8, 0xff, 0xff, 0x10, 0x0, 0x0, 0x0, 0xbf,
    0xff, 0x70, 0x0, 0x0, 0x0, 0xf, 0xff, 0xd0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xf4, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xfb, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xff, 0x20, 0x0, 0x0, 0x0, 0x0, 0xef,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x94, 0x0, 0x0, 0x0,
    0x0,

    /* U+F185 "" */
    0x0, 0x0, 0x0, 0x0, 0x1, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x73, 0x0, 0xc, 0xff, 0xd0, 0x0, 0x37,
    0x10, 0x0, 0x0, 0x1f, 0xfe, 0x97, 0xff, 0xff,
    0x88, 0xef, 0xf3, 0x0, 0x0, 0x0, 0xcf, 0xff,
    0xff, 0xcc, 0xef, 0xff, 0xfd, 0x0, 0x0, 0x0,
    0x6, 0xff, 0xf6, 0x14, 0x41, 0x6f, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x1f, 0xf4, 0x5f, 0xff, 0xf6,
    0x3f, 0xf2, 0x0, 0x0, 0x0, 0x4c, 0xf9, 0x3f,
    0xff, 0xff, 0xf4, 0x7f, 0xd5, 0x0, 0x3, 0xcf,
    0xff, 0x39, 0xff, 0xff, 0xff, 0xa1, 0xff, 0xfc,
    0x40, 0xdf, 0xff, 0xf1, 0xaf, 0xff, 0xff, 0xfc,
    0xf, 0xff, 0xff, 0x1, 0x8f, 0xff, 0x18, 0xff,
    0xff, 0xff, 0x90, 0xff, 0xf9, 0x10, 0x0, 0x18,
    0xf6, 0x1e, 0xff, 0xff, 0xf2, 0x4f, 0x91, 0x0,
    0x0, 0x0, 0x1f, 0xd0, 0x2c, 0xff, 0xd3, 0xc,
    0xf2, 0x0, 0x0, 0x0, 0x6, 0xff, 0xb1, 0x1,
    0x10, 0xb, 0xff, 0x70, 0x0, 0x0, 0x0, 0xbf,
    0xff, 0xe8, 0x55, 0x8e, 0xff, 0xfc, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xfd, 0xff, 0xff, 0xdf, 0xff,
    0xf1, 0x0, 0x0, 0x2, 0xea, 0x50, 0xe, 0xff,
    0xf1, 0x5, 0xae, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xf9, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x60,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F72E "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x36, 0x50,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xaf, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xff, 0xe1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xd, 0xfd, 0x26, 0xff,
    0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34,
    0x10, 0xf, 0xf7, 0x0, 0x5, 0x77, 0x77, 0x77,
    0x77, 0x77, 0x77, 0x7c, 0xff, 0x40, 0x0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0,
    0x0, 0xe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x88,
    0x88, 0x86, 0x30, 0x28, 0x88, 0x88, 0x76, 0x10,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xa0, 0xaf, 0xff,
    0xff, 0xff, 0x60, 0xe, 0xff, 0xff, 0xff, 0xff,
    0x82, 0xff, 0xff, 0xff, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x1c, 0xfe, 0x0, 0x0, 0x0, 0x4f, 0xfc,
    0x0, 0x3, 0xbb, 0x10, 0x9f, 0xf0, 0x0, 0x0,
    0x0, 0x9f, 0xf0, 0x0, 0x3f, 0xfc, 0x9f, 0xfc,
    0x2, 0x77, 0x0, 0xa, 0xff, 0x0, 0x0, 0xbf,
    0xff, 0xff, 0x30, 0x5f, 0xfa, 0x48, 0xff, 0xa0,
    0x0, 0x0, 0x8e, 0xfc, 0x30, 0x0, 0xcf, 0xff,
    0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xaf, 0xff, 0xc2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x13, 0x20, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 400, .box_w = 25, .box_h = 19, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 238, .adv_w = 200, .box_w = 13, .box_h = 21, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 375, .adv_w = 320, .box_w = 21, .box_h = 21, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 596, .adv_w = 320, .box_w = 21, .box_h = 19, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x25, 0xc3, 0x66c
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 61634, .range_length = 1645, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t weather_20 = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};

#endif /*#if WEATHER_20*/
