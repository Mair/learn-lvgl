#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driver/gpio.h"
#include "lvgl/lvgl.h"
#include "driver/pcnt.h"

#define IS_ESP32 1
//#define IS_ARDUINO 1

#define BTN_A 39
#define BTN_B 38
#define BTN_C 37

bool encoder_read_chip(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

void initialize_encoder()
{
  gpio_pad_select_gpio(BTN_A);
  gpio_set_direction(BTN_A, GPIO_MODE_INPUT);
  gpio_set_pull_mode(BTN_A, GPIO_PULLUP_ONLY);

  gpio_pad_select_gpio(BTN_B);
  gpio_set_direction(BTN_B, GPIO_MODE_INPUT);
  gpio_set_pull_mode(BTN_B, GPIO_PULLUP_ONLY);

  gpio_pad_select_gpio(BTN_C);
  gpio_set_direction(BTN_C, GPIO_MODE_INPUT);
  gpio_set_pull_mode(BTN_C, GPIO_PULLUP_ONLY);
}

void encoder_on_chip_button()
{
  initialize_encoder();
  lv_group_t *group = lv_group_create();

  lv_indev_drv_t kb_drv;
  lv_indev_drv_init(&kb_drv);
  kb_drv.type = LV_INDEV_TYPE_ENCODER;
#if defined(IS_ESP32) || defined(IS_ARDUINO)
  kb_drv.read_cb = encoder_read_chip;
#else
  kb_drv.read_cb = mousewheel_read;
#endif
  lv_indev_t *kb_indev = lv_indev_drv_register(&kb_drv);
  lv_indev_set_group(kb_indev, group);

  lv_obj_t *container = lv_cont_create(lv_scr_act(), NULL);
  lv_obj_set_auto_realign(container, true);
  lv_cont_set_fit(container, LV_FIT_TIGHT);
  lv_cont_set_layout(container, LV_LAYOUT_COLUMN_LEFT);
  lv_obj_t *checkbox = lv_checkbox_create(container, NULL);
  lv_checkbox_set_text(checkbox, "yes or no");
  lv_group_add_obj(group, checkbox);

  lv_obj_t *spinner = lv_spinbox_create(container, NULL);
  lv_spinbox_set_range(spinner, 0, 999);
  lv_spinbox_set_digit_format(spinner, 3, 0);
  lv_group_add_obj(group, spinner);

  lv_obj_t *a_switch = lv_switch_create(container, NULL);
  lv_group_add_obj(group, a_switch);

  lv_obj_t *drop_down = lv_dropdown_create(container, NULL);
  lv_dropdown_set_options(drop_down, "America\nCanada\nAutralia\nIndia");
  lv_group_add_obj(group, drop_down);

  lv_obj_t *btn = lv_btn_create(container, NULL);
  lv_obj_t *btn_label = lv_label_create(btn, NULL);
  lv_label_set_text(btn_label, "Click me!");
  lv_group_add_obj(group, btn);
}

bool enc_pressed()
{
  return !gpio_get_level(BTN_B);
}

int enc_get_count()
{
  static int16_t count;
  static bool btnA_pressed = false;
  if(!gpio_get_level(BTN_A))
    btnA_pressed = true;
  else
  {
    if(btnA_pressed)
    {
      btnA_pressed = false;
      count--;
    }
  }

static bool btnC_pressed = false;
  if(!gpio_get_level(BTN_C))
    btnC_pressed = true;
  else
  {
    if(btnC_pressed)
    {
      btnC_pressed = false;
      count++;
    }
  }
    
  return count;
}

bool encoder_read_chip(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
  static int32_t last_encoder_diff = 0;
  int32_t encoder_val = enc_get_count();
  int32_t encoder_diff = encoder_val - last_encoder_diff;
  data->enc_diff = encoder_diff;
  last_encoder_diff = encoder_val;

  if (enc_pressed())
    data->state = LV_INDEV_STATE_PR;
  else
    data->state = LV_INDEV_STATE_REL;
  return false;
}
