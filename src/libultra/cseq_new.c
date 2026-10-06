#include "libaudio.h"

u32 __readVarLen(ALCSeq *seq, u32 track);
void alCSeqNew(ALCSeq *seq, u8 *ptr);

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
