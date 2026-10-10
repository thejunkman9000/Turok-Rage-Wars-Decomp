#include "o03_types.h"
s32 func_00419ABC(O3Menu *o, s32 f);
void func_00419AA8(O3Menu *o, s32 f);
void func_00419A98(O3Menu *o, s32 f);
void func_00419A5C(O3Menu *o, s32 i);
s32 func_00419760(O3Menu *o, s32 a1, s32 dt) {
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
                        func_00419A5C(o, o->cnt - 2);
                    } else if (func_00419ABC(o, 0x20) != 0) {
                        if (o->f60 > 0) {
                            o->f60 = o->f60 - 1;
                            func_00419A5C(o, 0);
                        }
                    } else if (func_00419ABC(o, 8) != 0) {
                        func_00419A5C(o, 0);
                    }
                }
            } else {
                if (o->cur > 0) {
                    o->cur = o->cur - 1;
                } else {
                    if (func_00419ABC(o, 0x10) != 0) {
                        func_00419AA8(o, 2);
                        func_00419A98(o, 1);
                        func_00419A5C(o, 1);
                    } else if (func_00419ABC(o, 0x20) != 0) {
                        if (o->f60 > 0) {
                            o->f60 = o->f60 - 1;
                            func_00419A5C(o, o->cnt - 1);
                        }
                    } else if (func_00419ABC(o, 8) != 0) {
                        func_00419A5C(o, o->cnt - 1);
                    }
                }
            }
        }
    }
    return 0;
}
