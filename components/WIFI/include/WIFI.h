#ifndef __WIFI_H
#define __WIFI_H

#include "driver/gpio.h"
#include <stdio.h>
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif_types.h"
#include "esp_netif_ip_addr.h"

#define SSID "caixiaomiao"
#define PASSWORD "7213793a"

void wifi_init(void);



#endif


