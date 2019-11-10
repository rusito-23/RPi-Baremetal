//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "../solfege/solfege.h"
#include "../solfege/notes.h"
#include "../play/play.h"
#include "song.h"

//-------------------------------------------------------------------------


void ALLNOTES() {
    PlayNote notes[14] = {
        {.note= DO,     .sec= 1, .divide= 0},
        {.note= RE,     .sec= 1, .divide= 0},
        {.note= MI,     .sec= 1, .divide= 0},
        {.note= FA,     .sec= 1, .divide= 0},
        {.note= SOL,    .sec= 1, .divide= 0},
        {.note= LA,     .sec= 1, .divide= 0},
        {.note= SI,     .sec= 1, .divide= 0},

        {.note= DO_S,     .sec= 1, .divide= 0},
        {.note= RE_S,     .sec= 1, .divide= 0},
        {.note= MI_S,     .sec= 1, .divide= 0},
        {.note= FA_S,     .sec= 1, .divide= 0},
        {.note= SOL_S,    .sec= 1, .divide= 0},
        {.note= LA_S,     .sec= 1, .divide= 0},
        {.note= SI_S,     .sec= 1, .divide= 0},
    };

    Song song = {.notes= notes, .size= 14, .replay = 0};
    InitSong(song);
}

/*
DO RE MI FA SOL LA SI
*/

void createDoReMiFaSolLaSi() {
    PlayNote notes[7] = {
        {.note= DO,     .sec= 5, .divide= 0},
        {.note= RE,     .sec= 5, .divide= 0},
        {.note= MI,     .sec= 5, .divide= 0},
        {.note= FA,     .sec= 5, .divide= 0},
        {.note= SOL,    .sec= 5, .divide= 0},
        {.note= LA,     .sec= 5, .divide= 0},
        {.note= SI,     .sec= 5, .divide= 0},
    };

    Song song = {.notes= notes, .size= 7, .replay = 0};
    InitSong(song);
}

/*
QUIEN SE HA TOMADO TODO EL VINO?
*/

void createQuienSeHaTomado() {
    PlayNote notes[14] = {
        {.note= LA,     .sec= 1, .divide= 700},
        {.note= DO_S,     .sec= 1, .divide= 300},
        {.note= MI_S,     .sec= 1, .divide= 300},

        {.note= LA,     .sec= 1, .divide= 700},
        {.note= DO_S,     .sec= 1, .divide= 300},
        {.note= MI_S,     .sec= 1, .divide= 300},

        {.note= LA,     .sec= 1, .divide= 700},
        {.note= DO_S,     .sec= 1, .divide= 300},
        {.note= MI_S,     .sec= 1, .divide= 300},

        {.note= RE_S,     .sec= 1, .divide= 300},
        {.note= DO_S,     .sec= 1, .divide= 300},
        {.note= SI,     .sec= 1, .divide= 300},

        {.note= SOL,    .sec= 1, .divide= 400},
        {.note= SOL,    .sec= 1, .divide= 400},


    };

    Song song = {.notes= notes, .size= 14, .replay = 1};
    InitSong(song);
}
