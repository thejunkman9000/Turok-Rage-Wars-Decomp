#include "libaudio.h"

void alCSeqSetLoc(ALCSeq *seq, ALCSeqMarker *m);
void alCSeqGetLoc(ALCSeq *seq, ALCSeqMarker *m);
s32 __alCSeqNextDelta(ALCSeq *seq, u32 *pDeltaTicks);
u32 __readVarLen(ALCSeq *seq, u32 track);
u8 __getTrackByte(ALCSeq *seq, u32 track);

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
