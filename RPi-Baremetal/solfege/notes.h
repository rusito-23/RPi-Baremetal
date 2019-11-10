#include "solfege.h"

#define BASE_OCTAVE 500000

/**
 * Define all notes
 * */

static Note DO  = {.Frequency= BASE_OCTAVE / 261, .Lit= 261 * 2, .Raw= 261 / 2}; // DO
static Note RE  = {.Frequency= BASE_OCTAVE / 293, .Lit= 293 * 2, .Raw= 293 / 2}; // RE
static Note MI  = {.Frequency= BASE_OCTAVE / 329, .Lit= 329 * 2, .Raw= 329 / 2}; // MI
static Note FA  = {.Frequency= BASE_OCTAVE / 349, .Lit= 349 * 2, .Raw= 349 / 2}; // FA
static Note SOL = {.Frequency= BASE_OCTAVE / 392, .Lit= 392 * 2, .Raw= 392 / 2}; // SOL
static Note LA  = {.Frequency= BASE_OCTAVE / 440, .Lit= 440 * 2, .Raw= 440 / 2}; // LA
static Note SI  = {.Frequency= BASE_OCTAVE / 493, .Lit= 493 * 2, .Raw= 493 / 2}; // SI

static Note DO_S  = {.Frequency= BASE_OCTAVE / (2 *261), .Lit= 261 * 2, .Raw= 261 / 2}; // DO
static Note RE_S  = {.Frequency= BASE_OCTAVE / (2 *293), .Lit= 293 * 2, .Raw= 293 / 2}; // RE
static Note MI_S  = {.Frequency= BASE_OCTAVE / (2 *329), .Lit= 329 * 2, .Raw= 329 / 2}; // MI
static Note FA_S  = {.Frequency= BASE_OCTAVE / (2 *349), .Lit= 349 * 2, .Raw= 349 / 2}; // FA
static Note SOL_S = {.Frequency= BASE_OCTAVE / (2 *392), .Lit= 392 * 2, .Raw= 392 / 2}; // SOL
static Note LA_S  = {.Frequency= BASE_OCTAVE / (2 *440), .Lit= 440 * 2, .Raw= 440 / 2}; // LA
static Note SI_S  = {.Frequency= BASE_OCTAVE / (2 *493), .Lit= 493 * 2, .Raw= 493 / 2}; // SI
