# RPI Baremetal :speaker:
## 1-bit audio

### Intro
This proyect was made as an exercise in FaMAF - Córdoba, Argentina for the course Computer Architecture.

### What is 1-bit music?

[Please read this document](docs/Intro.pdf)

### How do we manage to achieve single bit music?

The raspberry manages to send bit signals through the pins, we use the pin connected with the signal GPIO18 to send a bit, which causes the speaker cone to go fordward or backwards.

This effect causes the speaker cone to vibrate and reproduce a sound. This vibration depends on the frequency on which the micro sends the bit, on every interruption it changes the bit value:

```c
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
	...
}
```

That's why each note has to define a different frequency on which the micro has to perform the interruptions, in order to achieve different notes, for example, in the case of *LA*, which has a 440 Frequency, we need the micro to work in `1000000/440`. A frequency of 1000000, equals a single interruption per second, so `1000000/440` will perform many more (440).

Using this formulas, we built the different times on which the notes will have to be played in order to achieve music.

For example, the first octave *LA*, uses as frequency `500000 / 440`, so we will have `2* 440` IPS (interruptions per second). If we need the note to be played during a *QUAVER* (0.5 sec), we need to perform `440` interruptions before passing to next note.

And so on . . .

### Structure

- **hal**: This module takes care of the communication with the RPi pins using GPIO registers.
	
- **solfege**: Defines the different structures we use accross the project, including the notes and some static values.

- **play**: Defines the logic to play a song, the song is defined in *solfege* as an array of structures **PlayNote**.

- **songs**: Defines different songs, which can be selected in *main.c* to be played.
