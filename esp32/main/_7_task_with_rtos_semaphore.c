#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lvgl/lvgl.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

static lv_chart_series_t *series;
static lv_obj_t *chart;

typedef struct internet_payload_t{
    int pressure;
}internet_payload_t;

extern SemaphoreHandle_t xGuiSemaphore;

void get_internet_data(void *params)
{
    while (true)
    {
        //go out to internet
        internet_payload_t internet_payload = {
            .pressure = rand() % 100
        };

        printf("got reading from interne=%d\n", internet_payload.pressure);
        if(xSemaphoreTake(xGuiSemaphore,pdMS_TO_TICKS(1000)))
        {
            lv_chart_set_next(chart, series, internet_payload.pressure);
            xSemaphoreGive(xGuiSemaphore);
        }
        
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
}


void task_with_rtos_semaphore(void)
{
    chart = lv_chart_create(lv_scr_act(), NULL);
    series = lv_chart_add_series(chart, LV_COLOR_BLUE);

    xTaskCreate(get_internet_data, "get_internet_data", 1024 * 4, NULL, 5, NULL);


}
