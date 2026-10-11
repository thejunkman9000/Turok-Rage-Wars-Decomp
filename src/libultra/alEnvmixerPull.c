#include "s1012_types.h"

#define assert_ln(EX, ln) ((EX) ? ((void)0) : __assert("EX", "audio/env.c", ln))

extern s16 D_800D8240[];

void __assert(const char *exp, const char *file, s32 line);
u32 osVirtualToPhysical(void *);
void _freePVoice(ALSynth *drvr, ALPVoice *pvoice);
void __freeParam(ALParam *param);

void *_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);
f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel);
s16 _getRate(f64 vol, f64 tgt, s32 count, u16 *ratel);

/* env.c alEnvmixerPull: apply the pending parameter updates (control list) at their sample offsets, pulling the source in
   sub-frames in between.  ctrlList->type: 0 free voice, 11 volume, 12 pan, 13 start voice, 14 set wave table, 15 reset,
   16 fx mix; any other id is passed down to the source.

   Source shape notes (needed for the exact match):
   - `one` / `eq` are set at the top of the loop only so that loop.c hoists them in the ROM order (li 1 first, then la eq);
   - the type 0 arm copies &alGlobals->drvr into a local first (makes it a 3 quantity block for local-alloc, see FINDINGS 6);
   - HACK: `register ALParam *pp asm("$2")` in the type 11 arm (ROM keeps the pointer in v0, the loaded value in v1). */
void *alEnvmixerPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALEnvMixerFull *e = (ALEnvMixerFull *)filter;
    s16 inp;
    s16 loutp;
    s32 delta;
    s32 cur = sampleOffset;
    s32 old;
    ALParam *tmp;
    s16 *eq;
    s32 one;
    loutp = 0;
    inp = 0;
    if (e->ctrlList != 0) {
        while (e->ctrlList != 0) {
            one = 1;
            eq = D_800D8240;
            old = cur;
            cur = e->ctrlList->delta;
            delta = cur - old;
            if (delta > outCount) break;
            assert_ln(delta >= 0, 0x67);
            assert_ln(delta <= 0xA0, 0x68);
            switch (e->ctrlList->type) {
            case 13: {
                ALParam *s1 = e->ctrlList;
                ALFilter *f = (ALFilter *)e;
                if (s1->moredata) {
                    (*f->setParam)(f, 8, 0);
                }
                (*f->setParam)(f, 5, s1->wave);
                (*f->setParam)(f, 9, 0);
                e->first = one;
                e->delta = 0;
                e->segEnd = s1->samples;
                e->volume = (s1->d2.v.vol * s1->d2.v.vol) >> 15;
                e->pan = s1->d2.v.pan;
                e->dryamt = eq[s1->d2.v.fxmix];
                e->wetamt = eq[0x7F - s1->d2.v.fxmix];
                if (s1->samples != 0) {
                    e->cvolL = one;
                    e->cvolR = one;
                } else {
                    e->cvolL = (e->volume * eq[e->pan]) >> 15;
                    e->cvolR = (e->volume * eq[0x7F - e->pan]) >> 15;
                }
                if (f->source) {
                    (*f->source->setParam)(f->source, 7, s1->data.p);
                }
                break; }
            case 11:
            case 12:
            case 16:
                ptr = _pullSubFrame(e, &inp, &loutp, delta, sampleOffset, ptr);
                if (e->delta >= e->segEnd) {
                    e->ltgt = (e->volume * eq[e->pan]) >> 15;
                    e->rtgt = (e->volume * eq[0x7F - e->pan]) >> 15;
                    e->cvolL = e->ltgt;
                    e->cvolR = e->rtgt;
                    e->delta = e->segEnd;
                } else {
                    e->cvolL = _getVol((f32)e->cvolL, e->delta, e->lratm, e->lratl);
                    e->cvolR = _getVol((f32)e->cvolR, e->delta, e->rratm, e->rratl);
                }
                if (e->cvolL == 0) e->cvolL = one;
                if (e->cvolR == 0) e->cvolR = one;
                if (e->ctrlList->type == 12) {
                    e->pan = e->ctrlList->data.i;
                }
                if (e->ctrlList->type == 11) {
                    register ALParam *pp __asm__("$2");
                    e->delta = 0;
                    pp = e->ctrlList;
                    e->volume = (pp->data.i * pp->data.i) >> 15;
                    e->segEnd = pp->d2.i;
                }
                if (e->ctrlList->type == 16) {
                    e->dryamt = eq[e->ctrlList->data.i];
                    e->wetamt = eq[0x7F - e->ctrlList->data.i];
                }
                e->first = one;
                break;
            case 14: {
                ALParam *s1 = e->ctrlList;
                if (s1->moredata) {
                    (*e->filter.setParam)(e, 8, 0);
                }
                (*e->filter.setParam)(e, 5, s1->data.p);
                (*e->filter.setParam)(e, 9, 0);
                break; }
            case 15:
                ptr = _pullSubFrame(e, &inp, &loutp, delta, sampleOffset, ptr);
                (*e->filter.setParam)(e, 4, 0);
                break;
            case 0: {
                ALSynth *drvr = &alGlobalsp->drvr;
                ALParam *pp = e->ctrlList;
                ((ALPVoice *)pp->data.p)->offset = 0;
                _freePVoice(drvr, (ALPVoice *)pp->data.p);
                break; }
            default:
                ptr = _pullSubFrame(e, &inp, &loutp, delta, sampleOffset, ptr);
                (*e->filter.setParam)(e, e->ctrlList->type, e->ctrlList->data.p);
                break;
            }
            outCount -= delta;
            loutp += delta << 1;
            tmp = e->ctrlList;
            e->ctrlList = tmp->next;
            if (e->ctrlList == 0) {
                e->ctrlTail = 0;
            }
            __freeParam(tmp);
        }
    }
    ptr = _pullSubFrame(e, &inp, &loutp, outCount, sampleOffset, ptr);
    if (e->delta > e->segEnd) {
        e->delta = e->segEnd;
    }
    return ptr;
}

