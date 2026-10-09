#include "seqp_types.h"

/* compact sequence object (cseq.c): functions in ROM order */
u8 __alCSeqGetTrackEvent(ALCSeq *seq, u32 track, ALEventFull *event);
void alCSeqNewMarker(ALCSeq *seq, ALCSeqMarker *m, u32 ticks);
u8 __getTrackByte(ALCSeq *seq, u32 track);
void alCSeqNew(ALCSeq *seq, u8 *ptr);
s32 alCSeqNextEvent(ALCSeq *seq, ALEventFull *event);
u32 alCSeqGetTicks(ALCSeq *seq);
f32 alCSeqTicksToSec(ALCSeq *seq, s32 ticks, u32 tempo);
u32 alCSeqSecToTicks(ALCSeq *seq, f32 sec, u32 tempo);
void alCSeqSetLoc(ALCSeq *seq, ALCSeqMarker *m);
void alCSeqGetLoc(ALCSeq *seq, ALCSeqMarker *m);
s32 __alCSeqNextDelta(ALCSeq *seq, u32 *pDeltaTicks);
u32 __readVarLen(ALCSeq *seq, u32 track);

/* helpers inlined into alCSeqNewMarker: defined first */
void alCSeqNew(ALCSeq *seq, u8 *ptr) {
    u32 i;
    u32 tmpOff;

    seq->base = (ALCSeqFile *)ptr;
    seq->validTracks = 0;
    seq->lastDeltaTicks = 0;
    seq->lastTicks = 0;
    seq->deltaFlag = 1;

    for (i = 0; i < 16; i++) {
        seq->lastStatus[i] = 0;
        seq->curBUPtr[i] = 0;
        seq->curBULen[i] = 0;
        tmpOff = seq->base->trackOffset[i];
        if (tmpOff) {
            seq->validTracks |= (1 << i);
            seq->curLoc[i] = ptr + tmpOff;
            seq->evtDeltaTicks[i] = __readVarLen(seq, i);
        } else {
            seq->curLoc[i] = 0;
        }
    }

    seq->qnpt = 1.0f / (f32)seq->base->division;
}

void alCSeqGetLoc(ALCSeq *seq, ALCSeqMarker *m) {
    s32 i;

    m->validTracks = seq->validTracks;
    m->lastTicks = seq->lastTicks;
    m->lastDeltaTicks = seq->lastDeltaTicks;

    for (i = 0; i < 16; i++) {
        m->curLoc[i] = seq->curLoc[i];
        m->curBUPtr[i] = seq->curBUPtr[i];
        m->curBULen[i] = seq->curBULen[i];
        m->lastStatus[i] = seq->lastStatus[i];
        m->evtDeltaTicks[i] = seq->evtDeltaTicks[i];
    }
}

inline s32 alCSeqNextEvent(ALCSeq *seq, ALEventFull *event) {
    u32 i;
    u32 firstTime = 0xFFFFFFFF;
    u32 firstTrack;
    u32 lastDelta = seq->lastDeltaTicks;

    for (i = 0; i < 16; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag) {
                seq->evtDeltaTicks[i] -= lastDelta;
            }
            if (seq->evtDeltaTicks[i] < firstTime) {
                firstTime = seq->evtDeltaTicks[i];
                firstTrack = i;
            }
        }
    }

    __alCSeqGetTrackEvent(seq, firstTrack, event);

    event->msg.midi.ticks = firstTime;
    seq->lastDeltaTicks = firstTime;
    seq->lastTicks += firstTime;

    if (event->type != AL_SEQ_END_EVT) {
        seq->evtDeltaTicks[firstTrack] += __readVarLen(seq, firstTrack);
    }

    seq->deltaFlag = 1;
    return 1;
}

