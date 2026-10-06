#include "b14_types.h"
extern u8 D_800E8000[];
extern u8 D_8016E000[];
extern u8 D_80153140[];
extern u8 D_801540CA[];


s32 func_0026583C(u32 a) {
if (a >= (u32)D_800E8000 && a < (u32)D_8016E000) return 1;
 if (a >= (u32)D_80153140 && a < (u32)D_801540CA) return 1;
 return 0;
}
