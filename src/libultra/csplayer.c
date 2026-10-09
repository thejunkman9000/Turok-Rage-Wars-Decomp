#include "seqp_types.h"

/* csplayer.c: compact sequence player (ROM 0xB4780-0xB5B00, last word is linker padding) */
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void alEvtqNew(ALEventQueue *evtq, ALEventQueueItem *items, s32 itemCount);
void alSynAddPlayer(void *drvr, ALPlayer *client);
void alSynStopVoice(void *drvr, ALVoice *voice);
void alSynFreeVoice(void *drvr, ALVoice *voice);
void alSynSetVol(void *drvr, ALVoice *voice, s16 vol, s32 time);
void alSynSetPitch(void *drvr, ALVoice *voice, f32 pitch);
void alSynSetPan(void *drvr, ALVoice *voice, u8 pan);
void alSynSetFXMix(void *drvr, ALVoice *voice, u8 fxmix);
s32 alSynAllocVoice(void *drvr, ALVoice *voice, ALVoiceConfig *vc);
void alSynStartVoiceParams(void *drvr, ALVoice *voice, void *w, f32 pitch, s16 vol, u8 pan, u8 fxmix, s32 t);
void alEvtqPostEvent(ALEventQueue *evtq, ALEventFull *evt, ALMicroTime delta);
void alEvtqFlushType(ALEventQueue *evtq, s16 type);
ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEventFull *evt);
void alLink(ALLink *ln, ALLink *to);
void alUnlink(ALLink *ln);
f32 alCents2Ratio(s32 cents);
void __assert(const char *a, const char *b, s32 c);
s32 alCSeqNextEvent(ALCSeq *seq, ALEventFull *event);
u8 __alCSeqNextDelta(ALCSeq *seq, s32 *pDeltaTicks);
void __initChanState(ALCSPlayerFull *seqp);
void __initFromBank(ALCSPlayerFull *seqp, void *bank);
void __setInstChanState(ALCSPlayerFull *seqp, ALInstrumentX *inst, s32 chan);
ALVoiceState *__mapVoice(ALCSPlayerFull *seqp, u8 key, u8 vel, u8 channel);
ALVoiceState *__lookupVoice(ALCSPlayerFull *seqp, u8 key, u8 chan);
ALSoundFull *__lookupSoundQuick(ALCSPlayerFull *seqp, u8 key, u8 vel, u8 chan);
void __unmapVoice(ALCSPlayerFull *seqp, ALVoice *voice);
void __seqpStopOsc(ALCSPlayerFull *seqp, ALVoiceState *vs);
u8 __voiceNeedsNoteKillOff(ALCSPlayerFull *seqp, ALVoice *voice, s32 killTime);
void __seqpReleaseVoice(ALCSPlayerFull *seqp, ALVoice *voice, s32 deltaTime);
u8 __vsPan(ALVoiceState *vs, ALCSPlayerFull *seqp);
s16 __vsVol(ALVoiceState *vs, ALCSPlayerFull *seqp);
s32 __vsDelta(ALVoiceState *vs, s32 t);
typedef s32 (*ALOscInitFn)(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay);

/* declaration order = emission order of the deferred (inlinable) helpers */
void alCSPNew(ALCSPlayerFull *seqp, ALSeqpConfigX *c);
ALMicroTime __CSPVoiceHandler(void *node);
void __CSPHandleNextSeqEvent(ALCSPlayerFull *seqp);
void __CSPHandleMIDIMsg(ALCSPlayerFull *seqp, ALEventFull *event);
void __CSPHandleMetaMsg(ALCSPlayerFull *seqp, ALEventFull *event);
void __CSPPostNextSeqEvent(ALCSPlayerFull *seqp);
void __CSPRepostEvent(ALEventQueue *evtq, ALEventQueueItemFull *item);
void __setUsptFromTempo_2(ALCSPlayerFull *seqp, f32 tempo);

