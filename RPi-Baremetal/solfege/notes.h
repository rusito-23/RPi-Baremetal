#ifndef NOTES_H
#define NOTES_H

#include "solfege.h"

#define BASE 500000

/**
 * Define all notes
 * */

#define DO 261.63
#define RE 293.66
#define MI 329.63
#define FA 349.23
#define SOL 392
#define LA 440
#define SI 493.88


// OCTAVES

#define FIRST_OCTAVE    1
#define SECOND_OCTAVE   2
#define THIRD_OCTAVE    3

// Note Creation

#define NOTE(NOTE) (struct Note) {.Frequency= BASE / NOTE, .IPS= NOTE * 2}
#define NOTE_O(NOTE, OCTAVE) (struct Note) {.Frequency= BASE / (OCTAVE * NOTE), .IPS= (OCTAVE * NOTE) * 2}
#define NO_NOTE (struct Note) {.Frequency= BASE_OCTAVE * 2, .IPS= 1};

#endif
