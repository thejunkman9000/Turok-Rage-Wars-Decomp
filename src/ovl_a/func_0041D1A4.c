/* Record/slot screen update (per-tick callback; constructor: func_0041CEB0): steps the transition state
   machine D_800E3590->state (1 panels slide in, 2 slide out, 4 wait for the fade, 5 start leaving, 6 style
   fade-in, 3 idle, 7 nothing) and while idle pulses the cursor style with sin(clock/300) and moves the
   cursor to the node now under focus.  Hidden inside pad_18AEA8.  Upstream: func_8041D134_de (100% there);
   the switch table (7 words) and the four literals 1/300, 30.0, 220.0, 2^31 are this object's own pool
   (ro=0xE20D0:44).  The step/alpha fields are written as whole words by the constructor, but read as
   halfword/byte (low part) here: (u16)/(u8) casts give the ROM's lhu 0xCE / lbu 0x107. */
#include "s1008_types.h"

extern S1008Menu *D_800E3590;

extern void func_0025DF54(s32 sound);
extern void func_0029A73C(void);
extern void func_0029A8A8(void);

extern void func_0040E958(S1008Node *node, s32 enabled);
extern void func_00419FA4(s32 fade);
extern s32 func_00419FB8(s32 fade);
extern void func_00419FD8(s32 fade, s32 speed);
extern S1008Node *func_0041B87C(void *handle, s32 arg1);
extern f32 func_002BB630(f32 x);

extern void func_0041DACC(s32 style);
extern void func_0041D9D0(void);
extern void func_0041D550(void);

s32 func_0041D1A4(s32 arg0, s32 arg1, s32 arg2) {
    S1008Node *node;

    switch (D_800E3590->state) {
    case 1:
        D_800E3590->left->x += (u16)D_800E3590->leftStep;
        D_800E3590->right->x -= (u16)D_800E3590->rightStep;
        if (--D_800E3590->timer <= 0) {
            func_0025DF54(0xE79);
            func_0040E958(D_800E3590->groupA, 1);
            func_00419FD8(D_800E3590->fade, 4);
            D_800E3590->state = 4;
            D_800E3590->timer = 4;
        }
        break;
    case 2:
        D_800E3590->left->x -= (u16)D_800E3590->leftStep;
        D_800E3590->right->x += (u16)D_800E3590->rightStep;
        if (--D_800E3590->timer <= 0) {
            D_800E3590->state = 3;
            func_0029A73C();
            func_0029A8A8();
            return 0;
        }
        break;
    case 4:
        if (func_00419FB8(D_800E3590->fade) != 0) {
            func_00419FA4(D_800E3590->fade);
            D_800E3590->state = 6;
            D_800E3590->timer = 4;
            func_0040E958(D_800E3590->groupB, 1);
            func_0040E958(D_800E3590->groupC, 1);
        }
        break;
    case 5:
        func_0025DF54(0xE78);
        D_800E3590->state = 2;
        D_800E3590->timer = 4;
        func_0040E958(D_800E3590->groupB, 0);
        func_0040E958(D_800E3590->groupC, 0);
        func_0040E958(D_800E3590->groupA, 0);
        break;
    case 6:
        D_800E3590->styleValue += D_800E3590->styleStep;
        D_800E3590->groupC->style += (u8)D_800E3590->alphaStep;
        func_0041DACC(D_800E3590->styleValue);
        if (--D_800E3590->timer <= 0) {
            D_800E3590->groupC->style = 100;
            func_0041DACC(0x6E);
            D_800E3590->state = 3;
            func_0040E958(D_800E3590->cursor, 1);
        }
        break;
    case 7:
        break;
    }

    if (D_800E3590->state == 3) {
        D_800E3590->clock += arg2;
        D_800E3590->cursor->style = func_002BB630((f32) D_800E3590->clock * 0.0033333334f) * 30.0f + 220.0f;
        node = func_0041B87C(D_800E3590->handle, 0);
        if (node != D_800E3590->focus) {
            func_0025DF54(0xE7E);
            if (D_800E3590->focus != 0) {
                D_800E3590->focus->style = 0x6E;
            }
            D_800E3590->focus = node;
            node->style = 0xE1;
            func_0041D9D0();
            func_0041D550();
            D_800E3590->cursor->x = node->x - 2;
            D_800E3590->cursor->y = node->y;
        }
    }
    return 0;
}
