#include "synth_types.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);

void _removeEvents(ALEventQueue *evtq, ALSndState *state) {
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
        if (thisItem->evt.msg.sndp.state == (ALSoundState *)state) {
            if (nextNode != 0) {
                nextItem->delta += thisItem->delta;
            }
            alUnlink(thisNode);
            alLink(thisNode, &evtq->freeList);
        }
        thisNode = nextNode;
    }
    osSetIntMask(mask);
}
