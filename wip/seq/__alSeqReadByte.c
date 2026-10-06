#include "libaudio.h"

u8 __alSeqReadByte(ALSeq *seq) {
    return *seq->curPtr++;
}
