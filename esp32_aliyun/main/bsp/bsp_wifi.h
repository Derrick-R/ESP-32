#ifndef __BSP_WIFI__
#define __BSP_WIFI__
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

//定义联网相关的宏
#define ESP_WIFI_SSID_STA      "YYH"            //账号
#define ESP_WIFI_PASS_STA      "12345678"        //密码
#define ESP_WIFI_SSID_AP       "YYH EAT SHIT"
#define ESP_WIFI_PASS_AP       "12345678"
#define PORT                    3333

void bsp_wifi_init_sta();  //用于连接wifi
#endif/*__BSP_WIFI__*/