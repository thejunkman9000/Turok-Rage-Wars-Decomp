#include "o01_types.h"
extern s32 D_800E2838;
extern u8 *D_80145060;
void func_004030E0(s32 a);
void func_004037E8(s32 a0) {
    register s32 a asm("$7");
    register u8 *bits asm("$4");
    register s32 id asm("$5");
    u8 b;
    s32 m;
    s32 i;
    a = a0;
    bits = D_80145060;
    if (D_800E2838 != 0) {
        id = a - 0x259;
        if ((u32)id < 6 && bits != 0) {
            bits += 0x638;
            i = id >> 3;
            m = 1 << (id & 7);
            b = bits[i];
            if ((b & m) != 0) return;
            bits[i] = b | m;
        }
        func_004030E0(a);
    }
}
