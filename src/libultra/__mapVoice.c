#include "libaudio.h"

ALVoiceState *__mapVoice(ALSeqPlayer *seqp, u8 key, u8 vel, u8 channel) {
    ALVoiceState *vs = seqp->vFreeList;
    if (vs != 0) {
        seqp->vFreeList = vs->next;
        vs->next = 0;
        if (seqp->vAllocHead == 0) {
            seqp->vAllocHead = vs;
        } else {
            seqp->vAllocTail->next = vs;
        }
        seqp->vAllocTail = vs;
        vs->channel = channel;
        vs->key = key;
        vs->velocity = vel;
        vs->voice.clientPrivate = vs;
    }
    return vs;
}
