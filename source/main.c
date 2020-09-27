#include<msp430.h>

#include "bit.h"
#include "timer.h"
#include "piano_keys.h"


void play(uint16_t key) {
	uint32_t i = 0;

	run_timer(key);
	for (i = 0; i < 0xffff; ++i) {}
}

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;  // Disable watchdog.

	// Setup output LED.
	SET_BIT(P2DIR, OUTPUT);
	UNSET_BIT(P2OUT, OUTPUT);

	__bis_SR_register(GIE);

	while (1) {
		play(C);
		play(D);
		play(E);
		play(F);
		play(G);
		play(A);
		play(B);
	}

	// Stop CPU and enable interrupts.
	__bis_SR_register(CPUOFF | GIE);
	
	return 0;
}
