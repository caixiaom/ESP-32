#include "WIFI.h"


void wifista_event_handler(void* event_handler_arg,esp_event_base_t event_base,int32_t event_id,void* event_data)
{
    if (event_id == WIFI_EVENT_STA_START)
    {
        esp_wifi_connect();
        printf("wifi starting!\r\n");
    }

    if (event_id == WIFI_EVENT_STA_CONNECTED)
    {
        
        printf("wifi connected!\r\n");
    }
    
}

void ip_event_handler(void* event_handler_arg,esp_event_base_t event_base,int32_t event_id,void* event_data)
{
    if (event_id == IP_EVENT_STA_GOT_IP)
    {
       esp_netif_ip_info_t *event = (esp_netif_ip_info_t *)event_data;
       printf("%d.%d.%d.%d",esp_ip4_addr1_16(&event->ip),esp_ip4_addr2_16(&event->ip),esp_ip4_addr3_16(&event->ip),esp_ip4_addr4_16(&event->ip));
       
    }
}


void wifi_init(void)
{
    esp_netif_init();
    esp_event_loop_create_default();
    esp_event_handler_register(WIFI_EVENT,ESP_EVENT_ANY_ID,&wifista_event_handler,NULL);
    esp_event_handler_register(IP_EVENT,IP_EVENT_STA_GOT_IP,&ip_event_handler,NULL);

    esp_netif_create_default_wifi_sta();

    wifi_init_config_t wifi_init_cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&wifi_init_cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);

    wifi_config_t wifi_init_sta = {
        .sta = {
                .ssid = SSID,
                .password = PASSWORD,
               }
    };

    esp_wifi_set_config(WIFI_IF_STA,&wifi_init_sta);

    esp_wifi_start();

}
