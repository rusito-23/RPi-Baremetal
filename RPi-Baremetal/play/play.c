//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "../hal/rpi-gpio.h"
#include "../hal/rpi-armtimer.h"
#include "../solfege/solfege.h"
#include "../song/song.h"

//-------------------------------------------------------------------------

// Static variables

static Song song;
static int index;
static int olit;

/**
* Calculate interruptions to be waited per note
*/
static int calculateOlit(PlayNote play) {
    // interruptions per second * seconds to play
    int seconds = play.note.IPS * play.s;
    // ips - (ips * (100 - deciseconds to play))
    int deciseconds = play.note.IPS - (play.note.IPS * (100 - play.ds));
    return seconds + deciseconds;
}

void InitSong(Song sSong) {
    // Initialize static vars
    song = sSong;
    index = 0;

    // Prepare the timer to start first note
    PlayNote firstPlay = song.notes[index];
    olit = calculateOlit(firstPlay);
    RPI_GetArmTimer()->Load = firstPlay.note.Frequency;

    // Go to next note
    index++;
}


void PlaySong() {

    // if we waited enough interruptions
    if (olit <= 0) {

        // get note to be played
        PlayNote play = song.notes[index];

        // Change the timer Frequency
        RPI_GetArmTimer()->Reload = play.note.Frequency;

        // Setup the time to be waited
        olit = calculateOlit(play);

        // Prepare for next song
        index++;
        if (index == song.size && song.replay) { index = 0; }

    } else {
        // wait
        olit--;
    }

}
