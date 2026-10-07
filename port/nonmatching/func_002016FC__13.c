#include "b01_types.h"

extern s32 D_800CD390;
extern OSMesg D_800F5C84[];
extern OSMesgQueue D_800F5C90;
extern OSMesg D_800F6CB0[];
extern OSMesg D_800F6CB4[];
extern u8 D_800F6CAC[];
extern OSMesgQueue D_800F6CC0;
extern OSMesgQueue D_800F6F40;
extern OSMesg D_800F6F58[];
extern OSThread D_800F6F60;
extern OSMesgQueue D_800F7110;
void func_002018A0(void *arg);

void func_002016FC(s32 pri) {
    if (D_800CD390 == 0) {
        D_800CD390 = 1;
        osCreateMesgQueue(&D_800F6CC0, D_800F6CB4, 1);
        osCreateMesgQueue(&D_800F6F40, D_800F6CB0, 1);
        osCreateMesgQueue(&D_800F7110, D_800F6F58, 1);
        osCreateMesgQueue(&D_800F5C90, D_800F5C84, 1);
        osSetEventMesg(0, &D_800F5C90, (OSMesg)1);
        osCreateThread(&D_800F6F60, 0x4653, func_002018A0, 0, D_800F6CAC + 4, pri);
        osStartThread(&D_800F6F60);
    }
}
