#include "libaudio.h"

void alSeqGetLoc(ALSeq *seq, ALSeqMarker *m) {
    m->curPtr = seq->curPtr;
    m->lastStatus = seq->lastStatus;
    m->lastTicks = seq->lastTicks;
}
