//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "../hal/rpi-gpio.h"
#include "../hal/rpi-armtimer.h"
#include "../solfege/solfege.h"
#include "../song/song.h"

static Song song;
static int index;
static int olit;

//-------------------------------------------------------------------------

void InitSong(Song sSong) {
    song = sSong;
    index = 1;
    olit = song.notes[index].note.Lit * (song.notes[index].msec / 1000);

    RPI_GetArmTimer()->Load = song.notes[0].note.Frequency;
}


void PlaySong() {

    if (olit == 0) {
        olit = song.notes[index].note.Lit * (song.notes[index].msec / 1000);
        RPI_GetArmTimer()->Reload = song.notes[index].note.Frequency;


        index++;
        if (index == song.size) { index = 0; }
    } else {
        // wait
        olit--;
    }
}
