#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED

void styles_starter(void)
{
	lv_obj_t* btn1 = lv_btn_create(lv_scr_act(),NULL);
	lv_obj_t* label = lv_label_create(btn1,NULL);
	lv_label_set_text(label,"button");

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_LIME);
    lv_style_set_radius(&style, LV_STATE_DEFAULT,0);
    lv_style_set_border_color(&style, LV_STATE_DEFAULT,LV_COLOR_BLACK);
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, LV_COLOR_AQUA);

    lv_obj_add_style(btn1,LV_BTN_PART_MAIN ,&style);
}

#endif
