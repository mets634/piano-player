#pragma once

#include <stdint.h>


/*
 * Warning: frequency must be larger
 * than 1, or an interger-overflow will
 * occur (due to the timer that is used).
*/
void run_timer0(uint16_t frequency);
void run_timer1(uint16_t frequency);

void stop_timer0(void);
void stop_timer1(void);
