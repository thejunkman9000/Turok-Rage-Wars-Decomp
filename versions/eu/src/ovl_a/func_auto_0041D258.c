#include "o03_types.h"

extern void func_0041C680(O3Act *a, s32 id, s32 p, s32 type);

void func_auto_0041D258(O3Act *a, s32 id, s32 p, s32 type) {
    *(u16 *)((u8 *)a + 0x274) = 0xFFFF;
    func_0041C680(a, id, p, type);
}
