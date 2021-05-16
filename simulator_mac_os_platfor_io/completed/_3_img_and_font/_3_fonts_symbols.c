#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


LV_FONT_DECLARE(weather_20)
#define BOLT "\uf0e7"
#define WIND "\uf72e"
#define CLOUD "\uf0c2"
#define SUN "\uf185"

void custom_font_symbols(void)
{
	static lv_style_t style;
	lv_style_init(&style);
	lv_style_set_text_font(&style, LV_STATE_DEFAULT,&weather_20);
	lv_style_set_text_color(&style, LV_STATE_DEFAULT,LV_COLOR_MAGENTA);

	lv_obj_t * lbl = lv_label_create(lv_scr_act(), NULL);

	lv_obj_align(lbl,NULL,LV_ALIGN_CENTER,0,0);
	lv_label_set_text(lbl,BOLT WIND CLOUD SUN);
	lv_obj_add_style(lbl,LV_LABEL_PART_MAIN,&style);


}

#endif
