#include<msp430.h>

#include "bit.h"
#include "timer.h"


int main(void) {
	WDTCTL = WDTPW | WDTHOLD;  // Disable watchdog.

	// Setup output LED.
	SET_BIT(P1DIR, LED);
	UNSET_BIT(P1OUT, LED);

	run_timer(2);

	// Stop CPU and enable interrupts.
	__bis_SR_register(CPUOFF | GIE);
	
	return 0;
}
