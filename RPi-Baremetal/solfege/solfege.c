
#include "solfege.h"

static note_t notes[7] = {0};

note_t *getNotes(void) {
    notes[0] = (struct note_t){BASE_FREQ / 261, 261 * 10, 261}; // DO
    notes[1] = (struct note_t){BASE_FREQ / 293, 293 * 10, 293}; // RE
    notes[2] = (struct note_t){BASE_FREQ / 329, 329 * 10, 329}; // MI
    notes[3] = (struct note_t){BASE_FREQ / 349, 349 * 10, 349}; // FA
    notes[4] = (struct note_t){BASE_FREQ / 392, 392 * 10, 392}; // SOL
    notes[5] = (struct note_t){BASE_FREQ / 440, 440 * 10, 440}; // LA
    notes[6] = (struct note_t){BASE_FREQ / 493, 493 * 10, 493}; // SI
    return notes;
}
