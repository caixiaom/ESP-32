#include "UART.h"

void uart_init(void)
{

    uart_config_t uart_cfg = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .parity = UART_PARITY_DISABLE,
        .rx_flow_ctrl_thresh = 0,
        .source_clk = UART_SCLK_APB,
        .stop_bits = UART_STOP_BITS_1,
    };

    uart_param_config(UART_NUM_2,&uart_cfg);
    
    uart_set_pin(UART_NUM_2,GPIO_NUM_17,GPIO_NUM_16,-1,-1);

    uart_driver_install(UART_NUM_2, 1024, 1024, 0, NULL, 0);

}
