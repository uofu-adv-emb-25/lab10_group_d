# Measurements
Scenario 1: sleep_ms to delay iterations

31-36 mA @ 3 V P = 93-108 mW

Scenario 2: FREERTOS with a thread

38-43 mA @ 3 V P = 114-129 mW

Scenario 3: Run busy loop

36 mA @ 3 V P = 108 mW

Scenario 4: Set up an interrupt to toggle a GPIO in response to an external signal

31 mA when the signal generator is off P = 93 mW

35 mA @ 1 KHz P = 105 mW

41 mA @ 500 KHz P = 123 mW

41 mA @ 1 MHz P = 123 mW

