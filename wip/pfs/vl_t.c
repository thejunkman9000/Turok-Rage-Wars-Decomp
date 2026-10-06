#include "libaudio.h"

s32 __alSeqReadVarLen(ALSeq *seq) {
    @@decl@@
    @@a@@
    if (value & 0x80) {
        value &= 0x7F;
        do {
            @@b@@
        } while (c & 0x80);
    }
    return value;
}
