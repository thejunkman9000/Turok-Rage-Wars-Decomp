#include "b14_types.h"
void func_00200500(void);
extern u8 D_C5E98[];
extern u8 D_400000[];
extern u8 D_49794[];
s32 func_00265898(u32 a) {
    if (a >= (u32)func_00200500 && a < (u32)func_00200500 + (u32)D_C5E98) {
        return 1;
    }
    if (a >= (u32)D_400000 && a < (u32)D_400000 + (u32)D_49794) {
        return 1;
    }
    return 0;
}
