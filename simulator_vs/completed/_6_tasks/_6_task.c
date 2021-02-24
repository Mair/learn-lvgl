﻿#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


static lv_chart_series_t *series;
lv_obj_t* chart;

int get_temprature(void)
{
	return rand() % 100;
}

void task_cb(lv_task_t task)
{
	int reading = get_temprature();
	lv_chart_set_next(chart,series,reading);
}

void task(void)
{
	lv_task_create((lv_task_cb_t)task_cb,500,LV_TASK_PRIO_MID,NULL);

	chart = lv_chart_create(lv_scr_act(), NULL);
	series = lv_chart_add_series(chart, LV_COLOR_BLUE);
}

#endif
