#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


void fonts(void)
{
	static lv_style_t style;
	lv_style_init(&style);
	lv_style_set_text_font(&style, LV_STATE_DEFAULT,&lv_font_montserrat_30);

	lv_obj_t * lbl = lv_label_create(lv_scr_act(), NULL);
	lv_obj_align(lbl,NULL,LV_ALIGN_CENTER,0,0);
	lv_label_set_text(lbl,"Hello World!");
	lv_obj_add_style(lbl,LV_LABEL_PART_MAIN,&style);
}

#endif
