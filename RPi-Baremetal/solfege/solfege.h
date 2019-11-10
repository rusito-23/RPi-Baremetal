#ifndef SOLFEGE_H
#define SOLFEGE_H

#define BASE_FREQ 500000

/**
 * Defines a note:
 *     - Frequency: Value to be send into IRQTimer
 *     - Lit: Interrups per second according to the Frequency
 *     - Raw: Raw frequency value (unused, yet usefull)
 * */
typedef struct Note {
    int Frequency;
    int Lit;
    int Raw;
} Note;

/**
 * Defines a note to be played:
 *     - note -> Note with te information to be played
 *     - msec -> milliseconds we wish the note to be played
 * */
typedef struct PlayNote {
    Note note;
    int msec;
} PlayNote;

#endif
