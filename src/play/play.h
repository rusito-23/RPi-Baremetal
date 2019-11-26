#ifndef PLAY_H
#define PLAY_H

#include "../song/song.h"

/**
* Prepares the song to be played inside the interrupt function
*/
void InitSong(Song song);

/**
* Function to be called inside the interrupt function
* once the song has been initialized
*/
void PlaySong();

#endif
