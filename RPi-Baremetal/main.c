
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "hal/rpi-gpio.h"
#include "hal/rpi-armtimer.h"
#include "hal/rpi-interrupts.h"
#include "solfege/solfege.h"
#include "song/song.h"
#include "play/play.h"

extern void __enable_interrupts ( void );

//-------------------------------------------------------------------------
void __attribute__((interrupt("IRQ"))) interrupt_vector ( void )
{
    static int lit = 0;

    RPI_GetArmTimer()->IRQClear = 1;

    if( lit )
    {
        SOUND_OFF();
        lit = 0;
    }
    else
    {
        SOUND_ON();
        lit = 1;
    }

    /* -------- Song Play -------- */

    PlaySong();

    /* ---------------------------- */
}

//-------------------------------------------------------------------------
int notmain ( void )
{
    RPI_GetIrqController()->Disable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;

    RPI_GetGpio()->SOUND_GPFSEL |= 1 << SOUND_GPFBIT;

    /* -------- Song Setup -------- */

    // Setup

    Song b = createQuienSeHaTomado();


    /* ---------------------------- */

    /* Setup the ARM Timer */
    RPI_GetArmTimer()->Control =
        RPI_ARMTIMER_CTRL_23BIT |
        RPI_ARMTIMER_CTRL_ENABLE |
        RPI_ARMTIMER_CTRL_INT_ENABLE |
        RPI_ARMTIMER_CTRL_PRESCALE_1;

    RPI_GetIrqController()->Enable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;
    __enable_interrupts();

    static int sw_flag = 0;

    while(1) {
        if ((RPI_GetGpio()->SW_GPFLEV & SW_GPIO_BIT)) {
            if (!sw_flag) {
                sw_flag = 1;
                changeSong(b);
            }
        } else {
            sw_flag = 0;
        }

    }
    return(0);
}
