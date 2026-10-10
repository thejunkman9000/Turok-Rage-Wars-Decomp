#include "b04_types.h"
extern DlCmd *D_80110634;
extern u8 D_8011FAC0[];
typedef struct { u8 pad0[0x44]; f32 f44; f32 f48; f32 f4C; f32 f50; } B04Wdef;
extern B04Wdef *D_800D052C[];
typedef struct { u8 pad0[0x5EA]; s16 unk5EA; u8 pad5EC[0x42]; s16 unk62E; } B04Pa;
typedef struct { u8 pad0[0x120]; s32 unk120; u8 pad124[0x178]; f32 f29C; f32 f2A0; f32 f2A4; f32 f2A8; } B04Pb;
void func_0026D8F8(DlCmd *);
void func_0026D980();
void func_0026D9D0();
void func_00291BF8(u8 *, s32, s32, s32, s32, s32);
void func_00249E18(void *, void *);
void func_0021CBAC(B04Pa *pl0, B04Pb *o0) {
    register B04Pa *pl asm("$17") = pl0;
    register B04Pb *o asm("$18") = o0;
    DlCmd *g;
    DlCmd *first;
    B04Wdef *w;
    f32 *q;
    if (pl->unk62E != -1 && pl->unk5EA != 0) {
        {
        u32 c0 = 0xE3001201;
        first = D_80110634++;
        first->w0 = c0;
        first->w1 = 0x2000;
        }
        g = D_80110634++;
        g->w0 = 0xE3000C00;
        g->w1 = 0x80000;
        do {
        func_0026D8F8(first);
        w = D_800D052C[pl->unk62E];
        q = &o->f29C;
        func_00291BF8(D_8011FAC0,
                      w->f44 * o->f29C + q[2],
                      w->f4C * o->f29C + q[2],
                      w->f48 * q[1] + q[3],
                      w->f50 * q[1] + q[3],
                      o->unk120);
        g = D_80110634++;
        g->w0 = 0xD9FFFFFF;
        g->w1 = 0x10000;
        g = D_80110634++;
        g->w0 = 0xDB040004;
        g->w1 = 1;
        g = D_80110634++;
        g->w0 = 0xDB04000C;
        g->w1 = 1;
        g = D_80110634++;
        g->w0 = 0xDB040014;
        g->w1 = 0xFFFF;
        g = D_80110634++;
        g->w0 = 0xDB04001C;
        g->w1 = 0xFFFF;
        func_0026D980();
        func_00249E18((u8 *)pl + 0x2E8, o);
        func_0026D9D0();
        } while (0);
    }
}
