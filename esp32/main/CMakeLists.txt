set(SOURCES 
    main.c
    _1_external_button_on_screen.c
    _3_keyboard_on_chip.c
    _4_rotary_encoder.c
    _5_rotary_encoder_button.c
    _6_task_with_rtos.c
    _7_task_with_rtos_semaphore.c
    )
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS .
                    REQUIRES lvgl_esp32_drivers lvgl_touch lvgl_tft lvgl lv_examples)

target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)
