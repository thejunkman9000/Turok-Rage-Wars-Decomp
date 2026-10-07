#include "b04_types.h"
extern f32 D_800D2988, D_800C7324, D_800C7328, D_800C732C, D_800C7330, D_800C7334;
void func_00217D74(B04Menu *, B04Act *, s32);
s32 func_0021846C(B04Menu *, B04Act *);
s32 func_0022FAE8(B04Act *);
s32 func_00232AAC(B04Act *);
s32 func_00245774();
void func_00285944(s32, s32);
void func_00217F4C(B04Menu *o, B04Act *p, s32 a2) {
    f32 t;
    if ((u32)(p->unk5E0 - 0x11) >= 2 && p->unkCCC == 0 && !(p->unk11D8 > 0.0f) && func_00245774() == 0) {
        o->w380 = p->stats->unk82 == 1;
        if (p->unk5E0 == 0xE) {
            if (p->unk48C != 0) {
                if (p->wpn->flagsB0 & 0x8000)
                    p->unk770 = func_00232AAC(p);
                goto blk15;
            }
        } else {
            if ((p->wpn->flagsB8 & 0x8000) && p->stats->unk82 != 0) {
                p->unk770 = func_0022FAE8(p);
            } else if (p->stats->unk82 != 1 || (p->unkCC0 != -1 && o->w388 != 8)) {
                func_00217D74(o, p, a2);
            }
blk15:
            if (p->unk770 != p->unk62E) {
                s32 a0 = p->unk11B0;
                if (a0 != 0) {
                    func_00285944(a0, 0);
                    p->unk11B0 = 0;
                }
                p->unk11F0 = 0;
                p->unk11F8 = -1;
            }
            switch (o->w0) {
            case 1:
                o->f8 = o->f8 + D_800D2988 * D_800C7324;
                if (o->w388 != -1)
                    o->f4 = D_800C7328;
                else
                    o->f4 = 0;
                if (o->f8 >= D_800C732C) {
                    o->w0 = 2;
                    o->f8 = D_800C732C;
                    if (o->w388 != -1)
                        o->w388 = 8;
                }
                break;
            case 2:
                if (func_0021846C(o, p) != 0) {
                    o->w388 = -1;
                    p->unk11B4 = 0;
                    o->w0 = 3;
            case 3:
                    t = o->f8 - D_800D2988 * D_800C7330;
                    o->f8 = t;
                    if (t <= 0.0f) {
                        o->f8 = 0.0f;
                        o->w0 = 0;
                    }
                }
                break;
            }
            if (o->w0 != 0)
                o->f14 = o->f14 + D_800D2988 * D_800C7334;
            else
                p->unk11B4 = 0;
        }
    }
}
