#include "libaudio.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);
void alCopy(u8 *src, u8 *dst, s32 len);

ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt) {
    ALEventQueueItem *item;
    OSIntMask mask;
    ALMicroTime delta;
    mask = osSetIntMask(1);
    item = (ALEventQueueItem *)evtq->allocList.next;
    if (item != 0) {
        alUnlink(&item->node);
        alCopy((u8 *)&item->evt, (u8 *)evt, sizeof(ALEvent));
        alLink(&item->node, &evtq->freeList);
        delta = item->delta;
    } else {
        evt->type = -1;
        delta = 0;
    }
    osSetIntMask(mask);
    return delta;
}
