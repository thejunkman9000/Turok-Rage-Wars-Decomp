#include "o02_types.h"
extern s32 D_80153F64[];
extern s32 D_80153F6C;
extern s32 D_80153F70;
extern s32 D_800E32CC;
void func_0041900C(void);
void func_004171B8(s32 v);
void func_004170B4(s32 mode) {
    s32 x, y;
    s32 *p = D_80153F64;
    s32 t;
    if (p[0] == 0) mode = 11;
    if (mode != D_800E32CC) {
        D_800E32CC = mode;
        if (mode == 11) {
            func_0041900C();
            x = p[-1] ? 0x55 : 0x53;
            x |= p[1] ? 0x300 : 0x500;
            y = x | (D_80153F6C ? 0x3000 : 0x5000);
            func_004171B8(y | (D_80153F70 ? 0x30000 : 0x50000));
        }
        else if (mode == 12) {
            func_0041900C();
            x = p[-1] ? 0x35 : 0x33;
            x |= p[1] ? 0x300 : 0x500;
            t = x | (D_80153F6C ? 0x3000 : 0x5000);
            y = t;
            func_004171B8(y | (D_80153F70 ? 0x30000 : 0x50000));
        }
    }
}
