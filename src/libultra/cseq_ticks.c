#include "libaudio.h"

u32 alCSeqGetTicks(ALCSeq *seq);
f32 alCSeqTicksToSec(ALCSeq *seq, s32 ticks, u32 tempo);
u32 alCSeqSecToTicks(ALCSeq *seq, f32 sec, u32 tempo);

u32 alCSeqGetTicks(ALCSeq *seq) {
    return seq->lastTicks;
}

f32 alCSeqTicksToSec(ALCSeq *seq, s32 ticks, u32 tempo) {
    return ((f32)ticks * (f32)tempo) / ((f32)seq->base->division * 1000000.0f);
}

u32 alCSeqSecToTicks(ALCSeq *seq, f32 sec, u32 tempo) {
    return (u32)((sec * ((f32)seq->base->division * 1000000.0f)) / (f32)tempo);
}
