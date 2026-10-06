#include "b20_types.h"

typedef struct { u8 pad0[0x110]; u32 fb; } Vi;

void func_00291BF8(s32 a, s32 b, s32 w, s32 c, s32 h, s32 d);
void func_002AB940(s32 a, s32 b, u32 *c, u32 *d);
void func_002AA224(s32 a);
void func_002ABC18(s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, s32 g);
extern DlCmd *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern Vi *D_8011FE80;

void func_00290C04(s32 arg) {
    u32 sp20;
    u32 sp24;
    DlCmd *g;
    Vi *vi = D_8011FE80;
    func_00291BF8(arg, 0, D_800E28D0, 0, D_800E28D4, 0);
    sp20 = 0;
    sp24 = 0;
    g = D_80110634++;
    g->w0 = 0xED000000;
    g->w1 = (((s32)((D_800E28D0 - 1) * 4.0f) & 0xFFF) << 12) | ((s32)((D_800E28D4 - 1) * 4.0f) & 0xFFF);
    g = D_80110634++;
    g->w0 = 0xFF100000 | ((D_800E28D0 - 1) & 0xFFF);
    g->w1 = vi->fb;
    g = D_80110634++;
    g->w0 = 0xE3000A01;
    g->w1 = 0x300000;
    g = D_80110634++;
    g->w0 = 0xFCFFFFFF;
    g->w1 = 0xFFFE793C;
    g = D_80110634++;
    g->w0 = 0xE200001C;
    g->w1 = 0;
    g = D_80110634++;
    g->w0 = 0xF7000000;
    g->w1 = 0x10001;
    g = D_80110634++;
    g->w0 = 0xF6000000 | ((D_800E28D0 & 0x3FF) << 14) | ((D_800E28D4 & 0x3FF) << 2);
    g->w1 = 0;
    func_002AB940(0x386, 0, &sp20, &sp24);
    if (sp20 != 0 && sp24 != 0) {
        func_002AA224(0xFF);
        func_002ABC18(0x386, 0, 0, 0, (f32)D_800E28D0 / (f32)(s32)sp20, (f32)D_800E28D4 / (f32)(s32)sp24, 1);
    }
}
