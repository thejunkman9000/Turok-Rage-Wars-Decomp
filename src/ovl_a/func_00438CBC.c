#include "o05_types.h"

extern void *D_800E5830;
extern s32 D_80146948;
extern s32 D_80146918;
extern s32 D_801468F4;
extern s32 D_8015402C;
extern u8 D_801462D5;
extern s32 D_80145088[];
extern u8 D_8011FE88[];
s32 func_0043C4E8(void *p);
void func_0043C260(void *p);
void func_0043C484(void *p);
void func_00438A08(void);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0040C4A8(s32 a);
void func_0040E958(void *w, s32 a);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);

typedef struct { u8 pad[0x1C]; s32 f1C; } O05M30b;

s32 func_00438CBC(void *cfg, s32 b, s32 ev) {
    s32 t;
    if (ev == 1) {
        t = func_0043C4E8(D_800E5830);
        if (t == ev) {
            func_0043C260(D_800E5830);
            func_0043C484(D_800E5830);
            if (func_0043C4E8(D_800E5830) != 2) {
                return 0;
            }
            if (((O05M30b *)D_800E5830)->f1C != 0) {
                if (((O05M30b *)D_800E5830)->f1C != t) {
                    return 0;
                }
                func_0040C4A8(0);
                func_0040E958(cfg, 1);
                func_0044AFC0(D_80145088, 0);
                func_0044A600(D_80145088 - 0x12, 0, 0);
                func_00286A78(D_8011FE88, 0, 0);
                D_80145088[0x17F0 / 4] = 8;
                return 0;
            }
            func_0029A73C();
            D_80146918 = 0;
            D_801468F4 = 0;
            if (D_80146948 == t) {
                if (D_8015402C >= 0x23) {
                    switch (D_801462D5) {
                    case 1: func_00299368(7); break;
                    case 3: func_00299368(3); break;
                    case 4: func_00299368(3); break;
                    default: func_00299368(3); break;
                    }
                } else func_00299368(10);
            } else func_00299368(10);
            return 0;
        } else {
            func_00438A08();
        }
    }
    return 0;
}
