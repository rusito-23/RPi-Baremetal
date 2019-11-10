#ifndef SOLFEGE_H
#define SOLFEGE_H

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
 *     - sec -> seconds we wish the note to be played
 *     - divide -> indicator to check if we have divide the value of the secs
 * */
typedef struct PlayNote {
    Note note;
    int sec;
    int divide;
} PlayNote;

#endif
