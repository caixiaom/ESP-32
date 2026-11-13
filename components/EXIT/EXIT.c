#include <stdio.h>
#include "EXIT.h"
#include "LED.h"

void exit_led_handle(void *arg)
{
    led_tg(GPIO_NUM_2);
}


void exit_init(void)
{
    esp_err_t err = 0;
    gpio_config_t gpio_conf = {
                                .intr_type = GPIO_INTR_NEGEDGE,
                                .mode = GPIO_MODE_INPUT,
                                .pin_bit_mask = 1ull << 0,
                                .pull_down_en = GPIO_PULLDOWN_DISABLE,
                                .pull_up_en = GPIO_PULLUP_ENABLE,
    };

    err = gpio_config(&gpio_conf);

    if ( err != ESP_OK )
    {
        printf("IO Init faile!\r\n");
        return;
    }

    gpio_install_isr_service(ESP_INTR_FLAG_EDGE);

    gpio_isr_handler_add(GPIO_NUM_0,exit_led_handle,NULL);

    gpio_intr_enable(GPIO_NUM_0);
}


