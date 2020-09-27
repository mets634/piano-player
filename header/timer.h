#pragma once

#include <stdint.h>


/*
 * ! Warning: frequency must be larger
 * than 1, or an interger-overflow will
 * occur (due to the timer that is used).
*/
void run_timer(uint16_t frequency);
