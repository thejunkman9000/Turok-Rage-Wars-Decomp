#include "b04_types.h"
extern s32 D_801468F4;
typedef struct { u8 pad0[0xC]; s16 unkC; } B04W2;
extern B04W2 *D_800D052C[];
s32 func_00217B3C(B04Act *);
void func_002181FC(B04Roster *, s32, B04Act *);
s32 func_0022C450(B04Act *);
void func_0025DF54(s32, void *, u16);
void func_00217D74(B04Roster *o, B04Act *p) {
    s32 s0v, k, v, t;
    u8 *e;
    u16 a2;
    s16 idx;
    s0v = p->wpn->flagsB0 & 0x8000;
    if (func_0022C450(p) != 0)
        s0v = 0;
    if (D_801468F4 != 0 && p->stats->unk8F == 1) {
        s0v = 0;
        o->w0 = 3;
    }
    if (s0v != 0 && o->f4 > 0.0f)
        o->w0 = 3;
    k = o->w0;
    if (k == 0 || k == 3) {
        if (s0v == 0) {
            if (p->unkCC0 != -1 && o->w388 != 8) {
                func_002181FC(o, 0, p);
                o->w0 = 1;
            }
        } else {
            p->unkCC0 = -1;
            func_002181FC(o, s0v, p);
            p->unk11B4 = 1;
            o->w0 = 1;
            goto blk15;
        }
    } else {
blk15:
        s0v = o->w388;
        if (s0v == -1) {
            v = func_00217B3C(p);
            if (v != o->w390) {
                if (v != s0v) {
                    e = (u8 *)o + v * 24;
                    a2 = *(u16 *)(e + 0x1E);
                    if (*(s32 *)(e + 0x24) == 0) {
                        func_0025DF54(0xD4D, e, a2);
                        return;
                    }
                    if ((s16)a2 < 0) {
                        o->w390 = s0v;
                        return;
                    }
                    if (v != o->w37C)
                        o->w37C = v;
                    idx = a2;
                    if (idx != p->unk62E) {
                        p->unk770 = a2;
                        if (!(p->flags38 & 0x1000)) {
                            t = D_800D052C[idx]->unkC;
                            if (t != s0v && p->pr[t].a != 0)
                                *(s32 *)(e + 0x1C) = t;
                        }
                    }
                }
                o->w390 = v;
            }
        }
    }
}
