#include "b04_types.h"
extern DlCmd *D_80110634;
extern u8 D_8011FE88[];
extern f32 D_800C7474;
extern s32 D_800CE430[];
extern s32 D_800CE47C;
extern s32 D_800D297C;
extern u8 D_801462E5;
extern s32 D_801468F4;
typedef struct { s32 type; u8 pad4[8]; s16 unkC; } B04Def5;
typedef struct { u8 pad0[0x81]; u8 unk81; u8 pad82[0xD]; u8 unk8F; } B04St5;
typedef struct { s32 w[6]; } B04Seg24;
typedef struct {
    u8 pad0[3]; u8 unk3; u8 pad4[4]; Vec3f pos; u8 pad14[4]; B04Def5 *def; u8 pad1C[0x54]; f32 unk70; u8 pad74[0xCC];
    B04Seg24 seg[1]; u8 pad158[0x480]; B04St5 *stats; u8 pad5DC[0x290]; s32 unk86C; u8 pad870[0x9A0]; s32 unk1210;
} B04O6;
f32 func_0024D274(void *);
void func_0028C6B0(u8 *, Vec3f *, B04Seg24 *);
void func_0028B250(u8 *, void *, s32, s32);
void func_00249E18(void *, void *);
void func_0021C674(void *, void *);
void func_0021C9B4(B04O6 *o, void *a1) {
    Vec3f v;
    s32 a2;
    DlCmd *g;
    v = o->pos;
    v.y = v.y + o->unk70;
    v.y = v.y + func_0024D274(o) * D_800C7474;
    func_0028C6B0(D_8011FE88, &v, &o->seg[D_800D297C]);
    a2 = 0x66;
    if (D_801462E5 != 0) {
        if (D_801468F4 != 0 && o->stats->unk8F != 0) {
            a2 = D_800CE47C;
        } else {
            a2 = D_800CE430[o->def->unkC];
            o->unk3 = o->stats->unk81;
        }
    }
    func_0028B250(D_8011FE88, o, a2, o->unk86C);
    g = D_80110634++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_80110634++;
    g->w0 = 0xE3000A01;
    g->w1 = 0x100000;
    g = D_80110634++;
    g->w0 = 0xD9FFFFFF;
    g->w1 = 0x10000;
    g = D_80110634++;
    g->w0 = 0xDB040004;
    g->w1 = 2;
    g = D_80110634++;
    g->w0 = 0xDB04000C;
    g->w1 = 2;
    g = D_80110634++;
    g->w0 = 0xDB040014;
    g->w1 = 0xFFFE;
    g = D_80110634++;
    g->w0 = 0xDB04001C;
    g->w1 = 0xFFFE;
    func_00249E18(o, a1);
    if (o->unk1210 != 0)
        func_0021C674(o, a1);
}