void *_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALEnvMixerFull *e = (ALEnvMixerFull *)filter;
    ALFilter *source = e->filter.source;

    if (e->motion != 1 || !outCount)
        return ptr;

    assert_ln(source, 366);

    ptr = (*source->handler)(source, inp, outCount, sampleOffset, p);

    aSetBuffer(ptr++, 0x00, *inp, 1088 + *outp, outCount << 1);
    aSetBuffer(ptr++, 0x08, 1408 + *outp, 1728 + *outp, 2048 + *outp);

    if (e->first) {
        e->first = 0;

        e->ltgt = (e->volume * D_800D8240[e->pan]) >> 15;
        e->lratm = _getRate((f64)e->cvolL, (f64)e->ltgt, e->segEnd, &(e->lratl));
        e->rtgt = (e->volume * D_800D8240[128 - e->pan - 1]) >> 15;
        e->rratm = _getRate((f64)e->cvolR, (f64)e->rtgt, e->segEnd, &(e->rratl));

        aSetVol(ptr++, 0x02 | 0x04, e->cvolL, 0, 0);
        aSetVol(ptr++, 0x00 | 0x04, e->cvolR, 0, 0);
        aSetVol(ptr++, 0x02 | 0x00, e->ltgt, e->lratm, e->lratl);
        aSetVol(ptr++, 0x00 | 0x00, e->rtgt, e->rratm, e->rratl);
        aSetVol(ptr++, 0x08, e->dryamt, 0, e->wetamt);
        aEnvMixer(ptr++, 0x01 | 0x08, osVirtualToPhysical(e->state));
    } else
        aEnvMixer(ptr++, 0x00 | 0x08, osVirtualToPhysical(e->state));

    *inp += (outCount << 1);
    e->delta += outCount;

    return ptr;
}

/* env.c: per-sample ramp factor.  Finds the rate r (16.16 as mant + ratel) with vol * r^count = tgt using the
   frexp()/ldexp() decomposition, an 8 entry table of ln(mantissa) and repeated squaring.  The libm frexp is inlined
   (the SDK build used -O3), hence the loops on absvalue / *eptr. */
typedef struct {
    f64 v[8];
} LogTab;

