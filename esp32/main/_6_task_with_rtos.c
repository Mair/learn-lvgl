#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lvgl/lvgl.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

static lv_chart_series_t *series;
lv_obj_t *chart;

typedef struct internet_payload_t{
    int pressure;
}internet_payload_t;

xQueueHandle internet_data_queue;

void get_internet_data(void *params)
{
    internet_data_queue = xQueueCreate(10,sizeof(internet_payload_t));
    while (true)
    {
        //go out to internet
        internet_payload_t internet_payload = {
            .pressure = rand() % 100
        };

        printf("got reading from interne=%d\n", internet_payload.pressure);
        xQueueSend(internet_data_queue,&internet_payload,pdMS_TO_TICKS(1000));

        //lv_chart_set_next(chart, series, ????);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
}


void task_cb(lv_task_t task)
{

    internet_payload_t internet_payload;
    if(xQueueReceive(internet_data_queue,&internet_payload,0))
    {
        lv_chart_set_next(chart, series, internet_payload.pressure);
    }
    
}

void task_with_rtos(void)
{
    xTaskCreate(get_internet_data, "get_internet_data", 1024 * 4, NULL, 5, NULL);

    lv_task_t *task = lv_task_create(task_cb, 500, LV_TASK_PRIO_MID, NULL);

    chart = lv_chart_create(lv_scr_act(), NULL);
    series = lv_chart_add_series(chart, LV_COLOR_BLUE);
}
