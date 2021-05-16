#include <stdio.h>
#include <string.h>
#include "../../course_main.h"
#ifndef COMPLETED


void base_obj(void)
{

  printf("Hello World!\n");
  printf("NOTE: a carriage return and fflush(NULL) is required for printf to display on screen!\n");

  lv_obj_t * base_obj = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_drag(base_obj, true);
  lv_obj_set_size(base_obj, 150, 120);
  lv_obj_set_pos(base_obj, (LV_HOR_RES - lv_obj_get_width(base_obj))/2, (LV_VER_RES-lv_obj_get_height(base_obj))/2);  // center base_obj on screen 
  printf("base object is at position %d, %d \n", lv_obj_get_x(base_obj), lv_obj_get_y(base_obj));

  printf("config size is %d, %d\n", LV_HOR_RES_MAX, LV_VER_RES_MAX);

  printf("Goodbye! End-of-Program.\n");
  fflush(NULL);

}

#endif
