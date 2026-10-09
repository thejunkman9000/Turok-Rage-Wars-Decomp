#include "seqp_types.h"

/* seqplayer.c: sequence player (ROM 0xB60A0-0xB7B50) */
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void alEvtqNew(ALEventQueue *evtq, ALEventQueueItem *items, s32 itemCount);
void alSynAddPlayer(void *drvr, ALPlayer *client);
void alSynStopVoice(void *drvr, ALVoice *voice);
void alSynFreeVoice(void *drvr, ALVoice *voice);
void alSynSetVol(void *drvr, ALVoice *voice, s16 vol, s32 time);
void alSynSetPitch(void *drvr, ALVoice *voice, f32 pitch);
void alSynSetPan(void *drvr, ALVoice *voice, u8 pan);
void alSynSetFXMix(void *drvr, ALVoice *voice, u8 fxmix);
void alSynSetPriority(void *drvr, ALVoice *voice, s16 priority);
s32 alSynAllocVoice(void *drvr, ALVoice *voice, ALVoiceConfig *vc);
void alSynStartVoiceParams(void *drvr, ALVoice *voice, void *w, f32 pitch, s16 vol, u8 pan, u8 fxmix, s32 t);
void alEvtqPostEvent(ALEventQueue *evtq, ALEventFull *evt, ALMicroTime delta);
void alEvtqFlushType(ALEventQueue *evtq, s16 type);
ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEventFull *evt);
void alLink(ALLink *ln, ALLink *to);
void alUnlink(ALLink *ln);
f32 alCents2Ratio(s32 cents);
void __assert(const char *a, const char *b, s32 c);
void alSeqNextEvent(ALSeq *seq, ALEventFull *event);
void alSeqSetLoc(ALSeq *seq, ALSeqMarker *m);
s32 alSeqGetTicks(ALSeq *seq);
u8 __alSeqNextDelta(ALSeq *seq, s32 *pDeltaTicks);
typedef s32 (*ALOscInitFn)(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay);

/* declaration order = emission order of the deferred (inlinable) helpers */
void alSeqpNew(ALSeqPlayerFull *seqp, ALSeqpConfigX *c);
ALMicroTime __voiceHandler(void *node);
void __handleNextSeqEvent(ALSeqPlayerFull *seqp);
void __handleMIDIMsg(ALSeqPlayerFull *seqp, ALEventFull *event);
ALVoiceState *__mapVoice(ALSeqPlayerFull *seqp, u8 key, u8 vel, u8 channel);
void __unmapVoice(ALSeqPlayerFull *seqp, ALVoice *voice);
u8 __voiceNeedsNoteKillOff(ALSeqPlayerFull *seqp, ALVoice *voice, s32 killTime);
ALVoiceState *__lookupVoice(ALSeqPlayerFull *seqp, u8 key, u8 chan);
ALSoundFull *__lookupSoundQuick(ALSeqPlayerFull *seqp, u8 key, u8 vel, u8 chan);
s16 __vsVol(ALVoiceState *vs, ALSeqPlayerFull *seqp);
s32 __vsDelta(ALVoiceState *vs, s32 t);
u8 __vsPan(ALVoiceState *vs, ALSeqPlayerFull *seqp);
void __initFromBank(ALSeqPlayerFull *seqp, ALBankX *b);
void __initChanState(ALSeqPlayerFull *seqp);
void __resetPerfChanState(ALSeqPlayerFull *seqp, s32 chan);
void __setInstChanState(ALSeqPlayerFull *seqp, ALInstrumentX *inst, s32 chan);
void __seqpReleaseVoice(ALSeqPlayerFull *seqp, ALVoice *voice, s32 deltaTime);
void __seqpStopOsc(ALSeqPlayerFull *seqp, ALVoiceState *vs);
void __postNextSeqEvent(ALSeqPlayerFull *seqp);
void __handleMetaMsg(ALSeqPlayerFull *seqp, ALEventFull *event);
void __setUsptFromTempo(ALSeqPlayerFull *seqp, f32 tempo);

