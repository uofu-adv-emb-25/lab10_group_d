/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma GCC optimize ("O0")
 #include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

int count = 0;
bool on = false;
const uint LED_PIN = 16;


//#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
//#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

void blink_task(__unused void *params) {
    hard_assert(cyw43_arch_init() == PICO_OK);

    gpio_init(LED_PIN);               // Initialize the GPIO
    gpio_set_dir(LED_PIN, GPIO_OUT);  // Set as output
    gpio_disable_pulls(LED_PIN);      // Disable pull-up and pull-down resistors

    while (1) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(500);
        gpio_put(LED_PIN, 0);
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

    //Number 1: sleep_ms to delay iterations
    hard_assert(cyw43_arch_init() == PICO_OK);

    // Select GPIO 16 (pin 21 on the Pico)

    gpio_init(LED_PIN);               // Initialize the GPIO
    gpio_set_dir(LED_PIN, GPIO_OUT);  // Set as output
    gpio_disable_pulls(LED_PIN);      // Disable pull-up and pull-down resistors

    while (1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }

    //Number 2: FreeRTOS with a thread
    //const char *rtos_name;
    //rtos_name = "FreeRTOS";
    //TaskHandle_t task;
    //xTaskCreate(blink_task, "BlinkThread",
    //            BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
    //vTaskStartScheduler();

    //Number 3: Run a busy loop
    // while(1) {
    //     uint32_t k;
    //     for (int i = 0; i < 30) {
    //         uint32_t j = 0;
    //         j = ((~j >> i) + 1) * 27644437;
    //         k = j;
    //     }
    // }
    return 0;
}
