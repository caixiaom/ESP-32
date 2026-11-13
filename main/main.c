#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "EXIT.h"
#include "LED.h"
#include "UART.h"

void app_main(void)
{
    uint8_t uart_r_buf[32] = {0};
    uint8_t length = 0;
    exit_init();
    uart_init();
    while (1)
    {   

       length =  uart_read_bytes(UART_NUM_2,uart_r_buf,32,portMAX_DELAY);
       if (length > 0)
       {
        uart_write_bytes(UART_NUM_2,uart_r_buf,length);
        uart_flush(UART_NUM_2);
       }
       vTaskDelay(5 / portTICK_PERIOD_MS);
       

    }
    


}