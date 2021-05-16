#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifndef COMPLETED


void grouped_widgets(void)
{
	//lists();
	btn_matrix();
}

void list_btn_clicked(lv_obj_t *btn, lv_event_t event)
{
	if(event == LV_EVENT_CLICKED)
	{
		printf("%s was pressed\n", lv_list_get_btn_text(btn));
		fflush(NULL);
	}
}

void lists(void)
{

}

static const char * btn_map[] = {"1", "2", "3","\n",
								 "4", "5", "6","\n",
								 "7", "8", "9","\n",
								 "#ff0000 0#", ".", "\n",
								 "+", "-", "*", "/", "\n",
								 "=", ""
};

void on_btnm_cb(lv_obj_t* obj, lv_event_t event)
{
	if(event == LV_EVENT_VALUE_CHANGED)
	{
		const char * txt = lv_btnmatrix_get_active_btn_text(obj);
		printf("%s was pressed\n",txt);
		fflush(NULL);
	}
}

void btn_matrix(void)
{

}

#endif
