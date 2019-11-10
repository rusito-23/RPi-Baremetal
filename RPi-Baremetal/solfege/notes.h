#include "solfege.h"

/**
 * Define all notes
 * */

static Note DO  = {.Frequency= BASE_FREQ / 261, .Lit= 261 * 2, .Raw= 261}; // DO
static Note RE  = {.Frequency= BASE_FREQ / 293, .Lit= 293 * 2, .Raw= 293}; // RE
static Note MI  = {.Frequency= BASE_FREQ / 329, .Lit= 329 * 2, .Raw= 329}; // MI
static Note FA  = {.Frequency= BASE_FREQ / 349, .Lit= 349 * 2, .Raw= 349}; // FA
static Note SOL = {.Frequency= BASE_FREQ / 392, .Lit= 392 * 2, .Raw= 392}; // SOL
static Note LA  = {.Frequency= BASE_FREQ / 440, .Lit= 440 * 2, .Raw= 440}; // LA
static Note SI  = {.Frequency= BASE_FREQ / 493, .Lit= 493 * 2, .Raw= 493}; // SI
