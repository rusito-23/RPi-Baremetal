//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "../solfege/solfege.h"
#include "../solfege/notes.h"
#include "../play/play.h"
#include "song.h"

//-------------------------------------------------------------------------

/*
DO RE MI FA SOL LA SI
*/

void createDoReMiFaSolLaSi() {
    PlayNote notes[7] = {
        {.note= NOTE(DO), .s= 5, .ds= 0},
        {.note= NOTE(RE), .s= 5, .ds= 0},
        {.note= NOTE(MI), .s= 5, .ds= 0},
        {.note= NOTE(FA), .s= 5, .ds= 0},
        {.note= NOTE(SOL), .s= 5, .ds= 0},
        {.note= NOTE(LA), .s= 5, .ds= 0},
        {.note= NOTE(SI), .s= 5, .ds= 0},
    };

    Song song = {.notes= notes, .size= 7, .replay = 0};
    InitSong(song);
}

/*
QUIEN SE HA TOMADO TODO EL VINO?
*/

void createQuienSeHaTomado() {
    PlayNote notes[24] = {
        {.note= NOTE(LA), .s= 0, .ds= 10},
        {.note= NOTE_O(DO, SECOND_OCTAVE), .s= 0, .ds= 10},
        {.note= NOTE_O(MI, SECOND_OCTAVE), .s= 0, .ds= 30},

        {.note= NOTE(LA), .s= 0, .ds= 10},
        {.note= NOTE_O(DO, SECOND_OCTAVE), .s= 0, .ds= 10},
        {.note= NOTE_O(MI, SECOND_OCTAVE), .s= 0, .ds= 30},

        {.note= NOTE(LA), .s= 0, .ds= 10},
        {.note= NOTE_O(DO, SECOND_OCTAVE), .s= 0, .ds= 10},
        {.note= NOTE_O(MI, SECOND_OCTAVE), .s= 0, .ds= 20},
        {.note= NOTE_O(RE, SECOND_OCTAVE), .s= 0, .ds= 10},
        {.note= NOTE_O(DO, SECOND_OCTAVE), .s= 0, .ds= 10},
        {.note= NOTE(SI), .s= 0, .ds= 80},

        {.note= NOTE(SOL), .s= 0, .ds= 10},
        {.note= NOTE(SI), .s= 0, .ds= 10},
        {.note= NOTE_O(RE, SECOND_OCTAVE), .s= 0, .ds= 30},

        {.note= NOTE(SOL), .s= 0, .ds= 10},
        {.note= NOTE(SI), .s= 0, .ds= 10},
        {.note= NOTE_O(RE, SECOND_OCTAVE), .s= 0, .ds= 30},

        {.note= NOTE(SOL), .s= 0, .ds= 10},
        {.note= NOTE(SI), .s= 0, .ds= 10},
        {.note= NOTE_O(RE, SECOND_OCTAVE), .s= 0, .ds= 30},

        {.note= NOTE_O(DO, SECOND_OCTAVE), .s= 0, .ds= 30},
        {.note= NOTE_O(RE, SECOND_OCTAVE), .s= 0, .ds= 30},
        {.note= NOTE_O(MI, SECOND_OCTAVE), .s= 0, .ds= 30},
    };

    Song song = {.notes= notes, .size= 24, .replay = 1};
    InitSong(song);
}
