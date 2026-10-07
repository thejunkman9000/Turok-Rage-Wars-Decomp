#include "b12_types.h"

extern u8 D_8016E000[];
extern u8 D_801051A0[];
extern u8 D_8010A248[];
extern u8 D_801051B8[];
u32 func_00265370(void);
void func_00255854(void *heap, void *base, u32 size);
void func_00255090(void *port, s32 id);
void func_00256220(void *p, s32 n);
void func_0023B9A0(s32 a, s32 b);
void func_00250E10(s32 a, s32 b);

void func_002567F0(void) {
    u32 end = 0x80400000;
    u8 *base = D_8016E000;
    u32 size;
    if (func_00265370() != 0x400000) {
        end = func_00265370() | 0x80000000;
    }
    size = end - (u32)base;
    memset(base, 0, size);
    func_00255854(D_801051A0, base, size);
    func_00255090(D_8010A248, 3);
    func_00256220(D_801051B8, 4);
    func_0023B9A0(0, 0);
    func_00250E10(0, 5);
}
