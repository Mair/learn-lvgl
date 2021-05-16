#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


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
	lv_obj_t * list = lv_list_create(lv_scr_act(),NULL);
	lv_obj_set_size(list,lv_obj_get_width_fit(lv_scr_act()), lv_obj_get_height_fit(lv_scr_act()));
	lv_obj_t * btn;
	btn = lv_list_add_btn(list,LV_SYMBOL_AUDIO,"Audio");
	lv_obj_set_event_cb(btn,list_btn_clicked);
	lv_obj_t * label = lv_list_get_btn_label(btn);
	lv_label_set_recolor(label, true);
	lv_label_set_text(label,"#ff00ff Audio#");

	btn = lv_list_add_btn(list,LV_SYMBOL_BELL,"Bell");
	lv_obj_set_event_cb(btn,list_btn_clicked);
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
	lv_obj_t * btnm = lv_btnmatrix_create(lv_scr_act(),NULL);
	lv_btnmatrix_set_map(btnm,btn_map);
	lv_obj_set_height(btnm,300);
	lv_btnmatrix_set_btn_width(btnm,9,2);
	lv_btnmatrix_set_btn_ctrl(btnm,15,LV_BTNMATRIX_CTRL_CHECK_STATE);
	lv_obj_set_event_cb(btnm,on_btnm_cb);
	lv_btnmatrix_set_recolor(btnm,true);
}

#endif
