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

    keyboard_on_chip();
}


void loop()
{

    lv_task_handler(); /* let the GUI do its work */
    delay(5);
}



//#define IS_ESP32 1
#define IS_ARDUINO 1

bool keyboard_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

void keyboard_on_chip()
{
  lv_group_t* group = lv_group_create();

  lv_indev_drv_t kb_drv;
  lv_indev_drv_init(&kb_drv);
  kb_drv.type = LV_INDEV_TYPE_KEYPAD;
#if defined(IS_ESP32) || defined(IS_ARDUINO)
  kb_drv.read_cb = keyboard_read_chip;
#else
  kb_drv.read_cb = keyboard_read;
#endif
  lv_indev_t* kb_indev = lv_indev_drv_register(&kb_drv);
  lv_indev_set_group(kb_indev,group);

  lv_obj_t * container = lv_cont_create(lv_scr_act(),NULL);
  lv_obj_set_auto_realign(container,true);
  lv_cont_set_fit(container,LV_FIT_TIGHT);
  lv_cont_set_layout(container,LV_LAYOUT_COLUMN_LEFT);
  lv_obj_t *checkbox = lv_checkbox_create(container,NULL);
  lv_checkbox_set_text(checkbox, "yes or no");
  lv_group_add_obj(group,checkbox);

  lv_obj_t *a_switch = lv_switch_create(container,NULL);
  lv_group_add_obj(group,a_switch);

  lv_obj_t *drop_down = lv_dropdown_create(container,NULL);
  lv_dropdown_set_options(drop_down,"America\nCanada\nAutralia\nIndia");
  lv_group_add_obj(group,drop_down);


  lv_obj_t * btn = lv_btn_create(container,NULL);
  lv_obj_t * btn_label =lv_label_create(btn,NULL);
  lv_label_set_text(btn_label, "Click me!");
  lv_group_add_obj(group,btn);
}

bool keyboard_read_chip(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
  static int last_key;
  int incoming_byte;
#ifdef IS_ESP32
  incoming_byte = getchar();
#elif IS_ARDUINO
  incoming_byte = Serial.read();
#endif

  switch(incoming_byte)
  {
  case '+':
    last_key = LV_KEY_RIGHT;
    break;
  case '-':
    last_key = LV_KEY_LEFT;
    break;
/******** for arduino******/
  case '*':
    last_key = LV_KEY_NEXT;
    break;
  case '.':
    last_key = LV_KEY_ENTER;
    break;
  case -1:
    break;
  default:
    last_key = incoming_byte;
    break;
  }

    data->state = incoming_byte == -1? LV_INDEV_STATE_REL: LV_INDEV_STATE_PR;
    data->key = last_key;
    return false;
}
