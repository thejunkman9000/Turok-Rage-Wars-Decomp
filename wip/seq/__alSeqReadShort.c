#include "libaudio.h"

s16 __alSeqReadShort(ALSeq *seq) {
    s32 v;
    v = *seq->curPtr++;
    v = v << 8;
    v |= *seq->curPtr++;
    return v;
}
