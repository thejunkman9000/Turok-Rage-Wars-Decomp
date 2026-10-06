#include "libaudio.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);

void alEvtqFlush(ALEventQueue *evtq) {
    ALLink *thisNode;
    ALLink *nextNode;
    OSIntMask mask = osSetIntMask(1);
    thisNode = evtq->allocList.next;
    while (thisNode != 0) {
        nextNode = thisNode->next;
        alUnlink(thisNode);
        alLink(thisNode, &evtq->freeList);
        thisNode = nextNode;
    }
    osSetIntMask(mask);
}
