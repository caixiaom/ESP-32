#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "LED.h"

void app_main(void)
{
    led_init();
    while (1)
    {
        led_tg(GPIO_NUM_2);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        // printf("led ON\r\n");

    }
    
}