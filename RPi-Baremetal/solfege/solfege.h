#ifndef SOLFEGE_H
#define SOLFEGE_H

/**
 * Defines a note:
 *     - Frequency: Value to be send into IRQTimer
 *     - Lit: Interrups per second according to the Frequency
 * */
typedef struct Note {
    int Frequency;
    int IPS;
} Note;

/**
* Defines a Note Duration (in seconds and deciseconds)
*/
typedef struct Duration {
    int s;
    int ds;
} Duration;

/**
 * Defines a note to be played:
 *     - note -> Note with te information to be played
 *     - sec -> seconds we wish the note to be played
 *     - decisec -> seconds dec we wish the note to be played (must be < 100)
 * */
typedef struct PlayNote {
    Note note;
    Duration duration;
} PlayNote;

#endif
