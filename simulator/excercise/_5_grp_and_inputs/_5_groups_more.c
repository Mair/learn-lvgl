#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/keyboard.h"

#ifndef COMPLETED
static void ddlist_event_handler(lv_obj_t* obj, lv_event_t event);
static void focus_cb(lv_group_t * group);
static void action_window(lv_group_t *group);
static void render_form_handler(lv_obj_t * btn, lv_event_t event);

lv_group_t* group;
lv_obj_t* menu;


void groups_more()
{
	group = lv_group_create();

	lv_indev_drv_t kb_drv;
	lv_indev_drv_init(&kb_drv);
	kb_drv.type = LV_INDEV_TYPE_KEYPAD;
	kb_drv.read_cb = keyboard_read;
	lv_indev_t* kb_indev = lv_indev_drv_register(&kb_drv);
	lv_indev_set_group(kb_indev,group);


}

static void render_form_handler(lv_obj_t * btn, lv_event_t event)
{
	if(event == LV_EVENT_SHORT_CLICKED)
	{
		action_window(group);
	}
}

void form_windows_close_handler(lv_obj_t * btn, lv_event_t event)
{
	if(event == LV_EVENT_RELEASED)
	{
		lv_win_close_event_cb(btn, event);
		lv_group_add_obj(group, menu);
	}
}

static void action_window(lv_group_t *group)
{

}


static void focus_cb(lv_group_t * group)
{

}



static void ddlist_event_handler(lv_obj_t* obj, lv_event_t event)
{
	if(event == LV_EVENT_FOCUSED)
	{
		printf("ddlist got focus\n");
	}
	if(event == LV_EVENT_DEFOCUSED)
	{
		printf("ddlist lost focus\n");
	}
	fflush(NULL);
}

#endif
