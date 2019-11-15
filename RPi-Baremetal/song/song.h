#ifndef SONG_H
#define SONG_H

#include "../solfege/solfege.h"

typedef struct Song {
    PlayNote *notes;
    int size;
    int replay;
    int number_song;
} Song;

/**
* ALL SONGS ARE DEFINED HERE
*/

Song createDoReMiFaSolLaSi();

Song createQuienSeHaTomado();

Song createTetris();

void changeSong(Song);

#endif
