#include "bsp_wifi.h"
static EventGroupHandle_t s_wifi_event_group;
static EventGroupHandle_t wifi_tcp_event_group;
void wifi_sta_event_handler(void *handler_arg, esp_event_base_t base, int32_t id, void *event_data);
void user_wifi_sta_task(void *pt);
static const char *TAG = "wifi softAP";
esp_netif_t *pEsp_wifi_netif;
void bsp_wifi_init_sta()
{
    s_wifi_event_group = xEventGroupCreate();
    nvs_flash_init();
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    pEsp_wifi_netif = esp_netif_create_default_wifi_sta();
    esp_netif_set_hostname(pEsp_wifi_netif, "Augtons");//设置设备名称
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    xTaskCreate(user_wifi_sta_task, "user_wifi_sta_task", 1024*12, NULL, 1, NULL);
    wifi_config_t wifi_config;
    memset(&wifi_config, 0, sizeof(wifi_config));
    sprintf((char*)wifi_config.sta.ssid, ESP_WIFI_SSID_STA);
    sprintf((char*)wifi_config.sta.password, ESP_WIFI_PASS_STA);
    wifi_config.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;
    wifi_config.sta.pmf_cfg.capable = true;
    wifi_config.sta.pmf_cfg.required = false;
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void user_wifi_sta_task(void *pt)
{
    esp_event_handler_register(ESP_EVENT_ANY_BASE, ESP_EVENT_ANY_ID, wifi_sta_event_handler, NULL);
    while (1)
    {
         xEventGroupWaitBits(s_wifi_event_group, BIT0, pdFALSE, pdFALSE, portMAX_DELAY);
         printf("connect sucessful");
         vTaskDelete(NULL);
    }
    
}

void wifi_sta_event_handler(void *handler_arg, esp_event_base_t base, int32_t id, void *event_data)
{
    switch (id)
    {
    case WIFI_EVENT_STA_START:
        ESP_LOGI("EVEVT", "WIFI_EVENT_STA_START");
        esp_wifi_connect();
        break;
    case WIFI_EVENT_STA_DISCONNECTED:
        ESP_LOGI("EVEVT", "WIFI_EVENT_STA_DISCONNECTED");
        esp_wifi_connect();
        break;
    case WIFI_EVENT_SCAN_DONE:
        ESP_LOGI("EVEVT", "IP_EVENT_STA_GOT_IP");
        xEventGroupSetBits(s_wifi_event_group, BIT0);
        break;
    default:
        break;
    }
}





