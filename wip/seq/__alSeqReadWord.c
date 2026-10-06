#include "libaudio.h"

s32 __alSeqReadWord(ALSeq *seq) {
    s32 v;
    v = *seq->curPtr++ << 24;
    v |= *seq->curPtr++ << 16;
    v |= *seq->curPtr++ << 8;
    v |= *seq->curPtr++;
    return v;
}
