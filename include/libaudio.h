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
        struct { s16 vol; } spvol;
        struct { void *seq; } spseq;
        struct { void *bank; } spbank;
        struct { struct ALSoundState_s *state; } sndp;
        struct { struct ALSoundState_s *state; u8 pan; } sndpan;
        struct { struct ALSoundState_s *state; s16 vol; } sndvol;
        struct { struct ALSoundState_s *state; f32 pitch; } sndpitch;
        struct { struct ALSoundState_s *state; u8 fxmix; } sndfx;
    } msg;
} ALEvent;

typedef u32 OSIntMask;
typedef s32 ALMicroTime;

typedef struct ALLink_s {
    struct ALLink_s *next;
    struct ALLink_s *prev;
} ALLink;

typedef struct {
    ALLink node;
    ALMicroTime delta;
    ALEvent evt;
} ALEventQueueItem;

typedef struct {
    ALLink freeList;
    ALLink allocList;
    s32 eventCount;
} ALEventQueue;

/* compact-sequence player (csplayer.c); only the fields recovered so far */
typedef struct {
    u8 pad00[0x2C];
    s32 state;
    u8 pad30[0x48 - 0x30];
    ALEventQueue evtq;
} ALCSPlayer;

/* plain MIDI sequence (seq.c) */
typedef struct {
    u8 *base;
    u8 *trackStart;
    u8 *curPtr;
    s32 lastTicks;
    u32 len;
    f32 qnpt;
    s16 division;
    u16 lastStatus;
} ALSeq;

typedef struct {
    u8 *curPtr;
    s32 lastTicks;
    s32 curTicks;
    u16 lastStatus;
} ALSeqMarker;

/* sound player (sndplayer.c) */
typedef struct {
    u8 pad00[0x0D];
    u8 sampleVolume;
} ALSound;

typedef struct ALSoundState_s {
    ALLink node;
    u8 voice[0x14];
    ALSound *sound;
    s16 priority;
    f32 pitch;
    s32 state;
    s16 vol;
    u8 pan;
    u8 fxMix;
} ALSoundState;

typedef struct ALPlayer_s {
    struct ALPlayer_s *next;
    void *clientData;
    void *handler;
    s32 callTime;
    s32 samplesLeft;
} ALPlayer;

typedef struct {
    ALPlayer node;
    ALEventQueue evtq;
    ALEvent nextEvent;
    void *drvr;
    s32 target;
    ALSoundState *sndState;
    s32 maxSounds;
    s32 frameTime;
    s32 nextDelta;
    s32 curTime;
} ALSndPlayer;

#define AL_SNDP_PLAY_EVT 0
#define AL_SNDP_STOP_EVT 1
#define AL_SNDP_PAN_EVT 2
#define AL_SNDP_VOL_EVT 3
#define AL_SNDP_PITCH_EVT 4
#define AL_SNDP_FX_EVT 8
#define AL_STOPPED 0

/* synthesizer (synthesizer.c) */
typedef struct ALFilter_s {
    struct ALFilter_s *source;
    void *setSource;
    s32 (*setParam)(struct ALFilter_s *filter, s32 type, void *param);
    void *handler;
} ALFilter;

typedef struct ALParam_s {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 pad;
    s32 data;
} ALParam;

typedef struct ALPVoice_s {
    ALLink node;
    u8 pad08[4];
    ALFilter *channelKnob;
    u8 pad10[0xD8 - 0x10];
    s32 offset;
} ALPVoice;

typedef struct {
    ALLink node;
    ALPVoice *pvoice;
    u8 pad0C[0x16 - 0x0C];
    s16 priority;
} ALVoice;

typedef struct ALSynth_s {
    ALPlayer *head;
    ALLink pFreeList;
    ALLink pAllocList;
    ALLink pLameList;
    s32 paramSamples;
    s32 curSamples;
    u8 pad24[0x2C - 0x24];
    ALParam *paramList;
    u8 pad30[0x44 - 0x30];
    s32 outputRate;
} ALSynth;

typedef struct {
    ALSynth drvr;
} ALGlobals;

extern ALGlobals *alGlobalsp;

#define AL_SEQP_MIDI_EVT 2
#define AL_SEQP_VOL_EVT 0xA
#define AL_SEQP_SEQ_EVT 0xD
#define AL_SEQP_BANK_EVT 0xE
#define AL_SEQP_PLAY_EVT 0xF
#define AL_SEQP_STOP_EVT 0x11

OSIntMask osSetIntMask(OSIntMask mask);

/* NOTE: GCC emits a file's functions in the order their names are first declared, so function prototypes belong in
   the .c files (in ROM order), not in this header. */

#endif
