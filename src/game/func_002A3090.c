#include "b23_types.h"

typedef struct TimerVar {
    f32 t;
    s32 flag;
} TimerVar;

extern s32 D_800D0E54;
extern f32 D_800D2988;
extern s32 D_800D2C90;
extern s32 D_800D2C98;
extern TimerVar D_800D2CA0;
extern s8 D_8010FBB8;
extern s32 D_8014694C;

void func_004104C8();
void func_0042E080();
void func_0042E7CC();
void func_00299FE8();
void func_0029A5D4(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_0029A958();
void func_002A27C4();
void func_002A2944();
void func_002A33F8(f32 v);
void func_002A342C();

void func_002A3090(void) {
    s32 type, a0, a1, fl;

    if (D_800D2C98 == 1) {
        func_002A27C4();
        func_0029A5D4(func_0029A958(), 0xE08, 0, 0, 0);
        func_00299FE8();
        func_004104C8();
        func_002A2944();
        type = func_0029A958();
        a1 = 1;
        a0 = 0;
        if (type == 3) {
            goto b3;
        }
        if (type == 0x18) {
            a0 = 0x14;
            goto join;
        }
        a1 = 0;
        goto join;
b3:
        a0 = 0x12C;
join:
        if (D_8014694C == 0 && a1 == 1 && (f32)(a0 * 15) < D_800D2CA0.t) {
            func_0042E7CC(a0);
            func_0042E080();
            func_002A33F8(0.0f);
        }
        D_800D2CA0.t = D_800D2CA0.t + D_800D2988;
        fl = D_800D2CA0.flag;
        if (fl == 1) {
            D_800D0E54 = D_800D0E54 - 1;
            if (D_800D0E54 <= 0) {
                D_800D0E54 = 0x3C;
                D_8010FBB8 = fl;
            }
        }
        if (D_800D2C90 == 1) {
            func_002A342C();
        }
    }
}

