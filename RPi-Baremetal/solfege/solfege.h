#ifndef SOLFEGE_H
#define SOLFEGE_H

#define BASE_FREQ 500000

/**
 * Defines a note:
 *     - Frequency: Value to be send into IRQTimer
 *     - Lit: Interrups per second according to the Frequency
 *     - Raw: Raw frequency value (unused, yet usefull)
 * */
typedef struct note_t {
    int Frequency;
    int Lit;
    int Raw;
} note_t;

/**
 * Defines a note to be played:
 *     - note -> note_t with te information to be played
 *     - msec -> milliseconds we wish the note to be played
 * */
typedef struct note {
    note_t note;
    int msec;
} note;

#endif
