#include "o01_types.h"

extern O01Rumble D_80153330[];
extern O01Pad4 D_8010FBE0[];
extern OSMesgQueue D_8010FC00;
extern u8 D_8010FBB8;
extern s32 D_801534F0[];
s32 func_0026451C(s32 flag);
void func_00263760();
void func_0026456C(void);
s32 func_00404018(s32 ch);

void func_00404E28(s32 ch) {
    O01Rumble *r;
    s32 ok;
    func_0026451C(1);
    func_00263760();
    D_8010FBB8 = 2;
    r = &D_80153330[ch];
    if (D_8010FBE0[ch].unk3 != 0) {
        r->ok = 0;
        ok = 0;
    } else {
        r->ok = osMotorInit(&D_8010FC00, &r->pfs, ch) == 0;
        ok = r->ok;
    }
    if (ok != 0) {
        D_801534F0[ch] = 2;
    } else if (func_00404018(ch) != 0) {
        D_801534F0[ch] = 3;
    } else {
        D_801534F0[ch] = 1;
    }
    func_0026456C();
}
