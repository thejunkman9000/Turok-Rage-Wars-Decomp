#include "s1012_types.h"

/* reverb.c alFxNew: set up the reverb filter from the parameter table of the configured effect (fxType 1..6, 6 = custom
   table in the config), allocate the delay line and, per section, the optional chorus resampler and low-pass filter.
   The init_lpfilter body is written out inline (the SDK -O3 build inlined the static helper).  All float/double
   constants are literals so that the object's own pool matches the ROM (jump table first, then 16384.0, 0.001f, 2^32,
   1/173123.4, 1.0f, 1/16384). */

extern s32 D_800D80B0[];
extern s32 D_800D8118[];
extern s32 D_800D81A0[];
extern s32 D_800D81C8[];
extern s32 D_800D81F0[];
extern s32 D_800D8218[];

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void *alFxPull(void);
s32 alFxParam(void *filter, s32 paramID, void *param);
s32 alFxParamHdl(void *filter, s32 paramID, void *param);

void alFxNew(ALFxFilter *r, ALSynConfigFx *c, ALHeap *hp) {
    u16 i, j, k;
    s32 *param = 0;
    ALFilter *f = &r->filter;
    ALDelayFx *d;

    alFilterNew(f, 0, alFxParam, 5);
    f->handler = (void *)alFxPull;
    r->paramHdl = alFxParamHdl;

    switch (c->fxType) {
    case 1:
        param = D_800D80B0;
        break;
    case 2:
        param = D_800D8118;
        break;
    case 5:
        param = D_800D81A0;
        break;
    case 3:
        param = D_800D81C8;
        break;
    case 4:
        param = D_800D81F0;
        break;
    case 6:
        param = c->params;
        break;
    default:
        param = D_800D8218;
        break;
    }

    j = 0;

    r->sectionCount = param[j++];
    r->length = param[j++];

    r->delay = (ALDelayFx *)alHeapDBAlloc(0, 0, hp, r->sectionCount, sizeof(ALDelayFx));
    r->base = (s16 *)alHeapDBAlloc(0, 0, hp, r->length, sizeof(s16));
    r->input = r->base;

    for (k = 0; k < r->length; k++)
        r->base[k] = 0;

    for (i = 0; i < r->sectionCount; i++) {
        d = &r->delay[i];
        d->input = param[j++];
        d->output = param[j++];
        d->fbcoef = param[j++];
        d->ffcoef = param[j++];
        d->gain = param[j++];

        if (param[j]) {
            s32 length;
            f64 flength;
            f32 rsinc;
            f32 depth;

            rsinc = (f32)param[j++] * 0.001f;
            d->rsinc = (rsinc + rsinc) / c->outputRate;

            depth = (f32)param[j++];
            length = d->output - d->input;
            flength = length;
            if (length < 0)
                flength += 4294967296.0;
            d->rsgain = depth * ((f32)flength * 0.0000057762265f);
            d->rsval = 1.0f;
            d->rsdelta = 0;
            d->rs = (ALResamplerFull *)alHeapDBAlloc(0, 0, hp, 1, sizeof(ALResamplerFull));
            d->rs->state = alHeapDBAlloc(0, 0, hp, 1, 32);
            d->rs->delta = 0;
            d->rs->first = 1;
        } else {
            d->rs = 0;
            j++;
            j++;
        }

        if (param[j]) {
            d->lp = (ALLowPassFx *)alHeapDBAlloc(0, 0, hp, 1, sizeof(ALLowPassFx));
            d->lp->fstate = (s16 *)alHeapDBAlloc(0, 0, hp, 1, 8);
            d->lp->fc = param[j++];
            {
                ALLowPassFx *lp = d->lp;
                s32 n, temp;
                s16 fc;
                f64 ffc, fcoef;

                temp = lp->fc * 16384;
                fc = temp >> 15;
                lp->fgain = 16384 - fc;

                lp->first = 1;
                for (n = 0; n < 8; n++)
                    lp->fcoef[n] = 0;

                lp->fcoef[n++] = fc;
                fcoef = ffc = (f64)fc * 0.00006103515625;

                for (; n < 16; n++) {
                    fcoef *= ffc;
                    lp->fcoef[n] = (s16)(fcoef * 16384.0);
                }
            }
        } else {
            d->lp = 0;
            j++;
        }
    }
}
