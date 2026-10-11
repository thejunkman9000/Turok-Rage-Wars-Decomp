#include "s1012_types.h"

/* libaudio synthesizer, bus filter handler (this is the SDK's alAuxBusPull; the repo names of the two buses are swapped):
   clear the aux left/right output buffers (DMEM 0x6C0 / 0x800) and pull every source filter of the bus. */

void *alMainBusPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALBus *m = (ALBus *)filter;
    ALFilter **sources = m->sources;
    s32 i;

    aClearBuffer(ptr++, 0x6C0, outCount << 1);
    aClearBuffer(ptr++, 0x800, outCount << 1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = sources[i]->handler(sources[i], outp, outCount, sampleOffset, ptr);
    }
    return ptr;
}
