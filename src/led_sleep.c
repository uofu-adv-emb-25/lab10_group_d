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

int main( void )
{
    stdio_init_all();

    //Activity 1: sleep_ms to delay iterations
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
    return 0;
}
