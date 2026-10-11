#include "s1013_types.h"

void init_lpfilter(S13LowPass *lp);
f32 _doModFunc(S13Delay *d, s32 count);
Acmd *_loadBuffer(S13Fx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p);

/* alFxParamHdl (libaudio reverb.c): set one parameter of one delay section; paramID = 2 + 8 * section + field */
s32 alFxParamHdl(void *filter, s32 paramID, void *param)
{
    S13Fx *f = (S13Fx *)filter;
    s32 p = (paramID - 2) % 8;
    s32 s = (paramID - 2) / 8;
    s32 val = *(s32 *)param;

    switch (p) {
        case 0:
            f->delay[s].input = (u32)val & 0xFFFFFFF8;
            break;
        case 1:
            f->delay[s].output = (u32)val & 0xFFFFFFF8;
            break;
        case 3:
            f->delay[s].ffcoef = (s16)val;
            break;
        case 2:
            f->delay[s].fbcoef = (s16)val;
            break;
        case 4:
            f->delay[s].gain = (s16)val;
            break;
        case 5:
            f->delay[s].rsinc = (((f32)val * 0.001f) * 2.0f) / (f32)alGlobalsp->drvr.outputRate;
            break;
        case 6: {
            f32 fval = (f32)val;
            s32 length = (f->delay[s].output - f->delay[s].input);
            double flength = length;

            if (length < 0)
                flength += 4294967296.0;
            f->delay[s].rsgain = fval * ((f32)flength * 5.7762263e-06f);
            break;
        }
        case 7:
            if (f->delay[s].lp) {
                f->delay[s].lp->fc = (s16)val;
                init_lpfilter(f->delay[s].lp);
            }
            break;
    }
    return 0;
}

/* _loadOutputBuffer (libaudio reverb.c): load a delay section, optionally applying chorus modulation and resampling */
Acmd *_loadOutputBuffer(S13Fx *r, S13Delay *d, s32 buff, s32 incount, Acmd *p)
{
    Acmd *ptr = p;
    s32 ratio, count, rbuff = 640;
    s16 *out_ptr;
    f32 fincount, fratio, delta;
    s32 ramalign = 0, length;
    f32 unity;

    if (d->rs) {
        length = d->output - d->input;
        delta = _doModFunc(d, incount);
        delta /= length;
        unity = 32768.0f;
        delta = (s32)(delta * unity);
        delta = delta * 0.000030517578125f;
        fratio = 1.0f - delta;

        fincount = d->rs->delta + (fratio * (f32)incount);
        count = (s32)fincount;
        d->rs->delta = fincount - (f32)count;

        out_ptr = &r->input[-(d->output - d->rsdelta)];
        ramalign = ((s32)out_ptr & 0x7) >> 1;

        ptr = _loadBuffer(r, out_ptr - ramalign, rbuff, count + ramalign, ptr);

        ratio = (s32)(fratio * unity);
        aSetBuffer(ptr++, 0, rbuff + (ramalign << 1), buff, incount << 1);
        aResample(ptr++, d->rs->first, ratio, osVirtualToPhysical(d->rs->state));

        d->rs->first = 0;
        d->rsdelta += count - incount;
    } else {
        out_ptr = &r->input[-d->output];
        ptr = _loadBuffer(r, out_ptr, buff, incount, ptr);
    }

    return ptr;
}
