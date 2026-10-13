#include "o04_types.h"
typedef struct { f32 x; f32 y; f32 z; } O04V3;
extern O04ModeS53C0 *D_800E53C0;
extern s32 D_800D752C;
extern f32 D_800E1B2C;
extern f32 D_800E1B30;
extern f32 D_800E1B34;
extern f32 D_800E1B38;
void *func_0040ECB0(s32 a, s32 b);
void func_0040E958(void *p, s32 a);
void func_00439D3C(void *p, s32 a, O04V3 v, O04V3 w);
void func_00439DC0(void *p, O04V3 v);
void func_00439E10(void *p, O04V3 v);
void func_00439E60(void *p, s32 a);
void func_auto_0042CE74(void) {
    O04V3 a;
    O04V3 b;
    O04V3 c;
    O04V3 d;
    O04Sub2C *o;
    if (D_800E53C0->unk32C != -1) {
        o = func_0040ECB0(D_800E53C0->unkE0, 0x263);
        func_0040E958(o, 1);
        o->unk10 = 0xAF;
        o->unk38 = D_800D752C;
        a.x = D_800E1B2C;
        a.y = D_800E1B2C;
        a.z = D_800E1B2C;
        c.x = 0;
        c.y = 0;
        c.z = 0;
        d.x = 0;
        d.y = D_800E1B30;
        d.z = 0;
        b.x = 0;
        b.y = D_800E1B34;
        b.z = D_800E1B38;
        func_00439D3C(D_800E53C0->unk20, 0, a, b);
        func_00439DC0(D_800E53C0->unk20, c);
        func_00439E10(D_800E53C0->unk20, d);
        func_00439E60(D_800E53C0->unk20, D_800E53C0->unk32C);
    }
}
