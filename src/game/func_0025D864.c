#include "b13_types.h"
#include "libaudio.h"

typedef struct SeqpCfg {
    s32 maxVoices;
    s32 maxEvents;
    u8 maxChannels;
    u8 pad9[3];
    ALHeap *heap;
    void *initOsc;
    void *updateOsc;
    void *stopOsc;
} SeqpCfg;

extern f32 D_800C90E8;
extern f32 D_800C90EC;

void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void alCSPNew(void *csp, SeqpCfg *cfg);

void func_0025D864(SndSeq *s, SndMgr *m) {
    SeqpCfg cfg;
    s->owner = m;
    s->unk18 = 0x10;
    s->unk28 = -1;
    s->unk1C = 0;
    cfg.maxVoices = 0x14;
    cfg.maxEvents = 0xC0;
    cfg.maxChannels = 0x14;
    cfg.heap = (ALHeap *)s->owner->heap;
    cfg.initOsc = 0;
    cfg.updateOsc = 0;
    cfg.stopOsc = 0;
    s->csp = alHeapDBAlloc(0, 0, (ALHeap *)s->owner->heap, 1, 0x7C);
    alCSPNew(s->csp, &cfg);
    s->unk10 = alHeapDBAlloc(0, 0, (ALHeap *)s->owner->heap, 1, 0xF8);
    s->unk24 = 0x32;
    s->unk38 = 0;
    s->unk30 = D_800C90E8;
    s->unk34 = D_800C90EC;
    s->unk3C = D_800C90E8;
    s->unk40.f = D_800C90E8;
}
