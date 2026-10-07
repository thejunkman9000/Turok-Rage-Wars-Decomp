#include "o02_types.h"
extern s32 D_800E28D8;
extern u8 D_800D763C[];
extern u8 D_800D7640[];
extern u8 D_800D7644[];
extern u8 D_800D764C[];
void *func_0040C43C(void) {
    switch (D_800E28D8) {
case 0: default: return D_800D763C;
case 1: return D_800D7640;
case 2: return D_800D7644;
case 3: return D_800D764C;
}
}
