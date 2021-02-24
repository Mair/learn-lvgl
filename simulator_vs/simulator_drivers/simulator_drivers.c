#include <stdbool.h>
#include <stdint.h>
#include "../../lvgl/lvgl.h"

#include <Windows.h>

static bool volatile g_keyboard_pressed = false;
static WPARAM volatile g_keyboard_value = 0;
static bool volatile g_mousewheel_pressed = false;
static int16_t volatile g_mousewheel_value = 0;

bool keyboard_read(
    lv_indev_drv_t* indev_drv,
    lv_indev_data_t* data)
{

    data->state = (lv_indev_state_t)(
        g_keyboard_pressed ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL);

    WPARAM KeyboardValue = g_keyboard_value;

    switch (KeyboardValue)
    {
    case VK_UP:
        data->key = LV_KEY_UP;
        break;
    case VK_DOWN:
        data->key = LV_KEY_DOWN;
        break;
    case VK_LEFT:
        data->key = LV_KEY_LEFT;
        break;
    case VK_RIGHT:
        data->key = LV_KEY_RIGHT;
        break;
    case VK_ESCAPE:
        data->key = LV_KEY_ESC;
        break;
    case VK_DELETE:
        data->key = LV_KEY_DEL;
        break;
    case VK_BACK:
        data->key = LV_KEY_BACKSPACE;
        break;
    case VK_RETURN:
        data->key = LV_KEY_ENTER;
        break;
    case VK_NEXT:
        data->key = LV_KEY_NEXT;
        break;
    case VK_PRIOR:
        data->key = LV_KEY_PREV;
        break;
    case VK_HOME:
        data->key = LV_KEY_HOME;
        break;
    case VK_END:
        data->key = LV_KEY_END;
        break;
    default:
        if (KeyboardValue >= 'A' && KeyboardValue <= 'Z')
        {
            KeyboardValue += 0x20;
        }

        data->key = (uint32_t)KeyboardValue;

        break;
    }

    return false;
}

bool mousewheel_read(
    lv_indev_drv_t* indev_drv,
    lv_indev_data_t* data)
{
    data->state = (lv_indev_state_t)(
        g_mousewheel_pressed ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL);
    data->enc_diff = g_mousewheel_value;
    g_mousewheel_value = 0;

    return false;
}
