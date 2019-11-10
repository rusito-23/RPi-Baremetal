#ifndef SONG_H
#define SONG_H

#include "../solfege/solfege.h"

typedef struct Song {
    PlayNote *notes;
    int size;
} Song;

#endif