void alSeqpNew(ALSeqPlayerFull *seqp, ALSeqpConfigX *c) {
    ALHeap *hp = c->heap;
    ALVoiceState *vs;
    ALVoiceState *voices;
    s32 i;
    seqp->chanMask = 0xFF;
    seqp->uspt = 488;
    seqp->bank = 0;
    seqp->target = 0;
    seqp->nextDelta = 0;
    seqp->state = 0;
    seqp->vol = 0x7FFF;
    seqp->drvr = alGlobalsp;
    seqp->debugFlags = c->debugFlags;
    seqp->frameTime = 16000;
    seqp->curTime = 0;
    seqp->initOsc = c->initOsc;
    seqp->updateOsc = c->updateOsc;
    seqp->stopOsc = c->stopOsc;
    seqp->loopStart = 0;
    seqp->loopEnd = 0;
    seqp->loopCount = 0;
    seqp->nextEvent.type = 9;
    seqp->maxChannels = c->maxChannels;
    seqp->chanState = alHeapDBAlloc(0, 0, hp, c->maxChannels, 16);
    __initChanState(seqp);
    voices = alHeapDBAlloc(0, 0, hp, c->maxVoices, 0x38);
    seqp->vFreeList = 0;
    for (i = 0; i < c->maxVoices; i++) {
        vs = &voices[i];
        vs->next = seqp->vFreeList;
        seqp->vFreeList = vs;
    }
    seqp->vAllocHead = 0;
    seqp->vAllocTail = 0;
    alEvtqNew(&seqp->evtq, alHeapDBAlloc(0, 0, hp, c->maxEvents, 0x1C), c->maxEvents);
    seqp->node.next = 0;
    seqp->node.handler = __voiceHandler;
    seqp->node.clientData = seqp;
    alSynAddPlayer(alGlobalsp, (ALPlayer *)seqp);
}

