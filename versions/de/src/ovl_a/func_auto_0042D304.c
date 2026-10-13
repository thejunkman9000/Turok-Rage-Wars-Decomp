#include "o04_types.h"
typedef struct { u8 pad0[0x92]; u8 unk92; u8 pad93[0x96 - 0x93]; } O04Ent96h;
extern O04ModeS53C0 *D_800E53C0;
extern O04Ent96h D_80146398[];
void *func_0040ECB0(void *a, u16 b);
void func_0040E958(void *p, s32 a);
void func_auto_0042D304(s32 a, s32 b, s32 c) {
    O04Ent96h *e = &D_80146398[a];
    O04Sub2C *h;
    O04Sub2C *p;
    s32 id;
    s32 v;
    h = func_0040ECB0((void *)D_800E53C0->unkE0, c);
    switch (b) {
    case 1:
        id = 0x267;
        break;
    case 2:
        id = 0x266;
        break;
    case 3:
        id = 0x265;
        break;
    case 0:
    default:
        id = 0x268;
        break;
    }
    p = func_0040ECB0(h, id);
    func_0040E958(p, 1);
    p->unk10 = 0x96;
    switch (e->unk92) {
    case 0:
        v = 0x63;
        break;
    case 1:
        v = 0x62;
        break;
    case 2:
        v = 0x61;
        break;
    case 3:
        v = 0x5F;
        break;
    default:
        func_0040E958(p, 0);
    case 4:
        v = 0x60;
        break;
    }
    p->unk2C = v;
}
