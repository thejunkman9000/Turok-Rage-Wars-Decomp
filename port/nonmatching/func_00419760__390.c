#include "o03_types.h"
s32 func_00419ABC(O3Menu *o, s32 f);
void func_00419AA8(O3Menu *o, s32 f);
void func_00419A98(O3Menu *o, s32 f);
void func_00419A5C(O3Menu *o, s32 i);
s32 func_00419760(O3Menu *o, s32 a1, s32 dt) {
    s32 idx;
    if (func_00419ABC(o, 4) == 0) {
        o->f54 = o->f54 + dt;
        o->g->col = o->tbl[o->cur];
        if (o->f54 > o->f58) {
            o->f54 = 0;
            if (func_00419ABC(o, 1) != 0) {
                if (o->cur < o->cnt - 1) {
                    o->cur = o->cur + 1;
                } else {
                    if (func_00419ABC(o, 0x10) != 0) {
                        func_00419AA8(o, 1);
                        func_00419A98(o, 2);
                        idx = o->cnt - 2;
                        goto set;
                    }
                    if (func_00419ABC(o, 0x20) != 0) {
                        if (o->f60 > 0) {
                            o->f60 = o->f60 - 1;
                            idx = 0;
                            goto set;
                        }
                    } else if (func_00419ABC(o, 8) != 0) {
                        idx = 0;
                        goto set;
                    }
                }
            } else {
                if (o->cur > 0) {
                    o->cur = o->cur - 1;
                } else {
                    if (func_00419ABC(o, 0x10) != 0) {
                        func_00419AA8(o, 2);
                        func_00419A98(o, 1);
                        idx = 1;
                        goto set;
                    }
                    if (func_00419ABC(o, 0x20) != 0) {
                        if (o->f60 > 0) {
                            idx = o->cnt;
                            o->f60 = o->f60 - 1;
                            goto dec;
                        }
                    } else if (func_00419ABC(o, 8) != 0) {
                        idx = o->cnt;
dec:
                        idx = idx - 1;
set:
                        func_00419A5C(o, idx);
                    }
                }
            }
        }
    }
    return 0;
}
