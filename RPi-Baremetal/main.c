
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "hal/rpi-gpio.h"
#include "hal/rpi-armtimer.h"
#include "hal/rpi-interrupts.h"
#include "solfege/solfege.h"

extern void __enable_interrupts ( void );

//-------------------------------------------------------------------------
void __attribute__((interrupt("IRQ"))) interrupt_vector ( void )
{
    static int lit = 0;

    static int index = 1;
    static int olit = 261 * 10;

    /* Clear the ARM Timer interrupt - it's the only interrupt we have
       enabled, so we want don't have to work out which interrupt source
       caused us to interrupt */
    RPI_GetArmTimer()->IRQClear = 1;

    //============================ CODE APP HERE =====================================
    /* EXAMPLE COD: Flip the LED every 1 second */
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

    if (olit == 0) {

        note_t note = getNotes()[index];
        RPI_GetArmTimer()->Reload = note.Frequency;

        // next note
        olit = note.Time;
        index++;
        if (index == 7) { index = 0; }
    } else {
        olit--;
    }
}

//-------------------------------------------------------------------------
int notmain ( void )
{

    RPI_GetIrqController()->Disable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;

    RPI_GetGpio()->LED_GPFSEL |= 1 << LED_GPFBIT;   // Configurar GPIO del LED como salida | Revisar definiciones en archivo rpi-gpio.h

    /* Setup the system timer interrupt */
    /* Timer frequency = CLK frequency = 1HHz, CLK period = 1 useg */
    RPI_GetArmTimer()->Load = getNotes()[0].Frequency; // LA 1.000.000 useg = 1 seg.

    /* Setup the ARM Timer */
    RPI_GetArmTimer()->Control =
        RPI_ARMTIMER_CTRL_23BIT |
        RPI_ARMTIMER_CTRL_ENABLE |
        RPI_ARMTIMER_CTRL_INT_ENABLE |
        RPI_ARMTIMER_CTRL_PRESCALE_1;

    RPI_GetIrqController()->Enable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;
    __enable_interrupts();

    while(1) {
        //============================ CODE APP HERE =====================================
    }
    return(0);
}