ALMicroTime __voiceHandler(void *node) {
    ALSeqPlayerFull *seqp = (ALSeqPlayerFull *)node;
    ALEventFull evt;
    f32 oscValue;
    ALVoice *voice;
    ALVoiceState *vs;
    void *oscState;
    ALMicroTime delta;
    u8 chan;
    do {
        switch (seqp->nextEvent.type) {
        case 0:
            __handleNextSeqEvent(seqp);
            break;
        case 9:
            evt.type = 9;
            alEvtqPostEvent(&seqp->evtq, &evt, seqp->frameTime);
            break;
        case 5:
            voice = seqp->nextEvent.msg.voice.voice;
            alSynStopVoice(seqp->drvr, voice);
            alSynFreeVoice(seqp->drvr, voice);
            vs = voice->clientPrivate;
            if (vs->flags != 0) {
                __seqpStopOsc(seqp, vs);
            }
            __unmapVoice(seqp, voice);
            break;
        case 6:
            voice = seqp->nextEvent.msg.env.voice;
            vs = voice->clientPrivate;
            if (vs->envPhase == 0) {
                vs->envPhase = 1;
            }
            delta = seqp->nextEvent.msg.env.delta;
            vs->envGain = seqp->nextEvent.msg.env.gain;
            vs->envEndTime = seqp->curTime + delta;
            alSynSetVol(seqp->drvr, voice, __vsVol(vs, seqp), delta);
            break;
        case 0x16:
            vs = seqp->nextEvent.msg.osc.state;
            oscState = seqp->nextEvent.msg.osc.oscState;
            delta = ((ALMicroTime (*)(void *, f32 *))seqp->updateOsc)(oscState, &oscValue);
            vs->tremelo = (u8)oscValue;
            alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
            evt.type = 0x16;
            evt.msg.osc.state = vs;
            evt.msg.osc.oscState = oscState;
            alEvtqPostEvent(&seqp->evtq, &evt, delta);
            break;
        case 0x17:
            oscState = seqp->nextEvent.msg.osc.oscState;
            vs = seqp->nextEvent.msg.osc.state;
            chan = seqp->nextEvent.msg.osc.chan;
            delta = ((ALMicroTime (*)(void *, f32 *))seqp->updateOsc)(oscState, &oscValue);
            vs->vibrato = oscValue;
            alSynSetPitch(seqp->drvr, &vs->voice, vs->pitch * vs->vibrato * seqp->chanState[chan].pitchBend);
            evt.type = 0x17;
            evt.msg.osc.state = vs;
            evt.msg.osc.oscState = oscState;
            evt.msg.osc.chan = chan;
            alEvtqPostEvent(&seqp->evtq, &evt, delta);
            break;
        case 2:
            __handleMIDIMsg(seqp, &seqp->nextEvent);
            break;
        case 7:
            __handleMetaMsg(seqp, &seqp->nextEvent);
            break;
        case 0xF:
            if (seqp->state != 1) {
                seqp->state = 1;
                __postNextSeqEvent(seqp);
            }
            break;
        case 0x10:
            if (seqp->state == 2) {
                for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead) {
                    voice = &vs->voice;
                    alSynStopVoice(seqp->drvr, voice);
                    alSynFreeVoice(seqp->drvr, voice);
                    if (vs->flags != 0) {
                        __seqpStopOsc(seqp, vs);
                    }
                    __unmapVoice(seqp, voice);
                }
                seqp->curTime = 0;
                seqp->state = 0;
            }
            break;
        case 0x11:
            if (seqp->state == 1) {
                alEvtqFlushType(&seqp->evtq, 0);
                alEvtqFlushType(&seqp->evtq, 2);
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                    if (__voiceNeedsNoteKillOff(seqp, &vs->voice, 50000)) {
                        __seqpReleaseVoice(seqp, &vs->voice, 50000);
                    }
                }
                seqp->state = 2;
                evt.type = 0x10;
                alEvtqPostEvent(&seqp->evtq, &evt, 0x7FFFFFFF);
            }
            break;
        case 0xA:
            seqp->vol = seqp->nextEvent.msg.spvol.vol;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
            }
            break;
        case 0xB:
            seqp->loopStart = seqp->nextEvent.msg.loop.loopStart;
            seqp->loopEnd = seqp->nextEvent.msg.loop.loopEnd;
            seqp->loopCount = seqp->nextEvent.msg.loop.loopCount;
            break;
        case 0xC:
            seqp->chanState[seqp->nextEvent.msg.prio.chan].priority = seqp->nextEvent.msg.prio.priority;
            break;
        case 0xD:
            if (seqp->state == 1) {
                __assert("EX", "audio/seqplayer.c", 0x128);
            }
            seqp->target = seqp->nextEvent.msg.spseq.seq;
            __setUsptFromTempo(seqp, 500000.0f);
            if (seqp->bank != 0) {
                __initFromBank(seqp, seqp->bank);
            }
            break;
        case 0xE:
            if (seqp->state != 0) {
                __assert("EX", "audio/seqplayer.c", 0x131);
            }
            __initFromBank(seqp, seqp->bank = seqp->nextEvent.msg.spbank.bank);
            break;
        case 1:
        case 3:
        case 4:
            __assert("EX", "audio/seqplayer.c", 0x13B);
            break;
        default:
            break;
        }
        seqp->nextDelta = alEvtqNextEvent(&seqp->evtq, &seqp->nextEvent);
    } while (seqp->nextDelta == 0);
    seqp->curTime += seqp->nextDelta;
    return seqp->nextDelta;
}

void __postNextSeqEvent(ALSeqPlayerFull *seqp) {
    ALEventFull evt;
    s32 deltaTicks;
    ALSeq *seq = seqp->target;
    if (seqp->state != 1) {
        return;
    }
    if (seq == 0) {
        return;
    }
    if (__alSeqNextDelta(seq, &deltaTicks)) {
        if (seqp->loopCount != 0) {
            if (alSeqGetTicks(seq) + deltaTicks >= seqp->loopEnd->curTicks) {
                alSeqSetLoc(seq, seqp->loopStart);
                if (seqp->loopCount != -1) {
                    seqp->loopCount--;
                }
            }
        }
        evt.type = 0;
        alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);
    }
}

void __handleNextSeqEvent(ALSeqPlayerFull *seqp) {
    ALEventFull evt;
    if (seqp->target == 0) {
        return;
    }
    alSeqNextEvent(seqp->target, &evt);
    switch (evt.type) {
    case 1:
        __handleMIDIMsg(seqp, &evt);
        __postNextSeqEvent(seqp);
        break;
    case 3:
        __handleMetaMsg(seqp, &evt);
        __postNextSeqEvent(seqp);
        break;
    case 4:
        seqp->state = 2;
        evt.type = 0x10;
        alEvtqPostEvent(&seqp->evtq, &evt, 0x7FFFFFFF);
        break;
    default:
        __assert("EX", "audio/seqplayer.c", 0x19C);
        break;
    }
}

