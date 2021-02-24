#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED

void display_widgets(void)
{
	//draw_chart();
	draw_gauge();
}

void draw_chart(void)
{
	static lv_style_t chart_style;
	lv_style_init(&chart_style);
	lv_style_set_pad_bottom(&chart_style,LV_STATE_DEFAULT,60);

	lv_obj_t* chart = lv_chart_create(lv_scr_act(), NULL);
	lv_obj_align(chart,NULL,LV_ALIGN_CENTER,0,0);
	lv_chart_set_type(chart,LV_CHART_TYPE_LINE);
	//lv_chart_set_range(chart,40, 80);
	lv_chart_set_x_tick_texts(chart,"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\11\n12",4,LV_CHART_AXIS_DRAW_LAST_TICK);
	lv_obj_add_style(chart,LV_CHART_PART_BG ,&chart_style);

	lv_chart_series_t * series1 = lv_chart_add_series(chart,LV_COLOR_BLUE);
	lv_chart_set_next(chart,series1,50);
	lv_chart_set_next(chart,series1,60);
	lv_chart_set_next(chart,series1,40);
	lv_chart_set_next(chart,series1,50);
	lv_chart_set_next(chart,series1,60);
	lv_chart_set_next(chart,series1,40);
	lv_chart_set_next(chart,series1,50);
	lv_chart_set_next(chart,series1,60);
	lv_chart_set_next(chart,series1,40);
	lv_chart_set_next(chart,series1,80);
	lv_chart_set_next(chart,series1,40);

	series1->points[9] = 20;
	lv_chart_refresh(chart);

	lv_chart_series_t * series2 = lv_chart_add_series(chart,LV_COLOR_RED);
	lv_chart_set_next(chart,series2,20);
	lv_chart_set_next(chart,series2,60);
	lv_chart_set_next(chart,series2,30);
	lv_chart_set_next(chart,series2,80);
	lv_chart_set_next(chart,series2,90);
	lv_chart_set_next(chart,series2,20);
	lv_chart_set_next(chart,series2,20);
	lv_chart_set_next(chart,series2,40);
	lv_chart_set_next(chart,series2,20);
	lv_chart_set_next(chart,series2,30);
	lv_chart_set_next(chart,series2,60);
}

void draw_gauge()
{
	lv_obj_t* gauge = lv_gauge_create(lv_scr_act(),NULL);
	lv_gauge_set_range(gauge,0,200);
	lv_gauge_set_critical_value(gauge,160);

	static lv_color_t needel_colors[3];
	needel_colors[0] = LV_COLOR_BLUE;
	needel_colors[1] = LV_COLOR_GREEN;
	needel_colors[2] = LV_COLOR_PURPLE;

	lv_gauge_set_needle_count(gauge,3,needel_colors);

	lv_gauge_set_value(gauge,1,20);
	lv_gauge_set_value(gauge,2,60);
	lv_gauge_set_value(gauge,3,80);




}

#endif



