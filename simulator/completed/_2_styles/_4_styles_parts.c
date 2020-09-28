#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


void styles_parts(void)
{
	//LV_SWITCH_PART_BG: main part
	//LV_SWITCH_PART_INDIC: the indicator (virtual part)
	//LV_SWITCH_PART_KNOB: the knob (virtual part)

	lv_switch_create(lv_scr_act(), NULL);

	lv_obj_t* dip = lv_switch_create(lv_scr_act(), NULL);
	lv_obj_align(dip,NULL,LV_ALIGN_CENTER,0,0);
	lv_obj_set_height(dip, 20);

	static lv_style_t style_bg;
	lv_style_init(&style_bg);

	lv_style_set_radius(&style_bg,LV_STATE_DEFAULT,0);
	lv_style_set_border_color(&style_bg,LV_STATE_DEFAULT,LV_COLOR_BLUE);
	lv_style_set_border_width(&style_bg,LV_STATE_DEFAULT,3);
	lv_style_set_outline_color(&style_bg,LV_STATE_DEFAULT,LV_COLOR_BLUE);
	lv_style_set_pad_top(&style_bg,LV_STATE_DEFAULT,5);
	lv_style_set_pad_bottom(&style_bg,LV_STATE_DEFAULT,5);
	lv_style_set_bg_color(&style_bg,LV_STATE_DEFAULT,LV_COLOR_BLACK);

	static lv_style_t style_knob;
	lv_style_init(&style_knob);
	lv_style_set_radius(&style_knob,LV_STATE_DEFAULT,0);
	lv_style_set_bg_color(&style_knob,LV_STATE_DEFAULT,LV_COLOR_RED);
	lv_style_set_pad_bottom(&style_knob,LV_STATE_DEFAULT,0);
	lv_style_set_pad_top(&style_knob,LV_STATE_DEFAULT,0);
	lv_style_set_pad_left(&style_knob,LV_STATE_DEFAULT,0);
	lv_style_set_pad_right(&style_knob,LV_STATE_DEFAULT,0);

	static lv_style_t style_indic;
	lv_style_init(&style_indic);
	lv_style_set_radius(&style_indic,LV_STATE_DEFAULT,0);
	lv_style_set_bg_color(&style_indic,LV_STATE_DEFAULT,LV_COLOR_WHITE);


	lv_obj_add_style(dip,LV_SWITCH_PART_BG,&style_bg);
	lv_obj_add_style(dip,LV_SWITCH_PART_KNOB,&style_knob);
	lv_obj_add_style(dip,LV_SWITCH_PART_INDIC,&style_indic);

	lv_obj_set_style_local_value_str(dip,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,"0");
	lv_obj_set_style_local_value_str(dip,LV_SWITCH_PART_KNOB,LV_STATE_CHECKED,"1");

}

#endif
