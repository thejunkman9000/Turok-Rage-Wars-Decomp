#include "o03_types.h"
void func_00419074(s32 mode) {
    if (mode != D_800E32C4) {
        D_800E32C4 = mode;
        O3_Sync();
        switch (mode) {
        case 6:
            O3_PUSH(0xE3000C00, 0x80000);
            break;
        case 7:
            O3_PUSH(0xE3000C00, 0);
            break;
        }
    }
}