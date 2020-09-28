#ifndef _COURSE_MAIN_H_
#define _COURSE_MAIN_H_

#include "../lvgl/lvgl.h"
// un-comment this, if you want to run the completed solution
#define COMPLETED

void course_main(void);

/*********************
 * Widgets
 ********************/
void base_obj(void);
void widget(void);
void label(void);
void form(void);
void btn_check(void);
void layout(void);
void containers(void);
void page(void);
void window(void);
void tab(void);
void grouped_widgets(void);
void lists(void);
void btn_matrix(void);
void display_widgets(void);
void draw_chart(void);
void draw_gauge(void);

/***********************
 * Styles
 **********************/
void styles_starter(void);
void styles_basic(void);
void styles_local(void);
void styles_parts(void);
void styles_advanced(void);

/**********************
 * Image and fonts
 *********************/
void fonts(void);
void custom_fonts(void);
void custom_font_symbols(void);
void image(void);
void draw_canvas(void);

/**********************
 * Animations
 *********************/
void animation(char *message);

/**********************
* Groups and inputs
*********************/
void external_button_on_screen(void);
void keyboard_with_groups(void);
void keyboard_on_chip(void);
void encoder_on_chip(void);
void groups_more(void);
void text_input(void);

#endif /* _COURSE_MAIN_H_ */
