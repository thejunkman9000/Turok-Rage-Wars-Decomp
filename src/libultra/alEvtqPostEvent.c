#include "libaudio.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);
void alCopy(u8 *src, u8 *dst, s32 len);

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta) {
    ALEventQueueItem *item;
    ALLink *node;
    OSIntMask mask;
    ALEventQueueItem *nextItem;
    s32 postAtEnd = 0;
    mask = osSetIntMask(1);
    item = (ALEventQueueItem *)evtq->freeList.next;
    if (item == 0) {
        osSetIntMask(mask);
        return;
    }
    alUnlink(&item->node);
    alCopy((u8 *)evt, (u8 *)&item->evt, sizeof(ALEvent));
    if (delta == 0x7FFFFFFF) {
        postAtEnd = -1;
    }
    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (node->next == 0) {
            if (postAtEnd) {
                item->delta = 0;
            } else {
                item->delta = delta;
            }
            alLink(&item->node, node);
            break;
        } else {
            nextItem = (ALEventQueueItem *)node->next;
            if (delta < nextItem->delta) {
                item->delta = delta;
                nextItem->delta -= delta;
                alLink(&item->node, node);
                break;
            }
            delta -= nextItem->delta;
        }
    }
    osSetIntMask(mask);
}
