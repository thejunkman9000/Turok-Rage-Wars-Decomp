#include "libaudio.h"

void alLink(ALLink *ln, ALLink *to);

void alEvtqNew(ALEventQueue *evtq, ALEventQueueItem *items, s32 itemCount) {
    s32 i;
    evtq->eventCount = 0;
    evtq->allocList.next = 0;
    evtq->allocList.prev = 0;
    evtq->freeList.next = 0;
    evtq->freeList.prev = 0;
    for (i = 0; i < itemCount; i++) {
        alLink(&items[i].node, &evtq->freeList);
    }
}
