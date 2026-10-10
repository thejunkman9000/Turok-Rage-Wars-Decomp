#include "o03_types.h"
extern u32 D_800E32D8;
s32 func_004173FC(s32 mode, u32 tex) {
    
    s32 ret = 1;
    if (D_800E32D8 != tex) {
        D_800E32D8 = tex;
        O3_Sync();
        if (mode == 4) {
            O3_PUSH(0xE3001001, 0x8000);
            O3_PUSH(0xFD100000, tex);
            O3_PUSH(0xE8000000, 0);
            O3_PUSH(0xF5000100, 0x07000000);
            O3_PUSH(0xE6000000, 0);
            O3_PUSH(0xF0000000, 0x0703C000);
            O3_PUSH(0xE7000000, 0);
        } else if (mode == 8) {
            O3_PUSH(0xE3001001, 0x8000);
            O3_PUSH(0xFD100000, tex);
            O3_PUSH(0xE8000000, 0);
            O3_PUSH(0xF5000100, 0x07000000);
            O3_PUSH(0xE6000000, 0);
            O3_PUSH(0xF0000000, 0x073FC000);
            O3_PUSH(0xE7000000, 0);
        } else if (mode == 0x10) {
            O3_PUSH(0xE3001001, 0);
        }
        ret = 0;
    }
    return ret;
}
