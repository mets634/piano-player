#include<msp430.h>
#include <stdint.h>

#include "bit.h"


#define MHZ_TO_HZ (1000000)
#define TIMER_DIVIDER (8)
#define TIMER_FREQUENCY_IN_HZ (MHZ_TO_HZ / TIMER_DIVIDER)


void run_timer(uint16_t frequency)
{
    // Before doing anything related to
    // the timer, we first stop the timer.
    TACCR0 = 0;  

    // Select timer configuration.
    TACCTL0 = CCIE;  // CCR0 interrupt enabled
    TACTL = TASSEL_2 + MC_1 + ID_3;  // SMCLK/8, upmode
    CCR0 = TIMER_FREQUENCY_IN_HZ / frequency;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void increment_timer(void)
{
    TOGGLE_BIT(P2OUT, OUTPUT);
}
