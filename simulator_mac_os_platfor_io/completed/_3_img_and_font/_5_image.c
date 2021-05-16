#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED

LV_IMG_DECLARE(cofee_true_color)
LV_IMG_DECLARE(butterfly)

void image(void)
{
	lv_obj_t * img = lv_img_create(lv_scr_act(),NULL);
	lv_img_set_src(img,&cofee_true_color);
	lv_img_set_zoom(img,350);

	lv_obj_t * img_butterfly = lv_img_create(lv_scr_act(),NULL);
	lv_img_set_src(img_butterfly,&butterfly);
	lv_obj_set_pos(img_butterfly, 500, 50);
	lv_img_set_angle(img_butterfly, 300);

	lv_obj_set_style_local_image_recolor_opa(img_butterfly,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,150);
	lv_obj_set_style_local_image_recolor(img_butterfly,LV_IMG_PART_MAIN,LV_STATE_DEFAULT, LV_COLOR_BLUE);



}


#endif
