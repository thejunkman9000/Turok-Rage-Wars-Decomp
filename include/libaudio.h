#ifndef LIBAUDIO_H
#define LIBAUDIO_H

#include "common.h"

/* ---- libultra audio library (compact sequences, sequence players, synthesizer) ---- */

#define AL_SEQ_MIDI_EVT 1
#define AL_TEMPO_EVENT 3
#define AL_SEQP_LOOP_START_EVT 0x13
#define AL_SEQP_LOOP_END_EVT 0x14
#define AL_TRACK_END 4
#define AL_SEQ_END_EVT 0x12

/* compact MIDI sequence file header: one offset per track, then the division */
typedef struct {
    u32 trackOffset[16];
    u32 division;
} ALCSeqFile;

typedef struct {
    ALCSeqFile *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u32 deltaFlag;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
} ALCSeq;

typedef struct {
    u32 validTracks;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
} ALCSeqMarker;

typedef struct {
    s32 ticks;
    u8 status;
    u8 byte1;
    u8 byte2;
    u32 duration;
} ALMIDIEvent;

typedef struct {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
    u8 byte1;
    u8 byte2;
    u8 byte3;
} ALTempoEvent;

typedef struct {
    s16 type;
    union {
        ALMIDIEvent midi;
        ALTempoEvent tempo;
        s32 ticks;
    } msg;
} ALEvent;

/* NOTE: GCC emits a file's functions in the order their names are first declared, so function prototypes belong in
   the .c files (in ROM order), not in this header. */

#endif
