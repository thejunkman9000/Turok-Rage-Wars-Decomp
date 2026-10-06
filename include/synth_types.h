#ifndef SYNTH_TYPES_H
#define SYNTH_TYPES_H

#include "libaudio.h"

/* sndplayer.c: sound envelope / sound / per-sound state with exact offsets
   (libaudio.h only has the fields of ALSound / ALSoundState used by the setter functions) */
typedef struct {
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 attackVolume;
    u8 decayVolume;
    u8 pad0E[2];
} ALSndEnvelope;

typedef struct {
    ALSndEnvelope *envelope;
    void *keyMap;
    void *wavetable;
    u8 samplePan;
    u8 sampleVolume;
    u8 flags;
    u8 pad0F;
} ALSndSound;

typedef struct ALSndState_s {
    ALVoice voice;          /* 0x00 */
    ALSndSound *sound;      /* 0x1C */
    s16 priority;           /* 0x20 */
    f32 pitch;              /* 0x24 */
    s32 state;              /* 0x28 */
    s16 vol;                /* 0x2C */
    u8 pan;                 /* 0x2E */
    u8 fxMix;               /* 0x2F */
} ALSndState;               /* 0x30 */

typedef struct {
    s32 maxSounds;
    s32 maxEvents;
    ALHeap *heap;
} ALSndpConfig;

/* synthesizer.c: element of the main-bus block (ALSynth.mainBus points to an array of these; alSynAllocFX
   builds the effect filter in the tail of element `bus` and uses the element itself as its source) */
typedef struct {
    u8 pad00[0x20];
    u8 fx[0x2C];
} ALSynFxBus;

#define AL_SNDP_DECAY_EVT 6
#define AL_SNDP_END_EVT 7
#define AL_SNDP_API_EVT 5
#define AL_PLAYING 1
#define AL_STOPPING 2

#endif
