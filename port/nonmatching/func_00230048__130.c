#include "m02_gen.h"
extern s32 D_801468F4;
extern u8 D_80121990[];
s32 func_00222A80(M2Own *o, s32 w);
s32 func_002831FC(void *tbl, M2Own *o);
s32 func_00230048(M2Act *a, M2St *s) {
    M2Own *o;
    f32 zero;
    f32 t = s->unk130;
    zero = 0.0f;
    o = a->owner;
    if (t > zero) {
        return 0;
    }
    if (func_00222A80(o, o->unk62E) == 0) {
        return 0;
    }
    if (o->stats->unk8F == 1) {
        if (D_801468F4 != 0) {
            return 0;
        }
    }
    if (o->unk11D8 > zero) {
        return 0;
    }
    if (o->unk11B4 != 0) {
        return 0;
    }
    switch (o->unk62E) {
    case 11:
        if (!(o->unk6AC & 0x4000)) {
            goto ret1;
        }
        return 0;
    case 18:
        if (o->unk788 == 2) {
            goto ret1;
        }
        return 0;
    case 9:
        if (s->unk148 > 0.0f) {
            if (s->unk13C == 2) {
                return 0;
            }
        }
        if (o->unk5F6 < 50) {
            if (s->unk13C == 2) {
                return 0;
            }
        }
        if (o->unk5F6 < 10) {
            if (s->unk13C == 1) {
                return 0;
            }
        }
        goto ret1;
    case 12:
        if (func_002831FC(D_80121990, o) < 3) {
            goto ret1;
        }
        return 0;
    case 1:
        if (s->unk144 == 0) {
            return 0;
        }
    default:
ret1:
        return 1;
    }
}
