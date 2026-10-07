#include "b18_types.h"

typedef struct B18Obj {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ f32 x;
    /* 0x00C */ f32 y;
    /* 0x010 */ f32 z;
    /* 0x014 */ u8 pad14[0x15C];
    /* 0x170 */ u8 pad170[4];
    /* 0x174 */ u8 unk174[0x5C];
    /* 0x1D0 */ s8 type;
} B18Obj;

extern u8 D_8011EE30[];
extern u8 D_8011EFF8[];
extern f32 D_800C9D54;

s32 func_00273208(void *a, void *b);
f32 func_00275E44(s32 a, f32 x, f32 z);
void func_00275480(void *a, s32 b);
void func_002756F8(void *a, s32 b);
void func_002742B4(void *a, void *b);
void func_0026F690(void *a, void *b, void *c);
f32 func_0027612C(s32 a, s32 b);
void func_00273744(void *a, f32 b);

void *func_0027D950(B18Obj *o, u8 *a1) {
    u8 buf10[0x40];
    u8 buf50[0x10];
    u8 *p;

    switch (o->type) {
    case -8:
        func_00273208(D_8011EE30, o->unk174);
        return D_8011EE30;
    case -6:
        if (a1 == 0) return 0;
        return a1 + 0xE94;
    case -4:
    case -1:
        if (a1 == 0) return 0;
        return a1 + 0xE54;
    case -3:
        if (o->y - func_00275E44(0, o->x, o->z) <= D_800C9D54) {
            p = buf50;
            func_00275480(p, 0);
            goto common;
        }
    case -5:
        return D_8011EFF8;
    case -2:
        p = buf50;
        func_002756F8(p, 0);
    common:
        func_002742B4(p, buf10);
        func_0026F690(D_8011EE30, D_8011EFF8, buf10);
        return D_8011EE30;
    case 0:
    case 1:
    case 2:
        func_00273744(D_8011EE30, func_0027612C(0, o->type));
        return D_8011EE30;
    default:
        return 0;
    }
}
