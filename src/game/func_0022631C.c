#include "b06_types.h"

void func_00216488(f32 *out, Plr *p, s32 a, f32 b, s32 c, s32 d);
void func_00219A40(Plr *a, u8 *b, f32 *c);
void func_002227D0(Plr *a, Plr *b, s32 c);
void func_0023919C(Pawn *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_002394AC(u8 *a, f32 b, f32 c, f32 d, f32 e, s32 f, Vec3f pos);
f32 func_002745D4(f32 x);
extern f32 D_800D2988;
extern u8 D_80145088[];

void func_0022631C(Plr *a) {
    Pawn *pw;
    Plr *tgt;
    Plr *o;
    f32 buf[6];
    f32 t;
    u32 v;
    if (a->unk5DC != NULL && 80.0f < func_002745D4(100.0f)) {
        pw = a->unk5DC;
        t = func_002745D4(7.5f);
        v = (u32)t;
        func_0023919C(pw, 0xFF, 0xFF, 0, 0, (u8)v, 3, 7);
        func_002394AC(D_80145088, 0.0f, 204.79999f, 0.0f, 512.0f, 0, pw->pos128);
    }
    a->unk1D4 = a->unk1D4 - D_800D2988;
    if (a->unk1D4 <= 0.0f || a->unk5E4 == 0) {
        o = a->unk13D8;
        tgt = NULL;
        if (o->unk0 == 1 && (o->flags100 & 0x300000)) {
            tgt = o;
        }
        a->flags100 &= 0xFF7FFFFF;
        func_002227D0(a, a, 2);
        if (tgt->unk122C & 0x200) {
            func_00216488(buf, a->unk13D8, 0x30200, 25.599998f, 0x80, 0);
        } else {
            func_00216488(buf, a->unk13D8, 0x4600, 25.599998f, 0x80, 0);
        }
        a->unk13D8 = NULL;
        func_00219A40(a, (u8 *)a + 0x170, buf);
    }
}
