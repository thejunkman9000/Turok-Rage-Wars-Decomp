#ifndef SEQP_TYPES_H
#define SEQP_TYPES_H

#include "libaudio.h"

/* Full layouts for the sequence players (seqplayer.c / csplayer.c) and friends.
   libaudio.h holds partial ALSeqPlayer / ALCSPlayer / ALChanState; these are the complete versions. */

typedef struct {
    s16 instCount;
    u8 flags;
    u8 pad03;
    s32 sampleRate;
    struct ALInstrument_s *percussion;
    struct ALInstrument_s *instArray[1];
} ALBankX;

typedef struct {
    void *inst; /* ALInstrument * */
    s16 bendRange;
    u8 fxId;
    u8 pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
} ALChanStateFull;

typedef struct {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
} ALKeyMapX;

typedef struct {
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 attackVolume;
    u8 decayVolume;
} ALEnvelopeX;

typedef struct {
    ALEnvelopeX *envelope;
    ALKeyMapX *keyMap;
    void *wavetable;
    u8 samplePan;
    u8 sampleVolume;
    u8 flags;
} ALSoundFull;

typedef struct ALInstrument_s {
    u8 volume;
    u8 pan;
    u8 priority;
    u8 flags;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    s16 bendRange;
    s16 soundCount;
    ALSoundFull *soundArray[1];
} ALInstrumentX;

typedef struct {
    s32 maxVoices;
    s32 maxEvents;
    u8 maxChannels;
    u8 debugFlags;
    u8 pad0A[2];
    ALHeap *heap;
    void *initOsc;
    void *updateOsc;
    void *stopOsc;
} ALSeqpConfigX;

/* full event record: ALEvent in libaudio.h only knows some message layouts */
typedef struct {
    s16 type;
    union {
        ALMIDIEvent midi;
        ALTempoEvent tempo;
        s32 ticks;
        struct { s16 vol; } spvol;
        struct { void *seq; } spseq;
        struct { void *bank; } spbank;
        struct { ALVoice *voice; } voice;
        struct { ALVoiceState *state; void *oscState; u8 chan; } osc;
        struct { ALSeqMarker *loopStart; ALSeqMarker *loopEnd; s32 loopCount; } loop;
        struct { ALVoice *voice; s32 delta; u8 gain; } env;
        struct { u8 chan; u8 priority; } prio;
    } msg;
} ALEventFull;

typedef struct {
    ALLink node;
    ALMicroTime delta;
    ALEventFull evt;
} ALEventQueueItemFull;


typedef struct {
    ALPlayer node;
    void *drvr;
    ALSeq *target;
    s32 curTime;
    void *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    u8 pad36[2];
    ALEventFull nextEvent;
    ALEventQueue evtq;
    s32 frameTime;
    ALChanStateFull *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    void *initOsc;
    void *updateOsc;
    void *stopOsc;
    ALSeqMarker *loopStart;
    ALSeqMarker *loopEnd;
    s32 loopCount;
} ALSeqPlayerFull;


/* compact sequence player (csplayer.c): same layout as the sequence player up to stopOsc, target is an ALCSeq */
typedef struct {
    ALPlayer node;
    void *drvr;
    ALCSeq *target;
    s32 curTime;
    void *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    u8 pad36[2];
    ALEventFull nextEvent;
    ALEventQueue evtq;
    s32 frameTime;
    ALChanStateFull *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    void *initOsc;
    void *updateOsc;
    void *stopOsc;
} ALCSPlayerFull;

#endif