void __handleMIDIMsg(ALSeqPlayerFull *seqp, ALEventFull *event) {
    ALEventFull evt;
    ALVoiceConfig config;
    void *oscState;
    f32 oscValue;
    ALVoiceState *vs;
    ALVoice *voice;
    ALSoundFull *sound;
    ALInstrumentX *inst;
    ALBankX *bank;
    s32 delta;
    f32 pitchBend;
    f32 pitch;
    u8 fxmix;
    u8 pan;
    s16 vol;
    s32 bend;
    ALMIDIEvent *midi = &event->msg.midi;
    s32 status;
    u8 chan;
    u8 key;
    u8 vel;
    u8 key2;
    u8 vel2;
    if (event->type != 1 && event->type != 2) {
        __assert("EX", "audio/seqplayer.c", 0x1B4);
    }
    chan = midi->status & 0xF;
    status = midi->status & 0xF0;
    key = midi->byte1;
    vel = midi->byte2;
    key2 = key;
    vel2 = vel;
    switch (status) {
    case 0x90:
        if (vel != 0) {
            if (seqp->state == 1) {
                sound = __lookupSoundQuick(seqp, key, vel, chan);
                if (sound != 0) {
                    config.priority = seqp->chanState[chan].priority;
                    config.fxBus = 0;
                    config.unityPitch = 0;
                    vs = __mapVoice(seqp, key, vel, chan);
                    if (vs != 0) {
                        voice = &vs->voice;
                        alSynAllocVoice(seqp->drvr, voice, &config);
                        vs->sound = (ALSound *)sound;
                        vs->envPhase = 0;
                        if (seqp->chanState[chan].sustain >= 0x40) {
                            vs->phase = 2;
                        } else {
                            vs->phase = 0;
                        }
                        vs->pitch = alCents2Ratio((s16)(sound->keyMap->detune + (key - sound->keyMap->keyBase) * 100));
                        vs->envGain = sound->envelope->attackVolume;
                        vs->envEndTime = seqp->curTime + sound->envelope->attackTime;
                        vs->flags = 0;
                        inst = seqp->chanState[chan].inst;
                        oscValue = 127.0f;
                        if (inst->tremType != 0 && seqp->initOsc != 0) {
                            delta = ((ALOscInitFn)seqp->initOsc)(&oscState, &oscValue, inst->tremType, inst->tremRate, inst->tremDepth, inst->tremDelay);
                            if (delta != 0) {
                                evt.type = 0x16;
                                evt.msg.osc.state = vs;
                                evt.msg.osc.oscState = oscState;
                                alEvtqPostEvent(&seqp->evtq, &evt, delta);
                                vs->flags |= 1;
                            }
                        }
                        vs->tremelo = (u8)oscValue;
                        oscValue = 1.0f;
                        if (inst->vibType != 0 && seqp->initOsc != 0) {
                            delta = ((ALOscInitFn)seqp->initOsc)(&oscState, &oscValue, inst->vibType, inst->vibRate, inst->vibDepth, inst->vibDelay);
                            if (delta != 0) {
                                evt.type = 0x17;
                                evt.msg.osc.state = vs;
                                evt.msg.osc.oscState = oscState;
                                evt.msg.osc.chan = chan;
                                alEvtqPostEvent(&seqp->evtq, &evt, delta);
                                vs->flags |= 2;
                            }
                        }
                        vs->vibrato = oscValue;
                        pitch = vs->pitch * seqp->chanState[chan].pitchBend * oscValue;
                        fxmix = seqp->chanState[chan].fxmix;
                        pan = __vsPan(vs, seqp);
                        vol = __vsVol(vs, seqp);
                        delta = sound->envelope->attackTime;
                        alSynStartVoiceParams(seqp->drvr, voice, sound->wavetable, pitch, vol, pan, fxmix, delta);
                        evt.type = 6;
                        evt.msg.env.voice = voice;
                        evt.msg.env.gain = sound->envelope->decayVolume;
                        evt.msg.env.delta = sound->envelope->decayTime;
                        alEvtqPostEvent(&seqp->evtq, &evt, sound->envelope->attackTime);
                    }
                }
            }
            break;
        }
        /* fall through */
    case 0x80:
        vs = __lookupVoice(seqp, key, chan);
        if (vs != 0) {
            if (vs->phase == 2) {
                vs->phase = 4;
            } else {
                vs->phase = 3;
                __seqpReleaseVoice(seqp, &vs->voice, ((ALSoundFull *)vs->sound)->envelope->releaseTime);
            }
        }
        break;
    case 0xA0:
        vs = __lookupVoice(seqp, key, chan);
        if (vs != 0) {
            vs->velocity = vel;
            alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
        }
        break;
    case 0xD0:
        for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
            if (vs->channel == chan) {
                vs->velocity = key2;
                alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
            }
        }
        break;
    case 0xB0:
        switch (key) {
        case 10:
            seqp->chanState[chan].pan = vel;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan) {
                    pan = __vsPan(vs, seqp);
                    alSynSetPan(seqp->drvr, &vs->voice, pan);
                }
            }
            break;
        case 7:
            seqp->chanState[chan].vol = vel;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan && vs->envPhase != 3) {
                    vol = __vsVol(vs, seqp);
                    alSynSetVol(seqp->drvr, &vs->voice, vol, __vsDelta(vs, seqp->curTime));
                }
            }
            break;
        case 16:
            seqp->chanState[chan].priority = vel;
            break;
        case 64:
            seqp->chanState[chan].sustain = vel;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan && vs->phase != 3) {
                    if (vel >= 0x40) {
                        if (vs->phase == 0) {
                            vs->phase = 2;
                        }
                    } else {
                        if (vs->phase == 2) {
                            vs->phase = 0;
                        } else if (vs->phase == 4) {
                            vs->phase = 3;
                            __seqpReleaseVoice(seqp, &vs->voice, ((ALSoundFull *)vs->sound)->envelope->releaseTime);
                        }
                    }
                }
            }
            break;
        case 0x5B:
            seqp->chanState[chan].fxmix = vel;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan) {
                    alSynSetFXMix(seqp->drvr, &vs->voice, vel2);
                }
            }
            break;
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 0x5D:
            break;
        default:
            break;
        }
        break;
    case 0xC0:
        if (seqp->bank == 0) {
            __assert("EX", "audio/seqplayer.c", 0x2CA);
        }
        bank = seqp->bank;
        if (key < bank->instCount) {
            __setInstChanState(seqp, (ALInstrumentX *)bank->instArray[key], chan);
        }
        break;
    case 0xE0:
        bend = (vel << 7) + key - 0x2000;
        pitchBend = alCents2Ratio(seqp->chanState[chan].bendRange * bend / 8192);
        seqp->chanState[chan].pitchBend = pitchBend;
        for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
            if (vs->channel == chan) {
                alSynSetPitch(seqp->drvr, &vs->voice, vs->pitch * pitchBend * vs->vibrato);
            }
        }
        break;
    default:
        break;
    }
}

