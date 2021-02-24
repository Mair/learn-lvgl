#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED

void styles_basic(void)
{
	//simple style*************************************************************************/
	lv_obj_t* btn1 = lv_btn_create(lv_scr_act(),NULL);
	lv_obj_t* label = lv_label_create(btn1,NULL);
	lv_label_set_text(label,"button");
	/**************/

	static lv_style_t style1;
	lv_style_init(&style1);
	lv_style_set_bg_color(&style1,LV_STATE_DEFAULT,LV_COLOR_LIME);
	lv_obj_add_style(btn1,LV_BTN_PART_MAIN,&style1);

	//add multiple styles
	lv_obj_t* btn2 = lv_btn_create(lv_scr_act(),NULL);
	lv_obj_set_pos(btn2,80,30);
	lv_label_create(btn2,label);

	static lv_style_t style2;
	lv_style_init(&style2);
	lv_style_set_border_color(&style2,LV_STATE_DEFAULT, LV_COLOR_ORANGE);
	lv_style_set_border_width(&style2,LV_STATE_DEFAULT,10);
	lv_style_set_bg_color(&style2,LV_STATE_PRESSED,LV_COLOR_AQUA);

	lv_obj_add_style(btn2,LV_BTN_PART_MAIN,&style1);
	lv_obj_add_style(btn2,LV_BTN_PART_MAIN,&style2);

	/************************/

	lv_obj_t* btn3 = lv_btn_create(lv_scr_act(),NULL);
	lv_obj_set_pos(btn3,160,60);
	lv_label_create(btn3,label);

	static lv_style_t copied_style;
	lv_style_init(&copied_style);
	lv_style_copy(&copied_style,&style2);
	lv_style_set_bg_color(&copied_style,LV_STATE_DEFAULT,lv_color_hex(0x6b178a));
	lv_style_set_bg_opa(&copied_style,LV_STATE_DEFAULT,100);

	lv_obj_add_style(btn3,LV_BTN_PART_MAIN,&copied_style);


}

#endif
