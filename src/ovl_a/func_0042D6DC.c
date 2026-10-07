#include "o04_types.h"
extern O04ModeS53C0 *D_800E53C0;
extern u8 D_80145088[];
extern u8 D_80145040[];
extern u8 D_8011FE88[];
extern u8 D_801462D5;
extern s32 D_80146918;
extern s32 D_801468F4;
s32 func_0043C4E8(void *p);
void func_0043C260(void *p);
void func_0043C484(void *p);
void func_0040C4A8(s32 a);
void func_0040E958(s32 p, s32 a);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
void func_0042D46C(void);
void func_0029A73C(void);
s32 func_0042B108(void);
s32 func_0042AEB8(void);
void func_0042E080(void);
void func_00299368(s32 a);
s32 func_0042D6DC(s32 a, s32 b, s32 c) {
    s32 s1;
    s32 v;
    s32 a0;
    if (c == 1) {
        s1 = func_0043C4E8(D_800E53C0);
        if (s1 == c) {
            func_0043C260(D_800E53C0);
            func_0043C484(D_800E53C0);
            if (func_0043C4E8(D_800E53C0) == 2) {
                v = D_800E53C0->unk1C;
                if (v != 0) {
                    if (v == s1) {
                        func_0040C4A8(0);
                        func_0040E958(a, 1);
                        func_0044AFC0(D_80145088, 0);
                        func_0044A600(D_80145088 - 0x48, 0, 0);
                        func_00286A78(D_8011FE88, 0, 0);
                        *(s32 *)(D_80145088 + 0x17F0) = 8;
                    }
                } else {
                    func_0040E958(a, 0);
                    func_0029A73C();
                    a0 = 0xF;
                    if (D_801462D5 == 0) {
                        D_80146918 = 0;
                        D_801468F4 = 0;
                        if (func_0042B108() && func_0042AEB8()) {
                            func_0042E080();
                            return 0;
                        }
                        a0 = 0x14;
                    } else {
                        D_80146918 = 0;
                        D_801468F4 = 0;
                    }
                    func_00299368(a0);
                }
            }
        } else {
            func_0042D46C();
        }
    }
    return 0;
}
