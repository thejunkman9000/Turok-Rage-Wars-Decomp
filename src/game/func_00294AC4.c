#include "p4_types.h"
typedef struct {
    u8 pad0[0x26DB0];
    s32 f26DB0;
    u8 pad26DB4[4];
    s32 f26DB8;
    s32 f26DBC;
    u8 pad26DC0[0x26DD0 - 0x26DC0];
    s32 f26DD0;
} P4Game;
typedef struct { void (*fn)(P4Game *); s32 b; s32 c; } P4Hook;
extern s32 D_80146D68;
extern P4Hook D_800D29D8[];
void func_00245690(void);
void func_0025E234(s32 a);
void func_00264874(s32 a);
void func_00294AC4(P4Game *g) {
    if (D_80146D68 == 2 && g->f26DD0 == 0) {
        s32 v = g->f26DBC;
        g->f26DB0 = 0;
        g->f26DB8 = v;
        func_00245690();
        func_0025E234(-1);
        func_00264874(0);
        if (D_800D29D8[g->f26DB8].fn != NULL) {
            D_800D29D8[g->f26DB8].fn(g);
        }
    }
}
