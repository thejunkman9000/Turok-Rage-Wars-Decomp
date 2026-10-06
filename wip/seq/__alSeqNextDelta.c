#include "libaudio.h"

s32 __alSeqReadVarLen(ALSeq *seq);

s32 __alSeqNextDelta(ALSeq *seq, s32 *pDeltaTicks) {
    u8 *tmp = seq->curPtr;
    if (tmp >= seq->base + seq->len) {
        return 0;
    }
    *pDeltaTicks = __alSeqReadVarLen(seq);
    seq->curPtr = tmp;
    return 1;
}
