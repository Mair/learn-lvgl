#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mousewheel.h"

#ifndef COMPLETED

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

}

#endif