void alCSPNew(ALCSPlayerFull *seqp, ALSeqpConfigX *c) {
    ALHeap *hp = c->heap;
    ALVoiceState *vs;
    ALVoiceState *voices;
    s32 i;
    seqp->chanMask = 0xFF;
    seqp->uspt = 488;
    seqp->vol = 0x7FFF;
    seqp->bank = 0;
    seqp->target = 0;
    seqp->nextDelta = 0;
    seqp->state = 0;
    seqp->frameTime = 16000;
    seqp->curTime = 0;
    seqp->drvr = alGlobalsp;
    seqp->initOsc = c->initOsc;
    seqp->updateOsc = c->updateOsc;
    seqp->stopOsc = c->stopOsc;
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
    seqp->node.handler = __CSPVoiceHandler;
    seqp->node.clientData = seqp;
    alSynAddPlayer(alGlobalsp, (ALPlayer *)seqp);
}

ALMicroTime __CSPVoiceHandler(void *node) {
    ALCSPlayerFull *seqp = (ALCSPlayerFull *)node;
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
            __CSPHandleNextSeqEvent(seqp);
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
            vs->envEndTime = seqp->curTime + delta;
            vs->envGain = seqp->nextEvent.msg.env.gain;
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
        case 0x15:
            __CSPHandleMIDIMsg(seqp, &seqp->nextEvent);
            break;
        case 7:
            __CSPHandleMetaMsg(seqp, &seqp->nextEvent);
            break;
        case 0xA:
            seqp->vol = seqp->nextEvent.msg.spvol.vol;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp), __vsDelta(vs, seqp->curTime));
            }
            break;
        case 0xF:
            if (seqp->state != 1) {
                seqp->state = 1;
                __CSPPostNextSeqEvent(seqp);
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
                seqp->state = 0;
            }
            break;
        case 0x11:
            if (seqp->state == 1) {
                alEvtqFlushType(&seqp->evtq, 0);
                alEvtqFlushType(&seqp->evtq, 0x15);
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
        case 0xC:
            seqp->chanState[seqp->nextEvent.msg.prio.chan].priority = seqp->nextEvent.msg.prio.priority;
            break;
        case 0xD:
            if (seqp->state == 1) {
                __assert("EX", "audio/csplayer.c", 0x127);
            }
            seqp->target = seqp->nextEvent.msg.spseq.seq;
            __setUsptFromTempo_2(seqp, 500000.0f);
            if (seqp->bank != 0) {
                __initFromBank(seqp, seqp->bank);
            }
            break;
        case 0xE:
            if (seqp->state != 0) {
                __assert("EX", "audio/csplayer.c", 0x130);
            }
            __initFromBank(seqp, seqp->bank = seqp->nextEvent.msg.spbank.bank);
            break;
        case 1:
        case 3:
        case 4:
            __assert("EX", "audio/csplayer.c", 0x13A);
            break;
        default:
            break;
        }
        seqp->nextDelta = alEvtqNextEvent(&seqp->evtq, &seqp->nextEvent);
    } while (seqp->nextDelta == 0);
    seqp->curTime += seqp->nextDelta;
    return seqp->nextDelta;
}

void __CSPPostNextSeqEvent(ALCSPlayerFull *seqp) {
    ALEventFull evt;
    s32 deltaTicks;
    if (seqp->state != 1) {
        return;
    }
    if (seqp->target == 0) {
        return;
    }
    if (__alCSeqNextDelta(seqp->target, &deltaTicks)) {
        evt.type = 0;
        alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);
    }
}

void __CSPHandleNextSeqEvent(ALCSPlayerFull *seqp) {
    ALEventFull evt;
    if (seqp->target == 0) {
        return;
    }
    alCSeqNextEvent(seqp->target, &evt);
    switch (evt.type) {
    case 1:
        __CSPHandleMIDIMsg(seqp, &evt);
        __CSPPostNextSeqEvent(seqp);
        break;
    case 3:
        __CSPHandleMetaMsg(seqp, &evt);
        __CSPPostNextSeqEvent(seqp);
        break;
    case 4:
        seqp->state = 2;
        evt.type = 0x10;
        alEvtqPostEvent(&seqp->evtq, &evt, 0x7FFFFFFF);
        break;
    case 0x12:
    case 0x13:
    case 0x14:
        __CSPPostNextSeqEvent(seqp);
        break;
    default:
        __assert("EX", "audio/csplayer.c", 0x190);
        break;
    }
}

