#include "b04_types.h"
extern f32 D_800D2988, D_800C7388, D_800C738C, D_800C7390, D_800C7394, D_800C7398;
extern s32 D_8014561C, D_801468C4;
extern s32 D_auto_800E0FF4[4][4];
extern u8 D_80145088[];
typedef struct { s32 w0; u8 pad4[4]; f32 f8; u8 padC[8]; f32 f14; u8 pad18[0x54]; s32 w6C; s32 w70; } B04Mn3;
s32 func_00245774();
void func_00218F84(B04Mn3 *);
void func_00219124(B04Mn3 *, s32, B04Act *);
s32 func_00218988(B04Act *);
s32 func_0021917C(B04Mn3 *, B04Act *);
void func_00237E70(u8 *, void *, s32);
void func_0025DF54(s32);
void func_auto_00218BA4(B04Mn3 *o, B04Act *p) {
    s32 v, k, wf, a0, k2;
    f32 t;
    if (func_00245774() == 0) {
        if (D_8014561C != 0 && o->w0 != 0) {
            func_00218F84(o);
            return;
        }
        wf = p->wpn->flagsB0 & 0x8000;
        k = o->w0;
        if (k == 0 || k == 3) {
            if (D_801468C4 != 0 && p->stats->unk92 == 0xFF) {
                func_00219124(o, wf, p);
                o->w0 = 1;
                goto blk9;
            }
        } else {
blk9:
            *(f32 *)((u8 *)p + 0x670) = D_800C7388;
            p->unk11B4 = 1;
            *(s32 *)((u8 *)p + 0x11B8) = 1;
            v = func_00218988(p);
            if (v != o->w70) {
                if (v != -1) {
                    u8 *e = (u8 *)o + v * 0x14;
                    u16 a1 = *(u16 *)(e + 0x1E);
                    if (*(s32 *)(e + 0x20) != 0) {
                        if ((s16)a1 < 0) {
                            o->w70 = -1;
                        } else {
                            if (v != o->w6C)
                                o->w6C = v;
                            p->stats->unk92 = a1;
                            goto blk17;
                        }
                    }
                } else {
blk17:
                    o->w70 = v;
                }
            }
        }
        k2 = o->w0;
        switch (k2) {
        case 1:
            o->f8 = o->f8 + D_800D2988 * D_800C738C;
            if (D_800C7390 <= o->f8) {
                o->f8 = D_800C7390;
                o->w0 = 2;
            }
            break;
        case 2:
            if (func_0021917C(o, p) != 0) {
                o->w0 = 3;
                p->unk11B4 = 0;
                *(s32 *)((u8 *)p + 0x11B8) = 0;
                switch (p->stats->unk92) {
                case 0:
                    func_00237E70(D_80145088, p->sub5DC, D_auto_800E0FF4[0][D_80145088[0x17C1]]);
                    a0 = 0x2E6;
                    goto blk38;
                case 1:
                    func_00237E70(D_80145088, p->sub5DC, D_auto_800E0FF4[1][D_80145088[0x17C1]]);
                    a0 = 0x2E4;
                    goto blk38;
                case 2:
                    func_00237E70(D_80145088, p->sub5DC, D_auto_800E0FF4[2][D_80145088[0x17C1]]);
                    a0 = 0x2E8;
                    goto blk38;
                case 3:
                    func_00237E70(D_80145088, p->sub5DC, D_auto_800E0FF4[3][D_80145088[0x17C1]]);
                    a0 = 0x2EC;
blk38:
                    func_0025DF54(a0);
                    break;
                }
            case 3:
                t = o->f8 - D_800D2988 * D_800C7394;
                o->f8 = t;
                if (t <= 0.0f) {
                    o->f8 = 0.0f;
                    o->w0 = 0;
                }
            }
            break;
        }
        if (o->w0 != 0)
            o->f14 = o->f14 + D_800D2988 * D_800C7398;
    }
}
