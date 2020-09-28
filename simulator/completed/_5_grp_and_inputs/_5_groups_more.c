#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#include "lv_drivers/indev/keyboard.h"

#ifdef COMPLETED
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

	menu = lv_list_create(lv_scr_act(),NULL);
	lv_obj_set_width(menu,lv_obj_get_width_fit(lv_scr_act()));
	lv_obj_t* list_btn = lv_list_add_btn(menu,LV_SYMBOL_EDIT,"Fill out form");
	lv_obj_set_event_cb(list_btn,render_form_handler);

	lv_group_add_obj(group, menu);

	list_btn = lv_list_add_btn(menu,LV_SYMBOL_WIFI,"Another Option");
	list_btn = lv_list_add_btn(menu,LV_SYMBOL_BATTERY_1,"Yet Another Option");

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
	lv_group_remove_all_objs(group);
	lv_obj_t * container = lv_win_create(lv_scr_act(),NULL);
	lv_win_set_title(container,"A Form");
	lv_win_set_layout(container,LV_LAYOUT_COLUMN_MID);
	lv_obj_t *close_btn = lv_win_add_btn(container, LV_SYMBOL_CLOSE);
	lv_obj_set_event_cb(close_btn,form_windows_close_handler);
	lv_group_add_obj(group,close_btn);
	lv_obj_set_style_local_outline_color(close_btn,LV_CHECKBOX_PART_BG,LV_STATE_FOCUSED,LV_COLOR_MAGENTA);
	lv_obj_set_style_local_outline_width(close_btn,LV_CHECKBOX_PART_BG,LV_STATE_FOCUSED,3);

	lv_obj_t *checkbox = lv_checkbox_create(container,NULL);
	lv_checkbox_set_text(checkbox, "yes or no");
	lv_group_add_obj(group,checkbox);
	lv_obj_set_style_local_outline_color(checkbox,LV_CHECKBOX_PART_BG,LV_STATE_FOCUSED,LV_COLOR_MAGENTA);


	lv_obj_t *a_switch = lv_switch_create(container,NULL);
	lv_group_add_obj(group,a_switch);

	lv_obj_t *drop_down = lv_dropdown_create(container,NULL);
	lv_dropdown_set_options(drop_down,"America\nCanada\nAutralia\nIndia");
	lv_group_add_obj(group,drop_down);
	lv_group_focus_obj(drop_down);
	lv_obj_set_style_local_border_color(drop_down,LV_DROPDOWN_PART_MAIN,LV_STATE_FOCUSED,LV_COLOR_MAGENTA);
	lv_obj_set_event_cb(drop_down,ddlist_event_handler);


	lv_obj_t * btn = lv_btn_create(container,NULL);
	lv_obj_t * btn_label =lv_label_create(btn,NULL);
	lv_label_set_text(btn_label, "Click me!");
	lv_group_add_obj(group,btn);
	lv_group_set_focus_cb(group,focus_cb);
}


static void focus_cb(lv_group_t * group)
{
	lv_obj_t* obj = lv_group_get_focused(group);
	lv_obj_type_t lv_obj_type;
	lv_obj_get_type(obj,&lv_obj_type);
	printf("focused on %s\n",lv_obj_type.type[0]);
	fflush(NULL);
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
