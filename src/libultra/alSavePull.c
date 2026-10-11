#include "s1013_types.h"

/* alSavePull (libaudio save.c): pull the main bus, interleave the left and right outputs and save the result to
   the DRAM output buffer */
Acmd *alSavePull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    ALSave *f = (ALSave *)filter;
    ALFilter *source = f->filter.source;

    if (source == 0)
        __assert("EX", "audio/save.c", 34);

    ptr = (*source->handler)(source, outp, outCount, sampleOffset, ptr);

    aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
    aInterleave(ptr++, 0x440, 0x580);
    aSetBuffer(ptr++, 0, 0, 0, outCount << 2);
    aSaveBuffer(ptr++, f->dramout);

    return ptr;
}
