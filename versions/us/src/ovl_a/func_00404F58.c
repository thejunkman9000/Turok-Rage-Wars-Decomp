#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];
extern OSPfs D_80153510[];
extern u8 D_800E0D00[];
extern u8 D_8010FBB8;
s32 func_0025471C(void);
void func_0025470C(s32 a);
s32 *func_002533DC(s32 a, s32 b, s32 c, void *d);
s32 func_0026451C(s32 flag);
void func_00263760();
void func_0026456C(void);
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
s32 osPfsReadWriteFile(OSPfs *pfs, s32 file_no, u8 flag, s32 offset, s32 nbytes, u8 *data);
void *memcpy(void *dst, const void *src, u32 n);

s32 func_00404F58(s32 pad, s32 fileNo, u8 *dst, s32 size) {
    s32 rsize = (size + 0xFF) & ~0xFF;
    s32 *h;
    s32 zero;
    u8 *buf;
    s32 r;
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    if (func_0025471C() == 0) {
        func_0025470C(1);
    }
    h = func_002533DC(0, rsize, 0x23, D_800E0D00);
    buf = (u8 *)*h;
    func_0026451C(1);
    func_00263760();
    r = D_80153500[pad];
    D_8010FBB8 = 2;
    if (r == 0) {
        r = osPfsReadWriteFile(&D_80153510[pad], fileNo, 0, 0, rsize, buf);
        zero = 0;
        if (r != zero) {
            r = -1;
        }
        if (r == 0) {
            memcpy(dst, buf, size);
        }
    }
    func_0026456C();
    func_002538A8(0);
    if (h != 0) {
        func_002537D8(0, (s32)h);
    }
    return r;
}
