#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/mousewheel.h"

#ifdef COMPLETED

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

  lv_obj_t * container = lv_cont_create(lv_scr_act(),NULL);
  lv_obj_set_auto_realign(container,true);
  lv_cont_set_fit(container,LV_FIT_TIGHT);
  lv_cont_set_layout(container,LV_LAYOUT_COLUMN_LEFT);
  lv_obj_t *checkbox = lv_checkbox_create(container,NULL);
  lv_checkbox_set_text(checkbox, "yes or no");
  lv_group_add_obj(group,checkbox);

  lv_obj_t * spinner = lv_spinbox_create(container,NULL);
  lv_spinbox_set_range(spinner, 0, 999);
  lv_spinbox_set_digit_format(spinner,3,0);
  lv_group_add_obj(group,spinner);

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

bool enc_pressed()
{
	}
int enc_get_count(){

}

bool encoder_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
	static int32_t last_encoder_diff = 0;
	int encoder_val = enc_get_count();
	int32_t encoder_diff = encoder_val - last_encoder_diff;
	data->enc_diff  = encoder_diff;
	last_encoder_diff = encoder_val;

	if(enc_pressed())
			data->state = LV_INDEV_STATE_PR;
	else
		data->state = LV_INDEV_STATE_REL;

    return false;
}

#endif
