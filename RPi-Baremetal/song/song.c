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
        {.note= DO,     .msec= 1000},
        {.note= RE,     .msec= 1000},
        {.note= MI,     .msec= 1000},
        {.note= FA,     .msec= 1000},
        {.note= SOL,    .msec= 1000},
        {.note= LA,     .msec= 1000},
        {.note= SI,     .msec= 1000},
    };

    Song song = {.notes= notes, .size= 7, .replay = 0};
    InitSong(song);
}

/*
QUIEN SE HA TOMADO TODO EL VINO?
*/
