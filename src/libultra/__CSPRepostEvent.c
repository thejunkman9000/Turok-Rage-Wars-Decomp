#include "libaudio.h"

void alLink(ALLink *ln, ALLink *to);

void __CSPRepostEvent(ALEventQueue *evtq, ALEventQueueItem *item) {
    OSIntMask mask;
    ALLink *node;
    ALLink *nextNode;
    ALEventQueueItem *nextItem;
    mask = osSetIntMask(1);
    for (node = &evtq->allocList; node != 0; node = node->next) {
        nextNode = node->next;
        if (nextNode == 0) {
            alLink(&item->node, node);
            break;
        }
        nextItem = (ALEventQueueItem *)nextNode;
        if (item->delta < nextItem->delta) {
            nextItem->delta -= item->delta;
            alLink(&item->node, node);
            break;
        }
        item->delta -= nextItem->delta;
    }
    osSetIntMask(mask);
}
