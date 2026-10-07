#include "o06_types.h"
extern s32 func_002643A8(void *a);
extern s32 func_002643C0(void *a);
extern s32 func_0026439C(void *a);
extern u8 D_8010F0E0[];
extern u32 D_801462D0[];
s32 func_0044438C(void) {
    if (func_002643A8(D_8010F0E0)) {
        switch (D_801462D0[0]) {
        case 8: D_801462D0[0] = 0x20; break;
        case 0x10: D_801462D0[0] = 8; break;
        case 0x20: D_801462D0[0] = 0x10; break;
        }
    }
    if (func_002643C0(D_8010F0E0) || func_0026439C(D_8010F0E0)) {
        switch (D_801462D0[0]) {
        case 8: D_801462D0[0] = 0x10; break;
        case 0x10: D_801462D0[0] = 0x20; break;
        case 0x20: D_801462D0[0] = 8; break;
        }
    }
    return 0;
}
