#include "libaudio.h"

/* seq.c: plain MIDI sequence reader (functions in ROM order) */
void alSeqNextEvent(ALSeq *seq, ALEvent *event);
void alSeqNew(ALSeq *seq, u8 *ptr, s32 len);
s32 alSeqGetTicks(ALSeq *seq);
f32 alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo);
u32 alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo);
void alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks);
void alSeqSetLoc(ALSeq *seq, ALSeqMarker *m);
void alSeqGetLoc(ALSeq *seq, ALSeqMarker *m);
s32 __alSeqNextDelta(ALSeq *seq, s32 *pDeltaTicks);
s32 __alSeqReadVarLen(ALSeq *seq);
u8 __alSeqReadByte(ALSeq *seq);
s16 __alSeqReadShort(ALSeq *seq);
s32 __alSeqReadWord(ALSeq *seq);

void alSeqNextEvent(ALSeq *seq, ALEvent *event) {
    u8 status;
    u8 type;
    s32 deltaTicks;
    deltaTicks = __alSeqReadVarLen(seq);
    seq->lastTicks += deltaTicks;
    status = __alSeqReadByte(seq);
    if (status == 0xFF) {
        type = __alSeqReadByte(seq);
        if (type == 0x51) {
            event->type = AL_TEMPO_EVENT;
            event->msg.tempo.ticks = deltaTicks;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.len = __alSeqReadByte(seq);
            event->msg.tempo.byte1 = __alSeqReadByte(seq);
            event->msg.tempo.byte2 = __alSeqReadByte(seq);
            event->msg.tempo.byte3 = __alSeqReadByte(seq);
        } else if (type == 0x2F) {
            event->type = AL_TRACK_END;
            event->msg.tempo.ticks = deltaTicks;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.len = __alSeqReadByte(seq);
        }
        seq->lastStatus = 0;
    } else {
        event->type = AL_SEQ_MIDI_EVT;
        event->msg.midi.ticks = deltaTicks;
        if (status & 0x80) {
            event->msg.midi.status = status;
            event->msg.midi.byte1 = __alSeqReadByte(seq);
            seq->lastStatus = status;
        } else {
            event->msg.midi.byte1 = status;
            event->msg.midi.status = seq->lastStatus;
        }
        if ((event->msg.midi.status & 0xF0) == 0xC0 || (event->msg.midi.status & 0xF0) == 0xD0) {
            event->msg.midi.byte2 = 0;
        } else {
            event->msg.midi.byte2 = __alSeqReadByte(seq);
        }
    }
}

void alSeqNew(ALSeq *seq, u8 *ptr, s32 len) {
    seq->base = ptr;
    seq->len = len;
    seq->lastStatus = 0;
    seq->lastTicks = 0;
    seq->curPtr = ptr;
    if (__alSeqReadWord(seq) == 0x4D546864) {
        __alSeqReadWord(seq);
        if (__alSeqReadShort(seq) == 0) {
            if (__alSeqReadShort(seq) == 1) {
                seq->division = __alSeqReadShort(seq);
                if ((seq->division & 0x8000) == 0) {
                    seq->qnpt = 1.0f / (f32)seq->division;
                    if (__alSeqReadWord(seq) == 0x4D54726B) {
                        __alSeqReadWord(seq);
                        seq->trackStart = seq->curPtr;
                    }
                }
            }
        }
    }
}

s32 alSeqGetTicks(ALSeq *seq) {
    return seq->lastTicks;
}

f32 alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo) {
    return ((f32)ticks * (f32)tempo) / ((f32)seq->division * 1000000.0f);
}

u32 alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo) {
    return (u32)((sec * ((f32)seq->division * 1000000.0f)) / (f32)tempo);
}

void alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks) {
    ALEvent evt;
    u8 *ptr;
    u16 status;
    s32 lastTicks;
    u8 *savePtr;
    u16 saveStatus;
    s32 saveTicks;
    if (ticks == 0) {
        m->curPtr = seq->trackStart;
        m->lastStatus = 0;
        m->lastTicks = 0;
        m->curTicks = 0;
    } else {
        saveStatus = seq->lastStatus;
        savePtr = seq->curPtr;
        saveTicks = seq->lastTicks;
        seq->lastStatus = 0;
        seq->lastTicks = 0;
        seq->curPtr = seq->trackStart;
        do {
            ptr = seq->curPtr;
            status = seq->lastStatus;
            lastTicks = seq->lastTicks;
            alSeqNextEvent(seq, &evt);
            if (evt.type == AL_TRACK_END) {
                ptr = seq->curPtr;
                status = seq->lastStatus;
                lastTicks = seq->lastTicks;
                break;
            }
        } while (seq->lastTicks < ticks);
        m->curPtr = ptr;
        m->lastStatus = status;
        m->lastTicks = lastTicks;
        m->curTicks = seq->lastTicks;
        seq->curPtr = savePtr;
        seq->lastStatus = saveStatus;
        seq->lastTicks = saveTicks;
    }
}

void alSeqSetLoc(ALSeq *seq, ALSeqMarker *m) {
    seq->curPtr = m->curPtr;
    seq->lastStatus = m->lastStatus;
    seq->lastTicks = m->lastTicks;
}

void alSeqGetLoc(ALSeq *seq, ALSeqMarker *m) {
    m->curPtr = seq->curPtr;
    m->lastStatus = seq->lastStatus;
    m->lastTicks = seq->lastTicks;
}

s32 __alSeqNextDelta(ALSeq *seq, s32 *pDeltaTicks) {
    u8 *tmp = seq->curPtr;
    if (tmp >= seq->base + seq->len) {
        return 0;
    }
    *pDeltaTicks = __alSeqReadVarLen(seq);
    seq->curPtr = tmp;
    return 1;
}

s32 __alSeqReadVarLen(ALSeq *seq) {
    s32 value;
    u32 c;
    c = *seq->curPtr++;
    value = c;
    if (value & 0x80) {
        value &= 0x7F;
        do {
            c = *seq->curPtr++;
            value = (value << 7) + (c & 0x7F);
        } while (c & 0x80);
    }
    return value;
}

u8 __alSeqReadByte(ALSeq *seq) {
    return *seq->curPtr++;
}

s16 __alSeqReadShort(ALSeq *seq) {
    s32 v;
    v = *seq->curPtr++;
    v = v << 8;
    v |= *seq->curPtr++;
    return v;
}

s32 __alSeqReadWord(ALSeq *seq) {
    s32 v;
    v = *seq->curPtr++ << 24;
    v |= *seq->curPtr++ << 16;
    v |= *seq->curPtr++ << 8;
    v |= *seq->curPtr++;
    return v;
}
