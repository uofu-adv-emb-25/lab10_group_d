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

int main( void )
{
    stdio_init_all();

    //Activity 3: Run a busy loop
    while(1) {
        uint32_t k;
        for (int i = 0; i < 30 ; i++) {
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
        }
    }
    return 0;
}