#include "s1013_types.h"

/* alResamplePull (libaudio resample.c): at unity pitch pull the source and move its output; otherwise clip and
   quantise the pitch ratio, pull the input sample count it needs and append a resample command. */
Acmd *alResamplePull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    S13Resampler *f = (S13Resampler *)filter;
    Acmd *ptr = p;
    s16 inp;
    s32 inCount;
    ALFilter *source = f->filter.source;
    s32 incr;
    f32 finCount;
    f32 ratio;
    f32 unity;

    inp = 320; /* AL_DECODER_OUT */

    if (!outCount)
        return ptr;

    if (f->upitch) {
        ptr = (*source->handler)(source, &inp, outCount, sampleOffset, p);
        aDMEMMove(ptr++, inp, *outp, outCount << 1);
    } else {
        if (f->ratio > 1.99996f)
            f->ratio = 1.99996f;

        ratio = f->ratio;
        unity = 32768.0f;
        f->ratio = (f32)(s32)(ratio * unity) * 0.000030517578125f;

        finCount = f->delta + (f->ratio * (f32)outCount);
        inCount = (s32)finCount;
        f->delta = finCount - (f32)inCount;

        ptr = (*source->handler)(source, &inp, inCount, sampleOffset, p);

        incr = (s32)(f->ratio * unity);
        aSetBuffer(ptr++, 0, inp, *outp, outCount << 1);
        aResample(ptr++, f->first, incr, osVirtualToPhysical(f->state));
        f->first = 0;
    }

    return ptr;
}
