#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED

void base_obj(void)
{
	lv_obj_create(lv_scr_act(), NULL);
	lv_obj_t * base_obj = lv_obj_create(lv_scr_act(), NULL);
	lv_obj_set_drag(base_obj,true);
	lv_obj_set_size(base_obj, 200,200);
	lv_obj_set_pos(base_obj,200, 200);
	printf("base obj is at %d, %d\n", lv_obj_get_x(base_obj), lv_obj_get_y(base_obj));

	lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_drag(btn,true);
	lv_obj_set_size(btn, 100,100);
	lv_obj_set_pos(btn,100, 100);

	lv_obj_t *led = lv_led_create(lv_scr_act(), NULL);
	lv_obj_set_drag(led,true);
	lv_obj_set_pos(led,50, 50);
	lv_led_on(led);

	fflush(NULL);
}

#endif
