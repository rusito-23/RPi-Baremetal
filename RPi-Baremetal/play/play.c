//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "../hal/rpi-gpio.h"
#include "../hal/rpi-armtimer.h"
#include "../solfege/solfege.h"

static note* song;
static int size;

//-------------------------------------------------------------------------

void InitSong(note* sSong, int sSize) {
    song = sSong;
    size = sSize;
    RPI_GetArmTimer()->Load = song[0].note.Frequency;
}


void PlaySong() {
    static int index = 1;
    static int olit = 261 * 2 * 5;

    if (olit == 0) {
        olit = song[index].note.Lit * (song[index].msec / 1000);
        RPI_GetArmTimer()->Reload = song[index].note.Frequency;

        index++;
        if (index == size) { index = 0; }
    } else {
        // wait
        olit--;
    }
}