u8 __alCSeqGetTrackEvent(ALCSeq *seq, u32 track, ALEventFull *event) {
    u8 status;
    u8 type;
    u8 *tmpPtr;
    u8 loopCt;
    u8 curLpCt;
    u32 offset;
    status = __getTrackByte(seq, track);
    if (status == 0xFF) {
        type = __getTrackByte(seq, track);
        if (type == 0x51) {
            event->type = 3;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.byte1 = __getTrackByte(seq, track);
            event->msg.tempo.byte2 = __getTrackByte(seq, track);
            event->msg.tempo.byte3 = __getTrackByte(seq, track);
            seq->lastStatus[track] = 0;
        } else if (type == 0x2F) {
            seq->validTracks ^= (1 << track);
            if (seq->validTracks != 0) {
                event->type = 0x12;
            } else {
                event->type = 4;
            }
        } else if (type == 0x2E) {
            loopCt = __getTrackByte(seq, track);
            curLpCt = __getTrackByte(seq, track);
            seq->lastStatus[track] = 0;
            event->type = 0x13;
        } else if (type == 0x2D) {
            tmpPtr = seq->curLoc[track];
            loopCt = *tmpPtr++;
            curLpCt = *tmpPtr;
            if (curLpCt == 0) {
                *tmpPtr = loopCt;
                seq->curLoc[track] = tmpPtr + 5;
            } else {
                if (curLpCt != 0xFF) {
                    *tmpPtr = curLpCt - 1;
                }
                tmpPtr++;
                offset = *tmpPtr++ << 24;
                offset += *tmpPtr++ << 16;
                offset += *tmpPtr++ << 8;
                offset += *tmpPtr++;
                seq->curLoc[track] = tmpPtr - offset;
            }
            seq->lastStatus[track] = 0;
            event->type = 0x14;
        }
    } else {
        event->type = 1;
        if (status & 0x80) {
            event->msg.midi.status = status;
            event->msg.midi.byte1 = __getTrackByte(seq, track);
            seq->lastStatus[track] = status;
        } else {
            event->msg.midi.status = seq->lastStatus[track];
            event->msg.midi.byte1 = status;
        }
        if ((event->msg.midi.status & 0xF0) != 0xC0 && (event->msg.midi.status & 0xF0) != 0xD0) {
            event->msg.midi.byte2 = __getTrackByte(seq, track);
            if ((event->msg.midi.status & 0xF0) == 0x90) {
                event->msg.midi.duration = __readVarLen(seq, track);
            }
        } else {
            event->msg.midi.byte2 = 0;
        }
    }
    return 1;
}

void alCSeqNewMarker(ALCSeq *seq, ALCSeqMarker *m, u32 ticks) {
    ALEventFull evt;
    ALCSeq tempSeq;
    alCSeqNew(&tempSeq, (u8 *)seq->base);
    do {
        alCSeqGetLoc(&tempSeq, m);
        alCSeqNextEvent(&tempSeq, &evt);
    } while (evt.type != AL_TRACK_END && tempSeq.lastTicks < ticks);
}

u8 __getTrackByte(ALCSeq *seq, u32 track) {
    u8 theByte;
    u8 loByte;
    u8 hiByte;
    u8 len;
    s32 backup;
    u8 *p;
    if (seq->curBULen[track]) {
        theByte = *seq->curBUPtr[track]++;
        seq->curBULen[track]--;
    } else {
        p = seq->curLoc[track];
        theByte = *p;
        seq->curLoc[track] = p + 1;
        if (theByte == 0xFE) {
            loByte = p[1];
            seq->curLoc[track] = p + 2;
            if (loByte != theByte) {
                hiByte = p[2];
                backup = loByte << 8;
                seq->curLoc[track] = p + 3;
                len = p[3];
                seq->curLoc[track] = p + 4;
                backup += hiByte;
                seq->curBUPtr[track] = seq->curLoc[track] - (backup + 4);
                seq->curBULen[track] = len;
                theByte = *seq->curBUPtr[track]++;
                seq->curBULen[track]--;
            }
        }
    }
    return theByte;
}




u32 alCSeqGetTicks(ALCSeq *seq) {
    return seq->lastTicks;
}

f32 alCSeqTicksToSec(ALCSeq *seq, s32 ticks, u32 tempo) {
    return ((f32)ticks * (f32)tempo) / ((f32)seq->base->division * 1000000.0f);
}

u32 alCSeqSecToTicks(ALCSeq *seq, f32 sec, u32 tempo) {
    return (u32)((sec * ((f32)seq->base->division * 1000000.0f)) / (f32)tempo);
}

void alCSeqSetLoc(ALCSeq *seq, ALCSeqMarker *m) {
    s32 i;

    seq->validTracks = m->validTracks;
    seq->lastTicks = m->lastTicks;
    seq->lastDeltaTicks = m->lastDeltaTicks;

    for (i = 0; i < 16; i++) {
        seq->curLoc[i] = m->curLoc[i];
        seq->curBUPtr[i] = m->curBUPtr[i];
        seq->curBULen[i] = m->curBULen[i];
        seq->lastStatus[i] = m->lastStatus[i];
        seq->evtDeltaTicks[i] = m->evtDeltaTicks[i];
    }
}

s32 __alCSeqNextDelta(ALCSeq *seq, u32 *pDeltaTicks) {
    u32 i;
    u32 firstTime = 0xFFFFFFFF;
    u32 lastDelta = seq->lastDeltaTicks;

    if (seq->validTracks == 0) {
        return 0;
    }

    for (i = 0; i < 16; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag) {
                seq->evtDeltaTicks[i] -= lastDelta;
            }
            if (seq->evtDeltaTicks[i] < firstTime) {
                firstTime = seq->evtDeltaTicks[i];
            }
        }
    }

    seq->deltaFlag = 0;
    *pDeltaTicks = firstTime;
    return 1;
}

u32 __readVarLen(ALCSeq *seq, u32 track) {
    u32 value;
    u32 c;

    value = __getTrackByte(seq, track);
    if (value & 0x80) {
        value &= 0x7F;
        do {
            c = __getTrackByte(seq, track);
            value = (value << 7) + (c & 0x7F);
        } while (c & 0x80);
    }
    return value;
}
