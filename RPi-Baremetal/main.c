
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "hal/rpi-gpio.h"
#include "hal/rpi-armtimer.h"
#include "hal/rpi-interrupts.h"
#include "solfege/solfege.h"
#include "solfege/notes.h"
#include "play/play.h"
#include "song/song.h"

extern void __enable_interrupts ( void );

//-------------------------------------------------------------------------
void __attribute__((interrupt("IRQ"))) interrupt_vector ( void )
{
    static int lit = 0;
    RPI_GetArmTimer()->IRQClear = 1;

    if( lit )
    {
        LED_OFF();
        lit = 0;
    }
    else
    {
        LED_ON();
        lit = 1;
    }

    /* -------- Song Play -------- */

    PlaySong();

    /* ---------------------------- */
}

//-------------------------------------------------------------------------
int notmain ( void )
{
    PlayNote notes[7] = {0};
    notes[0] = (struct PlayNote){.note= DO,     .msec= 5000};
    notes[1] = (struct PlayNote){.note= RE,     .msec= 5000};
    notes[2] = (struct PlayNote){.note= MI,     .msec= 5000};
    notes[3] = (struct PlayNote){.note= FA,     .msec= 5000};
    notes[4] = (struct PlayNote){.note= SOL,    .msec= 5000};
    notes[5] = (struct PlayNote){.note= LA,     .msec= 5000};
    notes[6] = (struct PlayNote){.note= SI,     .msec= 5000};

    RPI_GetIrqController()->Disable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;

    RPI_GetGpio()->LED_GPFSEL |= 1 << LED_GPFBIT;   // Configurar GPIO del LED como salida | Revisar definiciones en archivo rpi-gpio.h

    /* -------- Song Setup -------- */

    Song song = {notes, 7};
    InitSong(song);

    /* ---------------------------- */

    /* Setup the ARM Timer */
    RPI_GetArmTimer()->Control =
        RPI_ARMTIMER_CTRL_23BIT |
        RPI_ARMTIMER_CTRL_ENABLE |
        RPI_ARMTIMER_CTRL_INT_ENABLE |
        RPI_ARMTIMER_CTRL_PRESCALE_1;

    RPI_GetIrqController()->Enable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;
    __enable_interrupts();

    while(1) {
    }
    return(0);
}
