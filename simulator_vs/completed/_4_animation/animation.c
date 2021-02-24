#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED

void ready_cb(lv_anim_t *old_anim);

void animation(char *message)
{
	lv_obj_t * toast = lv_obj_create(lv_scr_act(),NULL);
	uint16_t height = 30;
	lv_obj_set_size(toast,lv_obj_get_width_fit(lv_scr_act()),height);
	lv_obj_set_y(toast,lv_obj_get_height_fit(lv_scr_act()) - height);
	lv_obj_set_style_local_bg_color(toast,LV_OBJ_PART_MAIN, LV_STATE_DEFAULT,LV_COLOR_GREEN);
	lv_obj_set_style_local_text_color(toast,LV_OBJ_PART_MAIN, LV_STATE_DEFAULT,LV_COLOR_WHITE);
	lv_obj_t* lbl = lv_label_create(toast,NULL);
	lv_label_set_text(lbl, message);
	lv_obj_align(lbl,NULL,LV_ALIGN_CENTER,0,0);

	lv_anim_t a;
	lv_anim_init(&a);
	lv_anim_set_var(&a,toast);

	/*MANDATORY SETTINGS */
	lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_x);
	lv_anim_set_values(&a,lv_obj_get_width_fit(lv_scr_act()) * -1,0);
	lv_anim_set_time(&a, 1000);
	/*OPTIONAL */
	lv_anim_set_ready_cb(&a,ready_cb);

	/*

	lv_anim_path_t path;
	lv_anim_path_init(&path);
	lv_anim_path_set_cb(&path, lv_anim_path_linear);
	lv_anim_set_path(&a,&path);

	lv_anim_set_playback_time(&a, 1000);
	lv_anim_set_playback_delay(&a, 1000);

	lv_anim_set_repeat_count(&a,2);
	lv_anim_set_repeat_delay(&a, 1000);
	*/
	///////////////////
	lv_anim_start(&a);

}


void set_opa(lv_obj_t* obj, uint16_t val)
{
	lv_obj_set_style_local_opa_scale(obj,LV_OBJ_PART_MAIN, LV_STATE_DEFAULT,val);
}


void ready_cb(lv_anim_t *old_anim)
{
	lv_obj_t * toast = old_anim->var;

	lv_anim_t a;
	lv_anim_init(&a);
	lv_anim_set_var(&a,toast);

	lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)set_opa);
	lv_anim_set_values(&a,255,0);
	lv_anim_set_time(&a, 1000);
	lv_anim_set_delay(&a,1000);

	lv_anim_start(&a);

}

#endif
