#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/keyboard.h"

#ifndef COMPLETED

//#define IS_ESP32 1
//#define IS_ARDUINO 1

bool keyboard_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

void keyboard_on_chip()
{
  lv_group_t* group = lv_group_create();


  kb_drv.type = LV_INDEV_TYPE_KEYPAD;
#if defined(IS_ESP32) || defined(IS_ARDUINO)
  kb_drv.read_cb = keyboard_read_chip;
#else
  kb_drv.read_cb = keyboard_read;
#endif
  lv_indev_t* kb_indev = lv_indev_drv_register(&kb_drv);
 }

bool keyboard_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
	static int last_key;
	int incoming_byte;
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
