#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED



void widget(void)
{
	printf("widget\n");
	//label();
	//form();
	btn_check();
	fflush(NULL);
}

void label(void)
{
	lv_obj_t * label1 = lv_label_create(lv_scr_act(),NULL);
	lv_label_set_text(label1,"Hello World!\nthis is another line\nand another");
	lv_label_set_align(label1,LV_LABEL_ALIGN_CENTER);

	lv_obj_t * label2 = lv_label_create(lv_scr_act(),NULL);
	lv_label_set_recolor(label2,true);
	lv_label_set_text_fmt(label2,"#5ce6ae Hello#  #eb1c87 World # #eb381c !# #5ce6ae %s#",LV_SYMBOL_HOME);
	lv_obj_set_y(label2, 60);

	lv_obj_t * btn = lv_btn_create(lv_scr_act(),NULL);
	lv_obj_set_y(btn, 100);

	lv_obj_t * label3 = lv_label_create(btn,NULL);
	lv_label_set_long_mode(label3,LV_LABEL_LONG_SROLL);
	lv_label_set_recolor(label3,true);
	lv_label_set_text_fmt(label3,"A very very long long text",LV_SYMBOL_HOME);
}

lv_obj_t *label_status;
void on_check_changed(lv_obj_t * checkbox, lv_event_t event)
{
	if(event == LV_EVENT_VALUE_CHANGED)
	{
		bool is_checked = lv_checkbox_is_checked(checkbox);
		lv_label_set_text_fmt(label_status,"checkbox changed to %s", is_checked? "True": "False");
	}
}

void on_switch_changed(lv_obj_t * lv_switch, lv_event_t event)
{
	if(event == LV_EVENT_VALUE_CHANGED)
	{
		bool is_checked = lv_switch_get_state(lv_switch);
		lv_label_set_text_fmt(label_status,"switch changed to %s", is_checked? "True": "False");
	}
}

void on_dropdown_changed(lv_obj_t * dropdown, lv_event_t event)
{
	if(event == LV_EVENT_VALUE_CHANGED)
	{
		char buffer[50];
		lv_dropdown_get_selected_str(dropdown,buffer,sizeof(buffer));
		lv_label_set_text_fmt(label_status,"%s was selected", buffer);
	}
}

void btn_envent_handler(lv_obj_t * dropdown, lv_event_t event)
{
	if(event == LV_EVENT_CLICKED)
	{
		lv_label_set_text(label_status,"LV_EVENT_CLICKED");
	}
	if(event == LV_EVENT_RELEASED)
	{
		lv_label_set_text(label_status,"LV_EVENT_RELEASED");
	}
}

void form(void)
{
	label_status = lv_label_create(lv_scr_act(),NULL);
	lv_obj_t * container = lv_cont_create(lv_scr_act(),NULL);
	lv_obj_set_auto_realign(container,true);
	lv_cont_set_fit(container,LV_FIT_TIGHT);
	lv_cont_set_layout(container,LV_LAYOUT_COLUMN_LEFT);
	lv_obj_t *checkbox = lv_checkbox_create(container,NULL);
	lv_checkbox_set_text(checkbox, "yes or no");
	lv_obj_set_event_cb(checkbox,on_check_changed);

	lv_obj_t *a_switch = lv_switch_create(container,NULL);
	lv_obj_set_event_cb(a_switch,on_switch_changed);

	lv_obj_t *drop_down = lv_dropdown_create(container,NULL);
	lv_dropdown_set_options(drop_down,"America\nCanada\nAutralia\nIndia");
	lv_obj_set_event_cb(drop_down,on_dropdown_changed);

	lv_obj_t * btn = lv_btn_create(container,NULL);
	lv_obj_t * btn_label =lv_label_create(btn,NULL);
	lv_label_set_text(btn_label, "Click me!");
	lv_obj_set_event_cb(btn,btn_envent_handler);
}

void btn_check_cb(lv_obj_t* btn, lv_event_t event)
{
	lv_btn_state_t state = lv_btn_get_state(btn);
	if(state == LV_BTN_STATE_CHECKED_PRESSED && event == LV_EVENT_PRESSED)
	{
		printf("pressed\n");
	}
	if(state == LV_BTN_STATE_CHECKED_RELEASED && event == LV_EVENT_VALUE_CHANGED)
	{
		printf("un-pressed\n");
	}
	fflush(NULL);

}

void btn_check(void)
{
	lv_obj_t* btn = lv_btn_create(lv_scr_act(),NULL);
	lv_btn_set_checkable(btn,true);
	lv_obj_set_event_cb(btn,btn_check_cb);
	lv_obj_t *lbl = lv_label_create(btn, NULL);
	lv_label_set_text(lbl,"click me!");

}

#endif