ALVoiceState *__mapVoice(ALSeqPlayerFull *seqp, u8 key, u8 vel, u8 channel) {
    ALVoiceState *vs = seqp->vFreeList;
    if (vs != 0) {
        seqp->vFreeList = vs->next;
        vs->next = 0;
        if (seqp->vAllocHead == 0) {
            seqp->vAllocHead = vs;
        } else {
            seqp->vAllocTail->next = vs;
        }
        seqp->vAllocTail = vs;
        vs->channel = channel;
        vs->key = key;
        vs->velocity = vel;
        vs->voice.clientPrivate = vs;
    }
    return vs;
}

void __unmapVoice(ALSeqPlayerFull *seqp, ALVoice *voice) {
    ALVoiceState *prev = 0;
    ALVoiceState *vs;
    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if (&vs->voice == voice) {
            if (prev != 0) {
                prev->next = vs->next;
            } else {
                seqp->vAllocHead = vs->next;
            }
            if (vs == seqp->vAllocTail) {
                seqp->vAllocTail = prev;
            }
            vs->next = seqp->vFreeList;
            seqp->vFreeList = vs;
            return;
        }
        prev = vs;
    }
}

u8 __voiceNeedsNoteKillOff(ALSeqPlayerFull *seqp, ALVoice *vs, s32 killTime) {
    s32 itemTime = 0;
    s32 status = 1;
    ALLink *thisNode = seqp->evtq.allocList.next;
    ALEventQueueItemFull *nextItem;
    ALEventQueueItemFull *thisItem;
    ALLink *nextNode;
    while (thisNode != 0) {
        nextNode = thisNode->next;
        thisItem = (ALEventQueueItemFull *)thisNode;
        nextItem = (ALEventQueueItemFull *)nextNode;
        itemTime += thisItem->delta;
        if (thisItem->evt.type == 5) {
            if (thisItem->evt.msg.voice.voice == vs) {
                if (itemTime > killTime) {
                    if (nextItem != 0) { nextItem->delta += thisItem->delta; }
                    alUnlink(thisNode);
                    alLink(thisNode, &seqp->evtq.freeList);
                    return status;
                }
                status = 0;
                break;
            }
        }
        thisNode = nextNode;
    }
    return status;
}

