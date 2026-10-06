#include "libaudio.h"

s32 __alSeqReadVarLen(ALSeq *seq) {
    s32 value;
    u32 c;
    c = *seq->curPtr++;
    value = c;
    if (value & 0x80) {
        value &= 0x7F;
        do {
            c = *seq->curPtr++;
            value = (value << 7) + (c & 0x7F);
        } while (c & 0x80);
    }
    return value;
}
