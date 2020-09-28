#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/mousewheel.h"

#ifndef COMPLETED

//#define IS_ESP32 1
//#define IS_ARDUINO 1

bool encoder_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

void encoder_on_chip()
{
  lv_group_t* group = lv_group_create();

  lv_indev_drv_t kb_drv;
  lv_indev_drv_init(&kb_drv);
  kb_drv.type = LV_INDEV_TYPE_ENCODER;
#if defined(IS_ESP32) || defined(IS_ARDUINO)
  kb_drv.read_cb = encoder_read_chip;
#else
  kb_drv.read_cb = mousewheel_read;
#endif
  lv_indev_t* kb_indev = lv_indev_drv_register(&kb_drv);
  lv_indev_set_group(kb_indev,group);

}

bool enc_pressed()
{
}

int enc_get_count(){

}

bool encoder_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{


    return false;
}

#endif
