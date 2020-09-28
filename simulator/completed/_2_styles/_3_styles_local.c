#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


void styles_local(void)
{
	lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_style_local_bg_color(btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT,LV_COLOR_MAGENTA);
	lv_obj_set_style_local_value_str(btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT,"a button");
}

#endif
