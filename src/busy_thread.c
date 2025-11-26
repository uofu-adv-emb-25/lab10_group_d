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

int main( void )
{
    stdio_init_all();

    //Activity 3: Run a busy loop
    while(1) {
        uint32_t k;
        for (int i = 0; i < 30) {
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
        }
    }
    return 0;
}