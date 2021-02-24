#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED


void containers(void)
{
	//page();
	//window();
	tab();
}

void page(void)
{
	lv_obj_t * page = lv_page_create(lv_scr_act(),NULL);
	lv_obj_set_size(page, 150,200);
	lv_obj_align(page,NULL,LV_ALIGN_CENTER,0,0);

	lv_obj_t * label = lv_label_create(page, NULL);
	lv_label_set_text(label,"Powerful building blocks such as buttons, charts, lists, sliders, images etc.\n"
		"Advanced graphics with animations, anti-aliasing, opacity, smooth scrolling\n"
		"Various input devices such as touchpad, mouse, keyboard, encoder etc.\n"
		"Multi-language support with UTF-8 encoding\n"
		"Multi-display support, i.e. use more TFT, monochrome displays simultaneously\n"
		"Fully customizable graphic elements\n"
		"Hardware independent to use with any microcontroller or display\n"
		"Scalable to operate with little memory (64 kB Flash, 16 kB RAM)\n"
		"OS, External memory and GPU supported but not required\n"
		"Single frame buffer operation even with advanced graphical effects\n"
		"Written in C for maximal compatibility (C++ compatible)\n"
		"Simulator to start embedded GUI design on a PC without embedded hardware\n"
		"Binding to MicroPython\n"
		"Tutorials, examples, themes for rapid GUI design\n"
		"Documentation is available as online and offline\n"
		"Free and open-source under MIT license\n");
	lv_label_set_long_mode(label,LV_LABEL_LONG_BREAK);
	lv_obj_set_width(label, lv_page_get_width_fit(page));
}

void on_settings_handler(lv_obj_t* btn, lv_event_t event)
{
	if(event == LV_EVENT_CLICKED)
	{
		//do something
	}
	lv_win_close_event_cb(btn, event);
}

void window(void)
{
	lv_obj_t *win = lv_win_create(lv_scr_act(), NULL);
	lv_win_set_title(win,"MY Window");
	lv_win_set_header_height(win, 20);
	lv_obj_t* close_btn = lv_win_add_btn(win,LV_SYMBOL_CLOSE);
	lv_obj_set_event_cb(close_btn, lv_win_close_event_cb);

	lv_obj_t* settings_btn = lv_win_add_btn(win,LV_SYMBOL_SETTINGS);
	lv_obj_set_event_cb(settings_btn, on_settings_handler);
    lv_win_add_btn(win,LV_SYMBOL_CHARGE);

    lv_obj_t * label = lv_label_create(win, NULL);
	lv_label_set_text(label,"Powerful building blocks such as buttons, charts, lists, sliders, images etc.\n"
		"Advanced graphics with animations, anti-aliasing, opacity, smooth scrolling\n"
		"Various input devices such as touchpad, mouse, keyboard, encoder etc.\n"
		"Multi-language support with UTF-8 encoding\n"
		"Multi-display support, i.e. use more TFT, monochrome displays simultaneously\n"
		"Fully customizable graphic elements\n"
		"Hardware independent to use with any microcontroller or display\n"
		"Scalable to operate with little memory (64 kB Flash, 16 kB RAM)\n"
		"OS, External memory and GPU supported but not required\n"
		"Single frame buffer operation even with advanced graphical effects\n"
		"Written in C for maximal compatibility (C++ compatible)\n"
		"Simulator to start embedded GUI design on a PC without embedded hardware\n"
		"Binding to MicroPython\n"
		"Tutorials, examples, themes for rapid GUI design\n"
		"Documentation is available as online and offline\n"
		"Free and open-source under MIT license\n");
	lv_label_set_long_mode(label,LV_LABEL_LONG_BREAK);
	lv_obj_set_width(label, lv_obj_get_width_fit(win));

}

void tab(void)
{
	lv_obj_t * tab_view = lv_tabview_create(lv_scr_act(), NULL);
	lv_tabview_set_btns_pos(tab_view,LV_TABVIEW_TAB_POS_BOTTOM);


	lv_obj_t * tab1 = lv_tabview_add_tab(tab_view,"tab 1");
	lv_obj_t * tab2 = lv_tabview_add_tab(tab_view,"tab 2");
	lv_obj_t * tab3 = lv_tabview_add_tab(tab_view,"tab 3");

	lv_obj_t * label1 = lv_label_create(tab1,NULL);
	lv_label_set_text(label1,"first tab content");

	lv_obj_t * label2 = lv_label_create(tab2,NULL);
	lv_label_set_text(label2,"second tab content");


	 lv_obj_t * label = lv_label_create(tab3, NULL);
		lv_label_set_text(label,"Powerful building blocks such as buttons, charts, lists, sliders, images etc.\n"
			"Advanced graphics with animations, anti-aliasing, opacity, smooth scrolling\n"
			"Various input devices such as touchpad, mouse, keyboard, encoder etc.\n"
			"Multi-language support with UTF-8 encoding\n"
			"Multi-display support, i.e. use more TFT, monochrome displays simultaneously\n"
			"Fully customizable graphic elements\n"
			"Hardware independent to use with any microcontroller or display\n"
			"Scalable to operate with little memory (64 kB Flash, 16 kB RAM)\n"
			"OS, External memory and GPU supported but not required\n"
			"Single frame buffer operation even with advanced graphical effects\n"
			"Written in C for maximal compatibility (C++ compatible)\n"
			"Simulator to start embedded GUI design on a PC without embedded hardware\n"
			"Binding to MicroPython\n"
			"Tutorials, examples, themes for rapid GUI design\n"
			"Documentation is available as online and offline\n"
			"Free and open-source under MIT license\n");
		lv_label_set_long_mode(label,LV_LABEL_LONG_BREAK);
		lv_obj_set_width(label, lv_page_get_width_fit(tab3));
}


#endif
