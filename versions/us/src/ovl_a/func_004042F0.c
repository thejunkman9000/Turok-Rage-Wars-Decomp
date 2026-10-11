#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];
extern OSPfs D_80153510[];
extern u8 D_8010FBB8;
extern u8 D_800E285C[];
s32 func_0026451C(s32 flag);
void func_00263760();
void func_0026456C(void);
s32 func_00404018(s32 pad);
s32 func_002A15A0(s32 c);
s32 osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, int file_size_in_bytes, s32 *file_no);
s32 osPfsReadWriteFile(OSPfs *pfs, s32 file_no, u8 flag, int offset, int size_in_bytes, u8 *data_buffer);
s32 osPfsDeleteFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name);
void *memcpy(void *dst, const void *src, u32 n);

static inline void O01Rev(u8 *src, u8 *dst, s32 n) {
    s32 i;
    s32 j;
    for (i = 0; i < n; i++) {
        src[i] = func_002A15A0(src[i]);
        for (j = 0; j < 0x42; j++) {
            if (src[i] == D_800E285C[j]) {
                dst[i] = j;
                break;
            }
        }
        if (j == 0x42) {
            dst[i] = 0;
        }
    }
}

s32 func_004042F0(s32 pad, s32 size, u8 *data, u8 *name, s32 *outFileNo, u8 *ext, u8 *company, u8 *game) {
    u8 nameBuf[16];
    u8 extBuf[8];
    OSPfs *pfs;
    u16 ccode;
    u32 gcode;
    s32 r;
    s32 zero;
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    func_0026451C(1);
    func_00263760();
    r = D_80153500[pad];
    D_8010FBB8 = 2;
    if (r == 0) {
        O01Rev(ext, extBuf, 4);
        size = (size + 0xFF) & ~0xFF;
        memcpy(nameBuf, name, 16);
        O01Rev(name, nameBuf, 16);
        pfs = &D_80153510[pad];
        ccode = (company[0] << 8) | company[1];
        gcode = (game[0] << 24) | (game[1] << 16) | (game[2] << 8) | game[3];
        r = osPfsAllocateFile(pfs, ccode, gcode, nameBuf, extBuf, size, outFileNo);
        zero = 0;
        if (r != zero) {
            r = -1;
        }
        if (r == 0) {
            r = osPfsReadWriteFile(pfs, *outFileNo, 1, 0, size, data);
            if (r != 0) {
                osPfsDeleteFile(pfs, ccode, gcode, nameBuf, extBuf);
                r = -1;
            }
        }
        func_00404018(pad);
    }
    func_0026456C();
    return r;
}
