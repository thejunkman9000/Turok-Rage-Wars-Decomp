#include "synth_types.h"

void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void alEvtqNew(ALEventQueue *evtq, ALEventQueueItem *items, s32 itemCount);
void alSynAddPlayer(ALSynth *drvr, ALPlayer *client);
void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);
s32 alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt);
s32 _sndpVoiceHandler(void *node);

void alSndpNew(ALSndPlayer *sndp, ALSndpConfig *c) {
    u32 i;
    ALSndState *state;
    ALEvent evt;
    sndp->maxSounds = c->maxSounds;
    sndp->target = -1;
    sndp->frameTime = 0x3E80;
    state = alHeapDBAlloc(0, 0, c->heap, 1, c->maxSounds * sizeof(ALSndState));
    sndp->sndState = (ALSoundState *)state;
    for (i = 0; i < c->maxSounds; i++) {
        state->sound = 0;
        state++;
    }
    alEvtqNew(&sndp->evtq, alHeapDBAlloc(0, 0, c->heap, 1, c->maxEvents * sizeof(ALEventQueueItem)), c->maxEvents);
    sndp->node.next = 0;
    sndp->node.clientData = sndp;
    sndp->drvr = alGlobalsp;
    sndp->node.handler = _sndpVoiceHandler;
    alSynAddPlayer(sndp->drvr, &sndp->node);
    evt.type = AL_SNDP_API_EVT;
    alEvtqPostEvent(&sndp->evtq, &evt, sndp->frameTime);
    sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
}