ALVoiceState *__lookupVoice(ALSeqPlayerFull *seqp, u8 key, u8 chan) {
    ALVoiceState *vs;
    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if (vs->key == key && vs->channel == chan && vs->phase != 3 && vs->phase != 4) {
            return vs;
        }
    }
    return 0;
}

ALSoundFull *__lookupSoundQuick(ALSeqPlayerFull *seqp, u8 key, u8 vel, u8 chan) {
    ALInstrumentX *inst = seqp->chanState[chan].inst;
    s32 l = 1;
    s32 r = inst->soundCount;
    s32 i;
    ALSoundFull *sound;
    ALKeyMapX *keymap;
    if (inst == 0) {
        __assert("EX", "audio/seqplayer.c", 0x376);
    }
    while (r >= l) {
        i = (l + r) / 2;
        sound = inst->soundArray[i - 1];
        keymap = sound->keyMap;
if (key >= keymap->keyMin && key <= keymap->keyMax && vel >= keymap->velocityMin && vel <= keymap->velocityMax) { return sound; }
if (key < keymap->keyMin) { r = i - 1; } else if (vel < keymap->velocityMin) { if (key > keymap->keyMax) { l = i + 1; } else { r = i - 1; } } else { l = i + 1; }
    }
    return 0;
}

s16 __vsVol(ALVoiceState *vs, ALSeqPlayerFull *seqp) {
    s32 t1, t2;
    t1 = (vs->tremelo * vs->velocity * vs->envGain) >> 6;
    t2 = (((ALSoundFull *)vs->sound)->sampleVolume * seqp->vol * seqp->chanState[vs->channel].vol) >> 14;
    t1 = t1 * t2;
    return (t1 << 1) >> 16;
}

s32 __vsDelta(ALVoiceState *vs, s32 t) {
    s32 delta;
    delta = vs->envEndTime - t;
    if (delta >= 0) {
        return delta;
    }
    return 1000;
}

u8 __vsPan(ALVoiceState *vs, ALSeqPlayerFull *seqp) {
    s32 tmp;
    tmp = seqp->chanState[vs->channel].pan - 64 + ((ALSoundFull *)vs->sound)->samplePan;
    if (tmp < 0) {
        tmp = 0;
    }
    if (tmp > 127) {
        tmp = 127;
    }
    return tmp;
}

void __initFromBank(ALSeqPlayerFull *seqp, ALBankX *b) {
    ALInstrumentX *inst;
    s32 i;
    s32 j = 0;
    do {
        inst = b->instArray[j++];
    } while (inst == 0);
    for (i = 0; i < seqp->maxChannels; i++) {
        __resetPerfChanState(seqp, i);
        __setInstChanState(seqp, inst, i);
    }
    if (b->percussion != 0) {
        __resetPerfChanState(seqp, i);
        __setInstChanState(seqp, b->percussion, 9);
    }
}

void __initChanState(ALSeqPlayerFull *seqp) {
    s32 i;
    for (i = 0; i < seqp->maxChannels; i++) {
        seqp->chanState[i].inst = 0;
        seqp->chanState[i].fxId = 0;
        seqp->chanState[i].fxmix = 0;
        seqp->chanState[i].pan = 0x40;
        seqp->chanState[i].vol = 0x7F;
        seqp->chanState[i].priority = 5;
        seqp->chanState[i].sustain = 0;
        seqp->chanState[i].bendRange = 200;
        seqp->chanState[i].pitchBend = 1.0f;
    }
}

