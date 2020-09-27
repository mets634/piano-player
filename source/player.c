#include "piano_keys.h"
#include "timer.h"

uint16_t song[] = {E, D, C, D, E, E, E, D, D, D, E, E, E,
                   E, D, C, D, E, E, E, C, D, D, E, D, C};

void play_tone(uint16_t key) {
	uint32_t i = 0;

	run_timer(key);
	for (i = 0; i < 0x8fff; ++i) {}

    stop_timer();
	for (i = 0; i < 0x0fff; ++i) {}
}

void play_song(void) {
    uint8_t index = 0;
    while (1) {
        for (index = 0; index < sizeof(song) / sizeof(song[0]); ++index)
        {
            play_tone(song[index]);
        }
    }
}