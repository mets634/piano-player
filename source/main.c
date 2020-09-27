#include<msp430.h>

#include "bit.h"
#include "player.h"


int main(void) {
	WDTCTL = WDTPW | WDTHOLD;  // Disable watchdog.

	// Setup output LED.
	SET_BIT(P2DIR, OUTPUT);
	UNSET_BIT(P2OUT, OUTPUT);

	__bis_SR_register(GIE);  // Enable interrupts.

	play_song();

	// Stop CPU.
	__bis_SR_register(CPUOFF);
	
	return 0;
}
