#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "EXIT.h"
#include "LED.h"

void app_main(void)
{
    led_init();
    exit_init();
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));

    }
    


}