s16 _getRate(f64 vol, f64 tgt, s32 count, u16 *ratel) {
    s16 s;
    f64 invn = 1.0f / (f32)count;
    f64 eps;
    f64 a;
    f64 fs;
    f64 mant;
    s32 i_invn;
    s32 ex;
    s32 indx;
    if (count == 0) {
        if (tgt >= vol) {
            *ratel = 0xFFFF;
            return 0x7FFF;
        } else {
            *ratel = 0;
            return 0;
        }
    }
    if (tgt < 1.0) {
        tgt = 1.0;
    }
    if (vol <= 0.0) {
        vol = 1.0;
    }
    {
        LogTab logtab = { { -0.91253697872161865, -0.75207197666168213, -0.60768300294876099, -0.47643798589706421, -0.3561440110206604, -0.24511200189590454, -0.14201900362968445, -0.04580400139093399 } };
        f64 absvalue;
        s32 *eptr;
        i_invn = (s32)(invn * 1073741824.0);
        tgt = tgt / vol;
        eptr = &ex;
        *eptr = 0;
        if (tgt == 0.0) {
            vol = tgt;
        } else {
            absvalue = __builtin_fabs(tgt);
            if (absvalue >= 1.0) {
                do {
                    absvalue *= 0.5;
                    ++(*eptr);
                } while (absvalue >= 1.0);
            }
            if (absvalue < 0.5) {
                do {
                    absvalue += absvalue;
                    --(*eptr);
                } while (absvalue < 0.5);
            }
            vol = absvalue;
            if (!(tgt > 0.0)) {
                vol = -vol;
            }
        }
        indx = (s32)(vol * 16.0);
        absvalue = 0.69314718246459961;
        eps = (logtab.v[indx - 8] + ex) * absvalue;
        mant = 1073741824.0;
        eps /= mant;
        fs = eps + 1.0;
        a = 1.0;
        while (i_invn) {
            if (i_invn & 1) {
                a = a * fs;
            }
            fs *= fs;
            i_invn >>= 1;
        }
    }
    /* the redundant test of vol (identical arms, cross-jumped away by jump2) keeps vol alive until here; without it
       the sign flip above comes out as neg.d $f12,$f1 instead of neg.d $f12,$f12 */
    if (vol) {
        a *= a;
        a *= a;
        a *= a;
        s = (s16)a;
        *ratel = (s16)((a - ((f32)s)) * 65535.0);
        return (s16)a;
    } else {
        a *= a;
        a *= a;
        a *= a;
        s = (s16)a;
        *ratel = (s16)((a - ((f32)s)) * 65535.0);
        return (s16)a;
    }
}

/* env.c: filter parameter handler of the envelope mixer.  Ids: 1 = set source, 3 = add update (control list),
   4 = reset, 9 = start; everything else is passed down to the source filter. */

s32 alEnvmixerParam(void *filter, s32 paramID, void *param) {
    ALFilter *f = (ALFilter *)filter;
    ALEnvMixerFull *e = (ALEnvMixerFull *)filter;

    switch (paramID) {
    case 3:
        if (e->ctrlTail) {
            e->ctrlTail->next = (ALParam *)param;
        } else {
            e->ctrlList = (ALParam *)param;
        }
        e->ctrlTail = (ALParam *)param;
        break;
    case 4:
        e->first = 1;
        e->motion = 0;
        e->volume = 1;
        if (f->source)
            (*f->source->setParam)(f->source, 4, param);
        break;
    case 9:
        e->motion = 1;
        if (f->source)
            (*f->source->setParam)(f->source, 9, param);
        break;
    case 1:
        f->source = (ALFilter *)param;
        break;
    default:
        if (f->source)
            (*f->source->setParam)(f->source, paramID, param);
    }
    return 0;
}

/* env.c: volume after `samples` samples at the per-8-sample rate ratem.ratel (16.16), by repeated squaring. */

f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel) {
    f32 base;
    f32 result;
    s32 n;
    s32 i;

    n = samples >> 3;
    i = 0;
    if (n == 0) {
        return ivol;
    }

    base = (f32)(ratem << 16);
    base += (f32)(ratel & 0xFFFF);
    base *= 0.0000152587890625f;
    result = 1.0f;
    do {
        if (n & 1) {
            result *= base;
        }
        n >>= 1;
        i++;
        if (n == 0) {
            break;
        }
        base *= base;
    } while (i < 0x20);

    return ivol * result;
}
