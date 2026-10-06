#include "libaudio.h"

s32 alSeqGetTicks(ALSeq *seq) {
    return seq->lastTicks;
}
