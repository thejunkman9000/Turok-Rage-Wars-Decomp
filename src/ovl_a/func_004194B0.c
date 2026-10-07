#include "o03_types.h"
extern O3Dl *D_80110634;
Mtx *func_002A25E4(s32 size);
void func_004194B0(f32 m[4][4]) {
    Mtx *mtx = func_002A25E4(0x40);
    guMtxF2L(m, mtx);
    O3_PUSH(0xDA380003, (u32)mtx);
}
