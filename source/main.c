#include<msp430.h>

#include "bit.h"
#include "timer.h"
#include "piano_keys.h"


int main(void) {
	WDTCTL = WDTPW | WDTHOLD;  // Disable watchdog.

	// Setup output LED.
	SET_BIT(P2DIR, OUTPUT);
	UNSET_BIT(P2OUT, OUTPUT);

	run_timer(G);

	// Stop CPU and enable interrupts.
	__bis_SR_register(CPUOFF | GIE);
	
	return 0;
}
