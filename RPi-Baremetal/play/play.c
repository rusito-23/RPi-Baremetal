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
    int seconds = play.note.IPS * play.duration.s;
    
    // as we cannot use double or floating point numbers,
    // we need to round the result of the division by 10
    // for the Intructions Per Second.
    // The final result (Intructions per decisecond to be played) is still aceptable.
    int deciseconds = play.note.IPS;
    while(deciseconds % 10 != 0) {
        deciseconds++;
    }
    deciseconds = (deciseconds / 10) * play.duration.ds;

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
