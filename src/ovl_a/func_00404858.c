#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];
extern OSPfs D_80153510[];
extern O01PadTab *D_800E2854;
extern u8 D_8010FBB8;
s32 func_0026451C(s32 flag);
void func_00263760();
void func_0026456C(void);
s32 func_00404018(s32 ch);
s32 osPfsDeleteFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name);

s32 func_00404858(s32 pad, s32 idx) {
    s32 r;
    O01PadEnt *e;
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    func_0026451C(1);
    func_00263760();
    r = D_80153500[pad];
    D_8010FBB8 = 2;
    if (r == 0) {
        r = osPfsDeleteFile(&D_80153510[pad], D_800E2854[pad].ent[idx].unk8, D_800E2854[pad].ent[idx].unk4, D_800E2854[pad].ent[idx].unkE, D_800E2854[pad].ent[idx].unkA);
        if (r != 0) {
            r = -1;
        }
        func_00404018(pad);
    }
    func_0026456C();
    return r;
}
