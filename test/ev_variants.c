#include "common.h"

typedef s32 OSEvent;
typedef struct { OSMesgQueue *messageQueue; OSMesg message; } __OSEventState;
extern __OSEventState __osEventStateTab[];

/* A: index through the array */
void evA(OSEvent e, OSMesgQueue *mq, OSMesg m) {
    register u32 saveMask;
    __OSEventState *es;
    saveMask = __osDisableInt();
    es = &__osEventStateTab[e];
    es->messageQueue = mq;
    es->message = m;
    __osRestoreInt(saveMask);
}

/* B: pointer arithmetic from the base, before disabling interrupts */
void evB(OSEvent e, OSMesgQueue *mq, OSMesg m) {
    register u32 saveMask;
    __OSEventState *es = __osEventStateTab;
    saveMask = __osDisableInt();
    es += e;
    es->messageQueue = mq;
    es->message = m;
    __osRestoreInt(saveMask);
}

/* C: direct element writes */
void evC(OSEvent e, OSMesgQueue *mq, OSMesg m) {
    register u32 saveMask;
    saveMask = __osDisableInt();
    __osEventStateTab[e].messageQueue = mq;
    __osEventStateTab[e].message = m;
    __osRestoreInt(saveMask);
}
