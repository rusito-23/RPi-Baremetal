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
    PlayNote notes[24] = {

        /* primera parte */

        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(MI), .duration= QUAVER},

        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(MI), .duration= QUAVER},

        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(MI), .duration= SEMIQUAVER},

        {.note= SECOND_OCTAVE(RE), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= SEMIQUAVER},
        {.note= FIRST_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= FIRST_OCTAVE(SOL), .duration= QUAVER},

        {.note= NO_NOTE, .duration= {.s = 0, .ds = 1}},

        /* segunda parte */

        {.note= FIRST_OCTAVE(SOL), .duration= SEMIQUAVER},
        {.note= FIRST_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(RE), .duration= QUAVER},

        {.note= FIRST_OCTAVE(SOL), .duration= SEMIQUAVER},
        {.note= FIRST_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(RE), .duration= SEMIQUAVER},

        {.note= SECOND_OCTAVE(DO), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(RE), .duration= QUAVER},
        {.note= SECOND_OCTAVE(MI), .duration= SEMIQUAVER},


        // silencio final
        {.note= NO_NOTE, .duration= {.s = 2, .ds = 0}},
    };

    Song song = {.notes= notes, .size= 24, .replay = 1};
    InitSong(song);
}
