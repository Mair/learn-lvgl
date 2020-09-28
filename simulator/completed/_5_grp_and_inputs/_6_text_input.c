#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mousewheel.h"

#ifdef COMPLETED

void text_input()
{
	lv_group_t* group = lv_group_create();

	lv_indev_drv_t kb_drv;
	lv_indev_drv_init(&kb_drv);
	kb_drv.type = LV_INDEV_TYPE_KEYPAD;
	kb_drv.read_cb = keyboard_read;
	lv_indev_t* kb_indev = lv_indev_drv_register(&kb_drv);
	lv_indev_set_group(kb_indev,group);

	lv_indev_drv_t enc_drv;
	lv_indev_drv_init(&enc_drv);
	enc_drv.type = LV_INDEV_TYPE_ENCODER;
	enc_drv.read_cb = mousewheel_read;
	lv_indev_t* enc_indev = lv_indev_drv_register(&enc_drv);
	lv_indev_set_group(enc_indev,group);

	lv_obj_t * text_area = lv_textarea_create(lv_scr_act(),NULL);
	lv_textarea_set_text(text_area, "");
	lv_textarea_set_placeholder_text(text_area,"write here...");
	lv_group_add_obj(group,text_area);

	lv_obj_t* key_board = lv_keyboard_create(lv_scr_act(),NULL);
	lv_keyboard_set_textarea(key_board,text_area);
	lv_group_add_obj(group,key_board);




}

#endif
