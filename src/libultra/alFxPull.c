#include "s1013_types.h"

Acmd *_loadBuffer(S13Fx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p);
Acmd *_saveBuffer(S13Fx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p);
Acmd *_loadOutputBuffer(S13Fx *r, S13Delay *d, s32 buff, s32 incount, Acmd *p);
Acmd *_filterBuffer(S13LowPass *lp, s32 buff, s32 count, Acmd *p);

/* alFxPull (libaudio reverb.c): pull the effect's source, mix the aux left and right outputs into the delay line
   input, run each delay section (load, feed-forward and feedback mixes, low-pass, save, gain into the output),
   advance the delay line input modulo its length and move the result into the aux left output. */
Acmd *alFxPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    S13Fx *r = (S13Fx *)filter;
    ALFilter *source = r->filter.source;
    s16 i, buff1, buff2, input, output;
    s16 *in_ptr, *out_ptr, *prev_out_ptr = 0;
    S13Delay *d;

    if (!source)
        __assert("EX", "audio/reverb.c", 75);

    ptr = (*source->handler)(source, outp, outCount, sampleOffset, p);

    input = 1728;
    output = 2048;
    buff1 = 0;
    buff2 = 320;

    aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
    aMix(ptr++, 0, 0xda83, 1728, input);
    aMix(ptr++, 0, 0x5a82, 2048, input);
    ptr = _saveBuffer(r, r->input, input, outCount, ptr);

    aClearBuffer(ptr++, output, outCount << 1);

    for (i = 0; i < r->sectionCount; i++) {
        d = &r->delay[i];
        in_ptr = &r->input[-d->input];
        out_ptr = &r->input[-d->output];

        if (in_ptr == prev_out_ptr) {
            { s16 t = buff2; buff2 = buff1; buff1 = t; };
        } else {
            ptr = _loadBuffer(r, in_ptr, buff1, outCount, ptr);
        }
        ptr = _loadOutputBuffer(r, d, buff2, outCount, ptr);

        if (d->ffcoef) {
            aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
            if (!d->rs && !d->lp) {
                ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);
            }
        }

        if (d->fbcoef) {
            aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
            ptr = _saveBuffer(r, in_ptr, buff1, outCount, ptr);
        }

        if (d->lp)
            ptr = _filterBuffer(d->lp, buff2, outCount, ptr);

        if (!d->rs)
            ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);

        if (d->gain)
            aMix(ptr++, 0, (u16)d->gain, buff2, output);

        prev_out_ptr = &r->input[d->output];
    }

    r->input += outCount;
    if (r->input > &r->base[r->length])
        r->input -= r->length;

    aDMEMMove(ptr++, output, 1728, outCount << 1);

    return ptr;
}
