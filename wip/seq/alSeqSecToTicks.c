#include "libaudio.h"

u32 alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo) {
    return (u32)((sec * ((f32)seq->division * 1000000.0f)) / (f32)tempo);
}
