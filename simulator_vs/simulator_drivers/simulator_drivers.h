#ifndef simulator_drivers_h
#define simulator_drivers_h

#include "../../lvgl/lvgl.h"

bool keyboard_read(lv_indev_drv_t* indev_drv, lv_indev_data_t* data);
bool mousewheel_read(lv_indev_drv_t* indev_drv, lv_indev_data_t* data);

#endif // !simulator_drivers