void __CSPHandleMIDIMsg(ALCSPlayerFull *seqp, ALEventFull *event) {
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
                        alEvtqPostEvent(&seqp->evtq, &evt, delta);
                        if (midi->duration != 0) {
                            evt.type = 0x15;
                            evt.msg.midi.status = chan | 0x80;
                            evt.msg.midi.byte1 = key;
                            evt.msg.midi.byte2 = 0;
                            alEvtqPostEvent(&seqp->evtq, &evt, seqp->uspt * midi->duration);
                        }
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
                    delta = __vsDelta(vs, seqp->curTime);
                    alSynSetVol(seqp->drvr, &vs->voice, vol, delta);
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
            break;
        default:
            break;
        }
        break;
    case 0xC0:
        if (seqp->bank == 0) {
            __assert("EX", "audio/csplayer.c", 0x2C7);
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

void __CSPHandleMetaMsg(ALCSPlayerFull *seqp, ALEventFull *event) {
    ALEventFull evt;
    s32 tmp;
    s32 tempo;
    s32 oldUspt;
    ALEventQueueItemFull *thisItem;
    ALEventQueueItemFull *nextItem;
    s32 curDelta = 0;
    ALEventQueueItemFull *firstItem = 0;
    if (event->msg.tempo.status == 0xFF) {
        if (event->msg.tempo.type == 0x51) {
            tempo = (event->msg.tempo.byte1 << 16) | (event->msg.tempo.byte2 << 8) | event->msg.tempo.byte3;
            oldUspt = seqp->uspt;
            __setUsptFromTempo_2(seqp, (f32)tempo);
            thisItem = (ALEventQueueItemFull *)seqp->evtq.allocList.next;
            while (thisItem != 0) {
                nextItem = (ALEventQueueItemFull *)thisItem->node.next;
                curDelta += thisItem->delta;
                if (thisItem->evt.type == 0x15) {
                    alUnlink(&thisItem->node);
                    if (firstItem != 0) {
                        alLink(&thisItem->node, &firstItem->node);
                    } else {
                        firstItem = thisItem;
                        thisItem->node.next = 0;
                        thisItem->node.prev = 0;
                    }
                    tmp = curDelta;
                    if (nextItem != 0) {
                        curDelta -= thisItem->delta;
                        nextItem->delta += thisItem->delta;
                    }
                    thisItem->delta = tmp;
                }
                thisItem = nextItem;
            }
            thisItem = firstItem;
            while (thisItem != 0) {
                thisItem->delta = (thisItem->delta / oldUspt) * seqp->uspt;
                nextItem = (ALEventQueueItemFull *)thisItem->node.next;
                __CSPRepostEvent(&seqp->evtq, thisItem);
                thisItem = nextItem;
            }
        }
    }
}

void __CSPRepostEvent(ALEventQueue *evtq, ALEventQueueItemFull *item) {
    OSIntMask mask;
    ALLink *node;
    ALLink *nextNode;
    ALEventQueueItemFull *nextItem;
    mask = osSetIntMask(1);
    for (node = &evtq->allocList; node != 0; node = node->next) {
        nextNode = node->next;
        if (nextNode == 0) {
            alLink(&item->node, node);
            break;
        }
        nextItem = (ALEventQueueItemFull *)nextNode;
        if (item->delta < nextItem->delta) {
            nextItem->delta -= item->delta;
            alLink(&item->node, node);
            break;
        }
        item->delta -= nextItem->delta;
    }
    osSetIntMask(mask);
}

void __setUsptFromTempo_2(ALCSPlayerFull *seqp, f32 tempo) {
    if (seqp->target != 0) {
        seqp->uspt = (s32)(tempo * seqp->target->qnpt);
    } else {
        seqp->uspt = 488;
    }
}
