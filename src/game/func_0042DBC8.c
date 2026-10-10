#include "o04_types.h"
extern O04ModeS5430 *D_800E5430;
extern char D_800E1B60[];
void *func_00252FFC(s32 a);
void func_002A3358(void);
s32 func_0041A300(s32 a, s32 b);
void func_0041A4FC(s32 a);
void func_0041B190(s32 a);
O04Sub2C *func_0040ECB0(s32 a, s32 b);
s32 func_00419ED4(s32 a, s32 b);
void func_002A1C08(char *dst, char *fmt, s32 n);
s32 func_0042DBC8(s32 a) {
    O04Sub2C *h;
    D_800E5430 = func_00252FFC(0x24);
    func_002A3358();
    D_800E5430->unk0 = func_0041A300(0x398, 0x399);
    func_0041A4FC(D_800E5430->unk0);
    func_0041B190(0x39C);
    h = func_0040ECB0(a, 0x39A);
    D_800E5430->unk8 = (O04Hdr16 *)h;
    h->unk10 = 0xF;
    D_800E5430->unk4 = func_00419ED4(0x39B, 0x6E);
    D_800E5430->unkC = 3;
    func_0040ECB0(a, 0x39D)->unk38 = (s32)D_800E5430->unk14;
    D_800E5430->unk20 = 1;
    func_002A1C08(D_800E5430->unk14, D_800E1B60, 1);
    return 0;
}
