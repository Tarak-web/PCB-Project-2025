/*
 * File: /d:/000_Collection_Bin/Code_Prac1/251201-GitHub-Record/Firmware/_Sandbox/Jiayu_train/main.c
 * 简单的 ESP-IDF 点灯（Blink）示例
 *
 * 修改 LED_GPIO 以匹配你的开发板引脚（常见板子为 GPIO2）
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_GPIO GPIO_NUM_2     // 根据板子修改
#define BLINK_DELAY_MS 500

static const char *TAG = "blink";

void app_main(void)
{
    // 配置为输出
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    bool level = false;
    while (1) {
        level = !level;
        gpio_set_level(LED_GPIO, level);
        ESP_LOGI(TAG, "LED %s", level ? "ON" : "OFF");
        vTaskDelay(pdMS_TO_TICKS(BLINK_DELAY_MS));
    }
}