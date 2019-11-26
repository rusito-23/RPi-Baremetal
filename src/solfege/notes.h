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

#define FIRST_OCTAVE(NOTE) (struct Note) {.Frequency= BASE / NOTE, .IPS= NOTE * 2}
#define SECOND_OCTAVE(NOTE) (struct Note) {.Frequency= BASE / (2 * NOTE), .IPS= (2 * NOTE) * 2}
#define THIRD_OCTAVE(NOTE) (struct Note) {.Frequency= BASE / (3 * NOTE), .IPS= (3 * NOTE) * 2}
#define NO_NOTE (struct Note) {.Frequency= BASE / 5, .IPS= 10}

/**
* Define all durations
*/

#define MINIM (struct Duration) {.s= 2, .ds= 0}             // blanca
#define CROTCHET (struct Duration) {.s= 1, .ds= 0}          // negra
#define QUAVER (struct Duration) {.s= 0, .ds= 5}           // corchea
#define SEMIQUAVER (struct Duration) {.s= 0, .ds= 2}       // semi corchea
#define FUSA (struct Duration) {.s= 0, .ds= 1}             // fusa

#define FIVE_SEC (struct Duration) {.s= 5, .ds= 0}             // blanca

#endif
