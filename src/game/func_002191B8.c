#include "b04_types.h"
extern s32 D_801468C4;
extern f32 D_800C73B8;
typedef struct { s32 kind; u8 pad4[0x68]; s32 unk6C; s32 unk70; } B04Menu;
s32 func_00218988(B04Act *);
void func_00219124(B04Menu *, s32, B04Act *);
void func_002191B8(B04Menu *o, B04Act *p) {
    s32 v;
    s32 wf = p->wpn->flagsB0 & 0x8000;
    s32 k = o->kind;
    if (k == 0 || k == 3) {
        if (D_801468C4 != 0 && p->stats->unk92 == 0xFF) {
            func_00219124(o, wf, p);
            o->kind = 1;
            goto blk5;
        }
    } else {
blk5:
        *(f32 *)((u8 *)p + 0x670) = D_800C73B8;
        *(s32 *)((u8 *)p + 0x11B4) = 1;
        *(s32 *)((u8 *)p + 0x11B8) = 1;
        v = func_00218988(p);
        if (v != o->unk70) {
            if (v != -1) {
                u8 *e = (u8 *)o + v * 0x14;
                u16 a1 = *(u16 *)(e + 0x1E);
                if (*(s32 *)(e + 0x20) != 0) {
                    if ((s16)a1 < 0) {
                        o->unk70 = -1;
                        return;
                    }
                    if (v != o->unk6C)
                        o->unk6C = v;
                    p->stats->unk92 = a1;
                    goto blk13;
                }
            } else {
blk13:
                o->unk70 = v;
            }
        }
    }
}
