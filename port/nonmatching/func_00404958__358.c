#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];
extern OSPfs D_80153510[];
extern u8 D_8010FBB8;
extern u8 D_800E0D18[];
extern u8 D_800E0D00[];
extern char *D_800D7708;
s32 func_0025471C(void);
void func_0025470C(s32 a);
s32 *func_002533DC(s32 a, s32 b, s32 c, void *d);
s32 func_0026451C(s32 flag);
void func_00263760();
void func_0026456C(void);
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
s32 func_00404858(s32 pad, s32 idx);
s32 func_004042F0(s32 pad, s32 size, u8 *data, u8 *name, s32 *outFileNo, u8 *ext, char *company, u8 *game);
s32 func_00265464(void *a, void *b, u32 n);
s32 osPfsReadWriteFile(OSPfs *pfs, s32 file_no, u8 flag, int offset, int size_in_bytes, u8 *data_buffer);
void *memcpy(void *dst, const void *src, u32 n);

static inline s32 O01ReadFile(s32 pad, s32 fileNo, u8 *dst, s32 size) {
    s32 rsize = (size + 0xFF) & ~0xFF;
    s32 *h;
    u8 *buf;
    s32 r;
    s32 zero;
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

s32 func_00404958(s32 pad, s32 size, u8 *data, u8 *name, u8 *ext, u8 *game) {
    s32 fileNo;
    s32 *h;
    u8 *buf;
    s32 rsize;
    s32 i;
    s32 r;
    rsize = (size + 0xFF) & ~0xFF;
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    h = func_002533DC(0, rsize, 0x23, D_800E0D18);
    buf = (u8 *)*h;
    i = 0;
    do {
        r = func_004042F0(pad, size, data, name, &fileNo, ext, D_800D7708, game);
        if (r != 0) {
            break;
        }
        if (O01ReadFile(pad, fileNo, buf, rsize) != 0 || func_00265464(buf, data, size) != 0) {
            if (func_00404858(pad, fileNo) != 0) {
                break;
            }
            i++;
        } else {
            break;
        }
    } while (i < 4);
    func_002538A8(0);
    if (h != 0) {
        func_002537D8(0, (s32)h);
    }
    return r;
}
