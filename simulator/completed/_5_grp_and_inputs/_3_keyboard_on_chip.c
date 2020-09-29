#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/keyboard.h"

#ifdef COMPLETED

//#define IS_ESP32 1
//#define IS_ARDUINO 1

bool keyboard_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

void keyboard_on_chip()
{
  lv_group_t* group = lv_group_create();

  lv_indev_drv_t kb_drv;
  lv_indev_drv_init(&kb_drv);
  kb_drv.type = LV_INDEV_TYPE_KEYPAD;
#if defined(IS_ESP32) || defined(IS_ARDUINO)
  kb_drv.read_cb = keyboard_read_chip;
#else
  kb_drv.read_cb = keyboard_read;
#endif
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

bool keyboard_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
	static int last_key;
	int incoming_byte = 0;
#ifdef IS_ESP32
	incoming_byte = getchar();
#elif IS_ARDUINO
	incoming_byte = Serial.read();
#endif

	switch(incoming_byte)
	{
	case '+':
		last_key = LV_KEY_RIGHT;
		break;
	case '-':
		last_key = LV_KEY_LEFT;
		break;
/******** for arduino******/
	case '*':
		last_key = LV_KEY_NEXT;
		break;
	case '.':
		last_key = LV_KEY_ENTER;
		break;
	case -1:
		break;
	default:
		last_key = incoming_byte;
		break;
	}

    data->state = incoming_byte == -1? LV_INDEV_STATE_REL: LV_INDEV_STATE_PR;
    data->key = last_key;
    return false;
}

#endif
