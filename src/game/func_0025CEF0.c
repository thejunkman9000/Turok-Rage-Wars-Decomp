
#include "b13_types.h"
#include "m04_types.h"

typedef struct M04FxB {
    /* 0x00 */ SndMgr *owner;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 state;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 idx;
    /* 0x14 */ s32 vol;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[2];
    /* 0x1E */ s16 snd;
} M04FxB;

extern f32 D_800C90A4;
void alSndpSetSound(void *p, s16 id);
void alSndpStop(void *p);
void func_00258760(SndMgr *m);
void func_002587C4(SndMgr *m);
void *func_00258D60(SndMgr *m);
s32 func_00265570(s32 a, s32 b, s16 id, s32 *lo, s32 *hi);
s32 func_00274544();

s32 func_0025CEF0(M04FxB *f, s32 id, f32 v) {
    s32 lo;
    s32 hi;
    s32 lo2;
    s32 hi2;
    s32 idx;
    s32 sum;
    s32 r;
    s32 i;
    s32 ret;
    s32 ok;
    s32 st;
    u8 *pl;
    sum = 0;
    ok = func_00265570(f->owner->unk2B60, f->owner->unk2B64, id, &lo, &hi);
    if (ok == 0) {
        idx = -1;
    } else {
        if (lo != hi) {
            for (i = lo; i <= hi; i++) {
                sum += 100;
            }
            r = func_00274544() % sum;
            sum = 0;
            for (i = lo; i < hi; i++) {
                sum += 100;
                idx = i;
                if (sum >= r) {
                    goto found;
                }
            }
            idx = i;
        } else {
            idx = lo;
        }
    }
found:
    if (idx == -1) {
        return -1;
    }
    sum = 0;
    func_00258D60(f->owner);
    func_00258760(f->owner);
    f->unkC = id;
    f->idx = idx;
    f->unk4 = f->unk4 + 1;
    ret = f->unk4;
    if (func_00265570(f->owner->unk2B60, f->owner->unk2B64, *(s16 *)((u8 *)f + 0xE), &lo2, &hi2) != 0) {
        if (lo2 != hi2) {
            for (i = lo2; i <= hi2; i++) {
                sum += 100;
            }
            r = func_00274544() % sum;
            sum = 0;
            for (i = lo2; i < hi2; i++) {
                sum += 100;
                if (sum >= r) {
                    break;
                }
            }
        }
    }
    f->unk18 = 0x40;
    f->vol = (s32)(v * D_800C90A4);
    st = f->state;
    if (st == 3 || st == 1) {
        if (st != 2 && st != 0) {
            f->state = 2;
            pl = func_00258D60(f->owner);
            alSndpSetSound(pl, f->snd);
            alSndpStop(pl);
        }
    } else {
        f->state = 1;
    }
    func_002587C4(f->owner);
    return ret;
}
