#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifndef COMPLETED

void display_widgets(void)
{
	draw_chart();
	draw_gauge();
}

void draw_chart(void)
{
	static lv_style_t chart_style;
	lv_style_init(&chart_style);
	lv_style_set_pad_bottom(&chart_style,LV_STATE_DEFAULT,60);

}

void draw_gauge()
{

}

#endif



