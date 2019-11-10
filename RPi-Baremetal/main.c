
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#include "hal/rpi-gpio.h"
#include "hal/rpi-armtimer.h"
#include "hal/rpi-interrupts.h"
#include "solfege/solfege.h"

static note notes[7] = {0};

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

    static int index = 1;
    static int olit = 261 * 2 * 5;

    if (olit == 0) {
        olit = notes[index].note.Lit * (notes[index].msec / 1000);
        RPI_GetArmTimer()->Reload = notes[index].note.Frequency;

        index++;
        if (index == 7) { index = 0; }
    } else {
        // wait
        olit--;
    }
}

//-------------------------------------------------------------------------
int notmain ( void )
{
    notes[0] = (struct note){.note= DO,     .msec= 5000};
    notes[1] = (struct note){.note= RE,     .msec= 5000};
    notes[2] = (struct note){.note= MI,     .msec= 5000};
    notes[3] = (struct note){.note= FA,     .msec= 5000};
    notes[4] = (struct note){.note= SOL,    .msec= 5000};
    notes[5] = (struct note){.note= LA,     .msec= 5000};
    notes[6] = (struct note){.note= SI,     .msec= 5000};

    RPI_GetIrqController()->Disable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;

    RPI_GetGpio()->LED_GPFSEL |= 1 << LED_GPFBIT;   // Configurar GPIO del LED como salida | Revisar definiciones en archivo rpi-gpio.h

    /* Setup the system timer interrupt */
    /* Timer frequency = CLK frequency = 1HHz, CLK period = 1 useg */
    RPI_GetArmTimer()->Load = notes[0].note.Frequency; // LA 1.000.000 useg = 1 seg.

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
