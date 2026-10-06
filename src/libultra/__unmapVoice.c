#include "libaudio.h"

void __unmapVoice(ALSeqPlayer *seqp, ALVoice *voice) {
    ALVoiceState *prev = 0;
    ALVoiceState *vs;
    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if (&vs->voice == voice) {
            if (prev != 0) {
                prev->next = vs->next;
            } else {
                seqp->vAllocHead = vs->next;
            }
            if (vs == seqp->vAllocTail) {
                seqp->vAllocTail = prev;
            }
            vs->next = seqp->vFreeList;
            seqp->vFreeList = vs;
            return;
        }
        prev = vs;
    }
}
