
#include <stdio.h>
#include "solfege/solfege.h"
#include "solfege/notes.h"



int main(int argc, char *argv[]) {

    // TEST ALGORITMO DE PROGRAMACION

    PlayNote notes[9] = {
        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= QUAVER},

        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= QUAVER},

        {.note= FIRST_OCTAVE(LA), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(SI), .duration= SEMIQUAVER},
        {.note= SECOND_OCTAVE(DO), .duration= SEMIQUAVER},
    };

    for (int i = 0; i < 9; i++) {
        int desec = notes[i].duration.ds;

        int IPS_B = notes[i].note.IPS;
        int IPS = notes[i].note.IPS;

        while(IPS % 10 != 0) {
            IPS++;
        }
        IPS = (IPS / 10) * desec;

        printf("desec: %d, IPS_B: %d, result: %d \n",desec, IPS_B, IPS);
    }

    return 0;
}
