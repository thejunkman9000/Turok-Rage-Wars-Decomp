#include "o02_types.h"
typedef struct O02Cam { u8 pad0[4]; struct O02Cam *next; u8 pad[0x29C - 8]; f32 f29C; f32 f2A0; s32 w2A4; s32 w2A8; } O02Cam;
typedef struct { O02Cam *head; u8 pad[0x1C]; O02Cam cam; } O02CamList;
extern O02CamList D_801450A8;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800D15C4;
extern u16 D_800E2A4E[];
extern u16 D_80153790;
extern s32 D_80000300;
void func_0040BE38(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_0040C504(u32 a0, s32 a1, s32 a2, s32 a3, s32 e, s32 f) {
    s32 flags = 0;
    s32 mode = 0;
    s32 low;
    O02Cam *n;
    switch (D_80000300) {
    case 0: mode = 1; break;
    case 1: break;
    case 2: mode = 2; break;
    }
    if (a0 >= 0x141) flags |= 4;
    if (D_800D15C4 != 0) flags |= 2;
    if (a0 >= 0x141) flags |= 1;
    D_80153790 = *(u16 *)((u8 *)D_800E2A4E + flags * 4 + mode * 32);
    func_0040BE38(a0, a1, a2, a3, e, f);
    if (&D_801450A8.cam) {
        D_801450A8.cam.f29C = D_800E28D0;
        D_801450A8.cam.w2A4 = 0;
        D_801450A8.cam.w2A8 = 0;
        D_801450A8.cam.f2A0 = D_800E28D4;
    }
    for (n = D_801450A8.head; n; n = n->next) {
        n->w2A4 = 0;
        n->w2A8 = 0;
        n->f29C = D_800E28D0;
        n->f2A0 = D_800E28D4;
    }
}
