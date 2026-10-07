#include "b04_types.h"
s32 func_00216BF4(B04Act *, void *, B04Act *);
s32 func_0021CD70(B04Act *pl, B04Act *t) {
    s16 w = pl->unk62E;
    s32 ty;
    s8 v;
    if (w == 0x12) {
        if (t->flags & 0x300000) {
            if (t->def->info.flags & 0x20) {
                v = t->unk1A4;
                if (v == 0x26) return 0;
                if (v == w) return 0;
                if (t->unk174 == 0) return 0;
                {
                    B04Sub *p = t->sub5DC;
                    s32 r;
                    if (p == NULL) r = 0;
                    else r = p->unk564 ? 1 : 0;
                    if (r != 0) return 0;
                    goto call;
                }
            }
            goto end0;
        }
        if (t->def->type == 1) {
            if (t->def->info.flags & 0x2400) {
                v = t->unk1A4;
                if (v == 0x21 || v == 0x34 || v == 0x3C) goto end0;
                if (v == 0x3D) return 0;
                if (t->unk174 != 0) goto call;
                return 0;
            }
            goto end0;
        }
    }
    ty = t->def->type;
    if (ty != 4) {
        if (ty >= 5) {
            switch (ty) {
            case 7:
                goto end0;
            case 11:
                goto c11;
            default:
                return 0;
            }
        } else
            return 0;
    } else {
        if (t->unk174 == 0) goto end0;
call:
        return func_00216BF4(pl, (u8 *)pl + 0x170, t) == 0;
    }
c11:
    {
        s32 a0 = 0;
        v = t->unk1A4;
        if (v != 0x26) {
            if (v != 0x12) {
                s32 r = t->unk174;
                if (r != 0) {
                    B04Sub *p = t->sub5DC;
                    if (p != NULL)
                        r = p->unk564 ? 1 : 0;
                    if (r == 0) a0 = 1;
                }
            }
        }
        return a0;
    }
end0:
    return 0;
}
