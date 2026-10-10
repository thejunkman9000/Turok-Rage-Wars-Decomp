#include "r01_types.h"

extern R1Map D_800F6D00[];
extern u8 D_8F0F7130[];
void func_00200610(void);
u32 func_002005A0(u32 addr);
void func_00200880(u32 dst, u32 src, u32 n);
void func_00200B14(u32 dst, u32 src, u32 n);
void func_00200D18(u32 dst, u32 src, u32 n);
void func_00200F98(u32 dst, u32 val, u32 n);
void func_00201064(u32 dst, u32 src, u32 n);

void func_002010D8(s32 dir) {
    u32 dst, src, n, len;
    u32 i;
    s32 fl;

    func_00200610();
    dst = 0xB1FE0000;
    src = func_002005A0(0xB1FFFFF4);
    n = func_002005A0(0xB1FFFFF8);
    if (src > 0xEFFFFFFF) {
        src += (u32)D_8F0F7130;
    }
    while (n != 0) {
        i = 0;
        while (src < D_800F6D00[i].lo || D_800F6D00[i].hi < src) {
            i++;
        }
        if (i >= 0x30) {
            fl = 0;
            len = 0x1000 - (src & 0xFFF);
        } else {
            fl = D_800F6D00[i].flags;
            { u32 e = src - 1; len = D_800F6D00[i].hi - e; }
        }
        if (n < len) {
            len = n;
        }
        if ((fl & dir) == 0) {
            if (dir == 1) {
                func_00200F98(dst, 0, len);
            }
            dst += len;
        } else if (fl & 4) {
            if (dir == 1) {
                func_00201064(dst, src, len);
            } else {
                func_00201064(src, dst, len);
            }
            dst += len;
        } else if (dir == 1) {
            func_00200D18(dst, src, len);
            dst += len;
        } else if (fl & 8) {
            func_00200B14(dst, src, len);
            dst += len;
        } else {
            func_00200880(dst, src, len);
            dst += len;
        }
        n -= len;
        src += len;
    }
}
