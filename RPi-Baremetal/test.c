
#include <stdio.h>
#include "solfege/solfege.h"



int main(int argc, char *argv[]) {


    note notes[7] = {
            {DO, 5000},
            {RE, 5000},
            {MI, 5000},
            {FA, 5000},
            {SOL, 5000},
            {LA, 5000},
            {SI, 5000},
    };

    static int index = 0;
    static int olit = 0;
    static int start = 1;

    if (!olit || start) {

        if (start) { start = 0; }

        // take the note
        Note note = notes[index].note;
        int msec = notes[index].msec;

        // make it sound
        printf("Frequency -> %d, Lit: -> %d, Msec: -> %d \n", note.Frequency, note.Lit, msec);
        //RPI_GetArmTimer()->Reload = note.Frequency;

        // set next note
        olit = note.Lit * (msec / 1000);
        index++;
        if (index == 6) { index = 0; }

    } else {
        // wait
        olit--;
    }

    return 0;
}
