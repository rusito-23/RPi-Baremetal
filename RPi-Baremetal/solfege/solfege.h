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

/**
 * Define all note_t
 * */

static note_t DO  = {.Frequency= BASE_FREQ / 261, .Lit= 261 * 2, .Raw= 261}; // DO
static note_t RE  = {.Frequency= BASE_FREQ / 293, .Lit= 293 * 2, .Raw= 293}; // RE
static note_t MI  = {.Frequency= BASE_FREQ / 329, .Lit= 329 * 2, .Raw= 329}; // MI
static note_t FA  = {.Frequency= BASE_FREQ / 349, .Lit= 349 * 2, .Raw= 349}; // FA
static note_t SOL = {.Frequency= BASE_FREQ / 392, .Lit= 392 * 2, .Raw= 392}; // SOL
static note_t LA  = {.Frequency= BASE_FREQ / 440, .Lit= 440 * 2, .Raw= 440}; // LA
static note_t SI  = {.Frequency= BASE_FREQ / 493, .Lit= 493 * 2, .Raw= 493}; // SI

#endif