void __resetPerfChanState(ALSeqPlayerFull *seqp, s32 chan) {
    seqp->chanState[chan].fxId = 0;
    seqp->chanState[chan].fxmix = 0;
    seqp->chanState[chan].pan = 0x40;
    seqp->chanState[chan].vol = 0x7F;
    seqp->chanState[chan].priority = 5;
    seqp->chanState[chan].sustain = 0;
    seqp->chanState[chan].bendRange = 200;
    seqp->chanState[chan].pitchBend = 1.0f;
}

void __setInstChanState(ALSeqPlayerFull *seqp, ALInstrumentX *inst, s32 chan) {
    seqp->chanState[chan].inst = inst;
    seqp->chanState[chan].pan = inst->pan;
    seqp->chanState[chan].vol = inst->volume;
    seqp->chanState[chan].priority = inst->priority;
    seqp->chanState[chan].bendRange = inst->bendRange;
}

void __seqpReleaseVoice(ALSeqPlayerFull *seqp, ALVoice *voice, s32 deltaTime) {
    ALEventFull evt;
    ALVoiceState *vs = voice->clientPrivate;
    ALLink *thisNode;
    ALLink *nextNode;
    ALEventQueueItemFull *thisItem;
    ALEventQueueItemFull *nextItem;
    if (vs->envPhase == 0) {
        thisNode = seqp->evtq.allocList.next;
        while (thisNode != 0) {
            nextNode = thisNode->next;
            thisItem = (ALEventQueueItemFull *)thisNode;
            nextItem = (ALEventQueueItemFull *)nextNode;
            if (thisItem->evt.type == 6 && thisItem->evt.msg.voice.voice == voice) {
                if (nextItem != 0) {
                    nextItem->delta += thisItem->delta;
                }
                alUnlink(thisNode);
                alLink(thisNode, &seqp->evtq.freeList);
            }
            thisNode = nextNode;
        }
    }
    vs->velocity = 0;
    vs->envPhase = 3;
    vs->envGain = 0;
    vs->envEndTime = seqp->curTime + deltaTime;
    alSynSetPriority(seqp->drvr, voice, 0);
    alSynSetVol(seqp->drvr, voice, 0, deltaTime);
    evt.type = 5;
    evt.msg.voice.voice = voice;
    alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
}

void __seqpStopOsc(ALSeqPlayerFull *seqp, ALVoiceState *vs) {
    ALLink *thisNode = seqp->evtq.allocList.next;
    ALLink *nextNode;
    ALEventQueueItemFull *thisItem;
    ALEventQueueItemFull *nextItem;
    s16 type;
    while (thisNode != 0) {
        nextNode = thisNode->next;
        thisItem = (ALEventQueueItemFull *)thisNode;
        nextItem = (ALEventQueueItemFull *)nextNode;
        type = thisItem->evt.type;
        if (type == 0x16 || type == 0x17) {
            if (thisItem->evt.msg.osc.state == vs) {
                ((void (*)(void *))seqp->stopOsc)(thisItem->evt.msg.osc.oscState);
                alUnlink(thisNode);
                if (nextItem != 0) {
                    nextItem->delta += thisItem->delta;
                }
                alLink(thisNode, &seqp->evtq.freeList);
                if (type == 0x16) {
                    vs->flags &= 0xFE;
                } else {
                    vs->flags &= 0xFD;
                }
                if (vs->flags == 0) {
                    break;
                }
            }
        }
        thisNode = nextNode;
    }
}

void __handleMetaMsg(ALSeqPlayerFull *seqp, ALEventFull *event) {
    ALEventFull evt;
    s32 tempo;
    if (event->msg.tempo.status == 0xFF) {
        if (event->msg.tempo.type == 0x51) {
            tempo = (event->msg.tempo.byte1 << 16) | (event->msg.tempo.byte2 << 8) | event->msg.tempo.byte3;
            __setUsptFromTempo(seqp, (f32)tempo);
        }
    }
}

void __setUsptFromTempo(ALSeqPlayerFull *seqp, f32 tempo) {
    if (seqp->target != 0) {
        seqp->uspt = (s32)(tempo * seqp->target->qnpt);
    } else {
        seqp->uspt = 488;
    }
}
