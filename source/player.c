#include "player.h"
#include "piano_keys.h"
#include "timer.h"

uint16_t song[] = {E, D, C, D, E, E, E, E, D, D, D, D, E, E, E, E,
                   E, D, C, D, E, E, E, C, D, D, E, D, C, C, C};


uint8_t note_counter = 0;
const uint8_t number_of_notes = sizeof(song) / sizeof(song[0]);

void transition_to_next_note(void) {
    if (song[(note_counter - 1) % number_of_notes] !=  song[note_counter]) {
        stop_timer0();
        run_timer0(song[note_counter]);
    }

    note_counter = (note_counter + 1) % number_of_notes;
}

void play_song(void) {
    note_counter = 0;
    run_timer1(2);
}