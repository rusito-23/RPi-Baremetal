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
        {.note= FIRST_OCTAVE(DO), .duration= FIVE_SEC},
        {.note= FIRST_OCTAVE(RE), .duration= FIVE_SEC},
        {.note= FIRST_OCTAVE(MI), .duration= FIVE_SEC},
        {.note= FIRST_OCTAVE(FA), .duration= FIVE_SEC},
        {.note= FIRST_OCTAVE(SOL), .duration= FIVE_SEC},
        {.note= FIRST_OCTAVE(LA), .duration= FIVE_SEC},
        {.note= FIRST_OCTAVE(SI), .duration= FIVE_SEC},
    };

    Song song = {.notes= notes, .size= 7, .replay = 0};
    InitSong(song);
}

/*
QUIEN SE HA TOMADO TODO EL VINO?
*/

void createQuienSeHaTomado() {
    PlayNote notes[9] = {
        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= QUAVER},

        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= QUAVER},

        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= SEMIQUAVER},
    };

    Song song = {.notes= notes, .size= 9, .replay = 1};
    InitSong(song);
}
