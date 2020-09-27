#include<msp430.h>
#include <stdint.h>

#include "timer.h"
#include "bit.h"
#include "player.h"


#define MHZ_TO_HZ (1000000)
#define TIMER_DIVIDER (8)
#define TIMER_FREQUENCY_IN_HZ (MHZ_TO_HZ / TIMER_DIVIDER)


void run_timer0(uint16_t frequency) {
    stop_timer0();

    // Select timer configuration.
    TA0CCTL0 = CCIE;  // CCR0 interrupt enabled
    TA0CTL = TASSEL_2 + MC_1 + ID_3;  // SMCLK/8, upmode
    TA0CCR0 = TIMER_FREQUENCY_IN_HZ / frequency;
}

void stop_timer0(void) {
    TA0CCR0 = 0;
}

void run_timer1(uint16_t frequency) {
    stop_timer1();

    // Select timer configuration.
    TA1CCTL0 = CCIE;  // CCR0 interrupt enabled
    TA1CTL = TASSEL_2 + MC_1 + ID_3;  // SMCLK/8, upmode
    TA1CCR0 = TIMER_FREQUENCY_IN_HZ / frequency;
}

void stop_timer1(void) {
    TA1CCR0 = 0;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void toggle_output_voltage(void) {
    TOGGLE_BIT(P2OUT, OUTPUT);
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void call_note_transition(void) {
    transition_to_next_note();
}