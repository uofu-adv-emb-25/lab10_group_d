/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

int count = 0;
bool on = false;

//#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
//#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

void blink_task(__unused void *params) {
    hard_assert(cyw43_arch_init() == PICO_OK);
    // while (true) {

        
    //     cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
    //     if (count++ % 11) on = !on;
    //     vTaskDelay(500);
    // }

    // Select GPIO 16 (pin 21 on the Pico)
    const uint PIN = 16;

    gpio_init(PIN);               // Initialize the GPIO
    gpio_set_dir(PIN, GPIO_OUT);  // Set as output
    gpio_disable_pulls(PIN);      // Disable pull-up and pull-down resistors

    while (1) {
        gpio_put(PIN, 1);
        vTaskDelay(500);
        gpio_put(PIN, 0);
        vTaskDelay(500);
    }
}

// void main_task(__unused void *params) {
//     xTaskCreate(blink_task, "BlinkThread",
//                 BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
//     char c;
//     while(c = getchar()) {
//         if (c <= 'z' && c >= 'a') putchar(c - 32);
//         else if (c >= 'A' && c <= 'Z') putchar(c + 32);
//         else putchar(c);
//     }
// }

int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;
    xTaskCreate(blink_task, "BlinkThread",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
    vTaskStartScheduler();
    return 0;
}
