#include <stdio.h>
#include "driver/gpio.h"
#include "LED.h"


void led_init(void)
{
    esp_err_t err = 0;
    gpio_config_t gpio_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT_OUTPUT,
        .pin_bit_mask = 1ull << 2,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };

    err = gpio_config(&gpio_conf);

    if ( err != ESP_OK )
    {
        printf("IO Init faile!\r\n");
        return;
    }
    
}

void led_tg(gpio_num_t gpio_num)
{
    if (gpio_get_level(gpio_num) == 0)
    {
        gpio_set_level(gpio_num , 1);
        printf("led ON\r\n");
    }
    else
    {
        gpio_set_level(gpio_num , 0);
        printf("led OFF\r\n");
    }

};
