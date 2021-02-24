#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


void layout(void)
{
	lv_obj_t * container = lv_cont_create(lv_scr_act(),NULL);
	lv_obj_set_size(container,300,200);
	lv_obj_align(container, NULL,LV_ALIGN_CENTER,0,0);



	lv_obj_t * btn = lv_btn_create(lv_scr_act(),NULL);
	lv_obj_t * btn_label =lv_label_create(btn,NULL);
	lv_label_set_text(btn_label, "Click me!");

	lv_obj_align(btn, container,LV_ALIGN_IN_BOTTOM_LEFT,0,0);



	lv_obj_t *checkbox = lv_checkbox_create(lv_scr_act(),NULL);
	lv_checkbox_set_text(checkbox, "yes or no");
	lv_obj_align(checkbox, btn,LV_ALIGN_OUT_RIGHT_MID,20,-20);

	lv_obj_t *a_switch = lv_switch_create(lv_scr_act(),NULL);
	lv_obj_align(a_switch, NULL,LV_ALIGN_IN_BOTTOM_RIGHT,0,-10);

	lv_obj_t *drop_down = lv_dropdown_create(lv_scr_act(),NULL);
	lv_dropdown_set_options(drop_down,"America\nCanada\nAutralia\nIndia");

	lv_obj_align(drop_down, container,LV_ALIGN_OUT_BOTTOM_LEFT,0,20);


}

#endif

