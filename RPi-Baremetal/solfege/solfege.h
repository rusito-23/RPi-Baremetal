#ifndef SOLFEGE_H
#define SOLFEGE_H

#define BASE_FREQ 500000

typedef struct note_t {
    int Frequency;
    int Time;
    int Raw;
} note_t;

note_t* getNotes(void);

#endif
