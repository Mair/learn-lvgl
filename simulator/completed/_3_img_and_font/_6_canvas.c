#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifdef COMPLETED

#define CANVAS_WIDTH 200
#define CANVAS_HEIGHT 200

void draw_canvas(void)
{
	static uint8_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

	lv_obj_t* canvas = lv_canvas_create(lv_scr_act(), NULL);
	lv_canvas_set_buffer(canvas,cbuf,CANVAS_WIDTH,CANVAS_HEIGHT,LV_IMG_CF_TRUE_COLOR);
	lv_obj_align(canvas,NULL, LV_ALIGN_CENTER,0,0);
	lv_canvas_fill_bg(canvas, LV_COLOR_GRAY, LV_OPA_COVER);

	lv_point_t points[] = {{.x=50, .y=30}, {.x=150, .y=30}, {.x=100, .y=150}};

	lv_draw_rect_dsc_t rect_dsc;
	lv_draw_rect_dsc_init(&rect_dsc);
	rect_dsc.radius = 10;
	rect_dsc.bg_opa = LV_OPA_COVER;
	rect_dsc.bg_grad_dir = LV_GRAD_DIR_HOR;
	rect_dsc.bg_color = LV_COLOR_RED;
	rect_dsc.bg_grad_color = LV_COLOR_BLUE;
	rect_dsc.border_width = 2;
	rect_dsc.border_opa = LV_OPA_90;
	rect_dsc.border_color = LV_COLOR_WHITE;
	rect_dsc.shadow_width = 5;
	rect_dsc.shadow_ofs_x = 5;
	rect_dsc.shadow_ofs_y = 5;

	lv_canvas_draw_polygon(canvas,points,3,&rect_dsc );

	lv_draw_label_dsc_t label_dsc;
	lv_draw_label_dsc_init(&label_dsc);
	label_dsc.color = LV_COLOR_YELLOW;

	lv_canvas_draw_text(canvas,50,10,100,&label_dsc,"A Triangle!",LV_LABEL_ALIGN_CENTER);

	static lv_color_t cbuf_tmp[CANVAS_WIDTH * CANVAS_HEIGHT];
	memcpy(cbuf_tmp,cbuf, sizeof(cbuf_tmp));

	lv_img_dsc_t img;
	img.data = cbuf_tmp;
	img.header.cf = LV_IMG_CF_TRUE_COLOR;
	img.header.w = CANVAS_WIDTH;
	img.header.h = CANVAS_HEIGHT;

	lv_canvas_fill_bg(canvas, LV_COLOR_GRAY, LV_OPA_COVER);
	lv_canvas_transform(canvas,&img,900,LV_IMG_ZOOM_NONE,0,0,CANVAS_WIDTH /2,CANVAS_HEIGHT /2,true);


}

#endif
