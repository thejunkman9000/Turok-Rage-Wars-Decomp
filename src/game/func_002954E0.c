#include "common.h"

extern u8 D_8014AEB0;
extern u8 D_8014AEB1;
extern s32 D_8014AEBC;
extern s32 D_8014AEC0;
extern s32 D_8014AEB4;
extern s32 D_8014AEC4;
extern s32 D_8014AECC;
extern s32 D_8014AED4;
extern s32 D_8014AED8;
extern s32 D_8014AED0;
extern s32 D_8014CFDC;
extern s32 D_8014CFE0;
extern s32 D_8014CFE4;
extern s32 D_8014D068;
extern s32 D_8014AEB8[];
extern s32 *D_8011FED8;

void func_002954E0(void) {
    D_8014AEB0 = 0;
    D_8014AEB1 = 0;
    D_8014AEBC = 0;
    D_8014AEC0 = 0;
    D_8014AEB8[0] = 1;
    D_8014AEB4 = 0;
    D_8014AEC4 = 0;
    D_8014AECC = 0;
    D_8014AED4 = 0;
    D_8014AED8 = 0;
    D_8014AED0 = 0;
    D_8014CFDC = 0;
    D_8014CFE0 = 0;
    D_8014CFE4 = 0;
    D_8014D068 = 0;
    memset((u8 *)D_8014AEB8 + 0x24, 0, 0x2000);
    memset((u8 *)D_8014AEB8 + 0x2024, 0xFF, 0x100);
    D_8014AEB8[0] = *D_8011FED8;
}
