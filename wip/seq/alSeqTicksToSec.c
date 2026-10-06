#include "libaudio.h"

f32 alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo) {
    return ((f32)ticks * (f32)tempo) / ((f32)seq->division * 1000000.0f);
}
