#include "o01_types.h"

extern s32 D_800E2838;
extern u8 *D_80145060;
void func_004030E0(s32 a);

void func_004037E8(s32 a) {
    u8 *bits = D_80145060;
    s32 id;
    s32 i;
    s32 m;
    u8 b;
    if (D_800E2838 != 0) {
        id = a - 0x259;
        if ((u32)id < 6 && bits != 0) {
            bits += 0x638;
            i = id >> 3;
            m = 1 << (id & 7);
            b = bits[i];
            if ((b & m) != 0) {
                return;
            }
            bits[i] = b | m;
        }
        func_004030E0(a);
    }
}
