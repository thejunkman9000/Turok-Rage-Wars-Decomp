#include "o05_types.h"

typedef struct { u8 pad[0x1C]; s32 f1C; } O05W20;
extern O05W20 *D_800E5554;
extern s32 D_80146894[];
extern u8 D_8011FE88[];
s32 func_0043C4E8(void *p);
void func_0043C260(void *p);
void func_0043C484(void *p);
void func_0040C4A8(s32 a);
void func_0029A73C(void);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
s32 func_0025471C(void);
void func_0025470C(s32 a);
void func_00299368(s32 a);
void func_0025E3A4(void);

s32 func_004360F4(s32 a, s32 b, s32 ev) {
    s32 *g;
    if (ev == 1) {
        if (func_0043C4E8(D_800E5554) != ev) {
            return 0;
        }
        func_0043C260(D_800E5554);
        func_0043C484(D_800E5554);
        if (func_0043C4E8(D_800E5554) != 2) {
            return 0;
        }
        func_0040C4A8(0);
        func_0029A73C();
        g = D_80146894;
        g[0] = 0;
        func_0044AFC0(g - 0x603, 0);
        func_0044A600(g - 0x615, 0, 0);
        func_00286A78(D_8011FE88, 0x24, 0);
        if (func_0025471C() == 0) {
            func_0025470C(1);
        }
        g[-7] = 8;
        func_00299368(D_800E5554->f1C);
        func_0025E3A4();
    }
    return 0;
}
