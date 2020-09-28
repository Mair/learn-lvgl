#include <lvgl.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
static lv_disp_buf_t disp_buf;
static lv_color_t buf[LV_HOR_RES_MAX * 10];

#if USE_LV_LOG != 0
/* Serial debugging */
void my_print(lv_log_level_t level, const char * file, uint32_t line, const char * dsc)
{

    Serial.printf("%s@%d->%s\r\n", file, line, dsc);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors(&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

/* Reading input device (simulated encoder here) */
bool read_encoder(lv_indev_drv_t * indev, lv_indev_data_t * data)
{
    static int32_t last_diff = 0;
    int32_t diff = 0; /* Dummy - no movement */
    int btn_state = LV_INDEV_STATE_REL; /* Dummy - no press */

    data->enc_diff = diff - last_diff;;
    data->state = btn_state;

    last_diff = diff;

    return false;
}

void setup()
{

    Serial.begin(115200); /* prepare for possible serial debug */

    lv_init();

#if USE_LV_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

    tft.begin(); /* TFT init */
    tft.setRotation(1); /* Landscape orientation */

    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * 10);

    /*Initialize the display*/
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 320;
    disp_drv.ver_res = 240;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the (dummy) input device driver*/
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = read_encoder;
    lv_indev_drv_register(&indev_drv);

    /* Create simple label */
    external_button_on_screen();
}


void loop()
{

    lv_task_handler(); /* let the GUI do its work */
    delay(5);
}

static lv_obj_t * _led;


void external_button_on_screen()
{
  lv_gpio_init();
  lv_indev_drv_t input_device_driver;
  lv_indev_drv_init(&input_device_driver);
  input_device_driver.type = LV_INDEV_TYPE_BUTTON;
  input_device_driver.read_cb = button_read;
  lv_indev_t *button_input_device = lv_indev_drv_register(&input_device_driver);

  lv_obj_t* btn = lv_btn_create(lv_scr_act(),NULL);
  lv_obj_set_style_local_value_str(btn, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,"Click me!");
  lv_obj_set_event_cb(btn,btn_event_cb);
  lv_obj_align(btn,NULL, LV_ALIGN_CENTER,0,0);

  static lv_point_t pionts[4];
  pionts[0].x = lv_obj_get_x(btn);
  pionts[0].y = lv_obj_get_y(btn);

  pionts[1].x = lv_obj_get_x(btn);
  pionts[1].y = lv_obj_get_y(btn) + lv_obj_get_height(btn);

  pionts[2].x = lv_obj_get_x(btn) + lv_obj_get_width(btn);
  pionts[2].y = lv_obj_get_y(btn);

  pionts[3].x = lv_obj_get_x(btn) + lv_obj_get_width(btn);
  pionts[3].y = lv_obj_get_y(btn)+ lv_obj_get_height(btn);



//  lv_obj_t *obj =  lv_obj_create(lv_scr_act(), NULL);
//  lv_obj_set_style_local_bg_color(obj,LV_OBJ_PART_MAIN, LV_STATE_DEFAULT,LV_COLOR_BLACK);
//  lv_obj_set_size(obj,10,10);
//  lv_obj_set_pos(obj,pionts[3].x, pionts[3].y );

  lv_indev_set_button_points(button_input_device,pionts);

  _led = lv_led_create(lv_scr_act(),NULL);
  lv_obj_align(_led,NULL, LV_ALIGN_CENTER,0,-80);
  lv_led_off(_led);
}

static void btn_event_cb(lv_obj_t* btn, lv_event_t event)
{
  if(event == LV_EVENT_PRESSING || event == LV_EVENT_LONG_PRESSED|| event == LV_EVENT_LONG_PRESSED_REPEAT)
    lv_led_on(_led);
  else
    lv_led_off(_led);
}

static void lv_gpio_init(void)
{
  pinMode(0,INPUT);
}

static bool button_read(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
  //read gpio
  if(digitalRead(0) == 0)
    data->state =LV_INDEV_STATE_PR;
   else
    data->state =LV_INDEV_STATE_REL;
  return false;
}
