#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifndef COMPLETED



void widget(void)
{
	printf("Widget & Events\n");
	label();
	//form();
	//btn_check();

	printf("Done!\n");
	fflush(NULL);
}

void label(void)
{
	lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL );
	lv_label_set_recolor(label1, true);
	lv_label_set_long_mode(label1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(label1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
	lv_obj_set_width(label1, 250);
	lv_obj_set_pos(label1, 100, 50);
	lv_label_set_text(label1, "#ff0000 Hello# #0000ff World\n #00f0ff This is a ##887623 new line.\n #449977 And another ##0000ff new line!");
	
}

lv_obj_t *label_status;
void on_check_changed(lv_obj_t * checkbox, lv_event_t event)
{

}

void on_switch_changed(lv_obj_t * lv_switch, lv_event_t event)
{

}

void on_dropdown_changed(lv_obj_t * dropdown, lv_event_t event)
{

}

void btn_envent_handler(lv_obj_t * dropdown, lv_event_t event)
{
}

void form(void)
{
}

void btn_check_cb(lv_obj_t* btn, lv_event_t event)
{

}

void btn_check(void)
{

}

#endif
