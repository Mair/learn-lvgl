#include <stdio.h>
#include <string.h>
#include "../../course_main.h"

#ifdef COMPLETED
static lv_obj_t * _led;

static void btn_event_cb(lv_obj_t* btn, lv_event_t event);
static void lv_gpio_init(void);
static bool button_read(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data);


void external_button_on_screen()
{
	lv_gpio_init();
	lv_indev_drv_t input_device_driver;
	lv_indev_drv_init(&input_device_driver);
	input_device_driver.type = LV_INDEV_TYPE_BUTTON;
	input_device_driver.read_cb = button_read;
	lv_indev_t *button_input_device = lv_indev_drv_register(&input_device_driver);

	lv_obj_t* btn = lv_btn_create(lv_scr_act(),NULL);
	lv_obj_set_style_local_value_str(btn, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,"Click me!");
	lv_obj_set_event_cb(btn,btn_event_cb);
	lv_obj_align(btn,NULL, LV_ALIGN_CENTER,0,0);

	static lv_point_t pionts[4];
	pionts[0].x = lv_obj_get_x(btn);
	pionts[0].y = lv_obj_get_y(btn);

	pionts[1].x = lv_obj_get_x(btn);
	pionts[1].y = lv_obj_get_y(btn) + lv_obj_get_height(btn);

	pionts[2].x = lv_obj_get_x(btn) + lv_obj_get_width(btn);
	pionts[2].y = lv_obj_get_y(btn);

	pionts[3].x = lv_obj_get_x(btn) + lv_obj_get_width(btn);
	pionts[3].y = lv_obj_get_y(btn)+ lv_obj_get_height(btn);



//	lv_obj_t *obj =  lv_obj_create(lv_scr_act(), NULL);
//	lv_obj_set_style_local_bg_color(obj,LV_OBJ_PART_MAIN, LV_STATE_DEFAULT,LV_COLOR_BLACK);
//	lv_obj_set_size(obj,10,10);
//	lv_obj_set_pos(obj,pionts[3].x, pionts[3].y );

	lv_indev_set_button_points(button_input_device,pionts);

	_led = lv_led_create(lv_scr_act(),NULL);
	lv_obj_align(_led,NULL, LV_ALIGN_CENTER,0,-80);
	lv_led_off(_led);
}

static void btn_event_cb(lv_obj_t* btn, lv_event_t event)
{
	if(event == LV_EVENT_PRESSING || event == LV_EVENT_LONG_PRESSED|| event == LV_EVENT_LONG_PRESSED_REPEAT)
		lv_led_on(_led);
	else
		lv_led_off(_led);
}

static void lv_gpio_init(void)
{
	//initialize GPIO
}

static bool button_read(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
	//read gpio
	if(rand() %20 == 1)
		data->state =LV_INDEV_STATE_PR;
	 else
		data->state =LV_INDEV_STATE_REL;
	return false;
}

#endif

