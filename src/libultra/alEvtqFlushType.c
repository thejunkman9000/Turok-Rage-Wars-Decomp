#include "libaudio.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);

void alEvtqFlushType(ALEventQueue *evtq, s16 type) {
    ALLink *thisNode;
    ALLink *nextNode;
    ALEventQueueItem *thisItem;
    ALEventQueueItem *nextItem;
    OSIntMask mask;
    mask = osSetIntMask(1);
    thisNode = evtq->allocList.next;
    while (thisNode != 0) {
        nextNode = thisNode->next;
        thisItem = (ALEventQueueItem *)thisNode;
        nextItem = (ALEventQueueItem *)nextNode;
        if (thisItem->evt.type == type) {
            if (nextItem != 0) {
                nextItem->delta += thisItem->delta;
            }
            alUnlink(thisNode);
            alLink(thisNode, &evtq->freeList);
        }
        thisNode = nextNode;
    }
    osSetIntMask(mask);
}
