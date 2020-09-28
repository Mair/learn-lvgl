#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/keyboard.h"

#ifdef COMPLETED

void keyboard_with_groups()
{
	lv_group_t* group = lv_group_create();

	lv_indev_drv_t kb_drv;
	lv_indev_drv_init(&kb_drv);
	kb_drv.type = LV_INDEV_TYPE_KEYPAD;
	kb_drv.read_cb = keyboard_read;
	lv_indev_t* kb_indev = lv_indev_drv_register(&kb_drv);
	lv_indev_set_group(kb_indev,group);

	lv_obj_t * container = lv_cont_create(lv_scr_act(),NULL);
	lv_obj_set_auto_realign(container,true);
	lv_cont_set_fit(container,LV_FIT_TIGHT);
	lv_cont_set_layout(container,LV_LAYOUT_COLUMN_LEFT);
	lv_obj_t *checkbox = lv_checkbox_create(container,NULL);
	lv_checkbox_set_text(checkbox, "yes or no");
	lv_group_add_obj(group,checkbox);

	lv_obj_t *a_switch = lv_switch_create(container,NULL);
	lv_group_add_obj(group,a_switch);

	lv_obj_t *drop_down = lv_dropdown_create(container,NULL);
	lv_dropdown_set_options(drop_down,"America\nCanada\nAutralia\nIndia");
	lv_group_add_obj(group,drop_down);


	lv_obj_t * btn = lv_btn_create(container,NULL);
	lv_obj_t * btn_label =lv_label_create(btn,NULL);
	lv_label_set_text(btn_label, "Click me!");
	lv_group_add_obj(group,btn);


}


#endif
